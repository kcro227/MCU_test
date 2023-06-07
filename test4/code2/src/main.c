#include "REG51.H"
#define uchar unsigned char

char code map[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void main()
{
    uchar receiv;
    TMOD = 0x20;
    TH1 = TL1 = 0xf4;
    PCON = 0;
    SCON = 0x50;
    TR1 = 1;
    while (1)
    {
        /* code */
        while(RI == 1)
        {
            RI = 0;
            receiv = SBUF;
            SBUF = receiv;
            while (TI==0);
            TI = 0;
            P2 = map[receiv];
            
        }
    }
    
}