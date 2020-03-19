#ifdef IG_MT_SEMAPHORE_H
#error "Header mt_semaphore.h included twice"
#endif
#define IG_MT_SEMAPHORE_H

typedef void* MT_SEMAPHORE;
int mt_semaphore_create(MT_SEMAPHORE semaphore, unsigned int initialCount, unsigned int maxCount);
int mt_semaphore_release(MT_SEMAPHORE semaphore);
int mt_semaphore_acquire(MT_SEMAPHORE semaphore);
int mt_semaphore_close(MT_SEMAPHORE semaphore);
size_t mt_semaphore_getinstancesize(void);
