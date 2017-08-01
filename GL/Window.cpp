//
// Created by Göksu Güvendiren on 01/08/2017.
//

#include "Window.h"

namespace gl
{
    Window::Window(int w, int h)
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // require the OpenGL context to support OpenGL 3.2 at the least
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE,
                       GLFW_OPENGL_CORE_PROFILE); // specifies that we want a context that only supports the new core functionality
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        window = glfwCreateWindow(w, h, "OpenGL", nullptr, nullptr); // Windowed
        glfwMakeContextCurrent(window);
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::Loop()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::CheckHandles()
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    }

    bool Window::Alive()
    {
        CheckHandles();
        return !glfwWindowShouldClose(window);
    }
}