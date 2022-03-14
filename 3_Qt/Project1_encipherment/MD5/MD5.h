#pragma once

#ifndef _MD5H_
#define _MD5H_
#include <math.h>
#include <Windows.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

namespace ZhouPengfei
{
    void ROL(unsigned int& s, unsigned short cx); //32λ��ѭ������ʵ�ֺ���
    void ltob(unsigned int& i); //B\L��ת������UINT����
    unsigned int* MD5(const char* mStr); //MD5���ܺ�������ִ���������
    unsigned int* MD5_2(const char* mStr); //MD5���ܺ�������ִ��������䣬����

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
    	my_md5(){ lGroup = new unsigned int[4]; };
    	~my_md5(){ delete[]lGroup; };
    	void MD5(const char* mStr);//MD5�����㷨
    	//MD5ѭ�����㺯����label=�ڼ���ѭ����1<=label<=4����lGroup����=4�����Ӹ�����M=���ݣ�16��32λ��ָ�룩����Ϣ����512λΪһ������д����
    	void AccLoop(unsigned short label, unsigned int* lGroup, void* M);
    	void Show();
        
        inline unsigned int*& get_lGroup() { return this->lGroup; }
    };
}

#endif
