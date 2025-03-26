#include <iostream>
#include <cstddef> // 为了使用 offsetof

// 为了满足成员对齐要求，编译器可能会在结构体成员之间插入填充字节（Padding）。这些填充字节通常不会影响数据的逻辑含义，但它们会增加结构体的总大小。

// 打印一个结构体在内存中的大小，结构体的对齐要求通常是它最大成员类型的对齐要求
struct AlignedStruct {
    char a;     // 1 字节
    char b;     // 1 字节
    char c;     // 1 字节
    int d;      // 4 字节，通常需要 4 字节对齐，因此 d 会被放置在 4 字节对齐的地址上，因此在 c 和 d 之间会插入 1 个填充字节
};

// 改变排列顺序
struct AlignedStructChangeOrder {
    char a;     // 1 字节
    int b;      // 4 字节，通常需要 4 字节对齐，因此 b 会被放置在 4 字节对齐的地址上，因此在 a 和 b 之间会插入 3 个填充字节
    char c;     // 1 字节，由于结构体的对齐要求通常为最大成员的对齐要求（即 int 的 4 字节对齐），
                // 所以 c 会紧跟在 b 后面，之后会进行填充，确保结构体的总大小为 4 字节的倍数。
};

// 使用 __attribute__((aligned)) 强制设置对齐方式
struct AlignedStructWithAlignment {
    char a;     // 1 字节
    int b;      // 4 字节，对齐到 4 的倍数
    char c;     // 1 字节，其后会填充字节，使结构体总大小为 8 的倍数
} __attribute__((aligned(8)));  // 强制按 8 字节对齐，结构体总大小会填充到 8 字节的倍数

int main() {
    AlignedStruct s;
    std::cout << "Size of AlignedStruct: " << sizeof(s) << " bytes\n";
    std::cout << "Offset of a: " << offsetof(AlignedStruct, a) << " bytes\n";
    std::cout << "Offset of b: " << offsetof(AlignedStruct, b) << " bytes\n";
    std::cout << "Offset of c: " << offsetof(AlignedStruct, c) << " bytes\n";
    std::cout << "Offset of d: " << offsetof(AlignedStruct, d) << " bytes\n";

    AlignedStructChangeOrder s1;
    std::cout << "Size of AlignedStructChangeOrder: " << sizeof(s1) << " bytes\n";
    std::cout << "Offset of a: " << offsetof(AlignedStructChangeOrder, a) << " bytes\n";
    std::cout << "Offset of b: " << offsetof(AlignedStructChangeOrder, b) << " bytes\n";
    std::cout << "Offset of c: " << offsetof(AlignedStructChangeOrder, c) << " bytes\n";

    AlignedStructWithAlignment s2;
    std::cout << "Size of AlignedStructWithAlignment: " << sizeof(s2) << " bytes\n";
    std::cout << "Offset of a: " << offsetof(AlignedStructWithAlignment, a) << " bytes\n";
    std::cout << "Offset of b: " << offsetof(AlignedStructWithAlignment, b) << " bytes\n";
    std::cout << "Offset of c: " << offsetof(AlignedStructWithAlignment, c) << " bytes\n";

    return 0;
}
