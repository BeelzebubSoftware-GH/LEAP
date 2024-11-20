#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Full functions

void printError(int critical, const char* msg, ...) {
    fprintf(stderr, "\033[31m%s:\033[0m ", critical?"CRITICAL":"ERROR");
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    fprintf(stderr, "\n"); 
}

void printLog(const char* msg, ...) {
    fprintf(stderr, "\033[32mLOG:\033[0m ");
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    fprintf(stderr, "\n");
}

void printInfo(const char* msg, ...) {
    fprintf(stderr, "\033[34mINFO:\033[0m ");
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    fprintf(stderr, "\n");
}

void printWarning(const char* msg, ...) {
    fprintf(stderr, "\033[33mWARNING:\033[0m ");
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    fprintf(stderr, "\n");
}

