#include <stdio.h>

struct Counter {
  int value;
};

void increment(struct Counter* counter, int amount) {
  counter->value += amount;
}

int main() {
  struct Counter counter;
  counter.value = 0;

  increment(&counter, 10);
  increment(&counter, 20);

  printf("Counter value: %d\n", counter.value);  // Outputs "Counter value: 30"

  return 0;
}
/*create a struct that holds an integer variable that is added up continuously 
within other functions  in C language*/