#pragma once

#include "ofMain.h"

class IntegrationStrategy {
 public:
  virtual void integrate() = 0;
};

class ActorIntegrationStrategy : public IntegrationStrategy {
 public:
  void integrate() override;
};

class PlayerIntegrationStrategy : public IntegrationStrategy {
 public:
   void integrate() override;
};
