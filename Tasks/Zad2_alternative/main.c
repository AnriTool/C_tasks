#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int n,i,j,result = 0; //������ ���������� ��� �����������, ������ � ���������
/*
	//������� ��� ������� ����� ����������� �������
	printf("Enter demensions: ");
	scanf("%d",n); //����� ����������� ����� �������
*/	
	n = 3; //����������� �����������(���� ������ ������� - ���� ������ ��� ������, ��� ����� ������)
	
	int matrix[n][n],solutions[n*2+2];
	
	printf("Enter matrix:\n");
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			scanf("%d",&matrix[i][j]); //���� ������� 
	
	
	//������� ���������
	solutions[n*2] = 0;
	solutions[n*2+1] = 0;	
	
	//��������
	for(i=0; i<n ;i++)
	{
		//�������� ���������
		solutions[n*2] += matrix[i][i];
		//��������� ���������
		solutions[n*2+1] += matrix[n-i-1][i];
		//����� �����
		solutions[i] = 0;
		//����� �����
		solutions[n+i] = 0;
    	for(j=0; j<n ;j++)
    	{
     		//�������� ��� �����
     		solutions[i] += matrix[i][j];
     		//������� ��� �����
     		solutions[n+i] += matrix[j][i];
    	}
//    	printf("%d line = %d \n",i+1, solutions[i] ); // ����� �����(debug)
//		printf("%d column = %d \n",i+1, solutions[n+i]); // ����� ��������(debug)
	}
	
//	printf("Main diagonal = %d \n",solutions[n*2]); //����� �������� ���������(debug)
//	printf("Second diagonal = %d \n",solutions[n*2+1]); //����� �������� ���������(debug)
	
	for (i = 0; i < n*2+2; i++)
		for (j = 0; j < n*2+2; j++)
		{
			if (solutions[i] == solutions[j]) //���� ���� �� ����������� ������������� �������, �� ��������� 1 � ����������
				result += 1;			
		}
	
	if (((n*2+2)*(n*2+2)) == result) //���� � ���������� ����� ������� �������+��������+����������, �� ������, ��� ��� �������, ������� � ��������� - �����.
		printf("it's a magic square\n");
	else 
		printf("it's no a magic square\n");
		
//	printf("Result = %d \n",result); //��� ������ ����� ��� ������ ����������(debug)
	
	return 0;
}
