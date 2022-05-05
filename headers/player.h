#pragma once

#include <bits/stdc++.h>
#include "card.h"
#include "effects.h"
#include "field.h"
#include "ability.h"

class Player {
    private:

    struct Hand {
        std::vector<Card*> cards;

        void push(Card* card) {
            cards.push_back(card);
        }

        void RemoveCard(Card* card) {
            for(auto it : deck) {
                if(&(*it) == card) {
                    deck.erase(it);
                    break;
                }
            }
        }
    };

    Hand hand;
    std::string name;
    int life;
    size_t damage;
    size_t mana;

    friend Game;
    
    std::vector<Card*> laid_cards;

    public:

    Player():
        // Generation of the Player;
    {}

    bool IsDead const {
        return life < 1;
    };

    void DealDamage(auto* target) {
        Game::ChangeHpON(target, -damage);
    }

    void Move() {
        std::pair<Interface::Command, 
            std::tuple<Args...>> directive = Interface::GetDirective();
        //Attack [executor*] [target*] - attacks a target by executor
        //deploy [card*] - deploys a card
        //finish - end the move
        if(directive.first == Interface::Command.attack) {
            directive.second[0].DealDamage(directive.second[1]);
        } else if(directive.first == Interface::Command.deploy) {
            mana -= directive.second[0].mana_cost;
            laid_cards.push_back(directive.second[0]);
            hand.RemoveCard(directive.second[0]);
            directive.second[0]->ExecuteAbility();
        } else {
            return;
        }

    }
};
