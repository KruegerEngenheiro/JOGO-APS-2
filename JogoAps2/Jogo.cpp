#include <iostream>
#include <cstdlib>
#include <ctime>

// Constantes para o tamanho do tabuleiro
const int ROWS = 5;
const int COLS = 5;

// Função para mostrar o menu
void showMenu() {
    std::cout << "---------------------------\n";
    std::cout << "1. Iniciar Jogo\n";
    std::cout << "2. Pausar Jogo\n";
    std::cout << "3. Reiniciar Jogo\n";
    std::cout << "4. Sair\n";
    std::cout << "---------------------------\n";
}

// Função para inicializar o tabuleiro com tesouros
void initializeBoard(char board[ROWS][COLS], int level) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = '.';
        }
    }
    int numTreasures = level * 2; // Aumenta o número de tesouros com o nível
    srand(time(0));
    for (int i = 0; i < numTreasures; ++i) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        board[row][col] = 'T';
    }
}

// Função para exibir o tabuleiro
void displayBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Função principal do jogo
void playGame() {
    char board[ROWS][COLS];
    int score = 0;
    int level = 1;
    int playerRow = 0;
    int playerCol = 0;

    initializeBoard(board, level);

    while (true) {
        displayBoard(board);
        std::cout << "Pontuação: " << score << " | Nível: " << level << std::endl;
        std::cout << "Movimentos: (w=up, s=down, a=left, d=right, q=quit): ";
        char move;
        std::cin >> move;

        if (move == 'q') {
            break;
        }

        switch (move) {
            case 'w': if (playerRow > 0) --playerRow; break;
            case 's': if (playerRow < ROWS - 1) ++playerRow; break;
            case 'a': if (playerCol > 0) --playerCol; break;
            case 'd': if (playerCol < COLS - 1) ++playerCol; break;
            default: std::cout << "Movimento inválido!\n";
        }

        if (board[playerRow][playerCol] == 'T') {
            std::cout << "Tesouro encontrado!\n";
            score += 10;
            board[playerRow][playerCol] = '.';
            if (score % 30 == 0) {
                ++level;
                std::cout << "Nível aumentado para " << level << "!\n";
                initializeBoard(board, level);
            }
        }
    }
}

// Função para pausar o jogo (placeholder, não faz nada neste exemplo)
void pauseGame() {
    std::cout << "Jogo pausado.\n";
}

// Função para reiniciar o jogo
void restartGame() {
    std::cout << "Jogo reiniciado.\n";
    playGame();
}

// Função principal
int main() {
    char choice;

    while (true) {
        showMenu();
        std::cout << "Escolha uma opção: ";
        std::cin >> choice;

        switch (choice) {
            case '1': playGame(); break;
            case '2': pauseGame(); break;
            case '3': restartGame(); break;
            case '4': std::cout << "Saindo do jogo.\n"; return 0;
            default: std::cout << "Opção inválida!\n";
        }
    }

    return 0;
}
