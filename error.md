Let's try to printf a simple sentence.
===== Custom format =====
Best\x0ASchool
===== Printing Binary =====
[11111111111111111111110000000000][11111111111111111111111111111111]
[1111111111]
===== Printing Chars && Strings =====
Character:[H]
String:[I am a string !]
===== Printing ROT13 =====
[Complete the sentence: You know nothing, Jon Snow.]
[This sentence is retrieved from va_args!]
===== Printing Reverse Order =====
[.ecnetnes elpmis a ftnirp ot yrt s'teL]
[dlrow olleH]
Unknown:[neL]
===== Printing Int && Digits =====
Length:[39, 39]
Negative:[-762534]
===== Printing Unsigned Int =====
Unsigned:[2147484671]
[1023]
[There is 1024 bytes in 1 KB]
===== Printing Octal =====
Unsigned octal:[20000001777]
[1777]
===== Printing Hexadecimal =====
Unsigned hexadecimal:[800003ff, 800003FF]
[FFFFFC00]
[A]
[FFFFFFFF]
[3FF]
===== Printing Percent =====
Percent:[%]
===== Printing memory addresses =====
Address:[0x7ffe637541f0]
0x7fff5100b608
(nil)
Can you print an address?
0x7fff5100b6f8
Nice!
Can you print several addresses?
0x7fff5100b6f8,0x7faf51f0f608,0x6ff42510b6f8,0x7fff510236f8
Nice!
Can you print an address?
0xffffffffffffffff
Nice!
14

Conditional jump or move depends on uninitialised value(s)
==2339==    at 0x109C0A: _strlen (in /home/vic/work/printf/a)
==2339==    by 0x109499: _swap_func (in /home/vic/work/printf/a)
==2339==    by 0x1095F5: _get_base (in /home/vic/work/printf/a)
==2339==    by 0x10955F: get_hex_val (in /home/vic/work/printf/a)
==2339==    by 0x109347: fill_no_printable_buff (in /home/vic/work/printf/a)
==2339==    by 0x109294: _no_printable_arg (in /home/vic/work/printf/a)
==2339==    by 0x10A624: _printf (in /home/vic/work/printf/a)
==2339==    by 0x10AEC2: main (in /home/vic/work/printf/a)
==2339==  Uninitialised value was created by a heap allocation
==2339==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==2339==    by 0x10993E: creat_heap_mem (in /home/vic/work/printf/a)
==2339==    by 0x109548: get_hex_val (in /home/vic/work/printf/a)
==2339==    by 0x109347: fill_no_printable_buff (in /home/vic/work/printf/a)
==2339==    by 0x109294: _no_printable_arg (in /home/vic/work/printf/a)
==2339==    by 0x10A624: _printf (in /home/vic/work/printf/a)
==2339==    by 0x10AEC2: main (in /home/vic/work/printf/a)
==2339==
==2339==
==2339== HEAP SUMMARY:
==2339==     in use at exit: 15 bytes in 1 blocks
==2339==   total heap usage: 34 allocs, 33 frees, 4,554 bytes allocated
==2339==
==2339== 15 bytes in 1 blocks are definitely lost in loss record 1 of 1
==2339==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==2339==    by 0x10993E: creat_heap_mem (in /home/vic/work/printf/a)
==2339==    by 0x10927B: _no_printable_arg (in /home/vic/work/printf/a)
==2339==    by 0x10A624: _printf (in /home/vic/work/printf/a)
==2339==    by 0x10AEC2: main (in /home/vic/work/printf/a)
==2339==
==2339== LEAK SUMMARY:
==2339==    definitely lost: 15 bytes in 1 blocks
==2339==    indirectly lost: 0 bytes in 0 blocks
==2339==      possibly lost: 0 bytes in 0 blocks
==2339==    still reachable: 0 bytes in 0 blocks
==2339==         suppressed: 0 bytes in 0 blocks
==2339==
==2339== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
==2339==
==2339== 1 errors in context 1 of 2:
==2339== Conditional jump or move depends on uninitialised value(s)
==2339==    at 0x109C0A: _strlen (in /home/vic/work/printf/a)
==2339==    by 0x109499: _swap_func (in /home/vic/work/printf/a)
==2339==    by 0x1095F5: _get_base (in /home/vic/work/printf/a)
==2339==    by 0x10955F: get_hex_val (in /home/vic/work/printf/a)
==2339==    by 0x109347: fill_no_printable_buff (in /home/vic/work/printf/a)
==2339==    by 0x109294: _no_printable_arg (in /home/vic/work/printf/a)
==2339==    by 0x10A624: _printf (in /home/vic/work/printf/a)
==2339==    by 0x10AEC2: main (in /home/vic/work/printf/a)
==2339==  Uninitialised value was created by a heap allocation
==2339==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==2339==    by 0x10993E: creat_heap_mem (in /home/vic/work/printf/a)
==2339==    by 0x109548: get_hex_val (in /home/vic/work/printf/a)
==2339==    by 0x109347: fill_no_printable_buff (in /home/vic/work/printf/a)
==2339==    by 0x109294: _no_printable_arg (in /home/vic/work/printf/a)
==2339==    by 0x10A624: _printf (in /home/vic/work/printf/a)
==2339==    by 0x10AEC2: main (in /home/vic/work/printf/a)
==2339==
==2339== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
