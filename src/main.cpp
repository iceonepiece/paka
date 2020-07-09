#include "./core/Game.hpp"

int main(int argc, char *args[]) {
  Game *game = new Game();

  game->initialize(800, 600);

  while (game->isRunning) {
    game->processInput();
    game->update();
    game->render();
  }

  game->destroy();

  return 0;
}
