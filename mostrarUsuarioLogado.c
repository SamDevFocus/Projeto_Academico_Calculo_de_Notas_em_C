#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mostrarUsuarioLogado(const char *usuarioLogado, const char *rgmLogado) {
	setlocale(LC_ALL,"Portuguese_Brazil.1252");
	
    if (usuarioLogado[0] != '\0' && rgmLogado[0] != '\0') {
        printf("Usu�rio: %s (RGM: %s)\n\n", usuarioLogado, rgmLogado);
    } else {
        printf("Usu�rio: Deslogado\n\n");
    }
}
//oi
