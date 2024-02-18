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


#ifndef BUFFER_SIZE
	// The complete length of the command to be executed
	#define BUFFER_SIZE 2048
#endif

#ifdef __linux__ // LINUX
	#define PLACEHOLDER "xdg-open '%s' > /dev/null 2>&1"
#elif __APPLE__ // MACOS
	#define PLACEHOLDER "open '%s'"
#elif _WIN32 // WINDOWS
	#define PLACEHOLDER "explorer '%s'"
#endif

static inline int openLink(const char *link) {
	char cmd[BUFFER_SIZE];
	int res = snprintf(cmd, BUFFER_SIZE, PLACEHOLDER, link);
	if (res < 0 || res > BUFFER_SIZE)
		return -1;
	res = system(cmd);
	return res;
}

static inline int openLinks(const char *links[], const int count) {
	char cmd[BUFFER_SIZE];
	int res = 0;
	for (int i = 0; i < count; i++) {
		res = snprintf(cmd, BUFFER_SIZE, PLACEHOLDER, links[i]);
		if (res < 0 || res > BUFFER_SIZE)
			return res;
		res = system(cmd);
	}
	return res;
}

#endif // WEBLINK_H