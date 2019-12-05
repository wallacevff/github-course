typedef struct No{
	int chave;
	char *nome;
	struct No *prox;
	//struct No *ant;
}No;


typedef struct Lista{
	No *inicio;
	int tamanho;
}Lista;

/*
int main(){
	char * atribui_string(char * str1);
	char *nome; char c; 
	char *nome2; int i = 0; int n = 0; int g;
	Lista *l;
	l=(Lista*)malloc(sizeof(Lista));
	constroi(&l);
	//int i = 0; 
	//nome = (char*)calloc(100,sizeof(char));
	//while((c = getchar()) != '\n'){
//		nome[i++] = c;
	//}
	
	
	//nome[i] = '\0';
	
	printf("Defina o número de nomes que deseja cadastrar: "); scanf("%d", &g); getchar(); printf("\n\n");
	for(i=0;i<g;i++)
	{
		printf("Nome: ");nome = getNome();
		insere_ordenada(&l,n++,nome);
	}
	enumera(&l);
	printf("Nome a ser Procurado: "); nome = getNome(); busca(&l, nome) == 1? printf("Nome pertence a lista\n") : printf("Nome não pertence a lista\n");
	
	printf("Nome a ser removido: "); nome = getNome(); printf("\n\n");
	remove_elem(&l,nome);
	enumera(&l);
	destroi(&l);
	
	//system("pause"); 
	//printf("%d\n",compara_string("and12", "and1"));
	return 0;
}
*/
