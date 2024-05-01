#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para imprimir a bandeira correspondente ao código ISO-2
void imprimir_bandeira(char iso2[], char **todas_as_bandeiras, int *tamanho_total, int *contador_bandeiras) {
    char nome_arquivo[50]; // Nome do arquivo da bandeira
    sprintf(nome_arquivo, "bandeiras-ansi/%s.ans", iso2); // Construir o nome do arquivo

    FILE *arquivo_bandeira = fopen(nome_arquivo, "r"); // Abrir o arquivo da bandeira

    if (arquivo_bandeira == NULL) {
        printf("Bandeira não encontrada para o código ISO-2 %s\n", iso2);
        return;
    }

    // Obtem o tamanho do arquivo da bandeira
    fseek(arquivo_bandeira, 0L, SEEK_END);
    int tamanho_bandeira = ftell(arquivo_bandeira);
    rewind(arquivo_bandeira);

    // Realoca memória suficiente para armazenar a nova bandeira
    *todas_as_bandeiras = realloc(*todas_as_bandeiras, *tamanho_total + tamanho_bandeira + 1);

    // Lê o conteúdo da bandeira e o anexa à string principal
    fread(*todas_as_bandeiras + *tamanho_total, 1, tamanho_bandeira, arquivo_bandeira);
    fclose(arquivo_bandeira);

    // Atualiza o tamanho total
    *tamanho_total += tamanho_bandeira;

    // Adiciona um caractere de nova linha ao final
    (*todas_as_bandeiras)[*tamanho_total] = '\n';
    (*tamanho_total)++;

    // Incrementa o contador de bandeiras
    (*contador_bandeiras)++;
}

int main() {
    FILE *arquivo;
    char linha[100]; // Buffer para armazenar cada linha do arquivo
    char codigo_iso2[3]; // Para armazenar o código ISO-2
    char *todas_as_bandeiras = NULL; // Para armazenar todas as bandeiras
    int tamanho_total = 0; // Tamanho total da string de todas as bandeiras
    int contador_bandeiras = 0; // Contador de bandeiras

    // Abre o arquivo para leitura
    arquivo = fopen("paises.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê e processa cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Extrai o código ISO-2 da linha
        sscanf(linha, "%*[^,], %2s", codigo_iso2);

        // Imprime a bandeira correspondente ao código ISO-2
        imprimir_bandeira(codigo_iso2, &todas_as_bandeiras, &tamanho_total, &contador_bandeiras);
    }

    fclose(arquivo); // Fecha o arquivo

    // Imprime todas as bandeiras
    printf("%s", todas_as_bandeiras);

    // Imprime o número total de bandeiras impressas
    printf("Total de bandeiras impressas: %d\n", contador_bandeiras);

    // Libera a memória alocada
    free(todas_as_bandeiras);

    // Aguarda o usuário pressionar uma tecla
    printf("Pressione qualquer tecla para sair...");
    getchar();

    return 0;
}
