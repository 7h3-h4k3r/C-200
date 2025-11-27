 gdb ./a.out 
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
--Type <RET> for more, q to quit, c to continue without paging--c
Reading symbols from ./a.out...
(gdb) break main
Breakpoint 1 at 0x1400: file doublelinkedlist.c, line 91.
(gdb) run
Starting program: /home/oxbin-sh/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/LIST/DoubleLInkedList/a.out 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at doublelinkedlist.c:91
91      int main(){
(gdb) n
94          __init__(&head);
(gdb) 
95          insert(&head,10);
(gdb) 
96          insert(&head,20);
(gdb) 
97          insert(&head,30);
(gdb) 
98          pop(&head,20);
(gdb) break pop
Breakpoint 2 at 0x55555555536a: pop. (2 locations)
(gdb) n

Breakpoint 2.1, pop (head=0x7fffffffd990, value=20) at doublelinkedlist.c:73
73          if (value == 0){
(gdb) n
77          __pop__(&(*head)->head,value);
(gdb) break __pop__
Breakpoint 3 at 0x5555555552d2: file doublelinkedlist.c, line 54.
(gdb) n

Breakpoint 3, __pop__ (head=0x5555555592a0, value=20) at doublelinkedlist.c:54
54          Node *temp = (*head);
(gdb) n
55          while (temp)
(gdb) 
57              if(temp->data == value){
(gdb) print temp->data
$1 = 10
(gdb) n
66              temp = temp->next;
(gdb) n
55          while (temp)
(gdb) n
57              if(temp->data == value){
(gdb) n
58                  if (temp->prev == NULL){
(gdb) n
63                  temp->prev->next = temp->next;
(gdb) print temp->prev->data
$2 = 10
(gdb) print temp->data
$3 = 20
(gdb) print temp->prev->next->data
$4 = 20
(gdb) n
64                  temp->next->prev = temp->prev;
(gdb) print temp->prev->next
$5 = (struct Node *) 0x555555559300
(gdb) print temp->prev->next->data
$6 = 30
(gdb) n
66              temp = temp->next;
(gdb) quit
A debugging session is active.

        Inferior 1 [process 3831] will be killed.

Quit anyway? (y or n) y
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/LIST/DoubleLInkedList$ gcc -g doublelinkedlist.c 
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/LIST/DoubleLInkedList$ gdb ./a.out 
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
--Type <RET> for more, q to quit, c to continue without paging--c
Reading symbols from ./a.out...
(gdb) break main
Breakpoint 1 at 0x140c: file doublelinkedlist.c, line 93.
(gdb) run
Starting program: /home/oxbin-sh/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/LIST/DoubleLInkedList/a.out 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) 
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at doublelinkedlist.c:93
93      int main(){
(gdb) break __pop__
Breakpoint 2 at 0x5555555552d2: file doublelinkedlist.c, line 54.
(gdb) c
Continuing.

Breakpoint 2, __pop__ (head=0x5555555592a0, value=20) at doublelinkedlist.c:54
54          Node *temp = (*head);
(gdb) n
55          while (temp)
(gdb) 
57              if(temp->data == value){
(gdb) 
67              temp = temp->next;
(gdb) 
55          while (temp)
(gdb) 
57              if(temp->data == value){
(gdb) 
58                  if (temp->prev == NULL){
(gdb) 
63                  temp->prev->next = temp->next;
(gdb) 
64                  temp->next->prev = temp->prev;
(gdb) 
65                  return 1;
(gdb) 
71      }
(gdb) print temp->data
$1 = 20
(gdb) n
pop (head=0x7fffffffd990, value=20) at doublelinkedlist.c:80
80      }
(gdb) print head->data
There is no member named data.
(gdb) print head->data
There is no member named data.
(gdb) n
main () at doublelinkedlist.c:101
101     }
(gdb) print (*head)->head->data
$2 = 10
(gdb) print (*head)->head->next->data
$3 = 30
(gdb) print (*head)->head->next->prev->data
$4 = 10