#include <algorithm>
#include <cmath>

#include "tgaimage.h"

// #include "geometry.h"
#include "vec.h"
#include "model.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255,   0,   0, 255);

void line(int x0, int y0, int x1, int y1, 
          TGAImage &image, const TGAColor &color) {
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror = std::abs(dy) * 2;
    float error  = 0;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        if (steep) {
            image.set(y, x, color);
        } else {
            image.set(x, y, color);
        }
        error += derror;
        if (error > dx) {
            y += (y1 > y0) ? 1 : -1;
            error -= dx * 2;
        }
    }
}

void draw_wireframe_model(const Model &model, TGAImage &image, const TGAColor &color) {
    int width = image.get_width();
    int height = image.get_height();
    for (size_t i = 0; i < model.num_faces(); i++) {
        std::vector<int> face = model.face(i);
        for (size_t j = 0; j < 3; j++) {
            Vec3f v0 = model.vertex(face[j]);
            Vec3f v1 = model.vertex(face[(j + 1)%3]);
            float x0 = (v0.x + 1.0)*(width/2.0);
            float y0 = (v0.y + 1.0)*(height/2.0);
            float x1 = (v1.x + 1.0)*(width/2.0);
            float y1 = (v1.y + 1.0)*(height/2.0);
            line(x0, y0, x1, y1, image, color);
        }
    }
}

int main(int argc, char** argv) {
    // TGAImage image(100, 100, TGAImage::RGB);
    // image.set(52, 41, red);
    //
    // line(10, 20, 75, 52, image, white);
    // line(20, 20, 40, 80, image, red);
    // line(40, 20, 20, 80, image, red);
    //
    // image.flip_vertically();
    // image.write_tga_file("../output.tga");
    //
    // Vec3f guh(1.2, 2.7, 3.14);
    // Vec3f guh2(1.1, 2.6, 3.04);
    // Vec3f guh3 = guh + guh2;
    // std::cout << guh3;

    const int width = 1000;
    const int height = 1000;
    TGAImage image(width, height, TGAImage::RGB);
    Model model("../res/african_head.obj");
    std::cout << "Number of vertices: " << model.num_vertices() << "\n"
              << "Number of faces:    " << model.num_faces()    << "\n";

    draw_wireframe_model(model, image, white);

    image.flip_vertically();
    image.write_tga_file("../output.tga");

    return 0;
}
