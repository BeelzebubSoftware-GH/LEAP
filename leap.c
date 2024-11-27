#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <getopt.h>
#include "headers/leap_header.h"

void clearBuffer() {
    const char* homedir = getenv("HOME");
    char bufferclear[256];
    snprintf(bufferclear, sizeof(bufferclear), "rm -rf %s/.leapbuffer", homedir);
    system(bufferclear);
    snprintf(bufferclear, sizeof(bufferclear), "mkdir %s/.leapbuffer", homedir);
    system(bufferclear);
}

int silent = 0;  // Global flag for silent mode

int main(int argc, char *argv[]) {
    // Define long options
    struct option long_options[] = {
        {"silent", no_argument, &silent, 1},  // `no_argument` means it doesn't take a parameter
        {0, 0, 0, 0}  // End of array
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "s", long_options, NULL)) != -1) {
        switch (opt) {
            case 's':
                silent = 1;
                break;
            case 0:  // For long options that set a flag
                break;
            case '?':
                printError(0, "Usage: leap run [flags] <package>\n");
                return 1;
        }
    }

    if (optind < argc && strcmp(argv[optind], "run") == 0) {
        if (argc - optind != 2) {
            printError(0, "Command \"run\" requires 1 argument, but %d were given.", argc - optind - 1);
            return 1;
        }
        if (!silent) {printf("Linux Executable Archive Program. © 2024 Beelzebub Software\n\n");}
        clearBuffer();

        if (leapRun(argv[optind + 1], silent)) {
            printError(1, "Failed to load metadata.");
            return 1;
        }
    } else {
        printError(0, "Usage: leap run [flags] <package>\n");
        return 1;
    }

    return 0;
}
