# Weblink

A header only library for opening links.

Currently works only on Linux, with consideration of MacOS and Windows at a later time.

Static linking with no compile flags required.

### Usage
```C
// main.c
#include "weblink.h"

int main(void) {
	char link[] = "https://example.com/";
	switch (open_link(link)) {
			case 0:
				printf("Success: Link \"%s\" opened\n", link);
				break;
			case 1:
				printf("Error: Link \"%s\" invalid\n", link);
				break;
			default:
				printf("Error: Unable to find a provider\n");
				break;
		}
	return 0;
}

// gcc main.c -o main.o
```
