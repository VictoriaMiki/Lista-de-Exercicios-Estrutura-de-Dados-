#include<stdio.h>

#define ALUNOS 5
#define PROVAS 4

float mediaAluno(int i, float matriz[][PROVAS]);

main() {
	float matriz[ALUNOS][PROVAS];
	float somaTurma, mediaTurma;
	
	for (int i = 0; i < ALUNOS; i++) {
		printf("< Notas do aluno %d >\n", i+1);
		for (int j = 0; j < PROVAS; j++) {
			printf("Prova %d: ", j+1);
			scanf("%f", &matriz[i][j]);
		}
		printf("\n");
	}
	
	for (int i = 0; i < ALUNOS; i++) {
		printf("Media do aluno %d: %.2f\n", i+1, mediaAluno(i, matriz));
		somaTurma += mediaAluno(i, matriz);
	}
	mediaTurma = somaTurma / ALUNOS;
	printf("\nMedia da turma: %.2f", mediaTurma);
}

float mediaAluno(int i, float matriz[][PROVAS]) {
	float soma = 0.0;
	float media;
	
	for (int j = 0; j < PROVAS; j++) {
		soma += matriz[i][j];
	}	
	
	media = soma / PROVAS;

	return media;
}
