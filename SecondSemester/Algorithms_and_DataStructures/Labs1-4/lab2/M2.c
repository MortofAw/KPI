#include "M1.h"
#include "MErr.h"
#include "common.h"

void F4(void) {
  fprintf(f1, "F4 started\n");
  Err();
  fprintf(f1, "F4 finished\n");
}
void F5(void) {
  fprintf(f1, "F5 started\n");

  fprintf(f1, "Cg2=%d\n", Cg2);

  Err();
  fprintf(f1, "F5 finished\n");
}
void F6(void) {
  fprintf(f1, "F6 started\n");

  fprintf(f1, "cnt=%d\n", cnt);
  if (cnt != 0) {
    cnt--;
    F2();
  }

  Err();
  fprintf(f1, "F6 finished\n");
}
