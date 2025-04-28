/*
 * Copyright © 2015 Zyax AB
 * This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See the COPYING file for more details.
 */

 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include <check.h>
 #include <glib.h>

 #include <attentive/at-timegm.h>


 START_TEST(test_timegm)
 {
     printf(":: test_timegm\n");

     struct tm tmg = {
        .tm_sec = 7,
        .tm_min = 14,
        .tm_hour = 3,
        .tm_mday = 19,
        .tm_mon = 0,
        .tm_year = 138,
        .tm_wday = 2,
        .tm_yday = 18,
        .tm_isdst = 0
    };

    time_t t = at_timegm(&tmg);
    ck_assert_int_eq(t, 0x7fffffff);
 }
 END_TEST

 Suite *attentive_suite(void)
 {
     Suite *s = suite_create("attentive");
     TCase *tc;

     tc = tcase_create("timegm");
     tcase_add_test(tc, test_timegm);
     suite_add_tcase(s, tc);

     return s;
 }

 int main()
 {
     int number_failed;
     Suite *s = attentive_suite();
     SRunner *sr = srunner_create(s);
     srunner_run_all(sr, CK_NORMAL);
     number_failed = srunner_ntests_failed(sr);
     srunner_free(sr);
     return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }

 /* vim: set ts=4 sw=4 et: */
