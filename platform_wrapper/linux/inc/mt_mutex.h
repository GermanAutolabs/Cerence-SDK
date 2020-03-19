#ifdef IG_MT_MUTEX_H
#error "Header mt_mutex.h included twice"
#endif
#define IG_MT_MUTEX_H

typedef void* MT_MUTEX;
int mt_mutex_init(MT_MUTEX mutex);
int mt_mutex_destroy(MT_MUTEX mutex);
int mt_mutex_lock(MT_MUTEX mutex);
int mt_mutex_unlock(MT_MUTEX mutex);
size_t mt_mutex_getinstancesize(void);
