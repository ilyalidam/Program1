/*
https://contest.yandex.ru/contest/41792/run-report/75456688/

1_3. Замкнутая ломаная
Задано N точек на плоскости. Указать (N-1)-звенную несамопересекающуюся замкнутую ломаную, проходящую через все эти точки.
Предполагается, что никакие три точки не лежат на одной прямой.
Стройте ломаную от точки, имеющей наименьшую координату x. Если таких точек несколько, то используйте точку с наименьшей координатой y. Точки на ломаной расположите в порядке убывания углов лучей от начальной точки до всех остальных точек.
Для сортировки точек реализуйте алгоритм сортировки вставками.

 O(n^2)
 */
#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    int x, y;
};

double ug(const Point& a, const Point& b) {
  if (a.x == b.x) return 1e9 + a.y - b.y;
  return (a.y - b.y) * 1.0 / (a.x - b.x);
}

bool Comp(const Point& start, const Point& a, const Point& b) {
  return ug(start, a) < ug(start, b);
}

void Sort(std::vector<Point>& v, const Point& start) {
  for (int i = 1; i < v.size(); i++) {
    int j = i;
    while (j > 0 && Comp(start, v[j - 1], v[j])) {
      std::swap(v[j], v[j - 1]);
      j--;
    }
  }
}

signed main() {
  int n = 0;
  std::cin >> n;
  std::vector<Point> v(n);
  Point start;
  start.x = 1e9, start.y = 1e9;
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].x >> v[i].y;
    if (v[i].x < start.x || (v[i].x == start.x && v[i].y < start.y)) start = v[i];
  }
  Sort(v, start);
  for (int i = 0; i < n; ++i) {
    std::cout << v[i].x <<' '<< v[i].y << std::endl;
  }
}
/*

10
0 5
0 0
2 -3
4 -2
6 -2
7 0
7 2
5 3
3 3
1 5

 */



