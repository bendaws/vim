/*
Experimental plugin support
Write em in lua :/
*/

#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"

#include "../headers.h"

void vimstatus(lua_State *L) {
    char* statusMessageText = lua_tostring(L, 1);
    editorSetStatusMessage(statusMessageText);
}

void *blank_fallback(char *query, int key) {}

void vimprompt(lua_State *L) {
    char* promptMessageText = lua_tostring(L, 1);
    lua_pushstring(L, editorPrompt(promptMessageText, blank_fallback));
}

int luaopen_microvim(lua_State *L) {
    lua_pushcfunction(L, vimstatus);
    lua_pushcfunction(L, vimprompt);

    return 1;
}