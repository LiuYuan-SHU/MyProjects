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
	unsigned int* lGroup;//���������������ϢժҪ
//����������
	//32λ��ѭ������(�������)ʵ�ֺ���
	void ROL(unsigned int& s, unsigned short cx);
	//B\L��ת������UINT����
	void ltob(unsigned int& i);
public:
	my_md5() {
		lGroup = new unsigned int[4];
		//sum = new char[sizeof(unsigned int) * 6];
	};
	virtual ~my_md5() {
		if (lGroup){delete[]lGroup;}
	};
	void MD5(const char* mStr);//MD5�����㷨
	//MD5ѭ�����㺯����label=�ڼ���ѭ����1<=label<=4����lGroup����=4�����Ӹ�����M=���ݣ�16��32λ��ָ�룩����Ϣ����512λΪһ������д����
	void AccLoop(unsigned short label, unsigned int* lGroup, void* M);
	void Show();
	friend void Signnature(const char* str, mpz_t key_d, mpz_t key_n);
};
#endif