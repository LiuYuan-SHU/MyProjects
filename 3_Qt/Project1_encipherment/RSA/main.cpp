#include<gmp.h>
#include <Windows.h>
#include<iostream>
#include"MD5.h"
#include"Key.h"
using namespace std;

//gb2312转换为unincode
char* G2U(const char* gb2312) {
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

//计算数字签名
void Signnature(const char* str, mpz_t key_d, mpz_t key_n)
{
	my_md5 m;//创建一个md5对象
	m.MD5(str);//调用该对象的MD5函数从而来计算哈希值；

	//将哈希值整合到一起，
	char* temp0 = new char[sizeof(m.lGroup[0]) * 10];
	temp0 = ultoa(m.lGroup[0], temp0, 10);
	char* temp = new char[sizeof(m.lGroup[0])];
	for (int i = 1;i < 4;i++)
	{
		temp = ultoa(m.lGroup[i], temp, 10);
		temp0 = strcat(temp0, temp);
	}
	mpz_t H;
	mpz_init_set_str(H, temp0, 10);

	mpz_t M, C;
	mpz_init(C);
	mpz_init_set(M, H);

	mpz_powm(C, M, key_d, key_n);
	gmp_printf("%s %ZX\n\n", "the Signnature is", C);
	mpz_clear(H);
	mpz_clear(C);
}

int main()
{
	Key key;
	//模幂运算
	mpz_t M, C;
	mpz_init(C);

	//手动输入
	string temp;
	cin >> temp;
	Signnature(G2U(temp.c_str()), key.key_d, key.key_n);


	//加密函数算法 
	mpz_init_set_ui(M, 1234454545);
	mpz_powm(C, M, key.key_d, key.key_n);//
	gmp_printf("%s %ZX\n\n", "the cipertxt is:", C);

	//解密函数算法
	mpz_t M2;
	mpz_init(M2);
	mpz_powm(M2, C, key.key_e, key.key_n);   
	gmp_printf("%s %ZX\n\n", "the M2 is", M2);

	return 0;
}

