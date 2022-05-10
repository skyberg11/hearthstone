#pragma once

#include "player.h"
#include "interface.h"

Mortal::Mortal():
    life(0),
    damage(0),
    opposite(nullptr)
    {}

Mortal::Mortal(int life, size_t damage, Player* opposite = nullptr):
    life(life),
    damage(damage),
    opposite(opposite)
{}

void Mortal::DealDamage(Mortal* target) {
    Game::ChangeHpON(target, -damage);
}

bool Mortal::IsDead() {
    return life < 1;
};


void Player::Hand::push(Card* card) {
    cards.push_back(card);
}

void Player::Hand::RemoveCard(Card* card) {
    for(std::vector<Card*>::iterator it = cards.begin();
        it != cards.end(); ++it) {
        if(*it == card) {
            cards.erase(it);
            break;
        }
    }
}

Player::Hand::Hand() = default;
Player::Player() = default;

Player::Player(int hp, size_t damage, Player* opposite, size_t mana):
    Mortal(hp, damage, opposite),
    mana(mana)
{}

void Player::Move() {
    Game::GarbageCollector(this, opposite);
    Directive directive = Interface::GetDirective(this, opposite);
    //Attack [executor*] [target*] - attacks a target by executor
    //deploy [card*] - deploys a card
    //finish - end the move
    if(directive.command == Command::attack) {
        if(directive.executor->IsAbleToAttack && 
            directive.executor->opposite != directive.target->opposite) {
            directive.executor->DealDamage(directive.target);
        } else {
            Interface::Echo("Deployed or not your card cant fight");
        }    
        Move();
    } else if(directive.command == Command::deploy) {
        Card* card = reinterpret_cast<Card*>(directive.card);
        mana -= card->mana_cost;
        if(card->card_type == CardType::monster) {
            laid_cards.push_back(reinterpret_cast<MonsterCard*>(directive.card));
        }
        hand.RemoveCard(reinterpret_cast<MonsterCard*>(directive.card));
        reinterpret_cast<MonsterCard*>(directive.card)->ExecuteAbility();
        Move();
    } else {
        return;
    }
}

void Game::GarbageCollector(Player* first, Player* second) {
    for(std::vector<Card*>::iterator it = first->laid_cards.begin();
        it != first->laid_cards.end(); ++it) {
        if(reinterpret_cast<MonsterCard*>(&(*it))->IsDead()) {
            first->laid_cards.erase(it);
        }
    }
    for(std::vector<Card*>::iterator it = second->laid_cards.begin();
        it != second->laid_cards.end(); ++it) {
        if(reinterpret_cast<MonsterCard*>(&(*it))->IsDead()) {
            second->laid_cards.erase(it);
        }
    }
}


void Game::ChangeHpON(Mortal* target, int value) {
    target->life += value;
}

void Game::SetHpOn(Mortal* target, int value) {
    target->life = value;
}

void Game::ChangeDamageOn(Mortal* target, int value) {
    target->damage += value;
}

void Game::SetDamageOn(Mortal* target, int value) {
    target->damage = value;
}

void Game::AddMana(Player* player, int value) {
    player->mana += value;
}

bool Game::IsGameEnd(Player* first, Player* second) {
    return first->IsDead() || second->IsDead();
}

void Game::StartGame() {
    static Player first;
    static Player second(30, 1, &first, 1);
    first = Player(30, 1, &second, 1);
    Deck deck;
    Player* current_player = &first;
    Player* next_player = &second; 
    while(IsGameEnd(&first, &second)) {
        switch(game_status) {
            case WhosMove::idle:
                game_status = WhosMove::first;
                break;
            case WhosMove::first:
                game_status = WhosMove::second;
                break;
            default:
                game_status = WhosMove::first;
                break;
        }
        current_player->Move();
        if(deck.IsAvailable()) {
            MonsterCard* to_push = 
                reinterpret_cast<MonsterCard*>(deck.GetUpperCard());
            to_push->opposite = next_player;
            current_player->hand.push(to_push);
        }
        Game::AddMana(current_player, 1);
        std::swap(current_player, next_player);
    }
}