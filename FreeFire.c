#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// --- STRUCT ITEM : representa objetos da mochila do jogador 
 typedef  struct {  
    char nome[30];
    char tipo [20];
    int quantidade;
 } Item;

 // ---  Funções obrigatórias 
 void inserirItem (Item mochila[], int *total);
 void removerItem (Item mochila [], int *total);
 void listarItens (Item mochila[], int total);
 void buscarItem (Item mochila [], int total);

 // --- Função auxiliar 

 int buscarPosicao (Item mochila[], int total, char ome []);

 //-----------------------------------------------------------

int main() { 
    Item mochila [MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf ("\n===== SITEMA DE INVENTÁRIO - MOCHILA INICIAL =====\n");
        printf ("1 - Cadastrar item\n");
        printf ("2 - Remover item \n");
        printf ("3 - Listar itens\n");
        printf ("4 - Buscar item\n");
        printf ("0 - Sair\n");
        printf (" Escolha uma opcao:  ");
        printf ("%d", &opcao);

        getchar(); //limpar buffer 

        switch (opcao){
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2: 
                removerItem(mochila, &total);
                break;
            case 3: 
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 0:
                printf ("\nEcerrando sistem...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
// ISERE UM NOVO ITEM NA MOCHILA

void inserirItem(Item mochila[], int *total){
    if (*total >= MAX_ITENS){
        printf("\n A mochila está cheia! Não é possível adicionar mais itens.\n ");
        return;
    }

    Item novo;

    printf ("\n Digite o nome do item: ");
    fgets(novo.nome, 30 , stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';
    
    printf ("Digite o tipo do item (arma, municao, cura...): ");
    fgets(novo.tipo, 20, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf ("Digite a quantidade: ");
    scanf ("%d", &novo.quantidade);
    getchar();

    mochila[*total] = novo;
    (*total)++;

    printf ("\n Item adicionado com sucesso! \n" );

    listarItens (mochila, *total);
}

// -- REMOVE UM ITEM PELO NOME

