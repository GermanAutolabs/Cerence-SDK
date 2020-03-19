#ifndef IG_AUDIOOUT_H
#define IG_AUDIOOUT_H
#include <pthread.h>
#include <alsa/asoundlib.h>
#include "ILogging.h"
#include "LogZone.h"
#if defined( __cplusplus )
extern "C" {
#endif

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * MACROS
++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define AUDIOOUT_FALSE  0
#define AUDIOOUT_TRUE   1
#define AUDIOOUT_NULL NULL
#define MAX_LEN 1024

#define AUDIOOUT_LOG(logModule, zone, format, ...)                                                                  \
{                                                                                                                   \
  nuance_common_ILogging *logging = nuance_common_ILogging_getInstance();                                           \
  LH_CHAR buffer[MAX_LEN];                                                                                          \
  snprintf (buffer, MAX_LEN, format, ##__VA_ARGS__);                                                                \
  buffer[MAX_LEN-1] = '\0';                                                                                         \
  if (logging && logModule)                                                                                         \
  {                                                                                                                 \
    nuance_common_ILogging_logText(logging, logModule, zone, buffer, __FILE__, __LINE__);                           \
  }                                                                                                                 \
}

#define AUDIOOUT_FREE_SET_NULL(memBlock) {free(memBlock); memBlock = NULL;}

#define AUDIOOUT_AUDIO_VERSION      ((AudioOut_UInt32) 0x00030000)

/* device string elements */
#define AUDIO_DEV_STRING_MASK "hw:CARD=%d,DEV=%d"
#define AUDIO_DEV_STRING_SIZE 256
#define AUDIO_DEV_DEBUG_INTERVAL 100

#define SUPPORTED_CHANNELS 2u
#define AUDIOOUT_STRLIT2CSTR(string)  (string)
#define DEVICE_PLAY_BUFFER_COUNT 3u

#define PACKAGE_TIMEOUT 3u /* wait at most for the playtime of x packages until poll returns */

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * Typedefs
 +++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 * @brief   AudioOut datatype for size variables.
 * Note: on 32-bit platforms, long is generally 32 bit, which matches pointer size.
 * (asserts to confirm this are at the end of the file)
 *
 * But this unfortunately breaks type matching in the c++ compiler.
 * Therefore we check for bitwidth
 *
 * On most 64-bit UNIX platforms, long is 64 bit.
 * On 32-bit platforms, int is generally 32 bit, which matches pointer size.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#if defined(__LP64__)
  typedef unsigned long      AudioOut_Size;

#else
  typedef unsigned int       AudioOut_Size;

#endif

typedef int             AudioOut_Bool;
typedef unsigned int    AudioOut_UInt;
typedef int             AudioOut_Int;
typedef unsigned int    AudioOut_UInt32;
typedef int             AudioOut_Int32;
typedef short           AudioOut_Int16;
typedef char            AudioOut_Char;

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * ENUMS
 +++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef enum _EWaveState
{
  E_WAVE_STATE_IDLE = 0,
  E_WAVE_STATE_WAITING,
  E_WAVE_STATE_STARTING,
  E_WAVE_STATE_PLAYING,
  E_WAVE_STATE_STOPPING,
  E_WAVE_STATE_CLOSING
} EWaveState;

typedef enum _EPackageState
{
  E_PACKAGE_STATE_UNUSED = 0,
  E_PACKAGE_STATE_PLAY,
  E_PACKAGE_STATE_RELEASE
} EPackageState;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   Return value of all AudioOut_... API
 *           functions. The datatype is used to hold the error enumeration
 *           of the audio output interface functions.
 *
 *  Each function of the Audio Output Interface returns
 *  a value of this enumeration. You can determine if there occured
 *  any errors while executing your operation.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef enum _AudioOut_Error
{
  AUDIO_OUTPUT_OK = 0,             /*!< no error occurred                                     */
  AUDIO_OUTPUT_ERR_INV_PARAM,      /*!< one or more parameter to the function are invalid     */
  AUDIO_OUTPUT_ERR_INTERNAL,       /*!< an internal error occurred                            */
  AUDIO_OUTPUT_ERR_INV_DEV_ID,     /*!< device identifier is not valid                        */
  AUDIO_OUTPUT_ERR_SAMPLE_RATE,    /*!< sample rate is not supported                          */
  AUDIO_OUTPUT_ERR_SIZE_DEV_BUF,   /*!< device buffer size is not supported                   */
  AUDIO_OUTPUT_ERR_OPEN_DEV,       /*!< error occurred while opening audio device             */
  AUDIO_OUTPUT_ERR_WRITE_DEV,      /*!< error occurred while writing to audio device          */
  AUDIO_OUTPUT_ERR_SIZE_PACK,      /*!< audio package size is not valid                       */
  AUDIO_OUTPUT_ERR_ABORT_DEV,      /*!< error occurred while aborting audio device            */
  AUDIO_OUTPUT_ERR_CLEAR_DEV_BUF,  /*!< error occurred while clearing audio device buffer     */
  AUDIO_OUTPUT_ERR_CLOSE_DEV,      /*!< error occured while closing audio device              */
  AUDIO_OUTPUT_ERR_MAX_NUM_PACK,   /*!< error occured because maximum number packages reached */
  AUDIO_OUTPUT_ERR_VERSION,        /*!< error because of incompatible Versions                */
  AUDIO_OUTPUT_ERR_CH_CNT,         /*!< error because of invalid channel count                */
} AudioOut_Error;


/*+++++++++++++++++++++++++++++++++++++++++++++++
 * CALLBACK FUNCTION PROTOTYPE
 +++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The data type defines a function pointer of an user
 *           callback function.
 *
 *  The referenced function is called from an Audio Output Interface
 *  instance of the Audio Interface if the corresponding
 *  audio package is played out from the audio output device.
 *
 *  \b Note: It is allowed to call the \c AudioOut_Write()
 *  function within the context of this user callback function.
 *
 *  @param   udPackagePlayed
 *               [in] Pointer to user data of the user callback
 *               function. The user data for a corresponding
 *               audio package callback function is installed
 *               with each call of the AudioOut_Write()
 *               function.
 *
 *  @param   pAudioPackage
 *               [in] Pointer to the audio package buffer, played
 *               out.
 *
 *  @return  none
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef void (*CbPackagePlayed)
(
  void  *udPackagePlayed,
  const AudioOut_Int16 *pAudioPackage
);

/*++++++++++++++++++++++++++++++++++++++++++
 * STRUCTURES
 ++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _TPlayFrame
{
  EPackageState       eState;                  /* eState of the package (used or unused) */
  const AudioOut_Int16  *pAudioPackageUser;    /* pointer to the audio package coming from the user */
  AudioOut_Size        sSizeAudioPackageUser;  /* size in samples of that buffer */
  CbPackagePlayed     fpPackagePlayed;         /* Pointer to a callback to write the audio output data */
  void               *udPackagePlayed;         /* Parameter of the callback CbPackageCaptured */
} TPlayFrame;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The datatype is used as a handle to identify mutex objects
 *           for the different mutex functions.
 *
 *  The actual type of the handle can be different for different platforms.
 *  The interface functions only use pointers to AudioOut_Mutex as a handle.
 *  The user does not need to care about the struct size or contents. Allocation
 *  and deallocation of memory for the structures is done by the mutex module.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _AudioOut_Mutex
{
  pthread_mutex_t hMutex;
  AudioOut_Bool    noAlloc;
} AudioOut_Mutex;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The datatype is used as a handle to identify semaphore objects for
 *           the different semaphore functions.
 *
 *  The actual type of the handle can be different for different platforms.
 *  The interface functions only use pointers to AudioOut_Sema as a handle.
 *  The user does not need to care about the struct size or contents. Allocation
 *  and deallocation of memory for the structures is done by the semaphore module.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _AudioOut_Sema
{
  volatile AudioOut_UInt32 n; /*!< the current value */
  pthread_mutex_t mutex;      /*!< the mutex to protect the wait condition */
  pthread_cond_t  cond;       /*!< the wait condition */
} AudioOut_Sema;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The datatype is used as a handle to identify an
 *           instance of the audio output interface.
 *
 *  The actual type of the handle can be different for different
 *  platforms. The interface functions only use pointers to
 *  AudioOut as a handle. The user does not need
 *  to care about the struct size or contents. Allocation and
 *  deallocation of memory for the structures is done by the
 *  audio module.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _AudioOut
{
  snd_pcm_t            *hAudioOut;              /* Handle of the audio output device */
  AudioOut_UInt32      uiNumberOfBuffers;       /* Number of audio output buffers */
  AudioOut_UInt32      uiFrameCount;            /* Number of frames of one package */
  AudioOut_UInt32      uiChannelCount;          /* number of channels of a package */
  AudioOut_UInt32      uiPendingBuffers;        /* number of calls which have to be ignored before the first package can be acknowledged */
  AudioOut_Bool        bNonInterleavedStream;   /* flag indicating if the stream is interleaved or not (writei vs. writen)*/
  AudioOut_Int32       startBurstPackageCount;  /* counter for the startup burst */
  AudioOut_Bool        bAbortMissing;           /* if close device is called without an abort an cleanup need to be triggered */
  AudioOut_Int32       iWaitTimeout;            /* timeout for the wait call in milliseconds */
  AudioOut_Char        *pDevName;               /* name of the device the user handed in */
  pthread_t            threadIdentifier;        /* worker thread */
  AudioOut_Sema        *pThreadCtrlSema;        /* sema used to handle the thread */
  AudioOut_Sema        *pFeedbackSema;          /* sema used to block interface-functions until a desired action was performed */
  AudioOut_Mutex       *pMutex;                 /* mutex used to sync worker thread and interface */
  EWaveState           eState;
  AudioOut_Bool        bSndPcmError;
  TPlayFrame           *pPlayList;
  TPlayFrame           *pHead;
  TPlayFrame           *pTailPlay;
  TPlayFrame           *pTailRelease;
  AudioOut_UInt32      uiFreeBuffers;
  nuance_common_ILogModule *pLogModule;          /*!< Variable to store instance of logmodule created in factory */
} AudioOut;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The datatype holds the audio output parameters
 *           of the audio output interface function to open a device
 *           by its name (passed as a string) or its ID
 *           (digit passed as string, representing CardID and DeviceID)
 *           respectively through AudioOut_Open_Device.
 *           This structure has to be filled in by the user.
 *           Allocation and deallocation of memory for the datatype
 *           is done by the user.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _AudioOut_Params
{
  AudioOut_Char        *uPlatformSpecificConf;  /*!< audio platform specific configuration */
  AudioOut_UInt32      uNumChannels;            /*!< number of output channels */
  AudioOut_UInt32      uSampleRate;             /*!< sample rate */
  AudioOut_UInt32      uMaxNumberFrames;        /*!< maximum number of frames */
  AudioOut_UInt32      uMaxSizeFrame;           /*!< maximum size of a frame */
  AudioOut_UInt32      uVersionNum;             /*!< audio version  */
  AudioOut_Char        *pDevIdentifier;         /*!< string value for digit or name , e.g. "4","SPEAKER1", "/dev/snd/pcmC0D0c" */
  AudioOut_Bool        bFrameMuxFlag;           /*!< flag for audio data,that data are frame multiplexed instead of sample multiplexed */
  nuance_common_ILogModule *pLogModule;          /*!< Variable to store instance of logmodule created in factory */
} AudioOut_Params;

/*+++++++++++++++++++++++++++++++++++++++++++++++
 * FUNCTION PROTOTYPES
 +++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function returns the error description of
 *           an Audio Output Interface function error code
 *           value.
 *
 *  The function is reentrant and can be called from different
 *  threads.
 *
 *  @param   iErrorCode
 *               [in] Error code value that indicates the Audio
 *               Output Interface function error.
 *
 *  @retval  A '\\0' terminated string, that contains the
 *           description of the Audio Output Interface
 *           function error code value.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

const AudioOut_Char* AudioOut_GetErrorText
(
  AudioOut_Int iErrorCode
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function initializes an Audio Output Interface
 *           instance of the Audio Interface.
 *           It is possible to open an output device by its name.
 *
 *  Therefore the function opens a specified number of audio
 *  output channels of a specified audio device or ID and prepares
 *  it for playing audio. For that the parameter \c uAudioOutParams
 *  is used to specify further attributes (e.g. audio platform specific
 *  configuration \c uPlatformSpecificConf,number of audio output channels
 *  \c uNumChannels, sample rate \c uSampleRate,maximum number of audio frames
 *  \c uMaxNumFrames, max. size of audio frames \c uMaxSizeFrame,
 *  the zero terminated string for the device identifier \c pDevIdentifier,
 *  multiplexing type of the audio package \c bFrameMuxFlag) of the Audio Output
 *  Interface instance. So the audio device driver is initialized
 *  with the number of audio output channels \c uNumChannels, the specified
 *  sampling rate \c uSampleRate and a specified size of the audio device
 *  output frame buffer (\c uMaxNumberFrames * \c uMaxSizeFrame).
 *
 *  Starting the playing process by calling the
 *  \c AudioOut_Write() function will fill this audio
 *  device output frame buffer and starts playing out of the audio
 *  samples. With a call of the \c AudioOut_Abort()
 *  function the playing process could be aborted.
 *
 *  The \c AudioOut_Open_Device() function has to be called
 *  before any other Audio Output Interface instance function. The
 *  function is reentrant and can be called from different threads.
 *
 *  The audio device driver can be identified in 3 different ways by passing
 *  a zero terminated string to the audio device driver:
 *  1.) The name of the device consists of string with mixed characters:
 *      The name will be sent as string, e.g. "/dev/snd/pcmC0D0p" or "SPEAKER1"
 *  2.) The name of the device consists of a string representing digits: e.g "001"
 *      The name will be sent as string with prefix (ADN_), e.g. " ADN_001"
 *  3.) The name of the device consists of a digit: e.g "1"
 *      The name will be sent as string, e.g "1" and the Card and device ID
 *      for the QNX audio device driver will be read from a mapping table.
 *      For "1" the Card = 0, Device = 0, for "9" the Card = 1, Device = 0, etc.
 *
 *  @param   ppAudioOut
 *              [in/out] Points to a pointer which identifies the
 *              Audio Output Interface instance of the  Audio Interface.
 *  @param   pAudioOutParams
 *              [in] The parameter \c pAudioOutParams is used to
 *              specify further attributes (e.g. audio API type,
 *              number of audio output channels, sample rate,
 *              maximum number of audio frames, max. size of audio frames,
 *              the zero terminated string for the device identifier,
 *              multiplexing type of the audio package) of the
 *              Audio output Interface instance.
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_OUTPUT_OK. Otherwise it returns an error
 *           code to indicate the error.
 *
 *  @retval  AUDIO_OUTPUT_OK
 *              No error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_INV_PARAM
 *              One or more parameter to the function are
 *              invalid.
 *  @retval  AUDIO_OUTPUT_ERR_INTERNAL
 *              An internal error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_INV_DEV_ID
 *              The device identifier of the audio output
 *              device is invalid.
 *  @retval  AUDIO_OUTPUT_ERR_SAMPLE_RATE
 *              The sample rate is not supported from audio
 *              output device.
 *  @retval  AUDIO_OUTPUT_ERROR_SIZE_DEV_BUF
 *              The size of audio output device buffer
 *              ( maxNumberPackages * maxSizePackages )
 *              is not supported.
 *  @retval  AUDIO_OUTPUT_ERROR_OPEN_DEV
 *              An error occurred while opening the audio
 *              output device.
 *  @retval  AUDIO_OUTPUT_ERR_VERSION
 *              The audio version is incompatible.
 *
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_Open_Device
(
  AudioOut **ppAudioOut,
  AudioOut_Params *pAudioOutParams
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function deinitializes an Audio Output Interface
 *           instance of the Audio Interface.
 *
 *  Therefore the function closes the corresponding audio output
 *  channel(s) of the audio output device. Before calling this
 *  function an currently running playback process has to be stopped
 *  with a  call of the \c AudioOut_Abort( ) function.
 *  The \c AudioOut_Close() function is the last function
 *  to be called of an Audio Output Interface instance. The function
 *  is reentrant and can be called from different threads.
 *
 *  @param   ppAudioOut
 *               [in/out] Points to a pointer which identifies
 *               the Audio Output Interface instance of the
 *               Audio Interface. In case of successful
 *               completion, the pointer referenced by audioOut is
 *               set to AUDIOOUT_NULL.
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_OUTPUT_OK. Otherwise it returns an error
 *           code to indicate the error.
 *
 *  @retval  AUDIO_OUTPUT_ERR_INV_PARAM
 *               One or more parameter to the function
 *               are invalid.
 *  @retval  AUDIO_OUTPUT_ERR_INTERNAL
 *               An internal error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_CLOSE_DEV
 *               An error occurred while closing the
 *               audio output device
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_Close
(
  AudioOut **ppAudioOut
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function adds an audio package to the audio
 *           output device buffer of an Audio Output Interface
 *           instance of the Audio Interface.
 *
 *  The format of an audio package is determined by the parameters
 *  to the \c AudioOut_Open() function. If the format
 *  (e.g. multiplexing type) of the audio package differs to the
 *  expected format of the audio output device, it is changed before
 *  writing the audio package to the audio output device buffer.
 *  If the added audio sample package is completely played out by
 *  the audio output device the corresponding user callback function
 *  \c fpPackagePlayed with userdata \c udPackagePlayed is called
 *  from the Audio Output Interface instance. If the maximum number
 *  of audio packets respectively audio frames that could be processed
 *  at one time by this Audio Output Interface instance is exceeded,
 *  the \c AudioOut_Write() function returns an error. The
 *  \c AudioOut_Open() function has to be called before
 *  calling this function. The function is none blocking, reentrant
 *  and can be called from different threads.
 *
 *  @param   pAudioOut
 *               [in] Pointer which identifies the Audio Output
 *               Interface instance of the Audio
 *               Interface.
 *  @param   pAudioPackage
 *               [in] Pointer to an audio output package buffer
 *               which contains audio data that should be played out.
 *               For some platforms the package is not copied,
 *               therefore the package must be valid until the
 *               callback function is called for this package.
 *               The package is not modified.
 *  @param   uSizeAudioPackage
 *               [in] Sample size of the audio package that should
 *               be played.
 *  @param   fpPackagePlayed
 *               [in] Function pointer to a user callback function.
 *               This callback function is called by the Audio
 *               Output Interface instance if the corresponding
 *               audio package is played out by the audio output
 *               device.
 *  @param   udPackagePlayed
 *               [in] Pointer to user data of the callback function.
 *               It is allowed to set a NULL pointer as user data.
 *
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_OUTPUT_OK. Otherwise it returns an error code
 *           to indicate the error.
 *
 *  @retval  AUDIO_OUTPUT_OK
 *               No error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_INV_PARAM
 *               One or more parameter to the function
 *               are invalid.
 *  @retval  AUDIO_OUTPUT_ERR_INTERNAL
 *               An internal error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_WRITE_DEV
 *               An error occurred while writing to the
 *               audio output device buffer.
 *  @retval  AUDIO_OUTPUT_ERR_SIZE_PACK
 *               The size of the audio package is invalid.
 *  @retval  AUDIO_OUTPUT_ERR_MAX_NUM_PACK
 *               The maximum number of audio packages that
 *               could be processed at one time by this
 *               Audio Output Interface instance is reached.
 *
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_Write
(
  AudioOut  *pAudioOut,
  const AudioOut_Int16   *pAudioPackage,
  AudioOut_UInt32 uSizeAudioPackage,
  CbPackagePlayed fpPackagePlayed,
  void *udPackagePlayed
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *
 *  @brief   This function flushes the remaining data of an audio
 *           output device buffer of an Audio Output Interface
 *           instance of the Audio Interface.
 *
 *  This function has to be called after writing the last audio
 *  package with a call of the \c AudioOut_Write()
 *  function.
 *
 *  The function is reentrant and can be called from different
 *  threads.
 *
 *  @param   pAudioOut
 *              [in] Pointer which identifies the Audio Output
 *              Interface instance of the Audio
 *              Interface.
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_OUTPUT_OK. Otherwise it returns an error code
 *           to indicate the error.
 *
 *  @retval  AUDIO_OUTPUT_OK
 *               No error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_INV_PARAM
 *               One or more parameter to the function
 *               are invalid.
 *  @retval  AUDIO_OUTPUT_ERR_INTERNAL
 *               An internal error occurred.
 *
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_EndOfStream
(
  AudioOut *pAudioOut
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function aborts the currently playing of audio
 *           samples and clears the audio output device buffer
 *           of an Audio Output Interface instance of the
 *           Audio Interface.
 *
 *  Additional all remaining callback functions of added audio
 *  packages will be called from the Audio Output Interface
 *  instance before this function returns. Before calling this
 *  function the Audio Output Interface instance has to be
 *  initialized with a call of the \c AudioOut_Open()
 *  function and playing has to be started with a call of the
 *  \c AudioOut_Write() function. The
 *  \c AudioOut_Abort() function is reentrant and can
 *  be called from different threads.
 *
 *  @param   pAudioOut
 *               [in] Pointer which identifies the Audio Output
 *               Interface instance of the Audio
 *               Interface.
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_OUTPUT_OK. Otherwise it returns an error
 *           code to indicate the error.
 *
 *  @retval  AUDIO_OUTPUT_OK
 *               No error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_INV_PARAM
 *               One or more parameter to the function
 *               are invalid.
 *  @retval  AUDIO_OUTPUT_ERR_INTERNAL
 *               An internal error occurred.
 *  @retval  AUDIO_OUTPUT_ERR_ABORT_DEV
 *               An error occurred while aborting the
 *               audio output device.
 *  @retval  AUDIO_OUTPUT_ERR_CLEAR_DEV_BUF
 *               An error occurred while clearing the
 *               audio output device buffer.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_Abort
(
  AudioOut *pAudioOut
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function creates a new semaphore object.
 *
 *  A handle to the semaphore is returned as out parameter and has to be used
 *  for calls to semaphore interface functions. The init function is always
 *  the first function to be called before using any of the other functions
 *
 *  @param   pSema
 *               [in/out] Pointer to a semaphore handle, which identifies the
 *               newly created semaphore object.
 *  @param   value
 *               [in] Initial counter value of the semaphore.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns AUDIO_OUTPUT_OK
 *           Otherwise it returns an error code.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_SemaInit
(
  AudioOut_Sema **pSema,
  AudioOut_UInt value,
  nuance_common_ILogModule *pLogModule
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function waits for a semaphore to get signaled.
 *
 *  The calling thread is blocked until the semaphore is signaled.
 *  When the semaphore is in the signaled state, the call
 *  succeeds and the counter of the semaphore is decremented by one.
 *
 *  @param   pSema
 *               [in] Semaphore handle, which identifies the semaphore object to
 *               wait for.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns AUDIO_OUTPUT_OK
 *           Otherwise it returns an error code.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_SemaWait
(
  AudioOut_Sema *pSema,
  nuance_common_ILogModule *pLogModule
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function signals a semaphore.
 *
 *  The semaphore counter is incremented by one.
 *
 *  @param   pSema
 *               [in] Semaphore handle, which identifies the semaphore object
 *               to signal.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns AUDIO_OUTPUT_OK
 *           Otherwise it returns an error code to indicate the error.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_SemaSignal
(
  AudioOut_Sema *pSema,
  nuance_common_ILogModule *pLogModule
);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function deinitializes a semaphore object.
 *
 *  After calling the deinit function, none of the other functions
 *  may be called for this semaphore. The resources allocated for the semaphore
 *  are freed.
 *
 *  @param   ppSema
 *               [in/out] Pointer to a semaphore handle, which identifies the
 *               semaphore object to deinitialize. In case of successful,
 *               completion, the pointer referenced by ppSema is set to NULL.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns AUDIO_OUTPUT_OK
 *           Otherwise it returns an error code.
 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioOut_Error AudioOut_SemaDeInit
(
  AudioOut_Sema **ppSema,
  nuance_common_ILogModule *pLogModule
);

#if defined( __cplusplus )
}
#endif
#endif /* IG_AUDIOOUT_H */
