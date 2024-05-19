#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <GL/glew.h>
#include "GameObject.h"

class Model : public GameObject {
public:
    Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals);
    void Render() const;

    GLuint VAO, VBO, uvVBO;
    unsigned int numVertexs;
};

#endif
