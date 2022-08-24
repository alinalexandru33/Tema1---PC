#include <stdio.h>
#include <stdlib.h>

/* Function to extract bitsNo number of bits from 
   instruction inst on the position pos */
unsigned int extractBits(unsigned int inst, int bitsNo, int pos) {
    unsigned int ret;
    int bitsValue;

    switch(bitsNo) {
        case 2:
            bitsValue = 3;
            break;

        case 3:
            bitsValue = 7;
            break;

        case 4:
            bitsValue = 15;
            break;

        default:
            exit(EXIT_FAILURE);
    }

    ret = bitsValue << (sizeof(inst) * 8 - bitsNo - pos);
    ret &= inst;
    ret >>= (sizeof(inst) * 8 - bitsNo - pos);

    return ret;

}

/* Function to decode the operation */
char decodeOp(unsigned int op) {
    char ret;
    
    switch(op) {
        case 0:
            ret = '+';
            break;

        case 1:
            ret = '-';
            break;

        case 2:
            ret = '*';
            break;

        case 3:
            ret = '/';
            break; 

        default:
            exit(EXIT_FAILURE);        
    }

    return ret;
}

int main() {

    unsigned int inst;
    unsigned int N;
    int i, pos = 0;    

    scanf("%d", &inst);

    N = extractBits(inst, 3, pos) + 1;
    printf("%d ", N);

    pos += 3;
    for (i = 0; i < N; i++) {
        printf("%c ", decodeOp(extractBits(inst, 2, pos)));
        pos += 2;
    }

    printf("%d\n", extractBits(inst, 4, pos) + 1);

    return 0;
}