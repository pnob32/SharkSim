#include "Window.h"

Window::Window(
   int _width,
   int _height,
   const char* title) {
   // Default attribute values
   start_time = glfwGetTime();
   time = 0;
   frames = 0;
   dt = 0.0f;
   prev_time = 0.0;
   prev_frames = 0;
   prev_second = 0.0;

   // Defined attribute values
   width = _width;
   height = _height;

   // Initialise GLFW
   if (!glfwInit()) {
      fprintf( stderr, "Failed to initialize GLFW\n" );
      exit(-1);
   }
   glfwWindowHint(GLFW_SAMPLES, 4);
   glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

   glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
   if (glfw_window == NULL) {
      fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
      glfwTerminate();
      exit(-1);
   }
   glfwMakeContextCurrent(glfw_window);

   glfwSetInputMode(glfw_window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we "hear" ESC
   hideMouse();
}

Window::~Window() {
   printf("terminating glfw\n");
   glfwTerminate();
}

void Window::drawText(char *string, float x, float y) {
   glColor3f(1.0f, 1.0f, 1.0f);   
   glRasterPos2f(x, y);
}

/**
 * @return Whether this window is still alive or has been closed by the user.
 */
bool Window::isActive() {
   return glfwGetKey(glfw_window, GLFW_KEY_ESCAPE) != GLFW_PRESS
      && glfwWindowShouldClose(glfw_window) == 0;
}

float Window::getElapsedTime() {
   return (float)(time - start_time);
}

void Window::step() {
   time = glfwGetTime();
   frames++;
   dt = (float)(time - prev_time);

   // Check if a second has passed
   if (time - prev_second >= 1) {
      int df = frames - prev_frames;

      fps = df/(time - prev_second);

      prev_frames = frames;
      prev_second = time;
   }

   prev_time = time;
}

void Window::showMouse() {
   glfwSetInputMode(glfw_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
/*
   // TODO upgrade to glfw 3.1 to use crosshair cursor
   // Use the crosshare cursor
   GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);
   glfwSetCursor(glfw_window, cursor);
*/
}

void Window::hideMouse() {
   glfwSetInputMode(glfw_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

