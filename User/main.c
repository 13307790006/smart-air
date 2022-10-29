#include "stm32f10x.h"
#include "./systick/bsp_SysTick.h"
#include "./led/bsp_led.h"
#include "./usart/bsp_usart.h"
#include "./ds18b20/bsp_ds18b20.h"
#include "./dht11/bsp_dht11.h"
float BH1750_Average_Lux(void);
void BH1750_Init(void);
int a;


/*
\xff\xff\xff��+���������ܵ�Ƭ��ָ�������־



*/
int main(void)
{	
  uint8_t uc, ucDs18b20Id [ 8 ];
	DHT11_Data_TypeDef DHT11_Data;
	BH1750_Init();//��ʼ��GY-302
  SysTick_Init();//ʱ�ӳ�ʼ��
  DHT11_Init ();//��ʼ��DTH11
  USART_Config();	//���ڳ�ʼ��
  DS18B20_Init();//��ʼ��DS18b20
  DS18B20_ReadId ( ucDs18b20Id  ); //��ȡDS18b20                                      ���к�          
	while(1)
	{	printf("add 3,0,%d\xff\xff\xff",(int)DS18B20_GetTemp_MatchRom ( ucDs18b20Id ));
	  printf("add 4,0,%d\xff\xff\xff",(int)BH1750_Average_Lux()*4/50); 
		printf("t4.txt=\"%.2f\"\xff\xff\xff",BH1750_Average_Lux()*4);
    printf("t3.txt=\"%.4f\"\xff\xff\xff",DS18B20_GetTemp_MatchRom ( ucDs18b20Id ) );
    DHT11_Read_TempAndHumidity(& DHT11_Data);//��ȡDTH11����
		printf("t5.txt=\"%d.%d\"\xff\xff\xff",DHT11_Data.humi_int,DHT11_Data.humi_deci);
		printf("t2.txt=\"%d.%d\"\xff\xff\xff",DHT11_Data.temp_int,DHT11_Data.temp_deci);
    printf("add 5,0,%d\xff\xff\xff",(int)DHT11_Data.humi_int);
	  printf("add 2,0,%d\xff\xff\xff",(int)DHT11_Data.temp_int); 
	  
	}	 
	}

