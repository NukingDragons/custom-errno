# custom-errno
My custom errno extension library

# Usage
The order of include directories matter when using this library, ensure that your own directory is the first one in the list, and that this libraries directory is the last one in the list. Any libraries that depend on this can be placed in any order in between.

```bash
gcc -Iinclude -Ipath/to/other/libraries/include -Icustom-errno/include source.c -o a.out
```

When using other libraries that depend on custom-errno, they will provide their own errors within their "custom-errnos.h" header.

When using only a single library that provides this file, then the include order is the only necessary step. When using multiple however, you must provide your own "custom-errnos.h" that contains the following, replacing the library names with the ones in use:

```c
#include <library1/custom-errnos.h>
#include <library2/custom-errnos.h>
```

You can also extend it with your own errors, refer to the provided "custom-errnos-example.h" file present in the include directory.

It's vital to not wrap the header with '#ifndef \_HEADER\_H_' etc, as it prevents multiple libraries from independently extending this library.
