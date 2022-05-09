#pragma once

#include <bits/stdc++.h>
#include "card.h"
#include "effects.h"
#include "field.h"
#include "ability.h"

class Player : public Mortal {
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

    
    std::string name;
    size_t mana;
    Player* opposite;

    friend Game;

    public:

    Hand hand;
    std::vector<Card*> laid_cards;

    Player():
        // Generation of the Player;
    {}

    bool IsDead const {
        return life < 1;
    };

    void Move() {
        Game::GarbageCollector();
        Interface::Directive directive = Interface::GetDirective(this, opposite);
        //Attack [executor*] [target*] - attacks a target by executor
        //deploy [card*] - deploys a card
        //finish - end the move
        if(directive.command == Interface::command.attack) {
            directive.executor->DealDamage(directive.target);
            Move();
        } else if(directive.command == Interface::Command.deploy) {
            Card* card = reinterpret_cast<Card*>(directive.card)->mana_cost;
            mana -= card->mana_cost;
            if(card->card_type == CardType.monster) {
                laid_cards.push_back(reinterpret_cast<MonsterCard*>(directive.card));
            }
            hand.RemoveCard(reinterpret_cast<MonsterCard*>(directive.card));
            reinterpret_cast<MonsterCard*>(directive.card)->ExecuteAbility();
            Move();
        } else {
            return;
        }
        
    }
};
