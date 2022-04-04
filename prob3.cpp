#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define WAY 0
#define WALL 1
#define VISTED_WAY 2

int FindPath(int x, int y, int dir, int c);
int N = 0;
int a[MAX][MAX] = { 0 };
int Handle = 0;                                     //���� ��ȯ�� �������� ���θ� üũ(1 or 0)

int main() {
    char s[MAX], * tok;                             //�Է�

    scanf("%d", &N);
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
    
    int R = FindPath(0, 0, 1, 0);                   //�������� ���
    int D = FindPath(0, 0, 2, 0);                   //�ϴ����� ���
    int ans;

    if (R < D)
        ans = R;
    else
        ans = D;

    if (ans == MAX) {
        printf("No path");
    }
    else
        printf("%d", ans);

    return 0;
}

/*MAX�� �����Ⱚ���� ����*/
int FindPath(int x, int y, int dir, int c) {
    if (x < 0 || y < 0 || x >= N || y >= N || a[x][y] == WALL) {        //���� �ε����� ���(���� ��ȯ�� ������)
        Handle = 1;
        return MAX;
    }
    else if (a[x][y] == VISTED_WAY)                                     //���ʿ� �� �̻� ���̾��� ����(���� ��ȯ �Ұ�)
        return MAX;
    else if (x == N - 1 && y == N - 1) {                                //����
        c++;
        return c;
    }
    else {
        a[x][y] = VISTED_WAY;

        if (dir == 1) {                                                 //����
            int tmp = FindPath(x, y + 1, 1, c);
            if (tmp != MAX) {
                a[x][y] = WAY;
                return tmp;
            }
        }
        else if (dir == 2) {
            int tmp = FindPath(x + 1, y, 2, c);
            if (tmp != MAX) {
                a[x][y] = WAY;
                return tmp;
            }
        }
        else if (dir == 3) {
            int tmp = FindPath(x, y - 1, 3, c);
            if (tmp != MAX) {
                a[x][y] = WAY;
                return tmp;
            }
        }
        else if (dir == 4) {
            int tmp = FindPath(x - 1, y, 4, c);
            if (tmp != MAX) {
                a[x][y] = WAY;
                return tmp;
            }
        }

        int min_c = MAX;                                                //������ȯ(c�� 1����)
        if (Handle == 1) {
            int tmp = FindPath(x, y + 1, 1, c + 1);
            if (tmp < min_c)
                min_c = tmp;
            tmp = FindPath(x + 1, y, 2, c + 1);
            if (tmp < min_c)
                min_c = tmp;
            tmp = FindPath(x, y - 1, 3, c + 1);
            if (tmp < min_c)
                min_c = tmp;
            tmp = FindPath(x - 1, y, 4, c + 1);
            if (tmp < min_c)
                min_c = tmp;
        }

        a[x][y] = WAY;                                                  //�ʱ�ȭ
        Handle = 0;

        return min_c;
    }
}

