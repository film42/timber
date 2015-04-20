#include <stdio.h>
#include <avl_tree.h>
#include <string.h>
#include <stdio.h>
#include "min_unit.h"

int tests_run = 0;

static void running_test(char * test_name) {
  printf("Running test: %s\n", test_name);
}

static char * avl_insert_tests() {
  avl_tree_t * tree  = avl_init();

  mu_assert( "Count is 0", avl_count(tree) == 0 );

  avl_insert(tree, "Hello!");
  mu_assert( "Count is 1", avl_count(tree) == 1 );
  mu_assert( "Contains 'Hello!'", avl_contains(tree, "Hello!") );

  avl_insert(tree, "Hello!");
  mu_assert( "Count is still 1", avl_count(tree) == 1 );

  avl_insert(tree, "Play!");
  mu_assert( "Count is 2", avl_count(tree) == 2 );
  mu_assert( "Contains 'Play!'", avl_contains(tree, "Play!") );

  avl_insert(tree, "Mark");
  avl_insert(tree, "fun");
  avl_insert(tree, "hannah");
  avl_insert(tree, "garrett");

  mu_assert( "Count is 6", avl_count(tree) == 6 );

  avl_deinit(tree);

  return 0;
}

static char * avl_contains_tests() {
  avl_tree_t * tree  = avl_init();
  avl_insert(tree, "Hello!");
  avl_insert(tree, "3");
  avl_insert(tree, "4");
  avl_insert(tree, "5");

  mu_assert( "Contains 'Hello!'", avl_contains(tree, "Hello!") );
  mu_assert( "Contains '3'", avl_contains(tree, "3") );
  mu_assert( "Contains '4'", avl_contains(tree, "4") );
  mu_assert( "Contains '5'", avl_contains(tree, "5") );
  mu_assert( "Doesn't contain 'Hllo'", !avl_contains(tree, "Hllo") );
  mu_assert( "Doesn't contain '7'", !avl_contains(tree, "7") );

  avl_deinit(tree);

  return 0;
}

static char * avl_delete_tests() {
  avl_tree_t * tree  = avl_init();
  avl_insert(tree, "1");
  avl_insert(tree, "2");
  avl_insert(tree, "3");
  avl_insert(tree, "4");
  avl_insert(tree, "5");

  mu_assert( "Contains '3'", avl_contains(tree, "3") );
  avl_print(tree);
  avl_delete(tree, "3");
  printf("------------\n");
  avl_print(tree);
  mu_assert( "Value '3' was removed", !avl_contains(tree, "3") );

  avl_deinit(tree);
  return 0;
}

static char * avl_all_tests() {
  running_test("Insert Tests");
  mu_run_test(avl_insert_tests);
  running_test("Contains Tests");
  mu_run_test(avl_contains_tests);
  //running_test("Delete Tests");
  //mu_run_test(avl_delete_tests);
  return 0;
}

int main(int argc, char ** argv) {
  /* Run tests */
  char * result = avl_all_tests();
  if (result != 0) {
     printf("TEST FAILED: %s\n", result);
  }
  else {
     printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
