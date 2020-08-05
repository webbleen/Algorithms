#include <iostream>
#include <time.h>

void selection_sort(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        int ith = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[ith]) {
                ith = j;
            }
        }
        int t = a[i];
        a[i] = a[ith];
        a[ith] = t;
    }
}

void print_a(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
        if ((i+1)%30 == 0)
        {
            std::cout << std::endl;
        }
        
    }
    std::cout << std::endl;
}

#define MAX_NUMBER 5000

int main() {
    int a[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; i++) {
        a[i] = rand() % MAX_NUMBER;
    }

    int n = sizeof(a) / sizeof(int);

    clock_t start,finish;
    start = clock();
    selection_sort(a, n);
    finish = clock();

    print_a(a, n);
    
    std::cout << "time eclipse: " << (double)(finish-start)/CLOCKS_PER_SEC << " sec" << std::endl;

    return 0;
}
