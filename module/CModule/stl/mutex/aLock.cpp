#include "aLock.h"

CLock::CLock(){
    pthread_mutex_init(&m_lock,NULL);
}

CLock::~CLock(){
    pthread_mutex_destroy(&m_lock);
}

void CLock::lock(){
    pthread_mutex_lock(&m_lock);
}

void CLock::unlock(){
    pthread_mutex_unlock(&m_lock);
}

CAutoLock::CAutoLock(CLock* pLock){
	// 锁住
    m_pLock = pLock;
    if(NULL != m_pLock)
        m_pLock->lock();
}

CAutoLock::~CAutoLock(){
	// 释放
    if(NULL != m_pLock)
        m_pLock->unlock();
}

