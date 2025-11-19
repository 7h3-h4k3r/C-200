#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <libgen.h>


/* 

get Last commit of it , git Using SHA 1 so its have 

a 160 bit , 40 byte 

*/
typedef struct hash  
{
    char *hash_value;

}githash;

struct githash *lastCommit(githash *path, char *head[]){
    FILE *file;
    path->hash_value = (char *)malloc(41 * sizeof(char*));
    strcpy(path->hash_value,"../.git/refs/heads");
    strcat(path->hash_value,"/main");
    file = fopen(path->hash_value,"r");
    printf("Get Last Commit :");
    while (fgets(path->hash_value, sizeof(path->hash_value), file) != NULL) {
        printf("%s", path->hash_value);
    }
    
}


int main(int argc , char *argv[]){
    githash *getHash;
    getHash = lastCommit(getHash,argv);
}













// int main()
// {
//     DIR *direct;
//     struct dirent *dir;
//     direct = opendir("../");
//     if (direct==NULL){
//         printf("ERROR [*] Dir is not Found");
//         return -1;
//     }

//     while ((dir = readdir(direct)) != NULL)
//     {
//         printf("%s \n",dir->d_name);
//     }
//     closedir(direct);
//     return 0;
    
// }