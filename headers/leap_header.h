#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


void printError(int critical, const char* msg, ...);

void printLog(const char* msg, ...);

void printInfo(const char* msg, ...);

void printWarning(const char* msg, ...);

int leapRun(const char* pkg_name, int silent);