//
// Created by fulva on 2020/10/6.
//

#include "wheelrecorder.h"

void omniodom::WheelRecorder::record() {
    wheelRecord.insertRecord(angleSensor.read());
}

omniodom::WheelRecorder::WheelRecorder(omniodom::AngleSensor &angleSensor, omniodom::WheelRecord &wheelRecord)
        : angleSensor(angleSensor), wheelRecord(wheelRecord) {}
