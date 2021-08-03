#include <iostream>
#include <chrono>
#include <stdlib.h>

#define SIZE 150

using namespace std;

int* generateRandomArray() {
    static int array[SIZE];

    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    return array;
}

double sumOfArray(const int* array) {
    int sum = 0;

    for(int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    return sum;
}

double findMeanOfArray(int* array) {
    double sum = sumOfArray(array);

    return sum / SIZE;
}

string intToTableElement(int num) {
    if(num < 10) {
        return "0" + to_string(num);
    } else {
        return to_string(num);
    }
}

void printArray(int* array) {
    for(int i = 0; i < SIZE; i++) {
        cout << intToTableElement(array[i]) << " ";

        if(i % 10 == 0 && i != 0) cout << endl;
    }

    cout << endl;
}
// --------------------

int main() {
    auto t1 = chrono::high_resolution_clock::now();

    int* array  = generateRandomArray();
    double mean = findMeanOfArray(array);

    auto t2 = chrono::high_resolution_clock::now();

    printArray(array);
    cout << mean << endl;
    cout << endl << "Duration: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds";
}