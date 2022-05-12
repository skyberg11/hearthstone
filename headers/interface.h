#pragma once

#include <bits/stdc++.h>
#include "ability.h"
#include "player.h"
#include "field.h"
#include "card.h"

struct Directive;

enum Command {
        attack,
        deploy,
        skill,
        finish
    };

namespace Interface {

    void Echo(std::string msg);

    Directive GetDirective(Player* ally, Player* opposite);
}


struct Directive {
    Command command = Command::finish;
    Mortal* executor = nullptr;
    Mortal* target = nullptr;
    Card* card = nullptr;

    Directive();
    Directive(Command name, Mortal* executor, 
        Mortal* target);
    Directive(Command name, Card* card);
};