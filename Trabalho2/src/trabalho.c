#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char caractere;
    struct no* ponto;
    struct no* traco;
}

no* criarNo(char dado){
    no* novo = (no*) malloc(sizeof(no));
    novo->caractere = dado;
    return novo;
}

void inserirNo(no* raiz, char *codigo, char letra){
    if(codigo[1]=='\0'){
        if(codigo[0]=='.'){
            if(raiz->ponto == NULL)
                raiz->ponto = criarNo(letra);
            else
                raiz->ponto->caractere = letra;
        } else if(codigo[0] == '-'){
            if(raiz->traco == NULL)
                raiz->traco = criarNo(letra);
            else
                raiz->traco->caractere = letra;
        }
    } else {
        if(codigo[0] == '.'){
            if(raiz->ponto == NULL)
                raiz->ponto = criarNo('+');    
            inserirNo(raiz->ponto,codigo[1],letra);
        }
        else if(codigo[0] == '-'){
            if(raiz->traco == NULL)
                raiz->traco = criarNo('+');    
            inserirNo(raiz->ponto,codigo[1],letra);
        }
    }
}

int main(){

    return 0;
}

