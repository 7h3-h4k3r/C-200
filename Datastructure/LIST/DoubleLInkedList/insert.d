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
Reading symbols from ./a.out...
(gdb) break main && break insert
Function "main && break insert" not defined.
Make breakpoint pending on future shared library load? (y or [n]) n
(gdb) break main
Breakpoint 1 at 0x1333: file doublelinkedlist.c, line 62.
(gdb) break insert
Breakpoint 2 at 0x11fd: file doublelinkedlist.c, line 31.
(gdb) run
Starting program: /home/oxbin-sh/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/LIST/DoubleLInkedList/a.out 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at doublelinkedlist.c:62
62	int main(){
(gdb) n
65	    __init__(&head);
(gdb) 
66	    insert(&head,10);
(gdb) 

Breakpoint 2.1, insert (head=0x7fffffffdc40, value=10) at doublelinkedlist.c:31
31	    Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
32	    if (new_node == NULL){
(gdb) 
35	    new_node->data = value;
(gdb) 
36	    if ((*head)->tail  == NULL){
(gdb) 
37	        new_node->prev = NULL;
(gdb) n
42	    if ((*head)->head == NULL && (*head)->tail == NULL){
(gdb) n
43	        (*head)->head = new_node;
(gdb) n
44	        (*head)->tail = new_node;
(gdb) n
50	}
(gdb) print (*head)->tail
$1 = (Node *) 0x5555555592c0
(gdb) print (*head)->tail->data
$2 = 10
(gdb) print (*head)->tail->prec
There is no member named prec.
(gdb) print (*head)->tail->prev
$3 = (struct Node *) 0x0
(gdb) n
main () at doublelinkedlist.c:67
67	    insert(&head,20);
(gdb) n

Breakpoint 2.1, insert (head=0x7fffffffdc40, value=20) at doublelinkedlist.c:31
31	    Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
32	    if (new_node == NULL){
(gdb) 
35	    new_node->data = value;
(gdb) 
36	    if ((*head)->tail  == NULL){
(gdb) 
40	        new_node->prev = (*head)->tail;
(gdb) 
42	    if ((*head)->head == NULL && (*head)->tail == NULL){
(gdb) 
47	        (*head)->tail->next = new_node;
(gdb) 
48	        (*head)->tail =  new_node;
(gdb) 
50	}
(gdb) print new_node 
$4 = (Node *) 0x5555555592e0
(gdb) print new_node->data
$5 = 20
(gdb) print new_node->next
$6 = (struct Node *) 0x0
(gdb) print new_node->prev->data
$7 = 10
(gdb) n
main () at doublelinkedlist.c:68
68	    insert(&head,30);
(gdb) n

Breakpoint 2.1, insert (head=0x7fffffffdc40, value=30) at doublelinkedlist.c:31
31	    Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
32	    if (new_node == NULL){
(gdb) 
35	    new_node->data = value;
(gdb) 
36	    if ((*head)->tail  == NULL){
(gdb) 
40	        new_node->prev = (*head)->tail;
(gdb) 
42	    if ((*head)->head == NULL && (*head)->tail == NULL){
(gdb) 
47	        (*head)->tail->next = new_node;
(gdb) 
48	        (*head)->tail =  new_node;
(gdb) 
50	}
(gdb) print (*head)->head->data
$8 = 10
(gdb) print (*head)->head->prec
There is no member named prec.
(gdb) print (*head)->head->prev
$9 = (struct Node *) 0x0
(gdb) print (*head)->head->next
$10 = (struct Node *) 0x5555555592e0
(gdb) print (*head)->head->next->data
$11 = 20
(gdb) print (*head)->head->next->prec->data
There is no member named prec.
(gdb) print (*head)->head->next->prev->data
$12 = 10
(gdb) print (*head)->head->next->data
$13 = 20
(gdb) print (*head)->head->next->next
$14 = (struct Node *) 0x555555559300
(gdb) print (*head)->head->next->next->data
$15 = 30
(gdb) 
