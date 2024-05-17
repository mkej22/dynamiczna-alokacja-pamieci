// Created by Administrator on May 3, 2024
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

FILE * filePtr;

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if(arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

int findMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if(arr[i] < minVal) minVal = arr[i];
    }
    return minVal;
}

float computeAverage(int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; ++i ) {
        sum += arr[i];
    }
    float avg = (float)sum / size;
    return avg;
}

void writeFile(int arr[], int size)
{
    filePtr = fopen("numbers.txt", "w+");
    if (filePtr == 0) {
        exit(1);
    }
    for (int u = 0; u < size ; ++u) {
        fputc(arr[u], filePtr);
    }

    fclose(filePtr);
}

void readFromFile(int arr[], int size)
{
    filePtr = fopen("numbers.txt", "r+");
    fseek(filePtr, 0, SEEK_SET);
    printf("Contents of the file:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = fgetc(filePtr);
        fseek(filePtr, 0, SEEK_CUR);
        printf("%d\n", arr[i]);
    }
    printf("\n");
    fclose(filePtr);
}

int* addValue(int *arr, int *s) {
    int element;
    (*s)++;
    arr = (int *)realloc(arr, (*s) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }
    printf("Enter number to add: ");
    scanf("%d", &element);
    arr[(*s) - 1] = element;
    return arr;
}

void printArr(int arr[], int s)
{
    for (int i = 0; i < s; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");
}

int* removeValues(int *arr, int *s) {
    if (*s == 0) {
        printf("Array is already empty!\n");
        return arr;
    }
    (*s)--;
    arr = (int *)realloc(arr, (*s) * sizeof(int));
    if (arr == NULL && *s > 0) {
        printf("Memory allocation error!");
        exit(1);
    }
    return arr;
}