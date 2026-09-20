#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>
#include "1klass.h"

using namespace std;

//  замера времени 
#define MEASURE_TIME(func_call) \
    { \
        auto _t_start = chrono::high_resolution_clock::now(); \
        func_call; \
        auto _t_end = chrono::high_resolution_clock::now(); \
        double _t_duration = chrono::duration<double, milli>(_t_end - _t_start).count(); \
        cout << "[время выполнения: " << _t_duration << " мс]\n\n"; \
    }

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    LaboratoryWork1 lab;
    string filename = "war_and_peace2.txt";

    cout << "=== задание 1: подсчет уникальных слов ===\n";
    MEASURE_TIME(lab.task1_countUniqueWords(filename));

    cout << "=== задание 2: индексация позиций слов ===\n";
    MEASURE_TIME(lab.task2_indexWordPositions(filename));

    // тестовые данные для заданий 3a-3c
    vector<int> testVec = { 12, 7, 4, 9, 2, 15, 8, 7, 3, 12, 5, 19, 4, 7 };

    cout << "=== задание 3a: возведение простых чисел в квадрат ===\n";
    cout << "исходный вектор: ";
    for (int x : testVec) cout << x << " ";
    cout << "\n";

    MEASURE_TIME(lab.task3a_squarePrimes(testVec));

    cout << "после обработки: ";
    for (int x : testVec) cout << x << " ";
    cout << "\n\n";

    cout << "=== задание 3b: сортировка (нечетные по возр., четные по убыв.) ===\n";
    MEASURE_TIME(lab.task3b_sortOddAscEvenDesc(testVec));

    cout << "отсортированный вектор: ";
    for (int x : testVec) cout << x << " ";
    cout << "\n\n";

    cout << "=== задание 3c: поиск уникальных чисел в диапазоне [5, 12] ===\n";
    vector<int> rangeResult;
    MEASURE_TIME(rangeResult = lab.task3c_findUniqueInRange(testVec, 5, 12));

    cout << "уникальные числа в диапазоне: ";
    for (int x : rangeResult) cout << x << " ";
    cout << "\n";

    system("pause");
    return 0;
}
