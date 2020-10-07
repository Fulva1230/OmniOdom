//
// Created by fulva on 2020/10/6.
//

#ifndef OMNIODOM_WHEELRECORDER_H
#define OMNIODOM_WHEELRECORDER_H

#include "anglesensor.h"
#include "wheelrecord.h"

namespace omniodom {
    class WheelRecorder {
    public:

    public:
        WheelRecorder(omniodom::AngleSensor &angleSensor, omniodom::WheelRecord &wheelRecord);

        void record();
    private:
        AngleSensor &angleSensor;
        WheelRecord &wheelRecord;
    };
}

#endif //OMNIODOM_WHEELRECORDER_H
