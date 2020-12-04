#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Variaveis globais
char nome[3];
int pontos;

//Chamando a funcao ranking
void ranking();

//Imagem do tabuleiro
void tabuleiro(char modelo[3][3]){
	system("cls");
	printf("\t   1   2   3\n");
	printf("\t 1 %c | %c | %c \n", modelo[0][0], modelo[0][1], modelo[0][2]);
	printf("\t  -----------\n");
	printf("\t 2 %c | %c | %c \n", modelo[1][0], modelo[1][1], modelo[1][2]);
	printf("\t  -----------\n");
	printf("\t 3 %c | %c | %c \n", modelo[2][0], modelo[2][1], modelo[2][2]);
}
//Modo singleplayer
void um_jogador(){
	setlocale(LC_ALL, "Portuguese");
	char casas[3][3];
	int cond;
	
	tabuleiro(casas);
	
	char resposta;
	int i,j;
	int cont_jogadas;
	int l,c;
	int vez = 0;
	
	do{
		cont_jogadas = 1;
		for(i=0;i<=2;i++){
			for(j=0;j<=2;j++){
				casas[i][j] = ' ';
			}
		}
		
		do{
			tabuleiro(casas);
			//O jogador "usuario"
			if(vez%2 == 0){
				printf("\nJogador X\n");
				printf("Digite a linha: ");
				scanf("%d", &l);
				printf("Digite a coluna: ");
				scanf("%d", &c);
			}
			//O pc ira procurar um espaço vazio e preencher com o 'O'
			else if((cond == 0) && (casas[l][c] == ' ')){
				casas[l][c] = 'O';
				cond = 0;
				vez++;
				
			}
			//Caso o numero seja menor que 1 e maior 3 a jogada sera considerada invalida
			if(l < 1 || c < 1 || l > 3 || c > 3){
				l = 0;
				c = 0;
			}
			//Verifica se a posição esta ocupada caso esteja a jogada sera considerada invalida
			else if(casas[l-1][c-1] != ' '){
				l = 0;
				c = 0;
			}
			else{
				//Jogador X
				if(vez%2 == 0){
					casas[l-1][c-1] = 'X';
				}
				//Jogador O
				else{
					casas[l-1][c-1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			//Condições de vitoria
			if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){cont_jogadas = 11;}
			if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){cont_jogadas = 11;}
			if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			
			if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){cont_jogadas = 12;}
			if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){cont_jogadas = 12;}
			if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}

		}while(cont_jogadas <= 9);
			tabuleiro(casas);
			if(cont_jogadas == 10){
				printf("\nA disputa acabou em empate!\n");
			}
			if(cont_jogadas == 11){
				printf("\nO vencedor foi o X\n");
			}
			if(cont_jogadas == 12){
				printf("\nO vencedor foi o O\n");
			}
			printf("\nObrigado por jogar!\n");
			break;
			printf("Deseja jogar novamente? [S-N]\n");
			scanf("%s", &resposta);
	}while(resposta == 'S');
}

//Modo multiplayer
void dois_jogadores(){
	setlocale(LC_ALL, "Portuguese");
	char casas[3][3];
	
	tabuleiro(casas);
	
	char resposta;
	int i,j;
	int cont_jogadas;
	int l,c;
	int vez = 0;
	
	do{
		cont_jogadas = 1;
		for(i=0;i<=2;i++){
			for(j=0;j<=2;j++){
				casas[i][j] = ' ';
			}
		}
		
		do{
			tabuleiro(casas);
			
			if(vez%2 == 0){
				printf("\nJogador X\n");
			}
			else{
				printf("\nJogador O\n");
			}
			printf("Digite a linha: ");
			scanf("%d", &l);
			printf("Digite a coluna: ");
			scanf("%d", &c);
			
			if(l < 1 || c < 1 || l > 3 || c > 3){
				l = 0;
				c = 0;
			}
			else if(casas[l-1][c-1] != ' '){
				l = 0;
				c = 0;
			}
			else{
				if(vez%2 == 0){
					casas[l-1][c-1] = 'X';
				}
				else{
					casas[l-1][c-1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){cont_jogadas = 11;}
			if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){cont_jogadas = 11;}
			if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			
			if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){cont_jogadas = 12;}
			if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){cont_jogadas = 12;}
			if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			
		}while(cont_jogadas <= 9);
			tabuleiro(casas);
			if(cont_jogadas == 10){
				printf("\nA disputa acabou em empate!\n");
			}
			if(cont_jogadas == 11){
				printf("\nO vencedor foi o X\n");
				printf("\nDigite o seu nome: [Maximo de 3 caracteres]: ");
				scanf("%s", nome);
				pontos += 10;
				ranking();
			}
			if(cont_jogadas == 12){
				printf("\nO vencedor foi o O\n");
				printf("\nDigite o seu nome [Maximo de 3 caracteres]: ");
				scanf("%s", nome);
				pontos += 10;
				ranking();
			}
			printf("\nDeseja jogar novamente? [S-N]\n");
			scanf("%s", &resposta);
			if(resposta == 'N'){
				break;
			}
			
	}while(resposta == 'S');
}
	//Função ranking
	void ranking(){
		system("cls");
		
		FILE *pont_arq;
		pont_arq = fopen("ranking.txt", "a");
		
		if(pont_arq == NULL){
			printf("Erro na abertura do arquivo!");
		} 
			fprintf(pont_arq, "Nome: %s Pontos: %d\n", nome, pontos);
			fclose(pont_arq);
			printf("Dados gravados com sucesso!");
		
	}
	//Função creditos
	void creditos(){
		system("cls");
		printf("Criado por:\n\n");
		printf("Arthur Henrique de Lucena Paiva\n");
		printf("RGM: 24690333\n\n");
		printf("Valquiria do Nascimento Pereira Gomes\n");
		printf("RGM: 24717339\n\n");
	}

