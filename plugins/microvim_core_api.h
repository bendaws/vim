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

void quitMicrovim(lua_State *L) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    exit(0);
}

void openFile(lua_State *L) {
    char* filepath = lua_tostring(L, 1);
    editorOpen(filepath);
}

void saveFile(lua_State *L) {
    editorSave();
}

int luaopen_microvim(lua_State *L) {
    lua_pushcfunction(L, vimstatus);
    lua_pushcfunction(L, vimprompt);

    lua_pushcfunction(L, quitMicrovim);
    lua_pushcfunction(L, openFile);
    lua_pushcfunction(L, saveFile);

    return 1;
}

void load_plugin(char* script_path)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	if(luaL_loadfile(L, script_path))
		err_exit(L, "luaL_loadfile failed.\n");

	if(lua_pcall(L, 0, 0, 0))
		editorSetStatusMessage(("plugin \"%s\" failed to load", script_path));

	lua_close(L);

	return 0;
}