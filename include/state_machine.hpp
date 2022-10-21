//
// Created by pedro on 21/10/22.
//
#pragma once
#include "data.hpp"
namespace Uno {
    class StateMachine {
    public:
        class Listener {
            virtual ~Listener() = 0;

            virtual void on_state_changed(const State &) = 0;
        };

        StateMachine() = default;

        virtual ~StateMachine() = 0;
        static State initial_state();

        virtual State currentState() const = 0;

        virtual size_t add_listener(const std::unique_ptr<Listener> &) = 0;

        virtual void remove_listener(size_t) = 0;

        virtual bool dispatch(const Event::Event &) = 0;

    protected:
        virtual std::optional<State> reduce(const State &, const Event::Event &);
    };
}