#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma string contém apenas dígitos

int apenasNumeros(const char *str) {
	
		system("cls");
	
    int i;
    for (i = 0; str[i]; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0; // falso
        }
    }
    return 1; // verdadeiro
}

// Função principal
void criarConta() {
    char nome[50];
    char rgm[20];
    
    system("cls");
    
    printf("===========================================\n");
    printf("           REPROVADOR 3000\n");
    printf("===========================================\n\n");
    printf("[ CRIACAO DE CONTA]\n");
    printf("VAMOS CRIAR A SUA CONTA PARA COMECAR.\n\n");
    printf("-------------------------------------------\n\n");

    // Lê o nome e valida se está vazio
    while (1) {
        printf("DIGITE SEU NOME: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; // remove \n

        if (strlen(nome) == 0) {
            printf("Nome nao pode estar vazio.\n");
        } else {
            break;
        }
    }

    // Lê o RGM e valida se contém apenas números
    while (1) {
        printf("DIGITE SEU RGM: ","\n");
        fgets(rgm, sizeof(rgm), stdin);
        rgm[strcspn(rgm, "\n")] = '\0';

        if (strlen(rgm) == 0) {
            printf("RGM nao pode estar vazio.\n");
        } else if (!apenasNumeros(rgm)) {
            printf("RGM deve conter apenas numeros.\n");
        } else {
            break;
        }
    }

    FILE *fp = fopen("alunosBrazCubaz.txt", "a+");
    if (!fp)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    rewind(fp);

    char linha[200];
    while (fgets(linha, sizeof(linha), fp))
    {
        char nomeArq[50], rgmArq[20];
        sscanf(linha, "%[^;];%[^;];", nomeArq, rgmArq);

        if (strncmp(nomeArq, "DELETADO_", 9) == 0)
        {
            continue;
        }

        if (strcmp(rgm, rgmArq) == 0)
        {
		printf("===========================================\n");
		printf("           REPROVADOR 3000\n");
		printf("===========================================\n\n");

		printf("[ CRIACAO DE CONTA ]\n");
		printf("O RGM informado ja esta cadastrado no sistema.\n");
		printf("Por favor, utilize um RGM diferente para criar a conta.\n");
		printf("\n-------------------------------------------\n");
		getchar();
        fclose(fp);
        return;
        }
    }

    // Salva com notas 0
    fprintf(fp, "%s;%s;%d;%d;%d\n", nome, rgm, 0, 0, 0);
    fclose(fp);

	system("cls");

    printf("Conta criada\n");
}
//oi
