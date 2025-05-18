#include <stdio.h>
#include <stdlib.h>

void calcularMedia() {
    float A1, A2, Af, soma;

    // Solicita e valida a nota da Avaliação A1
    do {
        printf("Insira a nota da Avaliacao A1 (0 a 5): ");
        scanf("%f", &A1);
        if (A1 < 0 || A1 > 5) {
            printf("Nota invalida. Tente novamente.\n");
        }
    } while (A1 < 0 || A1 > 5);

    // Solicita e valida a nota da Avaliação A2
    do {
        printf("Insira a nota da Avaliacao A2 (0 a 5): ");
        scanf("%f", &A2);
        if (A2 < 0 || A2 > 5) {
            printf("Nota invalida. Tente novamente.\n");
        }
    } while (A2 < 0 || A2 > 5);

    soma = A1 + A2;

    if (soma >= 6) {
        printf("Nota: %.2f - Aluno aprovado.\n", soma);
    } else {
        printf("Nota: %.2f - Nota inferior a 6. Sera necessario realizar a avaliacao final.\n", soma);

        // Solicita e valida a nota da avaliacao final
        do {
            printf("Insira a nota da Avalaliação final (0 a 5): ");
            scanf("%f", &Af);
            if (Af < 0 || Af > 5) {
                printf("Nota invalida. Tente novamente.\n");
            }
        } while (Af < 0 || Af > 5);

      
        if (A1 < A2) { // substituição das notas (se a nota1 for menor que nota2, logo nota 1 é a menor nota
            A1 = Af;   // se nota 1 e a menor então ela e igual a Af (substituição)
        } else {
            A2 = Af;
        }

        // Recalcula a soma
        soma = A1 + A2;

        // Resultado final
        if (soma >= 6) {
            printf("Nova nota: %.2f - Aluno aprovado apos Avaliacao final.\n", soma);
        } else {
            printf("Nova nota: %.2f - Aluno reprovado.\n", soma);
        }
        
    
    }
    
    return 0;
}
//oi
