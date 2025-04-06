#include <stdio.h>

int main() {
    float avaliacaoUm;
    float avaliacaoDois;
    float avaliacaoFinal;
    float menorNota;
    float soma;

    printf("Ola, bem-vindo ao calculador oficial de aprovacao da Universidade Braz Cubas\n");

    do{
    	printf("Por favor, insira sua nota na Avaliacao UM:\n");
    	scanf("%f", &avaliacaoUm);
    
    if (avaliacaoUm < 0 || avaliacaoUm > 5){
    	printf("Nota invalida! Digite um valor entre 0 e 5\n");
	}
    
	}while (avaliacaoUm < 0 || avaliacaoUm > 5);
	
	do {
		printf("Por favor, insira sua nota na Avaliacao DOIS:\n");
    	scanf("%f", &avaliacaoDois);
    	
    if (avaliacaoDois < 0 || avaliacaoDois > 5){
    	printf("Nota invalida! Digite um valor entre 0 e 5\n");
	}
	
	} while (avaliacaoDois < 0 || avaliacaoDois > 5);

    soma = avaliacaoUm + avaliacaoDois;

    if (soma >= 6.0) {
        printf("Aprovado com nota final de %.2f\n", soma);
    } else {
        printf("Voce nao alcancou a nota minima. Sua nota foi %.2f\n", soma);
        
        do {
            printf("Por favor, insira a nota da Avaliacao Final:\n");
            scanf("%f", &avaliacaoFinal);

            if (avaliacaoFinal < 0 || avaliacaoFinal > 5) {
                printf("Nota invalida! Digite um valor entre 0 e 5\n");
            }
        } while (avaliacaoFinal < 0 || avaliacaoFinal > 5);

        if (avaliacaoUm < avaliacaoDois) {
            menorNota = avaliacaoUm;
            if (avaliacaoFinal > menorNota) {
                avaliacaoUm = avaliacaoFinal;
            }
        } else {
            menorNota = avaliacaoDois;
            if (avaliacaoFinal > menorNota) {
                avaliacaoDois = avaliacaoFinal;
            }
        }

        soma = avaliacaoUm + avaliacaoDois;

        if (soma >= 6.0) {
		printf("Aprovado com uso da avaliacao final. Nota final: %.2f\n", soma);
        } else {
            printf("Reprovado com nota final de %.2f\n", soma);
        }
    }

    return 0;
}

