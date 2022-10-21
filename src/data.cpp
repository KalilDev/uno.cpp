//
// Created by pedro on 21/10/22.
//
#include "data.hpp"

Uno::Card::Default::Default(Uno::Card::Color, Uno::uno_number_t) {

}

Uno::Card::Color Uno::Card::Default::color() const {
    return Uno::Card::yellow;
}

Uno::uno_number_t Uno::Card::Default::number() const {
    return 0;
}

bool Uno::Card::Default::operator==(const Uno::Card::Default &) const {
    return false;
}

Uno::Card::Reverse::Reverse(Uno::Card::Color) {

}

Uno::Card::Color Uno::Card::Reverse::color() const {
    return Uno::Card::yellow;
}

bool Uno::Card::Reverse::operator==(const Uno::Card::Reverse &) const {
    return false;
}

Uno::Card::Block::Block(Uno::Card::Color) {

}

Uno::Card::Color Uno::Card::Block::color() const {
    return Uno::Card::yellow;
}

bool Uno::Card::Block::operator==(const Uno::Card::Block &) const {
    return false;
}

Uno::Card::PlusTwo::PlusTwo(Uno::Card::Color) {

}

Uno::Card::Color Uno::Card::PlusTwo::color() const {
    return Uno::Card::yellow;
}

bool Uno::Card::PlusTwo::operator==(const Uno::Card::PlusTwo &) const {
    return false;
}

bool Uno::Card::PlusFour::operator==(const Uno::Card::PlusFour &) const {
    return false;
}

bool Uno::Card::Rainbow::operator==(const Uno::Card::Rainbow &) const {
    return false;
}

Uno::Player::Id::Id(const std::string &) {

}

bool Uno::Player::Id::operator==(const Uno::Player::Id &) const {
    return false;
}

bool Uno::Player::Id::operator<(const Uno::Player::Id &) const {
    return false;
}

Uno::Player::State::State(const Uno::Player::Id &, const std::string &, const Uno::Card::CardList &,
                          const Uno::time_point_t &, bool) {

}

std::string Uno::Player::State::name() const {
    return std::string();
}

Uno::Card::CardList Uno::Player::State::cards() const {
    return Uno::Card::CardList();
}

Uno::time_point_t Uno::Player::State::last_play_time() const {
    return Uno::time_point_t();
}

bool Uno::Player::State::did_uno() const {
    return false;
}

bool Uno::Player::State::operator==(const Uno::Player::State &) const {
    return false;
}

Uno::Player::State Uno::Player::State::with(const std::optional<Id> &, const std::optional<std::string> &,
                                            const std::optional<Card::CardList> &, const std::optional<time_point_t> &,
                                            const std::optional<bool> &) const {
    return Uno::Player::State(Player::Id(), __cxx11::basic_string(), std::vector(), chrono::time_point(), false);
}

Uno::Play::Playing::Playing(const Uno::time_point_t &, const Uno::time_point_t &, const Uno::duration_t &,
                            const Uno::Player::Id &, Uno::Direction, const Uno::Card::PlusTwoOrPlusFourStack &) {

}

Uno::time_point_t Uno::Play::Playing::start_time() const {
    return Uno::time_point_t();
}

Uno::time_point_t Uno::Play::Playing::play_start_time() const {
    return Uno::time_point_t();
}

Uno::duration_t Uno::Play::Playing::play_remaining_duration() const {
    return Uno::duration_t();
}

Uno::Player::Id Uno::Play::Playing::current_player() const {
    return Uno::Player::Id(__cxx11::basic_string());
}

Uno::Direction Uno::Play::Playing::direction() const {
    return Uno::clockwise;
}

Uno::Card::PlusTwoOrPlusFourStack Uno::Play::Playing::stacking_pluses() const {
    return Uno::Card::PlusTwoOrPlusFourStack();
}

bool Uno::Play::Playing::operator==(const Uno::Play::Playing &) const {
    return false;
}

Uno::Play::Playing Uno::Play::Playing::with(const std::optional<time_point_t> &, const std::optional<time_point_t> &,
                                            const std::optional<duration_t> &, const std::optional<Player::Id> &,
                                            const std::optional<Direction> &,
                                            const std::optional<Card::PlusTwoOrPlusFourStack> &) const {
    return Uno::Play::Playing(chrono::time_point(), chrono::time_point(), chrono::duration(), Player::Id(),
                              Uno::clockwise, std::stack());
}

