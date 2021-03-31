#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Загружаем библиотеку, работающую со строками

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char string[80]; //Объявляем массив из символов(char), что будет являться строкой.
	int i,len; // i - переменная счётчик, для цикла. len - переменная для длины строки
	
	printf("Enter string:\n");
	fgets(string,80,stdin); //Читаем строку, результат записываем в переменную string, ограничение в 80 символов, ввод с клавиатуры(stdin)
	
	len = strlen(string); //Задаём переменной len - значение, равное длине строки
		
	printf("Modified string:\n"); 	
	//Заменяем буквы		
	for (i = 0; i < len; i++) //Задаем i = 0; пока i < len, выполнять цикл, а по прохождению одной итерации - увиличивать i на 1
	{
		if (string[i] == 'a') //Если i-й эллемент строки - буква а
			string[i] = 'A'; //Заменить маленькую a на A
		if (string[i] == 'b')//Если i-й эллемент строки - буква b
			string[i] = 'B'; //Заменить маленькую a на B
		printf("%c",string[i]); //Выводим i-й эллемент строки 
	}
	
	return 0;
}
