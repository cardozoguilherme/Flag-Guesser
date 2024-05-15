#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include <unistd.h>

#define MAX_LINE_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_NOME 100

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#ifdef _WIN32

#define HEART "<3 "

void banner()
{
    printf(MAG);
    printf(" ::::::::   ::::::::  :::    ::: ::::    ::: ::::::::::: :::::::::  :::   :::      :::::::::: :::            :::      ::::::::        ::::::::      :::     ::::    ::::  ::::::::::\n");
    printf(":+:    :+: :+:    :+: :+:    :+: :+:+:   :+:     :+:     :+:    :+: :+:   :+:      :+:        :+:          :+: :+:   :+:    :+:      :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:        \n");
    printf("+:+        +:+    +:+ +:+    +:+ :+:+:+  +:+     +:+     +:+    +:+  +:+ +:+       +:+        +:+         +:+   +:+  +:+             +:+         +:+   +:+  +:+ +:+:+ +:+ +:+        \n");
    printf("+#+        +#+    +:+ +#+    +:+ +#+ +:+ +#+     +#+     +#++:++#:    +#++:        :#::+::#   +#+        +#++:++#++: :#:             :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#   \n");
    printf("+#+        +#+    +#+ +#+    +#+ +#+  +#+#+#     +#+     +#+    +#+    +#+         +#+        +#+        +#+     +#+ +#+   +#+#      +#+   +#+# +#+     +#+ +#+       +#+ +#+        \n");
    printf("#+#    #+# #+#    #+# #+#    #+# #+#   #+#+#     #+#     #+#    #+#    #+#         #+#        #+#        #+#     #+# #+#    #+#      #+#    #+# #+#     #+# #+#       #+# #+#        \n");
    printf(" ########   ########   ########  ###    ####     ###     ###    ###    ###         ###        ########## ###     ###  ########        ########  ###     ### ###       ### ########## \n");
    printf("\n");
    printf(reset);
}

void banner_perdeu()
{
    printf(RED);
    printf("\n");
    printf("::::::::::: :::::::::: ::::    ::: ::::::::::: ::::::::::      ::::    :::  ::::::::  :::     :::     :::     ::::    ::::  :::::::::: ::::    ::: ::::::::::: :::::::::: \n");
    printf("    :+:     :+:        :+:+:   :+:     :+:     :+:             :+:+:   :+: :+:    :+: :+:     :+:   :+: :+:   +:+:+: :+:+:+ :+:        :+:+:   :+:     :+:     :+:        \n");
    printf("    +:+     +:+        :+:+:+  +:+     +:+     +:+             :+:+:+  +:+ +:+    +:+ +:+     +:+  +:+   +:+  +:+ +:+:+ +:+ +:+        :+:+:+  +:+     +:+     +:+        \n");
    printf("    +#+     +#++:++#   +#+ +:+ +#+     +#+     +#++:++#        +#+ +:+ +#+ +#+    +:+ +#+     +:+ +#++:++#++: +#+  +:+  +#+ +#++:++#   +#+ +:+ +#+     +#+     +#++:++#   \n");
    printf("    +#+     +#+        +#+  +#+#+#     +#+     +#+             +#+  +#+#+# +#+    +#+  +#+   +#+  +#+     +#+ +#+       +#+ +#+        +#+  +#+#+#     +#+     +#+        \n");
    printf("    #+#     #+#        #+#   #+#+#     #+#     #+#             #+#   #+#+# #+#    #+#   #+#+#+#   #+#     #+# #+#       #+# #+#        #+#   #+#+#     #+#     #+#        \n");
    printf("    ###     ########## ###    ####     ###     ##########      ###    ####  ########      ###     ###     ### ###       ### ########## ###    ####     ###     ########## \n");
    printf("\n");
    printf(reset);
}

void banner_ganhou()
{
    printf(GRN);
    printf("\n");
    printf("\n");
    printf("\n");
    printf(reset);
}
#else

#define HEART "❤ "

