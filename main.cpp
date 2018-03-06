#include <iostream>
#include <memory>
#include <thread>
#include <functional>
#include <SDL.h>

bool g_quit = false;

void render_work(SDL_Window *win)
{
  auto screen = SDL_GetWindowSurface(win);

  while (!g_quit) {
  }
}

void event_work(SDL_Window *win)
{
  while (!g_quit) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        g_quit = true;
        break;
      }
    }
  }
}

int main()
{
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
    std::cout << "unable to initialize SDL: " << SDL_GetError();
    return -1;
  }

  auto win = SDL_CreateWindow(
      "gba emulator",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      640,
      480,
      SDL_WINDOW_SHOWN);

  auto render_thread = std::thread(std::bind(render_work, win));
  event_work(win);
  render_thread.join();

  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
