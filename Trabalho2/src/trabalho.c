#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ONE_OVER_BILLION 1E-9 


typedef struct elemento{
    char simbolo;
    char codigo[10];
    struct elemento *prox;
} t_elemento;

typedef struct lista{
    t_elemento *inicio;
    t_elemento *fim;
} t_lista;

t_lista * novaLista(){
    t_lista * l = (t_lista*) malloc(sizeof(t_lista));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

typedef struct no{
    char caractere;
    struct no* ponto;
    struct no* traco;
} t_no;


void insereInicio(t_lista *lista, char simbolo, char * codigo){
    t_elemento * elemento = (t_elemento*) malloc(sizeof(t_elemento));
    elemento->simbolo = simbolo;
    sprintf(elemento->codigo, "%s", codigo);
    elemento->prox = lista->inicio;
    lista->inicio = elemento;
    if(lista->fim == NULL) 
        lista->fim = lista->inicio;
}

t_lista * dicionario(){
    int lido = 1;
    char simbolo, codigo[15];
    t_lista * lista = novaLista();
    FILE * morse = fopen("morse.txt", "r");
    while(lido != -1){
        lido = fscanf(morse, "%c %s\n", &simbolo, codigo);
        if(lido != -1)
            insereInicio(lista, simbolo, codigo);
    }
    fclose(morse);
    return lista;
}

char procura(char * codigo, t_lista * l){
    int naoAchou = 1;
    t_elemento * atual = l->inicio;
    while(naoAchou){
        if(strcmp(atual->codigo, codigo) != 0)
            atual = atual->prox;
        else
            naoAchou = 0;
    }
    return atual->simbolo;
}

void decodificaLista(t_lista * tradutor){
	int lido = 1;
    char codigo[10];
	FILE * mensagem = fopen("mensagem.txt", "r");

	while(lido != -1){
		lido = fscanf(mensagem, "%s ", codigo);
		if(lido != -1){
			if(strcmp(codigo, "/") != 0)
				putchar(procura(codigo, tradutor));
			else
				putchar(' ');
		}
	}
	fclose(mensagem);
}

t_no* criarNo(char dado){
    t_no* novo = (t_no*) malloc(sizeof(t_no));
    novo->caractere = dado;
    return novo;
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

char traduzir(t_no *raiz, char *codigo){
    if(*codigo == '\0')
        return raiz->caractere;
    else if (*codigo != '/'){
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
    FILE *mensagem = fopen( "./mensagem.txt", "r" );
<<<<<<< HEAD
    char codigo[9],a;/*
=======
    char codigo[9],a;
>>>>>>> 385f1538f3784a4bf0b0983f0627491c281b0ef1
    a=fgetc(mensagem);
    while(!feof(mensagem)){
        putchar(a);
        a=fgetc(mensagem);
    }
    fseek(mensagem, 0, SEEK_SET);
    while(fscanf(mensagem, "%s ", codigo) != -1){
        putchar(traduzir(raiz, codigo));
    }
    fclose(mensagem);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    // Calculate time it took
    double accum = ( requestEnd.tv_sec - requestStart.tv_sec )+( requestEnd.tv_nsec - requestStart.tv_nsec )*ONE_OVER_BILLION;;
    printf( "%lf\n", accum );
    
    clock_gettime(CLOCK_REALTIME, &requestStart);
    t_lista * tradutor = dicionario();
	decodificaLista(tradutor);
	clock_gettime(CLOCK_REALTIME, &requestEnd);
    // Calculate time it took
    accum = ( requestEnd.tv_sec - requestStart.tv_sec )+( requestEnd.tv_nsec - requestStart.tv_nsec )*ONE_OVER_BILLION;;
    printf( "%lf\n", accum );    

    return 0;
}

