#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit PWM=P2^0;//  P2���pwm
sbit p1=P2^1;
sbit p2=P2^2;
sbit p3=P2^3;
sbit p4=P2^4;
uchar time=0;  // ����ռ�ձȵı���
uint n=0;//ռ�ձ�
bit m=0;//�����ת����
void main()
{
	
T2CON=0; //���ö�ʱ��2���ƼĴ�����������ʵ�������ã�T2CON�ϵ�Ĭ�Ͼ���0�����︳ֵֻ��Ϊ����ʾ����Ĵ���������
IE=0xA0; //1010 0000�����жϣ����ⶨʱ��2�ж�
TR2=1; //������ʱ��2
	TH2=0xff;//����ֵ��ʱ
	TL2=0xf7;//��ʱʱ�䰴���Լ��ľ������
	EA=1;//�����ж�
	ET2=1;//����ʱ��0�ж�
	TR2=1;//������ʱ��0 
	while(1)
	{			
	
}//�������д��Ķ�������⺯��֮��ģ�Ҳ����ʲô������
}
void tim2() interrupt 5
{
	TF2=0;//��ʱ��2��Ҫ��������
	TR2=0;//����ֵʱ���رն�ʱ��
	TH2=0xff;//����ֵ��ʱ
	TL2=0xf7;//
	TR2=1;//�򿪶�ʱ��
	time++;
	if(time>=100)  //
	{
	time=0;
	n++;
	}
	if((n>=100)&&(m==0))
	{
	n=0;
	m=1;
	}
	if((n>=100)&&(m==1))
	{
	n=0;
	m=0;
	}
	if((time<=n)&&(m==0))   //ռ�ձ�
	{ PWM=0;p1=0;p2=0;p3=0;p4=0;}  
	else if((time>n)&&(m==0))
	{PWM=1;p1=1;p2=1;p3=1;p4=1;}
	if((time<=n)&&(m==1))   //ռ�ձ�
	{ PWM=1;p1=1;p2=1;p3=1;p4=1;} 
	else if((time>n)&&(m==1))
	{PWM=0;p1=0;p2=0;p3=0;p4=0;}
}