#include"bircleManage.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include"stdio.h"
using namespace std;


CbircleManage::CbircleManage(){
    printf("CbircleManage is action \n");
    m_BircleMap.clear();
}
CbircleManage::~CbircleManage(){
    printf("CbircleManage is release \n");
}

int CbircleManage::init(vector<int> line){

    printf("CbircleManage is run action \n");
    return 0;

    //for (int i=0;i<line.size();i++){
    //    Cbircle *bc = new CLinebircle(size[i]);
    //      m_BircleMap.insert
    //}
}

int CbircleManage::run(int t){
    return 0;

    static int tfirst = t;
    if(abs(t - tfirst)){
        tfirst = t;

        // 取一个随机值，放行一个单车

        // 各单车执行一次逻辑

        // 检测各单车现在啥情况有没有释放，释放之后对站台进行重新计算

        // 检测是否需要货车进行搬运
    }
}


int CbircleManage::getDoBircle(){
    return 0;
}
