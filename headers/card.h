#pragma once

#include <bits/stdc++.h>
#include "player.h"
#include "ability.h"

enum CardType {
    effect,
    monster
};

struct Card {
    std::string name;
    CardType card_type;
    size_t mana_cost;
    Ability ability;
    
    Card(std::string name, CardType ct, 
    size_t mana_cost, Ability ability);

    Card(std::string name, size_t mana_cost, int life, 
        size_t damage, Ability ability);

    friend void Game::ChangeHpON(Mortal* target, int value);
    friend void Game::SetHpOn(Mortal* target, int value);
    friend void Game::ChangeDamageOn(Mortal* target, int value);
    friend void Game::SetDamageOn(Mortal* target, int value);
    friend void Game::AddMana(Player* player, int value);
};

class MonsterCard : public Card, public Mortal {

    Player* ally;

    public:
    MonsterCard(std::string name, size_t mana_cost, int life, 
        size_t damage, Ability ability);

    void ExecuteAbility();

};

// struct EffectCard : public Card {

//     EffectCard():
//         cardType(effect)
//     {}
// };

