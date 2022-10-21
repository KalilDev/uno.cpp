//
// Created by pedro on 21/10/22.
//
#pragma once
#include "state_machine.hpp"
#include "data.hpp"

namespace Uno {
    class ThreadedStateMachine: public StateMachine {
        const std::unique_ptr<StateMachine> _underlying_machine;
        const std::thread _thread;
        const std::mutex _state_mutex;
    public:
        virtual ~ThreadedStateMachine() override;

        virtual State currentState() const override;

        virtual size_t add_listener(const std::unique_ptr<Listener> &) override ;

        virtual void remove_listener(size_t) override;

        virtual bool dispatch(const Event::Event &) override;

    };
}