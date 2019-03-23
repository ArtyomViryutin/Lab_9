#pragma once
typedef struct

{

	char fio[20];

	int age;

	int growth;

	double weight;

	char kind[20];

	char charac[20];


} sport;


int input();   // Функция заполнения базы данных 

int add();	// Функция добавление записи в базу данных

int delete(); //Удаление заданной записи из базы

int search(); // Функция поиска записи по заданному полю

int change(); // Функция редактирования заданной записи в базе

void sort(); // Функция сортировки данных в базе по заданному полю

void output(); // Функция вывода на экран содержимого базы в табличном виде

int checker_letter(char* string); // Функция проверки на корректность ввода строк
