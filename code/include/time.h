/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

struct timespec {
    long sec;
    long nsec;
};

unsigned int nanosleep(const struct timespec *req, const struct timespec *rem);
unsigned int sleep(unsigned int sec);

#endif
