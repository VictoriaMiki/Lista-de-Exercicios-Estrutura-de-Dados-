#include<stdio.h>

#define CIDADE 7
#define MES 6

float mediaCidade(int i, float matriz[][MES]);
float mediaMesRegiao(int j, float matriz[][MES]);

main() {
	float matriz[CIDADE][MES];
	
	for (int i = 0; i < CIDADE; i++) {
		printf("< Indice pluviometrico  da cidade %d >\n", i+1);
		for (int j = 0; j < MES; j++) {
			printf("Mes %d: ", j+1);
			scanf("%f", &matriz[i][j]);
		}
		printf("\n");
	}
	
	for (int i = 0; i < CIDADE; i++) {
		printf("O indice de pluviosidade medio mensal da cidade %d: %.2f\n", i+1, mediaCidade(i, matriz));
	}
	
	for (int j = 0; j < MES; j++) {
		printf("O indice de pluviosidade media na regiao no mes %d: %.2f\n", j+1, mediaMesRegiao(j, matriz));
	}
}

float mediaCidade(int i, float matriz[][MES]) {
	float soma = 0.0;
	float media;
	
	for (int j = 0; j < MES; j++) {
		soma += matriz[i][j];
	}	
	
	media = soma / MES;

	return media;
}

float mediaMesRegiao(int j, float matriz[][MES]) {
	float soma = 0.0;
	float media;
	
	for (int i = 0; i < MES; i++) {
		soma += matriz[i][j];
	}	
	
	media = soma / MES;

	return media;
}
