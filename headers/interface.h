namespace Interface {

    enum Command {
        attack,
        deploy,
        skill,
        finish
    }

    std::tuple<Command, Args...> GetDirective() {
        // implement move
    }

}