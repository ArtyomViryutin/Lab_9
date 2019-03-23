#define _CRT_SECURE_NO_WARNINGS

#include "func.h"

#include <stdio.h>

#include <locale.h>

int main()

{

	int i, check = 0;

	setlocale(LC_ALL, "rus"); // подключение русских букв

	system(" chcp 1251 ");

	setlocale(LC_NUMERIC, "eng"); 

	system(" cls"); // очистка экрана консоли 


	while (check == 0) // цикл для меню выбора действия 

	{

		check = 0;

		printf("Выберите действие:\n"); // варианты действий
		printf("1 - Заполнение базы данных\n2 - Добавление записи в базу данных\n3 - Удаление заданной записи из базы\n4 - Поиск записи по заданному полю\n5 - Редактирование заданной записи в базе\n6 - Сортировка данных в базе по заданному полю\n7 - Вывод на экран содержимого базы в табличном виде\n0 - Выход из программы\n");

		if (!scanf("%d", &i)) // проверка на корректность ввода действия 
		{
			i = -1;        
			getchar();
		}

		printf("\n");

		switch (i)

		{

		case 1:

			input();

			break;

		case 2:

			add();

			break;

		case 3:

			delete();

			break;

		case 4:

			search();

			break;

		case 5:

			change();

			break;

		case 6:

			sort();

			break;

		case 7:

			output();

			break;

		case 0:

			check = 1; // условие выхода из цикла

			break;

		default:

			printf("Вы ввели неправильное число\n\n");

		}

	}

	return 0;

}


