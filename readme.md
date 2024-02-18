# Weblink

A header only library for opening links with C.

Works on Linux, MacOS and Windows.

### Usage
```C
/*
Both openLink() & openLinks() use a buffered char[] to format the appropriate shell command to open URLs
The URL open command length differs on each OS but 2048 seems to be a safe average size that should work on all of the supported OS
If you decide to define your own size, make sure to place the definition above the include header statement
*/

//#define BUFFER_SIZE 10    // This will work. The header will check for this and use it instead of the default 2048

#include <stdio.h>
#include "weblink.h"

//#define BUFFER_SIZE 10    // This will not work. It will warn as a redefinition

int main(void) {
	char *link = "https://example.com/";
	int res = openLink(link);
	printf("Weblink\n  Status: %d,\n  Url: %s\n", res, link);
	return 0;
}
```

```C
#include <stdio.h>
#include "weblink.h"

#define COUNT 3

int main(void) {
	const char *links[COUNT] = {
		"https://www.example.com",
		"https://www.youtube.com",
		"https://www.twitter.com"
	};
	int res = openLinks(links, COUNT);
	printf("Weblink\n  Status: %d\n", res);
}

// gcc main.c -o main
```
