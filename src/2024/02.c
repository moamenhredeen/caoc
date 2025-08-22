#include "2024.h"
#include <stdlib.h>


typedef enum {false, true}          bool_t;
typedef enum { asc, desc, none }    direction_t;

int solve_2024_02_a(int *restrict reports, int *restrict reports_lengths,
                    int reports_count) {
    bool_t is_safe;
  direction_t d;
  int safe_reports = 0;
  int offset = 0;
  for (int i = 0; i < reports_count; i++) {
    is_safe = true;
    d = none;
    for (int j = 0; j < reports_lengths[i] - 1; j++) {
        if (abs(reports[offset + j] - reports[offset + j + 1]) > 3){
            is_safe = false;
            break;
        }
      if (reports[offset + j] > reports[offset + j + 1]) {
        if (d == none) {
          d = desc;
        } else if (d == asc) {
            is_safe = false;
          break;
        }
      } else if (reports[offset + j] < reports[offset + j + 1]) {
        if (d == none) {
          d = asc;
        } else if (d == asc) {
            is_safe = false;
          break;
        }
      }
    }
    
    if (is_safe == true)  safe_reports++;
    offset += reports_lengths[i];
  }
  return safe_reports;
}