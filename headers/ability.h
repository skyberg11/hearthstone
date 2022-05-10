#pragma once

#include <bits/stdc++.h>

struct Ability {
    std::string name = "default ability";
    int change_HP_on = 0;
    int change_damage_on = 0;
    int add_mana = 0;
    bool hero_friendly;
    bool hero_bad;

    Ability(std::string name, int change_HP_on, int change_damage_on,
    int add_mana, bool hero_friendly, bool hero_bad);
};