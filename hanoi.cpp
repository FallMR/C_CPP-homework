#include <iostream>
#include <cstdio>

using namespace std;

void mov(int n, char from, char to) {
    printf("move %d from %c to %c\n",n, from, to);
}

void hanoi(int n, char from, char depend, char to) {
    if (n == 1) {
        mov(1, from, to);
    } else {
        hanoi(n-1, from, to, depend);
        mov(n, from, to);
        hanoi(n-1, depend, from, to);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}