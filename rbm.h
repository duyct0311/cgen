/*
  (C) 2021 Nguyen Ba Ngoc (bangoc)
*/

#ifndef RBM_H_
#define RBM_H_

#include "base/rb.h"
#include "base/gtype.h"

typedef struct rbm_node {
  struct rb_node_s rb_node;
  gtype key, value;
} *rbm_node_t;

typedef struct rbm_s {
  struct bn_tree t;
  gtype_cmp_t cmp;
  gtype_free_t free_key, free_value;
} *rbm_t;

typedef struct rbm_insert_result {
  rbm_node_t nd;
  int inserted;
} rbm_ires;

#define to_rbm(n) ((rbm_node_t)n)
#define rbm_node_key(n) (to_rbm(n)->key)
#define rbm_node_value(n) (to_rbm(n)->value)

rbm_node_t rbm_create_node(gtype key, gtype value);
rbm_t rbm_create(gtype_cmp_t cmp,
  gtype_free_t free_key, gtype_free_t free_value);

rbm_ires rbm_insert(rbm_t t, gtype key, gtype value);
gtype *rbm_vref(rbm_t t, gtype key);
rbm_node_t rbm_search(rbm_t t, gtype key);
int rbm_remove(rbm_t t, gtype key);

#define rbm_free(m) \
  do { \
    bn_free_tree((bn_tree_t)m); \
  } while (0)

#define rbm_traverse(cur, tm) \
  for (rbm_node_t cur = to_rbm(bn_left_most(tm->t.root)); \
       cur != NULL_PTR; cur = to_rbm(bn_next_inorder(to_bn(cur))))


#endif  // RBM_H_
