#ifndef _BIRCLE_MANAGE_H
#define _BIRCLE_MANAGE_H

#include "bircle.h"
#include "Linebircle.h"

#include <list>
#include <vector>

using namespace std;



class CbircleManage{
public:
    CbircleManage();
    ~CbircleManage();
    int init(vector<int> line);     // 初始化本轮逻辑
    int run(int t);

private:
    int getDoBircle();  //   当前在运行的单车

private:
    list<Cbircle *> m_BircleMap;
};

#endif