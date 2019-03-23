#define _CRT_SECURE_NO_WARNINGS
#include "func.h"

#include <stdio.h>

#include <string.h>

#include <malloc.h>

#include "locale.h"

#include <ctype.h> // библиотека с isspace

#define filename "myfile.bin"


int checker_letter(char* string)
{
	for (int i = 0; i < strlen(string); i++) // пока и меньше длины строки

	{
		if ((!(string[i]<0 && string[i]>-65 || string[i] == -72 || string[i] == -88)) && isspace(string[i]) == 0) // isspace возвращаем ненулевое значение если символ это - 
																								// символом пробела, возврата каретки, горизонтальной табуляции, вертикальной
																							//табуляции, перевода формата или новой строки; в противном случае возвращается 0

		{
			printf("Вы ввели недопустимые символы.Вы можете вводить только буквы,притом русские.\n\n"); // вывод при некорректном вводе

			return -1;
		}

	}

	return 0;
}


int input()

{
	system(" chcp 1251 "); // подключение кодировки 1251 (русские буквы)

	system(" cls"); // очистка экрана консоли

	FILE *f;

	sport sp;

	int n, i;

	char str[30];

	if (!(f = fopen(filename, "wb"))) { // создаем бинарный файл для записи 
		printf("Файл не может быть открыт.\n"); //сообщение о том, что файл не может быть открыт
		system("pause");
		exit(1); // выход из программы 
	}

	printf("Введите количество спортсменов: "); // ввод количества спортсменов и проверка ввода на корректность

	if(!scanf("%d",&n)) {

		getchar();

		printf("Вы ввели неправильное количество. Попробуйте еще раз.\n\n");

		printf("Введите количество спортсменов: ");

		scanf("%d", &n);
	}

	while (n <= 0) {

		getchar();

		printf("Вы ввели неправильное количество. Попробуйте еще раз.\n\n");

		printf("Введите количество спортсменов: ");

		scanf("%d", &n);
	}



	for (i = 0; i < n; i++) // цикл ввода и записи в файл данных

	{

		gets(str);

		printf("\nВведите данные %d-го спортсмена:\n", i + 1);

		printf("Введите ФИО: ");

		gets(sp.fio); // ввод ФИО

		if (checker_letter(sp.fio) == -1)  // проверка на корректность ввода
			return -1; // в случае некорректного ввода, возвращает -1 и выходит в общее меню выбора действия


		printf("Введите возраст: "); // ввод возраста

		if (!scanf("%d", &sp.age)) // проверка на корректность ввода
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin); // очистка потока ввода

			getchar();

			return -1; // в случае некорректного ввода, возвращает -1 и выходит в общее меню выбора действия

		}

		if( sp.age<0 || sp.age >120 ) // проверка на реальность введенного возраста

		{
			printf("Вы ввели неправильное значение.Человека с данным возрастом не может существовать\n\n");

			fflush(stdin); 

			getchar();

			return -1;

		}

		
		printf("Введите рост: "); // ввод роста

		if (!scanf("%d", &sp.growth)) // проверка на корректность ввода
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin); 

			getchar();

			return -1;

		}

		if (sp.growth < 0 || sp.growth >250) // проверка не реальность введенного роста

		{
			printf("Вы ввели неправильное значение.Человека с данным ростом не может существовать\n\n");

			fflush(stdin); 

			getchar();

			return -1;

		}

		

		printf("Введите вес: ");

		if (!scanf("%lf", &sp.weight)) // ввод веса и проверка на корректность ввода
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		if (sp.weight < 0 || sp.weight >250) // проверка на реальность введенного веса

		{
			printf("Вы ввели неправильное значение.Человека с данным весом не может существовать\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		gets(str);

		printf("Введите вид спорта: "); // ввод вида спорта

		gets(sp.kind);

		printf("Введите характеристику: "); // ввод характеристики

		gets(sp.charac);

		fwrite(&sp, sizeof(sport), 1, f); // запись структуры в файл

		fflush(stdin); // очистка потока ввода

	}

	printf("\n");

	fclose(f); // закрываем файл

	printf("База данных спортсменов заполнена.\n\n");
	return 0;

}

int add()

