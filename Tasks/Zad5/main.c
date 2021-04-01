#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

int main(int argc, char *argv[]) {
	int i,j,n; //���������� ������ � ����������� ��������
	double **matrix1,**matrix2,**solution; //������ ��� ������� ������� ����� ������� � ���������, �� ������� ����� �������� ������
	char action; //���������� ���������� ��� �����
	
	
	printf("Enter demensions(n)\n");
	scanf("%d",&n); // ������ ����������� �������
	
	//�������� ������ ��� ��������, �.�. � ��� ��������� ������, ������ �� �������� ������ ���, ��� ������� ���� ���������� �������(matrix[i])
	matrix1 = (double**)malloc(n*sizeof(double*));
	matrix2 = (double**)malloc(n*sizeof(double*));
	solution = (double**)malloc(n*sizeof(double*));	
	
	// �������� ������ ��� j-�� ���������(������ ������ ������ � ��� ����� matrix[i][j]), ��� ������� ��� �������� ����������� �������, �������� ������ �� ��� ����, ��� ������ ��� ����������.
	for (i = 0;i < n;i++)
	{
		matrix1[i] = (double*)malloc(n*sizeof(double));
		matrix2[i] = (double*)malloc(n*sizeof(double));
		solution[i] = (double*)malloc(n*sizeof(double));			
	}	
	
	//���� ������ �������
	printf("Enter 1st matrix\n");
	for (i = 0;i < n; i++)
		for (j = 0;j < n; j++)
			scanf("%lf",&matrix1[i][j]);
	

	printf("\n");// ��������� ������ ��� �������
	//���� ������ �������
	printf("Enter 2nd matrix\n");
	for (i = 0;i < n; i++)
		for (j = 0;j < n; j++)
			scanf("%lf",&matrix2[i][j]);
	
	
	printf("\n");// ��������� ������ ��� �������
	//���� �����
	printf("enter an action(+,-,*)\n");
	scanf(" %c",&action);
	
	
	//����� ����� ���� �����
	if (action == '+') //���� ����� '+'
		solution = summ(matrix1,matrix2,n);
	else if (action == '-') //���� ����� '-'
		solution = subs(matrix1,matrix2,n);
	else if (action == '*') //���� ����� '*'
		solution = mult(matrix1,matrix2,n);
	
	
	printf("\n");// ��������� ������ ��� �������
	//����� ����������
	printf("Result matrix\n");
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
			printf("%lf ", solution[i][j]);
		printf("\n");
	}
	
	
	for (i = 0;i < n;i++)	//����������� ������ �� j-� ���������� �������(������ ���������� � ���������� ������) 
	{
		free(matrix1[i]);
		free(matrix2[i]);
		free(solution[i]);			
	}
	free(matrix1);//����������� ��������� ������
	free(matrix2);
	free(solution);
	
	return 0;
}
