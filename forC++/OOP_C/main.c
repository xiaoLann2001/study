#include <stdio.h>

#include "Shape.h"
#include "Rectangle.h"

int main() {
    Rectangle rect;
    Rectangle_init(&rect, 10, 20);

    Shape* shape = (Shape*)&rect;
    Shape_draw(shape);  // 多态调用 Rectangle_draw

    return 0;
}