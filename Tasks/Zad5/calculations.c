#include <stdlib.h>

//��������
double **summ(double **matrix1, double **matrix2, int n) //������� ��������� �� �������, ����������� �������� ����� ��������� �� ���� ������� ��� ** ������ ��� ��������� �������
{
	int i,j; //���������� ��� �����
	double **result;
	
	//��������� ������ ��� ����������
	result = (double**)malloc(n*sizeof(double*)); 
	for(i = 0; i < n; i++)
		result[i] = (double*)malloc(n*sizeof(double));
	
	//����������(+)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			result[i][j] = matrix1[i][j] + matrix2[i][j];
	
	//����������� result �� �������
	return result;
}

//���������
double **subs(double **matrix1, double **matrix2, int n) 
{
	int i,j;//���������� ��� �����
	double **result;
	
	//��������� ������ ��� ����������
	result = (double**)malloc(n*sizeof(double*)); 
	for(i = 0; i < n; i++)
		result[i] = (double*)malloc(n*sizeof(double));
	
	//����������(-)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			result[i][j] = matrix1[i][j] - matrix2[i][j];
	
	//����������� result �� �������
	return result;
}

//���������
double **mult(double **matrix1, double **matrix2, int n) 
{
	int i,j,k,s; //���������� ��� ����� � �����
	double **result;
	
	//��������� ������ ��� ����������
	result = (double**)malloc(n*sizeof(double*)); 
	for(i = 0; i < n; i++)
		result[i] = (double*)malloc(n*sizeof(double));
	
	//����������(*)
	for (i = 0; i<n; i++) {
        for (j = 0; j<n; j++) {
            s = 0;
            for (k = 0; k<n; k++) {
                s += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] += s;
        }
    }
	
	//����������� result �� �������
	return result;
}
