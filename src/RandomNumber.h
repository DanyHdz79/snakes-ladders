#include <stdlib.h>
#include <time.h>


class RandomNumber {
private:
  int low, limit;

public:
  RandomNumber() : low(1), limit(6) {}

  RandomNumber(int nLow, int nLimit) {
    low = nLow;
    limit = nLimit;
  }

  int generateRN() {
    return rand() % limit + low;
  }
};

//bitdegree.org/learn/random-number-generator-cpp
