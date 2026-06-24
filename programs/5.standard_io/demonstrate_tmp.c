#include "apue.h"

int main(void)
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    // warning: the use of `tmpnam' is dangerous, better use `mkstemp'
    printf("%s\n", tmpnam(NULL)); /* first temp name */

    printf("%s\n", name);       /* second temp name */
    tmpnam(name);

    if ((fp = tmpfile()) == NULL) /* create temp */
        err_sys("tmpfile error");

    fputs("one line of output\n", fp); /* write to temp file */
    rewind(fp);                        /* then read it back */

    if (fgets(line, sizeof(line), fp) == NULL)
        err_sys("fgets error");
    fputs(line, stdout);        /* print the line we wrote */
    exit(0);
}
