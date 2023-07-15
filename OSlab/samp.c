#define _DEFAULT_SOURCE
#include<stdio.h>
//#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
int main(int argc, char* argv[])
{
    DIR *d;
    struct dirent *de;
    struct dirent **filelist;
    char P[10] = "rwxrwxrwx", AP[10];
    char time[26];
    struct group *g;
    struct passwd *p;
    struct tm *t;
    struct stat buf;
    int j;
    int n;
    n = scandir(".",&filelist,NULL, alphasort);
    //d = opendir(".");
    //while((de = readdir(d)) != NULL)
    for(int i = 0; filelist[i] != NULL ; i++)
    {
        de = filelist[i];
        stat(de->d_name, &buf);
        if(S_ISDIR(buf.st_mode))
            printf("d");
        else if(S_ISREG(buf.st_mode))
            printf("-");
        else if(S_ISCHR(buf.st_mode))
            printf("c");
        else if(S_ISBLK(buf.st_mode))
            printf("b");
        else if(S_ISFIFO(buf.st_mode))
            printf("p");
        else if(S_ISLNK(buf.st_mode))
            printf("l");
        else if(S_ISSOCK(buf.st_mode))
            printf("s");
        for(int i = 0, j = (1 << 8); i < 9; i++, j >>= 1)
            AP[i] = (buf.st_mode & j) ? P[i] : '-';
        AP[9] = '\0';
        printf("%s\t",AP);
        printf("%ld\t",buf.st_nlink);
        p = getpwuid(buf.st_uid);
        printf("%s\t", p->pw_name);
        g = getgrgid(buf.st_gid);
        printf("%s\t",g->gr_name);
        t = localtime(&buf.st_mtime);
        strftime(time, sizeof(time), "%b %d %H:%M", t);
        printf("%s\t", time);
        printf("%s",de->d_name);
        printf("\n");
    }
    //closedir(d);

}