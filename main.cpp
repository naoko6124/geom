#include <iostream>
#include "geom.h"

int main(int argc, char** argv)
{
    geom obj;
    obj.vertices = {
        { {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f} },
        { {1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f} },
        { {-1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f} },
        { {-1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f} },
    };
    obj.indices = {
        0, 1, 2,
        1, 2, 3
    };
    obj.write("test.geom");

    geom copy;
    copy.read("test.geom");

    printf("vertices\n");
    for (auto& v : copy.vertices)
    {
        printf("(%.0f, %.0f, %.0f) (%.0f, %.0f, %.0f) (%.0f, %.0f)\n",
        v.position[0], v.position[1], v.position[2],
        v.normal[0], v.normal[1], v.normal[2],
        v.uv[0], v.uv[1]);
    }

    printf("indices\n");
    for (auto& i : copy.indices)
    {
        printf("%d, ", i);
    }
}