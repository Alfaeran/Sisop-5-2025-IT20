#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

void shell() {
    char buf[128];
    char cmd[64];
    char arg[2][64];

    printString("Welcome to EorzeOS!\n");

    while (true) {
        printString("> ");
        readString(buf);
        clear(cmd, 64);
        clear(arg[0], 64);
        clear(arg[1], 64);

        parseCommand(buf, cmd, arg);

        if (strcmp(cmd, "echo")) {
            printString(arg[0]);
            printString("\n");
        } else if (strcmp(cmd, "clear")) {
            clearScreen();
        } else if (strcmp(cmd, "exit")) {
            printString("Goodbye.\n");
            break;
        } else {
            printString("Unknown command\n");
        }
    }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
    int i = 0, j = 0, k = 0, mode = 0;
    while (buf[i] != '\0') {
        if (buf[i] == ' ') {
            if (mode == 0) {
                cmd[j] = '\0';
                mode = 1;
                j = 0;
            } else if (mode == 1) {
                arg[0][j] = '\0';
                mode = 2;
                j = 0;
            }
        } else {
            if (mode == 0) cmd[j++] = buf[i];
            else if (mode == 1) arg[0][j++] = buf[i];
            else if (mode == 2) arg[1][j++] = buf[i];
        }
        i++;
    }

    if (mode == 0) cmd[j] = '\0';
    else if (mode == 1) arg[0][j] = '\0';
    else if (mode == 2) arg[1][j] = '\0';
}
