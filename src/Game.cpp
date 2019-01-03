#include "Game.hpp"

SDL_Texture* playerTex;


Game::Game(){

}

Game::~Game(){

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
  int flags = 0;
  if(fullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    std::cout << "SDL INITIALIZED!" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window){
      std::cout << "window created" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer){
      SDL_SetRenderDrawColor(renderer, 255,255,255,255);
      std::cout << "renderer created" << std::endl;
    }
    isRunning = true;
  } else {
    isRunning = false;
  }
  SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
  playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);

}

void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type){
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }


}

void Game::update(){

}

void Game::render(){
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, playerTex, NULL, NULL);
  SDL_RenderPresent(renderer);

}

void Game::clean(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "cleaned up" << std::endl;

}
