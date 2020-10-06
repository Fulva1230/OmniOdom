//
// Created by fulva on 2020/10/6.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "timer.h"
#include "wheelrecord.h"

using ::testing::Return;

class MockTimer : public omniodom::timer {
public:
    MOCK_METHOD(long, now, (), (override));
};


TEST(omniodom, wheelrecord) {
    MockTimer mockTimer{};
    omniodom::WheelRecord wheelRecord{mockTimer};
    EXPECT_CALL(mockTimer, now())
            .WillOnce(Return(100))
            .WillOnce(Return(200))
            .WillOnce(Return(300))
            .WillOnce(Return(400))
            .WillOnce(Return(500))
            .WillRepeatedly(Return(600));

    wheelRecord.insertRecord(10);
    wheelRecord.insertRecord(20);
    wheelRecord.insertRecord(30);
    wheelRecord.insertRecord(40);

    ASSERT_EQ(wheelRecord.latestState().value().angle, 50);
    ASSERT_EQ(wheelRecord.latestState().value().timeStamp, 600);
    ASSERT_EQ(wheelRecord.stateAt(150).value().angle, 15);
}
