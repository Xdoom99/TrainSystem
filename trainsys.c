#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>


void initNcurses() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}


void closeNcurses() {
    endwin();
}


void displayMessageAndWait(const char *message) {
    mvprintw(LINES / 2, (COLS - strlen(message)) / 2, "%s", message);
    refresh();
    getch();
    clear();
}


int displayMenu() {
    clear();
    printw("Railway Reservation System\n");
    printw("1. Add Train\n");
    printw("2. Display Available Trains\n");
    printw("3. Reserve a Seat\n");
    printw("4. Exit\n");
    printw("Enter your choice: ");

    int choice;
    scanw("%d", &choice);
    return choice;
}

int main() {

    initNcurses();

    int choice;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                addTrain();
                displayMessageAndWait("Train added successfully!");
                break;
            case 2:
                displayTrains();
                displayMessageAndWait("");
                break;
            case 3:
                reserveSeat();
                break;
            case 4:
                printw("Exiting the program. Goodbye!\n");
                break;
            default:
                displayMessageAndWait("Invalid choice. Please try again.");
        }

    } while (choice != 4);


    closeNcurses();

    return 0;
}
