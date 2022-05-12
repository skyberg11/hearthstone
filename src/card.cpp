#pragma once

#include "card.h"

Card::Card(std::string name, CardType ct, 
    size_t mana_cost, Ability ability):
        name(name),
        card_type(ct),
        mana_cost(mana_cost),
        ability(ability)
        {}

// Card::Card(std::string name, size_t mana_cost, int life, 
//         size_t damage, Ability ability):
//         Card(name, CardType::monster, mana_cost, ability)
//     {}

 MonsterCard::MonsterCard(std::string name, size_t mana_cost, int life, 
        size_t damage, Ability ability):
        Card(name, CardType::monster, mana_cost, ability),
        Mortal(life, damage, nullptr)
    {}

 void MonsterCard::ExecuteAbility() {
        if(ability.hero_friendly) {
            Game::ChangeHpON(reinterpret_cast<Mortal*>(opposite), ability.change_HP_on);
            Game::ChangeDamageOn(reinterpret_cast<Mortal*>(opposite), ability.change_damage_on);
            Game::AddMana(opposite, ability.add_mana);
        }
        if(ability.hero_bad) {
            Game::ChangeHpON(reinterpret_cast<Mortal*>(opposite), ability.change_HP_on);
            Game::ChangeDamageOn(reinterpret_cast<Mortal*>(opposite), ability.change_damage_on);
            Game::AddMana(opposite, ability.add_mana);
        }
 }

