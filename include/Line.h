#pragma once 

/*
https://stackoverflow.com/questions/3484260/opengl-line-width
*/

#include "Object.h"

class Line {
public:
    Line(glm::ivec2 _x, glm::ivec2 _y, int _interval);
    GLuint vbo[2], ebo[2];
    struct ObjectInfo xinfo, yinfo;
    void drawX() const;
    void drawY() const;
private:
    glm::ivec2 x, y;
    int interval;
    GLuint vao[2];
    void CreateLine();
};