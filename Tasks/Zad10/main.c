#include <stdio.h>
#include <stdlib.h>

#define maximum(mass, n) \
	int k;\
	int max = mass[0];\
	for (k = 0; k < n; k++)\
		if (max < mass[k])\
			max = mass[k];
//� ������� ������������ k - ��� �����, � ��������� ������������� �������� ������� ���������
//�� ����� ���� ����� ���� ����� ����������� ������ maximum(���-��,���-��)

int main(int argc, char *argv[]) {
	char string[512]; //� ���� ���������� ����� ��������� ������ � �������
	char *numbers; //����� ���� ��������� ����� ������ ������ �� �����
	int i, num[512];//�������, ������ � ������� �� ������ 
	fgets(string,512,stdin);//���� ������ � ����������, ����. ����� = 512
	numbers = strtok(string, " ");//����� ������, ������ ���������	
	
	while (numbers != NULL) 
  	{
      num[i] = strtod(numbers,NULL); //��������� ������ ������� �� ������
	  //printf("\n%lf", num[i]); //����� �����
	  i++; //����������� ������� �������
      numbers = strtok(NULL, " "); //���������� ������ ������
	  }
	maximum(num,i);//�������� ������(�� ����� ��� ���� - �� ����� ������� ��������� ������, ������� � ��� �������)
	printf("max = %d",max); //������� max, ������� ��������� � �������

	return 0;
}

