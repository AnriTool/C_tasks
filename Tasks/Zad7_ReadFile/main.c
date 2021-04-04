#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���������
struct human{
char name[20];
char surname[20];
int year;
};


int main()
{
	FILE *in, *out;
		
	struct human *old; // ������ �� ���������, � ������� �� ����� ����������, �� ���� ����������� ������
	struct human *sorted; //����� ������, ��������� �� ������ ������� old, � ����������� �� �����
	struct human temp; //����� ��� ����������, ��� ��������� ����������, ���� �� ���������� ��������, ���� ��� �� �������.
	int i,j,n; //���������� ��� ������

	in = fopen("names.txt","r");
	out = fopen("newnames.txt","w");

//��������� ����������� ����� � �����( ���� ����� : "%*[^\n]%*c" - ����� � ���������)
while (fscanf(in, "%*[^\n]%*c") != EOF) {
		n = n + 1;
	}	
	fclose(in);
	in = fopen("names.txt","r");
	
//������� ������ ��� ���� �������� �� ��������.
old = (struct human *)malloc(n*sizeof(struct human)); 
sorted = (struct human *)malloc(n*sizeof(struct human));


for (i = 0; i < n; i++)
{
	fscanf(in,"%s%s%d\n", &old[i].name, &old[i].surname, &old[i].year);	
}

//������� ������ ������ � �����
for (i = 0; i < n; i++)
{
	strcpy(sorted[i].name,old[i].name);
	strcpy(sorted[i].surname,old[i].surname);
	sorted[i].year = old[i].year;
}


//����������� ���������� ������ �������
for (i = 0; i < n; i++)
{
	for (j = n-1; j > i; j--)
	{
		if (sorted[j-1].year > sorted[j].year)
		{
			//����� �������
			temp = sorted[j-1];
			sorted[j-1] = sorted[j];
			sorted[j] = temp;
			
		}
	}
}

for (i = 0; i < n; i++)
{
	fprintf(out,"%s %s %d\n", sorted[i].name, sorted[i].surname, sorted[i].year);	
}

	//�������� ����� �������������� txt ����� � ������ ������
	free(sorted);
	free(old);
	fclose(in);
	fclose(out);
	return 0;
}

