/*------------------------- Trabalho 1 - Pilhas -------------------------
*       header da pilha com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _LIST_H_
#define _LIST_H_
    
    #include <stdlib.h>
    
    /* definicao de constantes */
    #define t_int 1
    #define t_char 2
    #define t_double 3
    
    /* definicao de tipos */
    typedef struct elemento{
        void *dado;
        int tipoDado;
        struct elemento *proximo;
    } t_element;
    typedef struct list{
        t_element *inicio;
        t_element *fim;
    } t_list;
    
    /* declaracao de prototipos de funcoes */
    extern t_list *newList();
    extern void addStart(t_list *list, void *dado, int tipoDado);
    extern void addEnd(t_list *list, void *dado, int tipoDado);
    extern int isEmpty(t_list *list);
    extern int removeFirstInt(t_list *list);
    extern char removeFirstChar(t_list *list);
    extern double removeFirstDouble(t_list *list);
    extern int getNextType(t_list *list);   

#endif
