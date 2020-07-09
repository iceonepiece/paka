#pragma once
#include <vector>
#include <SDL2/SDL.h>

class GameObject {
public:
  virtual void update(float deltaTime) = 0;
  virtual void render(SDL_Renderer *renderer) = 0;
};
