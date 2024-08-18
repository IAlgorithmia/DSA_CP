#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b) //This is a parameterized constructor, since its taking two inputs
    {
        x = a;
        y = b;
    }
    friend float DistanceFinder(Point, Point);
    void displayPoint()
    {
        cout << "The point is (" << x << ", " << y << ")" << endl;
    }
};

float DistanceFinder(Point pt1, Point pt2){
    return (sqrt(pow(pt1.x -pt2.x, 2) + pow(pt1.y - pt2.y, 2)));
}

int main()
{
    Point p(1, 1);
    p.displayPoint();

    Point q(4, 6);
    q.displayPoint();

    cout << DistanceFinder(p, q);
    return 0;
}