void banner()
{
    printf(MAG);
    printf("\n");
    printf(" ██████╗ ██████╗ ██╗   ██╗███╗   ██╗████████╗██████╗ ██╗   ██╗    ███████╗██╗      █████╗  ██████╗      ██████╗  █████╗ ███╗   ███╗███████╗\n");
    printf("██╔════╝██╔═══██╗██║   ██║████╗  ██║╚══██╔══╝██╔══██╗╚██╗ ██╔╝    ██╔════╝██║     ██╔══██╗██╔════╝     ██╔════╝ ██╔══██╗████╗ ████║██╔════╝\n");
    printf("██║     ██║   ██║██║   ██║██╔██╗ ██║   ██║   ██████╔╝ ╚████╔╝     █████╗  ██║     ███████║██║  ███╗    ██║  ███╗███████║██╔████╔██║█████╗  \n");
    printf("██║     ██║   ██║██║   ██║██║╚██╗██║   ██║   ██╔══██╗  ╚██╔╝      ██╔══╝  ██║     ██╔══██║██║   ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  \n");
    printf("╚██████╗╚██████╔╝╚██████╔╝██║ ╚████║   ██║   ██║  ██║   ██║       ██║     ███████╗██║  ██║╚██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗\n");
    printf(" ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝       ╚═╝     ╚══════╝╚═╝  ╚═╝ ╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n");
    printf("\n");
    printf(reset);
}

void banner_perdeu()
{
    printf(RED);
    printf("\n");
    printf("████████ ███████ ███    ██ ████████ ███████     ███    ██  ██████  ██    ██  █████  ███    ███ ███████ ███    ██ ████████ ███████\n");
    printf("   ██    ██      ████   ██    ██    ██          ████   ██ ██    ██ ██    ██ ██   ██ ████  ████ ██      ████   ██    ██    ██     \n");
    printf("   ██    █████   ██ ██  ██    ██    █████       ██ ██  ██ ██    ██ ██    ██ ███████ ██ ████ ██ █████   ██ ██  ██    ██    █████  \n");
    printf("   ██    ██      ██  ██ ██    ██    ██          ██  ██ ██ ██    ██  ██  ██  ██   ██ ██  ██  ██ ██      ██  ██ ██    ██    ██     \n");
    printf("   ██    ███████ ██   ████    ██    ███████     ██   ████  ██████    ████   ██   ██ ██      ██ ███████ ██   ████    ██    ███████\n");
    printf("\n");
    printf(reset);
}
#endif

// Estrutura de dados
typedef struct Pais
{
    int id; // 0 ate 194
    char iso[3];
    char nome[MAX_NAME_LENGTH];
    int continente; // 1: America, 2: Africa, 3: Asia, 4: Europa, 5: Oceania
    
    struct Pais *prox;
} Pais;

typedef struct Alternativas
{
    char a[MAX_NAME_LENGTH];
    char b[MAX_NAME_LENGTH];
    char c[MAX_NAME_LENGTH];
    char d[MAX_NAME_LENGTH];
    int correta;
} Alternativas;

typedef struct Jogador
{
    int vidas;
    int pontos;
    int lose;
} Jogador;

typedef struct Placar {
    char nome[MAX_NOME];
    double tempo;
    int pontos;
} Placar;

void menu();
void banner();
void menu_do_jogo();
void game(int continente);
void adicionar_pais(Pais **head, Pais **pais);
void carregar_paises(Pais **head, int continente);
void print_bandeira_pais(char iso2[3]);
Pais *retornar_struct_pais(int id);
void modo_de_jogo_rogue_like();

int main()
{
    menu();
    return 0;
}

void salvar_jogador_no_placar(const char *nome, double valor, int numero) {
    FILE *arquivo;
    arquivo = fopen("placar.txt", "a"); // Abre o arquivo para escrita, adicionando dados ao final
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreve os dados no arquivo
    int escritos = fprintf(arquivo, "%s %.1f %d\n", nome, valor, numero);
    
    fclose(arquivo); // Fecha o arquivo
}


