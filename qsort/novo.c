#include <stdio.h>
#include <stdlib.h>
#include <string.h>




 void insertionSort(){
    // int tamanhoArray = sizeof(arrayBaguncado)/sizeof(int);
    int arraydes[4] = {0, 4, 2, 1};


    for(int j = 1; j<4; j++){
        int key = arraydes[j];
        int i = j-1;
        while((i>0) && (arraydes[i] > key)){
            arraydes[i+1] = arraydes[i];
            i = i - 1;
        }
        arraydes[i + 1] = key;
    }
     for (int i = 0; i < 4; i++)
    {
        printf("%d\n", arraydes[i]);
    }
}

int main()
{
    insertionSort();
    
    return 0;
}
