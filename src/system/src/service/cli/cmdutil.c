//
//  cmdutil.c
//  GunwOS
//
//  Created by Artur Danielewski on 22.03.2020.
//

#include "cmdutil.h"

#include "../../../../lib/stdgunw/stdgunw.h"

struct k_cmd_param k_cmd_paramAt(const char * const params, unsigned int loc) {
    if (!params) return (struct k_cmd_param){ 0, 0 };

    size_t len = strlen(params);    
    size_t lastOffset = 0;
    size_t currentOffset = 0;
    size_t currentParam = 0;

    while (currentOffset <= len) {
        if (!params[currentOffset] || params[currentOffset] == CMD_PARAM_SEPARATOR) {
            if (currentParam == loc) {
                return (struct k_cmd_param){ lastOffset, currentOffset - lastOffset };
            }

            ++currentParam;
            lastOffset = ++currentOffset;
        } else {
            ++currentOffset;
        }
    }
        
    return (struct k_cmd_param){ 0, 0 };
}

void k_cmd_paramLoad(const char * const params, char * const loc, const struct k_cmd_param pDesc) {
    memnull(loc, pDesc.length + 1);
    memcopy(params + pDesc.offset, loc, pDesc.length);
}