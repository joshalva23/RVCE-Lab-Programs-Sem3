#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void list_directory(const char *path, int lflag, int aflag) {
    DIR *directory;
    struct dirent *entry;
    struct stat fileStat;

    directory = opendir(path);
    if (directory == NULL) {
        perror("Error: Could not open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (!aflag && entry->d_name[0] == '.')
            continue;
        if (lflag) {
            char filePath[1000];
            strcpy(filePath, path);
            strcat(filePath, "/");
            strcat(filePath, entry->d_name);
            if (lstat(filePath, &fileStat) < 0)
                perror("lstat");
            else {
                printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
                printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
                printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
                printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
                printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
                printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
                printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
                printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
                printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
                printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
                printf("  %ld ", fileStat.st_nlink);
                struct passwd *pw = getpwuid(fileStat.st_uid);
                struct group *gr = getgrgid(fileStat.st_gid);
                printf(" %s %s", pw->pw_name, gr->gr_name);
                printf(" %ld ", fileStat.st_size);
                char time[100];
                strftime(time, sizeof(time), "%b %d %H:%M", localtime(&fileStat.st_mtime));
                printf(" %s ", time);
            }
        }
        printf("%s\n", entry->d_name);
    }

    closedir(directory);
}

int main(int argc,char *argv[]){
    
    return 0;
}


