#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fibR(int n, int *knownFib) {
    if (knownFib[n]) return knownFib[n];
    if (!knownFib[n-1]) fibR(n-1, knownFib);
    if (!knownFib[n-2]) fibR(n-2, knownFib);
    knownFib[n] = knownFib[n-1] + knownFib[n-2];
    return knownFib[n];
}

int fib(int n) {
    assert(n > 0);
    int *knownFib = calloc(n+1, sizeof(int));
    assert(knownFib != NULL);
    knownFib[1] = 1;
    knownFib[2] = 1;
    int f = fibR(n, knownFib);
    free(knownFib);
    return f;
}
