#include<stdio.h>

int verificar(char jogo[][3]);

main() {
	char jogo[3][3];
	int linha, coluna;
	int p1 = 1;
	
	printf(" [0 0] | [0 1] | [0 2] \n");
	printf(" [1 0] | [1 1] | [1 2] \n");
	printf(" [2 0] | [2 1] | [2 2] \n");	
	
	for (int i=0; i<3; i++)  for (int j=0; j<3; j++)  {     
		jogo[i][j] = ' ';
	}
		
	do {
		printf("Insira a coordenada: ");
		scanf("%d %d", &linha, &coluna);
		if (p1 == 1) {
			jogo[linha][coluna] = 'X';
			p1 = 0;
		} else {
			jogo[linha][coluna] = 'O';
			p1 = 1;
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c ", jogo[i][j]);
			}
			printf("\n");
		}	
	} while (verificar(jogo) == 0);
	
	if (verificar(jogo) == 1) {
		printf("Jogador X ganhou!");
	}
	if (verificar(jogo) == 2) {
		printf("Jogador O ganhou!");
	}
}

int verificar(char jogo[][3]) {
	int x = 0, o = 0;
	int retorno = 0;
	
	// verifica linha
	for (int i = 0; i < 3; i++) {
		x = 0;
		o = 0;
		for (int j = 0; j < 3; j++) {
			if (jogo[i][j] == 'X') x++;
			if (jogo[i][j] == 'O') o++;
		}
		if (x == 3) {
			retorno = 1;
			break;
		}
		if (o == 3) {
			retorno = 2;
			break;
		}
	}
	
	// verifica coluna
	for (int i = 0; i < 3; i++) {
		x = 0;
		o = 0;
		for (int j = 0; j < 3; j++) {
			if (jogo[j][i] == 'X') x++;
			if (jogo[j][i] == 'O') o++;
		}
		if (x == 3) {
			retorno = 1;
			break;
		}
		if (o == 3) {
			retorno = 2;
			break;
		}
	}
	
	// verifica diagonal 1
	x = 0;
	o = 0;
	for (int i = 0; i < 3; i++) {
		if (jogo[i][i] == 'X') x++;
		if (jogo[i][i] == 'O') o++;
	}
	if (x == 3) {
		retorno = 1;
	}
	if (o == 3) {
		retorno = 2;
	}
	
	// verifica diagonal 2
	x = 0;
	o = 0;
	if (jogo[0][2] == 'X') x++;
	if (jogo[0][2] == 'O') o++;
	if (jogo[1][1] == 'X') x++;
	if (jogo[1][1] == 'O') o++;
	if (jogo[2][0] == 'X') x++;
	if (jogo[2][0] == 'O') o++;
	if (x == 3) {
		retorno = 1;
	}
	if (o == 3) {
		retorno = 2;
	}
	
	return retorno;
}
