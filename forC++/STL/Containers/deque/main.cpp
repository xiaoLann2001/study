#include <iostream>
#include <deque>
#include <algorithm>

void printDeque(const std::deque<int>& d) { // 使用const引用是因为不需要修改容器中的元素
    // 使用const_iterator是因为不需要修改容器中的元素，防止*it = 100这种写操作
    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test1() {
    /// deque和vector的区别
    // 1. vector是单向扩容，deque是双向扩容
    // 2. vector在尾部插入、删除元素效率高，deque在头部插入、删除元素效率高
    // 3. vector在中间插入元素效率低，deque在中间插入元素效率高
    
    /// deque内部工作原理
    // 1. deque是一个动态数组，内部维护了一个指向块（缓冲区）的指针数组（中控器），块是一个固定大小的数组
    // 2. deque内部有两个指针，一个指向块的头部，一个指向块的尾部
    // 3. 当在头部插入元素时，如果头部指针指向的块已经满了，就会在头部插入一个新的块
    // 4. 当在尾部插入元素时，如果尾部指针指向的块已经满了，就会在尾部插入一个新的块
    // 5. 当在头部删除元素时，如果头部指针指向的块只有一个元素，就会删除这个块
    // 6. 当在尾部删除元素时，如果尾部指针指向的块只有一个元素，就会删除这个块
    // 7. 当在中间插入元素时，会根据插入位置选择一个指针，然后在这个指针指向的块中插入元素
    // 8. 当在中间删除元素时，会根据删除位置选择一个指针，然后在这个指针指向的块中删除元素

    // deque容器的迭代器也是支持随机访问的

    // deque容器的构造函数
    std::deque<int> d1; // 默认构造函数
    std::deque<int> d2(10); // 指定大小的构造函数
    std::deque<int> d3(10, 5); // 指定大小和初始值的构造函数
    std::deque<int> d4(d3); // 拷贝构造函数
    std::deque<int> d5(d3.begin(), d3.end()); // 区间构造函数

    // deque容器的插入和删除操作
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);    // 尾部插入
    }
    printDeque(d1);
    d1.pop_back();          // 尾部删除
    printDeque(d1);
    d1.push_front(100);     // 头部插入
    printDeque(d1);
    d1.pop_front();         // 头部删除
    printDeque(d1);
    d1.insert(d1.begin(), 1000); // 在指定位置插入元素，支持区间插入
    printDeque(d1);
    d1.erase(d1.begin());       // 删除指定位置的元素，支持区间删除
    printDeque(d1);
    d1.clear();                 // 清空容器
    printDeque(d1);

    // deque容器的赋值操作
    d1.assign(10, 1);
    d2 = d1; // 重载=操作符
    d3.assign(d1.begin(), d1.end()); // 区间赋值
    d4.assign(10, 100); // 指定大小和初始值赋值
    printDeque(d2);
    printDeque(d3);
    printDeque(d4);

    // deque容器的大小操作
    std::cout << "d1.size() = " << d1.size() << std::endl;
    std::cout << "d1.empty() = " << d1.empty() << std::endl;
    d1.resize(15, -1); // 如果新的大小比原来的大，会在尾部插入元素，如果新的大小比原来的小，会在尾部删除元素
    printDeque(d1);
    d1.resize(5); // 如果新的大小比原来的大，会在尾部插入元素，如果新的大小比原来的小，会在尾部删除元素
    printDeque(d1);

    // deque容器的数据存取操作
    std::cout << "d1[0] = " << d1[0] << std::endl;
    std::cout << "d1.at(0) = " << d1.at(0) << std::endl;
    std::cout << "d1.front() = " << d1.front() << std::endl;
    std::cout << "d1.back() = " << d1.back() << std::endl;

    // 对deque容器进行排序
    std::deque<int> d6;
    d6.push_back(3);
    d6.push_back(1);
    d6.push_back(2);
    d6.push_back(5);
    d6.push_back(4);
    printDeque(d6);

    // 对于支持随机访问的容器，可以使用sort进行排序，如vector、deque
    std::sort(d6.begin(), d6.end());    // 默认从小到大排序
    printDeque(d6);



}

int main() {
    test1();

    return 0;
}
