#include "Funcoes.c"
char * getNome();
void escreve_arquivo(char * nom, char * senha);
char * atribui_string(char * str1);
int tamanho_string(char * str);
int compara_string(char * str1, char * str2);
void constroi(Lista **l);
void insere_ordenada(Lista **l, int c, char * elem, char * senha);
void enumera(Lista **l);
int busca(Lista **l, char * elem);
No* remove_elem(Lista **l, char * elem);
void destroi(Lista **l);
No* remove_elemKey(Lista **l, int elem);
