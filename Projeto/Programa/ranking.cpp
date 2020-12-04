#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função ver o ranking (Exibir na tela os usuarios e a pontuação)
void ver_ranking(){
	char linhas[100];
	char voltar;
	system("cls");
	printf("\n ######- Ranking de Jogadores -######\n");
    printf("  \n");
    printf(" NOME - PONTOS\n\n");

	FILE *pont_arq;
	pont_arq = fopen("ranking.txt", "r");
		
	if(pont_arq == NULL){
		printf("\n\nErro na abertura do arquivo!\nVoce precisa jogar o modo 'Dois jogadores' pelo menos uma vez!\n\n");
	} 
	while(fgets(linhas, 100, pont_arq) != NULL){
		printf("%s",linhas);
	}
	fclose(pont_arq);
	}
