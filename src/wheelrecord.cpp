//
// Created by fulva on 2020/10/6.
//

#include "wheelrecord.h"

#include <array>

using std::prev;
using std::next;

std::optional<WheelState> omniodom::WheelRecord::stateAt(long timeStamped) {
    if (std::size(states) < 3) {
        return std::optional<WheelState>{};
    }

    auto endIter = std::cend(states);
    for (auto iter = std::cbegin(states); iter != endIter; ++iter) {
        if (iter->timeStamp <= timeStamped) {
            return interpolate(timeStamped, iter);
        }
    }
    return std::optional<WheelState>();
}

std::optional<WheelState>
omniodom::WheelRecord::interpolate(long timeStamped, std::deque<WheelState>::const_iterator iter) const {
    if (iter == std::cbegin(states)) {
        iter = next(iter);
    } else if (iter == prev(std::cend(states))) {
        iter = prev(iter);
    }

    std::array<double, 2> firstOrder{0};
    firstOrder[0] = ((timeStamped - iter->timeStamp) * prev(iter)->angle -
                     (timeStamped - prev(iter)->timeStamp) * iter->angle) /
                    (prev(iter)->timeStamp - iter->timeStamp);
    firstOrder[1] = ((timeStamped - next(iter)->timeStamp) * iter->angle -
                     (timeStamped - iter->timeStamp) * next(iter)->angle) /
                    (iter->timeStamp - next(iter)->timeStamp);
    double secondOrder{
            ((timeStamped - next(iter)->timeStamp) * firstOrder[0] -
             (timeStamped - prev(iter)->timeStamp) * firstOrder[1]) /
            (prev(iter)->timeStamp - next(iter)->timeStamp)
    };
    return WheelState{secondOrder, timeStamped};
}

std::optional<WheelState> omniodom::WheelRecord::latestState() {
    if (std::size(states) < 3) {
        return std::optional<WheelState>{};
    }

    return interpolate(timer.now(), std::cbegin(states));
}

omniodom::WheelRecord::WheelRecord(omniodom::timer &timer) : timer(timer) {}

void omniodom::WheelRecord::insertRecord(double angle) {
    states.push_front(WheelState{angle, timer.now()});
}

