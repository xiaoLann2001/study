#include "Shape.h"

void Shape_draw(Shape* self) {
    if (self->draw)
        self->draw(self);
}