#include <algorithm>
#include <cmath>

#include "tgaimage.h"

// #include "geometry.h"
#include "vec.h"

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

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    image.set(52, 41, red);

    line(10, 20, 75, 52, image, white);
    line(20, 20, 40, 80, image, red);
    line(40, 20, 20, 80, image, red);

    image.flip_vertically();
    image.write_tga_file("../output.tga");

    Vec3f guh(1.2, 2.7, 3.14);
    std::cout << guh;

    return 0;
}
