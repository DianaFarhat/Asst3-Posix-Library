#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int length=100;
int count;
int * array;
int * initializeArray(int length){
    int * array= (int *) malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        int num = (rand() %
        (5 - 1 + 1)) + 1;
        array[i]=num;
    }
    return array;
}

void printArray(int * array){
    printf("{ ");
    for (int i=0; i< length; i++){
        if (i==length-1){
           printf("%d ", array[i]); 
           printf("}");
           return;
        }
        printf("%d , ", array[i]);
    }
    printf("}\n");
}

int count1s(){
    count=0;
    for (int i=0; i<length; i++){
        if (array[i]==1){
            count ++;
        }
    }
    return count;
}
int main(){
    clock_t begin = clock();
    array=  initializeArray(length);
    printArray(array);
    int answer= count1s();
    printf("The array has %d ones.\n", answer);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", time_spent);
}
