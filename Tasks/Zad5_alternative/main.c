#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "multiple.h" //���������� ����� �������

main()
{
 int **matrix;
 int *vector, *res;
 int  n, i, j, k;
 
//���� ����������� ��� ������� � �������
 printf("enter demension: ");
  scanf("%d", &n);

//�������� ������ ��� �������
	vector = (int*)malloc(n*sizeof(int)); // = vector[n]

//���� �������
 printf("Enter vector: \n", i);
	for (i = 0; i<n; i++)
	{
     scanf("%d", &vector[i]);
	}

//�������� ������ ��� �������
	matrix=(int**)malloc(n*sizeof(int*)); // = matrix[n]
	for(i=0;i<n;i++)
	{
	 matrix[i]=(int*)malloc(n*sizeof(int )); // = matrix[n][n]
	}
	
//������ �������
	printf("Enter matrix %dx%d: \n",n,n);
	for (i = 0; i<n; i++)
	{
  	 for (j = 0; j<n; j++)
  	 {
      scanf("%d", &matrix[i][j]);	
	 }
  	}


//���������� ��������� ����� ������������ �������
res = mult(matrix,vector,n);

//����� 
printf("Result vector = \n");
  for (i = 0; i < n; i++)
  {
  	printf("%d ", res[i]);
  }

//������������ ������
for(i=0;i<n;i++)
 {
  	free(matrix[i]);
 }
free(matrix);
free(res);
free(vector);
return 0;	 
}