{

	system(" cls"); // очистка экрана консоли

	char str[30];

	FILE *f;

	sport sp;

	fflush(stdin);

	gets(str);

	f = fopen(filename, "rb+"); // открываем бинарный файл для чтения и запис

	printf("Введите данные нового спортсмена:\n");

	printf("Введите ФИО: ");

	gets(sp.fio);

	if (checker_letter(sp.fio) == -1) 
		return -1;

	printf("Введите возраст: ");

	if (!scanf("%d", &sp.age))
	{
		printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

		fflush(stdin);

		getchar();

		return -1;

	}

	if (sp.age < 0 || sp.age >120)

	{
		printf("Вы ввели неправильное значение.Человека с данным возрастом не может существовать\n\n");

		fflush(stdin);

		getchar();

		return -1;

	}




	printf("Введите рост: ");

	if (!scanf("%d", &sp.growth))
	{
		printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

		fflush(stdin);

		getchar();

		return -1;

	}

	if (sp.growth < 0 || sp.growth >250)

	{
		printf("Вы ввели неправильное значение.Человека с данным ростом не может существовать\n\n");

		fflush(stdin);

		getchar();

		return -1;

	}

	

	printf("Введите вес: ");

	if (!scanf("%lf", &sp.weight))
	{
		printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

		fflush(stdin);

		getchar();

		return -1;

	}

	if (sp.weight < 0 || sp.weight >250)

	{
		printf("Вы ввели неправильное значение.Человека с данным весом не может существовать\n\n");

		fflush(stdin);

		getchar();

		return -1;

	}


	gets(str);

	printf("Введите вид спорта: ");

	gets(sp.kind);


	printf("Введите характеристику: ");

	gets(sp.charac);

	fseek(f, 0, SEEK_END); // возвращаем указатель на конец файла

	fwrite(&sp, sizeof(sport), 1, f); // записываем новую запись

	fclose(f); // закрываем файл

	printf("\nСпортсмен добавлен\n\n");

	return 0;

}

int delete()

{

	system(" cls"); // очистка экрана консоли

	FILE *f;

	sport sp;

	int i, ind, size;

	f = fopen(filename, "rb+"); // открываем бинарный файл для чтения и записи

	printf("Введите номер спортсмена, которого вы хотите удалить: "); // ввод номера спортсмена , которого нужно удалить

	if (!scanf("%d", &ind)) {
		getchar();
		printf("Вы ввели неправильное значение.\n");
			return -1;
	}

	fseek(f, 0, SEEK_END); // возвращаем указатель на конец файла

	size = ftell(f) / sizeof(sport); // ftell -возвращает  текущее значение указателя положения в файле в байтах 
									 // поделив это значение на размер структуры находим количество элементов в файле
	while ((ind > size) || (ind < 1)) // пока номер спортсмена больше количества спортсменов(элементов) или меньше 1 делаем повторный ввод

	{

		printf("\nВ базе нет спортсмена с таким номером, введите новый номер спортсмена: ");

		scanf("%d", &ind);

	}


	--ind; // уменьшаем номер спортсмена на 1

	for (i = ind; i < size - 1; ++i) // сдвигаем все элементы после элемента с номером ind влево на размер структуры

	{

		fseek(f, (i + 1) * sizeof(sport), SEEK_SET); // ставим указатель после элемента который хотим удалить

		fread(&sp, sizeof(sport), 1, f); // считываем следующий элемент

		fseek(f, i * sizeof(sport), SEEK_SET); // ставим указатель перед элементом который хотим удалить

		fwrite(&sp, sizeof(sport), 1, f); // записываем туда считанный элемент 

	}

	chsize(_fileno(f), (size - 1) * sizeof(sport)); // уменьшаем размер файла

	fclose(f); // закрываем файл

	printf("\nСпортсмен удален\n\n");

	return 0;

}

int search()

