#include <iostream>

// 1️⃣ **全局变量**
static int g_static_var = 10;          // 仅限本文件使用
const int g_const_var = 20;            // 只读全局变量
static const int g_static_const_var = 30; // 仅限本文件的只读变量

// 2️⃣ **静态函数**
static void staticFunctionOnlyInThisFile() {
    std::cout << "This function is only accessible in this file." << std::endl;
}

// 3️⃣ **static 和 const 变量**
void demoStaticConst() {
    static int staticVar = 100;    // 局部静态变量，生命周期贯穿整个程序
    const int constVar = 200;      // 只读变量，必须初始化
    static const int staticConstVar = 300; // 只读静态变量

    std::cout << "staticVar: " << staticVar++ << ", constVar: " << constVar << std::endl;
}

// 4️⃣ **const 指针**
void demoConstPointer() {
    char str1[] = "Hello";
    char str2[] = "World";

    const char *p1 = str1;  // ✅ p1 可以修改指向，但 *p1 不能改
    char *const p2 = str1;  // ✅ p2 指向固定，但 *p2 可以改
    const char *const p3 = str1; // ❌ p3 既不能改指向，也不能改值

    p1 = str2;   // ✅ 修改指向
    // p1[0] = 'X';  // ❌ 错误，p1 指向的内容不可修改

    // p2 = str2;  // ❌ 错误，p2 不能修改指向
    p2[0] = 'X';  // ✅ 修改内容

    // p3 = str2;  // ❌ 错误，p3 不能修改指向
    // p3[0] = 'X';  // ❌ 错误，p3 指向的内容也不能修改

    std::cout << "p1: " << p1 << ", p2: " << p2 << std::endl;
}

// 5️⃣ **static 和 const 在类中**
class MyClass {
public:
    static int staticCount; // ✅ 所有对象共享
    const int id;           // ✅ 只读变量，必须在构造函数初始化

    MyClass(int num) : id(num) {
        staticCount++;
    }

    static void printStatic() { // ✅ 静态成员函数，不依赖对象
        std::cout << "staticCount: " << staticCount << std::endl;
    }
};

// ✅ 静态变量必须在类外初始化
int MyClass::staticCount = 0;

// 6️⃣ **const 形参**
void printConstReference(const std::string &str) {
    // str.append("!");  // ❌ 错误，防止修改字符串
    std::cout << "Const Reference: " << str << std::endl;
}

// 7️⃣ **const 成员函数**
class Demo {
private:
    int value;

public:
    Demo(int val) : value(val) {}

    void setValue(int val) { value = val; }

    int getValue() const { // ✅ const 成员函数，不能修改对象状态
        // value = 10; // ❌ 错误，const 成员函数不能修改成员变量
        return value;
    }
};

// 8️⃣ **static 和 const 结合**
class StaticConstDemo {
public:
    static const int staticConstValue = 42; // ✅ 静态常量，类内可直接赋值
};

// 9️⃣ **main 函数**
int main() {
    // 1️⃣ 调用 static 函数
    demoStaticConst();
    demoStaticConst();

    // 2️⃣ const 指针示例
    demoConstPointer();

    // 3️⃣ static 变量和 const 变量在类中
    MyClass obj1(1), obj2(2);
    MyClass::printStatic(); // ✅ 访问静态成员函数

    // 4️⃣ const 成员函数
    Demo demoObj(100);
    std::cout << "demoObj.getValue(): " << demoObj.getValue() << std::endl;

    // 5️⃣ 静态常量
    std::cout << "Static Const Value: " << StaticConstDemo::staticConstValue << std::endl;

    return 0;
}
