#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *in, *out; //Создаём переменные in и out - которые являются указателями на файлы
	char name[100],surname[100],secondname[100]; //Создаём строковые переменные для имени, фамилии и отчества
	int date,mydate; //Переменные для 


	in = fopen("names.txt","r");  //Открываем файл names для чтения
	out = fopen("newnames.txt","w"); //Открываем файл names для записи

/* 
	//Эта часть кода нужна для ручного ввода даты, но т.к. у нас в условии сказанно 1980 год, то я закоментировал его 
	printf("enter date: ");
	scanf("%d",&mydate);

	fprintf(out,"Дата: %d\n",mydate);
*/

	mydate = 1980; //Указываем дату, после которой будем выводить

	while (fscanf(in,"%s%s%s%d\n",&name,&surname,&secondname,&date) != EOF) //Пока мы можем читать строку, строку, строку, число и не дошли до конца(EndOfFile)
	{
		if (date > mydate)//Если дата, больше моей даты(1980)
			fprintf(out,"%s %s %s %d\n",name,surname,secondname,date); //Заносим в файл out - имя, фамилию, отчество, дату
	}
	
	fclose(in); //Закрываем in
	fclose(out); //Закрываем out
	return 0;
}
