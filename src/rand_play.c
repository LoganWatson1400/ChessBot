#include "header.h"

/*
 * CAN USE
 * ChessBoard.ChessBoardNew
 * ChessBoard.ChessBoardToFEN
 * ChessBoard.ChessBoardPlayMove 
 * ChessBoard.ChessBoardPrintBoard
 * ChessBoard.ChessBoardPrintMove
 * ChessBoard.ChessBoardChecking
 * ChessBoard.ChessBoardPinned
 * ChessBoard.ChessBoardAttacked
 * ChessBoard.ChessBoardFlip
 * LookupTable.LookupTableNew
 * LookupTable.LookupTableFree
 * LookupTable.LookupTableAttacks
 * LookupTable.LookupTableSquaresBetween
 * LookupTable.LookupTableLineOfSight
 * MoveSet...
 * BitBoard...
 */
 
int main(void)
{
    srand((unsigned)time(NULL));

    char *start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    ChessBoard cb = ChessBoardNew(start_fen);
    LookupTable lookup = LookupTableNew();

    int move_count = 0;
    const int max_moves = 10000;

    // Print initial board first time
    ChessBoardPrintBoard(cb);

    while (move_count < max_moves)
    {
        // Move cursor up before re-printing board to overwrite old board
        printf("\033[10A");  // Adjust 10 to your actual board height

        // Print the board
        ChessBoardPrintBoard(cb);

        MoveSet moves = MoveSetNew();
        MoveSetFill(lookup, &cb, &moves);

        if (MoveSetIsEmpty(&moves))
        {
            printf("No legal moves available. Game over.\n");
            break;
        }

        int num_moves = MoveSetCount(&moves);
        int choice = rand() % num_moves;

        Move selected_move;
        for (int i = 0; i <= choice; i++)
            selected_move = MoveSetPop(&moves);

        // Move cursor up 1 line to overwrite previous move (optional)
        printf("\033[1A");

        printf("Move %d: ", move_count + 1);
        ChessBoardPrintMove(selected_move);
        printf("\n");

        cb = ChessBoardPlayMove(&cb, selected_move);

        move_count++;
    }

    // Print final board and FEN without moving cursor up
    //ChessBoardPrintBoard(cb);
    char *final_fen = ChessBoardToFEN(&cb);
    printf("Final FEN: %s\n", final_fen);

    LookupTableFree(lookup);

    return 0;
}

