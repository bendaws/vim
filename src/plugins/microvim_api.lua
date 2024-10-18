--[[
THIS WRAPS OVER THE ESSENTIALS!
Please see plugins.c for the real code.
]]

local microvim_core_api = require("@microvim@")

local microvim_api = {}

function microvim_api.setstatus(text)
    microvim_core_api.vimstatus(text)
end

function microvim_api.query(text)
    return microvim_core_api.vimprompt(text)
end