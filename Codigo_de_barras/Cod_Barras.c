#include<stdio.h>
#include<stdlib.h>

int main(void){
	char c; char d[1000];
	int i; i =0;
	while((c = getchar()) != '\n'){
		if(c != ' ' && c != '-'){
			d[i] = c;
			i++;
		}		
	}
	d[i] = '\0';
	
	printf("%s\n", d);
	system("pause");
	return 0;
}
