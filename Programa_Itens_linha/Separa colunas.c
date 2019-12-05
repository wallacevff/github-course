#include<stdio.h>


int main(){
	FILE * file;
	file = fopen("texto_ajustado.txt","w");
	char c;
	char str[300];
	int n = 0, i = 0, primeira_linha = 1;
	while((c = getchar())!= '\n'){
		str[i++] = c;
		if(c == ';'){
			if(primeira_linha == 1){ printf("\n\n\n-----------------------------------------------------------------------------\n");
				fprintf(file,"-----------------------------------------------------------------------------\n");
			 	primeira_linha = 0;
			 }
			str[i] = '\0';
			n ++; i = 0;		
			printf("%s", str);
			fprintf(file,"%s",str);
			if(n >= 9){
				n = 0;
				printf("\n");
				fprintf(file,"\n");
			}			
		}
				
	}
	if(n<9){ printf("\n"); }
	fprintf(file,"-----------------------------------//----------------------------------------");
	fclose(file);
	printf("-----------------------------------//----------------------------------------\n\n");	
	system("pause");
	return 0;
}
