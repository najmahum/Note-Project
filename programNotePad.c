#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

int main(){
    FILE *file;
    char filename[100];
    char data[10000];
    int choices, YesOrNo, i=0;
    char list[1000][100];
    while(1){
        printf("\nChoose what you want to do (1/2/3/4/5/6)\n");
        printf("1. New Notepad\n");
        printf("2. Edit Notepad\n");
        printf("3. Read Notepad\n");
        printf("4. Delete Notepad\n");
        printf("5. List File\n");
        printf("6. Exit\n");
        scanf("%d", &choices);
        while(getchar() != '\n');
        switch(choices){
            case 1:
                printf("Input file name: ");
                scanf("%99s", filename);
                file = fopen(filename, "w");
                strcpy(list[i++], filename);
                printf("\n\e[0;93mWrite something on your NotePad\n");
                printf("Write 'EXIT' with capslock and an enter to close the NotePad\e[0m\n\n");
                while(1){
                    fgets(data, sizeof(data), stdin);
                    if(strcmp(data, "EXIT\n") == 0){
                        break;
                    }
                    fputs(data, file);
                }
                printf("\e[0;94mFile %s has been created successfully\e[0m\n", filename);
                fclose(file);
                break;
            case 2:
                printf("Input file name: ");
                scanf("%99s", filename);
                file = fopen(filename, "r+");
                if(file == NULL){
                    printf("There's no file names %s\n", filename);
                    break;
                } else {
                    printf("\n\e[0;93mWrite something on your NotePad\n");
                    printf("Write 'EXIT' with capslock and an enter to close the NotePad\e[0m\n\n");
                    printf("\n      %s\n", filename);
                    while (fgets(data, sizeof(data), file) != NULL) {
                        printf("%s", data);
                    }
                    fseek(file, 0, SEEK_END);
                    while(1){
                        fgets(data, sizeof(data), stdin);
                        if(strcmp(data, "EXIT\n") == 0){
                            break;
                        }
                        fputs(data, file);
                    }
                }
                printf("\e[0;94mFile %s has been edited successfully\e[0m\n", filename);
                fclose(file);
                break;
            case 3:
                printf("Input file name: ");
                scanf("%99s", filename);
                file = fopen(filename, "r");
                if(file == NULL){
                    printf("There's no file names %s\n", filename);
                    break;
                }
                printf("\n      %s\n", filename);
                while (fgets(data, sizeof(data), file) != NULL) {
                    printf("%s", data);
                }
                fclose(file);
                break;
            case 4:
                printf("Input file name: ");
                scanf("%99s", filename);
                printf("Are you sure want to delete %s?\n", filename);
                printf("1. Yes\n2. No\n");
                scanf("%d", &YesOrNo);
                if(YesOrNo ==  1){
                    if(remove(filename)==0){
                        for (int j = 0; j < i; j++) {
                            if (strcmp(list[j], filename) == 0) {
                                list[j][0] = '\0';
                            }
                        }
                        printf("\e[0;94mFile %s has been deleted successfully\e[0m\n", filename);
                    } else {
                        printf("\e[0;91mFailed to delete file %s\e[0m\n", filename);
                    }
                } else {
                    printf("\e[0;94mOkay! Cancelling delete file %s\e[0m\n", filename);
                    break;
                }
                break;
            case 5:
                printf("List of available files:\n");
                for (int j = 0; j < i; j++) {
                    printf("%s\n", list[j]);
                }
                break;
            case 6:
                printf("\e[0;94mThank you for using NotePad\e[0m\n");
                exit(0);
            default:
                printf("\e[0;91mSorry, the number you input is invalid please try again\e[0m\n");
                break;
        }
    }
}