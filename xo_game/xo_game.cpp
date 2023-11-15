#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <dos.h>
#include <cstdlib>
#include <unistd.h>
#define BOARD_ROW 22
#define BOARD_COLUMN 42
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define UP_KEY 72
#define DOWN_KEY 80
#define ENTER_KEY 13
#define ESC_KEY 27

using namespace std;


void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class Board {
    char** board;
    int ans[9];
    int posX;
    int posY;
    int currPlayer;
public:
    Board() {
        posX = 0;
        posY = 0;
        currPlayer = 1;
        board = new char*[BOARD_ROW];
        for (int i=0;i<BOARD_ROW;i++) {
            board[i] = new char[BOARD_COLUMN];
        }
        for (int i=0;i<9;i++) {
            ans[i] = -1;
        }
        for (int i=0;i<BOARD_ROW;i++) {
            for (int j=0;j<BOARD_COLUMN;j++) {
                if (i == 0 || j == 0 || i == BOARD_ROW-1 || j == BOARD_COLUMN-1 || i == 7 || i == 14 || j == 13 || j == 27){
                    board[i][j] = '*';
                }
                else board[i][j] = ' ';
            }
        }
    }
    void printBoard() {
        system("cls");
        for (int i=0;i<BOARD_ROW;i++) {
            for (int j=0;j<BOARD_COLUMN;j++) {
                cout<<board[i][j];
            }
            cout<<endl;
        }
        gotoxy(0, 25);
        cout<<"Current player: "<<currPlayer;
        gotoxy(0, 26);
        cout<<"Pos X: "<<posX;
        gotoxy(0, 27);
        cout<<"Pos Y: "<<posY;
        gotoxy(0, 28);
        for (int i=0;i<9;i++) {
            cout<<ans[i]<<"  ";
        }
    }
    void getInput() {
        gotoxy(posY*(BOARD_COLUMN/3) + 5, posX*(BOARD_ROW/3) + 3);
        char c = _getch();
        if (c == -32) {
            c = _getch();
        }
        switch(c) {
            case LEFT_KEY: {
                posY--;
                if (posY < 0) posY = 2;
                break;
            }
            case RIGHT_KEY: {
                posY++;
                if (posY > 2) posY = 0;
                break;
            }
            case UP_KEY: {
                posX--;
                if (posX < 0) posX = 2;
                break;
            }
            case DOWN_KEY: {
                posX++;
                if (posX > 2) posX = 0;
                break;
            }
            case ENTER_KEY: {
                if (ans[posX + (3*posY)] == -1) {
                    ans[posX + (3*posY)] = currPlayer;
                    switch(currPlayer) {
                        case 1:{
                            updateBoardX();
                            currPlayer++;
                            break;
                        }
                        case 2:{
                            updateBoardCircle();
                            currPlayer--;
                            break;
                        }
                        default:{
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    void updateBoardCircle() {
        int i ;
        int iRange = posX*(BOARD_ROW/3)+6;
        int j ;
        int jRange = (posY*(BOARD_COLUMN/3)+4)+5;

        for (i = posX*(BOARD_ROW/3)+2; i < iRange;i++) {
            for (j = posY*(BOARD_COLUMN/3)+4; j < jRange;j++) {
                if ( i == posX*(BOARD_ROW/3)+2 || j == posY*(BOARD_COLUMN/3)+4 || i == iRange-1 || j == jRange-1 ) {
                    board[i][j] = '*';
                }
            }
        }
    }
    void updateBoardX() {
        int i;//posX*(BOARD_ROW/3)+2
        int j;//posY*(BOARD_COLUMN/3)+4
        for (i = 0; i < 5;i++) {
            for (j = 0; j < 5;j++) {
                if ( i == j ) {
                    board[i+(posX*(BOARD_ROW/3)+2)][j+(posY*(BOARD_COLUMN/3)+4)] = '*';
                    board[(posX*(BOARD_ROW/3)+6)-i][j+(posY*(BOARD_COLUMN/3)+4)] = '*';
                }
            }
        }
    }
    int checkWin() {
        gotoxy(0, 29);
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
        if(ans[0] == ans[1] && ans[1] == ans[2] && ans[0] != -1) {
                cout<<"CASE 1";
            switch(ans[0]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        else if(ans[3] == ans[4] && ans[4] == ans[5] && ans[3] != -1) {
            cout<<"CASE 2";
            switch(ans[3]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        else if(ans[6] == ans[7] && ans[7] == ans[8] && ans[6] != -1) {
            cout<<"CASE 3";
            switch(ans[6]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        else if(ans[0] == ans[3] && ans[3] == ans[6] && ans[0] != -1) {
            cout<<"CASE 4";
            switch(ans[0]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        else if(ans[1] == ans[4] && ans[4] == ans[7] && ans[1] != -1) {
            cout<<"CASE 5";
            switch(ans[1]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        else if(ans[2] == ans[5] && ans[5] == ans[8] && ans[2] != -1) {
            cout<<"CASE 6";
            switch(ans[2]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        else if(ans[0] == ans[4] && ans[4] == ans[8] && ans[0] != -1) {
            switch(ans[0]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        else if(ans[2] == ans[4] && ans[4] == ans[6] && ans[2] != -1) {
            cout<<"CASE 7";
            switch(ans[2]) {
                case 1: system("cls");
                        cout<<"PLAYER 1 WINS!";
                        break;
                case 2: system("cls");
                        cout<<"PLAYER 2 WINS!";
                        break;
            }
            return 1;
        }
        return 0;
    }
    ~Board() {
        for (int i=0;i<BOARD_ROW;i++) {
            delete[] board[i];
        }
        delete[] board;
    }

};
void playBoard(Board board);

int main() {

    Board board;
    playBoard(board);
}

void playBoard(Board board) {
    while (true) {
        board.printBoard();
        board.getInput();
        if(board.checkWin()) {
            return;
        }
    }
}
