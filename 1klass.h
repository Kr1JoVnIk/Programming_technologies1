#pragma once
#include <string>
#include <vector>

using namespace std;

class LaboratoryWork1 {
public:
    // задание 1: 
    void task1_countUniqueWords(const string& filename);

    // задание 2: 
    void task2_indexWordPositions(const string& filename);

    // задание 3a: 
    void task3a_squarePrimes(vector<int>& vec);

    // задание 3b: 
    void task3b_sortOddAscEvenDesc(vector<int>& vec);

    // задание 3c: 
    vector<int> task3c_findUniqueInRange(const vector<int>& vec, int min_val, int max_val);

private:
    
    string cleanAndLower(const string& word);
    bool isPrime(int n);
};