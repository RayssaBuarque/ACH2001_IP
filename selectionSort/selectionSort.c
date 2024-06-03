#define tamanhoArray 7

// função que retorna o índice do menor item da array
int menor(int *array){
    int iaux = 0; // índice auxiliar

    // para cada item da array, cheque se a[iaux] < a[i]
    // se for verdade, salve o novo índice menor.
    for(int i = 1; i<tamanhoArray; i++){
        if(array[i] < array[iaux]){
            iaux = i;
        }
    }

    return iaux;
}

// função de organização da array
void selection_sort(int *array){
    int imenor;

    // para cada item da array:
    for(int i=0; i<tamanhoArray--; i++){ 
        imenor = menor(array); // colete seu menor índice
        int aux = array[i]; // armazene o valor atual do loop numa var auxiliar
        array[i] = array[imenor]; // substitua-o pelo menor valor
        array[imenor] = aux; // coloque o valor auxiliar na antiga posição do menor valor 
        array++; // ???????????
    }
}
