#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ONE_OVER_BILLION 1E-9 

typedef struct no{
    char caractere;
    struct no* ponto;
    struct no* traco;
} t_no;

void inserirNo(t_no* raiz, char *codigo, char letra);

t_no* criarNo(char dado){
    t_no* novo = (t_no*) malloc(sizeof(t_no));
    novo->caractere = dado;
    return novo;
}

t_no* montarArvore(){
    t_no *raiz = criarNo(' ');
    FILE *arvore = fopen( "./morse.txt", "r" );
    char codigo[9], letra;
    while(!feof(arvore)){
        fscanf(arvore, "%c %s\n", &letra, codigo);
        inserirNo(raiz, codigo, letra);
    }
    fclose(arvore);
    return raiz;
}

void inserirNo(t_no* raiz, char *codigo, char letra){
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
                raiz->ponto = criarNo(' ');    
            inserirNo(raiz->ponto,codigo+1,letra);
        }
        else if(codigo[0] == '-'){
            if(raiz->traco == NULL)
                raiz->traco = criarNo(' ');    
            inserirNo(raiz->traco,codigo+1,letra);
        }
    }
}

char traduzir(t_no *raiz, char *codigo){
    if(*codigo == '\0')
        return raiz->caractere;
    else{
        if(*codigo=='.')
            return traduzir(raiz->ponto, codigo+1);
        if(*codigo=='-')
            return traduzir(raiz->traco, codigo+1);
    }
    return ' ';
}

int main(){
    t_no *raiz = montarArvore();
    struct timespec requestStart, requestEnd;
    clock_gettime(CLOCK_REALTIME, &requestStart);
    FILE *mensagem = fopen( "./mensagemLonga.txt", "r" );
    char codigo[9],a;
    a=fgetc(mensagem);
    while(!feof(mensagem)){
        putchar(a);
        a=fgetc(mensagem);
    }
    fseek(mensagem, 0, SEEK_SET);
    fscanf(mensagem, "%[.-]", codigo);
    printf("%c", traduzir(raiz, codigo));
    while(!feof(mensagem)){
        fscanf(mensagem, "%[ ]", codigo);
        fscanf(mensagem, "%[^ ]", codigo);
        printf("%c", traduzir(raiz, codigo));
    }
    fclose(mensagem);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    // Calculate time it took
    double accum = ( requestEnd.tv_sec - requestStart.tv_sec )+( requestEnd.tv_nsec - requestStart.tv_nsec )*ONE_OVER_BILLION;;
    printf( "%lf\n", accum );
    return( EXIT_SUCCESS );
    return 0;
}

