/*
 * v0.0.1 - Copyright 2024 David Reed - All Rights Reserved
 * Originally created by OxCUBE (2020).
 * NOTICE: All redistributions of the following code must explicitly state what was modified by the end user
 * and the names 'David Reed' and '0xCUBE' must be mentioned in the credits of the public repository.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum TYPE { REGULAR, LTTSTORE, FLEX, HELP };

// Variables used in the script
bool should_run = true;
enum TYPE type = REGULAR;
const char *bold = "\033[1m";
const char *normal = "\033[0m";

// Arbitrary colors to be used for text color. Default is used if not put as a command-line argument.
const char *RED = "\033[38;5;1m";
const char *GREEN = "\033[38;5;2m";
const char *YELLOW = "\033[38;5;3m";
const char *BLUE = "\033[38;5;4m";
const char *MAGENTA = "\033[38;5;5m";
const char *CYAN = "\033[38;5;6m";

const char *color = "";

void set_color(const char *arg) {
    if (strcmp(arg, "red") == 0) {
        color = RED;
    } else if (strcmp(arg, "green") == 0) {
        color = GREEN;
    } else if (strcmp(arg, "yellow") == 0) {
        color = YELLOW;
    } else if (strcmp(arg, "blue") == 0) {
        color = BLUE;
    } else if (strcmp(arg, "magenta") == 0) {
        color = MAGENTA;
    } else if (strcmp(arg, "cyan") == 0) {
        color = CYAN;
    } else {
        should_run = false;
        printf("Invalid color. Please select a color from: (red, green, yellow, blue, magenta, cyan).\n");
    }
}

void set_type(const char *arg) {
    if (strcmp(arg, "--regular") == 0) {
        type = REGULAR;
    } else if (strcmp(arg, "--lttstore") == 0 || strcmp(arg, "--lttstore.com") == 0) {
        type = LTTSTORE;
    } else if (strcmp(arg, "--flex") == 0) {
        type = FLEX;
    } else if (strcmp(arg, "--help") == 0) {
        type = HELP;
    }
}

int main(int argc, char *argv[]) {
    // Iterate through all command line arguments and see if any of them are valid
    int x = 0;
    for (int i = 1; i < argc; i++) {
        if (x >= 2) {
            printf("Too many arguments passed (max is 2; 1 for color (i.e. green), 1 for type (i.e. --regular))\n");
            return 1;
        } else if (strncmp(argv[i], "--", 2) == 0) {
            set_type(argv[i]);
            x++;
        } else {
            set_color(argv[i]);
            x++;
        }
    }

    if (should_run) {
        // Default nofetch output
        if (type == REGULAR) {
            system("clear");
            printf("%s\n", color);
            printf(" __      _    _______    _______   _______   _________    ________   _       _\n");
            printf("| | \\   | |  / _____ \\  |  _____| |  _____| |___   ___|  / _______| | |     | |\n");
            printf("| |\\ \\  | | | |     | | | |___    | |___        | |     | |         | |_____| |\n");
            printf("| | \\ \\ | | | |     | | |  ___|   |  ___|       | |     | |         |  _____  |\n");
            printf("| |  \\ \\| | | |     | | | |       | |           | |     | |         | |     | |\n");
            printf("| |   \\ | | | |_____| | | |       | |_____      | |     | |_______  | |     | |\n");
            printf("|_|    \\__|  \\_______/  |_|       |_______|     |_|      \\________| |_|     |_|\n");
            printf("\n");
        // LTTstore.com nofetch output
        } else if (type == LTTSTORE) {
            system("clear");
            printf("%s\n", color);
            printf(" _         _________   _________    ________   _________    _______    _______    _______         ________    _______    _____________\n");
            printf("| |       |___   ___| |___   ___|  /  ______| |___   ___|  / _____ \\  |  ____  \\ |  _____|       / _______|  / _____ \\  |  ___   ___  |\n");
            printf("| |           | |         | |     |  |____        | |     | |     | | | |____| | | |___         | |         | |     | | | |   | |   | |\n");
            printf("| |           | |         | |      \\______ \\      | |     | |     | | | _______/ |  ___|        | |         | |     | | | |   | |   | |\n");
            printf("| |           | |         | |             | |     | |     | |     | | | | \\ \\    | |            | |         | |     | | | |   | |   | |\n");
            printf("| |______     | |         | |      _______| |     | |     | |_____| | | |  \\ \\   | |_____    _  | |_______  | |_____| | | |   | |   | |\n");
            printf("|________|    |_|         |_|     |________/      |_|      \\_______/  |_|   \\_\\  |_______|  |_|  \\________|  \\_______/  |_|   |_|   |_|\n");
            printf("\n");
        // Flex output to flex the hardware you wish you had
        } else if (type == FLEX) {
            system("clear");
            printf("%s", color);
            printf("%s%sOS:%s AmogOS\n", bold, RED, normal);
            printf("%s%sHost:%s Grandma's Computer\n", bold, RED, normal);
            printf("%s%sUptime:%s 69 years, 420 days\n", bold, RED, normal);
            printf("%s%sCPU:%s AMD Ryzen Threadripper 6990X (420) @ 6.90GHz\n", bold, RED, normal);
            printf("%s%sGPU:%s NVIDIA RTX 6090 1024 GB\n", bold, RED, normal);
            printf("%s%sMemory:%s 0.0000001MiB / 4300800MiB\n", bold, RED, normal);
            printf("\n");
        // Help...obviously
        } else if (type == HELP) {
            system("clear");
            printf("%s\n", color);
            printf("nofetch is the best fetch script ever. Don't argue.\n");
            printf("You downloaded it. It's yours now. Here's help if you need it ;)\n");
            printf("\n");
            printf("Syntax: nofetch --OPTION COLOR\n");
            printf("Options:\n");
            printf("    Colors:\n");
            printf("        red green blue yellow magenta cyan\n");
            printf("\n");
            printf("    Options:\n");
            printf("        --regular     Standard nofetch output\n");
            printf("        --lttstore    Prints 'lttstore.com' in nofetch fashion\n");
            printf("        --flex        Lets you flex on your friends because I know the skids want that\n");
            printf("        --help        Prints this message (but I guess you already figured that out)\n");
            printf("\n");
        }
    }
    return 0;
}
