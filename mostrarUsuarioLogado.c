#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mostrarUsuarioLogado(const char *usuarioLogado, const char *rgmLogado) {
	setlocale(LC_ALL,"Portuguese_Brazil.1252");
	
    if (usuarioLogado[0] != '\0' && rgmLogado[0] != '\0') {
        printf("Usuário: %s (RGM: %s)\n\n", usuarioLogado, rgmLogado);
    } else {
        printf("Usuário: Deslogado\n\n");
    }
}
//oi
