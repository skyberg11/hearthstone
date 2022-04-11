#pragma once

#include <bits/stdc++.h>
#include "card.h"
#include "effects.h"
#include "player.h"
#include "ability.h"

class Deck
{
    protected:

    vector<Card>deck;

    Deck():
    {
        //Generation of Deck;
    }

    static Deck* deck_;

    public:
    Deck(Deck &other) = delete;
    void operator=(const Deck &) = delete;

    bool IsAvailable() {
        return deck_.empty();
    }
    
    Card GetUpperCard() {
        Card tmp = deck_.back();
        deck_.pop_back();
        return tmp;
    }
};
