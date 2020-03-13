#ifndef IG_AUDIOIN_H
#define IG_AUDIOIN_H
#include <pthread.h>
#include <alsa/asoundlib.h>
#include "ILogging.h"
#include "LogZone.h"
#if defined( __cplusplus )
extern "C"
{
#endif

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * MACROS
++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define MAX_LEN 1024

#define AUDIOIN_LOG(logModule, zone, format, ...)                                                                   \
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

#define SUPPORTED_CHANNELS 8

#define AUDIOIN_FALSE  0
#define AUDIOIN_TRUE   1
#define AUDIOIN_FREESETNULL(memBlock) {free(memBlock); memBlock = NULL;}

#define AUDIOIN_STRLIT2CSTR(string)  (string)
#define AUDIOIN_NULL NULL

#define AUDIOIN_AUDIO_VERSION  ((AudioIn_UInt32) 0x00030000)
#define SUPPORTED_SAMPLESIZE 2u /* do not change: only PCM data 16bit is supported */
#define PACKAGE_TIMEOUT      3u /* wait at most for the playtime of x packages until poll returns */
#define DEVICE_MIN_CAPTURE_BUFFER_COUNT  2u
#define AUDIO_DEV_DEBUG_INTERVAL 100

/* device string elements */
#define AUDIO_DEV_STRING_MASK "hw:CARD=%d,DEV=%d"
#define AUDIO_DEV_STRING_SIZE 256

/*+++++++++++++++++++++++++++++++++++++++++++++++++
 * Typedefs
 +++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef int             AudioIn_Bool;
typedef unsigned int    AudioIn_UInt;
typedef int             AudioIn_Int;
typedef unsigned int    AudioIn_UInt32;
typedef int             AudioIn_Int32;
typedef short           AudioIn_Int16;
typedef unsigned char   AudioIn_UChar;
typedef char            AudioIn_Char;
typedef unsigned char   AudioIn_UByte;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   AudioIn datatype for size variables.
 * Note: on 32-bit platforms, long is generally 32 bit, which matches pointer size.
 * (asserts to confirm this are at the end of the file)
 *
 * But this unfortunately breaks type matching in the c++ compiler.
 * Therefore we check for bitwidth
 *
 * On most 64-bit UNIX platforms, long is 64 bit.
 * Note: on 32-bit platforms, int is generally 32 bit, which matches pointer size.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#if defined(__LP64__)
  typedef unsigned long      AudioIn_Size;

#else
  typedef unsigned int       AudioIn_Size;

# endif

/* -------------------------------------------------------------------------+
 |   ENUMS                                                                  |
 + -------------------------------------------------------------------------*/

typedef enum _EWaveState
{
  E_WAVE_STATE_IDLE = 0,
  E_WAVE_STATE_WAITING,
  E_WAVE_STATE_STARTING,
  E_WAVE_STATE_CAPTURING,
  E_WAVE_STATE_STOPPING,
  E_WAVE_STATE_CLOSING
} EWaveState;

typedef enum _EWaitResult
{
  E_WAIT_OK = 0,
  E_WAIT_ERROR
} EWaitResult;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   Return value of all AudioIn_... API
 *           functions.
 *
 *  Each function of the AudioIn Input Interface returns
 *  a value of this enumeration. You can determine if there occured
 *  any errors while executing your operation.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef enum _AudioIn_Error
{
  AUDIO_INPUT_OK = 0,             /*!< no error occurred                                 */
  AUDIO_INPUT_ERR_INV_PARAM,      /*!< one or more parameter to the function are invalid */
  AUDIO_INPUT_ERR_INTERNAL,       /*!< an internal error occurred                        */
  AUDIO_INPUT_ERR_INV_DEV_ID,     /*!< device identifier is not valid                    */
  AUDIO_INPUT_ERR_SAMPLE_RATE,    /*!< sample rate is not supported                      */
  AUDIO_INPUT_ERR_SIZE_DEV_BUF,   /*!< device buffer size is not supported               */
  AUDIO_INPUT_ERR_SIZE_PACK,      /*!< audio package size is not valid                   */
  AUDIO_INPUT_ERR_OPEN_DEV,       /*!< error occurred while opening audio device         */
  AUDIO_INPUT_ERR_CLEAR_DEV_BUF,  /*!< error occurred while clearing audio device buffer */
  AUDIO_INPUT_ERR_START_DEV,      /*!< error occurred while starting audio device        */
  AUDIO_INPUT_ERR_READ_DEV,       /*!< error occurred while reading from audio device    */
  AUDIO_INPUT_ERR_STOP_DEV,       /*!< error occurred while stopping audio device        */
  AUDIO_INPUT_ERR_CLOSE_DEV,      /*!< error occured while closing audio device          */
  AUDIO_INPUT_ERR_VERSION,        /*!< error because of incompatible  versions           */
  AUDIO_INPUT_ERR_CH_CNT,         /*!< error because of invalid channel count            */
  AUDIO_INPUT_ERR_INV_STATE       /*!< error because of invalid state                    */
} AudioIn_Error;

/*+++++++++++++++++++++++++++++++++++++++++++++++
 * CALLBACK FUNCTION PROTOTYPE
 +++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The data type defines a function pointer of an user
 *           callback function.
 *
 *  The referenced function is called from an Audio Input Interface
 *  instance of the  AudioIn Interface if a captured audio
 *  package is available at the audio input device.
 *
 *  \b Note: It is not allowed to call any Audio Input Interface
 *  function of the AudioIn Interface within the context of this
 *  user callback function.
 *
 *  @param   udPackageCaptured
 *               [in] Pointer to user data of the user callback
 *               function. The user data is installed with a call
 *               of the AudioIn_Open() function.
 *
 *  @param   pAudioPackage
 *               [in] Pointer to the captured audio package buffer.
 *
 *  @param   uSizePackage
 *               [in] Size of the audio package (number of samples).
 *
 *  @param   errorCode
 *               [in] Error code value that indicates an error while
 *               reading from audio input device. Upon successful
 *               completion, the value returns AUDIO_INPUT_OK.
 *               Otherwise it returns an error code to indicate the
 *               error. Possible values are:
 *               @li AUDIO_INPUT_ERR_INTERNAL An internal error
 *               occurred.
 *               @li AUDIO_INPUT_ERR_READ_DEV An error occurred while
 *               reading from the audio input device.
 *
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef void (*CbPackageCaptured)
(
  void                       *udPackageCaptured,
  const AudioIn_Int16        *pAudioPackage,
  AudioIn_UInt32             uSizePackage,
  AudioIn_Error  eErrorCode
);

/* -------------------------------------------------------------------------+
 |   STRUCTURES                                                             |
 + -------------------------------------------------------------------------*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The datatype is used as a handle to identify mutex objects for the different
 *           mutex functions.
 *
 *  The actual type of the handle can be different for different platforms. <br>
 *  The interface functions only use pointers to AudioIn_Mutex as a handle.
 *  The user does not need to care about the struct size or contents. Allocation and
 *  deallocation of memory for the structures is done by the mutex module.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _AudioIn_Mutex
{
  pthread_mutex_t hMutex;
  AudioIn_Bool    noAlloc;
} AudioIn_Mutex;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The datatype is used as a handle to identify semaphore objects for the
 *           different semaphore functions.
 *
 *  The actual type of the handle can be different for different platforms. <br>
 *  The interface functions only use pointers to AudioIn_Sema as a handle.
 *  The user does not need to care about the struct size or contents. Allocation and
 *  deallocation of memory for the structures is done by the semaphore module.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _AudioIn_Sema
{
  volatile AudioIn_UInt32 n;  /*!< the current value */
  pthread_mutex_t mutex;      /*!< the mutex to protect the wait condition */
  pthread_cond_t  cond;       /*!< the wait condition */
} AudioIn_Sema;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The datatype holds the audio input parameters
 *           of the audio input interface function to open a device
 *           by its name (passed as a string) or its ID
 *           (digit passed as string, representing CardID and DeviceID)
 *           respectively through AudioIn_Open_Device.
 *           This structure has to be filled in by the user.
 *           Allocation and deallocation of memory for the datatype
 *           is done by the user.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct _AudioIn_Params
{
  AudioIn_Char        *uPlatformSpecificConf;     /*!< audio platform specific functionality*/
  AudioIn_UInt32      uNumChannels;               /*!< number of input channels */
  AudioIn_UInt32      uSampleRate;                /*!< sample rate */
  AudioIn_UInt32      uSizeOfFrameBuffer;         /*!< size of input frame buffer (= x * uSizeOfFrame) */
  AudioIn_UInt32      uSizeOfFrame;               /*!< size of a input frame */
  AudioIn_UInt32      uVersionNum;                /*!< audio version */
  AudioIn_Char        *pDevIdentifier;            /*!< string value for digit or name , e.g. "4","MIC1", "/dev/snd/pcmC0D0c" */
  AudioIn_Bool        bFrameMuxFlag;              /*!< flag for audio data,that data are frame multiplexed instead of sample multiplexed    */
  CbPackageCaptured   fpPackageCaptured;          /*!< function pointer to ther user callback function   */
  void                *udPackageCaptured;         /*!< userdata  */
  nuance_common_ILogModule *pLogModule;           /*!< Variable to store instance of logmodule created in factory */
} AudioIn_Params;

