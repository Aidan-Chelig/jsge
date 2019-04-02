#include "Game.h"
#include <iostream>

Game* game = nullptr;


int main(int argc, char* argv[]){
 

  game = new Game();
  game->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false, argv[0]);
  while (game->running()) {
    game->handleEvents();
    game->update();
    game->render();

  }

  game->clean();

  return 0;
}
