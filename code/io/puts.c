// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int puts(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    write(1, "\n", 1);
	return 0;
}
