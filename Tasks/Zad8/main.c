#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Структура
struct human {
	char name[20];
	char surname[20];
	int year;
	char gndr[1];
	double height;
};


struct human *all; // Массив из структуры, в который мы будем записывать, то есть изначальный массив
struct human *sorted; //Новый массив, созданный на основе массива all, с сортировкой по годам
struct human temp; //Нужен для сортировки, как временная переменная, куда мы записываем значение, чтоб оно не пропало.
int n;
int sortint[5];


void replace(j)
{
	temp = sorted[j-1];
	sorted[j-1] = sorted[j];
	sorted[j] = temp;
}

//Функция для перетасовки эллементов
void switcher(sort)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = n-1; j > i; j--) {
			switch(sortint[sort]) {
				case 1:

					if(strcmp(sorted[j-1].name, sorted[j].name) == 1) {
						replace(j);
					}
					break;
				case 2:

					if(strcmp(sorted[j - 1].surname, sorted[j].surname) == 1) {
						replace(j);
					}
					break;
				case 3:
					if (sorted[j-1].year > sorted[j].year) {
						replace(j);
					}
					break;
				case 4:

					if(strcmp(sorted[j-1].gndr, sorted[j].gndr) == 1) {
						replace(j);
					}
					break;
				case 5:

					if (sorted[j-1].height > sorted[j].height) {
						replace(j);
					}
					break;
			}
		}
}

//Функция для сравнения предыдущего эллемента и нынешнего(чтоб отсортировать, если предыдущие - одинаковые)
void compare(prev, sort)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = n-1; j > i; j--) {
			switch (prev) {
				case 0:
					switcher(sort);
					break;
				case 1:
					if(strcmp(sorted[j-1].name, sorted[j].name) == 0)
						switcher(sort);
					break;
				case 2:
					if(strcmp(sorted[j - 1].surname, sorted[j].surname) == 0)
						switcher(sort);
					break;
				case 3:
					if (sorted[j-1].year > sorted[j].year)
						switcher(sort);
					break;
				case 4:
					if(strcmp(sorted[j-1].gndr, sorted[j].gndr) == 0)
						switcher(sort);
					break;
				case 5:
					if (sorted[j-1].height == sorted[j].height)
						switcher(sort);
					break;
			}
		}
	}
}



int main()
{
	FILE *in, *out;
	int i,j,k, prev = 0; //Переменные для циклов prev - пердыдущий цикл

	char sortstr[5];


	in = fopen("names.txt","r");
	out = fopen("newnames.txt","w");

//Определяю колличество строк в файле( этот кусок : "%*[^\n]%*c" - нашёл в интернете)
	while (fscanf(in, "%*[^\n]%*c") != EOF) {
		n = n + 1;
	}
//printf("%d\n",n);
	fclose(in);
	in = fopen("names.txt","r");

//Выделяю память для всех массивов из структур.
	all = (struct human *)malloc(n*sizeof(struct human));
	sorted = (struct human *)malloc(n*sizeof(struct human));


	for (i = 0; i < n; i++) {
		fscanf(in,"%s %s %d %s %lf\n", &all[i].name, &all[i].surname, &all[i].year, &all[i].gndr,&all[i].height);
	}

//Копирую первый массив в новый
	for (i = 0; i < n; i++) {
		strcpy(sorted[i].name,all[i].name);
		strcpy(sorted[i].surname,all[i].surname);
		sorted[i].year = all[i].year;
		strcpy(sorted[i].gndr,all[i].gndr);
		sorted[i].height = all[i].height;
	}


	printf("sorted by:\nname(n)\nsurname(s)\nbirthyear(b)\ngender(g)\nheight(h)\n"); //Спрашиваю каким образом надо отсортировать
	scanf("%s",&sortstr);//Записываю в sort - ответ

//Превращаем буквы в удобные нам цифры, с которыми можно будет рабоать через switch
	for (i = 0; i < 5; i++) {
		switch(sortstr[i]) {
			case 'n':
				sortint[i] = 1;
				break;
			case 's':
				sortint[i] = 2;
				break;
			case 'b':
				sortint[i] = 3;
				break;
			case 'g':
				sortint[i] = 4;
				break;
			case 'h':
				sortint[i] = 5;
				break;
			default :
				sortint[i] = 0;
				break;
		}
	}

	for (i = 0; i < 5; i++)
		printf("%d ",sortint[i]);
	printf("\n");

	for (i = 0; i < 5; i++) {
		compare(prev, sortint[i]);
		prev = sortint[i];
	}

	fprintf(out,"sorted by: ");
	for (i = 0; i < 5; i++) {
		switch(sortint[i]) {
			case 1:
				fprintf(out, "name ");
				break;
			case 2:
				fprintf(out, "surname ");
				break;
			case 3:
				fprintf(out, "birthyear ");
				break;
			case 4:
				fprintf(out, "gender ");
				break;
			case 5:
				fprintf(out, "height ");
				break;
		}
	}
	fprintf(out, "\n");
	for (i = 0; i < n; i++) {
		fprintf(out,"%s %s %d %s %lf\n", sorted[i].name, sorted[i].surname, sorted[i].year, sorted[i].gndr, sorted[i].height);
	}

	//Закрываю ранее использованные txt файлы и очищаю память
	free(sorted);
	free(all);
	fclose(in);
	fclose(out);

	return 0;
}

