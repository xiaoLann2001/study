#include <iostream>
#include <set>

using namespace std;

// 自定义数据类型
class Person {
    public:
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }

        string name;
        int age;
};

// 仿函数
class MyCompare {
    public:
        bool operator()(int v1, int v2) {
            return v1 > v2;
        }
};

class MyComparePerson {
    public:
        bool operator()(const Person& p1, const Person& p2) {
            // 按照年龄降序排序
            return p1.age > p2.age;
        }
};

void printSet(const set<int>& s) {
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printSet(const multiset<int>& s) {
    for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printSet(const set<int, MyCompare>& s) {
    for (set<int, MyCompare>::const_iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// void printSet(const set<Person>& s) {
//     for (set<Person>::const_iterator it = s.begin(); it != s.end(); it++) {
//         cout << "姓名：" << it->name << " 年龄：" << it->age << endl;
//     }
// }

void printSet(const set<Person, MyComparePerson>& s) {
    for (set<Person, MyComparePerson>::const_iterator it = s.begin(); it != s.end(); it++) {
        cout << "姓名：" << it->name << " 年龄：" << it->age << endl;
    }
}

void test1() {
    // set容器的特点：
    // 1. set容器中的元素会自动排序，因为set容器底层是红黑树
    // 2. set容器中的元素不允许重复
    // 3. set容器中的元素只能读，不能写

    // set容器的构造函数
    // set<T> st; // 默认构造函数
    // set(const set &st); // 拷贝构造函数

    // set容器赋值操作
    // set& operator=(const set &st); // 重载等号操作符

    set<int> s1;
    s1.insert(20);   // set容器只有insert方法，没有push_back方法
    s1.insert(50);
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    printSet(s1);

    set<int> s2(s1);
    printSet(s2);

    set<int> s3;
    s3 = s1;
    printSet(s3);

}

void test2() {
    // set容器的大小操作
    // size(); // 返回容器中元素的数目
    // empty(); // 判断容器是否为空

    // set容器的交换操作
    // swap(st); // 将st与本身的元素互换

    set<int> s;
    s.insert(20);
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(40);
    printSet(s);

    if (s.empty()) {
        cout << "s为空" << endl;
    } else {
        cout << "s不为空" << endl;
        cout << "s的大小为：" << s.size() << endl;
    }

    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);
    s2.insert(500);

    s.swap(s2);
    printSet(s);
    printSet(s2);
}

void test3() {
    // set插入和删除操作
    // insert(elem); // 在容器中插入元素
    // clear(); // 清除所有元素
    // erase(pos); // 删除pos迭代器所指的元素，返回下一个元素的迭代器

    set<int> s;
    s.insert(20);
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(40);
    printSet(s);

    s.erase(s.begin()); // 删除第一个元素，与插入顺序无关
    printSet(s);

    s.erase(30);
    printSet(s);

    s.erase(s.begin(), s.end());
    printSet(s);

    s.clear();
    printSet(s);
}

void test4() {
    // set查找和统计操作
    // find(key); // 查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    // count(key); // 统计key的元素个数，对set来说，要么是0，要么是1

    set<int> s;
    s.insert(20);
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(40);
    printSet(s);

    set<int>::iterator it = s.find(30);
    if (it != s.end()) {
        cout << "找到了元素：" << *it << endl;
    } else {
        cout << "未找到元素" << endl;
    }

    int num = s.count(30);
    cout << "30的个数为：" << num << endl;

}

void test5() {
    // set容器和multiset的区别
    // set容器中的元素是唯一的，每个元素只能出现一次。当插入重复元素时，set容器会自动忽略重复的元素。
    // multiset容器中的元素可以重复出现，允许插入重复的元素。
    // 这意味着set容器中的元素是按照键值进行排序和存储的，而multiset容器中的元素则按照键值进行排序，但允许重复的键值存在。

    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second) {
        cout << "第一次插入成功" << endl;
    } else {
        cout << "第一次插入失败" << endl;
    }

    ret = s.insert(10);
    if (ret.second) {
        cout << "第二次插入成功" << endl;
    } else {
        cout << "第二次插入失败" << endl;
    }

    ret = s.insert(20);
    if (ret.second) {
        cout << "第三次插入成功" << endl;
    } else {
        cout << "第三次插入失败" << endl;
    }

    printSet(s);


    multiset<int> ms;
    ms.insert(10);  // multiset容器允许插入重复元素，返回值为迭代器
    ms.insert(10);
    ms.insert(20);
    printSet(ms);
    
}

void test6() {
    // pair对组
    // pair<T1, T2> p; // 构造对组
    // pair<T1, T2> p(val1, val2); // 拷贝构造
    // p = make_pair(val1, val2); // 通过make_pair函数创建对组
    // p.first; // 访问第一个数据
    // p.second; // 访问第二个数据

    pair<string, int> p("Tom", 20);
    cout << "姓名：" << p.first << " 年龄：" << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 30);
    cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;

    pair<string, int> p3 = p;
    cout << "姓名：" << p3.first << " 年龄：" << p3.second << endl;

    pair<string, int> p4;
    p4 = make_pair("Jack", 40);
    cout << "姓名：" << p4.first << " 年龄：" << p4.second << endl;


}

void test7() {
    // set容器的排序规则
    // set容器中的元素默认是按照升序排序的，如果想改变排序规则，可以自定义排序规则
    // set容器的排序规则是在创建set容器对象时通过仿函数指定的

    set<int, MyCompare> s;
    s.insert(20);
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(40);

    printSet(s);

    // set<Person> s2;
    // s2.insert(Person("Tom", 20));
    // s2.insert(Person("Jerry", 30));
    // s2.insert(Person("Jack", 40));

    // printSet(s2);   // 没有指定排序规则，报错，自定义数据类型需要指定排序规则

    set<Person, MyComparePerson> s2;
    s2.insert(Person("Tom", 20));
    s2.insert(Person("Jerry", 30));
    s2.insert(Person("Jack", 40));

    printSet(s2);


}

int main() {

    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();

    return 0;
}
