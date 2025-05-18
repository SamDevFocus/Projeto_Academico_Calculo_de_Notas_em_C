#include <stdio.h>
#include <stdlib.h>

void mostrarUsuarioLogado(const char *usuarioLogado, const char *rgmLogado) {
    if (usuarioLogado[0] != '\0' && rgmLogado[0] != '\0') {
        printf("Usuario: %s (RGM: %s)\n\n", usuarioLogado, rgmLogado);
    } else {
        printf("Usuario: Deslogado\n\n");
    }
}
//oi
