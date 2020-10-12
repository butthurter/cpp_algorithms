#include <iostream>
using namespace std;

void swap(int* mas, int a, int b ) {
    int mesto = mas[a];
    mas[a] = mas[b];
    mas[b] = mesto;
}

void shaker(int* mas, int size) {
    int left = 0;
    int right = size;

    while(left <= right) {
        for (int i = left; i < right; i++) {
            if (i + 1 >= size) {
                break;
            }
            if (mas[i + 1] < mas[i])
                swap(mas, i, i + 1);
        }
        right--;

        for (int i = right - 1; i > left; i--) {
            if (i - 1 < 0) {
                break;
            }
            if (mas[i - 1] > mas[i])
                swap(mas, i, i - 1);
        }
        left++;
    }
}

int main() {
    const int size = 10;

    int mas[size];
    for (int s = 0; s < size; s++) {
        cin >> mas[s];
    }

    shaker(mas, size);

    for (int k = 0; k < size; k++) {
        cout << mas[k] << " ";
    }

    return 0;
}