#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch_one_test(int x, int v[], int n);

int main(void)
{
    int v[100000];
    for (int i = 0; i < 100000; i++)
        v[i] = i * 2;  

    int target = 18876;
    int n = 100000;
    int result;

    clock_t start, end;


    start = clock();
    for (int i = 0; i < 100000; i++)
        result = binsearch(target, v, n);
    end = clock();
    printf("Original result = %d, time = %lf sec\n",
           result, (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < 100000; i++)
        result = binsearch_one_test(target, v, n);
    end = clock();
    printf("Improved result = %d, time = %lf sec\n",
           result, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch_one_test(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (v[low] == x)
        return low;
    else
        return -1;
}

