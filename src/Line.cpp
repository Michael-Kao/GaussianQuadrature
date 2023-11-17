#include "Line.h"


Line::Line(glm::ivec2 _x, glm::ivec2 _y, int _interval = 1) 
    : x(_x), y(_y), interval(_interval) {
    CreateLine();
}

void Line::CreateLine() {
    if(interval < 1) {
        std::cout << "Interval Error\n";
        return;
    }
    double hx = 1.0 * (x.y - x.x) / interval;
    double hy = 1.0 * (y.y - y.x) / interval;

    for(int i = 0; i < interval; i++) {
        xinfo.vertices.emplace_back(
            x.x + i       * hx,
            0.0,
            0.0
        );
    }
    for(int i = 0; i < xinfo.vertices.size(); i++) {
        xinfo.vertexIndices.push_back(i);
        xinfo.vertexIndices.push_back(i + 1);
    }

    for(int i = 0; i < interval; i++) {
        yinfo.vertices.emplace_back(
            0.0,
            y.x + i       * hy,
            0.0
        );
    }
    for(int i = 0; i < yinfo.vertices.size(); i++) {
        yinfo.vertexIndices.push_back(i);
        yinfo.vertexIndices.push_back(i + 1);
    }

    xinfo.vertexSize      = xinfo.vertices.size()      * sizeof(glm::vec3);
    xinfo.vertIndicesSize = xinfo.vertexIndices.size() * sizeof(unsigned int);
    yinfo.vertexSize      = yinfo.vertices.size()      * sizeof(glm::vec3);
    yinfo.vertIndicesSize = yinfo.vertexIndices.size() * sizeof(unsigned int);

    glGenVertexArrays(2, vao);
    glBindVertexArray(vao[0]);
    
    glGenBuffers(2, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, xinfo.vertexSize, xinfo.vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(2, ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, xinfo.vertIndicesSize, xinfo.vertexIndices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

    glBindVertexArray(vao[1]);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, yinfo.vertexSize, yinfo.vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, yinfo.vertIndicesSize, yinfo.vertexIndices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
}

void Line::drawX() const {
    if(interval < 1) {
        std::cout << "Interval Error\n";
        return;
    }

    glBindVertexArray(vao[0]);
    glDrawElements(GL_LINES, xinfo.vertexIndices.size(), GL_UNSIGNED_INT, 0);
}

void Line::drawY() const {
    if(interval < 1) {
        std::cout << "Interval Error\n";
        return;
    }

    glBindVertexArray(vao[1]);
    glDrawElements(GL_LINES, yinfo.vertexIndices.size(), GL_UNSIGNED_INT, 0);
}