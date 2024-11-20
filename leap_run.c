#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "headers/leap_header.h"

int leapRun(const char* pkg_name) {
    // Variables for system commands and output
    char com[512];
    char output[256];
    FILE* fp;

    // Step 1: Extract the package to .leapbuffer
    snprintf(com, sizeof(com), "tar -xzf %s -C %s/.leapbuffer/", pkg_name, getenv("HOME"));
    printLog("Extracting %s to .leapbuffer...", pkg_name);
    if (system(com) != 0) {
        printError(0, "Failed to extract %s.", pkg_name);
        return 1;
    }

    // Step 2: Verify metadata.json exists
    snprintf(com, sizeof(com), "%s/.leapbuffer/metadata.json", getenv("HOME"));
    printLog("Checking existence of metadata.json...");
    if (access(com, F_OK) != 0) {
        printError(0, "metadata.json not found in .leapbuffer.");
        return 1;
    }

    // Step 3: Run the Python script to parse metadata.json
    snprintf(com, sizeof(com), "./.venv/bin/python3 ./__pycache__/leap_json_parse.cpython-312.pyc run");
    printLog("Running Python script to parse metadata.json...");
    fp = popen(com, "r");
    if (fp == NULL) {
        printError(1, "Failed to execute Python script.");
        return 1;
    }

    // Step 4: Read the output from the Python script
    if (fgets(output, sizeof(output), fp) == NULL) {
        printError(1, "Failed to retrieve output from Python script.");
        pclose(fp);
        return 1;
    }
    pclose(fp);

    // Step 5: Clean up the output and prepare to use it
    output[strcspn(output, "\n")] = '\0'; // Remove trailing newline
    snprintf(com, sizeof(com), "%s/.leapbuffer/%s", getenv("HOME"), output);
    printLog("Output from Python script: %s", output);

    // Step 6: Verify the file path from metadata exists (if required)
    if (access(com, F_OK) != 0) {
        printError(0, "File %s from metadata.json does not exist.", output);
        return 1;
    }

    // Step 7: Continue the program logic (e.g., executing the extracted file)
    printLog("Successfully processed metadata.json. Proceeding...");
    char runcom[512];
    snprintf(runcom, sizeof(runcom), "%s/.leapbuffer/%s", getenv("HOME"), output);
    printf("***\n\n\n");
    system(runcom);
    return 0;
    
}
