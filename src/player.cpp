//
// Created by ztimu on 27.03.2022.
//
#include <vector>
#include "effects.h"
#include "card.h"
#include "player.h"

void Player::CastCard(const Card& cast) {

}

void Player::Hand::push(const Card& card) {
    cards.push_back(card);
}
Player::Player():
    life(30),
    effects(std::vector<Effect>()),
    status(alive)
{}

~Player::Player() = default;

bool Player::IsDead const {
    return status;
};

void Player::Move() {

}
