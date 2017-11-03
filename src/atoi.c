#include <math.h>
#include <stdio.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int isNumber(char C) {
    return '0' <= C && C <= '9';
}
int charToNumber(char C) {
    return isNumber(C) ? C - '0' : -1;
}
int matoi(const char *S) {
    int I, N, i, n1, n, m, p;

    n1 = 0;
    while(S[n1] && S[n1] == ' ') n1++;
    n = n1;
    while(S[n] && (isNumber(S[n]) || S[n] == '-' || S[n] == '+')) n++;

    if (!S[n1]) return 0;
    m = S[n1] == '-' ? 1 : 0;
    p = S[n1] == '+' ? 1 : 0;

    i = n1 + m + p;
    I = 0;
    while(S[i] && i<n) {
        N = charToNumber(S[i]);
        if (N == -1) return 0;
        int T = N*pow(10, n-i-1);
        if (T == MAX_INT || T == MIN_INT) return m ? MIN_INT : MAX_INT;
        I += N*pow(10, n-i-1);
        i++;
    }

    return m ? -1*I : I;
}

int main() {
    printf("%d\n", matoi("-88297 248252140B12 37239U4622733246I218 9 1303 44 A83793H3G2 1674443R591 4368 7 97"));
}
