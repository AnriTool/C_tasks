#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

int main(int argc, char *argv[]) {
	int i,j,n; //переменные циклов и размерность массивов
	double **matrix1,**matrix2,**solution; //Создаём два массива которые будем вводить и результат, на которые будем выделять память
	char action; //Символьная переменная для знака
	
	
	printf("Enter demensions(n)\n");
	scanf("%d",&n); // Вводим размерность матрицы
	
	//Выделяем память для массивов, т.к. у нас двумерный массив, сейчас мы выделили память так, что матрицы лишь одномерные массивы(matrix[i])
	matrix1 = (double**)malloc(n*sizeof(double*));
	matrix2 = (double**)malloc(n*sizeof(double*));
	solution = (double**)malloc(n*sizeof(double*));	
	
	// выделяем память для j-го эллемента(тоесть теперь массив у нас будет matrix[i][j]), для каждого уже имеющего одномерного массива, выделяем память на ещё один, что сделет его двухмерным.
	for (i = 0;i < n;i++)
	{
		matrix1[i] = (double*)malloc(n*sizeof(double));
		matrix2[i] = (double*)malloc(n*sizeof(double));
		solution[i] = (double*)malloc(n*sizeof(double));			
	}	
	
	//Ввод первой матрицы
	printf("Enter 1st matrix\n");
	for (i = 0;i < n; i++)
		for (j = 0;j < n; j++)
			scanf("%lf",&matrix1[i][j]);
	

	printf("\n");// Пропускаю строку для красоты
	//Ввод второй матрицы
	printf("Enter 2nd matrix\n");
	for (i = 0;i < n; i++)
		for (j = 0;j < n; j++)
			scanf("%lf",&matrix2[i][j]);
	
	
	printf("\n");// Пропускаю строку для красоты
	//Ввод знака
	printf("enter an action(+,-,*)\n");
	scanf(" %c",&action);
	
	
	//Узнаём какой знак ввели
	if (action == '+') //Если ввели '+'
		solution = summ(matrix1,matrix2,n);
	else if (action == '-') //Если ввели '-'
		solution = subs(matrix1,matrix2,n);
	else if (action == '*') //Если ввели '*'
		solution = mult(matrix1,matrix2,n);
	
	
	printf("\n");// Пропускаю строку для красоты
	//Вывод результата
	printf("Result matrix\n");
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
			printf("%lf ", solution[i][j]);
		printf("\n");
	}
	
	
	for (i = 0;i < n;i++)	//Освобождаем память от j-х эллементов массива(тоесть превращаем в одномерныц массив) 
	{
		free(matrix1[i]);
		free(matrix2[i]);
		free(solution[i]);			
	}
	free(matrix1);//Освобождаем остальную память
	free(matrix2);
	free(solution);
	
	return 0;
}
