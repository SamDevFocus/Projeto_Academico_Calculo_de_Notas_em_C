#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alterarNotas() {
    char rgmBusca[20];
    float A1, A2, Af, soma;
    int encontrado = 0;

    printf("Digite o RGM do aluno para alterar as notas: ");
    fgets(rgmBusca, sizeof(rgmBusca), stdin);
    rgmBusca[strcspn(rgmBusca, "\n")] = '\0';

    FILE *orig = fopen("alunosBrazCubaz.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!orig || !temp) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char linha[200];
    while (fgets(linha, sizeof(linha), orig)) {
        char nome[50], rgm[20];
        float nota1, nota2, notaFinal;

        sscanf(linha, "%[^;];%[^;];%f;%f;%f", nome, rgm, &nota1, &nota2, &notaFinal);

        // Ignora usuários deletados
        if (strncmp(nome, "DELETADO_", 9) == 0) {
            fputs(linha, temp);
            continue;
        }

        if (strcmp(rgm, rgmBusca) == 0) {
            encontrado = 1;

            // Solicita e valida a nota da Avaliação A1
            do {
                printf("Insira a nova nota da Avaliacao A1 (0 a 5): ");
                scanf("%f", &A1);
                if (A1 < 0 || A1 > 5) {
                    printf("Nota invalida. Tente novamente.\n");
                }
            } while (A1 < 0 || A1 > 5);

            // Solicita e valida a nota da Avaliação A2
            do {
                printf("Insira a nova nota da Avaliacao A2 (0 a 5): ");
                scanf("%f", &A2);
                if (A2 < 0 || A2 > 5) {
                    printf("Nota invalida. Tente novamente.\n");
                }
            } while (A2 < 0 || A2 > 5);

            soma = A1 + A2;

            if (soma >= 6) {
                Af = 0;
                printf("Nota: %.2f - Aluno aprovado.\n", soma);
            } else {
                printf("Nota: %.2f - Sera necessario realizar a Avaliacao final (AF).\n", soma);

                do {
                    printf("Insira a nota da Avaliacao final (0 a 5): ");
                    scanf("%f", &Af);
                    if (Af < 0 || Af > 5) {
                        printf("Nota invalida. Tente novamente.\n");
                    }
                } while (Af < 0 || Af > 5);

                if (A1 < A2) A1 = Af;
                else A2 = Af;

                soma = A1 + A2;

                if (soma >= 6) {
                    printf("Nova nota: %.2f - Aluno aprovado apos AF.\n", soma);
                } else {
                    printf("Nova nota: %.2f - Aluno reprovado.\n", soma);
                }
            }

            // Salva a nova linha atualizada
            fprintf(temp, "%s;%s;%.2f;%.2f;%.2f\n", nome, rgm, A1, A2, Af);
        } else {
            fputs(linha, temp); // mantém a linha original
        }
    }

    fclose(orig);
    fclose(temp);

    remove("alunosBrazCubaz.txt");
    rename("temp.txt", "alunosBrazCubaz.txt");

    if (!encontrado) {
        printf("Aluno com RGM %s nao encontrado.\n", rgmBusca);
    }
}
