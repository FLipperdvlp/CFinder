#include <stdio.h>
#include "FULL.h"

int main() {
    char filename[100];
    int _choice = 0;
    char option;

    printf("Please enter the name of the file and format (e.g. filename.txt): ");
    scanf("%s", filename);
    do {
        printf("Do you want to continue (y/n)?: ");
        getchar();
        scanf("%c", &option);
        switch (option) {
            case 'y':
                printf("Please enter the type of search: (1-C:, 2-D:, 3-another, 4-full): ");
                scanf("%d", &_choice);
                switch (_choice) {
                    case 1:
                        Search_Disk_C(filename);
                        break;
                    case 2:
                        Search_Disk_D(filename);
                        break;
                    case 3:
                        Search_Disk_Another(filename);
                        break;
                    case 4:
                        Search_Full(filename);
                        break;
                    default:
                        printf("Invalid search option.\n");
                        break;
                }
                break;
            case 'n':
                printf("Goodbye!\n");
                break;
            default:
                printf("Unknown command. Please enter y or n.\n");
                break;
        }
    } while (option != 'n');
    return 0;
}