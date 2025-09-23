/*******************************************************************************
 * Лабораторная работа №1 по дисциплине "Программирование"                     *
 *-----------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                   *
 * Project Name  : Функции и последовательности чисел                          *
 * File Name     : sequences.h                                                *
 * Programmer(s) :                                                             *
 * Modifyed By   :                                                             *
 * Created       : 15/09/25                                                    *
 * Last Revision : 24/09/25                                                    *
 * Comment(s)    : Заголовочный файл с объявлениями функций для формирования  *
 *                 последовательностей (упорядоченные и неупорядоченные       *
 *                 массивы), измерение последовательностей и частично         *
 *                 упорядоченные последовательности. Формирование              *
 *                 последовательностей на экране                               *
 *******************************************************************************/

#ifndef SEQUENCES_H
#define SEQUENCES_H

#include <iostream>     // Подключение библиотеки ввода/вывода
#include <iomanip>      // Подключение библиотеки для манипулятора setw
#include <chrono>       // Подключение библиотеки для измерения времени выполнения алгоритмов
#include <cmath>        // Для математических функций (sin)

using namespace std;    // Использование пространства имен std

/*******************************************************************/
/*            КОНСТАНТЫ И ПЕРЕМЕННЫЕ ПРОГРАММЫ                     */
/*******************************************************************/
const int interval = 20;                           // Интервал для алгоритма

/*******************************************************************/
/*              ОБЪЯВЛЕНИЯ ФУНКЦИЙ ПРОГРАММЫ                      */
/*******************************************************************/

// Для целых чисел
// Формирование последовательности по возрастанию
int linevozrastanie(int* pznachenue, int number, const int rand_max);

// Формирование последовательности по убыванию
int lineubuvanie(int* pznachenue, int number, const int rand_max);

// Формирование случайной последовательности
int slucaynaya(int* pznachenue, int number, const int rand_max);

// Формирование пилообразной последовательности
int piloobraznaya(int* pznachenue, int number, const int rand_max);

// Формирование ступенчатой последовательности
int stupenchataya(int* pznachenue, int number, const int rand_max);

// Формирование квази-упорядоченной последовательности
int kvazi(int* pznachenue, int number, const int rand_max);

// Формирование синусоидальной последовательности
int sinus(int* pznachenue, int number, const int rand_max);

// Создание динамического массива - целые числа
void sozdanie(int** pznachenue, int& number);

// Удаление динамического массива - целые числа
void udalenie(int* pznachenue);

// Выбор функции из меню
int(*MENU())(int*, int, const int);

// Вывод последовательности на экран
void pechat_int_mass(int* pznachenue, int number, const int rand_max);

// Для чисел с плавающей точкой
double linevozrastanie(double* pznacheniedoub, int number, const int rand_max);
double lineubuvanie(double* pznacheniedoub, int number, const int rand_max);
double slucaynaya(double* pznacheniedoub, int number, const int rand_max);
double piloobraznaya(double* pznacheniedoub, int number, const int rand_max);
double stupenchataya(double* pznacheniedoub, int number, const int rand_max);
double kvazi(double* pznacheniedoub, int number, const int rand_max);
double sinus(double* pznacheniedoub, int number, const int rand_max);
void sozdanie(double** pznacheniedoub, int& number);
void udalenie(double* pznacheniedoub);
double (*MENU2())(double*, int, const int);
void pechat_doub_mass(double pznacheniedoub[], int number, const int rand_max);

// Функция вывода меню
void pechatusloviy();

#endif // SEQUENCES_H
