#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	double doub_matrix[3][3]; //��������� ������� 3x3 �� ������������ �����
	double diagonal[2];//�������� ��������� ������ ��� �������, ��� ������� 3x3
	int int_matrix[2][2]; //��������� ������� 2x2 �� ����� �����
	int int_matrix_pow[2][2]; //������� 2x2 ���������� � �������
	int i,j,k,s; //��������� ��� �����, � ���������� s ��� ������������ ������

//����� ����, ��������� � �������� 3x3	
	printf("Enter 3x3 matrix(enter numbers separated by spaces)\n");
	for (i = 0; i < 3; i++) //������ ����
		for (j = 0; j < 3; j++) //������ ����
			scanf("%lf",&doub_matrix[i][j]); //���������� ��������� ��� ������� 
	// ���� ��������� �� ����, �� ��������� ���������� ��� (i,j):(0,0)(0,1)(0,2)(1,0)(1,1)(1,2)(2,0)(2,1)(2,2); 
	// ������ ����� j ���������� �� ���������, ������ ����� ������������� i 
	
	diagonal[0] = 0; //������� ��������, ����� ��� ��������� "����"
	diagonal[1] = 0;
	
	//���������� ����������
	for (i = 0; i < 3; i++)
	{
		diagonal[0] += doub_matrix[i][i]; //�������� ���������
		diagonal[1] += doub_matrix[2-i][i]; //�������� ��������� 
	}
	printf("Main diagonal: %lf\nSecond diagonal: %lf\n",diagonal[0],diagonal[1]); //������ ���������

//����� ����, ��������� � �������� 2x2
	//���� ������� 2x2
	printf("Enter 2x2 matrix(enter numbers separated by spaces)\n");
	for (i = 0; i < 2; i++) //������ ����
		for (j = 0; j < 2; j++) //������ ����
			scanf("%d",&int_matrix[i][j]); //���������� ��������� ��� ������� 
	
	//��������� �������, � ������� �� ����� ���������� ���������� � �������, �� ��� ��������� "����" 
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			int_matrix_pow[i][j] = 0;
	
	//��������� ������� ���� �� ����(���������� � �������)
	for (i = 0; i<2; i++) {
        for (j = 0; j<2; j++) {
            s = 0;
            for (k = 0; k<2; k++) {
                s += int_matrix[i][k] * int_matrix[k][j];
            }
            int_matrix_pow[i][j] += s;
        }
    }
	//����� ���������� � ������� �������
	printf("matrix squared\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ",int_matrix_pow[i][j]);
		printf("\n");
	}
	
	return 0;
}
