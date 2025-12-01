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
int main() {


    return 0;
}

