//
// Created by fulva on 2020/10/6.
//

#ifndef OMNIODOM_ANGLESENSOR_H
#define OMNIODOM_ANGLESENSOR_H

namespace omniodom {
    class AngleSensor {
    public:
        virtual ~AngleSensor() = 0;

        virtual double read() = 0;
    };
}

#endif //OMNIODOM_ANGLESENSOR_H
