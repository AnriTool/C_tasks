#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Структура
struct human{
char name[20];
char surname[20];
int year;
};


int main()
{
	FILE *in, *out;
		
	struct human *old; // Массив из структуры, в который мы будем записывать, то есть изначальный массив
	struct human *sorted; //Новый массив, созданный на основе массива old, с сортировкой по годам
	struct human temp; //Нужен для сортировки, как временная переменная, куда мы записываем значение, чтоб оно не пропало.
	int i,j,n; //Переменные для циклов

	in = fopen("names.txt","r");
	out = fopen("newnames.txt","w");

//Определяю колличество строк в файле( этот кусок : "%*[^\n]%*c" - нашёл в интернете)
while (fscanf(in, "%*[^\n]%*c") != EOF) {
		n = n + 1;
	}	
	fclose(in);
	in = fopen("names.txt","r");
	
//Выделяю память для всех массивов из структур.
old = (struct human *)malloc(n*sizeof(struct human)); 
sorted = (struct human *)malloc(n*sizeof(struct human));


for (i = 0; i < n; i++)
{
	fscanf(in,"%s%s%d\n", &old[i].name, &old[i].surname, &old[i].year);	
}

//Копирую первый массив в новый
for (i = 0; i < n; i++)
{
	strcpy(sorted[i].name,old[i].name);
	strcpy(sorted[i].surname,old[i].surname);
	sorted[i].year = old[i].year;
}


//Пузырьковая сортировка нового массива
for (i = 0; i < n; i++)
{
	for (j = n-1; j > i; j--)
	{
		if (sorted[j-1].year > sorted[j].year)
		{
			//Меняю местами
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

	//Закрываю ранее использованные txt файлы и очищаю память
	free(sorted);
	free(old);
	fclose(in);
	fclose(out);
	return 0;
}

