#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"
#include "Square.h"
using namespace std;

bool compareArea(const Square& s1, const Square& s2) {
    if (s1.getArea() != s2.getArea()) return s1.getArea() < s2.getArea();
    if (s1.getX() != s2.getX()) return s1.getX() < s2.getX();
    return s1.getY() < s2.getY();
}

bool compareMaxX(const Square& s1, const Square& s2) {
    return static_cast<long long>(s1.getX()) + s1.getSide() < static_cast<long long>(s2.getX()) + s2.getSide();
}

bool compareMaxY(const Square& s1, const Square& s2) {
    return static_cast<long long>(s1.getY()) + s1.getSide() < static_cast<long long>(s2.getY()) + s2.getSide();
}

void printArea(const Square& s) {
    cout << s.getName() << "(" << static_cast<long long>(s.getX()) << ", " << static_cast<long long>(s.getY()) << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
}

void printMaxX(const Square& s) {
    cout << s.getName() << "(" << static_cast<long long>(s.getX()) + s.getSide() << ", " << static_cast<long long>(s.getY()) << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
}

void printMaxY(const Square& s) {
    cout << s.getName() << "(" << static_cast<long long>(s.getX()) << ", " << static_cast<long long>( s.getY()) + s.getSide() << ") side=" << s.getSide() << ", area=" << s.getArea() << endl;
}

int main() {
    int num;
    cin >> num;
    vector<Square> sbs;
    for (int i = 0; i < num; i++) {
        string name;
        int x, y, side;
        cin >> name >> x >> y >> side;
        sbs.push_back(Square(name, x, y, side));
    }

    cout << endl;

    vector<Square> s_area = sbs;
    sort(s_area.begin(), s_area.end(), compareArea);
    cout << "Squares in increasing order of area" << endl;
    for (const auto& s : s_area) printArea(s);
    cout << endl;

    vector<Square> s_x = sbs;
    stable_sort(s_x.begin(), s_x.end(), compareMaxX);
    cout << "Squares in increasing order of max x-coordinate" << endl;
    for (const auto& s : s_x) printMaxX(s);
    cout << endl;

    vector<Square> s_y = sbs;
    stable_sort(s_y.begin(), s_y.end(), compareMaxY);
    cout << "Squares in increasing order of max y-coordinate" << endl;
    for (const auto& s : s_y) printMaxY(s);
}