void ler_placar(Placar placar[], int *n_jogadores) {
    FILE *arquivo;
    arquivo = fopen("placar.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    *n_jogadores = 0;
    while (fscanf(arquivo, "%s %lf %d", placar[*n_jogadores].nome, &placar[*n_jogadores].tempo, &placar[*n_jogadores].pontos) == 3) {
        (*n_jogadores)++;
    }

    fclose(arquivo);
}

void insertion_sort(Placar placar[], int n_jogadores) {
    int i, j;
    Placar chave;

    for (i = 1; i < n_jogadores; i++) {
        chave = placar[i];
        j = i - 1;

        // Ordenar por pontuação, tempo e nome
        while (j >= 0 && (placar[j].pontos < chave.pontos || (placar[j].pontos == chave.pontos && placar[j].tempo > chave.tempo) || (placar[j].pontos == chave.pontos && placar[j].tempo == chave.tempo && strcmp(placar[j].nome, chave.nome) > 0))) {
            placar[j + 1] = placar[j];
            j = j - 1;
        }
        placar[j + 1] = chave;
    }
}

void exibir_placar(Placar placar[], int n_jogadores) {
    printf("Placar:\n");
    printf("--------------------------------------------------------------\n");
    printf("Posição  Nome             Tempo    Pontuação\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n_jogadores; i++) {
        printf("%-8d %-16s %.1lf     %d\n", i+1, placar[i].nome, placar[i].tempo, placar[i].pontos);
    }
    printf("--------------------------------------------------------------\n");
}

void embaralhar(int *array, size_t n)
{
    srand(time(NULL));
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

void carregar_todos_paises(Pais **head)
{
    int todos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194};

    int tamanho = sizeof(todos) / sizeof(todos[0]); // Calcula o tamanho do array
    embaralhar(todos, tamanho);

    for (int i = 0; i < 194; i++)
    {

        Pais *pais = retornar_struct_pais(todos[i]);

        if (pais != NULL)
        {
            adicionar_pais(head, &pais);
        }
    }

    system(CLEAR_SCREEN);
}

void carregar_paises(Pais **head, int continente)
{
    // 0: todos, 1: america, 2: africa, 3: asia, 4: europa, 5: oceania
    int todos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194};
    int america[] = {7, 12, 21, 22, 23, 27, 28, 34, 37, 38, 39, 46, 47, 49, 61, 68, 70, 71, 73, 83, 91, 98, 122, 128, 135, 136, 144, 162, 165, 177, 182, 183, 186, 187};
    int africa[] = {15, 18, 19, 25, 29, 30, 31, 33, 35, 40, 44, 48, 51, 52, 54, 59, 63, 64, 65, 66, 69, 86, 90, 101, 102, 106, 107, 111, 114, 117, 119, 121, 124, 125, 126, 127, 149, 152, 153, 158, 160, 161, 163, 164, 167, 168, 169, 174, 179, 181, 192, 193, 194};
    int asia[] = {2, 5, 10, 13, 17, 20, 24, 36, 41, 62, 75, 77, 78, 79, 80, 84, 85, 87, 88, 92, 93, 94, 95, 96, 97, 100, 115, 116, 120, 123, 131, 134, 138, 139, 141, 145, 150, 155, 166, 170, 171, 172, 173, 176, 184, 188, 191};
    int europa[] = {0, 4, 8, 11, 14, 16, 26, 32, 42, 43, 45, 50, 53, 55, 58, 60, 67, 72, 74, 76, 81, 82, 99, 103, 104, 105, 108, 109, 110, 113, 118, 129, 130, 140, 142, 146, 147, 148, 154, 156, 157, 159, 180, 185};
    int oceania[] = {56, 57, 89, 112, 132, 133, 137, 143, 151, 175, 178, 189, 190};

    if (continente == 0)
    {
        int tamanho = sizeof(todos) / sizeof(todos[0]); // Calcula o tamanho do array
        embaralhar(todos, tamanho);

        for (int i = 0; i < 10; i++)
        {

            printf("> %d\n", todos[i]);

            Pais *pais = retornar_struct_pais(todos[i]);

            if (pais != NULL)
            {
                adicionar_pais(head, &pais);
            }
        }
    }
    else if (continente == 1)
    {
        int tamanho = sizeof(america) / sizeof(america[0]); // Calcula o tamanho do array
        embaralhar(america, tamanho);

        for (int i = 0; i < 10; i++)
        {

            printf("> %d\n", america[i]);

            Pais *pais = retornar_struct_pais(america[i]);

            if (pais != NULL)
            {
                adicionar_pais(head, &pais);
            }
        }
    }
    else if (continente == 2)
    {
        int tamanho = sizeof(africa) / sizeof(africa[0]); // Calcula o tamanho do array
        embaralhar(africa, tamanho);

        for (int i = 0; i < 10; i++)
        {

            printf("> %d\n", africa[i]);

            Pais *pais = retornar_struct_pais(africa[i]);

            if (pais != NULL)
            {
                adicionar_pais(head, &pais);
            }
        }
    }
    else if (continente == 3)
    {
        int tamanho = sizeof(asia) / sizeof(asia[0]); // Calcula o tamanho do array
        embaralhar(asia, tamanho);

        for (int i = 0; i < 10; i++)
        {

            printf("> %d\n", asia[i]);

            Pais *pais = retornar_struct_pais(asia[i]);

            if (pais != NULL)
            {
                adicionar_pais(head, &pais);
            }
        }
    }
    else if (continente == 4)
    {
        int tamanho = sizeof(europa) / sizeof(europa[0]); // Calcula o tamanho do array
        embaralhar(europa, tamanho);

        for (int i = 0; i < 10; i++)
        {

            printf("> %d\n", europa[i]);

            Pais *pais = retornar_struct_pais(europa[i]);

            if (pais != NULL)
            {
                adicionar_pais(head, &pais);
            }
        }
    }
    else
    {
        int tamanho = sizeof(oceania) / sizeof(oceania[0]); // Calcula o tamanho do array
        embaralhar(oceania, tamanho);

        for (int i = 0; i < 10; i++)
        {

            printf("> %d\n", oceania[i]);

            Pais *pais = retornar_struct_pais(oceania[i]);

            if (pais != NULL)
            {
                adicionar_pais(head, &pais);
            }
        }
    }
}

