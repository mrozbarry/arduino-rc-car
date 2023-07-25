#pragma once

class Tickable {
  public:
      virtual ~Tickable() {};
      
      virtual void setup() = 0;
      virtual void tick() = 0;
};