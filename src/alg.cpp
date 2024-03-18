// Copyright 2021 NNTU-CS
#include <cstdint>

int countPairs1(int *arr, int len, int value) {
    int summa = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if(value == arr[i] + arr[j]) {
                summa = summa + 1;
            }
        }
    }
    return summa;
}
int countPairs2(int *arr, int len, int value) {
    int summa = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len-1; j > i; --j) {
            if(value == arr[i] + arr[j]) {
                summa = summa + 1;
            }
        }
    }
    return summa;
}
int binarySearch(int* arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
        return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int summa = 0;
    for (int i = 0; i < len; ++i) {
        int secondElement = value - arr[i];
        int index = binarySearch(arr, i + 1, len - 1, secondElement);
        if (index != -1) {
            summa++;
        }
    }
    return summa;
}
