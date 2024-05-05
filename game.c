#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NAME_LENGTH 50

void menu();
void banner();
void game_menu();
void placar_de_jogadores();
void game(int continente);

// Estrutura de dados
typedef struct Pais {
    int id; // 0 até 194
    char iso[3];
    char nome;
    int continente; // 1: America, 2: Africa, 3: Asia, 4: Europa, 5: Oceania
    struct Pais *prox;
} Pais;


typedef struct Jogador {
    char nome[MAX_NAME_LENGTH];
    int pontos;
} Jogador;

void adicionar_pais(Pais **head, int id, char iso[3], char nome, int continente);
void remover_pais(Pais **head, int id);
void imprimir_bandeira(Pais *head, int id);
void carregar_paises(Pais **head, int continente);
void print_bandeira_pais(char iso2[3]);
int numeroExiste(int numero, int *array, int tamanho);
Pais *retonar_struct_pais(int id);
void randomizar_ordem_bandeiras();
void randomizar_respostas();
void placar_jogadores();
void listar_paises(Pais *head);

int main()
{
    menu();
    return 0;
}

void listar_paises(Pais *head) {
    while (head != NULL) {
        printf("%d\n", head);
    }
    printf("\n");
}

int numeroExiste(int numero, int *array, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        if (array[i] == numero) {
            return 1;
        }
    }
    return 0;
}

int tamanhoArray(int *array) {
    int tamanho = 0;

    // Incrementa o tamanho enquanto o elemento atual for diferente de -1
    while (array[tamanho] != -1) {
        tamanho++;
    }

    return tamanho;
}s

void carregar_paises(Pais **head, int continente)
{
    int america[] = {7, 12, 21, 22, 23, 27, 28, 34, 37, 38, 39, 46, 47, 49, 61, 68, 70, 71, 73, 83, 91, 98, 122, 128, 135, 136, 144, 162, 165, 177, 182, 183, 186, 187};
    int africa[] ={15, 18, 19, 25, 29, 30, 31, 33, 35, 40, 44, 48, 51, 52, 54, 59, 63, 64, 65, 66, 69, 86, 90, 101, 102, 106, 107, 111, 114, 117, 119, 121, 124, 125, 126, 127, 149, 152, 153, 158, 160, 161, 163, 164, 167, 168, 169, 174, 179, 181, 192, 193, 194};
    int asia[] = {2, 5, 10, 13, 17, 20, 24, 36, 41, 62, 75, 77, 78, 79, 80, 84, 85, 87, 88, 92, 93, 94, 95, 96, 97, 100, 115, 116, 120, 123, 131, 134, 138, 139, 141, 145, 150, 155, 166, 170, 171, 172, 173, 176, 184, 188, 191};
    int europa[] = {0,4, 8, 11, 14, 16, 26, 32, 42, 43, 45, 50, 53, 55, 58, 60, 67, 72, 74, 76, 81, 82, 99, 103, 104, 105, 108, 109, 110, 113, 118, 129, 130, 140, 142, 146, 147, 148, 154, 156, 157, 159, 180, 185};
    int oceania[] = {56, 57, 89, 112, 132, 133, 137, 143, 151, 175, 178, 189, 190};
    int todos[] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194};

    if (continente == 0) {
        int indices_usados[195];

        while(tamanhoArray(indices_usados) < 194) {
            int indice_aleatorio = rand() % 194;

            if (!numeroExiste(indice_aleatorio, indices_usados, 194)) {
                indices_usados[tamanhoArray(indices_usados)] = indice_aleatorio;

                Pais *pais = retonar_struct_pais(todos[indice_aleatorio]);

                if (pais->id == -1) {printf("PAIS NAO ENCONTRADO!!!!");break;}

                adicionar_pais(head, pais->id, pais->iso, pais->nome, pais->continente);
            }
        }
    }
}

void print_bandeira_pais(char iso2[3]) {
    FILE *paises_file;
    FILE *bandeira_file;
    char linha[MAX_LINE_LENGTH];
    char iso2_lido[3], pais[MAX_LINE_LENGTH];
    int continente_lido;
    char arquivo[MAX_LINE_LENGTH];

    // Abrir o arquivo de países
    paises_file = fopen("paises.txt", "r");
    if (paises_file == NULL) {
        printf("Erro ao abrir o arquivo de países.\n");
        exit(EXIT_FAILURE);
    }

    // Ler o arquivo de países linha por linha
    while (fgets(linha, sizeof(linha), paises_file) != NULL) {
        // Extrair os valores da linha
        sscanf(linha, "%*d,%c,%[^,],%d", &iso2_lido, pais, &continente_lido);

        // Verificar se o ISO2 corresponde ao desejado
        if (strcmp(iso2_lido, iso2) == 0) {
            // Construir o nome do arquivo da bandeira
            sprintf(arquivo, "bandeiras-ansi/%s.ans", iso2);

            // Abrir o arquivo da bandeira
            bandeira_file = fopen(arquivo, "r");
            if (bandeira_file == NULL) {
                printf("Erro ao abrir o arquivo da bandeira para %s.\n", pais);
                exit(EXIT_FAILURE);
            }

            // Ler e imprimir a bandeira
            printf("Bandeira para %s:\n", pais);
            while (fgets(linha, sizeof(linha), bandeira_file) != NULL) {
                printf("%s", linha);
            }

            // Fechar o arquivo da bandeira
            fclose(bandeira_file);

            // Não é necessário continuar procurando
            break;
        }
    }

    // Fechar o arquivo de países
    fclose(paises_file);
}

