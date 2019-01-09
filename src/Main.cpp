#include "Game.h"
#include "Globals/Globals.h"

Game* game = nullptr;

int main(){
  std::cout << Globals::getModDir() << std::endl;

  game = new Game();
  game->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
  while (game->running()) {
    game->handleEvents();
    game->update();
    game->render();

  }

  game->clean();

  return 0;
}
