#pragma once
#include<gmp.h>
#include <Windows.h>
#include<iostream>
struct Key{
	mpz_t key_n, key_e, key_d;//公钥（n,e）;密钥（n,d）
	Key();
	void create(mpz_t& key_p, mpz_t& key_q);
};
Key::Key()
{
	mpz_t a, b, c;
	mpz_init_set_ui(a, 1);  //a = 1
	mpz_init_set_ui(b, 1);  //b = 1
	mpz_init(c);

	mpz_add(c, a, b);  //c = a + b
	
	mpz_t key_p, key_q;
	mpz_init(key_p);
	mpz_init(key_q);	//一个mpz_t类型的变量必须在初始化后才能被使用
	create(key_p, key_q);


	//生成的两个素数相乘
	mpz_init(key_n);
	mpz_mul(key_n, key_p, key_q); //计算p * q，并将结果储存在key_n中

	//计算欧拉函数值
	mpz_t key_f;
	mpz_init(key_f);

	mpz_sub_ui(key_p, key_p, 1);	//p=p-1
	mpz_sub_ui(key_q, key_q, 1);	//q=q-1
	mpz_mul(key_f, key_p, key_q);   //计算(p - 1) * (q - 1)，并将结果储存在key_f中

	//选取一个正整数e，并输出公钥（n,e），一般我们取e为65537
	mpz_init_set_ui(key_e, 65537);//初始化并设置e为65537

	//gmp_printf("%s (%ZX, %ZX)\n\n", "public key is:", key_n, key_e); //输出公钥(n, e)

	//计算私钥之中的d,利用GMP中的求数论倒数的函数，扩展欧几里德算法
	mpz_init(key_d);

	mpz_invert(key_d, key_e, key_f); //求e的数论倒数d

	//gmp_printf("%s (%ZX, %ZX)\n\n", "private key is:", key_n, key_d);//输出私钥(n, d)
}



void Key::create(mpz_t& key_p, mpz_t& key_q)
{
	gmp_randstate_t grt;
	gmp_randinit_default(grt); //设置随机数生成算法为默认
	gmp_randseed_ui(grt, time(NULL));	//设置随机化种子为当前时间，这几条语句的作用相当于标准C中的srand(time(NULL));

	mpz_urandomb(key_p, grt, 1024);
	mpz_urandomb(key_q, grt, 1024);	//随机生成一个在0~2^1024-1之间的随机数

	if (mpz_even_p(key_p))
		mpz_add_ui(key_p, key_p, 1);
	if (mpz_even_p(key_q))
		mpz_add_ui(key_q, key_q, 1);	//如果生成的随机数为偶数，则加一

	while (!mpz_probab_prime_p(key_p, 25) > 0)  //逐个检查比p大的奇数是否为素数
		mpz_add_ui(key_p, key_p, 2);
	while (!mpz_probab_prime_p(key_q, 25) > 0)
		mpz_add_ui(key_q, key_q, 2);
}