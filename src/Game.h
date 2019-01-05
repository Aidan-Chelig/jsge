#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"

class Game {
  
public:
  Game();
  ~Game();

  void init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
  
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

#endif /* Game_hpp */
