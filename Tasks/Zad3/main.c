#include <stdio.h>
#include <stdlib.h>
#include <string.h> //��������� ����������, ���������� �� ��������

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char string[80]; //��������� ������ �� ��������(char), ��� ����� �������� �������.
	int i,len; // i - ���������� �������, ��� �����. len - ���������� ��� ����� ������
	
	printf("Enter string:\n");
	fgets(string,80,stdin); //������ ������, ��������� ���������� � ���������� string, ����������� � 80 ��������, ���� � ����������(stdin)
	
	len = strlen(string); //����� ���������� len - ��������, ������ ����� ������
		
	printf("Modified string:\n"); 	
	//�������� �����		
	for (i = 0; i < len; i++) //������ i = 0; ���� i < len, ��������� ����, � �� ����������� ����� �������� - ����������� i �� 1
	{
		if (string[i] == 'a') //���� i-� �������� ������ - ����� �
			string[i] = 'A'; //�������� ��������� a �� A
		if (string[i] == 'b')//���� i-� �������� ������ - ����� b
			string[i] = 'B'; //�������� ��������� a �� B
		printf("%c",string[i]); //������� i-� �������� ������ 
	}
	
	return 0;
}
