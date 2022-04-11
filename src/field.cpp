#include "card.h"
#include "effects.h"
#include "player.h"
#include <bits/stdc++.h>
#include "field.h"


void Field::ExecuteEffects() {


}

void Field::ExecuteMove() {
    ExecuteEffects();
    ExecuteMonsters();
}

void Field::Builder() {



}

void Field::StartGame() {
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

bool Field::IsGameEnd() {
    return first.isDead() || second.isDead();
}
