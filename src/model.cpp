#include <fstream>
#include <sstream>
#include <string>

#include "model.h"

Model::Model(const char* filename) {
    // TODO: parse .obj file for vertices and faces
    std::ifstream file(filename);
    if (file.fail()) {
        std::cerr << "Failed to load model: " << filename << "\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream stream(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v ")) {
            stream >> trash;
            Vec3f vertex;
            stream >> vertex.x >> vertex.y >> vertex.z;
            m_vertices.push_back(vertex);
        } else if (!line.compare(0, 2, "f ")) {
            stream >> trash;
            std::vector<int> face;
            int itrash, index;
            while (stream >> index >> trash >> itrash >> trash >> itrash) {
                index--; // in .obj all indices start at 1
                face.push_back(index);
            }
            m_faces.push_back(face);
        }
    }
}

Model::~Model() {}

size_t Model::num_vertices() const {
    return m_vertices.size();
}

size_t Model::num_faces() const {
    return m_faces.size();
}

Vec3f Model::vertex(size_t index) const {
    return m_vertices[index];
}

std::vector<int> Model::face(size_t index) const {
    return m_faces[index];
}
