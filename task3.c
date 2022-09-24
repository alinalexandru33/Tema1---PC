#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char const *argv[]) {
    
    unsigned int inst, N, dim;
    unsigned short nr, aux;
    int i, j = 0, pos = 3, opNo, result = 0;  

    scanf("%u", &inst);

    N = extractBitsUint(inst, 3, 0) + 1;
    dim = extractBitsUint(inst, 4, 3 + 2 * N) + 1;
    opNo = ((N + 1) * dim) / 16;

    if (((N + 1) * dim) % 16 != 0) {
        opNo++;
    }
    
    for (i = 0; i < opNo; i++) {
        
        /* First operand */
        if (i == 0) {
            scanf("%hd", &nr);

            result = extractBits(nr, dim, j);
            j += dim;
        } else {

            /* Cannot get a full operand from the number */
            if (dim > maxSize - j) {
                aux = extractBits(nr, maxSize - j, j);
                
                scanf("%hd", &nr);
                aux = (aux << (dim - (maxSize - j))) | (extractBits(nr, dim - (maxSize - j), 0));
                j = dim - (maxSize - j);

                result = executeOp(result, aux, extractBitsUint(inst, 2, pos));
                pos += 2;
            
            /* Can get another full operand from the number */
            } else {
                aux = extractBits(nr, dim, j);
                j += dim;

                result = executeOp(result, aux, extractBitsUint(inst, 2, pos));
                pos += 2;

                opNo++;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}
