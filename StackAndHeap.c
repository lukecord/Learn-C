#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    clock_t stackBegin = clock();
    int stackInt = 0;
    while(stackInt < 1000000) {
        stackInt += 1;
    }
    clock_t stackEnd = clock();
    double stackTime = (double)(stackEnd - stackBegin) / CLOCKS_PER_SEC;

    clock_t heapBegin = clock();
    int* heapInt = (int*)malloc(sizeof(int));
    if (heapInt != NULL) {
        *heapInt = 0;
    }
    while(*heapInt < 1000000) {
        *heapInt += 1;
    }
    free(heapInt);
    clock_t heapEnd = clock();
    double heapTime = (double)(heapEnd - heapBegin) / CLOCKS_PER_SEC;
    printf("Stack: %f, Heap: %f\n", stackTime, heapTime);

    return 0;

} 
