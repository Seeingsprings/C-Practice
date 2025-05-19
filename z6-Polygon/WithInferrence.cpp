#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cmath>

// 定义颜色宏
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

using namespace std;

// 点类
class Point {
public:
    float x, y;
    Point(float a = rand() % 100, float b = rand() % 100) : x(a), y(b) {}

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << setw(3) << p.x << "," << setw(3) << p.y << ")";
        return os;
    }
};

// 计算两点间距离
double Distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// 抽象基类：图形
class Shape {
public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual void show()=0;
    virtual ~Shape() = default;
};

// 圆类
class Circle : public Shape {
    const double PI=3.1415926;
    double radius;
public:
    Circle() : radius(rand() % 100) {}

    double perimeter() const override {
        return 2 * PI * radius;
    }

    double area() const override {
        return PI * radius * radius;
    }

    void show() override {
        cout << CYAN;
        cout << "|-----------------------------------------------------------------|" << endl;
        cout << "|" << left << setw(30) << "Index:Circle "
             << "|" << left << setw(10) << "Radius"
             << "|" << left << setw(12) << "Perimeter"
             << "|" << left << setw(10) << "Area" << "|" << endl;
        cout << "|-----------------------------------------------------------------|" << endl;
        for (int i = 1; i <= 100; ++i) {
            radius=rand()%100;
            cout << "|" << left << setw(30) << i
                 << "|" << left << setw(10) << radius
                 << "|" << left << setw(12) << perimeter()
                 << "|" << left << setw(10) << area() << "|" << endl;
        }
        cout << RESET;
    }
};

class Line : public Shape {
    Point p1, p2;
public:
    Line() : p1(), p2() {}

    double perimeter() const override {
        return Distance(p1, p2);
    }

    double area() const override {
        return 0;
    }

    void show() override {
        cout << GREEN;
        cout << "|------------------------------------------------|" << endl;
        cout << "|" << left << setw(15) << "Index:Line "
             << "|" << left << setw(11) << "A点"
             << "|" << left << setw(11) << "B点"
             << "|" << left << setw(10) << "AB" << "|" << endl;
        cout << "|------------------------------------------------|" << endl;
        for (int i = 1; i <= 100; ++i) {
            Point p1, p2;
            cout << "|" << left << setw(15) << i
                 << "|" << p1 << " |" << p2 << " |"
                 << left << setw(10) << perimeter() << "|" << endl;
        }
        cout << RESET;
    }
};

// 三角形类
class Triangle : public Shape {
    public:
    Point A, B, C;
    double a, b, c;
    void generateSides() {
        do {
            A = Point();
            B = Point();
            C = Point();
            a = Distance(A, B);
            b = Distance(A, C);
            c = Distance(B, C);
        } while (!(a + b > c && a + c > b && b + c > a));
    }

    Triangle() {
        generateSides();
    }

    double perimeter() const override {
        return a + b + c;
    }

    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void show() override {
        cout << YELLOW;
        cout << "|----------------------------------------------------------------------|" << endl;
        cout << "|" << left << setw(15) << "Index:Triangle "
             << "|" << left << setw(11) << "A点"
             << "|" << left << setw(11) << "B点"
             << "|" << left << setw(10) << "C点"
             << "|" << left << setw(11) << "Perimeter"
             << "|" << left << setw(10) << "Area" << "|" << endl;
        cout << "|----------------------------------------------------------------------|" << endl;
        for (int i = 1; i <= 100; ++i) {
            generateSides();
            cout << "|" << left << setw(15) << i
                 << "|" << A << " |" << B << " |" << C
                 << "|" << left << setw(11) << perimeter()
                 << "|" << left << setw(10) << area() << "|" << endl;
        }
        cout << RESET;
    }
};

// 矩形类
class Rectangle : public Shape {
    double a, b;
public:
    Rectangle() : a(rand() % 100), b(rand() % 100) {}

    double perimeter() const override {
        return 2 * (a + b);
    }

    double area() const override {
        return a * b;
    }

    void show()override {
        cout << BLUE;
        cout << "|-----------------------------------------------------------------|" << endl;
        cout << "|" << left << setw(16) << "Index:Rectangle "
             << "|" << left << setw(11) << "Line 1"
             << "|" << left << setw(11) << "Line 2"
             << "|" << left << setw(11) << "Perimeter"
             << "|" << left << setw(12) << "Area" << "|" << endl;
        cout << "|-----------------------------------------------------------------|" << endl;
        for (int i = 1; i <= 100; ++i) {
            a=rand() % 100;
            b=rand() % 100;
            cout << "|" << left << setw(16) << i
                 << "|" << left << setw(11) << a
                 << "|" << left << setw(11) << b
                 << "|" << left << setw(11) << perimeter()
                 << "|" << left << setw(12) << area() << "|" << endl;
        }
        cout << RESET;
    }
};

// 多边形类
class Polygon : public Shape {
    const double PI = 3.14;
    double n, a;
public:
    Polygon(double b) : n(b), a(rand() % 100) {}

    double perimeter() const override {
        return n * a;
    }

    double area() const override {
        double angle = PI / n;
        return 0.25 * n * a * a / tan(angle);
    }

    void show()  override {
        cout << MAGENTA;
        cout << "|-------------------------------------------------|" << endl;
        cout << "|" << left << setw(15) << "Index:Polygon "
             << "|" << left << setw(12) << "边长"
             << "|" << left << setw(11) << "Perimeter"
             << "|" << left << setw(10) << "Area" << "|" << endl;
        cout << "|-------------------------------------------------|" << endl;
        for (int i = 1; i <= 100; ++i) {
            a=rand() % 100;
            cout << "|" << left << setw(15) << i
                 << "|" << left << setw(10) << a
                 << "|" << left << setw(11) << perimeter()
                 << "|" << left << setw(10) << area() << "|" << endl;
        }
        cout << RESET;
    }
};

// 显示菜单
void menu() {
    cout << RESET;
    cout << "\n输入数字\n";
    cout << "1.生成100个圆形\n";
    cout << "2. 生成100条线段\n";
    cout << "3. 生成100个正三角形\n";
    cout << "4. 生成100个矩形\n";
    cout << "5. 生成100个n正多边形(n>4)\n";
    cout << "0. 退出\n";
    cout << "请选择操作(数字): ";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int n;


        do{
            menu();
            cin>>n;
            if(cin.fail()){
                throw invalid_argument("输入数据有误！");
            }
        
        
            if(n==1){
                Circle circle;
                circle.show();
            }else if(n==2){
                Line line;
                line.show();
            }else if(n==3){
                Triangle triangle;
                triangle.show();
            }else if(n==4){
                Rectangle rectangle;
                rectangle.show();
            }else{
                Polygon polygon(n);
                polygon.show();
            }
           
        }while(n!=0);

    return 0;
}    