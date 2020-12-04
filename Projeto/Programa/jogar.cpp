#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "modo.cpp"

void jogar(){
	setlocale(LC_ALL, "Portuguese");
	int selecionar;
	
	//Menu para escolher o modo
	system("cls");
	printf("Selecione uma das opcoes abaixo:\n\n");
	printf("1 - Um jogador\n");
	printf("2 - Dois jogadores\n\n");
	printf("=> Escolha: ");
	scanf("%d", &selecionar);
	printf("\n");
	
	if(selecionar == 1){
		um_jogador();
	}
	else if(selecionar == 2){
		dois_jogadores();
	}
	else{
		printf("Comando incorreto!");
	}
}

