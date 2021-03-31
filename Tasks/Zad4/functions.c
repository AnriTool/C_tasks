#include <stdbool.h> //Загружаем библиотеку для работы с bool
#include <math.h> //Загружаем математику для фунции sqrt()

bool exist (double a,double b,double c) //Создаем функцию, на которую подаются a,b,c, которая проверяет существование треугольника
{
	if ((a+b>c)&&(a+c>b)&&(c+b>a)) //Проверяем существование треугольника
		return true; //Возвращаем true
	else //Иначе
		return false;//Возвращаем false
}

double per(double a,double b,double c) //Функция для поиска периметра треугольника
{
	double P;
	P = a + b + c;
	return P;	
}

double sqr(double a,double b,double c) //Функция поиска плозади, через полупериметр
{
	double S,p;
	p = per(a,b,c)/2; //Полупериметр
	S = sqrt(p*(p-a)*(p-b)*(p-c)); //Берём корень из полумериметра, умноженного на разности полупериметра и сторон
	return S;
}
