#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int n,i,j,result = 0; //Создаём переменные для размерности, циклов и результат
/*
	//Оставил для ручного ввода размерности матрицы
	printf("Enter demensions: ");
	scanf("%d",n); //задаём размерность нашей матрицы
*/	
	n = 3; //Присваиваем размерность(если вводим вручную - надо снести это строку, она будет лишней)
	
	int matrix[n][n],solutions[n*2+2];
	
	printf("Enter matrix:\n");
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			scanf("%d",&matrix[i][j]); //Ввод матрицы 
	
	
	//Обнуляю диагонали
	solutions[n*2] = 0;
	solutions[n*2+1] = 0;	
	
	//Заполняю
	for(i=0; i<n ;i++)
	{
		//Основная диагональ
		solutions[n*2] += matrix[i][i];
		//Вторичная диагональ
		solutions[n*2+1] += matrix[n-i-1][i];
		//Суммы строк
		solutions[i] = 0;
		//Суммы колон
		solutions[n+i] = 0;
    	for(j=0; j<n ;j++)
    	{
     		//Подсчеты для строк
     		solutions[i] += matrix[i][j];
     		//Подсчет для колон
     		solutions[n+i] += matrix[j][i];
    	}
//    	printf("%d line = %d \n",i+1, solutions[i] ); // Вывод строк(debug)
//		printf("%d column = %d \n",i+1, solutions[n+i]); // Вывод столбцов(debug)
	}
	
//	printf("Main diagonal = %d \n",solutions[n*2]); //Вывод основной диагонали(debug)
//	printf("Second diagonal = %d \n",solutions[n*2+1]); //Вывод побочной диагонали(debug)
	
	for (i = 0; i < n*2+2; i++)
		for (j = 0; j < n*2+2; j++)
		{
			if (solutions[i] == solutions[j]) //Если один из результатов соответствует дургому, то добавляем 1 к результату
				result += 1;			
		}
	
	if (((n*2+2)*(n*2+2)) == result) //Если в результате будет квадрат колонок+столбцов+диагоналей, то значит, что все столбцы, колонки и диагонали - равны.
		printf("it's a magic square\n");
	else 
		printf("it's no a magic square\n");
		
//	printf("Result = %d \n",result); //Эта строка нужна для вывода результата(debug)
	
	return 0;
}