typedef struct _AudioIn
{
  snd_pcm_t           *hAudioIn;               /* Handle of the alsa audio device */
  AudioIn_UInt32      uiNumberOfBuffers;      /* Number of audio packages */
  AudioIn_UInt32      uiFrameCount;           /* Number of frames of one package */
  AudioIn_UInt32      uiChannelCount;         /* number of channels of a package */
  AudioIn_Bool        bNonInterleavedStream;  /* flag indicating if the stream is interleaved or not (readi vs. readn)*/
  AudioIn_Int32       iWaitTimeout;           /* timeout for the wait call in milliseconds */
  AudioIn_Int16       *pAudioWorkBuffer;       /* audio in work buffer */
  AudioIn_Size        sFrameCountAudioWB;     /* size in frames of that buffer */
  AudioIn_Char        *pDevName;               /* name of the device the user handed in */
  pthread_t           threadIdentifier;        /* worker thread */
  AudioIn_Sema        *pThreadCtrlSema;        /* sema used to handle the thread */
  AudioIn_Sema        *pFeedbackSema;          /* sema used to block interface-functions until a desired action was performed */
  AudioIn_Mutex       *pMutex;                 /* mutex used to sync worker thread and interface */
  EWaveState          eState;
  CbPackageCaptured   fpPackageCaptured;       /* Pointer to a callback to read out the audio input data */
  void                *udPackageCaptured;      /* Parameter of the callback CbPackageCaptured */
  nuance_common_ILogModule *pLogModule;        /* Variable to store instance of logmodule created in factory */
} AudioIn;

