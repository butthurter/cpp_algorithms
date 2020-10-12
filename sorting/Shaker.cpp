#include <iostream>
using namespace std;

void swapInt(int* array, int a, int b ) {
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

void shaker(int* array, int size) {
    int left = 0;
    int right = size;

    while(left <= right) {
        for (int i = left; i < right; i++) {
            if (i + 1 >= size) {
                break;
            }
            if (array[i + 1] < array[i]) {
                swapInt(array, i, i + 1);
            }
        }
        right--;

        for (int i = right - 1; i > left; i--) {
            if (i - 1 < 0) {
                break;
            }
            if (array[i - 1] > array[i]) {
                swapInt(array, i, i - 1);
            }
        }
        left++;
    }
}

int main() {
    const int size = 10;

    int array[size];
    for (int & ma : array) {
        cin >> ma;
    }

    shaker(array, size);

    for (int ma : array) {
        cout << ma << " ";
    }

    delete[] & array;

    return 0;
}