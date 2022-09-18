#include <REGX52.H>
#define Dioda P0_0
#define numer 1

unsigned char code Tab[] = {0xEF,0xDF, 0xBF, 0x7F};
unsigned char bdata Key;
sbit Key_3 = Key^3;
sbit Key_2 = Key^2;
sbit Key_1 = Key^1;
void delay(void);

void main(void)
{
	unsigned char data i = 0;
	unsigned char data j = 0;
	bit Zezwalaj = 1;			// flaga, zabezpieczajaca przed wielokrotnym wejsciem do procedury wykonawczej przy przytrzymaniu klawisza
  while(1)
  {
		P2 = Tab[i];
		Key = P2; 
		if ((Key_3&Key_2&Key_1)==0)
		{ 
			if (Zezwalaj == 1)
			{
				Zezwalaj = 0;
				if (Key == (Tab[i] & 0xF7)) 
        {  
					for(j = 0; j <= i ; j++)
					{
					Dioda = 0;
					delay();
					Dioda = 1;
					delay();						
					}
					for(j = 0; j < 2 ; j++)
					{
						delay();
					}
					Dioda = 0;
					delay();
					Dioda = 1;	
					delay();
				}	
				else if (Key == (Tab[i] & 0xFB))
				{
					for(j = 0; j <= i ; j++)
					{
					Dioda = 0;
					delay();
					Dioda = 1;
					delay();						
					}		
					for(j = 0; j < 2 ; j++)
					{
						delay();
					}
					for(j = 0 ; j < 2 ; j++)
					{
					Dioda = 0;
					delay();
					Dioda = 1;
					delay();						
					}
				}
				else if (Key == (Tab[i] & 0xFD))
				{
					for(j = 0; j <= i ; j++)
					{
					Dioda = 0;
					delay();
					Dioda = 1;
					delay();						
					}		
					for(j = 0; j < 2 ; j++)
					{
						delay();
					}
					for(j = 0 ; j < 3 ; j++)
					{
					Dioda = 0;
					delay();
					Dioda = 1;
					delay();
					}					
				}
			}
		}
		else
		{
			if (i<3) 
			{
				i++;
			}
			else 
			{
				i = 0;
			}
			Zezwalaj = 1;			// odblokowanie zezwalania na wejscie do procedur obslugi klawiszy 
    }
  }
}	 

void delay(void)
{
  unsigned char j;
  unsigned char i;
 
   for(i=0 ; i<200 ; i++)
   {
      for(j=0;j<189;j++)
      {;}
   }
}


