#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int compare(const void *a, const void *b) {
    return strcmp((*(const struct dirent **)a)->d_name, (*(const struct dirent **)b)->d_name);
}

int main(int argc, char *argv[]) {
    char* path;
    struct dirent **entries;
    int n;

    if(argc < 2)
    {
        path = malloc(sizeof(char));
        path[0] = '.';
    }
    else
    {
        path = argv[1];
    }

    n = scandir(path, &entries, NULL, alphasort);
    if (n < 0) {
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", entries[i]->d_name);
    }

    while (n--) {
        free(entries[n]);
    }
    free(entries);
    return 0;
}
