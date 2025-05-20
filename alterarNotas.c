#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int alterarNotas() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    char rgmBusca[20];
    float A1 = 0, A2 = 0, Af = 0, soma = 0;
    int encontrado = 0, sucesso = 0;
    char entrada[20];

    printf("Digite o RGM do aluno para alterar as notas: ");
    fgets(rgmBusca, sizeof(rgmBusca), stdin);
    rgmBusca[strcspn(rgmBusca, "\n")] = '\0'; // Remove o '\n' do final

    FILE *orig = fopen("alunosBrazCubaz.txt", "r");
    if (!orig) {
        printf("Erro ao abrir o arquivo de leitura.\n");
        return 0;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        fclose(orig);
        printf("Erro ao criar o arquivo temporário.\n");
        return 0;
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

            // Solicita e valida A1
            do {
                printf("Insira a nova nota da Avaliação A1 (0 a 5): ");
                fgets(entrada, sizeof(entrada), stdin);
                sucesso = sscanf(entrada, "%f", &A1);
                if (sucesso != 1 || A1 < 0 || A1 > 5) {
                    printf("Nota inválida. Tente novamente.\n");
                }
            } while (sucesso != 1 || A1 < 0 || A1 > 5);

            // Solicita e valida A2
            do {
                printf("Insira a nova nota da Avaliação A2 (0 a 5): ");
                fgets(entrada, sizeof(entrada), stdin);
                sucesso = sscanf(entrada, "%f", &A2);
                if (sucesso != 1 || A2 < 0 || A2 > 5) {
                    printf("Nota inválida. Tente novamente.\n");
                }
            } while (sucesso != 1 || A2 < 0 || A2 > 5);

            soma = A1 + A2;

            if (soma >= 6) {
                Af = 0;
                printf("Nota: %.2f - Aluno aprovado.\n", soma);
            } else {
                printf("Nota: %.2f - Será necessário realizar a Avaliação Final (AF).\n", soma);

                // Solicita e valida AF
                do {
                    printf("Insira a nota da Avaliação Final (0 a 5): ");
                    fgets(entrada, sizeof(entrada), stdin);
                    sucesso = sscanf(entrada, "%f", &Af);
                    if (sucesso != 1 || Af < 0 || Af > 5) {
                        printf("Nota inválida. Tente novamente.\n");
                    }
                } while (sucesso != 1 || Af < 0 || Af > 5);

                // Substitui a menor nota por AF
                printf("Substituindo a menor nota pela AF...\n");
                if (A1 < A2) A1 = Af;
                else A2 = Af;

                soma = A1 + A2;

                if (soma >= 6) {
                    printf("Nova nota: %.2f - Aluno aprovado após AF.\n", soma);
                } else {
                    printf("Nova nota: %.2f - Aluno reprovado.\n", soma);
                }
            }

            // Reescreve linha atualizada
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
        printf("Aluno com RGM %s não encontrado.\n", rgmBusca);
        return 0;
    }

    return 1;
}

