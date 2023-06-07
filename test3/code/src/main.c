#include "REG51.H"
unsigned char code table[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};//数码管显示段码
unsigned char count        = 0;
int0_srv() interrupt 1
{
    if (++count == 100) count = 0;
    P0 = table[count / 10]; //十位
    P2 = table[count % 10]; //个位
}

void main()
{
    P0 = P2 = table[0]; //初始化P0和P2
    TMOD    = 0x06;     //初始化定时器模式
    TH0 = TL0 = 0xff;       //定时初值
    ET0       = 1;      //开启中断
    EA        = 1;
    TR0       = 1;
    while ((1)) {
        /* code */;
    }
}