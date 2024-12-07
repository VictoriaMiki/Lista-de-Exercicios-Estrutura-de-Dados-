# Lista-de-Exercicios-Estrutura-de-Dados
07/12/2024: Lista de exercíos final da matéria de Estrutura de Dados

- As questões de 1 a 4, e 10 foram feitas separadamente em arquivos distintos;
- A questão 5 não exigia código, então sua resolução foi feita em um arquivo txt;
- As questões 6 a 9 foram feitas em um único código fonte e a parte respectiva a cada questão foi indicada por meio de comentários.

====================================================

Questões

1. Suponha uma matriz de 3 linhas por 3 colunas do tipo inteiro.
Leia os valores dessa matriz, depois informe qual é o maior e o menor elemento.

2. Faça um jogo da velha

3. Notas da turma - Fazer um programa para ler as notas de 4 provas para 5 alunos de uma turma e calcular a média do aluno e média da turma

4. Centro meterológico - Um centro meteorológico distribuiu dispositivos para registrar índices pluviométricos em um conjunto de 7 cidades de uma região (identificadas por códigos numéricos de 1 a 7) durante 6 meses(Jan a Jun), onde, para cada mês foi registrado um valor real que corresponde ao índice pluviométrico total do mês.

Escreva um programa que leia os 6 índices pluviométricos de cada uma das sete cidades e imprima:

a) O índice de pluviosidade médio mensal de cada cidade;

b) O índice de pluviosidade média de cada mês na região.


5. Quais serão os valores de x, y e p ao final do trecho de código abaixo?

int x, y, *p;y = 0;

p = &y;

x = *p;

x = 4;

(*p)++;

--x;

(*p) += x;

Justifique sua resposta:

6. Fazer um programa em Linguagem C que criem uma estrutura de dados voo(struct voo) para a empresa VOEBEM, que servirá para implementar funções para controle da lista
dos voos. A estrutura voo deve ser implementada de forma dinâmica e deve conter os seguintes dados:
- número do voo - inteiro;
- data do voo - inteiro: (1 - seg, 2 - ter, 3 - qua, 4- qui, 5 - sex, 6 - sab, 7 - dom, 8 - diario);
- horário do voo - hora inteiro, min inteiro;
- aeroporto de Saída - inteiro - id do aeroporto;
- aeroporto de Chegada - inteiro - id do aeroporto;
- rota - inteiro id;
- tempo estimado de voo - float;
- passageiros a bordo - inteiro;

 
7. Implementar a função cadastrarVoo() que deve permitir o cadastro de um novo voo;

8. Implementar a função consultaVoo() que deve permitir obter as informações do voo com base na digitação do número do voo;

9. Implementar a função removeVoo() que permita a exclusão de um determinado voo.

10. Faça uma rotina recursiva para calcular a somatória de todos os número de 1 a N (N será lido do teclado).
Observação: se N é igual a 5 por exemplo, A somatória dos números será igual a 15, ou seja, 1+2+3+4+5 = 15 
