#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void deletarUsuario() {
	setlocale(LC_ALL,"Portuguese_Brazil.1252");
    char rgmExcluir[20];
    char linha[100];
    int encontrado = 0;
    

    system("cls"); // limpa a tela no Windows

    printf("===========================================\n");
    printf("//////////     DELETAR USU�RIO     \\\\\\\\\\\\\\\\\\\n");
    printf("===========================================\n");
    printf("*-------------------------------------------*\n");
    printf("| Digite o RGM do usu�rio a ser deletado:   |\n");
    printf("*-------------------------------------------*\n");
    printf(">>> ");
    fgets(rgmExcluir, sizeof(rgmExcluir), stdin);
    rgmExcluir[strcspn(rgmExcluir, "\n")] = '\0'; // remove \n

    FILE *orig = fopen("alunosBrazCubaz.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!orig || !temp)
    {
        printf("\n[ERRO] N�o foi poss�vel abrir os arquivos.\n");
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

    printf("\n===========================================\n");
    if (encontrado)
    {
        printf("[SUCESSO] Usu�rio com RGM %s foi marcado como DELETADO.\n", rgmExcluir);
    }
    else
    {
        printf("[AVISO] Usu�rio n�o encontrado ou j� est� marcado como DELETADO.\n");
    }
    printf("===========================================\n");
    system("pause"); 
}
//oi

