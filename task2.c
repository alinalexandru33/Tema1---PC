#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char const *argv[]) {
    
    unsigned int inst, N, dim;
    unsigned short nr;
    int i, j, pos = 3, opNo, result = 0, aux;
    

    scanf("%u", &inst);

    N = extractBitsUint(inst, 3, 0) + 1;
    dim = extractBitsUint(inst, 4, 3 + 2 * N) + 1;
    opNo = ((N + 1) * dim) / 16;

    if (((N + 1) * dim) % 16 != 0) {
        opNo++;
    }

    /* Read opNo unsigned shorts and divide them into dim bits numbers*/
    for (i = 0; i < opNo; i++) {
        scanf("%hd", &nr);

        for (j = 0; j < maxSize; j += dim) {
            if (pos >= 3 + 2 * N) {
                break;
            }

            /* First operand */
            if (i == 0 && j == 0) {
                result = extractBitsUShort(nr, dim, j);
            } else {
                aux = extractBitsUShort(nr, dim, j);
                result = executeOp(result, aux, extractBitsUint(inst, 2, pos));
                pos += 2;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}
