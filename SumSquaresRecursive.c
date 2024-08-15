#include <stdio.h>
#include <stdlib.h>

int SumSquares(int m,int n) {
    if (m < n) {
        printf("Added %d to the sum\n", m*m);
        return m*m + SumSquares(m+1, n);
    }
    else {
        printf("Added %d to the sum\n", m*m);
        return m*m;
    }
}

int SumSquaresDown(int m, int n) {
    if (m < n) {
        printf("Added %d to the sum\n", n*n);
        return SumSquaresDown(m, n-1) + n*n;
    }
    else {
        printf("Added %d to the sum\n", n*n);
        return n*n;
    }
}

int main(int argc, char** argv) {
    int res = SumSquares(1,9);
    printf("Upwards SumSquares: %d\n", res);
    res = SumSquaresDown(1,9);
    printf("Downwards SumSquares: %d\n", res);
}
