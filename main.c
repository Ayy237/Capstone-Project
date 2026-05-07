#include <stdio.h>
#include "event.h"

int main() {
    int choice;

    while (1) {
        printf("\n=== Calendar System ===\n");
        printf("1. Add Event\n");
        printf("2. View Events\n");
        printf("3. Edit Event\n");
        printf("4. Delete Event\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEvent();
                break;
            case 2:
                viewEvents();
                break;
            case 3:
                editEvent();
                break;
            case 4:
                deleteEvent();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}