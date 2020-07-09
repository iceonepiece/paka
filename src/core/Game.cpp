#include "./Game.hpp"

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

Game::Game() {
  this->isRunning = false;
}

Game::~Game() {}

void Game::initialize(int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }

  window = SDL_CreateWindow(
    NULL,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    NULL
  );

  if (!window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }

  this->isRunning = true;
}

void Game::processInput() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT: {
      isRunning = false;
      break;
    }
    case SDL_KEYDOWN: {
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
      }
    }
    default: {
      break;
    }
  }
}

void Game::update() {
  int waitTime = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
  if (waitTime > 0 && waitTime <= FRAME_TARGET_TIME) SDL_Delay(waitTime);
  float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
  ticksLastFrame = SDL_GetTicks();

  // start your logics

  for (int i = 0; i < this->gameObjects.size(); i++) {
    this->gameObjects[i]->update(deltaTime);
  }

  // end your logic
}

void Game::render() {
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
  SDL_RenderClear(this->renderer);

  // start your logic

  for (int i = 0; i < this->gameObjects.size(); i++) {
    this->gameObjects[i]->render(this->renderer);
  }

  // end your logic

  SDL_RenderPresent(this->renderer);
}

void Game::destroy() {
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}
