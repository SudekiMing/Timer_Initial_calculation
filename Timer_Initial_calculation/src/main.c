/******************** Copyright 2016 SudekiMing. All Rights Reserved. ***************************
 * �ļ���  ��main.c
 * ����    ��SudekiMing  
 * ���뻷��: VS2012
 * ��汾  ����
 * ����ʱ�䣺2016-12-09
 
 * ����	   ��
			 51ϵ�е�Ƭ����ʱ��ֵ����
						
 * ����޸ģ�
	ʱ�䣺
	���ݣ�
	
************************************************************************************************/

#include <stdio.h>
#include <math.h>
#include <windows.h>

int THX;	//��ʱ����ֵ�߰�λ 
int TLX;	//��ʱ����ֵ�Ͱ�λ 
int y;      //��ʱ��������ʽ 
float fosc;	//����Ƶ�� 
float t;    //��ʱʱ�� 
float TimingMax;	//���ʱʱ�� 


//��ʱ����ֵ���㺯������ 
void Timer_Initial_calculation();  

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main()
{
	system("color 03");	//����ǰ��ɫΪ����ɫ
	printf("***************************��ʱ����ֵ����************************\n\n");
	printf("**      ��ʱ����ͬ������ʽ�µĳ�ֵ���㣨����51ϵ�е�Ƭ����     **\n\n");
	printf("**************************���ߣ�SudekiMing **********************\n\n\n"); 
	while(1)
	{
		
		printf("������ѡ��Ķ�ʱ��������ʽ����0��1��2��\n");
		scanf_s("%d",&y);
		printf("������ѡ��ľ���Ƶ�ʣ���λ��MHz��\n"); 
		scanf_s("%f",&fosc);
		printf("�����붨ʱʱ�䣺��λ��ms��\n");
		scanf_s("%f",&t);
		Timer_Initial_calculation();		//���㶨ʱ����ֵ 
		if(t>TimingMax)
		{
			printf("\n��ѡ��ʱ��������ʽ���ʱʱ��Ϊ:��λ��ms��%3.3f\n",TimingMax);
			printf("\n��ѡ����ʵĶ�ʱʱ�䣡\n\n\n");
		}
		else
		{
			printf("\nTHX = %x\n",THX);
			printf("\nTLX = %x\n\n\n",TLX);
		} 
		printf("***************************��ʱ����ֵ����************************\n\n");
		
	}
	
} 


/*
 * ��������Timer_Initial_calculation
 * ����  ����ʱ����ֵ���㺯��
 * ����  ����
 * ���  ����
 */
void Timer_Initial_calculation()
{
	int N;	//����ֵ 
	int n;  //��ʱ��λ�� 
	int TimeDigit;	//������ֵ 

	N = (t*fosc*1000) / 12;     //�������ֵN 
	//��ʱ��λ��ѡ��
	switch(y)
	{
		case 0: 
			n=13;
			TimeDigit = pow(2.0,n);      //��ʱ��λ��ѡ�� 
			TimingMax = TimeDigit*12/fosc/1000;		//���㶨ʱ�ʱ�� 
			THX = (TimeDigit - N)/32;	//��ֵ�߰�λ 
			TLX = (TimeDigit - N)%32;	//��ֵ�Ͱ�λ 
			break;
		case 1: 
			n=16;
			TimeDigit = pow(2.0,n);      //��ʱ��λ��ѡ�� 
			TimingMax = TimeDigit*12/fosc/1000;		//���㶨ʱ�ʱ�� 
			THX = (TimeDigit - N)/256;	//��ֵ�߰�λ 
			TLX = (TimeDigit - N)%256;	//��ֵ�Ͱ�λ 
			break;
		case 2: 
			n=8;
			TimeDigit = pow(2.0,n);      //��ʱ��λ��ѡ�� 
			TimingMax = TimeDigit*12/fosc/1000;		//���㶨ʱ�ʱ��  
			THX = TimeDigit - N;		//��ֵ�߰�λ 
			TLX = TimeDigit - N;		//��ֵ�Ͱ�λ 
			break;
		default:
			break;
	}
	
}