bool Uno::Play::WaitingStart::operator==(const Uno::Play::WaitingStart &) const {
    return false;
}

Uno::Play::Finished::Finished(const Uno::Player::Id &, const Uno::duration_t &) {

}

Uno::Player::Id Uno::Play::Finished::winner() const {
    return Uno::Player::Id(__cxx11::basic_string());
}

Uno::duration_t Uno::Play::Finished::duration() const {
    return Uno::duration_t();
}

Uno::Play::Finished
Uno::Play::Finished::with(const std::optional<Player::Id> &, const std::optional<duration_t> &) const {
    return Uno::Play::Finished(Player::Id(), chrono::duration());
}

Uno::State::State(const Uno::Player::PlayerStates &, const Uno::Card::CardStack &, const Uno::Card::CardStack &,
                  Uno::Card::Color, const std::unique_ptr<Play::State> &) {

}

Uno::Player::PlayerStates Uno::State::players() const {
    return Uno::Player::PlayerStates();
}

Uno::Card::CardStack Uno::State::played_cards() const {
    return Uno::Card::CardStack();
}

Uno::Card::CardStack Uno::State::card_stack() const {
    return Uno::Card::CardStack();
}

Uno::Card::Color Uno::State::current_color() const {
    return Uno::Card::yellow;
}

Uno::Play::State Uno::State::play_state() const {
    return Uno::Play::State();
}

bool Uno::State::operator==(const Uno::State &other) const {
    return false;
}

Uno::State Uno::State::with(const std::optional<Player::PlayerStates> &, const std::optional<Card::CardStack> &,
                            const std::optional<Card::CardStack> &, const std::optional<Card::Color> &,
                            const std::optional<std::unique_ptr<Play::State>> &) const {
    return Uno::State(std::map(), std::stack(), std::stack(), Uno::Card::yellow, std::unique_ptr());
}

bool Uno::Event::StartGame::operator==(const Uno::Event::StartGame &) const {
    return false;
}

Uno::Event::PlayCard::PlayCard(const size_t, const std::optional<Card::Color> &) {

}

size_t Uno::Event::PlayCard::card_index() const {
    return 0;
}

std::optional<Card::Color> Uno::Event::PlayCard::chosen_wildcard_color() const {
    return std::optional<Card::Color>();
}

bool Uno::Event::PlayCard::operator==(const Uno::Event::PlayCard &) const {
    return false;
}

bool Uno::Event::SayUno::operator==(const Uno::Event::SayUno &) const {
    return false;
}

Uno::Event::AddPlayer::AddPlayer(const Uno::Player::Id &, const std::string &) {

}

Uno::Player::Id Uno::Event::AddPlayer::player() const {
    return Uno::Player::Id(__cxx11::basic_string());
}

std::string Uno::Event::AddPlayer::name() const {
    return std::string();
}

bool Uno::Event::AddPlayer::operator==(const Uno::Event::AddPlayer &) const {
    return false;
}

Uno::Event::ChangePlayerName::ChangePlayerName(const Uno::Player::Id &, const std::string &name) {

}

Uno::Player::Id Uno::Event::ChangePlayerName::player() const {
    return Uno::Player::Id(__cxx11::basic_string());
}

std::string Uno::Event::ChangePlayerName::name() const {
    return std::string();
}

bool Uno::Event::ChangePlayerName::operator==(const Uno::Event::ChangePlayerName &) const {
    return false;
}

Uno::Event::RemovePlayer::RemovePlayer(const Uno::Player::Id &) {

}

Uno::Player::Id Uno::Event::RemovePlayer::player() const {
    return Uno::Player::Id(__cxx11::basic_string());
}

bool Uno::Event::RemovePlayer::operator==(const Uno::Event::RemovePlayer &) const {
    return false;
}

bool Uno::Event::TimePassed::operator==(const Uno::Event::TimePassed &) const {
    return false;
}

bool Uno::Event::PlayerDrewCard::operator==(const Uno::Event::PlayerDrewCard &) const {
    return false;
}

Uno::Event::PlayerSnitchedUno::PlayerSnitchedUno(const Uno::Player::Id &) {

}

Uno::Player::Id Uno::Event::PlayerSnitchedUno::player() const {
    return Uno::Player::Id(__cxx11::basic_string());
}

bool Uno::Event::PlayerSnitchedUno::operator==(const Uno::Event::PlayerSnitchedUno &) const {
    return false;
}
