#pragma once
#include<gmp.h>
#include <Windows.h>
#include<iostream>
struct Key{
	mpz_t key_n, key_e, key_d;//��Կ��n,e��;��Կ��n,d��
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
	mpz_init(key_q);	//һ��mpz_t���͵ı��������ڳ�ʼ������ܱ�ʹ��
	create(key_p, key_q);


	//���ɵ������������
	mpz_init(key_n);
	mpz_mul(key_n, key_p, key_q); //����p * q���������������key_n��

	//����ŷ������ֵ
	mpz_t key_f;
	mpz_init(key_f);

	mpz_sub_ui(key_p, key_p, 1);	//p=p-1
	mpz_sub_ui(key_q, key_q, 1);	//q=q-1
	mpz_mul(key_f, key_p, key_q);   //����(p - 1) * (q - 1)���������������key_f��

	//ѡȡһ��������e���������Կ��n,e����һ������ȡeΪ65537
	mpz_init_set_ui(key_e, 65537);//��ʼ��������eΪ65537

	//gmp_printf("%s (%ZX, %ZX)\n\n", "public key is:", key_n, key_e); //�����Կ(n, e)

	//����˽Կ֮�е�d,����GMP�е������۵����ĺ�������չŷ������㷨
	mpz_init(key_d);

	mpz_invert(key_d, key_e, key_f); //��e�����۵���d

	//gmp_printf("%s (%ZX, %ZX)\n\n", "private key is:", key_n, key_d);//���˽Կ(n, d)
}



void Key::create(mpz_t& key_p, mpz_t& key_q)
{
	gmp_randstate_t grt;
	gmp_randinit_default(grt); //��������������㷨ΪĬ��
	gmp_randseed_ui(grt, time(NULL));	//�������������Ϊ��ǰʱ�䣬�⼸�����������൱�ڱ�׼C�е�srand(time(NULL));

	mpz_urandomb(key_p, grt, 1024);
	mpz_urandomb(key_q, grt, 1024);	//�������һ����0~2^1024-1֮��������

	if (mpz_even_p(key_p))
		mpz_add_ui(key_p, key_p, 1);
	if (mpz_even_p(key_q))
		mpz_add_ui(key_q, key_q, 1);	//������ɵ������Ϊż�������һ

	while (!mpz_probab_prime_p(key_p, 25) > 0)  //�������p��������Ƿ�Ϊ����
		mpz_add_ui(key_p, key_p, 2);
	while (!mpz_probab_prime_p(key_q, 25) > 0)
		mpz_add_ui(key_q, key_q, 2);
}