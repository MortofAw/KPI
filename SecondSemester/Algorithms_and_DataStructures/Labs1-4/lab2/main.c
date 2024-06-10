#include "M1.h"
#include "M3.h"
#include "common.h"

int main(void) {
  common_init();

  fprintf(f1, "main started\n");
  Vg1 = 0;

  fprintf(f1, "Vg1=%d\n", Vg1);
  fprintf(f1, "Vg2=%d\n", Vg2);
  fprintf(f1, "Vg3=%d\n", Vg3);
  fprintf(f1, "Vg4=%d\n", Vg4);
  fprintf(f1, "Vg5=%d\n", Vg5);

  F1();
  cnt = 3;
  F2();
  cnt = 3;
  F3();

  fprintf(f1, "main finished\n");
  return 0;
}
