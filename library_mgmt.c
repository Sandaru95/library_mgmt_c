#include <stdio.h>
FILE *fp;

int main(){
    fp = fopen("library.txt", "a+");
    if(fp == NULL){
        printf("Error reading the file");
        return 1;
    }
    fseek(fp, 0, SEEK_SET);

    char name[100];
    char font[100];
    char pages[100];
    while(fscanf(fp, "%s %s %s", name, font, pages) == 3){
        // printf("%s, %s, %s\n\n", name, font, pages);
    }

    printf("Welcome to Library Management System!\n");
    while (1)
    {
        fseek(fp, 0, SEEK_SET);
        int i;
        printf("1.Add Book\n");
        printf("2.Display Book Information\n");
        printf("3.Exit\n");

        scanf("%d", &i);

        if(i==1){
            char name[50];
            char font[50];
            int pages;
            char formattedString[100];

            printf("Proceeding to add Book\n");
            printf("Name: ");
            scanf("%s", name);
            printf("Font: ");
            scanf("%s", font);
            printf("Pages: ");
            scanf("%d", &pages);
            // Going to end of file
            fseek(fp, 0, SEEK_END);

            // Appending to file
            sprintf(formattedString, "\n%s %s %d", name, font, pages);

            fputs(formattedString, fp);
        }else if (i==2){
            char userSearch[50];
            // Going to the begging of the file
            fseek(fp, 0, SEEK_SET);

            printf("Proceeding to search Book Details\n");
            printf("Name: \n");
            scanf("%s", userSearch);

            while(fscanf(fp, "%s %s %s", name, font, pages) == 3){
                if(strcmp(userSearch, name) == 0){
                    printf("%s, %s, %s\n\n", name, font, pages);
                };
            }
        }else if (i==3){
            printf("Programme Quits\n");
            fclose(fp);
            break;
        }else{
            printf("Not Valid\n");
        }
        printf("\n\n--------------------------------------\n");
    }
    return 0;
}