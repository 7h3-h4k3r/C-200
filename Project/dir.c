#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
    DIR *direct;
    struct dirent *dir;
    direct = opendir("../");
    if (direct==NULL){
        printf("ERROR [*] Dir is not Found");
        return -1;
    }

    while ((dir = readdir(direct)) != NULL)
    {
        printf("%s \n",dir->d_name);
    }
    closedir(direct);
    return 0;
    
}