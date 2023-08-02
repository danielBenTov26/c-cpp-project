#include <stdio.h>
#include "minieSweeper.h"
int main() {


    GameBoard a;
    initBoard(&a,5,5,1);
    int d[2] = {1,2};
    printBoard(&a,d);

    // printf("plaese enter numbers of rows end colls: ")


    return 0;
}
