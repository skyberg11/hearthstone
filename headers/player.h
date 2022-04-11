#pragma once

#include <bits/stdc++.h>
#include "card.h"
#include "effects.h"
#include "field.h"
#include "ability.h"

enum Life {
    alive = true,
    dead = false
};

template<bool IsBot>
class Player {
    private:

    struct Hand {
        std::vector<Card*> cards;
        void push(Card* card) {
            cards.push_back(card);
        }
    };

    Life status;
    int life;
    int damage;

    std::vector<Card*> laid_cards;

    public:

    Player():
        // Generation of the Player;
    {}

    bool IsDead const {
        return status;
    };

    void Move() {
        if(IsBot) {
            // ??? Artificial Intelligence or some algo wtf ???
            return;
        } else {
            std::tuple<Interface::Command, Args...> directive = Interface::GetDirective();
            //Attack [card/hero] [executor] [target] - attacks a target by executor
            //deploy [card] - deploys a card
            //skill - use hero skill
            //finish - end the move
            if(directive[0] == attack) {
                
            } else if()
        }
    }
};
