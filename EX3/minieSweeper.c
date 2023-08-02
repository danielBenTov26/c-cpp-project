//
// Created by danielBentov on 01/12/2022.
//
#include "minieSweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


bool initBoard (GameBoard * g, int rows, int cols, int level);	//returns true upon success
void clickTile (GameBoard * g, int row, int col);
void flagTile (GameBoard * g, int row, int col);
void populateMines (GameBoard * g, int level);
void markNumbers (GameBoard * g);
void printBoard (GameBoard * g, int cursorCoords[2]);



bool
initBoard (GameBoard * g, int rows, int cols, int level)
{
    g->rows = rows;
    g->cols = cols;
    g->hiddenTiles = rows*cols;
    g->board = (Tile**)malloc(rows*sizeof (Tile*));
    if (g->board == NULL)
        return FALSE;
    for (int i = 0; i < rows; ++i)
    {
        g->board[i] = (Tile *)malloc(cols * sizeof (Tile));
        if (g->board[i] == NULL)
            return FALSE;
    }
    for (int i = 0; i < g->rows; i++)
    {
        for (int j = 0; j < g->cols; j++)
        {
            g->board[i][j].numOfMines = 0;
            g->board[i][j].isMine=FALSE;
        }

    }


    populateMines (g, level);
    markNumbers (g);
    return TRUE;
}

void
populateMines (GameBoard * g, int level)
{
    srand (time (0));
    int numMines;
    int rows = g->rows;
    int cols = g->cols;

    if (level == EASY)
        numMines = ((rows * cols) * EASY_LEVEL_PERCENT) / 100;

    if (level == MEDIUM)
        numMines = ((rows * cols) * MEDIUM_LEVEL_PERCENT) / 100;
    if (level == HARD)
        numMines = ((rows * cols) * HARD_LEVEL_PERCENT) / 100;


    for (int k = 0; k < numMines;)
    {
        int i = rand () % rows;
        int j = rand () % cols;
        if (g->board[i][j].isMine == FALSE)
        {
            g->board[i][j].isMine = TRUE;
            g->board[i][j].numOfMines = -1;
            k++;
        }
    }
}

void markNumbers (GameBoard * g)
{
    int rows = g->rows;
    int cols = g->cols;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (g->board[i][j].isMine)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                    if (g->board[i - 1][j - 1].isMine == FALSE)	//i-1,j-1
                    {
                        g->board[i - 1][j - 1].numOfMines++;
                    }

                if (i - 1 >= 0)
                    if (g->board[i - 1][j].isMine == FALSE)	//i-1,j
                    {
                        g->board[i - 1][j].numOfMines++;
                    }
                if (i - 1 >= 0 && j + 1 < cols)
                    if (g->board[i - 1][j + 1].isMine == FALSE)	//i-1,j+1
                    {
                        g->board[i - 1][j + 1].numOfMines++;
                    }
                if (j - 1 >= 0)
                    if (g->board[i][j - 1].isMine == FALSE)	//i,j-1
                    {
                        g->board[i][j - 1].numOfMines++;
                    }
                if (j + 1 < cols)
                    if (g->board[i][j + 1].isMine == FALSE)	//i,j+1
                    {
                        g->board[i][j + 1].numOfMines++;
                    }
                if (i + 1 < rows && j - 1 >= 0)
                    if (g->board[i + 1][j - 1].isMine == FALSE)	//i+1,j-1
                    {
                        g->board[i + 1][j - 1].numOfMines++;
                    }
                if (i + 1 < rows)
                    if (g->board[i + 1][j].isMine == FALSE)	//i+1,j
                    {
                        g->board[i + 1][j].numOfMines++;
                    }

                if (i + 1 < rows && j + 1 < cols)
                    if (g->board[i + 1][j + 1].isMine == FALSE)	//i+1,j+1
                    {
                        g->board[i + 1][j + 1].numOfMines++;
                    }

            }

        }

    }
}

void
clickTile (GameBoard * g, int row, int col)
{
    int rows = g->rows;
    int cols = g->cols;
    if (g->board[row][col].isVisible)
        return;
    else if (g->board[row][col].isFlagged)
        return;
    else
    {
        if (g->board[row][col].isMine)
        {
            g->isMineClicked;
            return;
        }
        else if (g->board[row][col].numOfMines > 0)
        {
            g->board[row][col].isVisible = TRUE;
            return;
        }
        else
        {
            int i = row, j = col;
            if (i - 1 >= 0 && j - 1 >= 0)
                clickTile (g, i - 1, j - 1);
            if (i - 1 >= 0)
                clickTile (g, i - 1, j);

            if (i - 1 >= 0 && j + 1 < cols)
                clickTile (g, i - 1, j + 1);

            if (j - 1 >= 0)
                clickTile (g, i, j - 1);

            if (j + 1 < cols)
                clickTile (g, i, j + 1);

            if (i + 1 < rows && j - 1 >= 0)
                clickTile (g, i + 1, j - 1);

            if (i + 1 < rows)

                clickTile (g, i + 1, j);

            if (i + 1 < rows && j + 1 < cols)
                clickTile (g, i + 1, j + 1);



        }
    }

}

void
flagTile (GameBoard * g, int row, int col)
{
    if (g->board[row][col].isVisible)
        return;

    else if (g->board[row][col].isFlagged)
    {
        g->board[row][col].isFlagged = FALSE;
    }
    else
        g->board[row][col].isFlagged = TRUE;

}

void
printBoard (GameBoard * g, int cursorCoords[2])
{
    for (int i = 0; i < g->rows; ++i)
    {
        for (int j = 0; j < g->cols; ++j)
        {

            // if (g->board[i][j].isVisible)
            if(g->board[i][j].isMine == TRUE)
                printf ("%d ", g->board[i][j].numOfMines);
            else
            printf (" %d ", g->board[i][j].numOfMines);
            // else printf(" v ");



        }
        printf ("\n");
    }
}
