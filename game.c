#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MAX_NAME_LENGTH 50

void menu();
void banner();
void game_menu();
void placar_de_jogadores();
void game(int continente);

// Estrutura de dados
typedef struct Pais
{
    int id; // 0 até 194
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
    char nome[MAX_NAME_LENGTH];
    int pontos;
} Jogador;

void adicionar_pais(Pais **head, Pais **pais);
void remover_pais(Pais **head, int id);
void imprimir_bandeira(Pais *head, int id);
void carregar_paises(Pais **head, int continente);
void print_bandeira_pais(char iso2[3]);
int numeroExiste(int numero, int *array, int tamanho);
Pais *retornar_struct_pais(int id);
void randomizar_ordem_bandeiras();
void randomizar_respostas();
void placar_jogadores();
void listar_paises(Pais *head);

int main()
{
    menu();
    return 0;
}

void listar_paises(Pais *head)
{
    while (head != NULL)
    {
        print_bandeira_pais(head->iso);
        printf("\n");
        head = head->prox;
    }
    printf("\n");
}

int numeroExiste(int numero, int *array, int tamanho)
{
    for (int i = 0; i < tamanho; ++i)
    {
        if (array[i] == numero)
        {
            return 1;
        }
    }
    return 0;
}

int tamanhoArray(int *array)
{
    int tamanho = 0;

    // Incrementa o tamanho enquanto o elemento atual for diferente de -1
    while (array[tamanho] != -1)
    {
        tamanho++;
    }

    return tamanho;
}

void shuffle(int *array, size_t n)
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
        shuffle(todos, tamanho);

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
        shuffle(america, tamanho);

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
        shuffle(africa, tamanho);

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
        shuffle(asia, tamanho);

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
        shuffle(europa, tamanho);

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
        shuffle(oceania, tamanho);

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
    if (bandeira_file == NULL)
    {
        printf("Erro ao abrir o arquivo da bandeira para %s.\n", pais);
        exit(EXIT_FAILURE);
    }

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
    Pais *info = malloc(sizeof(Pais)); // Alocar memória para a estrutura Pais

    // Verificar se a alocação de memória foi bem-sucedida
    if (info == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    // Abrir o arquivo de países
    paises_file = fopen("paises.txt", "r");
    if (paises_file == NULL)
    {
        printf("Erro ao abrir o arquivo de países.\n");
        exit(EXIT_FAILURE);
    }

    // Ler o arquivo de países linha por linha
    while (fgets(linha, sizeof(linha), paises_file) != NULL)
    {
        // Extrair os valores da linha
        sscanf(linha, "%d,%2s,%[^,],%d", &info->id, info->iso, info->nome, &info->continente);

        // Verificar se o ID corresponde ao desejado
        if (info->id == id)
        {
            // Fechar o arquivo de países
            fclose(paises_file);
            // printf("%d %s %s %d\n", info->id, info->iso, info->nome, info->continente);
            return info;
        }
    }

    // Fechar o arquivo de países
    fclose(paises_file);

    // Se o ID não for encontrado, liberar a memória alocada e retornar NULL
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
            // placar_de_jogadores();
        }
        else if (opcao == 3)
        {
            return;
        }
        else
        {
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
        game(1);
    }
    else if (modo_de_jogo == 4)
    {
        game(2);
    }
    else if (modo_de_jogo == 5)
    {
        game(3);
    }
    else if (modo_de_jogo == 6)
    {
        game(4);
    }
    else if (modo_de_jogo == 7)
    {
        game(5);
    }
    else
    {
        printf("Opção Inválida!\n");
        game_menu();
    }
}

void insertion_sort(Jogador *jogadores, int num_jogadores)
{
    int i, j;
    Jogador chave;
    for (i = 1; i < num_jogadores; i++)
    {
        chave = jogadores[i];
        j = i - 1;
        while (j >= 0 && jogadores[j].pontos < chave.pontos)
        {
            jogadores[j + 1] = jogadores[j];
            j = j - 1;
        }
        jogadores[j + 1] = chave;
    }
}

void placar_jogadores()
{
    FILE *placar_file;
    char linha[MAX_LINE_LENGTH];
    Jogador *jogadores = NULL;
    int num_jogadores = 0;
    int capacidade_jogadores = 0;

    // Abrir o arquivo de placar
    placar_file = fopen("placar.txt", "r");
    if (placar_file == NULL)
    {
        printf("Erro ao abrir o arquivo de placar.\n");
        exit(EXIT_FAILURE);
    }

    // Ler o arquivo de placar e armazenar os jogadores
    while (fgets(linha, sizeof(linha), placar_file) != NULL)
    {
        // Verificar se é necessário realocar espaço para mais jogadores
        if (num_jogadores >= capacidade_jogadores)
        {
            capacidade_jogadores += 10; // Incremento arbitrário
            jogadores = realloc(jogadores, capacidade_jogadores * sizeof(Jogador));
            if (jogadores == NULL)
            {
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
    for (int i = 0; i < num_jogadores; i++)
    {
        printf("%s - Pontos: %d\n", jogadores[i].nome, jogadores[i].pontos);
    }

    // Liberar a memória alocada para os jogadores
    free(jogadores);
}

// TODO: Fazer depois
// void inserir_placar_jogadores(){
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

void shuffleWithSpecificLast(int arr[], int size, int specificElement)
{
    // Inicializa o gerador de números aleatórios com uma semente diferente a cada execução
    srand(time(NULL));

    // Embaralhamento usando o algoritmo de Fisher-Yates
    for (int i = size - 1; i > 0; i--)
    {
        // Escolhe um índice aleatório entre 0 e i (inclusive)
        int j = rand() % (i + 1);

        // Troca arr[i] com arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Coloca o elemento específico no final do array
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

    shuffleWithSpecificLast(todos, tamanho, pais);

    // Gera um índice aleatório dentro do intervalo do array

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

void game(int continente)
{
    Pais *head = NULL;

    carregar_paises(&head, continente);

    int pontuacao = 0;

    for (int i = 0; i < 10; i++)
    {
        print_bandeira_pais(head->iso);
        printf("Responda corretamente, de qual País é essa bandeira?\n");

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
                printf("Digite o número correspondente ao país: ");
                if (scanf("%d", &resposta) == 1)
                {
                    break;
                }
                else
                {
                    printf("Resposta inválida, tente novamente.\n");

                    while (getchar() != '\n')
                        ;
                }
            }

            // Validação das alternativas

            if (resposta == 1)
            {
                break;
            }
            else if (resposta == 2)
            {
                break;
            }
            else if (resposta == 3)
            {
                break;
            }
            else if (resposta == 4)
            {
                break;
            }
            printf("Resposta inválida, tente novamente.\n");
        }
        head = head->prox;
    }
}