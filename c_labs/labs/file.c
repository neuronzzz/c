//
//  file.c
//  labs
//
//  Created by Ryan Zhang on 11/03/2018.
//  Copyright © 2018 yao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

#define SUCCESS 0
#define FAILED -1
#define LEN sizeof(struct student)
#define BUFF_SIZE 255

// lang
char* endl = "\n";

//// code
//int SUCCESS = 1;
//int FAILED = 0;

//default stoarge?
//char* STORAGE_FORMAT = ".txt";
//char* DEFAULT_STORAG = strcat("student", STORAGE_FORMAT);
//char* DEFAULT_BACKUP = strcat(DEFAULT_STORAG, "_backup", STORAGE_FORMAT)
char* DEFAULT_STORAGE = "students.txt";


//student
struct student
{
    char *stu_id;
//    char *name;
    char *first_name;
    char *last_name;
    char *sex;
    //    char birthday[20];
    //    char academy[20];
    //    char major[10];
    //    char province[10];
    //    char address[20];
    //    char phone[11];
    //    char email[30];
};

typedef enum student_property
{
    stu_id,
//    name,
    first_name,
    last_name,
    sex,
    birthday,
    academy,
    major,
    province,
    address,
    phone,
    email
} student_property;

//students linked list
struct student_node//带学生信息结构体的链表单位
{
    struct student stu;
    struct student_node *next;//后续链表地址
};

struct student_node *students;

//linked list opertions
//create
//struct student_node students = NULL;
//append
//search
//update
//delete


//ui
struct student_node * ui_insert(struct student_node *stu)
{
    struct student_node *stu_node = (struct student_node *)malloc(LEN);
    return stu_node;
}
struct student_node * ui_search()
{
    struct student_node *stu_node = (struct student_node *)malloc(LEN);
    return stu_node;
}
struct student_node * ui_update()
{
    struct student_node *stu_node = (struct student_node *)malloc(LEN);
    return stu_node;
}
int ui_delete()
{
    //undo
    return SUCCESS;
}

//insert
int insert(struct student_node *stu_list)
{
    return SUCCESS;
}

void show_student(struct student stu)
{
    // if stu is null, stu_id is null and if use stu.name, will get error, maybe because stu.stu_id is null and not able to identify stu.name address.
    printf("stu_id: %s\n",stu.stu_id);
//    printf("name: %s\n", stu.name);
    printf("name: %s %s\n", stu.first_name, stu.last_name);
//    printf("sex: %s\n", stu.sex);
}

void show_students(struct student_node *head)
{
    if (head == NULL)
    {
        return;
    }
    
    struct student_node *node;
    node = head;
    
    while(node != NULL)
    {
        show_student(node->stu);
        node = node->next;
    }
}

char * strtrim(char *s) {
    char *p = s;
    char *q = s;
    while (*p==' ' || *p=='\t') ++p;
    while (*q++=*p++)
        ;
    q -= 2;
    while (*q==' ' || *q=='\t') --q;
    *(q+1) ='\0';
    return s;
}

//persist
//save students to storage x
//  save
//  before exit program
//load students from storage x
struct student_node * load_students_from_storage(char* file_name)
{
    FILE *fp = fopen(file_name, "r");
    
    if (fp == NULL) {
//        fprintf(stderr,"null pointer");
        //exit(EXIT_FAILURE);
        printf("file not exist");
        //        return NULL;
        return NULL;
    }
    
    struct student_node *head, *tail = NULL;
    head = NULL;
    
    char line[BUFF_SIZE];
    const char *split = ",";
    
    while (fgets(line, BUFF_SIZE, (FILE*)fp) != NULL)
    {
        struct student_node *node = (struct student_node *)malloc(LEN);
        struct student *stu = (struct student *)malloc(LEN);
        
        node->stu = *stu;
        
        //first time strtok
        char *token = strtok(line, split);
        int i = 0;
        
        while (token != NULL)
        {
            //            stu_id,
            //            name,
            //            sex,
            //            birthday,
            //            academy,
            //            major,
            //            province,
            //            address,
            //            phone,
            //            email
            token = strtrim(token);
            printf("%s\n", token);
            switch (i) {
                case stu_id:
                    node->stu.stu_id = strdup(token);
//                    strcpy(node->stu.stu_id, token);//This usage will cause thread access issue.//这个会报EXC_BAD_ACCESS错误，主要是由于stu.stu_id还没有分配地址，而strcpy是直接赋值内容，由于没有地址，没有任何空间，直接copy内容到地址所在的内存无法操作，而在生命一个变量的时候，或者一个地址的时候，如果不赋值为NULL，默认会分配一个随机地址？或者在当前栈的位置分配一个地址。
//                    strcpy(stu->stu_id, token);
                    break;
                case first_name:
                    node->stu.first_name = strdup(token);
//                    strcpy(stu->last_name, token);
                    break;

                case last_name:
                    node->stu.last_name = strdup(token);
//                    strcpy(stu->last_name, token);
                    break;

                case sex:
                    node->stu.sex = strdup(token);
//                    strcpy(stu->sex, token);
                    break;
                    
                default:
                    break;
            }
            
            token = strtok(NULL, split);
            i++;
        }
        
        if (head == NULL)
        {
            head = node;
            tail = head;
            tail->next = NULL;

        }else
        {
            tail->next = node;
            tail = node;
            tail->next = NULL;
        }
    }
    
//    free(node);           //p1->num为0的时候跳出了while循环，并且释放node
//    node = NULL;          //特别不要忘记把释放的变量清空置为NULL,否则就变成"野指针"，即地址不确定的指针
    
    return head;
}

//clear storge x

//internal function
//clear backup x

void init_storage()
{
    if(fopen(DEFAULT_STORAGE, "r") == NULL)
    {
        fopen(DEFAULT_STORAGE, "w");
        printf("init storage failed.");
    }
}

void init()
{
    printf("init storage\n");
    init_storage();
    
    printf("init students\n");
    students = load_students_from_storage(DEFAULT_STORAGE);
    
    printf("show students\n");
    show_students(students);
}


void function_introduction()
{
    printf("=====Students MIS=====\n");
    printf("1. search\n");
    printf("2. insert\n");
    printf("3. update\n");
    printf("4. delete\n");
    printf("0. exit press ctrl + c\n");
}


int main()
{
    printf("Student MIS initializing...\n");
    init();
    printf("Student MIS initializing complete.\n");
    function_introduction();
    
}

