#include "MErr.h"
#include "common.h"

void F7(void);
void F8(void);

void F3(void) {
  fprintf(f1, "F3 started\n");
  F7();
  F8();
  Err();
  fprintf(f1, "F3 finished\n");
}
void F7(void) {
  fprintf(f1, "F7 started\n");

  fprintf(f1, "Cg3=%d\n", Cg3);

  Err();
  fprintf(f1, "F7 finished\n");
}
void F8(void) {
  fprintf(f1, "F8 started\n");
  fprintf(f1, "cnt=%d\n", cnt);
  if (cnt != 0) {
    cnt--;
    F3();
  }
  Err();
  fprintf(f1, "F8 finished\n");
}
