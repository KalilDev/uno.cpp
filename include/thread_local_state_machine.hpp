//
// Created by pedro on 21/10/22.
//
#pragma once
#include "state_machine.hpp"
#include "data.hpp"

namespace Uno {
    class ThreadLocalStateMachine: public StateMachine {
        const size_t _cards_in_hand;
        const duration_t _play_duration;
        const duration_t _uno_snitch_time;
        const Rules _rules;
        State _state = initial_state();
        const std::map<size_t,std::unique_ptr<Listener>> _listeners = {};
    public:
        ThreadLocalStateMachine(size_t, const duration_t&, const duration_t&, const std::set<Rule>&);
        virtual ~ThreadLocalStateMachine() override = default;

        virtual State currentState() const override;

        virtual size_t add_listener(const std::unique_ptr<Listener> &) override ;

        virtual void remove_listener(size_t) override;

        virtual bool dispatch(const Event::Event &) override;
    };
}