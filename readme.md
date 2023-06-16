# Weblink

A header only library for opening links.

Works on Linux, MacOS and Windows.

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
