#include <math.h>
#ifndef TASK
#define TASK 

#define maxSize 16

/* Functions to extract bitsNo number of bits from 
   instruction inst on the position pos */
int extractBits(unsigned short inst, int bitsNo, int pos) {
    unsigned short ret;
    int i, bitsValue = 0;

    /* Compute bits value coresponding to the number of bits */
    for (i = 0; i < bitsNo; i++) {
        bitsValue += pow(2, i);
    }

    ret = bitsValue << (sizeof(inst) * 8 - bitsNo - pos);
    ret &= inst;
    ret >>= (sizeof(inst) * 8 - bitsNo - pos);

    return ret;
}

int extractBitsUint(unsigned int inst, int bitsNo, int pos) {
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

int extractBitsUShort(unsigned short inst, int bitsNo, int pos) {
    unsigned short ret;
    int bitsValue;

    switch(bitsNo) {
        case 1:
            bitsValue = 1;
            break;

        case 2:
            bitsValue = 3;
            break;

        case 3:
            bitsValue = 7;
            break;

        case 4:
            bitsValue = 15;
            break;

        case 8:
            bitsValue = 255;
            break;

        case 16:
            bitsValue = 65535;
            break;

        default:
            perror("Invalid bitsNo\n");
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
            perror("Operation can't be decoded\n");
            exit(EXIT_FAILURE);        
    }

    return ret;
}

/* Function to execute the operation */
int executeOp(int left, int right, int op) {
    int ret;

    switch(op) {
        case 0:
            ret = left + right;
            break;

        case 1:
            ret = left - right;
            break;

        case 2:
            ret = left * right;
            break;

        case 3:
            ret = left / right;
            break; 

        default:
            perror("Operation can't be executed\n");
            exit(EXIT_FAILURE);        
    }

    return ret;
}

#endif