#include <stdio.h>
#include <stdlib.h>
#include "num_pairs.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("One argument must be specified(Max number)\n");
        exit(1);
    }

    unsigned long max;
    max = strtoul(argv[1], NULL, 10);

    printf("Searching for all betrothed pairs up to %lu\n", max);

    unsigned long i, j, count;
    count = 0;
    for (i = 1; i <= max; i++) {
        for (j = 1; j <= i; j++) {
            if (is_betrothed(i, j)) {
                printf("(%lu, %lu)\n", i, j);
                count += 1;
            }
        }
    }
    if (count <= 1) {
        printf("%lu pair found\n", count);
    } else {
        printf("%lu pairs found\n", count);
    }

    return 0;
}