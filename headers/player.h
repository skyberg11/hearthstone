#pragma once

#include <bits/stdc++.h>
#include "ability.h"

class Mortal;
class Player;
struct Card;

namespace Game {

    void ShowGame(Player* first, Player* second);

    void GarbageCollector(Player* first, Player* second);

    void ChangeHpON(Mortal* target, int value);

    void SetHpOn(Mortal* target, int value);

    void ChangeDamageOn(Mortal* target, int value);

    void SetDamageOn(Mortal* target, int value);

    void AddMana(Player* player, int value);
    
    enum WhosMove {
        first,
        second,
        idle
    };

    static WhosMove game_status = WhosMove::idle;

    bool IsGameEnd(Player* first, Player* second);

    void StartGame();
}

class Mortal {
    private:
    int life;
    size_t damage;


    friend void Game::ChangeHpON(Mortal* target, int value);
    friend void Game::SetHpOn(Mortal* target, int value);
    friend void Game::ChangeDamageOn(Mortal* target, int value);
    friend void Game::SetDamageOn(Mortal* target, int value);
    friend void Game::AddMana(Player* player, int value);

    public:
    Player* opposite;

    Mortal();
    Mortal(int life, size_t damage, Player* opposite);
    Mortal(std::string name, size_t mana_cost, int life, 
        size_t damage, Ability ability):
        Mortal(life, damage, nullptr)
        {}
    void DealDamage(Mortal* target);
    
    int ShowHP();

    bool IsDead();
    
    bool IsAbleToAttack = false;
};

class Player : public Mortal {
    struct Hand {
        std::vector<Card*> cards;

        Hand();
        void push(Card* card);

        void RemoveCard(Card* card);
    };

    
    size_t mana;

    friend void Game::ChangeHpON(Mortal* target, int value);
    friend void Game::SetHpOn(Mortal* target, int value);
    friend void Game::ChangeDamageOn(Mortal* target, int value);
    friend void Game::SetDamageOn(Mortal* target, int value);
    friend void Game::AddMana(Player* player, int value);

    public:

    Hand hand;
    std::vector<Card*> laid_cards;

    Player();
    Player(int hp, size_t damage, Player* opposite, size_t mana);

    bool IsAbleToAttack = true;

    void Move();
};
