/*------------------------- Trabalho 2 - Árvores -------------------------
*       header da lista
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _LIST_H_
#define _LIST_H_
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
      
    /* definicao de tipos */
    typedef struct elemento{
        char simbolo;
        char codigo[10];
        struct elemento *prox;
    } t_elemento;

    typedef struct lista{
        t_elemento *inicio;
        t_elemento *fim;
    } t_lista;
    
    /* declaracao de prototipos de funcoes */
    extern t_lista *novaLista();
    extern t_lista * dicionario();
    extern void insereInicio(t_lista *lista, char simbolo, char * codigo);
    extern char procura(char * codigo, t_lista * l);
    extern void decodificaLista(t_lista * tradutor);   

#endif