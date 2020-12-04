#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "jogar.cpp"
#include "ranking.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	int selecionar;
	
	//Menu inicial
	while(1){
		printf("\n\nJogo da Velha 3x3\n\n");
		printf("Selecione uma das opcoes abaixo:\n\n");
		printf("1 - Jogar\n");
		printf("2 - Ranking\n");
		printf("3 - Creditos\n");
		printf("4 - Sair\n\n");
		printf("=> Escolha: ");
		scanf("%d", &selecionar);
		printf("\n");

		if(selecionar == 1){
			jogar();
		}
		else if(selecionar == 2){
			ver_ranking();
		}
		else if(selecionar == 3){
			creditos();
		}
		else if(selecionar == 4){
			printf("\n\nObrigado por jogar, volte sempre!\n\n");
			break;
		}
		else{
			printf("Comando incorreto!");
		}
	}
	return 0;
}
