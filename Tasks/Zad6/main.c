#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *in, *out; //������ ���������� in � out - ������� �������� ����������� �� �����
	char name[100],surname[100],secondname[100]; //������ ��������� ���������� ��� �����, ������� � ��������
	int date,mydate; //���������� ��� 


	in = fopen("names.txt","r");  //��������� ���� names ��� ������
	out = fopen("newnames.txt","w"); //��������� ���� names ��� ������

/* 
	//��� ����� ���� ����� ��� ������� ����� ����, �� �.�. � ��� � ������� �������� 1980 ���, �� � �������������� ��� 
	printf("enter date: ");
	scanf("%d",&mydate);

	fprintf(out,"����: %d\n",mydate);
*/

	mydate = 1980; //��������� ����, ����� ������� ����� ��������

	while (fscanf(in,"%s%s%s%d\n",&name,&surname,&secondname,&date) != EOF) //���� �� ����� ������ ������, ������, ������, ����� � �� ����� �� �����(EndOfFile)
	{
		if (date > mydate)//���� ����, ������ ���� ����(1980)
			fprintf(out,"%s %s %s %d\n",name,surname,secondname,date); //������� � ���� out - ���, �������, ��������, ����
	}
	
	fclose(in); //��������� in
	fclose(out); //��������� out
	return 0;
}
