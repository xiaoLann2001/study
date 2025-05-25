#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <stdio.h>

#include "Shape.h"

// 类定义
typedef struct {
    Shape base;     // 父类放在第一个成员
    int width;
    int height;
} Rectangle;

/* 
父类结构体必须放在子类结构体的“第一个成员”位置，是为了实现：子类向父类的安全转换（upcast）
Shape* shape = (Shape*)&rect; 这个强转是合法的且内存对齐不变，因为：rect 的地址就是 base 的地址；
所以 Shape* shape 访问 shape->draw 时，恰好就是访问 rect.base.draw，不会出错。
*/

// 成员函数
void Rectangle_draw(Shape* shape);

void Rectangle_init(Rectangle* self, int w, int h);

#endif  // __RECTANGLE_H__