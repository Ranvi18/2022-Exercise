#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define WAY 0
#define WALL 1
#define BOMB 2
#define VISTED_WAY 3
#define BOMB_WAY 4

bool FindPath(int x, int y);
int N, K = 0;
int a[MAX][MAX] = { 0 };

int main() {
    char s[MAX], * tok;

    scanf("%d", &N);                        //�Է�
    getchar();
    int j = 0;
    while (j < N) {
        gets_s(s, MAX);
        int i = 0;
        while (i < N) {
            if (i == 0) {
                tok = strtok(s, " ");
            }
            else {
                tok = strtok(NULL, " ");
            }
            sscanf(tok, "%d", &a[j][i]);
            i++;
        }
        j++;
    }
    scanf("%d", &K);                        

    if (FindPath(0, 0) == true)
        printf("Yes");
    else
        printf("No");
    
    return 0;
}

bool FindPath(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N || a[x][y] == WALL || a[x][y] == VISTED_WAY || a[x][y] == BOMB_WAY || K < 0)         //��ΰ� ���� ���
        return false;
    else if (x == N - 1 && y == N - 1) {                                                                                        //����
        a[x][y] = VISTED_WAY;
        return true;
    }
    else {
        if (a[x][y] == BOMB) {              //��λ� ��ź�� ���� ���
            K--;
            a[x][y] = BOMB_WAY;
        }
        else
            a[x][y] = VISTED_WAY;           //�׳� ���� ���

        if (FindPath(x - 1, y) || FindPath(x, y + 1) || FindPath(x + 1, y) || FindPath(x, y - 1))
            return true;                  

        if (a[x][y] == BOMB_WAY) {          //�ʱ�ȭ
            K++;
            a[x][y] = BOMB;
        }
        else if (a[x][y] == VISTED_WAY)     //�ʱ�ȭ
            a[x][y] = WAY;
        return false;
    }
}

