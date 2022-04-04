#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 1000

int Rank(int N, int K);
int a[MAX] = { 0 };

int main() {
    int N, K = 0;
    char s[MAX], * tok;

    scanf("%d", &N);                            //입력
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

int Rank(int N, int K) {                        //a[N-1]부터 a[0]까지 N번 비교하는 함수
    if (N < 0) {
        return 0;
    }
    else {
        if (K > a[N - 1]) {                     //K가 a[N-1]보다 큰 경우만 return 값에 +1
            return 1 + Rank(N - 1, K);
        }
        else
            return Rank(N - 1, K);
    }
}
