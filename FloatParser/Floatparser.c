#include <stdbool.h>

typedef struct {
  bool value_exists;
  double value;
} maybe_double ;

maybe_double parse_float(const char *input) {
// If the input is a valid string representation of a double,
  
// store it in `value` and set `value_exists` to `true`
// Otherwise, set `value_exists` to `false`, and the content of `value` is irrelevant
  
  
    return (maybe_double) { .value_exists = true, .value = 0.0 / 0.0 };
}