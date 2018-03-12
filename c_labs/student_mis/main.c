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
    
    
    char *p1,a='5', b[5]="abc";
    p1=b;
    p1=&a;                     //显然是正确的，
    p1="abcd";              //但为什么也可以这样赋值？？
    
    
    // below will work for strcpy
    char src[] = "ryan";
    char dest[] = "hahaha";
    
    // below will not work with strcpy
//    char *src = "ryan";
//    char *des = "hahaha";
    
    strcpy(dest, src);
    
    FILE *fp = fopen("students.txt", "r");
    
    char line[255];
    const char *split = ",";
    
    char *token_p = "hahahahahahahhahahahaha";
    
    while (fgets(line, 255, (FILE*)fp) != NULL)
    {
        char *token = strtok(line, split);
        
        while (token != NULL)
        {
//            printf("%s\n", token);
            token = strtok(NULL, split);
            //        token_p = (char *)malloc(sizeof(token));
            strcpy(token_p, token);
            printf("token_p: %s", token_p);
        }
    }
    
    
    return 0;

}
