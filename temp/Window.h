#ifndef __Window__
#define __Window__

#include "includes.h"

class Window {
   public:
      GLFWwindow* glfw_window;
      int width;
      int height;
      double time;
      long frames;
      float dt;
      float fps;

      Window(
         int _width,
         int _height,
         const char* title);
      virtual ~Window();

      void drawText(char* string, float x, float y);
      bool isActive();
      void step();
      void showMouse();
      void hideMouse();
      float getElapsedTime();
   private:
      double start_time;
      double prev_time;
      long prev_frames;
      double prev_second;
};

#endif
