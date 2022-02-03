#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE_ 1024

int replace_char(char text[BUFFER_SIZE_], char search, char replace) {
    int count = 0;

    for (int i = 0; i < strlen(text); i++) {       
        if (text[i] == search) {
            text[i] = replace;
            count++;
        }
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    return count;
}

int main(int argc, char *argv[5]) {
    if (argc != 5) {
        printf("Usage: ./a.out src.txt dest.txt search_char replace_char\n");
        return 1;
    }

    FILE *srcFile = {0}, *destFile = {0};
    int replacements = 0;
    
    if(!access(argv[1], F_OK)) {
        srcFile = fopen(argv[1], "r");
    } else {
        printf("SOURCE FILE DOES NOT EXIST.\n");
        return 1;
    }

    if (access(argv[2], F_OK)) {
        destFile = fopen(argv[2], "w");  
    } else {
        printf("DESTINATION FILE EXISTS.\n");
        return 1;
    }
    

    while(1) {
        char buffer[BUFFER_SIZE_] = {0};
        fgets(buffer, BUFFER_SIZE_, srcFile);

        replacements += replace_char(buffer, *argv[3], *argv[4]);

        fprintf(destFile, "%s\n", buffer);
        
        if(feof(srcFile)){
            break;
        }
    }

    printf("Copying %s into %s\n%d characters changed.\n", argv[1], argv[2], replacements);
    fclose(srcFile);
    fclose(destFile);
    return 0;
}