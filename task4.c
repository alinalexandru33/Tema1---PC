#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char const *argv[]) {
    
    unsigned int inst, N, dim, operations[10];
    unsigned short nr, operands[10];
    int i, j = 0, pos = 3, opNo, idx = 0;  

    scanf("%u", &inst);

    N = extractBitsUint(inst, 3, 0) + 1;
    dim = extractBitsUint(inst, 4, 3 + 2 * N) + 1;
    opNo = ((N + 1) * dim) / 16;

    if (((N + 1) * dim) % 16 != 0) {
        opNo++;
    }
    
    /* Extract the operands */
    for (i = 0; i < opNo; i++) {
        scanf("%hd", &nr);

        for (j = 0; j < maxSize; j += dim) {
            if (pos >= 3 + 2 * N) {
                break;
            }

            operands[idx] = extractBitsUShort(nr, dim, j);
                idx++;
        }
    }

    /* Extract the operations */
    for (i = 0; i < N; i++) {
        operations[i] = extractBitsUint(inst, 2, pos);
        pos += 2;
    }

    
    /* Execute multiplication and division first */
    for (i = 0; i < N; i++) {
        if (operations[i] == 2 || operations[i] == 3) {
            operands[i] = executeOp(operands[i], operands[i + 1], operations[i]);

            /* Remove one operand */
            for (j = i + 1; j < idx - 1; j++) {
                operands[j] = operands[j + 1];
            }
            idx--;
            
            /* Remove the operations */
            for (j = i; j < N - 1; j++) {
                operations[j] = operations[j + 1];
            }
            N--;
            i--;
        }
    }

    /* Then execute the rest */
    for (i = 0; i < N; i++) {
        operands[i] = executeOp(operands[i], operands[i + 1], operations[i]);

        /* Remove one operand */
        for (j = i + 1; j < idx - 1; j++) {
            operands[j] = operands[j + 1];
        }
        idx--;
        
        /* Remove the operations */
        for (j = i; j < N - 1; j++) {
            operations[j] = operations[j + 1];
        }
        N--;
        i--;
    }

    printf("%d\n", operands[0]);

    return 0;
}
