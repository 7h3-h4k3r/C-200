#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int age;
    float id;
} name;
void getData(name *get_Student_data){
    printf(" My name is Gobal Iam from the Idle kadai\n");
    printf("%d Age %f ID\n",get_Student_data->age ,get_Student_data->id);
}

struct name* allocateData(){
    name* node = (name *)malloc(sizeof(name));
    if (node == NULL){
        printf("Memory allocation Failed {Internal Error}");
        exit(-1);
    }
    return node;
}

int main(){
    printf("Hello , Welcome to The Bit Coin World ");
    name *new_data = NULL;
    new_data = allocateData();
    printf("Enter Your Age [18+ only allowed the BinCoin World] , And Enter you BTCOIN user ID (add up on end with .89304)\n");
    if (scanf("%d",&new_data->age) && scanf("%f",&new_data->id)){
        getData(new_data);
    }


}

































// #include<stdio.h>
// int main(){
//     int x = 0;
//     if (x = 5) {
//         printf("One");
//     } else {
//         printf("Two");
//     }
// // int x = 5;
// // if (x > 3)
// //     printf("High
// // ");
// // else
// //     printf("Low
// // ");
//  }
