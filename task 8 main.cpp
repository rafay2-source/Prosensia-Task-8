#include <iostream>
using namespace std;

bool isOdd(int n) { return n % 2 != 0; }

void conditionalSwap(int* x, int* y) {
    int diff = *x - *y;
    if (diff < 0) diff = -diff;
    if (diff > 10) { int* t = new int(*x); *x = *y; *y = *t; delete t; }
}

void printArrayViaPointer(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " @ " << (arr + i) << endl;
}

int* findFirstEven(int* arr, int size) {
    for (int i = 0; i < size; i++) if (*(arr + i) % 2 == 0) return (arr + i);
    return nullptr;
}

void incrementOddsByAddress(int* arr, int size) {
    for (int i = 0; i < size; i++) if (isOdd(*(arr + i))) (*(arr + i))++;
}

int countGreaterThan(int* arr, int size, int* refPtr) {
    int c = 0;
    for (int i = 0; i < size; i++) if (*(arr + i) > *refPtr) c++;
    return c;
}

int main() {
    int a, b, arr[5];
    cout << "Enter two integers: "; cin >> a >> b;
    cout << "Enter 5 integers: "; for (int i = 0; i < 5; i++) cin >> *(arr + i);

    cout << "\nBefore: a=" << a << ", b=" << b << endl;
    conditionalSwap(&a, &b);
    cout << "After : a=" << a << ", b=" << b << endl;

    cout << "\nArray & Addresses:\n"; printArrayViaPointer(arr, 5);

    incrementOddsByAddress(arr, 5);
    cout << "\nArray after odds incremented:\n"; printArrayViaPointer(arr, 5);

    int* even = findFirstEven(arr, 5);
    cout << (even ? "\nFirst even: " + to_string(*even) : "\nNo even number found.") << endl;

    cout << "\nCount > a: " << countGreaterThan(arr, 5, &a) << endl;
    return 0;
}
