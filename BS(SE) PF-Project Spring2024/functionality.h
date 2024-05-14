/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR SPRING 2024 BS(SE)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
//---Piece Starts to Fall When Game Starts---//
#include<fstream>
#include <time.h>


/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
int &initial(int boardArray[][15]) {
   
    return boardArray[0][0];
}
bool checkGameOver() {
    for (int i = 0; i < 4; i++) {
        if (gridArray[boxSlelectionY[i]][boxSelectionX[i]] == 1) {
            return true; // Game over if any part of the falling piece overlaps with existing blocks
        }
    }
    return false;
}


bool leftMovePermission() {
    bool leftLayerCheck = true;

    for (int k = 0;k < 4;k++) {
        leftLayerCheck = true;
        for (int i = 0;i < 4;i++) {
            // if any box of shape is present in the next row then it makes layer false
            if (boxSelectionX[k] - 1 == boxSelectionX[i]) {
                leftLayerCheck = false;
            }

        }

        if (leftLayerCheck == false)
            continue;
        else if (boxSelectionX[k] == 0) {
            return false;//down position
        }
        else if (gridArray[boxSlelectionY[k]][boxSelectionX[k] - 1] == 1 || gridArray[boxSlelectionY[k]][boxSelectionX[k] - 1] == 9) { // bottom boundary
            return false;
        }

    }
    return true;
}

bool rightMovepermission()
{
    bool rightlayercheck = true;
    for (int i = 0;i < 4;i++)
    {
        rightlayercheck = true;
        for (int j = 0;j < 4;j++)
        {
            if (boxSelectionX[i] + 1 == boxSelectionX[j]) {
                rightlayercheck = false;
            }
        }
        if (rightlayercheck == false)
        {
            continue;
        }
        else if (boxSelectionX[i] == 14)
        {
            return false;
        }
        else if (gridArray[boxSlelectionY[i]][boxSelectionX[i] + 1] == 1 || gridArray[boxSlelectionY[i]][boxSelectionX[i] + 1] == 9)
        {
            return false;
        }
    }
    return true;
}
void removebox() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0;j < 4;j++) {
            gridArray[boxSlelectionY[i]][boxSelectionX[j]] = 0;
            colorOfGrid[boxSlelectionY[i]][boxSelectionX[j]] = 7;
        }
    }
}
bool checkPosition(int  arr[4]) {
    for (int k = 0;k < 4;k++) {
        // for last row
        if (arr[k] + 1 == 19) {
            return false;
            break;
        }
        bool boxOfShape = false;
        // downbox
        if (gridArray[arr[k] + 1][boxSelectionX[k]] == 1) {
            for (int j = 0;j < 4;j++) {
                if (((arr[k] + 1) == arr[j]) && (boxSelectionX[k] == boxSelectionX[j])) {
                    boxOfShape = true;
                    break;
                }
            }
            if (boxOfShape == false) {
                return false;
                break;
            }
        }

    }
    return true;
}

















///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
