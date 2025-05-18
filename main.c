#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "login.h"

int main() {
	configurarTerminal();
    char usuarioLogado[50] = "";
    char rgmLogado[20] = "";
    int opcao;
    char resposta;

    // Repetir apresenta��o at� o usu�rio digitar uma resposta v�lida
    do
    {
        system("cls"); // ou system("clear"); para Linux
        apresentacao();
        scanf(" %c", &resposta);
        getchar(); // limpa \n do buffer

        resposta = toupper(resposta);

        if (resposta == 'S')
        {
            fazerLogin(usuarioLogado, rgmLogado);
        }
        else if (resposta == 'N')
        {
            criarConta();
            fazerLogin(usuarioLogado, rgmLogado);
        }
        else
        {
            printf("\nOpcao invalida! Pressione ENTER para tentar novamente...\n");
            getchar(); // Espera ENTER
        }

    } while (resposta != 'S' && resposta != 'N');

    // Menu principal
    do
    {
        system("cls"); // ou system("clear") no Linux

        printf("===========================================\n");
        printf("//////////     REPROVADOR 3000     \\\\\\\\\\\\\\\\\\\n");
        printf("===========================================\n\n");

        mostrarUsuarioLogado(usuarioLogado, rgmLogado);

        printf(">>>>>>>>>>>>>>  MENU PRINCIPAL  <<<<<<<<<<<<<<\n");
        printf("*-------------------------------------------*\n");
        printf("| 1  Criar conta                            |\n");
        printf("| 2  Listar usuarios                        |\n");
        printf("| 3  Deletar usuario                        |\n");
        printf("| 4  Fazer login                            |\n");
        printf("| 5  Calcular media                         |\n");
        printf("| 6  Sair                                   |\n");
        printf("*-------------------------------------------*\n");
        printf("Digite o numero da opcao desejada           \n");
        printf(">>> ");
        scanf("%d", &opcao);
        getchar(); // limpa o \n do buffer

        switch (opcao)
        {
        case 1:
            criarConta();
            break;
        case 2:
            listarUsuarios();
            break;
        case 3:
            deletarUsuario();
            break;
        case 4:
            fazerLogin(usuarioLogado, rgmLogado);
            break;
        case 5:
            calcularMedia();
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

        if (opcao != 6)
        {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcao != 6);

    return 0;
}
