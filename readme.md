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
	switch (open_link(link)) {
		case 0:
			printf("Success: Link \"%s\" opened\n", link);
			break;
		default:
			printf("Error: Link \"%s\" invalid\n", link);
			break;
	}
	return 0;
}

// gcc main.c -o main
```
