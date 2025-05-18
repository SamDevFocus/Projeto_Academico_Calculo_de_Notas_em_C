#include <stdio.h>
#include <stdlib.h>
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
    printf("=== Lista de Usuários ===\n");
    while (fgets(linha, sizeof(linha), fp)) {
        char nome[50], rgm[20];
        sscanf(linha, "%[^;];%[^;];", nome, rgm);

        if (strncmp(nome, "DELETADO_", 9) != 0) {
            printf("Nome: %s | RGM: %s\n", nome, rgm);
        }
    }

    fclose(fp);
    
//    printf("\nPressione qualquer tecla para voltar ao menu...");
	system("pause"); // no Windows
	system("cls");
}
//oi