Pais *retonar_struct_pais(int id) {
    FILE *paises_file;
    char linha[MAX_LINE_LENGTH];
    Pais *info;

    // Abrir o arquivo de países
    paises_file = fopen("paises.txt", "r");
    if (paises_file == NULL) {
        printf("Erro ao abrir o arquivo de países.\n");
        exit(EXIT_FAILURE);
    }

    // Ler o arquivo de países linha por linha
    while (fgets(linha, sizeof(linha), paises_file) != NULL) {
        // Extrair os valores da linha
        sscanf(linha, "%d,%2s,%[^,],%d", &info->id, info->iso, info->nome, &info->continente);

        // Verificar se o ID corresponde ao desejado
        if (info->id == id) {
            // Fechar o arquivo de países
            fclose(paises_file);
            return info;
        }
    }

    // Fechar o arquivo de países
    fclose(paises_file);

    // Se o ID não for encontrado, retornar uma struct com valores padrão
    Pais *not_found = NULL;
    return not_found;
}

void adicionar_pais(Pais **head, int id, char iso[3], char nome, int continente){
    Pais *novo = (Pais*)malloc(sizeof(Pais));
    if(novo !=NULL){
        novo->id = id;
        novo->continente = continente;
        strncpy(novo->iso, iso, 3);
        novo->nome = nome;
        novo->prox = *head;
        *head = novo;
    }
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
            //placar_de_jogadores();
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
        game(0);
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

void insertion_sort(Jogador *jogadores, int num_jogadores) {
    int i, j;
    Jogador chave;
    for (i = 1; i < num_jogadores; i++) {
        chave = jogadores[i];
        j = i - 1;
        while (j >= 0 && jogadores[j].pontos < chave.pontos) {
            jogadores[j + 1] = jogadores[j];
            j = j - 1;
        }
        jogadores[j + 1] = chave;
    }
}

void placar_jogadores() {
    FILE *placar_file;
    char linha[MAX_LINE_LENGTH];
    Jogador *jogadores = NULL;
    int num_jogadores = 0;
    int capacidade_jogadores = 0;

    // Abrir o arquivo de placar
    placar_file = fopen("placar.txt", "r");
    if (placar_file == NULL) {
        printf("Erro ao abrir o arquivo de placar.\n");
        exit(EXIT_FAILURE);
    }

    // Ler o arquivo de placar e armazenar os jogadores
    while (fgets(linha, sizeof(linha), placar_file) != NULL) {
        // Verificar se é necessário realocar espaço para mais jogadores
        if (num_jogadores >= capacidade_jogadores) {
            capacidade_jogadores += 10; // Incremento arbitrário
            jogadores = realloc(jogadores, capacidade_jogadores * sizeof(Jogador));
            if (jogadores == NULL) {
                printf("Erro ao alocar memória.\n");
                exit(EXIT_FAILURE);
            }
        }
        // Extrair os valores da linha
        sscanf(linha, "%s %d", jogadores[num_jogadores].nome, &jogadores[num_jogadores].pontos);
        num_jogadores++;
    }

    // Fechar o arquivo de placar
    fclose(placar_file);

    // Ordenar os jogadores pelo número de pontos usando o insertion sort
    insertion_sort(jogadores, num_jogadores);

    // Imprimir os jogadores ordenados
    printf("Placar dos jogadores:\n");
    for (int i = 0; i < num_jogadores; i++) {
        printf("%s - Pontos: %d\n", jogadores[i].nome, jogadores[i].pontos);
    }

    // Liberar a memória alocada para os jogadores
    free(jogadores);
}

// TODO: Fazer depois
//void inserir_placar_jogadores(){
//    FILE *placar_file;
//
//    // Abrir o arquivo de placar no modo de adição
//    placar_file = fopen("placar.txt", "a");
//    if (placar_file == NULL) {
//        printf("Erro ao abrir o arquivo de placar.\n");
//        exit(EXIT_FAILURE);
//    }
//    // Escrever os dados do jogador no arquivo
//    fprintf(placar_file, "%s %d\n", nome, pontos);
//
//    // Fechar o arquivo de placar
//    fclose(placar_file);
//}

void todos_continentes(){

}

void continente(int continente) {

}

void game(int continente) {
    Pais *head = NULL;

    carregar_paises(&head, continente);
    listar_paises(head);
}