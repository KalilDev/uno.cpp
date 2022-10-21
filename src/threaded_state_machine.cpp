//
// Created by pedro on 21/10/22.
//
#pragma once
#include "threaded_state_machine.hpp"

Uno::ThreadedStateMachine::~ThreadedStateMachine() {

}

Uno::State Uno::ThreadedStateMachine::currentState() const {
    return Uno::State(std::map(), std::stack(), std::stack(), Uno::Card::yellow, std::unique_ptr());
}

size_t Uno::ThreadedStateMachine::add_listener(const std::unique_ptr<Listener> &) {
    return 0;
}

void Uno::ThreadedStateMachine::remove_listener(size_t) {

}

bool Uno::ThreadedStateMachine::dispatch(const Uno::Event::Event &) {
    return false;
}
