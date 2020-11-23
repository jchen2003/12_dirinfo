#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

int main(){
    int d_size;
    DIR *d = opendir(".");
    struct dirent *entry = readdir(d);

    printf("Statistics for directory: %s\n", entry->d_name);

    struct stat sb;
    printf("Directories:\n");
    while (entry!=NULL){
        stat(entry->d_name, &sb);
        if (S_ISDIR(sb.st_mode)){
            printf("\t%s\n",entry->d_name);
            d_size+=sb.st_size;
        }
        entry = readdir(d);
    }
    rewinddir(d);
    entry = readdir(d);

    printf("\nRegular files:\n");
    while (entry!=NULL){
        stat(entry->d_name, &sb);
        if (!S_ISDIR(sb.st_mode)){
            printf("\t%s\n",entry->d_name);
            d_size+=sb.st_size;
        }
        entry = readdir(d);
    }

    printf("\nTotal Diectory Size: %d Bytes\n",d_size);

}