#include <REGX52.H>
#define Dioda P0_0
#define numer 1

unsigned char code Tab[] = {0xEF,0xDF, 0xBF, 0x7F};
unsigned char Haslo[] = {0xBD, 0x7B, 0xEB, 0xDD}; // Haslo - 9026
unsigned char wejscie[] = {0xFF, 0xFF, 0xFF, 0xFF};
bit opoznienie = 0;
unsigned char bdata Key;
sbit Key_3 = Key^3;
sbit Key_2 = Key^2;
sbit Key_1 = Key^1;
void delay(bit wolniej);
bit blad = 0;

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
				if(j <= 3)
				{
					wejscie[j] = P2;
					j++;
				}
				else
				{
					if(Key == 0x7D)
					{
						for(j = 0; j<=3 ; j++)
						{
							if(wejscie[j] == Haslo[j])
							{
								;
							}
							else
							{
								blad = 1;
								break;
							}
						}
						if(blad == 0)
						{
							for(j = 0 ; j<6 ; j++)
							{
							Dioda = 0;
							delay(opoznienie);
							Dioda = 1;
							delay(opoznienie);								
							}
						}
			
						for(j = 0; j<=3; j++)
						{
							wejscie[j] = 0xFF;
						}
						j = 0;
						blad = 0;
					}
					else if(Key == 0x77)
					{
						for(j = 0; j<=3 ; j++)
						{
							if(wejscie[j] == Haslo[j])
							{
								;
							}
							else
							{
								blad = 1;
								break;
							}
						}
						if(blad == 0)
						{
							for(j = 0; j<=2; j++)
							{
								Dioda = 0;
								delay(opoznienie);
								Dioda = 1;
								delay(opoznienie);
							}
							opoznienie = 1;
							delay(opoznienie);
							opoznienie = 0;
							for(j = 0; j<=2; j++)
							{
								Dioda = 0;
								delay(opoznienie);
								Dioda = 1;
								delay(opoznienie);
							}
						
							for(j = 0; j<=3; j++)
							{
								wejscie[j] = 0xFF;
							}
						}
						j = 0;
						blad = 0;
					}
					else
					{
						for(j = 0; j<=3; j++)
						{
							wejscie[j] = 0xFF;
						}	
					j = 0;
					blad = 0;
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

void delay(bit wolniej)
{
	unsigned char data i;
	unsigned char data j;
	
	if(wolniej == 0)
	{
   for(i=0 ; i<200 ; i++)
   {
      for(j=0;j<94;j++)
      {;}
   }
	}
	else
	{
   for(i=0 ; i<200 ; i++)
   {
      for(j=0;j<189;j++)
      {;}
   }	
	}
}