#pragma once

#include "interface.h"


void Interface::Echo(std::string msg) {
    std::cout << msg << '\n';
}

Directive Interface::GetDirective(Player* ally, Player* opposite) {
    Directive directive;
    //Attack [hero;1;2;3;4...] [hero;1;2;3;4;5...]
    std::string command;
    std::cin >> command;
    std::cerr << command;
    throw std::exception();
    if(command == "attack") {
            std::string exec, target;
            std::cin >> exec >> target;
            Mortal* from;
            Mortal* to;
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
            directive = Directive(Command::attack, from, to);
    } else if(command == "deploy") {
            size_t card_index;
            std::cin >> card_index;
            Card* to_deploy;
            if(ally->hand.cards.size() < card_index) {
                to_deploy = ally->hand.cards[card_index - 1];
            } else {
                Echo("Error. Please try again");
                return GetDirective(ally, opposite);
            }
            directive = Directive(Command::deploy, to_deploy);
    } else {
        std::cout << "skip\n";
    }
    return directive; 
}

Directive::Directive() = default;

Directive::Directive(Command name, Mortal* executor, 
    Mortal* target):
    command(name),
    executor(executor),
    target(target)
    {}
Directive::Directive(Command name, Card* card):
    command(name),
    card(card)
    {}
