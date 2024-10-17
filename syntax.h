#include <stdlib.h>

char *C_HL_extensions[] = {".c", ".h", NULL};
char *C_HL_keywords[] = {
    "switch", "if",      "while",  "for",     "break",     "continue",
    "return", "else",    "struct", "union",   "typedef",   "static",
    "enum",   "class",   "case",   "#define", "#include",  "int|",
    "long|",  "double|", "float|", "char|",   "unsigned|", "signed|",
    "void|", "const|", NULL};

char *CPP_HL_extensions[] = {".cpp", ".hpp", ".cc", ".hh", NULL};
char *CPP_HL_keywords[] = {
    "switch", "if",      "while",  "for",     "break",     "continue",
    "return", "else",    "struct", "union",   "typedef",   "static",
    "enum",   "class",   "case",   "#define", "#include",  "int|",
    "long|",  "double|", "float|", "char|",   "unsigned|", "signed|",
    "void|", "const|",  NULL};

char *Python_HL_extensions[] = {".py"};
char *Python_HL_keywords[] = {
    "True", "False", "None", "and", "as", "assert", "async", "await", "def",
    "del", "elif", "else", "break", "class", "continue", "except", "finally", "for",
    "from", "global", "if", "import", "in", "is", "lambda", "nonlocal", "not", "or",
    "pass", "raise", "return", "try", "while", "with", "yield", NULL};

char *Go_HL_extensions[] = {".go"};
char *Go_HL_keywords[] = {
    "const", "var", "func", "type", "import", "package",
    "chan", "interface", "map", "struct",
    "break", "case", "continue", "default", "else", "fallthrough", "for",
    "goto", "if", "range", "return", "select", "switch",
    "defer", "go", NULL};