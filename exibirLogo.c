#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


int contarLinhasArquivo(const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }
    int linhas = 0;
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), fp)) {
        linhas++;
    }
    fclose(fp);
    return linhas;
}

void exibirLogo() {
    const char *nomeArquivo = "asciiart.txt";

    configurarTerminal();

    int linhasLogo = contarLinhasArquivo(nomeArquivo);
    if (linhasLogo == 0) {
        printf("Arquivo vazio ou nao encontrado.\n");
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int alturaConsole = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int linhasAntes = (alturaConsole - linhasLogo) / 2;
    if (linhasAntes < 0) linhasAntes = 0;
	int repeticao;
    for (repeticao = 0; repeticao < 2; repeticao++) {
        system("cls");
		int i;
        for (i = 0; i < linhasAntes; i++) {
            printf("\n");
        }

        FILE *fp = fopen(nomeArquivo, "r");
        if (!fp) {
            printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
            return;
        }

        char linha[512];
        while (fgets(linha, sizeof(linha), fp)) {
            printf("%s", linha);
        }
        fclose(fp);

        Sleep(1000);
    }

    system("cls");
}

