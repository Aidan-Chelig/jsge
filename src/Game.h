#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"
#include "Mods/ModManager.h"

class Game {
  
public:
  Game();
  ~Game();

  void init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen, char* argv);
  
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return isRunning; }

private:
  bool isRunning = false;
  SDL_Window *window;
  SDL_GLContext context;
};

#endif /* Game_h */
