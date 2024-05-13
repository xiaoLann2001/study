#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& l) {
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int v1, int v2) {
    return v1 > v2;
}

void test1() {
    // list容器的特点
    // 1. 链表是一种线性表（STL中的list是双向循环链表：每个节点的指针域有两个指针（前驱和后继），+头节点的前驱是尾节点，尾节点的后继是头节点）
    // 2. 链表的每个元素都是一个节点
    // 3. 链表的每个节点都包含两个部分：数据域和指针域
    // 4. 链表的第一个节点叫做头节点
    // 5. 链表的最后一个节点叫做尾节点
    // 6. 链表的头节点不存储数据
    // 7. 链表的尾节点的指针域指向NULL
    // 8. 链表的节点通过指针域连接在一起
    // 9. 链表的节点在内存中不是连续存储的
    // 10. 链表提供的操作有：push_back, push_front, pop_back, pop_front, insert, erase, clear, size, empty, front, back

    // 链表的优点
    // 1. 链表的插入和删除操作效率高，插入删除不会造成已有迭代器失效
    // 2. 链表的内存利用率高
    
    // 链表的缺点
    // 1. 链表的随机访问效率低
    // 2. 链表的存储空间开销大

    cout << "------------------test1------------------" << endl;
    // list的构造函数
    list<int> l1;   // 默认构造
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    printList(l1);

    list<int> l2(l1.begin(), l1.end());    // 区间构造
    printList(l2);

    list<int> l3(l2);   // 拷贝构造
    printList(l3);

    list<int> l4(10, 100);  // 10个100
    printList(l4);

}

void test2() {
    // list容器的赋值操作和交换操作
    // list& operator=(const list& l);
    // void swap(list& l);

    cout << "------------------test2------------------" << endl;

    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    printList(l1);

    list<int> l2;
    l2 = l1;        // operator=赋值
    printList(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());    // assign赋值
    printList(l3);

    list<int> l4;
    l4.assign(10, 100); // 10个100
    printList(l4);

    l1.swap(l4);    // 交换
    printList(l1);
    printList(l4);
}

void test3() {
    // list容器的大小操作
    // size();
    // empty();
    // resize(int n, const T& val = T());

    cout << "------------------test3------------------" << endl;

    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    printList(l1);

    cout << "size: " << l1.size() << endl;
    cout << "empty: " << l1.empty() << endl;

    l1.resize(10, 100);
    printList(l1);

    l1.resize(2);
    printList(l1);
}

void test4() {
    // list容器的插入和删除操作
    // push_back(const T& val);                                 // 尾插
    // pop_back();                                              // 尾删
    // push_front(const T& val);                                // 头插
    // pop_front();                                             // 头删
    // insert(iterator pos, const T& val);                      // 在pos位置插入val
    // insert(iterator pos, int count, const T& val);           // 在pos位置插入count个val
    // insert(iterator pos, iterator first, iterator last);     // 在pos位置插入区间
    // erase(iterator pos);                                     // 删除pos位置
    // erase(iterator first, iterator last);                    // 删除区间
    // remove(const T& val);                                    // 删除指定值
    // clear();                                                 // 清空

    cout << "------------------test4------------------" << endl;

    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    printList(l1);

    l1.pop_back();
    l1.pop_front();
    printList(l1);

    list<int>::iterator it = l1.begin();
    it++;
    l1.insert(it, 1000);
    printList(l1);

    it = l1.begin();
    l1.erase(it);
    printList(l1);

    l1.push_back(1000);
    l1.push_back(1000);
    l1.push_back(1000);
    printList(l1);
    l1.remove(1000);
    printList(l1);

    l1.clear();
    printList(l1);

}

void test5() {
    // list容器的存取操作
    // front();         // 返回第一个元素
    // back();          // 返回最后一个元素
    // list容器没有提供[]操作符
    // list容器没有提供at操作函数
    // 因为链表不支持随机访问

    cout << "------------------test5------------------" << endl;

    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    cout << "front: " << l1.front() << endl;

    cout << "back: " << l1.back() << endl;

    // 验证链表不支持随机访问
    list<int>::iterator it = l1.begin();
    it++;
    cout << *it << endl;
    it--;
    cout << *it << endl;
    // it = it + 1;    // error，链表不支持随机访问
    // it = it + n;    // error，链表不支持随机访问
}

void test6() {
    // list容器的反转和排序
    // reverse();       // 反转
    // sort();          // 排序

    cout << "------------------test6------------------" << endl;

    list<int> l1;
    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(5);
    l1.push_back(3);
    l1.push_back(4);
    printList(l1);

    l1.reverse();
    printList(l1);

    // sort(l1.begin(), l1.end());    // 所有不支持随机访问的容器都不支持全局算法

    l1.sort();      // 默认升序
    printList(l1);

    list<int> l2;
    l2 = l1;
    l2.sort(greater<int>());    // 降序，greater<int>()是函数对象
    printList(l2);

    list<int> l3;
    l3 = l1;
    l3.sort(myCompare);         // 降序，myCompare是回调函数
    printList(l3);


}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}