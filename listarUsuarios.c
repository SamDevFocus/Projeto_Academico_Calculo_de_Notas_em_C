#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void listarUsuarios() {
    setlocale(LC_ALL,"Portuguese_Brazil.1252");
    system("cls");

    FILE *fp = fopen("alunosBrazCubaz.txt", "r");

    if (!fp) {
        printf("Erro ao abrir o arquivo de alunos.\n");
        return;
    }

    char linha[200];

    printf("=============== LISTA DE USUÁRIOS ===============\n\n");

    while (fgets(linha, sizeof(linha), fp)) {
        char *nome, *rgm, *n1, *n2, *nf;
        float nota1 = 0, nota2 = 0, notaFinal = 0;

        // Remove \n no final se existir
        linha[strcspn(linha, "\n")] = 0;

        // Divide a linha
        nome = strtok(linha, ";");
        rgm  = strtok(NULL, ";");
        n1   = strtok(NULL, ";");
        n2   = strtok(NULL, ";");
        nf   = strtok(NULL, ";");

        if (nome && rgm && n1 && n2 && nf) {
            // Converte strings para float
            nota1 = strtof(n1, NULL);
            nota2 = strtof(n2, NULL);
            notaFinal = strtof(nf, NULL);

            if (strncmp(nome, "DELETADO_", 9) != 0) {
                printf("Nome: %-20s | RGM: %-11s | Nota1: %.1f | Nota2: %.1f | Final: %.1f\n",
                       nome, rgm, nota1, nota2, notaFinal);
            }
        } else if (nome && rgm) {
            if (strncmp(nome, "DELETADO_", 9) != 0) {
                printf("Nome: %-20s | RGM: %-11s | (Sem notas)\n", nome, rgm);
            }
        } else {
            printf("Linha inválida (não exibida): %s\n", linha);
        }
    }

    fclose(fp);

    printf("\n");
    system("pause");
    system("cls");
}

