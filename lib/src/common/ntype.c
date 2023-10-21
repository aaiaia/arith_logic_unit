#include <stdlib.h>
#include <stdint.h>

#include "common/ntype.h"
#include "common/util.h"

ntype_s* mkNum(size_t bitLen) {
    ntype_s* p = (ntype_s*)malloc(sizeof(ntype_s));
    p->bitLen = bitLen;
    p->size = BIT2SIZE(bitLen);
    p->array = (NTYPE*)calloc(p->size, sizeof(NTYPE));
    return p;
}

int rmNum(ntype_s** p) {
    int fs = 0;
    if((void*)p!=NULL) {
        if((void*)(*p)!=NULL) {
            free((*p)->array);
            free((*p));
            (*p) = (ntype_s*)NULL;
        }
        else {
            fs = -1;
        }
    }
    else {
        fs = -1;
    }
    return fs;
}
