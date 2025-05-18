#ifndef LOGIN_H
#define LOGIN_H

void mostrarUsuarioLogado(const char *usuarioLogado, const char *rgmLogado); 

void apresentacao();

void listarUsuarios();

void calcularMedia();

void alterarNotas();

// Cria uma nova conta (salvando nome, RGM e notas zeradas)
void criarConta();

// Faz login validando nome e RGM
void fazerLogin(char *usuarioLogado, char *rgmLogado);

// Marca o usuário como deletado
void deletarUsuario();

// void listarAlunos();
// void exibirNotasUsuario(const char *rgm);

#endif

