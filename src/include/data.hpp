#include <string>
#include <stack>
#include <vector>
#include <functional>
#include <chrono>
#include <map>
#include <optional>
#include <memory>
#include <variant>
#include <set>
#include <thread>
#include <mutex>

namespace Uno {

    typedef unsigned char uno_number_t;
    using time_point_t = std::chrono::time_point<std::chrono::system_clock>;
    using duration_t = std::chrono::duration<size_t>;

    enum Direction {
        clockwise, counterclockwise
    };

    namespace Card {
        enum Color {
            green, blue, yellow, red,
        };

        class Card {
        public:
            virtual ~Card() = 0;
            enum Kind {
                Default, Reverse, Block, PlusTwo, PlusFour, Rainbow
            };
            virtual Kind kind() const;
        };

        class Default : public Card{
        private:
            const Color _color;
            const uno_number_t _number;
        public:
            Default(Color, uno_number_t);
            virtual ~Default() override = default;

            Color color() const;

            uno_number_t number() const;

            bool operator==(const Default &) const;
            Kind kind() const override {
                return Kind::Default;
            }
        };

        class Reverse : public Card {
        private:
            const Color _color;
        public:
            Reverse(Color);
            virtual ~Reverse() override = default;

            Color color() const;

            bool operator==(const Reverse &) const;
            Kind kind() const override {
                return Kind::Reverse;
            }
        };

        class Block : public Card{
        private:
            const Color _color;
        public:
            Block(Color);
            virtual ~Block() override = default;

            Color color() const;

            bool operator==(const Block &) const;
            Kind kind() const override {
                return Kind::Block;
            }
        };

        class PlusTwo : public Card {
        private:
            const Color _color;
        public:
            PlusTwo(Color);
            virtual ~PlusTwo() override = default;

            Color color() const;

            bool operator==(const PlusTwo &) const;
            Kind kind() const override {
                return Kind::PlusTwo;
            }
        };

        class PlusFour : public Card {
        public:
            PlusFour() = default;
            virtual ~PlusFour() override = default;

            bool operator==(const PlusFour &) const;
            Kind kind() const override {
                return Kind::PlusFour;
            }
        };

        class Rainbow : public Card{
        public:
            Rainbow() = default;
            virtual ~Rainbow() override = default;

            bool operator==(const Rainbow &) const;
            Kind kind() const override {
                return Kind::Rainbow;
            }
        };

        using CardStack = std::stack<Card>;
        using CardList = std::vector<Card>;

        using PlusTwoOrPlusFour = std::variant<PlusTwo, PlusFour>;
        using PlusTwoOrPlusFourStack = std::stack<PlusTwoOrPlusFour>;
    };

    namespace Player {
        class Id {
        private:
            const std::string _id;
        public:
            Id(const std::string &);

            bool operator==(const Id &) const;
            bool operator<(const Id&) const;
        };

        class State {
        private:
            const Id _id;
            const std::string _name;
            const Card::CardList _cards;
            const time_point_t _last_play_time;
            const bool _did_uno;
        public:
            State(const Id &, const std::string &, const Card::CardList &,
                  const time_point_t &,
                  bool);

            std::string name() const;

            Card::CardList cards() const;

            time_point_t last_play_time() const;

            bool did_uno() const;

            bool operator==(const State &) const;

            State with(const std::optional<Id> &,
                    const std::optional< std::string> &,
                    const  std::optional<Card::CardList> &,
                       const std::optional< time_point_t> &,
                       const std::optional<bool> &
                       ) const;
        };

        using PlayerStates = std::map<Id, State>;
    }

    namespace Play {
        class State {
        public:
            virtual ~State() = 0;
            enum Kind {
                Playing, WaitingStart, Finished
            };
            virtual Kind kind() const;
        };
        class Playing : public State{
        private:
            const time_point_t _start_time;
            const time_point_t _play_start_time;
            const duration_t _play_remaining_duration;
            const Player::Id _current_player;
            const Direction _direction;
            const Card::PlusTwoOrPlusFourStack _stacking_pluses;
        public:
            Playing(
                    const time_point_t &,
                    const time_point_t &,
                    const duration_t &,
                    const Player::Id &,
                    Direction,
                    const Card::PlusTwoOrPlusFourStack &);
            virtual ~Playing() override = default;

            time_point_t start_time() const;

            time_point_t play_start_time() const;

            duration_t play_remaining_duration() const;

            Player::Id current_player() const;

            Direction direction() const;

            Card::PlusTwoOrPlusFourStack stacking_pluses() const;

            bool operator==(const Playing &) const;

            Playing with(
                    const std::optional<time_point_t> &,
                    const std::optional< time_point_t> &,
                    const std::optional< duration_t> &,
                    const std::optional< Player::Id> &,
                    const std::optional<Direction> &,
                    const std::optional< Card::PlusTwoOrPlusFourStack> &

                    ) const;
            Kind kind() const override {
                return Kind::Playing;
            };
        };

        class WaitingStart : public State {
        public:
            WaitingStart();
            virtual ~WaitingStart() override = default;

            bool operator==(const WaitingStart &) const;
            Kind kind() const override {
                return Kind::WaitingStart;
            };
        };

        class Finished : public State {
        private:
            const Player::Id _winner;
            const duration_t _duration;
        public:
            Finished(
                    const Player::Id &,
                    const duration_t &);
            virtual ~Finished() override = default;

            Player::Id winner() const;
            duration_t duration() const;

            bool operator==(const Finished &) const;
            Finished with(
                    const std::optional<Player::Id> &,
                    const std::optional< duration_t> &
                    ) const;

            Kind kind() const override {
                return Kind::Finished;
            };
        };
    }

