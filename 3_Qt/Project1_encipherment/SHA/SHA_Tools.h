#include "SHA256.h"

#include <iostream>
#include <math.h>
#include <QDebug>

using namespace std;
using Qt::endl;

#define cout qDebug()

namespace XvJianchao
{
    typedef unsigned int UInt32;
    typedef unsigned __int64 UInt64;
    typedef unsigned char UChar;
    #define Max 1000//����ַ���
    SHA256 sha256 = SHA256();
    Message_Digest M_D;
    UInt32 W[Max / 4];//����
    UInt32 M[16];   //�������Ϣ
    //ѹ��+��ʾ
    void compress() {
        int i;
        M_D = sha256.DEAL(M);
        cout << "Hash Value: ";
        for (i = 0; i < 8; i++) {
            cout << hex << M_D.H[i] << " ";
        }
        cout << endl;
    }
    //������λ+��ӳ���
    void PAD(UChar Y[Max]) {
        //x+1+d+l=|x|
        UInt32 i, j;
        UInt32 T1 = 0, T2 = 0, T3 = 0, T4 = 0;
        UChar temp[Max] = { 0 };
        UInt64 x = strlen((char*)Y);                  //���ݳ���
        UInt32 d =x<55? (55 - x) % 64:(x - 55) % 64;  //��䳤��
        UInt32 n = (x + 8) / 64 + 1;                  //������
        UInt32 m = x % 64;                            //��������ݳ���
        UInt32 l = 8;
        cout << "String length x: " << int(x) << " ";
        cout << "Filling length d:" << d << " ";
        cout << "Group number n:  " << n << " ";
        cout << "Final length m:  " << m << endl;
        //�����
        for (i = 0; i < x; i++) {
            temp[i] = Y[i];
        }
        //���1��1000 0000
        temp[x] = 0x80;
        //���d��0000 0000
        for (i = x + 1; i < x + d + 1; i++) {
            temp[i] = 0x00;
        }
        //��䳤�ȵ�63-0λ
        for (i = 1; i <= l; i++) {
            temp[(n * 64) - i] = (UChar)(8 * x >> (i - 1) * 8);
        }
        //�޷����ַ�ת��Ϊ�޷�������
        for (i = 0; i < Max / 4; i++) {
            for (j = 0; j < 4; j++) {
                if (j == 0)
                    T1 = temp[4 * i + j];
                if (j == 1)
                    T2 = temp[4 * i + j];
                if (j == 2)
                    T3 = temp[4 * i + j];
                if (j == 3)
                    T4 = temp[4 * i + j];
            }
            W[i] = (T1 << 24) + (T2 << 16) + (T3 << 8) + T4;
        }
        
        //��ʾ16��������
        cout << "data in hex��";
        for (i = 0; i < n * 16; i++) {
            cout << hex << " " << W[i];
        }
        cout << endl;
        //���鴦��
        for (i = 0; i < n; i++) {
            cout << "packet processing:" << i + 1 << endl;
            for (j = 0; j < 16; j++) {
                M[j] = W[(i * 16) + j];
            }
            compress();//sha-256ѹ��
        }
    }
    
    //������
    //int main() {
    //    UChar Y[Max];
    //    cout << "������Ҫ���ܵ��ַ��������" << Max << "������" << endl;
    //    cin >> Y;
    //    PAD(Y);
    //
    //    system("pause");
    //    return 0;
    //}
}


