#include <stdio.h>
#include <locale.h>

void apresentacao() {
	setlocale(LC_ALL,"Portuguese_Brazil.1252");
 	exibirLogo();

    printf("===========================================\n");
    printf("//////////     SOBRE O PROGRAMA     \\\\\\\\\\\\\\\\\\\n");
    printf("===========================================\n");
    printf("*-------------------------------------------*\n");
    printf("| Um sistema direto que calcula a média     |\n");
    printf("| Informa se foram aprovados ou reprovados  |\n");
    printf("| Exibe as notas de todos os cadastrados    |\n");
    printf("| Facilita o acompanhamento da turma        |\n");
    printf("*-------------------------------------------*\n\n");

    printf("===========================================\n");
    printf("//////////    ACESSO AO SISTEMA     \\\\\\\\\\\\\\\\\\\n");
    printf("===========================================\n");
    printf("*-------------------------------------------*\n");
    printf("| Você já tem uma conta no sistema?         |\n");
    printf("| S - Sim                                   |\n");
    printf("| N - Não                                   |\n");
    printf("*-------------------------------------------*\n");
    printf("Digite sua escolha\n");
    printf(">>> ");
}
//oi
