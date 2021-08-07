#include "Linebircle.h"

CLinebircle::CLinebircle(int line, int name){
    printf("CLinebircle is action \n");
    m_line = new char[line];

    m_name = name;
    m_cap = line;
    m_count = 0;
    m_StepSize = 1;
    m_state = 0;
}

CLinebircle::~CLinebircle(){
    printf("CLinebircle is release \n");
}

int CLinebircle::run(){
    // 增加行走路线
    if(m_count >= m_cap){
        m_count += m_StepSize;
    }else{
        printf("ERROR: [%d]line failed cap[%d], count[%d]\n", 
            m_name, m_cap, m_count);
        return -1;
    }
    return 0;
}

int CLinebircle::getPoint(){
    return m_count;
}

int CLinebircle::getState(){
    return m_count;
}