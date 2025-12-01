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
 void buscarItens (Item mochila [], int total);

 // --- Função auxiliar 

 int buscarPosicao (Item mochila[], int total, char ome []);

 //-----------------------------------------------------------

int main() { 
    Item mochila [MAX_ITENS];
    int total = 0;
    int opcao;
    ]
    do {
        printf ("\n===== SITEMA DE INVENTÁRIO - MOCHILA INICIAL =====\n");
        printf ("1 - Cadastrar item\n");
        printf ("2 - Remover item \n");
        printf ("3 - Listar item\n");
        printf ("4 - Buscar item\n");
        printf ("0 - Sair\n");
        printf (" Escolha uma opcao:  ");
        printf ("%d", &opcao);

        getchar(); //limpar buffer 

        


    }

    return 0;
}

