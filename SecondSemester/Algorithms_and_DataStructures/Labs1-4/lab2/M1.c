#include "M2.h"
#include "MErr.h"
#include "common.h"

void F1(void) {
  fprintf(f1, "F1 started\n");
  F4();

  Tg1 value1 = 10;

  fprintf(f1, "Cg1=%d\n", Cg1);
  fprintf(f1, "Tg1=%d\n", value1);

  F5();
  Err();
  fprintf(f1, "F1 finished\n");
}

void F2(void) {
  fprintf(f1, "F2 started\n");
  F5();
  F6();
  Err();
  fprintf(f1, "F2 finished\n");
}
