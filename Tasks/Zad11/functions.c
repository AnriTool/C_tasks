#include <stdarg.h>
int sum(int n, ...) //Инициализируем функцию 
{
    int res = 0; //Результату задаём 0(сумма)
    va_list pointer; //Создаём указатель типа va_list
    va_start(pointer, n); //Делаем стартовой точкой указателя - nный эллемент переменных
    while (n)
    {
        res += va_arg(pointer,int); //Прибовляем к результату - аргумент, на котором находится указатель(при этом оно автоматически переходит к следующему эллементу)
        --n; //уменьшаем n
    }
    va_end(pointer); //Типа очизаем указатель(вроде)
    return res;
}

int max(int n, ...) //тут всё тоже самое, кроме одной переменной - p, в которую записываем va_arg, чтоб несколько раз не прыгать за итерацию
{
    int res = -9999999999999, p;
    va_list pointer;
    va_start(pointer, n);
    while (n)
    {
    	p = va_arg(pointer,int);
        if (res < p)
        	res = p;
        --n;
    }
    va_end(pointer); 
    return res;
}


int min(int n, ...) //Меняем знак < на >
{
    int res = 9999999999999, p;
    va_list pointer;
    va_start(pointer, n);
    while (n)
    {
    	p = va_arg(pointer,int);
        if (res > p)
        	res = p;
        --n;
    }
    va_end(pointer); 
    return res;
}

double average(int n, ...) // Тут считаем обычную сумму и делим на колличество
{
    double res = 0;
    int i;
    va_list pointer;
    va_start(pointer, n);
    i = n; //Колличество эллементов
    while (n)
    {
        res += va_arg(pointer,int);
        --n;
    }
    va_end(pointer); 
    res = res/i;
    return res;
}
