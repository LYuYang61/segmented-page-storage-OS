#pragma once
/*
题目描述：
22. 段页式存储管理系统：建一个基本段页存储管理系统模型（1 人，难度：4）
	首先分配一片较大的内存空间，作为程序运行的可用存储空间；
	建立应用程序的模型，包括分段结构在内；
	建立进程的基本数据结构及相应算法；
	建立管理存储空间的基本存储结构；
	建立管理段页的基本数据结构与算法；
	设计存储空间的分配与回收算法；
	提供信息转储功能，可将存储信息存入磁盘，也可从磁盘读入。
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>

typedef struct Page  //页结构
{
	int ID;          //页号
	char in_out;     //是否在内存
	int pageOffset;	 //页内偏移
	int block_num;   //对应块号
	int time;        //在内存的时间
	int Process_ID;  //所属进程ID
	char name[10];   //所属进程名
	int Segment_ID;  //所属进程段号 
	struct Page* next;
}Pa, * PaNode;

typedef struct Segment //段结构
{
	int ID;            //段号
	Page* page;        //段中的页结构
	int size;          //段大小
	char in_out;       //是否在内存中
	struct Segment* next;
}Seg, * SegNode;

typedef struct PCB     //进程信息
{
	Segment* segm;     //进程段信息
	int total_segmet;  //段总数
	int ID;            //进程ID
	char name[10];     //进程名
	struct PCB* next;
}PCB, * pcb;

typedef struct Memory //内存块信息
{
	int ID;            //页框号
	char allocated;    //标记是否已分配
	int block_size;    //页框大小
	int Process_ID;    //占用进程ID
	char name[10];     //占用进程名
	int Segment_ID;    //占用进程段号
	int Page_ID;       //占用进程的页号
	int time_in_memory;//页在内存中的时间
	int recently;      //最近访问的时间
	struct Memory* next;
}*memory;

//函数声明
//void CreateSegment();
void CreateMemory();                            // 内存块信息
void CreateProcess();                           // 进程信息
void InitPage(PaNode* p);                       // 初始化页
void InitSegment(SegNode* s);                   // 初始化段
void InitProcess(pcb* pro);                     // 初始化进程
void ApplyMemory();                             // 初始化分配进程到内存
void AddressExchange();                         // 地址转换
void InterruptHanding(int id, int i, int j);    // 中断处理
void Apply();                                   // 申请内存
void Recycle();                                 // 内存回收

int Register;                                   //段表的起始地址
int Flash;                                      //内存大小
int BLOCK;                                      //页框大小
int remained;                                   //剩余的内存
pcb process;                                    //申明一个进程链表
int total_process = 0;                          //进程总数
memory memory_info;                             //申明一个记录内存信息的链表
int InterruptType = -1;                         //中断类型,1表示缺段中断，0表示缺页中断