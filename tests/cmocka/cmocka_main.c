/****************************************************************************
 * tests/cmocka/cmocka_main.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/boardctl.h>

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka/include/cmocka.h"

#ifdef CONFIG_BUILD_KERNEL
int main(int argc, char *argv[])
#else
int cmocka_main(int argc, char *argv[])
#endif
{
  int status = OK;
  if(test_alloc_main() != 0)
    status = ERROR;
  if(test_assert_macros_main() != 0)
    status = ERROR;
  if(test_assert_macros_fail_main() == 0)
    status = ERROR;
  if(test_basics_main() != 0)
    status = ERROR;
  if(test_cmockery_main() != 0)
    status = ERROR;
    //test_exception_handler_main();
  if(test_fixtures_main() != 0)
    status = ERROR;
  if(test_group_fixtures_main() != 0)
    status = ERROR;
  if(test_group_setup_fail_main() == 0)
    status = ERROR;
  if(test_setup_fail_main() == 0)
    status = ERROR;
  if(test_skip_main() != 0)
    status = ERROR;

  printf("Tests completed with status: %d\n",status);
  boardctl(BOARDIOC_POWEROFF,status);
  return status;
}