    class State {
    private:
        const Player::PlayerStates _players;
        const Card::CardStack _played_cards;
        const Card::CardStack _card_stack;
        const Card::Color _current_color;
        const std::unique_ptr<Play::State> _play_state;
    public:
        State(
                const Player::PlayerStates &,
                const Card::CardStack &,
                const Card::CardStack &,
                Card::Color,
                const std::unique_ptr<Play::State> &);

        Player::PlayerStates players() const;

        Card::CardStack played_cards() const;

        Card::CardStack card_stack() const;

        Card::Color current_color() const;

        Play::State play_state() const;

        bool operator==(const State &other) const;
        State with (
                const std::optional<Player::PlayerStates> &,
                const std::optional< Card::CardStack> &,
                const std::optional< Card::CardStack> &,
                const std::optional<Card::Color>&,
                const std::optional<std::unique_ptr< Play::State>> &) const;
    };
    namespace Event {
        class Event {
        public:
            virtual ~Event() = 0;
            enum Kind {
                StartGame,
                PlayCard,
                SayUno,
                AddPlayer,
                ChangePlayerName,
                RemovePlayer,
                TimePassed,
                PlayerDrewCard,
                PlayerSnitchedUno
            };
            virtual Kind kind() const;
        };

        class StartGame : public Event{
        public:
            StartGame() = default;
            virtual ~StartGame() = default;

            bool operator==(const StartGame &) const;
            Kind kind() const override {
                return Kind::StartGame;
            };
        };

        class PlayCard  : public Event{
        private:
            const size_t _card_index;
            const std::optional<Card::Color> _chosen_wildcard_color;
        public:
            PlayCard(const size_t, const std::optional<Card::Color> &);
            virtual ~PlayCard() = default;

            size_t card_index() const;

            std::optional<Card::Color> chosen_wildcard_color() const;

            bool operator==(const PlayCard &) const;
            Kind kind() const override {
                return Kind::PlayCard;
            };
        };

        class SayUno  : public Event{
        public:
            SayUno() = default;
            virtual ~SayUno() = default;

            bool operator==(const SayUno &) const;
            Kind kind() const override {
                return Kind::SayUno;
            };
        };

        class AddPlayer  : public Event{
        private:
            const Player::Id _player;
            const std::string _name;
        public:
            AddPlayer(const Player::Id &, const std::string &);
            virtual ~AddPlayer() override = default;

            Player::Id player() const;

            std::string name() const;

            bool operator==(const AddPlayer &) const;
            Kind kind() const override {
                return Kind::AddPlayer;
            };
        };

        class ChangePlayerName  : public Event{
        private:
            const Player::Id _player;
            const std::string _name;
        public:
            ChangePlayerName(const Player::Id &, const std::string &name);
            virtual ~ChangePlayerName() override = default;

            Player::Id player() const;

            std::string name() const;

            bool operator==(const ChangePlayerName &) const;
            Kind kind() const override {
                return Kind::ChangePlayerName;
            };
        };

        class RemovePlayer  : public Event{
        private:
            const Player::Id _player;
        public:
            RemovePlayer(const Player::Id &);
            virtual ~RemovePlayer() override = default;

            Player::Id player() const;

            bool operator==(const RemovePlayer &) const;
            Kind kind() const override {
                return Kind::RemovePlayer;
            };
        };

        class TimePassed  : public Event{
        public:
            TimePassed() = default;
            virtual ~TimePassed() override = default;

            bool operator==(const TimePassed &) const;
            Kind kind() const override {
                return Kind::TimePassed;
            };
        };

        class PlayerDrewCard  : public Event{
        public:
            PlayerDrewCard() = default;
            virtual ~PlayerDrewCard() override = default;

            bool operator==(const PlayerDrewCard &) const;
            Kind kind() const override {
                return Kind::PlayerDrewCard;
            };
        };

        class PlayerSnitchedUno  : public Event{
        private:
            const Player::Id _player;
        public:
            PlayerSnitchedUno(const Player::Id &);
            virtual ~PlayerSnitchedUno() override = default;

            Player::Id player() const;

            bool operator==(const PlayerSnitchedUno &) const;
            Kind kind() const override {
                return Kind::PlayerSnitchedUno;
            };
        };
    }

    enum Rule {
        plus_two_stacks_plus_two,
        plus_four_stacks_plus_two,
        plus_four_stacks_plus_four,
    };

    class StateMachine {
    public:
        class Listener {
            virtual ~Listener() = 0;

            virtual void on_state_changed(const State &);
        };

        StateMachine() = default;

        virtual ~StateMachine() = 0;

        virtual State currentState() const = 0;

        virtual size_t add_listener(const std::unique_ptr<Listener> &) = 0;

        virtual void remove_listener(size_t) = 0;

        virtual bool dispatch(const Event::Event &) = 0;

    protected:
        virtual std::optional<State> reduce(const State &, const Event::Event &);
    };
    class ThreadLocalStateMachine: public StateMachine {
        const size_t _cards_in_hand;
        const duration_t _play_duration;
        const duration_t _uno_snitch_time;
        const std::set<Rule> _rules;
        State _state = initial_state();
        const std::map<size_t,std::unique_ptr<Listener>> _listeners = {};
    public:
        ThreadLocalStateMachine(size_t, const duration_t&, const duration_t&, const std::set<Rule>&);
        virtual ~ThreadLocalStateMachine() override = default;
        static constexpr State initial_state();

        virtual State currentState() const override;

        virtual size_t add_listener(const std::unique_ptr<Listener> &) override ;

        virtual void remove_listener(size_t) override;

        virtual bool dispatch(const Event::Event &) override;
    };
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
};