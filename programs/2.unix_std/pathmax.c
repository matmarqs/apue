#include "apue.h"

int main() {
    size_t size;
    path_alloc(&size);
    printf("path = %lu\n", size);
    return 0;
}
