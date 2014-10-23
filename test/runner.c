#ifndef __TEST_RUNNER_C__
#define __TEST_RUNNER_C__

#include "linked_list_test.c"
// is_test("one equals one") {
//   is_true(1 == 1, "1 did not equal 1!");
// }


int main (int argc, char const *argv[]) {
  run_linked_list_tests();
  return 0;
}


#endif
