#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "headers/leap_header.h"

void clearBuffer() {
    const char* homedir = getenv("HOME");
    char bufferclear[256];
    snprintf(bufferclear, sizeof(bufferclear), "rm -rf %s/.leapbuffer", homedir);
    system(bufferclear);
    snprintf(bufferclear, sizeof(bufferclear), "mkdir %s/.leapbuffer", homedir);
    system(bufferclear);
}

int main(int argc, char *argv[]) {
    printf("Linux Executable Archive Program. © 2024 Beelzebub Software\n\n");
    clearBuffer();
    if (argc == 3 && !strcmp(argv[1], "run")) {
        if (leapRun(argv[2])) {
            printError(1, "Failed to load metadata.");
            return 1;
        }
    }
    else if (argc != 3 && !strcmp(argv[1], "run")) {
        printError(0, "Command \"run\" requires 1 argument, but %d were given.", argc - 2);
        return 1;
    }
    return 0;
}