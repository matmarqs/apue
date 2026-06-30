#include <stdio.h>

void main() {
    printf("hello, world\n");
}

/* interesting, with void main() we get:
 * $ ./programs/7.process_environment/hello_world_classic.out
 * hello, world
 * └─$ echo $?
 * 13
 * Notice that 13 is the length of "hello, world\n"
 */
