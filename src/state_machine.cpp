//
// Created by pedro on 21/10/22.
//
#include "state_machine.hpp"
#include <algorithm>
#include <random>

constexpr bool is_special(const Uno::Card::Card & card) {
    switch (card.kind()) {
        case Uno::Card::Card::Default:
            return false;
        case Uno::Card::Card::Reverse:
        case Uno::Card::Card::Block:
        case Uno::Card::Card::PlusTwo:
        case Uno::Card::Card::PlusFour:
        case Uno::Card::Card::Rainbow:
            return true;
    }
};

constexpr bool is_wildcard(const Uno::Card::Card & card) {
    switch (card.kind()) {
        case Uno::Card::Card::Default:
        case Uno::Card::Card::Reverse:
        case Uno::Card::Card::Block:
        case Uno::Card::Card::PlusTwo:
            return false;
        case Uno::Card::Card::PlusFour:
        case Uno::Card::Card::Rainbow:
            return true;
    }
};

constexpr Uno::Card::Color color_for_card(const Uno::Card::Card &card, const std::optional<Uno::Card::Color> &chosen_wildcard_color = {}) {

    switch (card.kind()) {
        case Uno::Card::Card::Default:
        {
            auto c =  dynamic_cast<const Uno::Card::Default&>(card);
            return c.color();

        }
        case Uno::Card::Card::Reverse:
        {
            auto c =  dynamic_cast<const Uno::Card::Reverse&>(card);
            return c.color();
        }
        case Uno::Card::Card::Block:
        {
            auto c =  dynamic_cast<const Uno::Card::Block&>(card);
            return c.color();
        }
        case Uno::Card::Card::PlusTwo:
        {
            auto c =  dynamic_cast<const Uno::Card::PlusTwo&>(card);
            return c.color();
        }
        case Uno::Card::Card::PlusFour:
        case Uno::Card::Card::Rainbow:
            return *chosen_wildcard_color;
    }
}

Uno::State Uno::StateMachine::initial_state() {
    auto cards = Uno::Card::Cards{};
    for (auto c = 0; c < 4; c++ ) {
        auto color = static_cast<Uno::Card::Color>(c);
        for (auto i = 0; i < 10; i++) {
            cards.push_back(std::make_unique<Uno::Card::Default>(color, i));
        }
        cards.push_back(std::make_unique<Uno::Card::Reverse>(color));
        cards.push_back(std::make_unique<Uno::Card::Block>(color));
        cards.push_back(std::make_unique<Uno::Card::PlusTwo>(color));
    }
    for (auto i = 0; i < 4; i++) {
        cards.push_back(std::make_unique<Uno::Card::PlusFour>());
        cards.push_back(std::make_unique<Uno::Card::Rainbow>());
    }
    auto rng = std::default_random_engine{std::random_device{}()};
    std::shuffle(cards.begin(), cards.end(), rng);
    // The first card needs to be initialized, so it will be initialized with an rainbow card
    auto _ = Uno::Card::Rainbow();
    auto first_card = std::ref<Uno::Card::Card>(_);
    auto did_find_first = false;
    auto card_stack = Uno::Card::CardStack{};
    for (auto &card : cards) {
        if (did_find_first || is_special(*card)) {
            card_stack.push(*card);
            continue;
        }
        first_card = *card;
        did_find_first = true;
    }
    auto color = color_for_card(first_card);
    auto played_cards = Uno::Card::CardStack{};
    played_cards.push(first_card);
    auto play_state = std::make_unique<Uno::Play::WaitingStart>();
    return {
            Uno::Player::PlayerStates{},
            played_cards,
            card_stack,
            cards,
            color,
            std::move(play_state)
    };

}

void todo() {
    throw "To be implemented";
}

std::optional<Uno::State> Uno::StateMachine::reduce(const Uno::State &state, const Uno::Event::Event &event) {
    const auto &play_state = state.play_state();
    switch(play_state.kind()) {
        case Play::State::Playing: {
            const auto &playing = dynamic_cast<const Play::Playing &>(play_state);
            switch (event.kind()) {
                case Event::Event::StartGame:
                    return {};
                case Event::Event::PlayCard:
                    todo();
                case Event::Event::SayUno:
                    todo();
                case Event::Event::AddPlayer:
                    todo();
                case Event::Event::ChangePlayerName:
                    return change_player_name();
                case Event::Event::RemovePlayer:
                    return remove_player();
                case Event::Event::TimePassed:
                    todo();
                case Event::Event::PlayerDrewCard:
                    todo();
                case Event::Event::PlayerSnitchedUno:
                    todo();
            }
        }
        case Play::State::WaitingStart: {
            const auto &waiting_start = dynamic_cast<const Play::WaitingStart &>(play_state);
            switch (event.kind()) {
                case Event::Event::StartGame:
                    todo();
                case Event::Event::PlayCard:
                case Event::Event::SayUno:
                    return {};
                case Event::Event::AddPlayer:
                    todo();
                case Event::Event::ChangePlayerName:
                    return change_player_name();
                case Event::Event::RemovePlayer:
                    return remove_player();
                case Event::Event::TimePassed:
                case Event::Event::PlayerDrewCard:
                case Event::Event::PlayerSnitchedUno:
                    return {};
            }
        }
        case Play::State::Finished: {
            const auto &finished = dynamic_cast<const Play::Finished &>(play_state);
            switch (event.kind()) {
                case Event::Event::StartGame:
                case Event::Event::PlayCard:
                case Event::Event::SayUno:
                case Event::Event::AddPlayer:
                    return {};
                case Event::Event::ChangePlayerName:
                    return change_player_name();
                case Event::Event::RemovePlayer:
                    return remove_player();
                case Event::Event::TimePassed:
                case Event::Event::PlayerDrewCard:
                case Event::Event::PlayerSnitchedUno:
                    return {};
            }
        }
    }
}
