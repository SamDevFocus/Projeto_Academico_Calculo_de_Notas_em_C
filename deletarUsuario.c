#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void deletarUsuario()
{
    char rgmExcluir[20];
    char linha[100];
    int encontrado = 0;

    printf("=== Deletar Usuario ===\n");
    printf("Digite o RGM do usuario a ser deletado: ");
    fgets(rgmExcluir, sizeof(rgmExcluir), stdin);
    rgmExcluir[strcspn(rgmExcluir, "\n")] = '\0'; // remove \n

    FILE *orig = fopen("alunosBrazCubaz.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!orig || !temp)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), orig))
    {
        char nome[50], rgm[20];
        sscanf(linha, "%[^;];%[^;\n];", nome, rgm);

        if (strcmp(rgm, rgmExcluir) == 0 && strncmp(nome, "DELETADO_", 9) != 0)
        {
            fprintf(temp, "DELETADO_%s;%s\n", nome, rgm);
            encontrado = 1;
        }
        else
        {
            fputs(linha, temp); // copia a linha original
        }
    }

    fclose(orig);
    fclose(temp);

    remove("alunosBrazCubaz.txt");
    rename("temp.txt", "alunosBrazCubaz.txt");

    if (encontrado)
    {
        printf("Usuario com RGM %s foi marcado como DELETADO.\n", rgmExcluir);
        system("pause"); // no Windows
		system("cls");
    }
    else
    {
        printf("Usuario nao encontrado ou ja esta marcado como DELETADO.\n");
    }
}
