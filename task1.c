#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char const *argv[]) {

    unsigned int inst, N;
    int i, pos = 0;    

    scanf("%d", &inst);

    N = extractBitsUint(inst, 3, pos) + 1;
    printf("%d ", N);

    pos += 3;
    for (i = 0; i < N; i++) {
        printf("%c ", decodeOp(extractBitsUint(inst, 2, pos)));
        pos += 2;
    }

    printf("%d\n", extractBitsUint(inst, 4, pos) + 1);

    return 0;
}