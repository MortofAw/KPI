#include <stdio.h>
#include <stdlib.h>
#define m 3
#define n 3

int main() {
  int A[m][n];

  int val = 1, i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      A[m - 1 - i][n - 1 - j] = val;
      val++;
    }
  }
  // A[0][0] = 8;
  // A[1][0] = 5;
  // A[2][0] = 2;
  // A[2][1] = 2;
  // A[2][2] = -4;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  for (int x = 0; x <= 5; x++) {
    int L = 0, R = m - 1;
    while (L <= R) { // col
      i = L + (R - L) / 2;

      if (x == A[i][0]) {
        break;
      } else {
        if (x > A[i][0])
          R = i - 1;
        else
          L = i + 1;
      }
    }
    if (L <= R) {
      printf("%d exists at the col pos: [%d][%d] ", x, i, 0);
    } else {
      printf("%d doesnt exist at col ", x);
    }

    L = 0, R = n - 1;
    while (L <= R) { // row
      i = L + (R - L) / 2;

      if (x == A[m - 1][i]) { // зустрівся з проблемою зміни половни в меншу
        break;
      } else {
        if (x > A[m - 1][i])
          R = i - 1;
        else
          L = i + 1;
      }
    }
    if (L <= R) {
      printf("%d exists at the row pos: [%d][%d]", x, m - 1, i);
    } else {
      printf("%d doesnt exist at row", x);
    }

    printf("\n");
  }
}
