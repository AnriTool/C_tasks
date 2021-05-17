#include <stdarg.h>
int sum(int n, ...) //�������������� ������� 
{
    int res = 0; //���������� ����� 0(�����)
    va_list pointer; //������ ��������� ���� va_list
    va_start(pointer, n); //������ ��������� ������ ��������� - n��� �������� ����������
    while (n)
    {
        res += va_arg(pointer,int); //���������� � ���������� - ��������, �� ������� ��������� ���������(��� ���� ��� ������������� ��������� � ���������� ���������)
        --n; //��������� n
    }
    va_end(pointer); //���� ������� ���������(�����)
    return res;
}

int max(int n, ...) //��� �� ���� �����, ����� ����� ���������� - p, � ������� ���������� va_arg, ���� ��������� ��� �� ������� �� ��������
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


int min(int n, ...) //������ ���� < �� >
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

double average(int n, ...) // ��� ������� ������� ����� � ����� �� �����������
{
    double res = 0;
    int i;
    va_list pointer;
    va_start(pointer, n);
    i = n; //����������� ����������
    while (n)
    {
        res += va_arg(pointer,int);
        --n;
    }
    va_end(pointer); 
    res = res/i;
    return res;
}
