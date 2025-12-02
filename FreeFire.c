#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void removerItem (Item mochila[], int *total){
        char nomeBusca[30];

        if (*total == 0){
            printf ("\nA mochila está vazia!\n");
            return;
        
        }
        
        printf ("\nDigite o nome item que deseja remover: ");
        fgets(nomeBusca, 30, stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\n';

        int pos = buscarPosicao(mochila, *total, nomeBusca);

        if (pos == -1){
            printf ("\bItem não encontrado.\n");
            return;
        }

        //Deslocar itens á esquerda
        for (int i = pos; i < (*total)- 1; i++){
            mochila[i] = mochila [i + 1];
        }

        (*total)--;

        printf ("\n Item removido com sucesso!\n");
        
        listarItens(mochila, *total);
        
    }
//---  LISTA TODOS OS ITENS DA MOCHILA
void listarItens (Item mochila[], int total){
    printf("\n===== ITENS NA MOCHILA =====\n");

    if (total== 0){
        printf ("Mochila vazia.\n");
        return;
    }
    for(int i=0; i< total; i++){
        printf ("%d) Nome: %s | Tipo: %s | Quantidade: %s\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}
//--- BUSCA SEQUENCIAL POR NOME

