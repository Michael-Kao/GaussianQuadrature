#pragma once

#include <vector>
#include "Object.h"

class Drawer {
public:
    Drawer(std::vector<float> _data);
    GLuint vbo, ebo;
    struct ObjectInfo info;
    void draw() const;
private:
    GLuint vao;
    void assignData();
    std::vector<float> data;
};