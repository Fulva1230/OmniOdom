//
// Created by fulva on 2020/10/6.
//

#ifndef OMNIODOM_TIMER_H
#define OMNIODOM_TIMER_H

namespace omniodom {
    class timer {
    public:
        virtual long now() = 0;

        virtual ~timer() {};
    };
}


#endif //OMNIODOM_TIMER_H
