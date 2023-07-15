#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <grp.h>
#include <string.h>
#include <pwd.h>
#include "colors.h"

int main(int argc, char *argv[])
{
    int BUFSIZE;
    struct dirent **namelist;
    int n;
    struct stat buf;
    char P[10] = "rwxrwxrwx", AP[10] = " ";
    struct passwd *p;
    struct group *g;
    struct tm *t;
    char time[26];
    char *path = ".";
    int j;
    char *absolute_path;
    
    if (argc == 2)
    {
        path = argv[1];
        BUFSIZE = sizeof(char)*strlen(argv[1])+256;
        absolute_path =(char*) malloc(BUFSIZE);
    }
    else{
        BUFSIZE = sizeof(char)+256;
        absolute_path = malloc(BUFSIZE);
    }
    n = scandir(path, &namelist, NULL, alphasort);
   
    if (n == -1)
    {
        printf(RED "Fatal Error:" RESET);
        printf(" No such directory found!!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; namelist[i] != NULL; i++)
    {
        absolute_path[0]='\0';
        snprintf(absolute_path, BUFSIZE,"%s/%s",path,namelist[i]->d_name);
        stat(absolute_path, &buf);
        if (S_ISDIR(buf.st_mode))
            printf("d");
        else if (S_ISREG(buf.st_mode))
            printf("-");
        else if (S_ISCHR(buf.st_mode))
            printf("c");
        else if (S_ISBLK(buf.st_mode))
            printf("b");
        else if (S_ISLNK(buf.st_mode))
            printf("l");
        else if (S_ISFIFO(buf.st_mode))
            printf("p");
        else if (S_ISSOCK(buf.st_mode))
            printf("s");
        for (int i = 0, j = (1 << 8); i < 9; i++, j >>= 1)
            AP[i] = (buf.st_mode & j) ? P[i] : '-';
        printf("%s", AP);
        printf("%5ld", buf.st_nlink);
        p = getpwuid(buf.st_uid);
        printf("\t%4.8s", p->pw_name);
        g = getgrgid(buf.st_gid);
        printf(" %4.8s", g->gr_name);
        printf(" %8ld ", buf.st_size);
        t = localtime(&buf.st_mtime);
        strftime(time, sizeof(time), "%b %d %H:%M", t);
        printf("%s\t", time);

        if (S_ISDIR(buf.st_mode))
        {
            printf(ORGE "%s" RESET, namelist[i]->d_name);
            printf("/");
        }
        else if (AP[2] == 'x' || AP[5] == 'x' || AP[7] == 'x')
        {
            printf(MAG "%s" RESET, namelist[i]->d_name);
            printf("*");
        }
        else
        {
            printf("%s", namelist[i]->d_name);
        }
        printf("\n");
        free(namelist[i]);
    }
    free(namelist);
    free(absolute_path);
    exit(EXIT_SUCCESS);
}