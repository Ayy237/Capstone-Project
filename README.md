# Calendar Management System
This is a simple calendar management system built in C. It lets users create, view, update, and delete events using a command-line interface. All data is saved in a text file so it stays even after you close the program.

## Features
Add new events with an ID  
View all events  
Edit event details (title, date, time)  
Delete events by ID  
Data is saved in a file (doesn’t disappear after closing)  
Simple and easy-to-use menu  
Basic error handling  

## File Structure
main.c - Handles the menu and user interaction  
event.c - Contains all the event functions (add, edit, delete, etc.)  
event.h - Struct and function declarations  
Makefile - Used to compile the program  
events.txt - Stores all event data (created automatically)  

## Event Fields
Each event includes:

ID  
Title (up to 100 characters)  
Date (YYYY-MM-DD)  
Time (HH:MM)  

## Menu Options
=== Calendar Management System ===  
1. Add Event  
2. View Events  
3. Edit Event  
4. Delete Event  
5. Exit  

## Compilation

Using Makefile:
make  
make clean  

Or manually:
gcc -Wall -o calendar main.c event.c  

## How to Run

./calendar  

## Sample Test Cases

### Test Case 1: Adding Events
Run the program  
Choose option 1  
Enter:
ID: 1  
Title: Meeting  
Date: 2026-05-10  
Time: 14:00  

Expected: Event gets added  

---

### Test Case 2: Viewing Events
Choose option 2  

Expected: All events show up  

---

### Test Case 3: Editing Event
Choose option 3  
Enter event ID  
Update info  

Expected: Event updates correctly  

---

### Test Case 4: Deleting Event
Choose option 4  
Enter event ID  

Expected: Event gets removed  

---

### Test Case 5: Data Persistence
Add some events  
Exit program  
Run it again  
Choose option 2  

Expected: Events are still there  

---

### Test Case 6: ID-Based Actions
Add multiple events  
Delete one  
Add another  

Expected: IDs stay consistent  

---

### Test Case 7: Error Handling
Try editing or deleting an ID that doesn’t exist  

Expected: Shows error message  

---

## Data Storage Format

Data is stored in a simple comma-separated format:

id,title,date,time  

Example:

1,Meeting,2026-05-10,14:00  
2,Doctor Appointment,2026-05-11,09:00  

---

## Key Features

### ID System
Each event uses an ID so it’s easy to find and update  

### File Storage
All data is saved in a file, so nothing gets lost  

### Simple Design
The program is lightweight and easy to use  

---

## Limitations
No GUI (only runs in terminal)  
Basic input validation  
No conflict checking (events can overlap)  
Not built for large-scale use  
No networking features  

---

## Future Improvements
Add conflict detection for overlapping events  
Use linked lists or dynamic memory  
Add networking (socket feature)  
Allow import/export (CSV or JSON)  
Build a GUI version  
Improve validation and error handling  
