/*
 * Pattern sourced from Design Patterns / Game Programming Patterns
 */

#pragma once

#include "Actor.h"

class Command {
 public:
  virtual void execute(Actor& actor){};
};

class MoveUp : public Command {
 public:
  void execute(Actor& actor) { actor.moveUp(); }
};

class MoveLeft : public Command {
 public:
  void execute(Actor& actor) { actor.moveLeft(); }
};

class MoveDown : public Command {
 public:
  void execute(Actor& actor) { actor.moveDown(); }
};

class MoveRight : public Command {
 public:
  void execute(Actor& actor) { actor.moveRight(); }
};
