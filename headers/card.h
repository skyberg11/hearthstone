#pragma once

#include <bits/stdc++.h>
#include "effects.h"
#include "player.h"
#include "ability.h"
#include "field.h"

enum CardType {
    effect,
    monster
};

struct Card {
    CardType card_type;
};

struct Target {
    std::vector<Player*> players;
    std::vector<card*> cards;
};

struct MonsterCard : Card {
    size_t mana_cost;
    int life;
    size_t damage;
    Ability ability;

    MonsterCard():
        cardType(monster)
    {}
};

struct EffectCard : Card {
    size_t mana_cost;
    Ability ability;

    EffectCard():
        cardType(effect)
    {}
};

