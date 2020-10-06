//
// Created by fulva on 2020/10/6.
//

#ifndef OMNIODOM_WHEELRECORD_H
#define OMNIODOM_WHEELRECORD_H

#include <deque>
#include <optional>

#include "timer.h"
#include "wheelstate.h"


namespace omniodom {
    class WheelRecord {
    public:
        WheelRecord(timer &timer);

        std::optional<WheelState> latestState();

        std::optional<WheelState> stateAt(long timeStamped);

        void insertRecord(double angle);

    private:

        timer &timer;
        std::deque<WheelState> states{};

        std::optional<WheelState> interpolate(long timeStamped, std::deque<WheelState>::const_iterator iter) const;
    };
}


#endif //OMNIODOM_WHEELRECORD_H
