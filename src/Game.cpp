#include "Game.h"

Game::Game(){
}

Game::~Game(){
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
  int flags = SDL_WINDOW_OPENGL;
  if(fullscreen){
    flags = flags | SDL_WINDOW_FULLSCREEN;
  }

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    std::cout << "SDL INITIALIZED!" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window){
      std::cout << "window created" << std::endl;
    }

    SDL_GL_CreateContext(window);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetSwapInterval(1);

    glewExperimental = GL_TRUE;
    glewInit();
    isRunning = true;
  }

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
  ModManager* mm = new ModManager();
  mm->init();
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
}

void Game::clean(){
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "cleaned up" << std::endl;
}
