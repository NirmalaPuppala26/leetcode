#include <stdbool.h>
#include <math.h>

bool isPowerOfTwo(int n) {
    for (int x = 0; x < 31; x++) {
        if (n == pow(2, x)) {
            return true;
        }
    }
    return false;
}
