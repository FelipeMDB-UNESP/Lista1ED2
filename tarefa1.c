#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QUANT_REGISTROS 10
#define TAM_NOME 15
#define TAM_SOBRENOME 15
#define TAM_NOME_RUA 26

typedef struct dado {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char rua[TAM_NOME_RUA];
    int numero_casa;
} DADO;

int main() {

    FILE* arq;

    DADO buffer[QUANT_REGISTROS];
    int i=0;

    if ((arq = fopen("fixo.dat","rb")) == NULL) {
        fclose(arq);
        exit(0);    
    }

    while (fread(buffer, sizeof(DADO), 1, arq))
        printf("\nRegistro %d:\n%s %s\n%s\n%i\n", ++i, buffer[0].nome,buffer[0].sobrenome,buffer[0].rua,buffer[0].numero_casa);
    
    rewind(arq);
    fread(buffer, sizeof(buffer), 1, arq);
    
    for(i=0; i<QUANT_REGISTROS; i++) 
        printf("\nRegistro %d:\n%s %s\n%s\n%i\n", i+1, buffer[i].nome,buffer[i].sobrenome,buffer[i].rua,buffer[i].numero_casa);

    fclose(arq);
}