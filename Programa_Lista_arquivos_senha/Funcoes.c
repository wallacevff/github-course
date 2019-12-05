#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include "Lista.c"

char * getNome(){
	char *var;
	var = (char*)calloc(100,sizeof(char));
	char c;
	int i = 0;
	while((c = getchar()) != '\n'){
		var[i++] = c;
	}
	var[i] = '\0';
	return var;
}

char * atribui_string(char * str1){
	char * str2;
	str2 = (char*)calloc(100,sizeof(char));
	int g = 0;
	while(str1[g] != '\0'){
		str2[g] = str1[g];
		g++;
	}
	str2[g] = '\0';
	return str2;
}

int tamanho_string(char * str){
	int n = 0;
	while(str[n] != '\0'){
	//	printf("%c",str[n]);
		n++;
	}
	//printf("%i\n\n", n);
	return n;
}

int compara_string(char * str1, char * str2){
	int i, n1, n2;
	i = 0; n1 = 0; n2 = 0;
	n1 = tamanho_string(str1);
	n2 = tamanho_string(str2);
	if(str1[i] < str2[i]){
		//printf("aqui1\n");
		return 1;
	}
	if(str2[i] > str1[i]){
		//printf("aqui2\n");
		return -1;
	}
	while(str1[i] == str2[i] && (str1[i] != '\0' && str2[i] != '\0')){
			if(i > n1 && i < n2){
				//printf("Aqui3 n1: %d n2: %d\n", n1, n2);
				//printf("Aqui3 n1: %s n2: %s\n", str1[i], str2[i]);
				return -1;
			}
			if(i > n2 && i < n1){
			//	printf("Aqui4\n");
				return 1;
			}
		//	printf("%i  ",i);
			i++;
	}
	if(str1[i] > str2[i]){
		//printf("aqui5\n");
		return -1;
	}
	else if(str1[i] < str2[i]){
		//printf("aqui4\n");
		return 1; 
	}
	else{
		//printf("aqui5\n");
		return 0;
	}
		

}



//--------------------- Funções Lista Encadeada ------------------------------------//


void constroi(Lista **l){
	(*l)->inicio = NULL;
	(*l)->tamanho = 0;
}

void insere_inicio(Lista **l, No *novo_no){
	novo_no->prox = (*l)->inicio;
	(*l)->inicio = novo_no;
}

void insere(Lista **l, int chave, char *nome){
	No *novo_no;
	novo_no=(No*)malloc(sizeof(No));
	novo_no->chave = chave;
	novo_no->nome = nome;
}

void insere_auxiliar(No **aux, struct No *novo )
{
	if((*aux))
	{
		if(compara_string(novo->nome, (*aux)->nome) ==1)
		{
			novo->prox=(*aux);
			(*aux)=novo;
			//(*aux)->prox=NULL;
		}
		else
		{
			insere_auxiliar(&((*aux)->prox),novo);
		}
	}
	else
	{
		novo->prox=(*aux);
		(*aux)=novo;
	//	(*aux)->prox=NULL;
	}
}

void insere_ordenada(Lista **l, int c, char * elem, char * senha)
{
	No *novo,*aux;
	novo=(No*)malloc(sizeof(No));
	novo->chave=c;
	novo->nome=atribui_string(elem);
	novo->senha=atribui_string(senha);
	(*l)->tamanho++;
	
	if ((*l)->inicio==NULL)
	{
		insere_inicio(l,novo);
	}
	else
	{
		if(compara_string(novo->nome, (*l)->inicio->nome) == 1)
		{
			insere_inicio(l,novo);
		}
		else
		{	
			insere_auxiliar(&((*l)->inicio->prox),novo);
		}
	}

}


void enumera(Lista **l)
{
	No *aux;
	aux=(*l)->inicio;
	while(aux!=NULL)
	{
		printf("Chave: %d",aux->chave);printf("  Nome: %s   Senha:  %s\n",aux->nome,aux->senha);
		aux=aux->prox;
	}
	
}


int busca(Lista **l, char * elem)
{
	No* aux;
	aux=(*l)->inicio;
	

	
	while(aux)
	{
		if(compara_string(aux->nome,elem) == 0){
			return 1;
		}
		else
		aux=aux->prox;
	}

	return 0;
}


int buscaKey(Lista **l, int elem)
{
	No* aux;
	aux=(*l)->inicio;
	

	
	while(aux)
	{
		if(aux->chave == elem){
			return 1;
		}
		else{
			aux=aux->prox;
		}
	}

	return 0;
}

No* remove_elem(Lista **l, char * elem)
{
	No *aux1,*aux2;
	aux1=(*l)->inicio;
	
	if(compara_string(aux1->nome,elem) == 0){
		(*l)->inicio=(*l)->inicio->prox;
		aux1->prox=NULL;
		(*l)->tamanho--; 
		//printf("%s\n", aux1->nome);
		return aux1;
	}
	
	while(compara_string(aux1->nome,elem) != 0 && aux1->prox != NULL)
	{
		//printf("%s\n", aux1->nome);
		aux2=aux1;
		aux1=aux1->prox; 
		
	}

	if (compara_string(aux1->nome,elem) == 0)
	{
		
		aux2->prox=aux1->prox;
		aux1->prox=NULL;
		(*l)->tamanho--;
		//printf("%s\n", aux1->nome);
		return aux1;
	}
	else
		return NULL;
	
}

