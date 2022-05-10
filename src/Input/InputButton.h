//
// Created by glosn on 5/8/2022.
//

#ifndef TETRISEXAM_INPUTBUTTON_H
#define TETRISEXAM_INPUTBUTTON_H

#include <SFML/Graphics.hpp>
#include <utility>
#include <optional>
#include <list>
#include "InputButtonSource.h"


namespace Tetris::Input
{
    class InputButton
    {
    public:
        enum class SignalType
        {
            AlwaysOff,                   ///< The button is always off
            AlwaysOn,                    ///< The button is always on
            ButtonState,                 ///< True when button is down
            NotButtonState,              ///< True when button is up
            OnButtonDown,                ///< True when button goes down
            OnButtonUp,                  ///< True when button goes up
            OnButtonUpAndDown,           ///< True when button goes up or down
            Interval,                    ///< True every interval
            IntervalWhithDelayFirst, ///< True every interval but the fist interval is different

            ButtonCount                  ///< Keep last -- the total number of SignalTypes
        };

        InputButton();
        explicit InputButton(SignalType signalType, InputButtonSource source);

        void addInputSource(InputButtonSource &source);


        /// @brief Call once per frame
        void update(float deltaTime);

        [[nodiscard]] bool getSignal();

        [[nodiscard]] bool isButtonPressed() const;


        void setSignalType(SignalType signalType);

        void setPreferredInterval(float interval);
        void setPreferredLongInterval(float interval); /// This value is used by SignalType::IntervalWhithDelayFirst

    private:

        SignalType _signalType{};

        std::list<InputButtonSource> _inputSources;

        /// A value of 0 means that is is not down/up
        float _downDuration{0}; ///< Seconds since button went down
        float _upDuration{0}; ///< Seconds since button went up

        bool _isButtonPressed{false};

        bool _didButtonSwitchStatePreviousFrame{true};

        /// These are used when you use SignalType Interval and IntervalWhithDelayFirst
        int _intervalCount{0};
        int _intervalCountShouldUpdateTo{0};
        float _intervalTime{0.1f};
        float _longIntervalTime{0.2f};

        bool checkInterval(bool withDelayFirst);
    };

} // Tetris::Input

#endif //TETRISEXAM_INPUTBUTTON_H
