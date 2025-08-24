#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


bool gameOver;
const int with = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = with / 2;
    y = height / 2;
    fruitX = rand() % with;
    fruitY = rand() % height;
    score = 0;

}

void Draw () {
    system("cls");

    for (int i = 0; i < with; i++){
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++){
        for (int j = 0; j < with; j++){
            if (j == 0 || j == with - 1) {
                cout << "#";
            }else if (i == y && j == x) {
                cout << "0";
            }else if (i == fruitY && j == fruitX) {
                cout << "X";
            } else {
                cout << " ";
            }

        }
        cout << endl;
    }

    for (int i = 0; i < with; i++){
        cout << "#";
    }
    cout << endl;
    cout << endl;

    for (int i = 0; i < with; i++){
           cout << "-";
    }
    cout << endl;
    cout << "Score: " << score << endl;
    for (int i = 0; i < with; i++){
           cout << "-";
    }
}

void Input() {
    if (_kbhit()){
        switch (_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'f':
            gameOver = true;
            // Draw();
            break;
        }
    
    }
}


void logic() {
    switch (dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }
    if (x >= with - 1 || x <= 0 || y >= height || y < 0) {
        gameOver = true;
    }
    if (x == fruitX && y == fruitY) {
        score += 100;
        fruitX = rand() % (with - 3);
        fruitY = rand() % (height - 3);
    }
}

int main () {
    Setup();
    Draw();
    while(!gameOver) {
        Draw();
        Input();
        logic();

        Sleep(100);

        // if (score < 5) {
        //     Sleep(100);
        // } else if (score > 6 && score < 10) {
        //     Sleep(70);
        // }else if (score > 11) {
        //     Sleep(40);
        // }
    }
    return 0;
}