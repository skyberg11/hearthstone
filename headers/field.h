#include "card.h"
#include "effects.h"
#include "player.h"
#include <bits/stdc++.h>

enum WhosMove {
    first,
    second,
    begin
};

class Field {
    queue<Effect> effectsStack;
    queue<Monster

    public:
    void Builder();
    void StartGame() {
        Field::Builder();
        WhosMove gameStatus = begin;
        while(IsGameEnd()) {
            Player& currentPlayer;
            switch(gameStatus) {
                case begin:
                    gameStatus = first;
                    currentPlayer = first;
                    break;
                case first:
                    gameStatus = second;
                    currentPlayer = second;
                    break;
                default:
                    gameStatus = first;
                    currentPlayer = first;
                    break;
            }
            currentPlayer::move();
            ExecuteMove();
        }
    }
    bool IsGameEnd() {
        return first.isDead() || second.isDead();
    }


};