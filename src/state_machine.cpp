//
// Created by pedro on 21/10/22.
//
#include "state_machine.hpp"
#include <algorithm>
#include <random>

Uno::State Uno::StateMachine::initial_state() {
}

std::optional<Uno::State> Uno::StateMachine::reduce(const Uno::State &, const Uno::Event::Event &) {
    return std::optional<State>();
}
