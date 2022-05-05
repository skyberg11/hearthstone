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
    friend Game;
};

struct Target {
    std::vector<Player*> players;
    std::vector<Card*> cards;
};

struct MonsterCard : Card {
    size_t mana_cost;
    int life;
    size_t damage;
    Ability ability;

    player* ally, opposite;

    MonsterCard():
        cardType(monster)
    {
        //
    }

    MonsterCard(std::string name, Player* ally, Player* opposite) 
    {}

    void ExecuteAbility {
        if(ability.hero_friendly) {
            Game.ChangeHpON(ally, ability.change_HP_on);
            Game.ChangeDamageOn(ally, ability.change_damage_on);
            Game.AddMana(ally, ability.add_mana);
        }
        if(ability.hero_bad) {
            Game.ChangeHpON(opposite, ability.change_HP_on);
            Game.ChangeDamageOn(opposite, ability.change_damage_on);
            Game.AddMana(opposite, ability.add_mana);
        }
        for(auto name : ability.to_summon) {
            Card* card = new Card(name, ally, opposite);
            ally->laid_cards.push_back(card);
        }
    }

    void DealDamage(auto* target) {
        Game::ChangeHpON(target, -damage);
    }
};

struct EffectCard : Card {
    size_t mana_cost;
    Ability ability;

    EffectCard():
        cardType(effect)
    {}
};

