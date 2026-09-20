#include "1klass.h"
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

// приведение к нижнему регистру дл€ windows-1251
char toLower1251(unsigned char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    if (c >= 192 && c <= 223) return c + 32; // а-€
    if (c == 168) return 184; // Є
    return c;
}

string LaboratoryWork1::cleanAndLower(const string& word) {
    string res;
    for (char c : word) {
        unsigned char uc = c;
        // оставл€ем только буквы
        if ((uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z') ||
            (uc >= 192 && uc <= 255) || uc == 168 || uc == 184) {
            res += toLower1251(uc);
        }
    }
    return res;
}

bool LaboratoryWork1::isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// задание 1: 
void LaboratoryWork1::task1_countUniqueWords(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ошибка открыти€ файла!\n";
        return;
    }

    map<string, int> wordCount;
    string word;
    while (file >> word) {
        string cleanWord = cleanAndLower(word);
        if (!cleanWord.empty()) {
            wordCount[cleanWord]++;
        }
    }

    cout << "--- результат задани€ 1 ---\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << " - " << pair.second << "\n";
    }
}

// задание 2: 
void LaboratoryWork1::task2_indexWordPositions(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ошибка открыти€ файла!\n";
        return;
    }

    map<string, vector<int>> wordPositions;
    string word;
    int wordIndex = 0;

    while (file >> word) {
        string cleanWord = cleanAndLower(word);
        if (!cleanWord.empty()) {
            wordPositions[cleanWord].push_back(wordIndex);
            wordIndex++;
        }
    }

    cout << "\n--- результат задани€ 2 ---\n";
    for (const auto& pair : wordPositions) {
        cout << pair.first << " Ц ";
        for (size_t i = 0; i < pair.second.size(); ++i) {
            cout << pair.second[i];
            if (i < pair.second.size() - 1) cout << ", ";
        }
        cout << "\n";
    }
}

// задание 3a: 
void LaboratoryWork1::task3a_squarePrimes(vector<int>& vec) {
    transform(vec.begin(), vec.end(), vec.begin(), [this](int x) {
        return isPrime(x) ? x * x : x;
        });
}

// задание 3b: 
void LaboratoryWork1::task3b_sortOddAscEvenDesc(vector<int>& vec) {
    sort(vec.begin(), vec.end(), [](int a, int b) {
        bool a_odd = (a % 2 != 0);
        bool b_odd = (b % 2 != 0);

        if (a_odd && !b_odd) return true;
        if (!a_odd && b_odd) return false;

        if (a_odd) return a < b;
        return a > b;
        });
}

// задание 3c: 
vector<int> LaboratoryWork1::task3c_findUniqueInRange(const vector<int>& vec, int min_val, int max_val) {
    vector<int> result;

    // копируем элементы из диапазона
    copy_if(vec.begin(), vec.end(), back_inserter(result),
        [min_val, max_val](int x) { return x >= min_val && x <= max_val; });

    // сортируем и удал€ем дубликаты
    sort(result.begin(), result.end());
    auto last = unique(result.begin(), result.end());
    result.erase(last, result.end());

    return result;
}