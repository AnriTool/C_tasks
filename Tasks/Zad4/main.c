#include <stdio.h>
#include <stdlib.h>
#include "functions.h" //���������� ��� ������������ ���� � ���������� � ��� ���������
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c; //���������� ��� ������ ������������
	printf("Enter a b c:\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	
	if (exist(a,b,c)) //���������� ���� ������� �� �������� �������������. ����� �� ������ �������, �.�. ���� ��� ����� ������������, �� ����� true, ��� ��������, ��� ������� ���������
	{
		printf("Perimetr = %lf\n", per(a,b,c));//������� ��������(����� ���� ��� �������� ����������, �������� ���� ������� � � �����������)
		printf("Square = %lf\n", sqr(a,b,c));//������� �������(����� �������� �������)
	}
	else //�����
		printf("Triangle not exist\n");//������� ��� "����� ����������� �� ����������"
			
	return 0;
}
