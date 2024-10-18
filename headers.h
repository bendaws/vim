#ifndef HEADERS
#define HEADERS

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

char* mode = "-- NORMAL --";

enum editorKey {
    BACKSPACE = 127,
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,
    DEL_KEY,
    HOME_KEY,
    END_KEY,
    PAGE_UP,
    PAGE_DOWN,
    ESCAPE_KEY,
    MODE_KEY
};

typedef struct erow {
    int idx;
    int size;
    int rsize;
    char *chars;
    char *render;
    unsigned char *hl;
    int hl_open_comment;
} erow;

struct editorConfig {
    int cx, cy;
    int rx;
    int rowoff;
    int coloff;
    int screenrows;
    int screencols;
    int numrows;
    erow *row;
    int dirty;
    char *filename;
    char statusmsg[80];
    int filetype_exists;
    time_t statusmsg_time;
    struct editorSyntax *syntax;
    struct termios orig_termios;
};

struct editorConfig E;

#define MICROVIM_VERSION "0.0.1"
#define MICROVIM_TAB_STOP 4
#define MICROVIM_QUIT_TIMES 3

#include "fallback.h" //
#include "display.h" //
#include "system.h" //
#include "terminal.h" //
#include "key.h" //
#include "row.h" //
#include "syntax.h" //
#include "find.h" //
#include "file.h" //
#include "char.h" //
#include "commands.h" //

#define CTRL_KEY(k) ((k) & 0x1f)

int interruptMode = 0;

#endif