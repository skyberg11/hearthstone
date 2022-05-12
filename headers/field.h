#pragma once

#include <bits/stdc++.h>
#include "card.h"

class Deck {
    protected:

    std::vector<Card*>deck;

    Deck();

    friend void Game::StartGame();
    public:
    Deck(Deck &other) = delete;
    void operator=(const Deck &) = delete;

    bool IsAvailable();
    
    Card* GetUpperCard();
};
