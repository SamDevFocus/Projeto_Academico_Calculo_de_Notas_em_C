#include <stdio.h>
#include <windows.h>
#define linhas_apresentacao 10
void apresentacao() {
	
    // Obtém o tamanho do console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int alturaConsole = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calcula a posição inicial para centralizar verticalmente
	int i;
    int linhasAntes = (alturaConsole - linhas_apresentacao) / 2;
    for (i = 0; i < linhasAntes; i++) {
        printf("\n");
    }
	
    printf("===========================================\n");
//	exibirLogo();
    printf("===========================================\n\n");

    printf("*************** SOBRE O PROGRAMA ***************\n");
    printf(" Um sistema direto que calcula a media dos alunos\n");
    printf(" Informa se foram aprovados ou reprovados\n");
    printf(" Exibe as notas de todos os cadastrados\n");
    printf(" Facilita o acompanhamento da turma\n");
    printf("***********************************************\n\n");

    printf("************** ACESSO AO SISTEMA **************\n");
    printf(" Voce ja tem uma conta no sistema\n");
    printf(" S - Sim\n");
    printf(" N - Nao\n");
    printf("***********************************************\n");
    printf("Digite sua escolha\n");
    printf(">>> ");
}
