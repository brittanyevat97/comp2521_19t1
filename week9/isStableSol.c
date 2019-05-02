#include <stdio.h>
#include <stdlib.h>

typedef struct { int a; int b; } Item;

// function that takes the original array, the sorted array,
// and returns 1 if the sort was stable, 0 otherwise

int isStableSort(Item original[], Item sorted[], int lo, int hi) {
    int i = lo;
    while (i <= hi) {
        int key = sorted[i].a;
        int j = lo;
        while (j <= hi) {
            for (; j <= hi; j++)
                if (original[j].a == key) break;
            if (sorted[i].b != original[j].b)
                return 0;
            i++;
            j++;
            if (i <= hi && sorted[i].a != key) break;
        }
    }
    return 1;
}
