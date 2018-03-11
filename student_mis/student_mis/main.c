//
//  main.c
//  student_mis
//
//  Created by Ryan Zhang on 11/03/2018.
//  Copyright © 2018 yao. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char input[16]="abc,d,ef,g";//待分解字符串
    char* delim=",";//分隔符字符串
    char* p=strtok(input,delim);//第一次调用strtok
    while(p!=NULL){//当返回值不为NULL时，继续循环
        printf("%s\n",p);//输出分解的字符串
        p=strtok(NULL,delim);//继续调用strtok，分解剩下的字符串
    }
    return 0;

}
