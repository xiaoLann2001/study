#include <iostream>
#include <map>
#include <string>

using namespace std;

class myCompare {
public:
    bool operator()(const int &v1, const int &v2) {
        return v1 > v2;
    }
};

void printMap(const map<int, string> m) {
    for (map<int, string>::const_iterator mit = m.begin(); mit != m.end(); mit++) {
        cout << mit->first << " " << mit->second << endl;
    }
    cout << endl;
}

void printMap(const map<int, string, myCompare> m) {
    for (map<int, string, myCompare>::const_iterator mit = m.begin(); mit != m.end(); mit++) {
        cout << mit->first << " " << mit->second << endl;
    }
    cout << endl;
}


void test1() {
    // map容器的特点：
    // 1. map中所有元素都是pair，pair中第一个元素是key，第二个元素是value，key起到索引作用（比如id号）
    // 2. map是关联式，map中的元素会根据key自动排序
    // 3. map中的key不允许重复，multimap中的key允许重复
    // 4. map中的key和value都可以读写
    // 5. map中的元素是按照key从小到大排序的
    // 6. map容器底层是红黑树
    
    // map的构造函数
    map<int, string> m1;
    m1.insert(pair<int, string>(3, "three"));
    m1.insert(pair<int, string>(1, "one"));
    m1.insert(pair<int, string>(4, "four"));
    m1.insert(pair<int, string>(2, "two"));
    printMap(m1);

    // map的拷贝构造函数
    map<int, string> m2(m1);
    printMap(m2);
    map<int, string> m3 = m2;   // 重载了=运算符
    printMap(m3);

}

void test2() {
    // map容器的大小操作
    map<int, string> m;
    m.insert(pair<int, string>(3, "three"));
    m.insert(pair<int, string>(1, "one"));
    m.insert(pair<int, string>(4, "four"));
    m.insert(pair<int, string>(2, "two"));

    cout << "size: " << m.size() << endl;

    cout << "empty: " << m.empty() << endl;

    m.clear();

    cout << "size: " << m.size() << endl;

    // map容器的交换操作
    map<int, string> m1;
    m1.insert(pair<int, string>(3, "three"));
    m1.insert(pair<int, string>(1, "one"));
    m1.insert(pair<int, string>(4, "four"));
    m1.insert(pair<int, string>(2, "two"));
    printMap(m1);

    map<int, string> m2;
    m2.insert(pair<int, string>(5, "five"));
    m2.insert(pair<int, string>(6, "six"));
    m2.insert(pair<int, string>(7, "seven"));
    printMap(m2);

    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}

void test3() {
    // map容器的插入和删除操作
    map<int, string> m;
    m.insert(pair<int, string>(3, "three"));
    m.insert(make_pair(1, "one"));
    m.insert(map<int, string>::value_type(4, "four"));
    m[2] = "two";   // 重载了[]运算符，不建议使用，因为如果key不存在，会自动插入一个key-value对，适用于访问key对应的value
    printMap(m);

    m.erase(m.begin()); // 按照迭代器删除
    printMap(m);

    m.erase(4);         // 按照key删除
    printMap(m);

    // m.erase(m.begin(), m.end());    // 按照区间删除
    m.clear();                    // 清空map
    printMap(m);

}

void test4() {
    // map容器的查找和统计操作
    map<int, string> m;
    m.insert(pair<int, string>(3, "three"));
    m.insert(pair<int, string>(1, "one"));
    m.insert(pair<int, string>(4, "four"));
    m.insert(pair<int, string>(2, "two"));

    map<int, string>::iterator it = m.find(3);
    if (it != m.end()) {
        cout << "find: " << it->first << " " << it->second << endl;
    } else {
        cout << "not find" << endl;
    }

    int num = m.count(3);           // 对于map容器，count的返回值只能是0或1
    cout << "num: " << num << endl;
    num = m.count(5);
    cout << "num: " << num << endl;
}

void test5() {
    // map容器的排序
    // 默认排序规则是按照key从小到大排序
    map<int, string> m;
    m.insert(pair<int, string>(3, "three"));
    m.insert(pair<int, string>(1, "one"));
    m.insert(pair<int, string>(4, "four"));
    m.insert(pair<int, string>(2, "two"));
    printMap(m);

    // 自定义排序规则，对于自定义类型，必须指定排序规则
    map<int, string, myCompare> m2;
    m2.insert(pair<int, string>(3, "three"));
    m2.insert(pair<int, string>(1, "one"));
    m2.insert(pair<int, string>(4, "four"));
    m2.insert(pair<int, string>(2, "two"));
    printMap(m2);
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    return 0;
}
