#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char *argv[]) {
    printf("---------------------------------------- \n");
    printf("|               CFinder                |\n");
    printf("---------------------------------------- \n");

    if (argc < 3) {
        int choice = 0;
        printf("Выберите один из вариантов:\n");
        printf("1 - Поиск по директории\n");
        printf("2 - Поиск по диску\n");
        printf("3 - Поиск по имени файла\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char directory[256], query[256], extension[50];
                printf("Введите директорию: ");
                scanf("%s", directory);
                printf("Введите поисковый запрос: ");
                scanf("%s", query);
                printf("Введите расширение (или оставьте пустым): ");
                scanf("%s", extension);
                search_directory(directory, query, *extension ? extension : NULL);
                break;
            }
            case 2:
                // TODO: реализовать поиск по диску
                printf("Поиск по диску пока не реализован.\n");
                break;
            case 3: {
                char filename[256];
                printf("Введите имя файла: ");
                scanf("%s", filename);
                // TODO: реализовать поиск по имени
                printf("Поиск по имени \"%s\" пока не реализован.\n", filename);
                break;
            }
            default:
                printf("Неверный выбор.\n");
                break;
        }
    } else {
        const char *directory = argv[1];
        const char *query = argv[2];
        const char *extension = (argc > 3) ? argv[3] : NULL;
        search_directory(directory, query, extension);
    }

    printf("\nПоиск завершён.\n");
    return 0;
}
