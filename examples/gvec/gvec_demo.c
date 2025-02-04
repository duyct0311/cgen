/*
  (C) Nguyen Ba Ngoc 2021
*/

#include "gvec.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  gvec_t v = gvec_create(10, NULL);
  srand(time(NULL));
  for (int i = 0; i < 10; ++i) {
    gvec_append(v, gtype_l(rand() % 100));
  }
  printf("Before sort: ");
  gvec_traverse(g, v) {
    printf(" %ld", g->l);
  }
  printf("\n");
  gvec_qsort(v, gtype_qsort_l);
  printf("After sort: ");
  gvec_traverse(g, v) {
    printf(" %ld", g->l);
  }
  printf("\n");
  gvec_free(v);
  return 0;
}