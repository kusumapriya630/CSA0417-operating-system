
43 lines (33 loc) · 768 Bytes
#include <stdio.h>
#include <string.h>

#define MAX_FILES 100

struct file {
    char name[20];
};

struct directory {
    char name[20];
    struct file files[MAX_FILES];
    int num_files;
};

int main() {
    struct directory cse;
    strcpy(cse.name, "CSE");
    cse.num_files = 0;

    
    struct file fileA, fileB, fileC;
    strcpy(fileA.name, "A");
    strcpy(fileB.name, "B");
    strcpy(fileC.name, "C");

    cse.files[cse.num_files++] = fileA;
    cse.files[cse.num_files++] = fileB;
    cse.files[cse.num_files++] = fileC;

    
    printf("Directory: %s\n", cse.name);
    for (int i = 0; i < cse.num_files; i++) {
        printf("File %d: %s\n", i+1, cse.files[i].name);
    }

    return 0;
}
/* OUTPUT
Directory: CSE
File 1: A
File 2: B
File 3: C */

