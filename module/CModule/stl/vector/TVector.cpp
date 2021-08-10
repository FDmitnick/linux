
#include "TVector.h"

using namespace std;

CVector::CVector(){
    mLock = new CLock();	// 锁创建
}
CVector::~CVector(){
    if(mLock){delete mLock; mLock = NULL;}
}
int CVector::add(cTest *Dt){
    // auto 栈空间释放（锁是由类申请）
	CAutoLock autoLock(mLock);
    cTest *D = new cTest;
    memcpy(D, Dt, sizeof(cTest));
    mTV.push_back(D);
    return 0;
}
int CVector::size(){
    // auto 栈空间释放（锁是由类申请）
	CAutoLock autoLock(mLock);
    return mTV.size();
}

// 单点删除 + 增加-------------------------------------
int CVector::get(int id, cTest *Dt){
    CAutoLock autoLock(mLock);
    vector<cTest *>::iterator it = mTV.begin();
    if (it != mTV.end()){
        cTest *t = (cTest *)&(*it);
        // if(id == &(*it)->id){
        if(id == t->id){
            memcpy(Dt, &(*it), sizeof(cTest));
            return 0;
        }
    }
    return -1;
}
int CVector::del(int id){
    CAutoLock autoLock(mLock);
    vector<cTest *>::iterator it = mTV.begin();
    if (it != mTV.end()){
        cTest *t = (cTest *)&(*it);
        // if(id == &(*it)->id){
        if(id == t->id){
            mTV.erase(it);
        }
    }
    return 0;
}

// 作为队列操作-------------------------------------------------
// 后插 前删除
int CVector::push(cTest *Dt){
    CAutoLock autoLock(mLock);
    mTV.push_back(Dt);
    return 0;
}

cTest* CVector::back(){
    if(!mTV.empty()){
        CAutoLock autoLock(mLock);
        cTest* t = mTV.back();
        mTV.pop_back();
        return t;
    }
    return NULL;
}

int CVector::test(){
    
    for(int i = 0; i<100; i++){
        cTest *t = new cTest;
        t->id = i;
        t->time = time(NULL);
        push(t);
    }
    printf(" vector size = %d \n", size());

    while(size() > 0){
        cTest* t = back();
        printf(" id = %d , time = %d \n", t->id, t->time);
    }
    return 0;
}










