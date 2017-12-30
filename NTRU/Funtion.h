#pragma once
#include<iostream>
#include <time.h>
using namespace std;

#define M 1000
int N, p, q;

//����ʽ�Ļ�������
void initF(int Lf[], int num);												//��ʼ��Lf����ʽ													
void init(int Arr[], int num);												//��ʼ���������ʽ
void print(int Arr[]);															//�������ʽ
void mod(int a1[], int mod);											//����ʽȡģ
void Add(int a1[], int a2[], int a3[]);									//����ʽ�ӷ�
void ModAdd(int a1[], int a2[], int a3[], int mod);			//����ʽģ��
void Minus(int a1[], int a2[], int a3[]);								//����ʽ����
void ModMinus(int a1[], int a2[], int a3[], int mod);		//����ʽģ��
void Mul(int a1[], int a2[], int a3[]);									//����ʽ�˷�
void ConstMul(int a1[], int con, int a3[]);						//����ʽ�볣�����
void RingMul(int a1[], int a2[], int a3[]);							//����ʽ���ϵĳ˷�
void ModRingMul(int a1[], int a2[], int a3[], int mod);	//����ʽ���ϵ�ģ��
int MaxExpon(int a[]);														//�ж϶���ʽ�����
void Divine(int a1[], int a2[], int a3[], int a4[]);				//����ʽ�ĳ���
void Copy(int a1[], int a2[]);												//����ʽ�ĸ���
int Inverse(int a1[], int a2[], int inverse[], int inv);			//����ʽ����
void Update(int Lf[], int inverse[], int fq[], int q);				//�������
void KeyGeneration(int Lf[], int U[], int g[], int h[]);			//��Կ����
void Encryption(int h[], int Lr[], int m[], int e[]);				//���ܹ���
void Decryption(int e[], int Lf[], int a[], int Fq[]);				//���ܹ���
