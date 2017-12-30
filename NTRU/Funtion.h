#pragma once
#include<iostream>
#include <time.h>
using namespace std;

#define M 1000
int N, p, q;

//多项式的基本操作
void initF(int Lf[], int num);												        //初始化Lf多项式													
void init(int Arr[], int num);												        //初始化其余多项式
void print(int Arr[]);														  	        //输出多项式
void mod(int a1[], int mod);										    	        //多项式取模
void Add(int a1[], int a2[], int a3[]);							        	//多项式加法
void ModAdd(int a1[], int a2[], int a3[], int mod);		        //多项式模加
void Minus(int a1[], int a2[], int a3[]);						        	//多项式减法
void ModMinus(int a1[], int a2[], int a3[], int mod);       	//多项式模减
void Mul(int a1[], int a2[], int a3[]);								        //多项式乘法
void ConstMul(int a1[], int con, int a3[]);					        	//多项式与常数相乘
void RingMul(int a1[], int a2[], int a3[]);					        	//多项式环上的乘法
void ModRingMul(int a1[], int a2[], int a3[], int mod);     	//多项式环上的模乘
int MaxExpon(int a[]);														            //判断多项式最大项
void Divine(int a1[], int a2[], int a3[], int a4[]);	        //多项式的除法
void Copy(int a1[], int a2[]);												        //多项式的复制
int Inverse(int a1[], int a2[], int inverse[], int inv);      //多项式的逆
void Update(int Lf[], int inverse[], int fq[], int q);	      //逆的提升
void KeyGeneration(int Lf[], int U[], int g[], int h[]);      //密钥生成
void Encryption(int h[], int Lr[], int m[], int e[]);		      //加密过程
void Decryption(int e[], int Lf[], int a[], int Fq[]);	      //解密过程
