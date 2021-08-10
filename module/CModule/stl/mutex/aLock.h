#ifndef _AUTO_LOCK_
#define _AUTO_LOCK_
#include <pthread.h>

class CLock
{
public:
    CLock();
    virtual ~CLock();
    void lock();
    void unlock();
    pthread_mutex_t& getMutex() { return m_lock; }
private:
    pthread_mutex_t m_lock;

};

class CAutoLock
{
public:
    CAutoLock(CLock* pLock);
    virtual ~CAutoLock();
private:
    CLock* m_pLock;
};

#endif
