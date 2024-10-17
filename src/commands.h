#include "headers.h"

#ifndef COMMANDS_H_
#define COMMANDS_H_

void command(char query[75]) {
    if (query == "w") {
        editorSave();
    } else if (query == "q") {
        if (E.dirty) {
            editorSetStatusMessage("File has unsaved changes. Use :q! to quit with quit, :w to save.");
        } else {
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            exit(0);
        }
    } else if (query == "q!") {
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        exit(0);
    } else if (query == "git") {
        editorSetStatusMessage("Git repository: https://github.com/bendaws/microvim");
    } else {
        editorSetStatusMessage("Unknown command :%s", query);
    }
}

void sendtothepit(char *query, int key) {
    if (key == '\r') {
        command(query);
        free(query);
    }
}

void command_bar() {
    char *query = editorPrompt(":%s", sendtothepit);
}

#endif