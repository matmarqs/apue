#define _POSIX_C_SOURCE 200809L  /* or use _XOPEN_SOURCE or _GNU_SOURCE */
#define _GNU_SOURCE
#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "apue.h"

/* this is an implementation of the getpwnam function */
struct passwd *getpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break;
    endpwent();
    return ptr;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        exit(1);
    }
    struct passwd *pwd = getpwnam(argv[1]);
    if (!pwd) {
        printf("Username %s not found in /etc/passwd file\n", argv[1]);
        exit(0);
    }
    printf("username = %s\n", pwd->pw_name);
    printf("encrypted password = %s\n", pwd->pw_passwd);
    printf("UID = %d\n", pwd->pw_uid);
    printf("GID = %d\n", pwd->pw_gid);
    printf("comment = %s\n", pwd->pw_gecos);
    printf("workdir = %s\n", pwd->pw_shell);
}
