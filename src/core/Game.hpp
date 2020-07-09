#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "./GameObject.hpp"

class Game {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  int ticksLastFrame;
  std::vector<GameObject*> gameObjects;

public:
  bool isRunning;

  Game();
  ~Game();

  void initialize(int width, int height);
  void processInput();
  void update();
  void render();
  void destroy();
};
