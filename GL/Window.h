//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include <GLFW/glfw3.h>

namespace gl
{
    class Window
    {
        GLFWwindow* window;
    public:
        Window(int w, int h);
        ~Window();

        void Loop();

        bool Alive();
        void Kill();

        void CheckHandles();
    };
}