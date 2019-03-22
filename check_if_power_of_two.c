// #include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool is_power_of_two(int);

int main(int argc, const char** argv) {
  int num;
  for (int i=1; i<argc; ++i) {
    num = strtoll(argv[i], NULL, 10);
    // assert(is_power_of_two(num));
    if(!is_power_of_two(num)) {
      printf("Apparently not a power of two: %d\n", num);
    }
  }
  return 0;
}

bool is_power_of_two(int num) {
  // from: http://hg.openjdk.java.net/jdk8/jdk8/jdk/file/687fd7c7986d/src/share/classes/java/util/concurrent/ForkJoinPool.java:3278
  // return ((num & (num - 1)) != 0);  // this checks "if not power of two"!
  return ((num & (num - 1)) == 0);
}

