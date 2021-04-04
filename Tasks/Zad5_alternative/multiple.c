#include <stdlib.h>

int *mult(int **matrix,int *vector, int n) //������� ��������� �� ������� ����������� ������� �������� ��������� �� ������� � ��������� �� ������ � �� ������������
{
  int *res; //�������� ��������� �� ������ ��� ����������
  res = (int*)malloc(n * sizeof(int)); //�������� ��� ������
  int i,j; //���������� ��� �����
  for (i = 0; i < n; i++)
  {
  	res[i] = 0; //�������� i-� �������� ����������
  	for (j = 0; j < n; j++)
  	{
  	 res[i] += matrix[i][j] * vector[j]; //�����������	
	}
  }
  return res;//���������� ���������.
}