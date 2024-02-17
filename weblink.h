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

#ifndef INCLUDED_STDIO_H
#define INCLUDED_STDIO_H
	#include <stdio.h>
#endif // INCLUDED_STDIO_H

#ifndef INCLUDED_STDLIB_H
#define INCLUDED_STDLIB_H
	#include <stdlib.h>
#endif // INCLUDED_STDLIB_H

/*
#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 2048
#endif
*/

// TODO: create an ifndef buffer size and use that for the cmd to avoid constant memory allocation and deallocation

static inline int openLink(const char *link) {
	char* cmd = NULL;
	//char cmd[BUFFER_SIZE];
	int res = 0;
#ifdef __linux__ // LINUX
	res = asprintf(&cmd, "xdg-open '%s' > /dev/null 2>&1", link);
#elif __APPLE__ // MACOS
	res = asprintf(&cmd, "open '%s'", link);
#elif _WIN32 // WINDOWS
	res = asprintf(&cmd, "explorer '%s'", link);
#endif
	if (res == -1)
		return res;
	res = system(cmd);
	free(cmd);
	return res;
}

static inline int openLinks(const char *links[], int count) {
	char *cmd = NULL;
	int res = 0;
	for (int i = 0; i < count; i++) {
#ifdef __linux__ // LINUX
		res = asprintf(&cmd, "xdg-open '%s' > /dev/null 2>&1", links[i]);
#elif __APPLE__ // MACOS
		res = asprintf(&cmd, "open '%s'", links[i]);
#elif _WIN32 // WINDOWS
		res = asprintf(&cmd, "explorer '%s'", links[i]);
#endif
		if (res == -1)
			return res;
		res = system(cmd);
		free(cmd);
	}
	return res;
}

#endif // WEBLINK_H