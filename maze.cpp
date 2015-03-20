#include <cstdio>
#include <cstdlib>
#include <queue>
#include <conio.h>

using namespace std;

struct Point{
	int x, y;
}st, ed, cur;

static int Count;

char Map[11][11] = {"##########",
					"#@  #   ##",
					"### # # ##",
					"###   # ##",
					"####### ##",
					"#       ##",
					"# ### ####",
					"# ###   ##",
					"#     #E##",
					"##########"};

bool Move(int deltax, int deltay);
void PrintScreen();

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

bool Move(int deltax, int deltay) {
	Point old = cur;
	cur.x += deltax; cur.y += deltay;
	if (Map[cur.x][cur.y] == 'E') {
		Count++;
		return true;
	} else if (Map[cur.x][cur.y] == '#') {
		cur.x -= deltax; cur.y -= deltay;
	} else {
		Map[cur.x][cur.y] = '@';
		Map[old.x][old.y] = ' ';
		Count++;
	}
	return false;
}

void PrintScreen() {
	printf("Total steps:%d\n", Count);
    for (int i = 0; i < 10; i++)
        printf("%s\n", Map[i]);
    printf("Enter w, a, s, d as the four directions.\n");
    printf("Enter q as quit.\n");
}
