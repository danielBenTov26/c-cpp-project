//
// Created by danielBentov on 01/12/2022.
//

#ifndef EX3_MINIESWEEPER_H
#define EX3_MINIESWEEPER_H



#define MAX_BOARD_DIM 		20

#define EASY_LEVEL_PERCENT		12
#define MEDIUM_LEVEL_PERCENT	16
#define HARD_LEVEL_PERCENT		21

enum
{ 	EASY = 1,
    MEDIUM,
    HARD };

typedef enum
{ 	FALSE,
    TRUE
}bool;
typedef enum
{	 	FLAG_TILE  	= '  ',
    CLICK_TILE 	= '\n',
    QUIT		= 'q',
    LEFT		= 'a',
    RIGHT		= 'd',
    UP		= 'w',
    DOWN		= 's'
} Command;

typedef struct
{
    bool isVisible, isMine, isFlagged;
    int numOfMines;
} Tile;

typedef struct
{
    Tile **board;
    int rows, cols, totalMines, hiddenTiles;
    bool isMineClicked;
} GameBoard;





bool initBoard(GameBoard *g, int rows, int cols, int level); //returns true upon success
void clickTile(GameBoard *g, int row, int col);
void flagTile(GameBoard *g, int row, int col);
void populateMines(GameBoard *g, int level);
void markNumbers(GameBoard *g);
void printBoard(GameBoard *g, int cursorCoords[2]);

#endif //EX3_MINIESWEEPER_H
