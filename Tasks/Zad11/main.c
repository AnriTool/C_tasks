#include <stdio.h>
#include <stdlib.h>
#include "functions.h" //�������� ������������ ���� � ���������

int main()
{   
	//��� �� ������ ���������� � ������� �������
    printf("%d \n", sum(5, 12, 21, 13, 4, 5));
    printf("%d \n", max(5, 12, 21, 13, 4, 5));
    printf("%d \n", min(5, 12, 21, 13, 4, 5));
	printf("%lf \n", average(5, 12, 21, 13, 4, 5));    
    return 0;
}
