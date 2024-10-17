#ifndef POINT_H
#define POINT_H

#include "mvim.h"

typedef struct point {
  int y, x;
} point;

point point_W(editorConfig e);

#endif
