#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

// 选手类
class Person {
public:
    Person(std::string name, int score = 0) : m_name(name), m_score(score) {}

    std::string getName() const {
        return m_name;
    }

    int getScore() const {
        return m_score;
    }

    void setScore(int score) {
        m_score = score;
    }

private:
    std::string m_name;
    int m_score;
};

void printDeque(std::deque<int>& d) {
    for (std::deque<int>::iterator it = d.begin(); it < d.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void generateScores(std::deque<int>& scores) {
    for (int i = 0; i < 10; i++)
    {
        int score = rand() % 11 + 90;
        scores.push_back(score);
    }
}

void removeHighestAndLowest(std::deque<int>& scores) {
    sort(scores.begin(), scores.end());
    scores.pop_front();
    scores.pop_back();
}

int calculateAverage(std::deque<int>& scores) {
    int sum = 0;
    for (std::deque<int>::iterator dit = scores.begin(); dit < scores.end(); dit++)
    {
        sum += *dit;
    }
    return sum / scores.size();
}

int main() {
    using namespace std;

    // 1. 创建5名选手
    Person p1("A");
    Person p2("B");
    Person p3("C");
    Person p4("D");
    Person p5("E");

    // 放到vector容器中
    vector<Person> persons;
    persons.push_back(p1);
    persons.push_back(p2);
    persons.push_back(p3);
    persons.push_back(p4);
    persons.push_back(p5);

    // 创建打分deque容器
    deque<int> scores;

    // 遍历vector容器
    for (vector<Person>::iterator it = persons.begin(); it < persons.end(); it++)
    {
        scores.clear();

        // 2. 为每名选手打分
        generateScores(scores);

        printDeque(scores);

        // 3. 去掉最高分和最低分
        removeHighestAndLowest(scores);

        // 4. 计算平均分
        int avg = calculateAverage(scores);
        it->setScore(avg);

        cout << "Name: " << it->getName() << ", Score: " << it->getScore() << endl;

    }
    
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <deque>
// #include <string>
// #include <algorithm>

// // 选手类
// class Person {
// public:
//     Person(std::string name, int score = 0) {
//         m_name = name;
//         m_score = score;
//     }
    
//     std::string getName() const {
//         return m_name;
//     }

//     int getScore() const {
//         return m_score;
//     }

//     void setScore(int score) {
//         m_score = score;
//     }

// private:
//     std::string m_name;
//     int m_score;
// };

// void printDeque(std::deque<int>& d) {
//     for (std::deque<int>::iterator it = d.begin(); it < d.end(); it++)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     using namespace std;

//     // 1. 创建5名选手
//     Person p1("A");
//     Person p2("B");
//     Person p3("C");
//     Person p4("D");
//     Person p5("E");

//     // 放到vector容器中
//     vector<Person> persons;
//     persons.push_back(p1);
//     persons.push_back(p2);
//     persons.push_back(p3);
//     persons.push_back(p4);
//     persons.push_back(p5);

//     // 创建打分deque容器
//     deque<int> scores;

//     // 遍历vector容器
//     for (vector<Person>::iterator it = persons.begin(); it < persons.end(); it++)
//     {
//         scores.clear();

//         // 2. 为每名选手打分
//         for (int i = 0; i < 10; i++)
//         {
//             int score = rand() % 11 + 90;
//             scores.push_back(score);
//         }

//         printDeque(scores);

//         // 3. 去掉最高分和最低分
//         sort(scores.begin(), scores.end());
//         scores.pop_front();
//         scores.pop_back();

//         // 4. 计算平均分
//         int sum = 0;
//         for (deque<int>::iterator dit = scores.begin(); dit < scores.end(); dit++)
//         {
//             sum += *dit;
//         }
//         int avg = sum / scores.size();
//         it->setScore(avg);

//         cout << "Name: " << it->getName() << ", Score: " << it->getScore() << endl;

//     }
    
//     return 0;
// }