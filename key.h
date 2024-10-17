#include "headers.h"

#ifndef KEY_H_
#define KEY_H_

#define CTRL_KEYLOCAL(k) ((k) & 0x1f)

int editorReadKey() {
    int nread;
    char c;
    while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
        if (nread == -1 && errno != EAGAIN) die("read");
    }

    if (c == '\x1b') {
        char seq[3];

        if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
        if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';

        if (seq[0] == '[') {
        if (seq[1] >= '0' && seq[1] <= '9') {
            if (read(STDIN_FILENO, &seq[2], 1) != 1) return '\x1b';
            if (seq[2] == '~') {
            switch (seq[1]) {
                case '1': return HOME_KEY;
                case '3': return DEL_KEY;
                case '4': return END_KEY;
                case '5': return PAGE_UP;
                case '6': return PAGE_DOWN;
                case '7': return HOME_KEY;
                case '8': return END_KEY;
            }
            }
        } else {
            switch (seq[1]) {
            case 'A': return ARROW_UP;
            case 'B': return ARROW_DOWN;
            case 'C': return ARROW_RIGHT;
            case 'D': return ARROW_LEFT;
            case 'H': return HOME_KEY;
            case 'F': return END_KEY;
            }
        }
        } else if (seq[0] == 'O') {
        switch (seq[1]) {
            case 'H': return HOME_KEY;
            case 'F': return END_KEY;
        }
        }

        return '\x1b';
    } else {
        return c;
    }
}

void editorProcessKeypress() {
  static int quit_times = 3;

  int c = editorReadKey();

  switch (c) {
    case '\r':
      if (mode == "-- INSERT --") {
        editorInsertNewline();
      }

      break;

    case CTRL_KEYLOCAL('q'):
      if (mode == "-- NORMAL --") {
        if (E.dirty && quit_times > 0) {
        editorSetStatusMessage("WARNING!!! File has unsaved changes. "
          "Press Ctrl-Q %d more times to quit.", quit_times);
        quit_times--;
        return;
        }
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        exit(0);
      }
      break;

    case CTRL_KEYLOCAL('s'):
      if (mode == "-- NORMAL --") {
        editorSave();
      }
      editorSave();
      break;

    case HOME_KEY:
      E.cx = 0;
      break;

    case END_KEY:
      if (E.cy < E.numrows)
        E.cx = E.row[E.cy].size;
      break;

    case CTRL_KEYLOCAL('f'):
      editorFind();
      break;

    case BACKSPACE:
    case CTRL_KEYLOCAL('h'):
    case DEL_KEY:
      if (mode == "-- INSERT --") {
        if (c == DEL_KEY) editorMoveCursor(ARROW_RIGHT);
        editorDelChar();
      }
      break;

    case PAGE_UP:
    case PAGE_DOWN:
      {
        if (c == PAGE_UP) {
          E.cy = E.rowoff;
        } else if (c == PAGE_DOWN) {
          E.cy = E.rowoff + E.screenrows - 1;
          if (E.cy > E.numrows) E.cy = E.numrows;
        }

        int times = E.screenrows;
        while (times--)
          editorMoveCursor(c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
      }
      break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
      editorMoveCursor(c);
      break;
    
    case 'i':
      if (mode == "-- NORMAL --") {
        mode = "-- INSERT --";
      } else {
        editorInsertChar(c);
      }

      break;
    
    case '\x1b':
      if (mode == "-- INSERT --") {
        mode = "-- NORMAL --";
      }

      break;
    
    case ':':
      if (mode == "-- NORMAL --") {
        command_bar();
      } else {
        editorInsertChar(c);
      }

      break;

    default:
      if (mode == "-- INSERT --") {
        editorInsertChar(c);
      }
      break;
  }

  quit_times = 3;
}

#endif