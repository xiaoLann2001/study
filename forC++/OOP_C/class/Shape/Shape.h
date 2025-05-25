#ifndef __SHAPE_H__
#define __SHAPE_H__

// 类定义
typedef struct Shape Shape; // 前向声明

/* 因为结构体里的成员 void (*draw)(Shape* self); 需要用到 Shape 类型自己。C 语言需要先知道 Shape 是一个合法的类型，才能接受它作为参数。*/

struct Shape{
    void (*draw)(Shape* self);  // 虚函数指针
};

// 成员函数
void Shape_draw(Shape* self);

#endif  // __SHAPE_H__