void print_bandeira_pais(char iso2[3])
{
    FILE *bandeira_file;
    char linha[MAX_LINE_LENGTH];
    char iso2_lido[3], pais[MAX_LINE_LENGTH];
    int continente_lido;
    char arquivo[MAX_LINE_LENGTH];

    sprintf(arquivo, "bandeiras-ansi/%s.ans", iso2);

    // Abrir o arquivo da bandeira
    bandeira_file = fopen(arquivo, "r");

    // Ler e imprimir a bandeira
    while (fgets(linha, sizeof(linha), bandeira_file) != NULL)
    {
        printf("%s", linha);
    }

    // Fechar o arquivo da bandeira
    fclose(bandeira_file);
}

Pais *retornar_struct_pais(int id)
{
    FILE *paises_file;
    char linha[MAX_LINE_LENGTH];
    Pais *info = malloc(sizeof(Pais)); // Alocar memoria para a estrutura Pais

    // Abrir o arquivo de paises
    paises_file = fopen("paises.txt", "r");

    // Ler o arquivo de paises linha por linha
    while (fgets(linha, sizeof(linha), paises_file) != NULL)
    {
        // Extrair os valores da linha
        sscanf(linha, "%d,%2s,%[^,],%d", &info->id, info->iso, info->nome, &info->continente);

        // Verificar se o ID corresponde ao desejado
        if (info->id == id)
        {
            // Fechar o arquivo de paises
            fclose(paises_file);
            return info;
        }
    }

    // Fechar o arquivo de paises
    fclose(paises_file);

    // Se o ID nao for encontrado, liberar a memoria alocada e retornar NULL
    free(info);
    return NULL;
}

void adicionar_pais(Pais **head, Pais **pais)
{
    Pais *novo = *pais;

    if (novo != NULL)
    {
        novo->prox = *head;
        *head = novo;
    }
}

void menu()
{
    while (1)
    {

        system(CLEAR_SCREEN);

        int opcao;

        banner();
        printf("\n");
        printf(YEL "[1] Jogar\n" reset);
        printf(BLU "[2] Placar de jogadores\n" reset);
        printf(CYN "[3] Sair\n" reset);
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            menu_do_jogo();
        }
        else if (opcao == 2)
        {
            system(CLEAR_SCREEN);

            Placar placar[100];
            int n_jogadores;

            ler_placar(placar, &n_jogadores);
            insertion_sort(placar, n_jogadores);
            exibir_placar(placar, n_jogadores);

            printf("Aperte enter para voltar ao menu.");
            getchar();
            getchar();
            menu();
        }
        else if (opcao == 3)
        {
            return;
        }
        else
        {
            printf("Opcao Invalida!\n");
            menu();
        }

        return;
    }
}

