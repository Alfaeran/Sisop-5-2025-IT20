#include "kernel.h"

void printString(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        interrupt(0x10, 0x0E00 + str[i], 0, 0, 0);
        i++;
    }
}

void readString(char *buf) {
    char c;
    int i = 0;

    while (1) {
        c = interrupt(0x16, 0, 0, 0, 0);
        if (c == 13) { // Enter
            buf[i] = '\0';
            printString("\r\n");
            break;
        } else if (c == 8) { // Backspace
            if (i > 0) {
                i--;
                printString("\b \b");
            }
        } else {
            buf[i++] = c;
            interrupt(0x10, 0x0E00 + c, 0, 0, 0);
        }
    }
}

void clearScreen() {
    int i;
    for (i = 0; i < 25 * 80; i++) {
        putInMemory(0xB800, i * 2, ' ');
        putInMemory(0xB800, i * 2 + 1, 0x07);
    }
}
