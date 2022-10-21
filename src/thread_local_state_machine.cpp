//
// Created by pedro on 21/10/22.
//
#include "thread_local_state_machine.hpp"

Uno::ThreadLocalStateMachine::ThreadLocalStateMachine(size_t, const Uno::duration_t &, const Uno::duration_t &,
                                                      const std::set<Rule> &) {

}

Uno::State Uno::ThreadLocalStateMachine::currentState() const {
    return Uno::State(std::map(), std::stack(), std::stack(), Uno::Card::yellow, std::unique_ptr());
}

size_t Uno::ThreadLocalStateMachine::add_listener(const std::unique_ptr<Listener> &) {
    return 0;
}

void Uno::ThreadLocalStateMachine::remove_listener(size_t) {

}

bool Uno::ThreadLocalStateMachine::dispatch(const Uno::Event::Event &) {
    return false;
}
