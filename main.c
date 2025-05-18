#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // para toupper()
#include "login.h"

int main()
{
    char usuarioLogado[50] = "";
    char rgmLogado[20] = "";
    int opcao;
    char resposta;

    exibirLogo();
    system("cls");

    apresentacao();
    scanf(" %c", &resposta);
    getchar(); // limpar o \n

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
        printf("Opcao invalida! Encerrando o programa.\n");
        return 1;
    }

    do
    {
    	exibirLogo();
    	configurarTerminal2();
        system("cls");

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
        printf("Digite o numero da opcao desejada\n");
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
            if (usuarioLogado[0] != '\0')
            {
                printf("Usuario logado: %s (RGM: %s)\n", usuarioLogado, rgmLogado);
            }
            else
            {
                printf("Falha no login.\n");
            }
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

        system("pause");

    } while (opcao != 6);

    return 0;
}
//oi

