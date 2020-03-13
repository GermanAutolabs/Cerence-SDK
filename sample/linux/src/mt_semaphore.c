#include <stddef.h>
#include <stdlib.h>
#include <semaphore.h>
#include "mt_semaphore.h"


int mt_semaphore_create(MT_SEMAPHORE _semaphore, unsigned int initialCount, unsigned int maxCount)
{
  // maxCount unused for linux
  return sem_init(_semaphore, 0, initialCount);
}

int mt_semaphore_release(MT_SEMAPHORE _semaphore)
{
  return sem_post(_semaphore);
}

int mt_semaphore_acquire(MT_SEMAPHORE _semaphore)
{
  return sem_wait(_semaphore);
}

int mt_semaphore_close(MT_SEMAPHORE _semaphore)
{
  return sem_close(_semaphore);
}

size_t mt_semaphore_getinstancesize(void)
{
  return sizeof(sem_t);
}
