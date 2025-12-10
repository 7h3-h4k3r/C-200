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

--Type <RET> for more, q to quit, c to continue without paging--n
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./graph...
(gdb) break add_edge
Breakpoint 1 at 0x1347: file graph.c, line 70.
(gdb) run
Starting program: /home/oxbin-sh/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph/graph 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, add_edge (graph=0x7fffffffd9b0, v1=10, v2=20) at graph.c:70
70          Vertax *vertax1 = get_vertax(graph,v1);
(gdb) n
71          if(vertax1==NULL){
(gdb) 
75          Vertax *vertax2 = get_vertax(graph,v2);
(gdb) 
76          if(vertax1==NULL){
(gdb) 
80          Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
81          new_node->value  = vertax2;
(gdb) 
82          if (new_node == NULL){
(gdb) 
86          Node *temp = vertax1->edge;
(gdb) 
87          if(temp==NULL){
(gdb) 
88              temp = new_node;
(gdb) 
89              return 1;
(gdb) 
97      }
(gdb) 
main () at graph.c:106
106     }
(gdb) quit
A debugging session is active.

        Inferior 1 [process 38428] will be killed.

Quit anyway? (y or n) y
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph$ make
cc -g    graph.c   -o graph
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph$ make gdb
gdb -q ./graph
Reading symbols from ./graph...
(gdb) break add_edge
Breakpoint 1 at 0x1347: file graph.c, line 70.
(gdb) n
The program is not being run.
(gdb) run
Starting program: /home/oxbin-sh/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph/graph 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, add_edge (graph=0x7fffffffd940, v1=10, v2=20) at graph.c:70
70          Vertax *vertax1 = get_vertax(graph,v1);
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) n
71          if(vertax1==NULL){
(gdb) 
75          Vertax *vertax2 = get_vertax(graph,v2);
(gdb) 
76          if(vertax1==NULL){
(gdb) 
80          Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
81          new_node->value  = vertax2;
(gdb) 
82          if (new_node == NULL){
(gdb) 
86          Node *temp = vertax1->edge;
(gdb) 
87          if(temp==NULL){
(gdb) 
88              temp = new_node;
(gdb) 
89              return 1;
(gdb) 
97      }
(gdb) 
main () at graph.c:105
105         add_edge(&graph,10,30);
(gdb) 

Breakpoint 1, add_edge (graph=0x7fffffffd940, v1=10, v2=30) at graph.c:70
70          Vertax *vertax1 = get_vertax(graph,v1);
(gdb) 
71          if(vertax1==NULL){
(gdb) 
75          Vertax *vertax2 = get_vertax(graph,v2);
(gdb) 
76          if(vertax1==NULL){
(gdb) 
80          Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
81          new_node->value  = vertax2;
(gdb) 
82          if (new_node == NULL){
(gdb) 
86          Node *temp = vertax1->edge;
(gdb) 
87          if(temp==NULL){
(gdb) 
88              temp = new_node;
(gdb) n
89              return 1;
(gdb) n
97      }
(gdb) n
main () at graph.c:106
106         printf("Debuggind");
(gdb) quit
A debugging session is active.

        Inferior 1 [process 39340] will be killed.

Quit anyway? (y or n) y
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph$ make
make: 'graph' is up to date.
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph$ make gdb
gdb -q ./graph
Reading symbols from ./graph...
(gdb) break add_edge
Breakpoint 1 at 0x1347: file graph.c, line 70.
(gdb) run
Starting program: /home/oxbin-sh/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph/graph 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, add_edge (graph=0x7fffffffd940, v1=10, v2=20) at graph.c:70
70          Vertax *vertax1 = get_vertax(graph,v1);
(gdb) n
71          if(vertax1==NULL){
(gdb) 
75          Vertax *vertax2 = get_vertax(graph,v2);
(gdb) 
76          if(vertax1==NULL){
(gdb) 
80          Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
81          new_node->value  = vertax2;
(gdb) 
82          if (new_node == NULL){
(gdb) 
86          Node *temp = vertax1->edge;
(gdb) 
87          if(temp==NULL){
(gdb) print vertax1->edge
$1 = (Node *) 0x0
(gdb) n
88              temp = new_node;
(gdb) n
89              return 1;
(gdb) print vertax1->edge
$2 = (Node *) 0x0
(gdb) quit
A debugging session is active.

        Inferior 1 [process 40020] will be killed.

Quit anyway? (y or n) y
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph$ make
cc -g    graph.c   -o graph
oxbin-sh@oxbin-sh-H61MHV3:~/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph$ make gdb
gdb -q ./graph
Reading symbols from ./graph...
(gdb) break add_edge
Breakpoint 1 at 0x1347: file graph.c, line 70.
(gdb) run
Starting program: /home/oxbin-sh/BrainFun/PlayGround/500_c_zeal_Ninja/Datastructure/graph/graph 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, add_edge (graph=0x7fffffffd940, v1=10, v2=20) at graph.c:70
70          Vertax *vertax1 = get_vertax(graph,v1);
(gdb) n
71          if(vertax1==NULL){
(gdb) 
75          Vertax *vertax2 = get_vertax(graph,v2);
(gdb) 
76          if(vertax1==NULL){
(gdb) 
80          Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
81          new_node->value  = vertax2;
(gdb) 
82          if (new_node == NULL){
(gdb) 
86          Node *temp = vertax1->edge;
(gdb) 
87          if(temp==NULL){
(gdb) 
88              vertax1->edge = new_node;
(gdb) 
89              return 1;
(gdb) print vertax1->edge
$1 = (Node *) 0x555555559360
(gdb) print vertax1->edge->value
$2 = (void *) 0x555555559300
(gdb) print vertax1->edge->next
$3 = (struct Node *) 0x0
(gdb) n
97      }
(gdb) n
main () at graph.c:105
105         add_edge(&graph,10,30);
(gdb) print graph
$4 = (Graph *) 0x5555555592a0
(gdb) print graph->v
$5 = (Vertax *) 0x5555555592c0
(gdb) print graph->v->vertax
$6 = 10
(gdb) print graph->v->edge
$7 = (Node *) 0x555555559360
(gdb) print graph->v->edge->value
$8 = (void *) 0x555555559300
(gdb) print graph->next->v
$9 = (Vertax *) 0x555555559300
(gdb) n

Breakpoint 1, add_edge (graph=0x7fffffffd940, v1=10, v2=30) at graph.c:70
70          Vertax *vertax1 = get_vertax(graph,v1);
(gdb) n
71          if(vertax1==NULL){
(gdb) n
75          Vertax *vertax2 = get_vertax(graph,v2);
(gdb) 
76          if(vertax1==NULL){
(gdb) 
80          Node *new_node = (Node*)malloc(sizeof(Node));
(gdb) 
81          new_node->value  = vertax2;
(gdb) 
82          if (new_node == NULL){
(gdb) 
86          Node *temp = vertax1->edge;
(gdb) 
87          if(temp==NULL){
(gdb) 
91          while (temp->next != NULL)
(gdb) 
95          temp->next = new_node;
(gdb) 
97      }
(gdb) 
main () at graph.c:106
106         printf("Debuggind");
(gdb) print graph->v
$10 = (Vertax *) 0x5555555592c0
(gdb) print graph->v-vertax
No symbol "vertax" in current context.
(gdb) print graph->v->vertax
$11 = 10
(gdb) print graph->v->edge
$12 = (Node *) 0x555555559360
(gdb) print graph->v->edge->value
$13 = (void *) 0x555555559300
(gdb) print graph->v->edge->next
$14 = (struct Node *) 0x555555559380
(gdb) print graph->v->edge->value
$15 = (void *) 0x555555559300
(gdb) print graph->v->edge->next->value
$16 = (void *) 0x555555559340
(gdb) print graph->v->edge->next->value->vertax
Attempt to dereference a generic pointer.
(gdb) x/4x 0x555555559340
0x555555559340: 0x0000001e      0x00000000      0x00000000      0x00000000
(gdb) print graph->v->next
There is no member named next.
(gdb) print graph->v
$17 = (Vertax *) 0x5555555592c0
(gdb) print graph->next->v
$18 = (Vertax *) 0x555555559300
(gdb) print graph->next->next->v
$19 = (Vertax *) 0x555555559340
(gdb) 