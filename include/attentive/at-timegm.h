/*
 * Copyright © 2025 Zyax AB
 * This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See the COPYING file for more details.
 */

#ifndef ATTENTIVE_AT_UNIX_H
#define ATTENTIVE_AT_UNIX_H

#include <time.h>
#include <stdint.h>

time_t at_timegm(const struct tm *tm);

#endif

/* vim: set ts=4 sw=4 et: */