void menu_do_jogo()
{
    int modo_de_jogo;
    printf("Escolha o modo de jogo:\n");
    printf("[0] Voltar para o menu principal\n");
    printf("[1] Todos os paises\n");
    printf("[2] Paises da America\n");
    printf("[3] Paises da Africa\n");
    printf("[4] Paises da Asia\n");
    printf("[5] Paises da Europa\n");
    printf("[6] Paises da Oceania\n");
    printf(RED "[666] Rogue Like Mode (Dificil)\n" reset);
    printf("Escolha: ");
    scanf("%d", &modo_de_jogo);

    if (modo_de_jogo == 0)
    {
        menu();
    }
    if (modo_de_jogo == 1)
    {
        game(0);
    }
    else if (modo_de_jogo == 2)
    {
        game(1);
    }
    else if (modo_de_jogo == 3)
    {
        game(2);
    }
    else if (modo_de_jogo == 4)
    {
        game(3);
    }
    else if (modo_de_jogo == 5)
    {
        game(4);
    }
    else if (modo_de_jogo == 6)
    {
        game(5);
    }
    else if (modo_de_jogo == 666)
    {
        modo_de_jogo_rogue_like();
    }
    else
    {
        printf("Opcao Invalida!\n");
        menu_do_jogo();
    }
}

void embaralhar_com_base_no_correto(int arr[], int size, int specificElement)
{
    // Inicializa o gerador de numeros aleatorios com uma semente diferente a cada execucao
    srand(time(NULL));

    // Embaralhamento usando o algoritmo de Fisher-Yates
    for (int i = size - 1; i > 0; i--)
    {
        // Escolhe um indice aleatorio entre 0 e i (inclusive)
        int j = rand() % (i + 1);

        // Troca arr[i] com arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Coloca o elemento especifico no final do array
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == specificElement)
        {
            int temp = arr[i];
            arr[i] = arr[size - 1];
            arr[size - 1] = temp;
            break;
        }
    }
}

Alternativas gerar_alternativas(int pais)
{
    int todos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194};

    srand(time(NULL));

    int indice_letra_a;
    int indice_letra_b;
    int indice_letra_c;
    int indice_letra_d;

    int tamanho = sizeof(todos) / sizeof(todos[0]); // Calcula o tamanho do array

    embaralhar_com_base_no_correto(todos, tamanho, pais);

    // Gera um indice aleatorio dentro do intervalo do array

    // Gerar qual letra vai ser a resposta correta
    int resposta_correta = rand() % 4;

    Alternativas alt;

    alt.correta = resposta_correta + 1;

    if (resposta_correta == 0)
    {
        Pais *paisA = retornar_struct_pais(pais);
        strcpy(alt.a, paisA->nome);

        indice_letra_b = todos[0];
        Pais *paisB = retornar_struct_pais(indice_letra_b);
        strcpy(alt.b, paisB->nome);

        indice_letra_c = todos[1];
        Pais *paisC = retornar_struct_pais(indice_letra_c);
        strcpy(alt.c, paisC->nome);

        indice_letra_d = todos[2];
        Pais *paisD = retornar_struct_pais(indice_letra_d);
        strcpy(alt.d, paisD->nome);
    }
    else if (resposta_correta == 1)
    {
        indice_letra_a = todos[0];
        Pais *paisA = retornar_struct_pais(indice_letra_a);
        strcpy(alt.a, paisA->nome);

        Pais *paisB = retornar_struct_pais(pais);
        strcpy(alt.b, paisB->nome);

        indice_letra_c = todos[1];
        Pais *paisC = retornar_struct_pais(indice_letra_c);
        strcpy(alt.c, paisC->nome);

        indice_letra_d = todos[2];
        Pais *paisD = retornar_struct_pais(indice_letra_d);
        strcpy(alt.d, paisD->nome);
    }
    else if (resposta_correta == 2)
    {
        indice_letra_a = todos[0];
        Pais *paisA = retornar_struct_pais(indice_letra_a);
        strcpy(alt.a, paisA->nome);

        indice_letra_b = todos[1];
        Pais *paisB = retornar_struct_pais(indice_letra_b);
        strcpy(alt.b, paisB->nome);

        Pais *paisC = retornar_struct_pais(pais);
        strcpy(alt.c, paisC->nome);

        indice_letra_d = todos[2];
        Pais *paisD = retornar_struct_pais(indice_letra_d);
        strcpy(alt.d, paisD->nome);
    }
    else if (resposta_correta == 3)
    {
        indice_letra_a = todos[0];
        Pais *paisA = retornar_struct_pais(indice_letra_a);
        strcpy(alt.a, paisA->nome);

        indice_letra_b = todos[1];
        Pais *paisB = retornar_struct_pais(indice_letra_b);
        strcpy(alt.b, paisB->nome);

        indice_letra_c = todos[2];
        Pais *paisC = retornar_struct_pais(indice_letra_c);
        strcpy(alt.c, paisC->nome);

        Pais *paisD = retornar_struct_pais(pais);
        strcpy(alt.d, paisD->nome);
    }

    return alt;
}

