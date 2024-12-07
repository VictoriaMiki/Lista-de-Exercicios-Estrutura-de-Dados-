#include <stdio.h>
#include <stdlib.h>

typedef struct voo {
    int numero;
    int data;               
    int hora;
    int min;
    int aeroporto_saida;
    int aeroporto_chegada;
    int rota;
    float tempo_estimado;
    int passageiros; 
    struct voo* prox;
} Voo;

// Questão 6
Voo* criarVoo(int numero, int data, int hora, int min, int aeroporto_saida, int aeroporto_chegada, int rota, float tempo_estimado, int passageiros) {
    Voo* novoVoo = (Voo*)malloc(sizeof(Voo));
    if (novoVoo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novoVoo->numero = numero;
    novoVoo->data = data;
    novoVoo->hora = hora;
    novoVoo->min = min;
    novoVoo->aeroporto_saida = aeroporto_saida;
    novoVoo->aeroporto_chegada = aeroporto_chegada;
    novoVoo->rota = rota;
    novoVoo->tempo_estimado = tempo_estimado;
    novoVoo->passageiros = passageiros;
    novoVoo->prox = NULL;
    return novoVoo;
}

// Questão 7
void cadastrarVoo(Voo** lista) {
    int numero, data, hora, min, aeroporto_saida, aeroporto_chegada, rota, passageiros;
    float tempo_estimado;

    printf("\nCadastrar novo voo:\n");
    printf("Numero do Voo: ");
    scanf("%d", &numero);
    printf("Data do Voo (1-seg, 2-ter, ..., 8-diario): ");
    scanf("%d", &data);
    printf("Horario do Voo (hora min): ");
    scanf("%d %d", &hora, &min);
    printf("Aeroporto de Saida (ID): ");
    scanf("%d", &aeroporto_saida);
    printf("Aeroporto de Chegada (ID): ");
    scanf("%d", &aeroporto_chegada);
    printf("Rota (ID): ");
    scanf("%d", &rota);
    printf("Tempo Estimado de Voo (horas): ");
    scanf("%f", &tempo_estimado);
    printf("Passageiros a Bordo: ");
    scanf("%d", &passageiros);

    Voo* novoVoo = criarVoo(numero, data, hora, min, aeroporto_saida, aeroporto_chegada, rota, tempo_estimado, passageiros);
    if (*lista == NULL) {
        *lista = novoVoo;
    } else {
        Voo* temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoVoo;
    }
    printf("Voo cadastrado com sucesso!\n");
}

// Questão 8
void consultaVoo(Voo* lista, int numero) {
    while (lista != NULL) {
        if (lista->numero == numero) {
            printf("\nInformacoes do Voo %d:\n", numero);
            printf("Data do Voo: %d\n", lista->data);
            printf("Horario do Voo: %02d:%02d\n", lista->hora, lista->min);
            printf("Aeroporto de Saida: %d\n", lista->aeroporto_saida);
            printf("Aeroporto de Chegada: %d\n", lista->aeroporto_chegada);
            printf("Rota: %d\n", lista->rota);
            printf("Tempo Estimado de Voo: %.2f horas\n", lista->tempo_estimado);
            printf("Passageiros a Bordo: %d\n", lista->passageiros);
            return;
        }
        lista = lista->prox;
    }
    printf("Voo com numero %d nao encontrado.\n", numero);
}

// Questão 9
void removeVoo(Voo** lista, int numero) {
    Voo* temp = *lista;
    Voo* anterior = NULL;

    while (temp != NULL && temp->numero != numero) {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) {
        printf("Voo com numero %d nao encontrado.\n", numero);
        return;
    }

    if (anterior == NULL) {
        *lista = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }

    free(temp);
    printf("Voo com numero %d removido com sucesso.\n", numero);
}


void exibirVoos(Voo* lista) {
    if (lista == NULL) {
        printf("Nenhum voo cadastrado.\n");
        return;
    }

    printf("\nLista de voos cadastrados:\n");
    while (lista != NULL) {
        printf("Numero do Voo: %d\n", lista->numero);
        printf("Data do Voo: %d\n", lista->data);
        printf("Horario do Voo: %02d:%02d\n", lista->hora, lista->min);
        printf("Aeroporto de Saída: %d\n", lista->aeroporto_saida);
        printf("Aeroporto de Chegada: %d\n", lista->aeroporto_chegada);
        printf("Rota: %d\n", lista->rota);
        printf("Tempo Estimado de Voo: %.2f horas\n", lista->tempo_estimado);
        printf("Passageiros a Bordo: %d\n", lista->passageiros);
        printf("-----------------------\n");
        lista = lista->prox;
    }
}


int main() {
    Voo* listaVoos = NULL;
    int opcao, numero;

    do {
        printf("\n=== MENU VOEBEM ===\n");
        printf("1. Cadastrar Voo\n");
        printf("2. Consultar Voo\n");
        printf("3. Remover Voo\n");
        printf("4. Exibir Voos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVoo(&listaVoos);
                break;
            case 2:
                printf("Digite o numero do voo para consulta: ");
                scanf("%d", &numero);
                consultaVoo(listaVoos, numero);
                break;
            case 3:
                printf("Digite o numero do voo para remocao: ");
                scanf("%d", &numero);
                removeVoo(&listaVoos, numero);
                break;
            case 4:
                exibirVoos(listaVoos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    while (listaVoos != NULL) {
        Voo* temp = listaVoos;
        listaVoos = listaVoos->prox;
        free(temp);
    }

    return 0;
}