{
	system(" cls"); // очищаем экран консоли

	int k = 1;

	FILE *f;

	sport sp;

	char str[30];

	int  ind, num;
	double num1;

	f = fopen(filename, "rb"); // открываем бинарный файл для чтения 

	printf("Выберите поле:\n1 - ФИО\n2 - Возраст\n3 - Рост\n4 - Вес\n5 - Вид спорта\n6 - Характеристика\n\n"); // выбор поля по которому нужно сделать поиск

	scanf("%d", &ind);
	
	printf("\n");

	gets(str);

	switch (ind)

	{

	case 1:

		printf("Введите ФИО: ");

		gets(str);

		if (checker_letter(str) == -1)
			return -1;

		printf("\nНайденные спортсмены:\n");

		while (!feof(f)) // пока не конец файла

		{

			fread(&sp, sizeof(sport), 1, f); // считываем элементы 

			if (!feof(f)) // пока не конец файла 

			{

				if (!strcmp(sp.fio, str)) // сравниваем строки , если они равны - возвращается 0

					printf("|%d|%-26s|%-9d|%-7d|%-6.2lf|%-20s|%-25s|\n",k, sp.fio, sp.age, sp.growth, sp.weight, sp.kind, sp.charac); // выводим элемент структуры с совпавшем полем

			}
			k++; // счетчик номера элемента

		}

		printf("\n");


		break;

	case 2:

		printf("Введите возраст: ");

		if (!scanf("%d", &num))
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		if (num < 0 || num >120)

		{
			printf("Вы ввели неправильное значение.Человека с данным возрастом не может существовать\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		printf("\nНайденные спортсмены:\n");

		while (!feof(f)) 

		{

			fread(&sp, sizeof(sport), 1, f);

			if (!feof(f))

			{

				if (sp.age == num)

					printf("|%d|%-26s|%-9d|%-7d|%-6.2lf|%-20s|%-25s|\n",k, sp.fio, sp.age, sp.growth, sp.weight, sp.kind, sp.charac);

			}
			k++;

		}


		printf("\n");

		break;

	case 3:

		printf("Введите рост: ");

		if (!scanf("%d", &num))
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		if (num < 0 || num >250)

		{
			printf("Вы ввели неправильное значение.Человека с данным ростом не может существовать\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		printf("\nНайденные спортсмены:\n");

		while (!feof(f))

		{

			fread(&sp, sizeof(sport), 1, f);

			if (!feof(f))

			{

				if (sp.growth == num)

					printf("|%d|%-26s|%-9d|%-7d|%-6.2lf|%-20s|%-25s|\n",k, sp.fio, sp.age, sp.growth, sp.weight, sp.kind, sp.charac);

			}

			k++;

		}

		printf("\n");

		break;

	case 4:

		printf("Введите вес: ");

		if (!scanf("%lf", &num1))
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		if (num1 < 0 || num1 >250)

		{
			printf("Вы ввели неправильное значение.Человека с данным весом не может существовать\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		printf("\nНайденные спортсмены:\n");

		while (!feof(f))

		{

			fread(&sp, sizeof(sport), 1, f);

			if (!feof(f))

			{

				if (sp.weight == num1)

					printf("|%d|%-26s|%-9d|%-7d|%-6.2lf|%-20s|%-25s|\n",k, sp.fio, sp.age, sp.growth, sp.weight, sp.kind, sp.charac);

			}

			k++;

		}


		printf("\n");

		break;

	case 5:

		printf("Введите вид спорта ");

		gets(str);

		printf("\nНайденные спортсмены:\n");

		while (!feof(f))

		{

			fread(&sp, sizeof(sport), 1, f);

			if (!feof(f))

			{

				if (!strcmp(sp.kind, str))

					printf("|%d|%-26s|%-9d|%-7d|%-6.2lf|%-20s|%-25s|\n",k, sp.fio, sp.age, sp.growth, sp.weight, sp.kind, sp.charac);

			}

			k++;

		}

		printf("\n");

		break;

	case 6:

		printf("Введите характеристику: ");

		gets(str);

		printf("\nНайденные спортсмены:\n");

		while (!feof(f)) 

		{

			fread(&sp, sizeof(sport), 1, f);

			if (!feof(f))

			{

				if (!strcmp(sp.charac, str))

					printf("|%d|%-26s|%-9d|%-7d|%-6.2lf|%-20s|%-25s|\n",k, sp.fio, sp.age, sp.growth, sp.weight, sp.kind, sp.charac);

			}

		}

		printf("\n");

		break;

	default:

		printf("Вы ввели неправильное число\n\n");

	}

	fclose(f);

	return 0;

}

int change()

{

	system(" cls");

	FILE *f;

	sport sp;

	char str[30];

	int i, ind, size;

	f = fopen(filename, "rb+"); // открываем файл для чтения и записи

	printf("Введите номер спортсмена: "); // ввод номера спортсмена записи которого нужно изменить

	if (!scanf("%d", &ind))
	{
		printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

		fflush(stdin);

		getchar();

		return -1;

	}

	fseek(f, 0, SEEK_END); // ставим указатель на конец файла

	size = ftell(f) / sizeof(sport); // определяем размер структуры

	while ((ind > size) || (ind < 1))

	{

		printf("\nВ базе нет спортсмена с таким номером, введите новый номер спортсмена: ");

		scanf("%d", &ind);

	}

	--ind;

	fseek(f, ind * sizeof(sport), SEEK_SET); // ставим указатель перед нужным элементом

	fread(&sp, sizeof(sport), 1, f); // считываем нужный элемент структуры 

	printf("\nВыберите поле:\n1 - ФИО\n2 - Возраст\n3 - Рост\n4 - Вес\n5 - Вид спорта\n6 - Характеристика\n\n");

	scanf("%d", &i);

	getchar();

	switch (i) // выбор поля которое нужно изменить

	{

	case 1:

		printf("Введите ФИО: ");

		gets(sp.fio); // перезаписываем возраст
		if (checker_letter(sp.fio) == -1)
			return - 1;

		printf("\n");

		break;

	case 2:

		printf("Введите возраст: ");

		if (!scanf("%d", &sp.age)) // перезаписываем возраст
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		if (sp.age < 0 || sp.age >120) 

		{
			printf("Вы ввели неправильное значение.Человека с данным возрастом не может существовать\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		printf("\n");

		break;

	case 3:

		printf("Введите рост: ");

		if (!scanf("%d", &sp.growth)) // перезаписываем рост
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		if (sp.growth < 0 || sp.growth >250)

		{
			printf("Вы ввели неправильное значение.Человека с данным ростом не может существовать\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		printf("\n");

		break;

	case 4:

		printf("Введите вес: ");

		if (!scanf("%lf", &sp.weight)) // перезаписываем вес
		{
			printf("Вы ввели неправильное значение.Вы можете писать только цифры.\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		if (sp.weight < 0 || sp.weight >250)

		{
			printf("Вы ввели неправильное значение.Человека с данным весом не может существовать\n\n");

			fflush(stdin);

			getchar();

			return -1;

		}

		printf("\n");

		break;

	case 5:

		printf("Введите вид спорта: ");

		gets(sp.kind); // перезаписываем вид спорта

		printf("\n");

		break;

	case 6:

		printf("Введите характеристику: ");

		gets(sp.charac); // перезаписываем характеристику

		printf("\n");

		break;

	default:

		printf("Вы ввели неправильное число\n\n");

	}

	fseek(f, ind * sizeof(sport), SEEK_SET); // возвращаем указатель перед изменяемым элементом

	fwrite(&sp, sizeof(sport), 1, f); // записываем измененный элемент

	fclose(f); // закрываем файл

	printf("Запись была редактирована.\n\n");

	return 0;

}

void sort()

{

	system(" cls");

	FILE *f;

	sport tmp;

	sport *sps = NULL;

	int i, j, ind1, ind2, size;

	f = fopen(filename, "rb+"); // открываем файл для записи и чтения

	fseek(f, 0, SEEK_END); // определяем количество элементов в файле

	size = ftell(f) / sizeof(sport);

	fseek(f, 0, SEEK_SET); // ставим указатель на конец файла

	sps = (sport*)malloc(size * sizeof(sport)); // динамически выделяем память для массива sps размером структуры

	for (i = 0; i < size; ++i)

	{

		fread(&sps[i], sizeof(sport), 1, f); // считываем элементы файла в массив sps

	}

	printf("Выберите поле по которому вы хотите сортировать:\n1 - ФИО\n2 - Возраст\n3 - Рост\n4 - Вес\n5 - Вид спорта\n6 - Характеристика\n\n");

	scanf("%d", &ind1);

	printf("\n");

	switch (ind1)

	{

	case 1:

		printf("1 - по возрастанию\n2 - по убыванию\n\n");

		scanf("%d", &ind2);

		printf("\n");

		switch (ind2)

		{

		case 1:

			for (i = size - 1; i >= 0; i--) // делаем size итераций по массиву

			{

				for (j = 0; j < i; j++) 

				{

					if (strcmp(sps[j].fio, sps[j + 1].fio) > 0) // сравниваем строки и сортируем их пузырьком по возрастанию(любая цифра больше русской буквы)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		case 2:

			for (i = size - 1; i >= 0; i--) 

			{

				for (j = 0; j < i; j++)

				{

					if (strcmp(sps[j].fio, sps[j + 1].fio) < 0) // сравниваем строки и сортируем их пузырьком по убыванию

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		default:

			printf("Вы ввели неправильное число\n\n"); // ошибка в случае некорректного выбора

		}

		break;

	case 2:

		printf("1 - по возрастанию\n2 - по убыванию\n\n");

		scanf("%d", &ind2);

		printf("\n");

		switch (ind2)

		{

		case 1:

			for (i = size - 1; i >= 0; i--) 

			{

				for (j = 0; j < i; j++)

				{

					if (sps[j].age > sps[j + 1].age) // сравниваем числа и сортируем их пузырьком

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		case 2:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (sps[j].age < sps[j + 1].age)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		default:

			printf("Вы ввели неправильное число\n\n");

		}

		break;

	case 3:

		printf("1 - по возрастанию\n2 - по убыванию\n\n");

		scanf("%d", &ind2);

		printf("\n");

		switch (ind2)

		{

		case 1:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (sps[j].growth > sps[j + 1].growth)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		case 2:for (i = size - 1; i >= 0; i--)

		{

			for (j = 0; j < i; j++)

			{

				if (sps[j].growth < sps[j + 1].growth )

				{

					tmp = sps[j];

					sps[j] = sps[j + 1];

					sps[j + 1] = tmp;

				}

			}

		}

			   break;

		default:

			printf("Вы ввели неправильное число\n\n");

		}

		break;

	case 4:

		printf("1 - по возрастанию\n2 - по убыванию\n\n");

		scanf("%d", &ind2);

		printf("\n");

		switch (ind2)

		{

		case 1:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (sps[j].weight > sps[j + 1].weight)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		case 2:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (sps[j].weight < sps[j + 1].weight)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		default:

			printf("Вы ввели неправильное число\n\n");

		}

		break;

	case 5:

		printf("1 - по возрастанию\n2 - по убыванию\n\n");

		scanf("%d", &ind2);

		printf("\n");

		switch (ind2)

		{

		case 1:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (strcmp(sps[j].kind, sps[j + 1].kind) > 0)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		case 2:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (strcmp(sps[j].kind, sps[j + 1].kind) < 0)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		default:

			printf("Вы ввели неправильное число\n\n");

		}

		break;

	case 6:

		printf("1 - по возрастанию\n2 - по убыванию\n\n");

		scanf("%d", &ind2);

		printf("\n");

		switch (ind2)

		{

		case 1:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (strcmp(sps[j].charac, sps[j + 1].charac) > 0)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		case 2:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (strcmp(sps[j].charac, sps[j + 1].charac) < 0)

					{

						tmp = sps[j];

						sps[j] = sps[j + 1];

						sps[j + 1] = tmp;

					}

				}

			}

			break;

		default:

			printf("Вы ввели неправильное число\n\n");

		}

		break;

	default:

		printf("Вы ввели неправильное число\n\n");

	}

	fseek(f, 0, SEEK_SET); // ставим указатель на начало файла 

	for (i = 0; i < size; ++i) // записываем все элементы массива файла

	{

		fwrite(&sps[i], sizeof(sport), 1, f);

	}

	free(sps); // очищаем массив

	sps = NULL;

	fclose(f); // закрываем файл

	printf("Сортировка была выполнена.\n\n");

}

void output()

{
	system("cls");

	int i = 1;

	FILE *f;

	sport sp;

	f = fopen(filename, "rb"); // открываем файл для чтения 

	printf("База данных:\n"); // создание прекрасной таблицы
	printf("\n\n");
	printf(" ____________________________________________________________________________________________________ \n");
	printf("| |                          |         |       |      |                    |                         |\n");
	printf("|№|           ФИО            | Возраст |  Рост |  Вес |    Вид спорта      |      Характеристика     |\n");
	printf("|_|__________________________|_________|_______|______|____________________|_________________________|\n");
	while (!feof(f)) //пока не конец файла

	{

		fread(&sp, sizeof(sport), 1, f); // считываем элементы файла

		if (!feof(f))

			printf("|%d|%-26s|%-9d|%-7d|%-6.2lf|%-20s|%-25s|\n",i, sp.fio, sp.age, sp.growth, sp.weight, sp.kind, sp.charac); // вывод

		i++; // счетчик номеров спортсменов 

	}

	printf("|_|__________________________|_________|_______|______|____________________|_________________________|\n");

	printf("\n");

	fclose(f); // закрываем файл

}
