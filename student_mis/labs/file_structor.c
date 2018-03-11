//
//  file_structor.c
//  labs
//
//  Created by Ryan Zhang on 11/03/2018.
//  Copyright © 2018 yao. All rights reserved.
//

#include "file_structor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int age;
    char name[30];
}people;

int write_file ()
{
    FILE * pFile;
    int i;
    people per[3];
    per[0].age=20;strcpy(per[0].name,"li");
    per[1].age=18;strcpy(per[1].name,"wang");
    per[2].age=21;strcpy(per[2].name,"zhang");
    
    if((pFile = fopen ("myfile.txt", "wb"))==NULL)
    {
        printf("cant open the file");
        exit(0);
    }
    
    for(i=0;i<3;i++)
    {
        if(fwrite(&per[i],sizeof(people),1,pFile)!=1)
            printf("file write error\n");
    }
    fclose (pFile);
    return 0;
}

int read_file()
{
    FILE * fp;
    people per;
    if((fp=fopen("myfile.txt","rb"))==NULL)
    {
        printf("cant open the file");
        exit(0);
    }
    
    while(fread(&per,sizeof(people),1,fp)==1)   //如果读到数据，就显示；否则退出
    {
        printf("%d %s\n",per.age,per.name);
    }
    return 0;
}

//int main()
//{
//    write_file();
//    read_file();
//}

