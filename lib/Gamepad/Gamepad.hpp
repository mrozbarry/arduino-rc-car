#pragma once

class Gamepad {
  public:
    struct Joy {
      long x;
      long y;
    };
    struct State {
      bool a, b, x, y;
      bool shoulderLeft, shoulderRight;
      bool triggerLeft, triggerRight;
      bool up, down, left, right;

      Joy left_joy;
      Joy right_joy;

      short battery;

      long updated_at;
    };

    Gamepad() {}


    virtual bool getState(State *currentState) = 0;

  protected:
    State state;
};
