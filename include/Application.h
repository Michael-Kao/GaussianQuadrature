#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Window.h"
#include "Object.h"
#include "Shader.h"
#include "Camera.h"
#include "Line.h"
#include "GaussianQuadrature.h"
#include "Drawer.h"

class Application{
public:
    Application(Window *wnd_ptr);
    Application();
    ~Application();
    void run();
private:
    Window *m_window;
    Object *m_cube;
    Shader *m_shader;
    Camera *m_camera;
    Line   *m_lines;
    GaussianQuadrature *m_gaussian;
    Drawer *m_drawer;
    void Init();
    void drawTest();
    void processCamera(float delta_time);
    void processInput();
    void drawLine();
};