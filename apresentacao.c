#include <stdio.h>
#include <locale.h>

void apresentacao() {
	setlocale(LC_ALL,"Portuguese_Brazil.1252");
 	exibirLogo();

    printf("===========================================\n");
    printf("//////////     SOBRE O PROGRAMA     \\\\\\\\\\\\\\\\\\\n");
    printf("===========================================\n");
    printf("*-------------------------------------------*\n");
    printf("| Um sistema direto que calcula a m�dia     |\n");
    printf("| Informa se foram aprovados ou reprovados  |\n");
    printf("| Exibe as notas de todos os cadastrados    |\n");
    printf("| Facilita o acompanhamento da turma        |\n");
    printf("*-------------------------------------------*\n\n");

    printf("===========================================\n");
    printf("//////////    ACESSO AO SISTEMA     \\\\\\\\\\\\\\\\\\\n");
    printf("===========================================\n");
    printf("*-------------------------------------------*\n");
    printf("| Voc� j� tem uma conta no sistema?         |\n");
    printf("| S - Sim                                   |\n");
    printf("| N - N�o                                   |\n");
    printf("*-------------------------------------------*\n");
    printf("Digite sua escolha\n");
    printf(">>> ");
}
//oi
