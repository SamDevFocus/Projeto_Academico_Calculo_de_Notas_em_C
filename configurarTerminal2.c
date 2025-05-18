#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void configurarTerminal2() {
    // Muda cor e t�tulo
    system("color 06"); // Fundo reto, texto azul claro
    system("title REPROVADOR 3000");

    // Define o modo com muitas colunas e linhas (zoom virtual)
    system("mode con: cols=180 lines=50"); // Aumenta o conte�do da janela

    // Maximiza a janela do console
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE); // Maximiza a janela

    // Define o tamanho da fonte para dar zoom visual
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 15; // Largura da fonte
    cfi.dwFontSize.Y = 25; // Altura da fonte (quanto maior, mais zoom)
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas"); // Fonte padr�o do terminal

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
//oi
