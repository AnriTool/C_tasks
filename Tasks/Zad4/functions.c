#include <stdbool.h> //��������� ���������� ��� ������ � bool
#include <math.h> //��������� ���������� ��� ������ sqrt()

bool exist (double a,double b,double c) //������� �������, �� ������� �������� a,b,c, ������� ��������� ������������� ������������
{
	if ((a+b>c)&&(a+c>b)&&(c+b>a)) //��������� ������������� ������������
		return true; //���������� true
	else //�����
		return false;//���������� false
}

double per(double a,double b,double c) //������� ��� ������ ��������� ������������
{
	double P;
	P = a + b + c;
	return P;	
}

double sqr(double a,double b,double c) //������� ������ �������, ����� ������������
{
	double S,p;
	p = per(a,b,c)/2; //������������
	S = sqrt(p*(p-a)*(p-b)*(p-c)); //���� ������ �� �������������, ����������� �� �������� ������������� � ������
	return S;
}
