#include <bits/stdc++.h>

using namespace std;

double a, b, c, p, q, r; // a是甜甜花，b个甜甜花合成一个c，p是砂糖概率，q是行秋概率，r是行秋每次返还个数

// 返回普通产物
double normal(double resource) {
    return resource * (c / b);
}

// 返回额外的产物
double shatang(double resource) {
    return resource * (c / b) * (p / 100);
}

// 返回额外的原材料
double xingqiu(double resource) {
    return resource / b * (q / 100) * r;
}

int main()
{
    cin >> a >> b >> c >> p >> q >> r;
    // 只用砂糖 %p 概率双倍
    double res1 = normal(a) + shatang(a);
    // 用行秋 %q 概率返还r个，再用普通合成
    double res2 = normal(a) + normal(xingqiu(a));
    cout << normal(a) << " " << shatang(a) << " " << xingqiu(a) << endl;
    cout << res1 << " " << res2 << endl;
    cout << max(res1, res2) << endl;
    return 0;
}