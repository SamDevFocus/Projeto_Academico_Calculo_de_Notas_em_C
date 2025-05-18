#include <stdio.h>
#include <stdlib.h>
#include "login.h"

int main() {
    char usuarioLogado[50] = "";
    char rgmLogado[20] = "";
    int opcao;
    char resposta;
    configurarTerminal();

    // Tela de apresentação
    
    exibirLogo();
    getchar();
    system("cls");
    apresentacao();
    scanf(" %c", &resposta);
    getchar(); // limpar o \n

    resposta = toupper(resposta);

    if (resposta == 'S') {
        fazerLogin(usuarioLogado, rgmLogado);
    } else if (resposta == 'N') {
        criarConta();
        fazerLogin(usuarioLogado, rgmLogado);
    } else {
        printf("Opcao invalida! Encerrando o programa.\n");
        return 1;
    }
    
    do {
    	printf("===========================================\n");
    	printf("           REPROVADOR 3000\n");
    	printf("===========================================\n\n");
    	
    	mostrarUsuarioLogado(usuarioLogado, rgmLogado);
    	
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Criar conta\n");
        printf("2. Listar usuarios\n");
        printf("3. Deletar usuario\n");
        printf("4. Fazer login\n");
        printf("5. Calcular Media\n");
        printf("6. Alterar Nota\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o \n do buffer

        switch(opcao) {
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
                if (usuarioLogado[0] != '\0') {
                    printf("Usuario logado: %s (RGM: %s)\n", usuarioLogado, rgmLogado);
                } else {
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
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