/*+++++++++++++++++++++++++++++++++++++++++++++++
 * FUNCTION PROTOTYPES
 +++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function creates a new semaphore object.
 *
 *  A handle to the semaphore is returned as out parameter and has to be used for calls
 *  to semaphore interface functions. The init function is always the first function
 *  to be called before using any of the other functions
 *
 *
 *  @param   ppSema
 *               [in/out] Pointer to a semaphore handle, which identifies the newly created semaphore object.
 *  @param   value
 *               [in] Initial counter value of the semaphore.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns SEMA_OK.
 *           Otherwise it returns an error code to indicate the error.
 *
 *  @retval  SEMA_OK
 *               No error occurred.
 *  @retval  SEMA_ERROR_INV_POINTER
 *               The caller passed an invalid pointer as parameter (NULL pointer).
 *  @retval  SEMA_ERROR_INV_VALUE
 *               An invalid value was passed as initial counter value.
 *  @retval  SEMA_ERROR_CREATE_FAILED
 *               A semaphore object could not be created.
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_SemaInit
(
  AudioIn_Sema **ppSema,
  AudioIn_UInt value,
  nuance_common_ILogModule *pLogModule
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function waits for a semaphore to get signaled.
 *
 *  The calling thread is blocked until the semaphore is signaled.
 *  When the semaphore is in the signaled state, the call
 *  succeeds and the counter of the semaphore is decremented by one.
 *
 *
 *  @param   pSema
 *               [in] Semaphore handle, which identifies the semaphore object to wait for.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns SEMA_OK.
 *           Otherwise it returns an error code to indicate the error.
 *
 *  @retval  SEMA_OK
 *               No error occurred.
 *  @retval  SEMA_ERROR_INV_HANDLE
 *               The caller passed an invalid semaphore handle.
 *  @retval  SEMA_ERROR_WAIT_FAILED
 *               The wait could not be processed (error from OS).
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_SemaWait
(
  AudioIn_Sema *pSema,
  nuance_common_ILogModule *pLogModule
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function signals  a semaphore.
 *
 *  The semaphore counter is incremented by one.
 *
 *
 *  @param   pSema
 *               [in] Semaphore handle, which identifies the semaphore object to signal.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns SEMA_OK.
 *           Otherwise it returns an error code to indicate the error.
 *
 *  @retval  SEMA_ERROR_INV_HANDLE
 *               The caller passed an invalid semaphore handle.
 *  @retval  SEMA_ERROR_SIGNAL_FAILED
 *               The semaphore could not be signaled (error from OS).
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_SemaSignal
(
  AudioIn_Sema *pSema,
  nuance_common_ILogModule *pLogModule
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function deinitializes a semaphore object.
 *
 *  After calling the deinit function, none of the other functions
 *  may be called for this semaphore. The resources allocated for the semaphore are freed.
 *
 *
 *  @param   ppSema
 *               [in/out] Pointer to a semaphore handle, which identifies the
 *               semaphore object to deinitialize. In case of successful completion,
 *               the pointer referenced by ppSema is set to AudioIn_NULL.
 *  @param   pLogModule
 *               [in] Logging module instance.
 *
 *  @return  Upon successful completion, the function returns SEMA_OK.
 *           Otherwise it returns an error code to indicate the error.
 *
 *  @retval  SEMA_OK
 *               No error occurred.
 *  @retval  SEMA_ERROR_INV_HANDLE
 *               The caller passed an invalid semaphore handle.
 *  @retval  SEMA_ERROR_DEINIT_FAILED
 *               The semaphore could not be deinitialized (error from OS).
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_SemaDeInit
(
  AudioIn_Sema **ppSema,
  nuance_common_ILogModule *pLogModule
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function initializes an Audio Input Interface
 *           instance of the AudioIn Audio Interface.
 *           It is possible to open an input device by its name.
 *
 *  Therefore the function opens a specified number of audio input
 *  channels of a specified audio device by its name or ID and prepares it for
 *  capturing audio. For that the parameter \c pAudioInParams is
 *  used to specify further attributes (e.i. audio platform specific configuration \c uPlatformSpecificConf,
 *  number of audio input channels \c uNumChannels, sample rate \c uSampleRate,
 *  size of frame buffer \c uSizeOfFrameBuffer, size of frame \c uSizeOfFrame,
 *  device identifier \c pDevIdentifier, multiplexing type of the audio packages \c bFrameMuxFlag,
 *  function pointer to package captured \c fpPackageCaptured,
 *  user data of the package cpatured \c udPackageCaptured) of the AudioIn Audio Input
 *  Interface instance. So the audio device driver is initialized
 *  with the number of audio input channels, the specified sampling
 *  rate \c uSampleRate, a specified audio device input frame buffer
 *  size (\c uSizeOfFrameBuffer * number of audio input channels)
 *  and a user callback function with user data parameter.
 *
 *  The audio device driver can be identified in 3 different ways by passing
 *  a zero terminated string to the audio device driver:
 *  1.) The name of the device consists of string with characters:
 *      The name will be sent as string, e.g. "/dev/snd/pcmC0D0c" or "MIC1"
 *  2.) The name of the device consists of a string representing digits: e.g "001"
 *      The name will be sent as string with prefix (ADN_), e.g. " ADN_001"
 *  3.) The name of the device consists of a digit: e.g "1"
 *      The name will be sent as string as string, e.g "1" and the Card and device ID
 *      for the QNX audio device driver will be read from a mapping table.
 *      For "1" the Card = 0, Device = 0, for "9" the Card = 1, Device = 0.
 *
 *  With calling the \c AudioIn_Start() function a
 *  capturing process is started. Up to now the audio input device
 *  frame buffer is continuously filled with the captured audio
 *  samples. Every time a captured audio package of a specified
 *  size (\c uSizeOfFrame * number of audio input channels) is
 *  available, the user callback function \c fpPackageCaptured
 *  with user data \c udPackageCaptured will be called from the
 *  Audio Input Interface instance. The format of an audio package
 *  is determined by the parameters to the \c AudioIn_Open()
 *  function. If this format (e.g. multiplexing type) differs to
 *  the delivered format of the audio input device, the AudioIn
 *  Audio Input Interface instance has to change it before calling
 *  the user callback function. Within the user callback function
 *  \c fpPackageCaptured the captured audio samples have to be copied
 *  into a local buffer because after return of the callback function
 *  the audio package is not longer valid.
 *
 *  By calling the \c AudioIn_Stop() function the capturing
 *  process is stopped and the audio input device buffer is cleared.
 *
 *  The \c AudioIn_Open_Device() function has to be called before any
 *  other Audio Input Interface function. The  function is reentrant and
 *  can be called from different threads.
 *
 *
 *  @param   ppAudioIn
 *              [in/out] Points to a pointer which identifies the
 *              Audio Input Interface instance of the AudioIn
 *              Audio Interface.
 *  @param   pAudioInParams
 *              [in] The parameter \c pAudioInParams is used to
 *              specify attributes (e.i. audio API type,
 *              number of audio input channels, sample rate, size of frame buffer,
 *              size of frame, device identifier,
 *              multiplexing type of the audio packages,function pointer to package captured,
 +              user data of the package captured) of the
 *              AudioIn Audio Input Interface instance.
 *
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_INPUT_OK. Otherwise it returns an error code
 *           to indicate the error.
 *
 *  @retval  AUDIO_INPUT_OK
 *              No error occurred.
 *  @retval  AUDIO_INPUT_ERR_INV_PARAM
 *              One or more parameter to the function are
 *              invalid.
 *  @retval  AUDIO_INPUT_ERR_INTERNAL
 *              An internal error occurred.
 *  @retval  AUDIO_INPUT_ERR_INV_DEV_ID
 *              The device identifier of the audio input
 *              device is invalid.
 *  @retval  AUDIO_INPUT_ERR_SAMPLE_RATE
 *              The sample rate is not supported from audio
 *              input device.
 *  @retval  AUDIO_INPUT_ERR_SIZE_DEV_BUF
 *              The audio input device buffer size is not
 *              supported from audio input device.
 *  @retval  AUDIO_INPUT_ERR_SIZE_PACK
 *              The audio package size is not valid.
 *  @retval  AUDIO_INPUT_ERR_OPEN_DEV
 *              An error occurred while opening the audio input
 *              device.
 *  @retval  AUDIO_INPUT_ERR_VERSION
 *              The audio version is incompatible.
 *
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_Open_Device
(
  AudioIn         **ppAudioIn,
  AudioIn_Params  *pAudioInParams
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function starts the capturing of audio samples
 *           at an Audio Input Interface instance of the AudioIn
 *           Audio Interface.
 *
 *  Therefore the function clears the audio input device frame
 *  buffer of the audio input device and starts the capturing
 *  process. Up to now every time a captured audio package of
 *  size \c uSizeOfFrame (v.q. \c AudioIn_Open())
 *  multiplied with the number of audio input channels is available
 *  at the audio input device the user callback function will be
 *  called. Before calling the \c AudioIn_Start()
 *  function the Audio Input Interface instance has to be initialized
 *  with a call of the \c AudioIn_Open() function. The
 *  \c AudioIn_Start() function is reentrant and can be
 *  called from different threads.
 *
 *
 *  @param   pAudioIn
 *               [in] Pointer which identifies the Audio
 *               Input Interface instance of the AudioIn
 *               Audio Interface.
 *
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_INPUT_OK. Otherwise it returns an error code
 *           to indicate the error.
 *
 *  @retval  AUDIO_INPUT_OK
 *              No error occurred.
 *  @retval  AUDIO_INPUT_ERR_INV_PARAM
 *              One or more parameter to the function are
 *              invalid.
 *  @retval  AUDIO_INPUT_ERR_INTERNAL
 *              An internal error occurred.
 *  @retval  AUDIO_INPUT_ERR_CLEAR_DEV_BUF
 *              An error occurred while clearing the audio
 *              input device buffer.
 *  @retval  AUDIO_INPUT_ERR_START_DEV
 *              An error occurred while starting the audio
 *              input device.
 *
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_Start
(
  AudioIn  *pAudioIn
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function stops the capturing of audio samples
 *           at an Audio Input Interface instance of the AudioIn
 *           Audio Interface.
 *
 *  The function has to guarantee that the user callback function
 *  will never be called again after calling this function. Before
 *  calling the \c AudioIn_Stop() function the Audio
 *  Input Interface instance has to be initialized with a call of the
 *  \c AudioIn_Open() function and capturing has to be
 *  started with a call of the \c AudioIn_Start() function.
 *  The \c AudioIn_Stop() function is reentrant and can be
 *  called from different threads.
 *
 *
 *  @param   pAudioIn
 *              [in] Pointer which identifies the Audio Input
 *              Interface instance of the AudioIn Audio
 *              Interface.
 *
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_INPUT_OK. Otherwise it returns an error code
 *           to indicate the error.
 *
 *  @retval  AUDIO_INPUT_OK
 *              No error occurred.
 *  @retval  AUDIO_INPUT_ERR_INV_PARAM
 *              One or more parameter to the function are invalid.
 *  @retval  AUDIO_INPUT_ERR_INTERNAL
 *              An internal error occurred.
 *  @retval  AUDIO_INPUT_ERR_STOP_DEV
 *              An error occurred while stopping the audio
 *              input device.
 *
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_Stop
(
  AudioIn  *pAudioIn
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
 *  @brief   The function deinitializes an Audio Input Interface
 *           instance of the AudioIn Audio Interface.
 *
 *  Therefor the function closes the corresponding audio input
 *  channel(s) of the audio input device. Before calling this
 *  function a running capturing process has to be stopped by
 *  calling the \c AudioIn_Stop() function. The
 *  \c AudioIn_Close() function is the last function
 *  to be called of an Audio Input Interface instance. The function
 *  is reentrant and can be called from different threads.
 *
 *
 *  @param   ppAudioIn
 *              [in/out] Pointer which identifies the Audio
 *              Input Interface instance of the AudioIn
 *              Audio Interface. In case of successful completion,
 *              the pointer referenced by \c ppAudioIn is set to
 *              NULL.
 *
 *  @return  Upon successful completion, the function returns
 *           AUDIO_INPUT_OK. Otherwise it returns an error code
 *           to indicate the error.
 *
 *  @retval  AUDIO_INPUT_OK
 *              No error occurred.
 *  @retval  AUDIO_INPUT_ERR_INV_PARAM
 *              One or more parameter to the function
 *              are invalid.
 *  @retval  AUDIO_INPUT_ERR_INTERNAL
 *              An internal error occurred.
 *  @retval  AUDIO_INPUT_ERR_CLOSE_DEV
 *              An error occurred while closing the audio
 *              input device.
 *
 */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

AudioIn_Error AudioIn_Close
(
  AudioIn  **ppAudioIn
);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*!
*  @brief   The audioin_ErrorGetString is used to retrieve a textual
*           description of the error code returned by any of the AudioIn_* functions.
*
*  @param   errorCode
*              [in] The Error code
*
*  @return    The function returns a pointer to a string.
*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

const AudioIn_Char* audioin_ErrorGetString
(
  AudioIn_Int32 errorCode
);

#if defined( __cplusplus )
}
#endif
#endif /* IG_AUDIOIN_H */
