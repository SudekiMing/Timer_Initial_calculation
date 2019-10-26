/******************** Copyright 2016 SudekiMing. All Rights Reserved. ***************************
 * 文件名  ：main.c
 * 作者    ：SudekiMing  
 * 编译环境: VS2012
 * 库版本  ：无
 * 初版时间：2016-12-09
 
 * 功能	   ：
			 51系列单片机定时初值计算
						
 * 最后修改：
	时间：
	内容：
	
************************************************************************************************/

#include <stdio.h>
#include <math.h>
#include <windows.h>

int THX;	//定时器初值高八位 
int TLX;	//定时器初值低八位 
int y;      //定时器工作方式 
float fosc;	//晶振频率 
float t;    //定时时间 
float TimingMax;	//最大定时时间 


//定时器初值计算函数声明 
void Timer_Initial_calculation();  

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main()
{
	system("color 03");	//设置前景色为湖蓝色
	printf("***************************定时器初值计算************************\n\n");
	printf("**      定时器不同工作方式下的初值计算（适用51系列单片机）     **\n\n");
	printf("**************************作者：SudekiMing **********************\n\n\n"); 
	while(1)
	{
		
		printf("请输入选择的定时器工作方式：（0或1或2）\n");
		scanf_s("%d",&y);
		printf("请输入选择的晶振频率：单位（MHz）\n"); 
		scanf_s("%f",&fosc);
		printf("请输入定时时间：单位（ms）\n");
		scanf_s("%f",&t);
		Timer_Initial_calculation();		//计算定时器初值 
		if(t>TimingMax)
		{
			printf("\n所选定时器工作方式最大定时时间为:单位（ms）%3.3f\n",TimingMax);
			printf("\n请选择合适的定时时间！\n\n\n");
		}
		else
		{
			printf("\nTHX = %x\n",THX);
			printf("\nTLX = %x\n\n\n",TLX);
		} 
		printf("***************************定时器初值计算************************\n\n");
		
	}
	
} 


/*
 * 函数名：Timer_Initial_calculation
 * 描述  ：定时器初值计算函数
 * 输入  ：无
 * 输出  ：无
 */
void Timer_Initial_calculation()
{
	int N;	//计数值 
	int n;  //定时器位数 
	int TimeDigit;	//计数总值 

	N = (t*fosc*1000) / 12;     //计算计数值N 
	//定时器位数选择
	switch(y)
	{
		case 0: 
			n=13;
			TimeDigit = pow(2.0,n);      //定时器位数选择 
			TimingMax = TimeDigit*12/fosc/1000;		//计算定时最长时间 
			THX = (TimeDigit - N)/32;	//初值高八位 
			TLX = (TimeDigit - N)%32;	//初值低八位 
			break;
		case 1: 
			n=16;
			TimeDigit = pow(2.0,n);      //定时器位数选择 
			TimingMax = TimeDigit*12/fosc/1000;		//计算定时最长时间 
			THX = (TimeDigit - N)/256;	//初值高八位 
			TLX = (TimeDigit - N)%256;	//初值低八位 
			break;
		case 2: 
			n=8;
			TimeDigit = pow(2.0,n);      //定时器位数选择 
			TimingMax = TimeDigit*12/fosc/1000;		//计算定时最长时间  
			THX = TimeDigit - N;		//初值高八位 
			TLX = TimeDigit - N;		//初值低八位 
			break;
		default:
			break;
	}
	
}