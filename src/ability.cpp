#pragma once

#include "ability.h"


Ability::Ability(std::string name, int change_HP_on, int change_damage_on,
int add_mana, bool hero_friendly, bool hero_bad) :
name(name), change_HP_on(change_HP_on), add_mana(add_mana), 
change_damage_on(change_damage_on), hero_friendly(hero_friendly), 
hero_bad(hero_bad) {}