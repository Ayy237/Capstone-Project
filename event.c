#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "event.h"

#define FILE_NAME "events.txt"

void addEvent() {
    FILE *file = fopen(FILE_NAME, "a");

    Event e;

    printf("Enter ID: ");
    scanf("%d", &e.id);

    printf("Enter Title: ");
    scanf(" %[^\n]", e.title);

    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", e.date);

    printf("Enter Time (HH:MM): ");
    scanf("%s", e.time);

    fprintf(file, "%d,%s,%s,%s\n", e.id, e.title, e.date, e.time);

    fclose(file);

    printf("Event added!\n");
}

void viewEvents() {
    FILE *file = fopen(FILE_NAME, "r");

    Event e;

    printf("\n--- Events ---\n");

    while (fscanf(file, "%d,%99[^,],%19[^,],%19[^\n]\n",
                  &e.id, e.title, e.date, e.time) != EOF) {
        printf("ID: %d | %s | %s | %s\n",
               e.id, e.title, e.date, e.time);
    }

    fclose(file);
}

void editEvent() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    int id, found = 0;
    Event e;

    printf("Enter ID to edit: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%99[^,],%19[^,],%19[^\n]\n",
                  &e.id, e.title, e.date, e.time) != EOF) {

        if (e.id == id) {
            found = 1;

            printf("Enter new Title: ");
            scanf(" %[^\n]", e.title);

            printf("Enter new Date: ");
            scanf("%s", e.date);

            printf("Enter new Time: ");
            scanf("%s", e.time);
        }

        fprintf(temp, "%d,%s,%s,%s\n",
                e.id, e.title, e.date, e.time);
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("Event updated!\n");
    else
        printf("Event not found.\n");
}

void deleteEvent() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    int id, found = 0;
    Event e;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%99[^,],%19[^,],%19[^\n]\n",
                  &e.id, e.title, e.date, e.time) != EOF) {

        if (e.id == id) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d,%s,%s,%s\n",
                e.id, e.title, e.date, e.time);
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("Event deleted!\n");
    else
        printf("Event not found.\n");
}