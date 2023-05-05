#ifndef NDC_MODEL_H
#define NDC_MODEL_H

#include <vector>

#include "vec.h"

class Model {
public:
    Model(const char* filename);
    ~Model();

    size_t num_vertices() const;
    size_t num_faces() const;
    Vec3f vertex(size_t index) const;
    std::vector<int> face(size_t index) const;

private:
    std::vector<Vec3f>            m_vertices;
    std::vector<std::vector<int>> m_faces;
};

#endif