void modo_de_jogo_rogue_like()
{
    char nome_jogador[100];
    while (getchar() != '\n');
    printf("Digite o nome: ");
    fgets(nome_jogador, sizeof(nome_jogador), stdin);
    nome_jogador[strcspn(nome_jogador, "\n")] = '\0';

    Pais *head = NULL;

    carregar_todos_paises(&head);

    Jogador Jogador;
    Jogador.vidas = 3;
    Jogador.lose = 0;
    Jogador.pontos = 0;

    time_t tempo_inicio;
    time(&tempo_inicio);

    for (int i = 0; i < 194; i++)
    {
        if (Jogador.lose == 1)
        {
            break;
        }

        system(CLEAR_SCREEN);

        print_bandeira_pais(head->iso);

        printf("\n[-] Modo de jogo: " RED "Rogue Like (GOD MODE)\n" reset);

        printf("[-] Vida(s): " RED);
        for (int i = 0; i < Jogador.vidas; i++)
        {
            printf(HEART);
        }

        printf("\n" reset);

        printf("\n[?] Responda corretamente, de qual Pais e essa bandeira?\n\n");

        // Gerar alternativas

        Alternativas alternativas = gerar_alternativas(head->id);

        printf("1) %s\n", alternativas.a);
        printf("2) %s\n", alternativas.b);
        printf("3) %s\n", alternativas.c);
        printf("4) %s\n", alternativas.d);

        while (1)
        {
            int resposta;

            while (1)
            {
                printf("\nDigite o numero correspondente ao pais: ");
                if (scanf("%d", &resposta) == 1)
                {
                    break;
                }
                else
                {
                    printf("Resposta invalida, tente novamente.\n");

                    getchar();
                    getchar();
                }
            }

            // Validacao das alternativas
            system(CLEAR_SCREEN);
            print_bandeira_pais(head->iso);

            if (resposta == alternativas.correta)
            {
                printf(GRN "\n[+] Voce acertou a bandeira.\n\n" reset);
                Jogador.pontos += 1;
            }
            else
            {
                printf(RED "\n[-] Voce errou a bandeira." reset);
                Jogador.vidas--;
                printf(RED "\n[-] Voce perdeu um coracao. Resta apenas %d\n\n" reset, Jogador.vidas);
            }

            if (alternativas.correta == 1)
            {
                printf(GRN);
                if (alternativas.correta == resposta)
                {
                    printf("1) %s <\n", alternativas.a);
                }
                else
                {
                    printf("1) %s\n", alternativas.a);
                }
                printf(reset);
            }
            else
            {
                if (resposta == 1)
                {
                    printf(RED "1) %s <\n" reset, alternativas.a);
                }
                else
                {
                    printf("1) %s\n", alternativas.a);
                }
            }

            if (alternativas.correta == 2)
            {
                printf(GRN);
                if (alternativas.correta == resposta)
                {
                    printf("2) %s <\n", alternativas.b);
                }
                else
                {
                    printf("2) %s\n", alternativas.b);
                }
                printf(reset);
            }
            else
            {
                if (resposta == 2)
                {
                    printf(RED "2) %s <\n" reset, alternativas.b);
                }
                else
                {
                    printf("2) %s\n", alternativas.b);
                }
            }

            if (alternativas.correta == 3)
            {
                printf(GRN);
                if (alternativas.correta == resposta)
                {
                    printf("3) %s <\n", alternativas.c);
                }
                else
                {
                    printf("3) %s\n", alternativas.c);
                }
                printf(reset);
            }
            else
            {
                if (resposta == 3)
                {
                    printf(RED "3) %s <\n" reset, alternativas.c);
                }
                else
                {
                    printf("3) %s\n", alternativas.c);
                }
            }

            if (alternativas.correta == 4)
            {
                printf(GRN);
                if (alternativas.correta == resposta)
                {
                    printf("4) %s <\n", alternativas.d);
                }
                else
                {
                    printf("4) %s\n", alternativas.d);
                }
                printf(reset);
            }
            else
            {
                if (resposta == 4)
                {
                    printf(RED "4) %s <\n" reset, alternativas.d);
                }
                else
                {
                    printf("4) %s\n", alternativas.d);
                }
            }

            if (Jogador.vidas <= 0)
            {
                Jogador.lose = 1;
                break;
            }

            if (resposta == 1 || resposta == 2 || resposta == 3 || resposta == 4)
            {
                printf("\nAperte enter para ir para proxima bandeira.\n");
                getchar();
                getchar();
                break;
            }

            printf("Resposta invalida, tente novamente.\n");
        }
        head = head->prox;
    }

    time_t tempo_fim;
    time(&tempo_fim);

    system(CLEAR_SCREEN);

    double diferenca = difftime(tempo_fim, tempo_inicio);

    // Imprimir a diferenca em segundos

    if (Jogador.vidas == 0)
    {
        banner_perdeu();
    }

    //
    salvar_jogador_no_placar(nome_jogador, diferenca, Jogador.pontos);
    //

    printf("> Estatisticas\n");
    printf(BGRN "- Voce completou em " BBLU "%lf" BGRN " segundos.\n", diferenca);
    printf("- Voce acertou " BBLU "%d" BGRN " bandeiras de 195.\n" reset, Jogador.pontos);

    printf("Aperte enter para voltar o menu.\n");
    getchar();
    getchar();
    menu();
}

