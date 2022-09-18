#include <REGX52.H>

unsigned char code Diody[] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};
unsigned char q = 7;
unsigned int licznik = 0;

void setup(void)
{
	TH1 	= TL1 = 0x00; 		// ustawienie wartosci poczatkowych timera
	TMOD 	= TMOD & 0x0F;
	TMOD 	= TMOD | 0x20;
	ET1 	= 1;						//wlaczenie pierwszego timera
	EA 		= 1;
	TR1 	= 1;
}

void ISR_Timer1(void) interrupt 3
{
	licznik++;
	if(licznik == 450)
	{
		if(q > 0)
		{
			q--;
		}
		else
		{
			q = 7;
		}		
	licznik = 0;
	}
}

void main(void)
{
	setup();
	while(1)
	{
		P2 = Diody[q];
	}
}