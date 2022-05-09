#pragma once

#include <bits/stdc++.h>
#include "card.h"
#include "effects.h"
#include "field.h"
#include "game.h"
#include "ability.h"

struct Directive;

namespace Interface {
    enum Command {
        attack,
        deploy,
        skill,
        finish
    }

    Directive GetDirective(Player* ally, Player* opposite) {
        Directive directive;
        //Attack [hero;1;2;3;4...] [hero;1;2;3;4;5...]
        std::string command;
        std::cin >> command;
        switch(command) {
            case "attack":
                std::string exec, target;
                std::cin >> exec >> target;
                Mortal* from, to;
                if(exec == "hero") {
                    from = reinterpret_cast<Mortal*>(ally);
                } else {
                    from = reinterpret_cast<Mortal*>(ally->laid_cards[stoi(exec) - 1]);
                }
                if(target == "hero") {
                    to = reinterpret_cast<Mortal*>(opposite);
                } else {
                    to = reinterpret_cast<Mortal*>(opposite->laid_cards[stoi(target) - 1]);
                }
                directive = Directive(Interface::Command.attack, from, to);
                break;
            case "deploy":
                size_t card_index;
                std::cin >> card_index;
                Mortal* to_deploy;
                to_deploy = reinterpret_cast<Mortal*>(ally->hand.cards[card_index - 1]);
                directive = Directive(Interface::Command.deploy, to_deploy);
            case "finish":
                directive = Directive(Interface::Command.attack.finish);
                break;
            default:
                std::cout << "skip\n";
        }
        return directive;        
    }
}


struct Directive {
    Interface::Command command;
    Mortal* executor = nullptr;
    Mortal* target = nullptr;
    Card* card = nullptr;

    Directive(Interface::Command name, Mortal* executor = nullptr, 
        Mortal* target = nullptr):
        command(name),
        executor(executor),
        target(target)
        {}
    Directive(Interface::Command name, Mortal& card):
        command(name),
        card(card)
        {}
}