#pragma once
/*
��Ŀ������
22. ��ҳʽ�洢����ϵͳ����һ��������ҳ�洢����ϵͳģ�ͣ�1 �ˣ��Ѷȣ�4��
	���ȷ���һƬ�ϴ���ڴ�ռ䣬��Ϊ�������еĿ��ô洢�ռ䣻
	����Ӧ�ó����ģ�ͣ������ֶνṹ���ڣ�
	�������̵Ļ������ݽṹ����Ӧ�㷨��
	��������洢�ռ�Ļ����洢�ṹ��
	���������ҳ�Ļ������ݽṹ���㷨��
	��ƴ洢�ռ�ķ���������㷨��
	�ṩ��Ϣת�����ܣ��ɽ��洢��Ϣ������̣�Ҳ�ɴӴ��̶��롣
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>

typedef struct Page  //ҳ�ṹ
{
	int ID;          //ҳ��
	char in_out;     //�Ƿ����ڴ�
	int pageOffset;	 //ҳ��ƫ��
	int block_num;   //��Ӧ���
	int time;        //���ڴ��ʱ��
	int Process_ID;  //��������ID
	char name[10];   //����������
	int Segment_ID;  //�������̶κ� 
	struct Page* next;
}Pa, * PaNode;

typedef struct Segment //�νṹ
{
	int ID;            //�κ�
	Page* page;        //���е�ҳ�ṹ
	int size;          //�δ�С
	char in_out;       //�Ƿ����ڴ���
	struct Segment* next;
}Seg, * SegNode;

typedef struct PCB     //������Ϣ
{
	Segment* segm;     //���̶���Ϣ
	int total_segmet;  //������
	int ID;            //����ID
	char name[10];     //������
	struct PCB* next;
}PCB, * pcb;

typedef struct Memory //�ڴ����Ϣ
{
	int ID;            //ҳ���
	char allocated;    //����Ƿ��ѷ���
	int block_size;    //ҳ���С
	int Process_ID;    //ռ�ý���ID
	char name[10];     //ռ�ý�����
	int Segment_ID;    //ռ�ý��̶κ�
	int Page_ID;       //ռ�ý��̵�ҳ��
	int time_in_memory;//ҳ���ڴ��е�ʱ��
	int recently;      //������ʵ�ʱ��
	struct Memory* next;
}*memory;

//��������
//void CreateSegment();
void CreateMemory();                            // �ڴ����Ϣ
void CreateProcess();                           // ������Ϣ
void InitPage(PaNode* p);                       // ��ʼ��ҳ
void InitSegment(SegNode* s);                   // ��ʼ����
void InitProcess(pcb* pro);                     // ��ʼ������
void ApplyMemory();                             // ��ʼ��������̵��ڴ�
void AddressExchange();                         // ��ַת��
void InterruptHanding(int id, int i, int j);    // �жϴ���
void Apply();                                   // �����ڴ�
void Recycle();                                 // �ڴ����

int Register;                                   //�α����ʼ��ַ
int Flash;                                      //�ڴ��С
int BLOCK;                                      //ҳ���С
int remained;                                   //ʣ����ڴ�
pcb process;                                    //����һ����������
int total_process = 0;                          //��������
memory memory_info;                             //����һ����¼�ڴ���Ϣ������
int InterruptType = -1;                         //�ж�����,1��ʾȱ���жϣ�0��ʾȱҳ�ж