#include "common.h"

const int Cg1 = 1;
const int Cg2 = 2;
const int Cg3 = 3;

int Vg1;
int Vg2;
int Vg3;
int Vg4;
int Vg5;

int cnt;

FILE *f1;

void common_init(void) {
  Vg1 = 1;
  Vg2 = 2;
  Vg3 = 3;
  Vg4 = 4;
  Vg5 = 5;

  f1 = fopen("log.txt", "w");
  fprintf(f1, "common_init started and finished\n");
}
