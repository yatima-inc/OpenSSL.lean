#include <lean/lean.h>

/**
 * Unwrap an Option of a lean_object* as data for some
 * or NULL (0) for none. Unsafe.
 */
static inline lean_object *lean_option_unwrap(b_lean_obj_arg a) {
  if (lean_is_scalar(a)) {
    return 0;
  } else {
    lean_object *some_val = lean_ctor_get(a, 0);
    return some_val;      
  }
}

inline static void foreach_noop(void *mod, b_lean_obj_arg fn) {}

/**
 * Option.some a
 */
static inline lean_object * lean_mk_option_some(lean_object * a) {
  lean_object* tuple = lean_alloc_ctor(1, 1, 0);
  lean_ctor_set(tuple, 0, a);
  return tuple;
}

/**
 * Option.none.
 * Note that this is the same value for Unit and other constant constructors of inductives.
 */
static inline lean_object * lean_mk_option_none() {
  return lean_box(0);
}

static inline lean_object * lean_mk_tuple2(lean_object * a, lean_object * b) {
  lean_object* tuple = lean_alloc_ctor(0, 2, 0);
  lean_ctor_set(tuple, 0, a);
  lean_ctor_set(tuple, 1, b);
  return tuple;
}
