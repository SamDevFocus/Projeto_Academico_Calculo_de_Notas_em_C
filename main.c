#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>  // para toupper()
#include "login.h"

int main()
{
   setlocale(LC_ALL,"Portuguese_Brazil.1252");
   configurarTerminal();
    char usuarioLogado[50] = "";
    char rgmLogado[20] = "";
    int opcao;
    char resposta;

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
        printf("Opcao inválida! Encerrando o programa.\n");
        return 1;
    }

    do
    {
    	exibirLogo();
    	
        system("cls");

        printf("===========================================\n");
        printf("//////////     BRAZ CUBAS     \\\\\\\\\\\\\\\\\\\n");
        printf("===========================================\n\n");

        mostrarUsuarioLogado(usuarioLogado, rgmLogado);

        printf(">>>>>>>>>>>>>>  MENU PRINCIPAL  <<<<<<<<<<<<<<\n");
        printf("*-------------------------------------------*\n");
        printf("| 1  Criar conta                            |\n");
        printf("| 2  Listar usuários                        |\n");
        printf("| 3  Deletar usuario                        |\n");
        printf("| 4  Fazer login                            |\n");
        printf("| 5  Calcular média                         |\n");
        printf("| 6  Altarar nota                           |\n");
        printf("| 7  Sair                                   |\n");
        printf("*-------------------------------------------*\n");
        printf("Digite o número da opção desejada\n");
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
                printf("Usuário logado: %s (RGM: %s)\n", usuarioLogado, rgmLogado);
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
            alterarNotas();
            break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }

        system("pause");

    } while (opcao != 6);

    return 0;
}
//oi

