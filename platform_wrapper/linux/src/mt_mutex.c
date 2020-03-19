#include <stddef.h>
#include <stdlib.h>
#include <pthread.h>
#include "mt_mutex.h"

int mt_mutex_init(MT_MUTEX _mutex)
{
  return pthread_mutex_init(_mutex, NULL);
}

int mt_mutex_destroy(MT_MUTEX _mutex)
{
  return pthread_mutex_destroy(_mutex);
}

int mt_mutex_lock(MT_MUTEX _mutex)
{
  return pthread_mutex_lock(_mutex);
}

int mt_mutex_unlock(MT_MUTEX _mutex)
{
  return pthread_mutex_unlock(_mutex);
}

size_t mt_mutex_getinstancesize(void)
{
   return sizeof(pthread_mutex_t);
}
