#ifndef WEBLINK_H
#define  WEBLINK_H

#define _GNU_SOURCE
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof((array)[0]))

#include <stdio.h>
#include <stdlib.h>

static inline int open_link(char link[]) {
    char* open, *cmd;
    char* provider_list[] = {
        "www-browser",
        "x-www-browser",
        "gnome-www-browser",
        "xdg-open"
    };
    for (int i = 0; i < ARRAY_LENGTH(provider_list); i++) {
        if (asprintf(&cmd, "which %s > /dev/null 2>&1", provider_list[i]) == -1) {
            return -1;
        }
        int ret = system(cmd);
        free(cmd);
        if (ret == -1) {
            return -1;
        } else if (ret == 0) {
            open = provider_list[i];
            break;
        }
    }
    if (open == NULL) {
        return -1;
    }
    // char* cmd;
    if(asprintf(&cmd, "%s '%s' > /dev/null 2>&1", open, link) == -1) {
        return -1;
    }
    int res = system(cmd);
    free(cmd);
    return res;
}

#endif // WEBLINK_H