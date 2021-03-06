/*-
 * Copyright (c) 2011 Pawel Jakub Dawidek <pawel@dawidek.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $P4: //depot/projects/trustedbsd/openbsm/bin/auditdistd/subr.h#1 $
 */

#ifndef	_AUDITDISTD_SUBR_H_
#define	_AUDITDISTD_SUBR_H_

#include <sys/types.h>

#include "auditdistd.h"

#define	KEEP_ERRNO(work)	do {					\
	int _rerrno;							\
									\
	_rerrno = errno;						\
	work;								\
	errno = _rerrno;						\
} while (0)

int vsnprlcat(char *str, size_t size, const char *fmt, va_list ap);
int snprlcat(char *str, size_t size, const char *fmt, ...);

const char *role2str(int role);
const char *adist_errstr(int error);

void adreq_log(int loglevel, int debuglevel, int error, struct adreq *adreq,
    const char *fmt, ...);

int adist_random(unsigned char *buf, size_t size);

int wait_for_dir_init(int fd);
int wait_for_file_init(int fd);
void wait_for_dir(void);
void wait_for_file(void);

#endif	/* !_AUDITDISTD_SUBR_H_ */
