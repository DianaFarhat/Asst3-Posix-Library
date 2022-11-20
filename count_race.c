#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>


//Size of Array
int LENGTH=100;
int COUNT=0;
int * array;

//Threads
int MAX_THREAD;
int PART=0;

//Functions
int * initializeArray(int LENGTH){
    int * array= (int *) malloc(LENGTH * sizeof(int));
    for (int i = 0; i < LENGTH; i++) {
        int num = (rand() %
        (5 - 1 + 1)) + 1;
        array[i]=num;
    }
    return array;
}

void printArray(int * array){
    printf("{ ");
    for (int i=0; i< LENGTH; i++){
        if (i==LENGTH-1){
           printf("%d ", array[i]); 
           printf("}\n");
           return;
        }
        printf("%d , ", array[i]);
    }
   
}

void * count1s(void * threadId){
    int * i = (int *)  threadId;
    int id = * i; 
    int part_length= LENGTH/MAX_THREAD;
    int start= (id-1)* part_length;
    int end= (id)*part_length;

    for (int i=start; i<end; i++){
        if (array[i]==1){
            COUNT ++;
        }
    }
    
}

void runProgram(int threadsNb){
    MAX_THREAD= threadsNb;
    //Begin Time Counter
    clock_t begin = clock();
    // Initialize Array
    array=  initializeArray(LENGTH);
    printArray(array);
    // Create threads
    pthread_t threads[MAX_THREAD];
    for (int i = 0; i < MAX_THREAD; i++){
        pthread_create(&threads[i], NULL, count1s,&i);
            
    }
    // Joining threads i.e. waiting for all 4 threads to complete
    for (int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);
        
    }
    printf("The array has %d ones.\n", COUNT);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds.\n", time_spent);
    COUNT=0;
}

int main(){
    for(int i=0; i<100; i++){
        printf("Test Case: %d \n", i);
        runProgram(1);
    }
}
