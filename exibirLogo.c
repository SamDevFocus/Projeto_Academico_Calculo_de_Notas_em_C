#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

//    configurarTerminal();
//	  system("cls");


void exibirLogo() {
    FILE *ler;
    ler = fopen("asciiart.txt", "r");

    if (ler == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        getchar(); 
        exit(1);   
    }

    char frase[100];

    while (fgets(frase, 100, ler) != NULL) {
        printf("%s", frase);
    }

    fclose(ler);
    printf("\n");
    
    getchar();
    system("cls"); 

}
