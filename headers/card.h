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
    std::string name;
    CardType card_type;
    size_t mana_cost;
    Ability ability;

    friend Game;
};

struct Target {
    std::vector<Player*> players;
    std::vector<Card*> cards;
};

struct MonsterCard : public Card, public Mortal {

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

};

struct EffectCard : public Card {

    EffectCard():
        cardType(effect)
    {}
};

