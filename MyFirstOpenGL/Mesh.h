#pragma once
#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm.hpp>

class Mesh {
public:

    Mesh() {};
    Mesh(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals);
    void Render() const;

    GLuint VAO, VBO, uvVBO;
    unsigned int numVertexs;

    
};

#endif
