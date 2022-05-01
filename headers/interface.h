namespace Interface {

    enum Command {
        attack,
        deploy,
        skill,
        finish
    }

    std::tuple<Command, Args...> GetDirective() {
        std::tuple<Command, Args...> directive;
        // implement
    }

}