//
// Created by Zhao Zhili on 2021/11/4.
//

#include <stdio.h>
#include <stdlib.h>

#define API_PREFIX av_
#include "abi_guard.h"

int main()
{
    const char *ptr;
    static_abi_guard_check(&ptr);
    printf("%s\n", ptr);
    return 0;
}