//nivel novato//
#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_STR 30

typedef struct {
    char nome[MAX_STR];
    char tipo[MAX_STR];
    int quantidade;
} Item;

void adicionarItem(Item mochila[], int *total) {
    if (*total >= MAX) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("Nome do item: ");
    scanf("%s", mochila[*total].nome);

    printf("Tipo do item: ");
    scanf("%s", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;
    printf("Item adicionado com sucesso!\n");
}

void removerItem(Item mochila[], int *total) {
    char nome[MAX_STR];
    printf("Digite o nome do item a remover: ");
    scanf("%s", nome);

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            printf("Item removido!\n");
            return;
        }
    }

    printf("Item não encontrado!\n");
}

void listarItens(Item mochila[], int total) {
    printf("\n=== Itens na Mochila ===\n");
    if (total == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    printf("%-15s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");

    for (int i = 0; i < total; i++) {
        printf("%-15s %-15s %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}

int main() {
    Item mochila[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n=== MENU – Mochila do Sobrevivente ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarItem(mochila, &total); break;
            case 2: removerItem(mochila, &total); break;
            case 3: listarItens(mochila, total); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}


//nivel aventureiro//
#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_STR 30

typedef struct {
    char nome[MAX_STR];
    char tipo[MAX_STR];
    int quantidade;
} Item;

void adicionarItem(Item mochila[], int *total) {
    if (*total >= MAX) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", mochila[*total].nome);

    printf("Tipo: ");
    scanf("%s", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;
}

void listarItens(Item mochila[], int total) {
    printf("\n=== Mochila ===\n");
    if (total == 0) {
        printf("Vazia!\n");
        return;
    }

    printf("%-15s %-15s %-10s\n", "Nome", "Tipo", "Qtd");

    for (int i = 0; i < total; i++) {
        printf("%-15s %-15s %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}

void buscarItem(Item mochila[], int total) {
    char nome[MAX_STR];
    printf("Nome do item para buscar: ");
    scanf("%s", nome);

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("Item não encontrado.\n");
}

int main() {
    Item mochila[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n=== MENU AVENTUREIRO ===\n");
        printf("1 - Adicionar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar por nome\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarItem(mochila, &total); break;
            case 2: listarItens(mochila, total); break;
            case 3: buscarItem(mochila, total); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Inválido!\n");
        }
    } while (opcao != 0);

    return 0;
}
//nivel mestre//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define MAX_STR 30

typedef struct {
    char nome[MAX_STR];
    char tipo[MAX_STR];
    int quantidade;
    int prioridade;
} Item;

typedef enum {
    ORDENAR_NOME = 1,
    ORDENAR_TIPO,
    ORDENAR_PRIORIDADE
} Criterio;

// ---------- Função: adicionar ----------
void adicionarItem(Item mochila[], int *total) {
    if (*total >= MAX) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", mochila[*total].nome);

    printf("Tipo: ");
    scanf("%s", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    printf("Prioridade (1 a 5): ");
    scanf("%d", &mochila[*total].prioridade);

    (*total)++;
}

// ---------- Listagem ----------
void listarItens(Item mochila[], int total) {
    printf("\n%-15s %-15s %-10s %-10s\n",
           "Nome", "Tipo", "Qtd", "Prioridade");

    for (int i = 0; i < total; i++) {
        printf("%-15s %-15s %-10d %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade,
               mochila[i].prioridade);
    }
}

// ---------- Ordenação (Insertion Sort) ----------
int ordenarMochila(Item mochila[], int total, Criterio c) {
    int comparacoes = 0;

    for (int i = 1; i < total; i++) {
        Item chave = mochila[i];
        int j = i - 1;

        while (j >= 0) {
            comparacoes++;

            bool cond = false;

            if (c == ORDENAR_NOME)
                cond = strcmp(mochila[j].nome, chave.nome) > 0;
            else if (c == ORDENAR_TIPO)
                cond = strcmp(mochila[j].tipo, chave.tipo) > 0;
            else
                cond = mochila[j].prioridade > chave.prioridade;

            if (!cond) break;

            mochila[j + 1] = mochila[j];
            j--;
        }

        mochila[j + 1] = chave;
    }

    return comparacoes;
}

// ---------- Busca Binária ----------
int buscaBinaria(Item mochila[], int total, char chave[]) {
    int ini = 0, fim = total - 1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int cmp = strcmp(chave, mochila[meio].nome);

        if (cmp == 0) return meio;
        else if (cmp < 0) fim = meio - 1;
        else ini = meio + 1;
    }
    return -1;
}

int main() {
    Item mochila[MAX];
    int total = 0;
    int opcao;

    bool ordenadoPorNome = false;

    do {
        printf("\n=== MENU MESTRE ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Listar\n");
        printf("3 - Ordenar\n");
        printf("4 - Busca binária por nome\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionarItem(mochila, &total);
            ordenadoPorNome = false;
        }

        else if (opcao == 2) {
            listarItens(mochila, total);
        }

        else if (opcao == 3) {
            int crit;
            printf("Ordenar por:\n1-Nome\n2-Tipo\n3-Prioridade\n");
            scanf("%d", &crit);

            int comp = ordenarMochila(mochila, total, crit);
            printf("Ordenado! Comparações: %d\n", comp);

            ordenadoPorNome = (crit == ORDENAR_NOME);
        }

        else if (opcao == 4) {
            if (!ordenadoPorNome) {
                printf("A lista precisa estar ordenada por NOME!\n");
                continue;
            }

            char nome[MAX_STR];
            printf("Nome para buscar: ");
            scanf("%s", nome);

            int pos = buscaBinaria(mochila, total, nome);

            if (pos >= 0) {
                printf("\nItem encontrado!\n");
                printf("Nome: %s\n", mochila[pos].nome);
                printf("Tipo: %s\n", mochila[pos].tipo);
                printf("Quantidade: %d\n", mochila[pos].quantidade);
                printf("Prioridade: %d\n", mochila[pos].prioridade);
            } else {
                printf("Item não encontrado.\n");
            }
        }

    } while (opcao != 0);

    return 0;
}
