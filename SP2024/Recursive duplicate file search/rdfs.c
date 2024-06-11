#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH 4096

typedef struct Node {
    char path[MAX_PATH];
    struct Node *next;
} Node;


int cmp_files_by_cont(const char *file1, const char *file2) {
    //read file for binary
    FILE *fp1 = fopen(file1, "rb");
    FILE *fp2 = fopen(file2, "rb");

    //compare
    int ch1, ch2;
    while ((ch1 = fgetc(fp1)) != EOF && (ch2 = fgetc(fp2)) != EOF) {
        if (ch1 != ch2) {
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
    }

    //check surplus char    
    int flag=0;
    if(fgetc(fp1) == EOF && fgetc(fp2) == EOF)
        flag=1;
    fclose(fp1);
    fclose(fp2);
    return flag;
}


const char* get_filename(const char* path) {
    //extract file name
    const char* fname = strrchr(path, '/');
    if (fname == NULL)
        fname = path;
    else
        fname++;
    return fname;
}
int cmp_files_by_name(const char *file1, const char *file2) {
    const char* fname1 = get_filename(file1);
    const char* fname2 = get_filename(file2);
    return strcmp(fname1, fname2) == 0; // compare
}


void free_nodes(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
void add_node(Node **head, const char *path) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->path, path);
    new_node->next = *head;
    *head = new_node;
}

void scan_dir(const char *dir_path, Node **file_list) {
    DIR *dp = opendir(dir_path);
    //error check
    if (!dp){
        if (errno == ENOENT)
            fprintf(stderr, "Warning: Directory %s does not exist!\n", dir_path);
        else if (errno == EACCES)
            fprintf(stderr, "Warning: No read permission to %s directory!\n", dir_path);
        else
            fprintf(stderr, "Error opening directory: %s\n", dir_path);
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dp))!=NULL) {
        //skip '.' and '..' files
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, ent->d_name);

        struct stat buf;
        if (stat(full_path, &buf) == -1) { // call stat
            perror("stat");
            continue;
        }

        if (S_ISDIR(buf.st_mode))
            scan_dir(full_path,file_list); // recursive search if cur file is directory
        else if (S_ISREG(buf.st_mode))
            add_node(file_list,full_path);
    }
    closedir(dp);
}

void find_dup_by_cont(Node *head) {
    for (Node *i = head; i != NULL; i = i->next) {
        int first = 1;
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (cmp_files_by_cont(i->path, j->path)) {
                if (first) {
                    printf("%s\n", i->path);
                    first = 0;
                }
                printf("%s\n", j->path);
            }
        }
        if (!first) {
            printf("\n");
        }
    }
}
void find_dup_by_name(Node *head) {
    for (Node *i = head; i != NULL; i = i->next) {
        int first = 1;
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (cmp_files_by_name(i->path, j->path)) {
                if (first) {
                    printf("%s\n", i->path);
                    first = 0;
                }
                printf("%s\n", j->path);
            }
        }
        if (!first) {
            printf("---\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-c] <directory1> [directory2] ...\n", argv[0]);
        return 1;
    }

    int flag = 0;
    if (strcmp(argv[1], "-c") == 0)
        flag=1;

    Node *file_list = NULL;
    if (flag) { // check dub contents
        for (int i = 2; i < argc; i++)
            scan_dir(argv[i],&file_list);
        find_dup_by_cont(file_list);
    } else { // check dup filename
        for (int i = 1; i < argc; i++)
            scan_dir(argv[i],&file_list);
        find_dup_by_name(file_list);
    }
    
    free_nodes(file_list);
    return 0;
}
