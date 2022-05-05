#pragma once

#include <bits/stdc++.h>
#include "card.h"
#include "effects.h"
#include "player.h"
#include "field.h"


struct Ability {
    std::string name = "default ability";
    int change_HP_on = 0;
    int change_damage_on = 0;
    int add_mana = 0;
    bool hero_friendly;
    bool hero_bad;
    std::vector<std::string> to_summon;

    Ability() {
        // Construction of Ability
    }
};