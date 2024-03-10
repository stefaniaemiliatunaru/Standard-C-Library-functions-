// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int sec) {
    struct timespec req = {sec, 0};
    struct timespec rem = {0, 0};

    nanosleep(&req, &rem);

    return rem.sec;
}
