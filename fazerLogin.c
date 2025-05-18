#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fazerLogin(char *usuarioLogado, char *rgmLogado) {
    char rgm[20];
    
    system("cls");

    printf("===========================================\n");
    printf("           REPROVADOR 3000\n");
    printf("===========================================\n\n");

    printf("[ LOGIN DO USUARIO ]\n");
    printf("Informe os dados da sua conta para continuar.\n\n");

    printf("-------------------------------------------\n");
    
    printf("RGM: ");
    fgets(rgm, sizeof(rgm), stdin);
    rgm[strcspn(rgm, "\n")] = '\0';    // remove \n
    printf("-------------------------------------------\n\n");

    printf("Verificando informacoes...\n\n");

    FILE *fp = fopen("alunosBrazCubaz.txt", "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    char linha[200];
    int encontrado = 0;
    while (fgets(linha, sizeof(linha), fp)) {
        char nomeArquivo[50], rgmArquivo[20];
        float A1, A2, Af;

        sscanf(linha, "%[^;];%[^;];%f;%f;%f", nomeArquivo, rgmArquivo, &A1, &A2, &Af);

        if (strncmp(nomeArquivo, "DELETADO_", 9) == 0) {
            continue;
        }

        // Compara s� o RGM
        if (strcmp(rgm, rgmArquivo) == 0) {
            encontrado = 1;
            strcpy(usuarioLogado, nomeArquivo);  // pega o nome do arquivo
            strcpy(rgmLogado, rgmArquivo);
            break;
        }
    }

    fclose(fp);

    if (encontrado) {
        printf("Acesso concedido! Bem-vindo de volta, %s.\n", usuarioLogado);
    } else {
        printf("Usuario nao encontrado ou esta marcado como deletado.\n");
        // Limpa as strings para indicar que n�o tem ningu�m logado
        usuarioLogado[0] = '\0';
        rgmLogado[0] = '\0';
    }

    printf("\n-------------------------------------------\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    system("cls");
}

