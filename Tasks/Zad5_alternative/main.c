#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "multiple.h" //Подгружаем новую функцию

main()
{
 int **matrix;
 int *vector, *res;
 int  n, i, j, k;
 
//Ввод размерности для матрицы и вектора
 printf("enter demension: ");
  scanf("%d", &n);

//Выделяем память для вектора
	vector = (int*)malloc(n*sizeof(int)); // = vector[n]

//Ввод вектора
 printf("Enter vector: \n", i);
	for (i = 0; i<n; i++)
	{
     scanf("%d", &vector[i]);
	}

//Выделяем память для матрицы
	matrix=(int**)malloc(n*sizeof(int*)); // = matrix[n]
	for(i=0;i<n;i++)
	{
	 matrix[i]=(int*)malloc(n*sizeof(int )); // = matrix[n][n]
	}
	
//Вводим матрицу
	printf("Enter matrix %dx%d: \n",n,n);
	for (i = 0; i<n; i++)
	{
  	 for (j = 0; j<n; j++)
  	 {
      scanf("%d", &matrix[i][j]);	
	 }
  	}


//Записываем результат через подгружаемую функцию
res = mult(matrix,vector,n);

//вывод 
printf("Result vector = \n");
  for (i = 0; i < n; i++)
  {
  	printf("%d ", res[i]);
  }

//Освобождение памяти
for(i=0;i<n;i++)
 {
  	free(matrix[i]);
 }
free(matrix);
free(res);
free(vector);
return 0;	 
}
