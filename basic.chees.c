#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef enum {
    KING,
    QUEEN,
    KOUL,
    SES,
    TOUK,
    TREY,
    TREYBORK
} Piece;

const char SYMBOL_P1[7][4] = { { "♚" }, { "♛" }, { "♝" }, { "♞" }, { "♜" }, { "♟" }, "♟+" };

typedef enum {
    P1 = 1,
    P2 = 2
} Player;

typedef enum {
    EMPTY,
    NOT_EMPTY
} State;

typedef struct {
    int board_id;
    State state;
    Player player;
    Piece piece;
} Board;

#define CLEAR_SCREEN system("clear")
#define COLOR_P1 "\033[31m"
#define COLOR_P2 "\033[32m"
#define RESET "\033[0m"

void init_player_piece(Board (*b)[8], Player player);
void set_piece(Board (*b)[8], int row, int col, Piece piece, Player player);
void display_board(Board (*b)[8]);

int main(int argc, char* argv[])
{
    Board(*new_game_board)[8] = malloc(sizeof(*new_game_board) * 8);
    Piece* piece;

    init_player_piece(new_game_board, P1);
    init_player_piece(new_game_board, P2);

    display_board(new_game_board);
    free(new_game_board);
    return EXIT_SUCCESS;
}

void init_player_piece(Board (*b)[8], Player player)
{
    bool def_player = player == P1;
    const short init_position_row = def_player ? 0 : 7;
    const short next_position_row = def_player ? 2 : 5;
    set_piece(b, init_position_row, 0, TOUK, player);
    set_piece(b, init_position_row, 1, SES, player);
    set_piece(b, init_position_row, 2, KOUL, player);
    set_piece(b, init_position_row, 3, def_player ? QUEEN : KING, player);
    set_piece(b, init_position_row, 4, def_player ? KING : QUEEN, player);
    set_piece(b, init_position_row, 5, KOUL, player);
    set_piece(b, init_position_row, 6, SES, player);
    set_piece(b, init_position_row, 7, TOUK, player);
    for (int i = 0; i < 8; i++) {
        set_piece(b, next_position_row, i, TREY, player);
    }
}

void set_piece(Board (*b)[8], int row, int col, Piece piece, Player player)
{
    b[row][col].state = NOT_EMPTY;
    b[row][col].piece = piece;
    b[row][col].player = player;
}

void display_board(Board (*b)[8])
{
    CLEAR_SCREEN;
    printf("    ");
    for (int i = 0, k = 65; i < 8; i++, k++) {
        printf(" %c ", k);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf(" %d |", i);
        for (int k = 0; k < 8; k++) {
            if (b[i][k].state == NOT_EMPTY) {
                if (b[i][k].player == P1) {
                    printf(COLOR_P1 " %s " RESET, SYMBOL_P1[b[i][k].piece]);
                } else {
                    printf(COLOR_P2 " %s " RESET, SYMBOL_P1[b[i][k].piece]);
                }
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}
