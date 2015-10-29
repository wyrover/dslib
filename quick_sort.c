#include "dslib.h"

void swap(int* x, int* y)
{
     int temp = *x;
     *x = *y;
     *y = temp;
}

void partition(int a[], int pivot, int left, int right)
{
    int i = left;
    int j = right;

    while(i<=j) {
        while (a[i] < a[pivot]) {
            i++;
        }
        while (a[j] > a[pivot]) {
            j--;
        }
        if (i <= j) {
            swap(&a[i] , &a[j]);
            i++;
            j--;
        }
    }
}

void quick_sort(int a[], int left, int right)
{
    int pivot = (right + left)/2;
    if (left < right) {
        partition(a,pivot,left, right);
        quick_sort(a, left, pivot );
        quick_sort(a,pivot+1, right);
    }
}

