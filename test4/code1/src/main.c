#include "REG51.H"
#define uchar unsigned char

char code map[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void delay(unsigned int time)
{
    unsigned int j = 0;
    for (; time > 0; time--) {
        for (j = 0; j < 125; j++)
            ;
    }
}

void main()
{
    uchar counter = 0;
    TMOD          = 0x20;
    TH1 = TL1 = 0xf4;
    PCON      = 0;
    SCON      = 0x50;
    TR1       = 1;
    while (1) {
        SBUF = counter;
        while (TI == 0)
            ;
        TI = 0;
        while (RI == 0)
            ;
        RI = 0;
        if (SBUF == counter)
        {
            P2 = map[counter];
            if(++counter>9) counter = 0;
            delay(500);
        }
    }
}