void game(int continente)
{
    Pais *head = NULL;

    carregar_paises(&head, continente);

    int pontos = 0;

    time_t tempo_inicio;
    time(&tempo_inicio);

    for (int i = 0; i < 10; i++)
    {

        system(CLEAR_SCREEN);
        print_bandeira_pais(head->iso);
        printf("Responda corretamente, de qual Pais e essa bandeira?\n");

        // Gerar alternativas

        Alternativas alternativas = gerar_alternativas(head->id);

        printf("1) %s\n", alternativas.a);
        printf("2) %s\n", alternativas.b);
        printf("3) %s\n", alternativas.c);
        printf("4) %s\n", alternativas.d);

        while (1)
        {
            int resposta;

            while (1)
            {
                printf("Digite o numero correspondente ao pais: ");
                if (scanf("%d", &resposta) == 1)
                {
                    break;
                }
                else
                {
                    printf("Resposta invalida, tente novamente.\n");

                    getchar();
                    getchar();
                }
            }

            // Validacao das alternativas

            if (resposta == alternativas.correta)
            {
                printf(BLU ">" YEL ">" GRN ">" "Parabens voce acertou!" GRN "<" YEL "<" BLU "<\n" reset);
                pontos += 1;
            }

            if (resposta == 1 || resposta == 2 || resposta == 3 || resposta == 4)
            {
                printf("Aperte enter para ir para proxima bandeira.\n");
                getchar();
                getchar();
                break;
            }

            printf("Resposta invalida, tente novamente.\n");
        }
        head = head->prox;
    }

    time_t tempo_fim;
    time(&tempo_fim);

    system(CLEAR_SCREEN);

    double diferenca = difftime(tempo_fim, tempo_inicio);

    // Imprimir a diferenca em segundos

    printf("📃 Estatisticas\n");
    printf(BGRN "- Voce completou em " BBLU "%lf" BGRN " segundos.\n", diferenca);
    printf("- Voce acertou " BBLU "%d" BGRN " bandeiras de 10.\n" reset, pontos);
    printf("Aperte enter para voltar o menu.\n");
    getchar();
    getchar();
    menu();
}