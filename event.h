#ifndef EVENT_H
#define EVENT_H

typedef struct {
    int id;
    char title[100];
    char date[20];
    char time[20];
} Event;

void addEvent();
void viewEvents();
void editEvent();
void deleteEvent();

#endif