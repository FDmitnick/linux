#ifndef _LINE_BIRCLE_H_
#define _LINE_BIRCLE_H_

#include "bircle.h"
#include "stdio.h"

class CLinebircle:public Cbircle{
    CLinebircle(int line, int name);
    ~CLinebircle();

    int run();      // 当前车辆变化的逻辑
    int getPoint();
    int getState();
};

#endif