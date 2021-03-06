#pragma once

#ifndef _MD5H_
#define _MD5H_
#include <math.h>
#include <Windows.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
#include<gmp.h>
using namespace std;

class my_md5
{
private:
	unsigned int* lGroup;//用来储存产生的消息摘要
//辅助函数：
	//32位数循环左移(或称右移)实现函数
	void ROL(unsigned int& s, unsigned short cx);
	//B\L互转，接收UINT类型
	void ltob(unsigned int& i);
public:
	my_md5() {
		lGroup = new unsigned int[4];
		//sum = new char[sizeof(unsigned int) * 6];
	};
	virtual ~my_md5() {
		if (lGroup){delete[]lGroup;}
	};
	void MD5(const char* mStr);//MD5加密算法
	//MD5循环计算函数，label=第几轮循环（1<=label<=4），lGroup数组=4个种子副本，M=数据（16组32位数指针），消息是以512位为一分组进行处理的
	void AccLoop(unsigned short label, unsigned int* lGroup, void* M);
	void Show();
	friend void Signnature(const char* str, mpz_t key_d, mpz_t key_n);
};
#endif