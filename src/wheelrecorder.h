//
// Created by fulva on 2020/10/6.
//

#ifndef OMNIODOM_WHEELRECORDER_H
#define OMNIODOM_WHEELRECORDER_H

#include "anglesensor.h"

namespace omniodom {
    class WheelRecorder {
    public:
        WheelRecorder(AngleSensor &angleSensor);

    public:
        void record(){
            //TODO
        };
    private:
        AngleSensor &angleSensor;

    };
}

#endif //OMNIODOM_WHEELRECORDER_H
