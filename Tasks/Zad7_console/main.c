#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//—труктура
struct human{
char name[20];
char surname[20];
int year;	
};


int main()
{
	struct human old[4]; // ћассив из структуры, в который мы будем записывать, то есть изначальный массив
	struct human sorted[4]; //Ќовый массив, созданный на основе массива old, с сортировкой по годам
	struct human temp; //Ќужен дл€ сортировки, как временна€ переменна€, куда мы записываем значение, чтоб оно не пропало.
	int i,j; //ѕеременные дл€ циклов

//«адаю первый массив 
for (i = 0; i < 4; i++)
{
	printf("Human[%d] name surname birthyear:\n",i+1);
	scanf("%s%s%d", &old[i].name, &old[i].surname,&old[i].year);
}

// опирую первый массив в новый
for (i = 0; i < 4; i++)
{
	strcpy(sorted[i].name,old[i].name);
	strcpy(sorted[i].surname,old[i].surname);
	sorted[i].year = old[i].year;
}

//ѕузырькова€ сортировка нового массива
for (i = 0; i < 4; i++)
{
	for (j = 3; j > i; j--)
	{
		if (sorted[j-1].year > sorted[j].year)
		{
			//ћен€ю местами год
			temp = sorted[j-1];
			sorted[j-1] = sorted[j];
			sorted[j] = temp;
		}
	}
}

printf("\n");
//¬ывожу новый отсортированный массив
for (i = 0; i < 4; i++)
{
	printf("Sorted:\nHuman[%d]: %s %s %d\n",i+1,sorted[i].name, sorted[i].surname, sorted[i].year);
 } 

	return 0;
}
