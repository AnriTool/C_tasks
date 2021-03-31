#include <stdio.h>
#include <stdlib.h>
#include "functions.h" //подгружаем наш заголовочный файл с описанными в нем функциями
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c; //Переменные для сторон треугольника
	printf("Enter a b c:\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	
	if (exist(a,b,c)) //Используем нашу функцию на проверку существования. Можно не писать условие, т.к. если оно будет существовать, то вернёт true, что означает, что условие выполнено
	{
		printf("Perimetr = %lf\n", per(a,b,c));//выводим периметр(можно даже без указания переменной, указывая саму функцию с её аргументами)
		printf("Square = %lf\n", sqr(a,b,c));//выводим площадь(также указывая функцию)
	}
	else //Иначе
		printf("Triangle not exist\n");//Выводим что "такой треугольник не существует"
			
	return 0;
}
