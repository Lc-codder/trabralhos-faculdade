#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	
	setlocale(LC_ALL, "Portugese");
	
	int i ;
	int n1;
	int n2;
	int sub , som;
	int resultado;
	
	
	
	printf("digite um numero inteiro :\n");
	scanf("%d", &n1);
	
	printf("digite seu outro numero\n");
	scanf("%d", &n2);
	
	printf("digite 1 para subtrair, e 2 para somar: \n");
	
	som = n1 + n2;
	sub = n1 - n2;
	
	if(i == 1)
	printf("o resultado é %d", sub);
	if(i == 2)
	printf("o resultado é: %d ", som);
	
	system("pause");
	
}
