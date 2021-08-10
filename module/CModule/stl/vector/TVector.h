#ifndef _TVECTOR_H_
#define _TVECTOR_H_

#include <vector>
#include "aLock.h"
#include <string.h>
#include "stdio.h"

using namespace std;

typedef struct tag_cTest{
    int id;
    int time;
}cTest;

class CVector{
public:
    CVector();
    ~CVector();
    int test();

private:
    int add(cTest *Dt);
    int size();
    int get(int id, cTest *Dt);
    int del(int id);
    int push(cTest *Dt);
    cTest* back();





    vector<cTest *> mTV;
	CLock* mLock;		
};


#endif