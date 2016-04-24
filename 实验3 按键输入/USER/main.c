#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
//ALIENTEKս��STM32������ʵ��3
//��������ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾ 	 
 int main(void)
 {
 	u8 t;
	delay_init();	    	 //��ʱ������ʼ��	  
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
	BEEP_Init();         	//��ʼ���������˿�
	LED0=0;					//�ȵ������
	while(1)
	{
 		t=KEY_Scan(0);		//�õ���ֵ
	   	if(t)
		{						   
			switch(t)
			{				 
				case KEY_UP:	//���Ʒ�����
					BEEP=!BEEP;
					break;
				case KEY_LEFT:	//����LED0��ת
					LED0=!LED0;
					break;
				case KEY_DOWN:	//����LED1��ת	 
					LED1=!LED1;
					break;
				case KEY_RIGHT:	//ͬʱ����LED0,LED1��ת 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else delay_ms(10); 
	}	 
 }

