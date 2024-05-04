#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void banner();
void game_menu();
void placar_de_jogadores();

// Estrutura de dados
typedef struct Pais {
    int id; // 0 até 194
    char iso;
    char nome;
    int continente; // 1: America, 2: Africa, 3: Asia, 4: Europa, 5: Oceania
    struct Pais *prox;
} Pais;

void adicionar_pais(Pais **head, int id, char iso, char nome, int continente);
void remover_pais(Pais **head, int id);
void imprimir_bandeira(Pais *head, int id);
void carregar_paises(Pais **head, int continente);
void randomizar_ordem_bandeiras();
void randomizar_respostas();
void placar_jogadores();

int main()
{
    menu();
    return 0;
}

void carregar_paises(Pais **head, int continente) 
{
    
}

void adicionar_pais(Pais **head, int id, char iso, char nome, int continente){
    
}

void banner()
{
    printf("\n");
    printf(" ██████╗ ██████╗ ██╗   ██╗███╗   ██╗████████╗██████╗ ██╗   ██╗    ███████╗██╗      █████╗  ██████╗      ██████╗  █████╗ ███╗   ███╗███████╗\n");
    printf("██╔════╝██╔═══██╗██║   ██║████╗  ██║╚══██╔══╝██╔══██╗╚██╗ ██╔╝    ██╔════╝██║     ██╔══██╗██╔════╝     ██╔════╝ ██╔══██╗████╗ ████║██╔════╝\n");
    printf("██║     ██║   ██║██║   ██║██╔██╗ ██║   ██║   ██████╔╝ ╚████╔╝     █████╗  ██║     ███████║██║  ███╗    ██║  ███╗███████║██╔████╔██║█████╗  \n");
    printf("██║     ██║   ██║██║   ██║██║╚██╗██║   ██║   ██╔══██╗  ╚██╔╝      ██╔══╝  ██║     ██╔══██║██║   ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  \n");
    printf("╚██████╗╚██████╔╝╚██████╔╝██║ ╚████║   ██║   ██║  ██║   ██║       ██║     ███████╗██║  ██║╚██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗\n");
    printf(" ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝       ╚═╝     ╚══════╝╚═╝  ╚═╝ ╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n");
    printf("\n");
}

void menu()
{
    while (1)
    {
        int opcao;

        banner();
        printf("\n");
        printf("[1] Jogar\n");
        printf("[2] Placar de jogadores\n");
        printf("[3] Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);


        if (opcao == 1)
        {
            game_menu();
        }
        else if (opcao == 2)
        {
            placar_de_jogadores();
        }
        else if (opcao == 3)
        {
            return;
        }
        else {
            printf("Opção Inválida!\n");
            menu();
        }

        return;
    }
}

void game_menu()
{
    int modo_de_jogo;
    printf("Escolha o modo de jogo:\n");
    printf("[1] Voltar para o menu principal\n");
    printf("[2] Todos os países\n");
    printf("[3] Países da América\n");
    printf("[4] Países da África\n");
    printf("[5] Países da Ásia\n");
    printf("[6] Países da Europa\n");
    printf("[7] Países da Oceania\n");
    printf("Escolha: ");
    scanf("%d", &modo_de_jogo);

    if (modo_de_jogo == 1)
    {
        menu();
    }
    else if (modo_de_jogo == 2)
    {
    }
    else if (modo_de_jogo == 3)
    {
    }
    else if (modo_de_jogo == 4)
    {
    }
    else if (modo_de_jogo == 5)
    {
    }
    else if (modo_de_jogo == 6)
    {
    }
    else if (modo_de_jogo == 7) 
    {
        
    }
    else
    {
        printf("Opção Inválida!\n");
        game_menu();
    }
}

void placar_jogadores()
{
}
