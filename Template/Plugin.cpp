#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
#include <Utils/PlayerMap.h>

playerMap<string> ORIG_NAME;

void PluginInit()
{
    Event::PlayerPreJoinEvent::subscribe([](Event::PlayerPreJoinEvent ev) {
        ORIG_NAME[(ServerPlayer*)ev.mPlayer] = ev.mPlayer->getRealName();
        return true;
        });
}

THook(string&, "?getNameTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ", ServerPlayer* x) {
    return ORIG_NAME.get(x);
}