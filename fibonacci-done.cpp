#include <iostream>
#include <chrono>

#define N 15

using namespace std;

int iterativeApproach(int n) {
    int first = 0;
    int last = 1;

    for(int i = 0; i < n; i++) {
        int newValue = first + last;

        first = last;
        last = newValue;
    }

    return last;
}

int recursiveApproach(int n) {
    if(n == 0 || n == 1) return 1;

    return recursiveApproach(n - 1) + recursiveApproach(n - 2);
}

int main() {
    cout << "Iterative approach" << endl;

    auto t1 = chrono::high_resolution_clock::now();
    for(int i = 0; i <= N; i++) {
        cout << iterativeApproach(i) << " ";
    }
    auto t2 = chrono::high_resolution_clock::now();

    cout << endl << "Duration: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds";

    cout << endl << "Recursive approach" << endl;
    t1 = chrono::high_resolution_clock::now();
    for(int i = 0; i <= N; i++) {
        cout << recursiveApproach(i) << " ";
    }
    t2 = chrono::high_resolution_clock::now();

    cout << endl << "Duration: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds";
}