No* remove_elemKey(Lista **l, int elem)
{
	No *aux1,*aux2;
	aux1=(*l)->inicio;
	
	if(aux1->chave == elem){
		(*l)->inicio=(*l)->inicio->prox;
		aux1->prox=NULL;
		(*l)->tamanho--; 
		//printf("%s\n", aux1->nome);
		return aux1;
	}
	
	while(aux1->chave != elem && aux1->prox != NULL)
	{
		//printf("%s\n", aux1->nome);
		aux2=aux1;
		aux1=aux1->prox; 
		
	}

	if (aux1->chave == elem)
	{
		
		aux2->prox=aux1->prox;
		aux1->prox=NULL;
		(*l)->tamanho--;
		//printf("%s\n", aux1->nome);
		return aux1;
	}
	else
		return NULL;
	
}






void destroi(Lista **l){
	No * aux;
	while((*l)->inicio){
		aux=(*l)->inicio;
		(*l)->inicio=(*l)->inicio->prox;
		aux->prox=NULL;
		free(aux);
	}
	(*l)->inicio=NULL;
	free((*l));
	l=NULL;
}

//--------------------------------------------------------------------------------------------------------//

void grava_nomes(Lista **l, FILE *file)
{
	fseek(file, 0, SEEK_SET);
	No *aux;
	aux=(*l)->inicio;
	while(aux!=NULL)
	{
		//fprintf(file,"Chave: %d",aux->chave);
		fprintf(file,"%s;%s\r\n",aux->nome,aux->senha);
		aux=aux->prox;
	}
	
}

void grava_senha(Lista **l, FILE *file)
{
	//fseek(file, 0, SEEK_SET);
	No *aux;
	aux=(*l)->inicio;
	while(aux!=NULL)
	{
		//fprintf(file,"Chave: %d",aux->chave);
		fprintf(file,"%s;\n",aux->senha);
		aux=aux->prox;
	}
	
}


int carregar_arquivo(Lista **l, FILE *file){
	fseek(file, 0, SEEK_SET);
	char c; 
	char str1[100];char str2[100];
	int i = 0; int n = 1, j = 0;
	int controle = 0;
	while((c = fgetc(file)) != EOF){
		if(c!= '\r' && c!= '\n' && controle == 0){
			if(c == ';'){
				controle = 1;
				str1[i] = '\0';
				i =0;
			//	printf("%s --------", str1);
			}
			else{
				str1[i] = c;
				i++;
			}
			//printf("%s",str[i]);
			
		}
		if(c!= ';' && controle == 1){
			if(c == '\r' || c == '\n'){
				controle = 0;
				str2[j] = '\0';
				j= 0;
				//printf(" %s\n", str2);
				insere_ordenada(l, n++,str1, str2);
				
			}
			else{
				str2[j] = c;
				j++;
			}
			
		}
		//printf("\n\n%i\n\n",i);
		
		
	}
		
	return n;
}


void escreve_arquivo(char * nom, char * senha){
	setlocale(LC_ALL, "Portuguese_Brasil");
	int opcao;
	FILE * nomes;
	nomes = fopen("nomes.txt","r");
	char *nome;
	char nomeImpresso[100];
	Lista *l;
	l=(Lista*)malloc(sizeof(Lista));
	constroi(&l); int i;
	i = carregar_arquivo(&l,nomes);
	fclose(nomes);
	int escolha; int chave; char * del;
	//printf("[1] - Inserir usuario\n[2] - Listar Usuarios\n[3] - Deletar Usuario\n[4] - Sair\n\nOpcao: "); scanf("%i",&opcao); getchar();
	
	opcao = 1;
	while(opcao != 4){
	
		switch(opcao){
			case 1:
				//enumera(&l);
			//	printf("\nDigite um nome: "); 
			//nome = atribui_string(nom);
				if(busca(&l, nom) == 1) { ; } else{ insere_ordenada(&l, i++,nom, senha); /*system("cls");*/}
				//enumera(&l);
				nomes = fopen("nomes.txt","w");
				grava_nomes(&l,nomes);
				//grava_senha(&l,nomes);
				fclose(nomes);
				
				opcao = 4;
			break;
	
			case 2:
				system("cls");
				printf("\nNomes cadastrados:\n");
				
				enumera(&l); printf("\n");
				//printf("\n");
			break;
			
			case 3:
				
				printf("[1] --> Apagar pela chave\n[2] --> Apagar pelo nome\nDigite a opcao: "); scanf("%d", &escolha); getchar();
				switch (escolha){
					case 1:
						printf("Digite a chave para exclusao: ");scanf("%d", &chave); getchar(); printf("\n");
						if(buscaKey(&l, chave)){							
							del = atribui_string(remove_elemKey(&l, chave)->nome);
							nomes = fopen("nomes.txt","w");
							grava_nomes(&l,nomes);
							fclose(nomes); 
						}
						else{
							del = NULL;
						}						
						del != NULL ? printf("Nome: '%s' deletado!\n\n", del) : printf("Elemento nao encontrado na lista\n");
											
					break;
					
					case 2:
						printf("Digite o nome a ser apagado: ");nome = getNome(); printf("\n");
						if(busca(&l,nome)){
							del = atribui_string(remove_elem(&l, nome)->nome);
							nomes = fopen("nomes.txt","w");
							grava_nomes(&l,nomes);
							fclose(nomes);
						}
						else{
							del = NULL;
						}		
						
						del != NULL ? printf("Nome: '%s' deletado!\n\n", del) : printf("Elemento nao encontrado na lista\n");
					break;
				}
			break;
	
			default:
				printf("Opcao invalida\n\n");
			break;
		}
		//printf("[1] - Inserir usuario\n[2] - Listar Usuarios\n[3] - Deletar Usuario\n[4] - Sair\n\nOpcao: "); scanf("%i",&opcao); getchar();
	}
	destroi(&l);
}


