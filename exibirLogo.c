#include <stdio.h>
#include <windows.h>

// Conta quantas linhas tem a logo
#define LINHAS_LOGO 8

void exibirLogo() {
    int i;
	configurarTerminal();
    // Obtém o tamanho do console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int alturaConsole = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calcula a posição inicial para centralizar verticalmente
    int linhasAntes = (alturaConsole - LINHAS_LOGO) / 2;
	int repeticao;
    for (repeticao = 0; repeticao < 2; repeticao++) {
        system("cls");

        for (i = 0; i < linhasAntes; i++) {
            printf("\n");
        }

        // Exibe a logo linha por linha com pausa
        printf("8888888b.  8888888888 8888888b.  8888888b.   .d88888b.  888     888 8888888b.         d8888 8888888b.   .d88888b.  8888888b.        .d8888b.   .d8888b.   .d8888b.   .d8888b.  \n");
        Sleep(100);
        printf("888   Y88b 888        888   Y88b 888   Y88b d88P\" \"Y88b 888     888 888   Y88b       d88888 888  \"Y88b d88P\" \"Y88b 888   Y88b      d88P  Y88b d88P  Y88b d88P  Y88b d88P  Y88b \n");
        Sleep(100);
        printf("888    888 888        888    888 888    888 888     888 888     888 888    888      d88P888 888    888 888     888 888    888           .d88P 888    888 888    888 888    888 \n");
        Sleep(100);
        printf("888   d88P 8888888    888   d88P 888   d88P 888     888 Y88b   d88P 888   d88P     d88P 888 888    888 888     888 888   d88P          8888\"  888    888 888    888 888    888 \n");
        Sleep(100);
        printf("8888888P\"  888        8888888P\"  8888888P\"  888     888  Y88b d88P  8888888P\"     d88P  888 888    888 888     888 8888888P\"            \"Y8b. 888    888 888    888 888    888 \n");
        Sleep(100);
        printf("888 T88b   888        888        888 T88b   888     888   Y88o88P   888 T88b     d88P   888 888    888 888     888 888 T88b        888    888 888    888 888    888 888    888 \n");
        Sleep(100);
        printf("888  T88b  888        888        888  T88b  Y88b. .d88P    Y888P    888  T88b   d8888888888 888  .d88P Y88b. .d88P 888  T88b       Y88b  d88P Y88b  d88P Y88b  d88P Y88b  d88P \n");
        Sleep(100);
        printf("888   T88b 8888888888 888        888   T88b  \"Y88888P\"      Y8P     888   T88b d88P     888 8888888P\"   \"Y88888P\"  888   T88b       \"Y8888P\"   \"Y8888P\"   \"Y8888P\"   \"Y8888P\"  \n");

        Sleep(1000); // espera 1 segundo com a logo visível
    }

    system("cls"); // limpa ao final
    return 0;
}

