#pragma once

#include <bits/stdc++.h>
#include "card.h"
#include "effects.h"
#include "player.h"
#include "field.h"


struct Ability {
    std::string name;
    int change_HP_on;
    int set_HP_on;
    int change_damage_on;
    int set_damage_on;
    int set_mana;

    Ability() {
        // Construction of Ability
    }
};