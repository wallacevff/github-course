#include<stdio.h>
#include<stdlib.h>

int main(void){
	char c; char d[1000];
	int i; i =0;
	FILE *file;
	file = fopen("codbar.txt","w");
	while((c = getchar()) != '\n'){
		if(c != ' ' && c != '-' && c != '.' && c != '\t'){
			d[i] = c;
			i++;
		}		
	}
	d[i] = '\0';
	
	printf("%s\n", d);
	fprintf(file,"%s",d);
	fclose(file);
	system("pause");
	return 0;
	
}
