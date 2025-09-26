/*******************************************************************************
 * Лабораторная работа №1 по дисциплине "Программирование"                     *
 *-----------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                   *
 * Project Name  : Функции и последовательности чисел                          *
 * File Name     : main.cpp                                                    *
 * Programmer(s) :                                                             *
 * Modifyed By   :                                                             *
 * Created       : 15/09/25                                                    *
 * Last Revision : 24/09/25                                                    *
 * Comment(s)    : Основная функция программы для работы с последовательностями*
 *                 чисел (упорядоченные и неупорядоченные массивы). Добавлена  *
 *                 поддержка экспоненциальных последовательностей              *
 *******************************************************************************/

#include "sequences.h"
#include <string>
#include <ctime>
#include <cstdlib>

// Функция для демонстрации ступенчатой последовательности
void demo_stupenchataya()
{
    cout << "===============================================" << endl;
    cout << "    ДЕМОНСТРАЦИЯ СТУПЕНЧАТОЙ ФУНКЦИИ         " << endl;
    cout << "===============================================" << endl;
    
    const int demo_size = 12;
    const int rand_max = 15;
    int* demo_array = new int[demo_size];
    
    // Генерируем ступенчатую последовательность
    stupenchataya(demo_array, demo_size, rand_max);
    
    cout << "Ступенчатая последовательность (целые числа):" << endl;
    cout << "+------------------------------+" << endl;
    for (int i = 0; i < demo_size; i++) {
        cout << "| " << setw(17) << setfill(' ') << demo_array[i] 
             << setw(11) << setfill(' ') << "| n = " << i + 1 << endl;
    }
    cout << "+------------------------------+" << endl;
    
    // Визуализация ступенек
    cout << "\nВизуализация ступенек:" << endl;
    cout << "Высота каждой ступеньки увеличивается:" << endl;
    for (int i = 0; i < demo_size; i++) {
        cout << "Ступень " << (i + 1) << ": ";
        int height = demo_array[i] / 5; // Масштабируем для визуализации
        for (int j = 0; j < height && j < 20; j++) {
            cout << "█";
        }
        cout << " (" << demo_array[i] << ")" << endl;
    }
    
    delete[] demo_array;
    
    // Демонстрация для чисел с плавающей точкой
    double* demo_array_double = new double[demo_size];
    stupenchataya(demo_array_double, demo_size, rand_max);
    
    cout << "\nСтупенчатая последовательность (с плавающей точкой):" << endl;
    cout << "+------------------------------+" << endl;
    for (int i = 0; i < demo_size; i++) {
        cout << "| " << setw(17) << setfill(' ') << demo_array_double[i] 
             << setw(11) << setfill(' ') << "| n = " << i + 1 << endl;
    }
    cout << "+------------------------------+" << endl;
    
    // Визуализация ступенек для double
    cout << "\nВизуализация ступенек (с плавающей точкой):" << endl;
    for (int i = 0; i < demo_size; i++) {
        cout << "Ступень " << (i + 1) << ": ";
        int height = (int)(demo_array_double[i] / 3); // Масштабируем для визуализации
        for (int j = 0; j < height && j < 25; j++) {
            cout << "█";
        }
        cout << " (" << demo_array_double[i] << ")" << endl;
    }
    
    delete[] demo_array_double;
    
    cout << "\nНажмите Enter для продолжения...";
    cin.ignore();
    cin.get();
    system("clear");
}

/**************************************************************/
/*            ОСНОВНАЯ ФУНКЦИЯ ПРОГРАММЫ                      */
/**************************************************************/

int main()
{
    // Простейший парсер аргументов командной строки
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    bool user_seed = false;
    bool skip_demo = false;

    for (int i = 1; i < argc; ++i) {
        string arg(argv[i]);
        if (arg == "--help" || arg == "-h") {
            cout << "Использование: " << argv[0]
                 << " [--seed=N | -s N] [--skip-demo] [--help]" << endl
                 << "  --seed=N, -s N   Установить зерно генератора rand()" << endl
                 << "  --skip-demo      Пропустить демонстрацию ступенчатой функции" << endl
                 << "  --help, -h       Показать эту справку и выйти" << endl;
            return 0;
        } else if (arg.rfind("--seed=", 0) == 0) {
            try {
                seed = static_cast<unsigned int>(stoul(arg.substr(8)));
                user_seed = true;
            } catch (...) {
                cerr << "Некорректное значение для --seed. Ожидается целое число." << endl;
                return 1;
            }
        } else if (arg == "-s") {
            if (i + 1 < argc) {
                try {
                    seed = static_cast<unsigned int>(stoul(argv[++i]));
                    user_seed = true;
                } catch (...) {
                    cerr << "Некорректное значение после -s. Ожидается целое число." << endl;
                    return 1;
                }
            } else {
                cerr << "Отсутствует значение после -s." << endl;
                return 1;
            }
        } else if (arg == "--skip-demo") {
            skip_demo = true;
        } else {
            cerr << "Неизвестный параметр: " << arg << endl;
        }
    }

    // Логирование запуска программы и установка зерна генератора
    cout << "Программа запущена с " << argc << " параметрами" << endl;
    srand(seed);
    cout << "Зерно генератора rand(): " << seed
         << (user_seed ? " (задано пользователем)" : " (по умолчанию)") << endl;

    // system("color F0");
    setlocale(LC_ALL, "Rus");                   // Установка русской локали
    // system("cls");                              // Очистка экрана (Windows only)
    system("clear");                            // Очистка экрана (Unix/macOS)

    int number = 0;                             // Количество элементов последовательности
    const int rand_max = 15;                    // Максимальное значение для генерации
    int* pznachenue = NULL;                     // Указатель на динамический массив целых чисел
    double* pznacheniedoub = NULL;              // Указатель на динамический массив чисел с плавающей точкой
    
    // Демонстрация ступенчатой функции с визуализацией
    if (!skip_demo) {
        cout << "===============================================" << endl;
        cout << "    ДЕМОНСТРАЦИЯ СТУПЕНЧАТОЙ ФУНКЦИИ         " << endl;
        cout << "===============================================" << endl;
        cout << "Ступенчатая функция создает последовательность" << endl;
        cout << "где значения группируются в 'ступеньки' с" << endl;
        cout << "постепенно увеличивающейся высотой." << endl;
        cout << "===============================================" << endl;
        cout << "Нажмите Enter для демонстрации...";
        cin.ignore();
        cin.get();
        system("clear");

        // Автоматическая демонстрация ступенчатой функции
        demo_stupenchataya();
    } else {
        cout << "Демонстрация ступенчатой функции пропущена (--skip-demo)." << endl;
    }
    
    // Работа с различными типами последовательностей включая новую экспоненциальную
    pechat_int_mass(pznachenue, number, rand_max);       // Работа с массивом целых чисел
    system("clear");                                       // Очистка экрана перед работой с числами с плавающей точкой
    pechat_doub_mass(pznacheniedoub, number, rand_max);  // Работа с массивом чисел с плавающей точкой
    
    return 0;                                            // Завершение программы
}
