#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���������
struct human{
char name[20];
char surname[20];
int year;	
};


int main()
{
	struct human old[4]; // ������ �� ���������, � ������� �� ����� ����������, �� ���� ����������� ������
	struct human sorted[4]; //����� ������, ��������� �� ������ ������� old, � ����������� �� �����
	struct human temp; //����� ��� ����������, ��� ��������� ����������, ���� �� ���������� ��������, ���� ��� �� �������.
	int i,j; //���������� ��� ������

//����� ������ ������ 
for (i = 0; i < 4; i++)
{
	printf("Human[%d] name surname birthyear:\n",i+1);
	scanf("%s%s%d", &old[i].name, &old[i].surname,&old[i].year);
}

//������� ������ ������ � �����
for (i = 0; i < 4; i++)
{
	strcpy(sorted[i].name,old[i].name);
	strcpy(sorted[i].surname,old[i].surname);
	sorted[i].year = old[i].year;
}

//����������� ���������� ������ �������
for (i = 0; i < 4; i++)
{
	for (j = 3; j > i; j--)
	{
		if (sorted[j-1].year > sorted[j].year)
		{
			//����� ������� ���
			temp = sorted[j-1];
			sorted[j-1] = sorted[j];
			sorted[j] = temp;
		}
	}
}

printf("\n");
//������ ����� ��������������� ������
for (i = 0; i < 4; i++)
{
	printf("Sorted:\nHuman[%d]: %s %s %d\n",i+1,sorted[i].name, sorted[i].surname, sorted[i].year);
 } 

	return 0;
}
