/*
 * MIT License
 *
 * Copyright (c) 2023 Ionut Rogojan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef WEBLINK_H
#define  WEBLINK_H

#define _GNU_SOURCE
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof((array)[0]))

#define WOPEN_SUCCESS 0
#define WOPEN_FAILURE 1
#define WOPEN_ERROR -1

#include <stdio.h>
#include <stdlib.h>

static inline int open_link(char link[]) {
    char* cmd;
#ifdef __linux__ // LINUX
    char* open;
    char* provider_list[] = {
        "www-browser",
        "x-www-browser",
        "gnome-www-browser",
        "xdg-open"
    };
    for (int i = 0; i < ARRAY_LENGTH(provider_list); i++) {
        if (asprintf(&cmd, "which %s > /dev/null 2>&1", provider_list[i]) == -1) {
            return WOPEN_ERROR;
        }
        int ret = system(cmd);
        free(cmd);
        if (ret == -1) {
            return WOPEN_ERROR;
        } else if (ret == 0) {
            open = provider_list[i];
            break;
        }
    }
    if (open == NULL) {
        return WOPEN_ERROR;
    }
    // char* cmd;
    if(asprintf(&cmd, "%s '%s' > /dev/null 2>&1", open, link) == -1) {
        return WOPEN_ERROR;
    }
#elif __APPLE__ // MACOS
    if(asprintf(&cmd, "open '%s'", link) == -1) {
        return WOPEN_ERROR;
    }
#elif _WIN32 // WINDOWS
    if(asprintf(&cmd, "explorer '%s'", link) == -1) {
        return WOPEN_ERROR;
    }
#endif
    int ret = system(cmd);
    free(cmd);
    return ret;
}

#endif // WEBLINK_H