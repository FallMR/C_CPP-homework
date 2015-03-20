#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Point{
    int x, y;
}st, ed, Cur;

int Move(char Direct);
void PrintScreen();

char Map[11][11] = {"##########",
                    "#@  #    #",
                    "## ## ## #",
                    "##    ## #",
                    "## ##### #",
                    "## ###   #",
                    "## ##  ###",
                    "####  ####",
                    "#####   E#",
                    "##########"};

int main() {
    char Dir;
    st.x = 1;
    st.y = 1;
    ed.x = 8;
    ed.y = 8;
    Cur = st;
    PrintScreen();
    scanf("%c", &Dir);
    while (Dir != 'q') {
        int flag = Move(Dir);
        if (flag == 1) {
            system("pause");
            return 0;
        } else if (flag == 2) {
            system("pause");
        }
        system("cls");
        PrintScreen();
        scanf("%c", &Dir);
    }
    return 0;
}

int Move(char Direction) {
    Point Old = Cur;
    switch (Direction) {
    case 'w':
        Cur.x--;
        if (Map[Cur.x][Cur.y] == 'E') {
            printf("You win!\n");
            return 1;
        } else if (Map[Cur.x][Cur.y] == '#') {
            printf("Wrong operation!\n");
            Cur.x++;
            return 2;
        } else {
            Map[Cur.x][Cur.y] = '@';
            Map[Old.x][Old.y] = ' ';
        }
        break;
    case 'a':
        Cur.y--;
        if (Map[Cur.x][Cur.y] == 'E') {
            printf("You win!\n");
            return 1;
        } else if (Map[Cur.x][Cur.y] == '#') {
            printf("Wrong operation!\n");
            Cur.y++;
            return 2;
        } else {
            Map[Cur.x][Cur.y] = '@';
            Map[Old.x][Old.y] = ' ';
        }
        break;
    case 's':
        Cur.x++;
        if (Map[Cur.x][Cur.y] == 'E') {
            printf("You win!\n");
            return 1;
        } else if (Map[Cur.x][Cur.y] == '#') {
            printf("Wrong operation!\n");
            Cur.x--;
            return 2;
        } else {
            Map[Cur.x][Cur.y] = '@';
            Map[Old.x][Old.y] = ' ';
        }
        break;
    case 'd':
        Cur.y++;
        if (Map[Cur.x][Cur.y] == 'E') {
            printf("You win!\n");
            return 1;
        } else if (Map[Cur.x][Cur.y] == '#') {
            printf("Wrong operation!\n");
            Cur.y--;
            return 2;
        } else {
            Map[Cur.x][Cur.y] = '@';
            Map[Old.x][Old.y] = ' ';
        }
        break;
    }
    return 3;
}

void PrintScreen() {
    for (int i = 0; i < 10; i++)
        printf("%s\n", Map[i]);
    printf("Enter w, a, s, d as the controll of directions.\n");
    printf("Enter q as quit.\n");
}
