#include"stdio.h"
#include"bircleManage.h"
#include <map>
#include <string>
#include "CTinclude.h"

using namespace std;

int main(){
    printf("main is action \n");
    vector<int> line;
    for(int i=0; i<3; i++){
        line.push_back(i);
    }
    printf("main is action 1 \n");
    CbircleManage bMange;
    bMange.init(line);
    while(1){
        usleep(10000);
        int t = time(NULL);
        bMange.run(t);
    }
    printf("main is release \n");
}