#include <cstdio>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct Point{
	int x, y;
}st, ed, cur;
Point destination[3] = {{8, 8}, {8, 7}, {8, 6}};
Point Boxes[3] = {{3, 3}, {5, 7}, {7, 3}};

static int Count = 0;

char Map[11][11] = {"##########",
					"#@   # # #",
					"#    #   #",
					"#  *     #",
					"#   ##   #",
					"#    # * #",
					"#    #   #",
					"#  * #####",
					"#     &&&#",
					"##########"};

inline bool Move(int deltax, int deltay);
inline void PrintScreen();
inline bool IsPlayerWin();

int main() {
	st.x = st.y = 1;
	ed.x = ed.y = 8;
	cur = st;
	PrintScreen();
	char dir = _getch();
	while(dir != 'q'){
		switch (dir) {
		case 'w':
			if (Move(-1, 0)) {
				printf("You win!\n");
				system("pause");
				return 0;
			}
			break;
		case 'a':
			if (Move(0, -1)) {
				printf("You win!\n");
				system("pause");
				return 0;
			}
			break;
		case 's':
			if (Move(1, 0)) {
				printf("You win!\n");
				system("pause");
				return 0;
			}
			break;
		case 'd':
			if (Move(0, 1))
				printf("You win!\n");
			break;
		}
		system("cls");
		PrintScreen();
		dir = _getch();
	}
	return 0;
}

inline bool Move(int deltax, int deltay) {
	Point old = cur;
	cur.x += deltax; cur.y += deltay;
	if (Map[cur.x][cur.y] != '*') {
		if (Map[cur.x][cur.y] == '#') {
			cur.x -= deltax; cur.y -= deltay;
		} else {
			Map[cur.x][cur.y] = '@';
			Map[old.x][old.y] = ' ';
			Count++;
		}
	} else {
		Point next = {cur.x + deltax, cur.y + deltay};
		if (Map[next.x][next.y] == '#' || Map[next.x][next.y] == '*') {
			cur.x -= deltax; cur.y -= deltay;
		} else {
			Map[cur.x][cur.y] = '@';
			Map[old.x][old.y] = ' ';
			Map[next.x][next.y] = '*';
			for (int k = 0; k < 3; k++) {
				if (Boxes[k].x == cur.x && Boxes[k].y == cur.y)
					Boxes[k] = next;
			}
			Count++;
		}
	}
	if (IsPlayerWin()) {
		return true;
	}
	return false;
}

inline void PrintScreen() {
	bool flag = false; 
	printf("Total steps:%d\n", Count);
    for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++){
			flag = false;
			for (int k = 0; k < 3; k++)
				if (i == destination[k].x && j == destination[k].y 
					&& Map[i][j] != '@' && Map[i][j] != '*') {
					printf("&");
					flag = true;
				}
			if (!flag) printf("%c", Map[i][j]);
		}
		printf("\n");
    }
    printf("Enter w, a, s, d as the four directions.\n");
    printf("Enter q as quit.\n");
}

inline bool IsPlayerWin() {
	int tot = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (Boxes[i].x == destination[j].x && Boxes[i].y == destination[j].y)
				tot++;
	if (tot == 3)
		return true;
	else
		return false;
}
