#include <stdlib.h>

//Сложение
double **summ(double **matrix1, double **matrix2, int n) //создаем указатель на функцию, аргументами которого будут указатели на наши матрицы две ** потому что двумерные матрицы
{
	int i,j; //Переменные для цикла
	double **result;
	
	//Выделение памяти для результата
	result = (double**)malloc(n*sizeof(double*)); 
	for(i = 0; i < n; i++)
		result[i] = (double*)malloc(n*sizeof(double));
	
	//Вычесление(+)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			result[i][j] = matrix1[i][j] + matrix2[i][j];
	
	//Возвращение result из функции
	return result;
}

//Вычитание
double **subs(double **matrix1, double **matrix2, int n) 
{
	int i,j;//Переменные для цикла
	double **result;
	
	//Выделение памяти для результата
	result = (double**)malloc(n*sizeof(double*)); 
	for(i = 0; i < n; i++)
		result[i] = (double*)malloc(n*sizeof(double));
	
	//Вычесление(-)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			result[i][j] = matrix1[i][j] - matrix2[i][j];
	
	//Возвращение result из функции
	return result;
}

//Умножение
double **mult(double **matrix1, double **matrix2, int n) 
{
	int i,j,k,s; //Переменные для цикла и суммы
	double **result;
	
	//Выделение памяти для результата
	result = (double**)malloc(n*sizeof(double*)); 
	for(i = 0; i < n; i++)
		result[i] = (double*)malloc(n*sizeof(double));
	
	//Вычесление(*)
	for (i = 0; i<n; i++) {
        for (j = 0; j<n; j++) {
            s = 0;
            for (k = 0; k<n; k++) {
                s += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] += s;
        }
    }
	
	//Возвращение result из функции
	return result;
}
