#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdbool.h>

void walk_directory_tree(char *directory_path);
char *get_file_perms(char *path);

int main(void) {
    // Gets the current work directory path
    char path_buff[PATH_MAX];
    getcwd(path_buff, PATH_MAX);

    // Walks down directory tree starting from cwd
    walk_directory_tree(path_buff);
    return 0;
}


void walk_directory_tree(char *directory_path) {
    // Opens directory
    DIR *d = opendir(directory_path);
    struct dirent *dir_entry;
    
    // Iterates over each directory entry
    while ((dir_entry = readdir(d)) != NULL) {
        // Constructs path for directory entry
        int path_length = strlen(directory_path) + strlen(dir_entry->d_name) + 1;
        char *path = malloc(path_length + 1);
        snprintf(path, path_length + 1, "%s/%s", directory_path, dir_entry->d_name);
        
        // Retrieves permission bits for directory entry
        char *file_perms = get_file_perms(path);
        bool is_dir = false;
        if (file_perms != NULL) {
            is_dir = (file_perms[0] == 'd');
            printf("%s %s\n", file_perms, path);
            free(file_perms);
        } else {
            printf("File permissions not available for %s\n", path);
        }

        // Recurses into sub-directories
        if (is_dir && strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            walk_directory_tree(path);
        }

        free(path);
    }

    // Closes directory
    closedir(d);
}

// Translates file mode bits into a readable/printable string
char *get_file_perms(char *path) {
    struct stat s;
    if (stat(path, &s) != 0) {
        perror("");
        return NULL;
    }

    char *perms = malloc(11);
    mode_t perm_bits = s.st_mode;
    perms[0] = (S_ISDIR(perm_bits)) ? 'd' : '-';
    perms[1] = (perm_bits & S_IRUSR) ? 'r' : '-';
    perms[2] = (perm_bits & S_IWUSR) ? 'w' : '-';
    perms[3] = (perm_bits & S_IXUSR) ? 'x' : '-';
    perms[4] = (perm_bits & S_IRGRP) ? 'r' : '-';
    perms[5] = (perm_bits & S_IWGRP) ? 'w' : '-';
    perms[6] = (perm_bits & S_IXGRP) ? 'x' : '-';
    perms[7] = (perm_bits & S_IROTH) ? 'r' : '-';
    perms[8] = (perm_bits & S_IWOTH) ? 'w' : '-';
    perms[9] = (perm_bits & S_IXOTH) ? 'x' : '-';
    perms[10] = 0;

    return perms;
}
