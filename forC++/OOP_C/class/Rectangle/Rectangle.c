#include "Rectangle.h"

void Rectangle_draw(Shape* shape) {
    Rectangle* self = (Rectangle*)shape;
    printf("Draw Rectangle: %d x %d\n", self->width, self->height);
}

void Rectangle_init(Rectangle* self, int w, int h) {
    self->base.draw = Rectangle_draw;
    self->width = w;
    self->height = h;
}