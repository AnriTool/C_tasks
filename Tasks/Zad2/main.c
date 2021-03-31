#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	double doub_matrix[3][3]; //Объявляем матрицу 3x3 из вещественных чисел
	double diagonal[2];//Объявляю отдельный массив для ответов, для матрицы 3x3
	int int_matrix[2][2]; //Объявляем матрицу 2x2 из целых чисел
	int int_matrix_pow[2][2]; //Матрица 2x2 возведённая в квадрат
	int i,j,k,s; //перменные для цикла, и переменная s для перемножения матриц

//Часть кода, связанная с матрицей 3x3	
	printf("Enter 3x3 matrix(enter numbers separated by spaces)\n");
	for (i = 0; i < 3; i++) //Первый цикл
		for (j = 0; j < 3; j++) //Второй цикл
			scanf("%lf",&doub_matrix[i][j]); //Записываем эллементы для матрицы 
	// Если проходить по коду, то изменения происходят так (i,j):(0,0)(0,1)(0,2)(1,0)(1,1)(1,2)(2,0)(2,1)(2,2); 
	// Тоесть когда j изменяется до максимума, только тогда увеличивается i 
	
	diagonal[0] = 0; //Обнуляю значения, вдруг там оказалась "каша"
	diagonal[1] = 0;
	
	//Заполнение диагоналей
	for (i = 0; i < 3; i++)
	{
		diagonal[0] += doub_matrix[i][i]; //Основная диагональ
		diagonal[1] += doub_matrix[2-i][i]; //Побочная диагональ 
	}
	printf("Main diagonal: %lf\nSecond diagonal: %lf\n",diagonal[0],diagonal[1]); //Вывожу диагонали

//Часть кода, связанная с матрицей 2x2
	//Ввод матрицы 2x2
	printf("Enter 2x2 matrix(enter numbers separated by spaces)\n");
	for (i = 0; i < 2; i++) //Первый цикл
		for (j = 0; j < 2; j++) //Второй цикл
			scanf("%d",&int_matrix[i][j]); //Записываем эллементы для матрицы 
	
	//Обнуление матрицы, в которую мы будем записывать возведённую в степень, во имя избежания "каши" 
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			int_matrix_pow[i][j] = 0;
	
	//Умножение матрицы саму на себя(возведение в квадрат)
	for (i = 0; i<2; i++) {
        for (j = 0; j<2; j++) {
            s = 0;
            for (k = 0; k<2; k++) {
                s += int_matrix[i][k] * int_matrix[k][j];
            }
            int_matrix_pow[i][j] += s;
        }
    }
	//Вывод возведённой в квадрат матрицы
	printf("matrix squared\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ",int_matrix_pow[i][j]);
		printf("\n");
	}
	
	return 0;
}
