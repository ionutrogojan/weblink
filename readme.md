# Weblink

A header only library for opening links with C.

Works on Linux, MacOS and Windows.

### Usage
```C
// main.c
#include <stdio.h>
#include "weblink.h"

int main(void) {
	char *link = "https://example.com/";
	int res = openLink(link);
	printf("Weblink\n  Status: %d,\n  Url: %s\n", res, link);
	return 0;
}

// gcc main.c -o main
```
