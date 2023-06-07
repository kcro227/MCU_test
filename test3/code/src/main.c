#include "REG51.H"
unsigned char code table[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};//�������ʾ����
unsigned char count        = 0;
int0_srv() interrupt 1
{
    if (++count == 100) count = 0;
    P0 = table[count / 10]; //ʮλ
    P2 = table[count % 10]; //��λ
}

void main()
{
    P0 = P2 = table[0]; //��ʼ��P0��P2
    TMOD    = 0x06;     //��ʼ����ʱ��ģʽ
    TH0 = TL0 = 0xff;       //��ʱ��ֵ
    ET0       = 1;      //�����ж�
    EA        = 1;
    TR0       = 1;
    while ((1)) {
        /* code */;
    }
}