# Weblink

A header only library for opening links with C.

Works on Linux, MacOS and Windows.

### Usage
```C
//#define BUFFER_SIZE 10

#include <stdio.h>
#include "weblink.h"

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
