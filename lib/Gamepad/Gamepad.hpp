#pragma once

class Gamepad {
  public:
    struct State {
      public:
        bool a, b, x, y;
        bool shoulderLeft, shoulderRight;
        bool triggerLeft, triggerRight;
        bool up, down, left, right;

        long leftJoyX, leftJoyY;
        long rightJoyX, rightJoyY;

        short battery;
    };


    virtual bool getState(State *currentState) = 0;
};
