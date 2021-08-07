#ifndef _BIRCLE_H_
#define _BIRCLE_H_

#include "stdio.h"

class Cbircle{
public:
    Cbircle(){};
    virtual ~Cbircle(){};


    virtual int run() = 0;      // 当前车辆变化的逻辑
    virtual int getPoint() = 0; 
    
    char *m_line; // 记录当前路线的点标
    
    int m_name;  // 记录线路相关名字
    int m_cap;        // 记录当前数组总的位置
    int m_count;      // 记录当前下标位置
    int m_StepSize;   // 记录当前步长
    int m_state;       // 未执行完
};

#endif