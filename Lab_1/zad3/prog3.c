#include <REGX52.H>
unsigned char code Diody[] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};
char q = 0;
unsigned char zgasnij = 0;
unsigned char reset = 0;
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
		if(P3 == 0xFB)
		{
		if(q < 7)
		{
			q++;
		}
		else if(q == 7)
		{
			zgasnij = 1;
			q++;
		}
		else
		{
			q = 0;
			zgasnij = 0;
		}
		}
		else
		{
			if(q>0)
			{
				q--;
			}
			else if (q == 0)
			{
				zgasnij = 1;
				q--;
			}
			else
			{
				q = 7;
				zgasnij = 0;
			}
		}
		licznik = 0;
	}
}
void main(void)
{
	setup();
	P2 = 0xFF;
	while(1)
	{
		if(P3 != 0xFB && reset == 0 )
		{
			q = 7;
			licznik = 0;
			reset = 1;
			P2 = 0xFF;
		}
		else if (P3 == 0xFB && reset == 1)
		{
			q = 0;
			licznik = 0;
			reset = 0;
			P2 = 0xFF;
		}
		if(zgasnij == 0)
		{
		P2 = P2 & Diody[q];
		}
		else
		{
			P2 = 0xFF;
		}
	}
}