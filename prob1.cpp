#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 1000

int Rank(int N, int K);
int a[MAX] = { 0 };

int main() {
    int N, K = 0;
    char s[MAX], * tok;

    scanf("%d", &N);                            //�Է�
    getchar();
    gets_s(s, MAX);
    int i = 0;
    while (i < N) {
        if (i == 0) {
            tok = strtok(s, " ");
        }
        else {
            tok = strtok(NULL, " ");
        }
        sscanf(tok, "%d", &a[i]);
        i++;
    }

    scanf("%d", &K);

    int ans = Rank(N, K);
    printf("%d", ans);

    return 0;
}

int Rank(int N, int K) {                        //a[N-1]���� a[0]���� N�� ���ϴ� �Լ�
    if (N < 0) {
        return 0;
    }
    else {
        if (K > a[N - 1]) {                     //K�� a[N-1]���� ū ��츸 return ���� +1
            return 1 + Rank(N - 1, K);
        }
        else
            return Rank(N - 1, K);
    }
}
