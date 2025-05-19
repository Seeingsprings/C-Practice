#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<stdexcept>
#include<cmath>
using namespace std;

class Point{
    public:
    float x,y;
    
    Point(float a=rand()%100,float b=rand()%100):x(a),y(b){}

    friend ostream&operator<<(ostream&os,Point p){
        os << "(" << setw(3) << p.x << "," << setw(3) << p.y << ")";
        return os;
    }
 };

double Distance(const Point&p1,const Point&p2){
    double dx=p1.x-p2.x;
    double dy=p1.y-p2.y;
    return sqrt(dx*dx+dy*dy);

}


class Circle{
    public:
    static constexpr double PI=3.1415926;
    double radius;
    int index;

    Circle(){}
    double Circle_Perimeter(){
        return 2*PI*radius;
    }
    double Circle_Area(){
        return PI*radius*radius;
    }

    void show(){
    int index=1;
    cout<<"\033[36m";
    cout << "|-----------------------------------------------------------------|" << endl;
    cout << "|" << left << setw(30) << "Index:Circle "<< "|" << left << setw(10) << "Radius" << "|" << left << setw(12) <<"Perimeter" << "|" << left << setw(10) <<"Area" << "|"<<endl;
	cout << "|-----------------------------------------------------------------|" << endl;
    for(int i=0;i<100;++i){
        radius=rand()%100;
        cout << "|" << left << setw(30) << index << "|" << left << setw(10) << radius<< "|" << left << setw(12) << Circle_Perimeter()  << "|" << left << setw(10) <<Circle_Area()<< "|"<<endl;
        index++;
    }
}
   
};
class Line{
    public:
    Line(){};

    void show(const Point&p1,const Point&p2){
        int index=1;
        cout<< "\033[32m";
        cout << "|------------------------------------------------|" << endl;
        cout << "|" << left << setw(15) << "Index:Line "<< "|"  << left << setw(11)<< "A点" << "|" << left << setw(11)
        <<"B点" << "|" << left << setw(10) <<"AB" << "|"<<endl;
        cout << "|------------------------------------------------|" << endl;
        for(int i=0;i<100;++i){

            cout << "|" << left << setw(15) << index << "|"   <<p1<< " |"  <<p2 << " |" << left << setw(10)<<Distance(p1,p2)<< "|"<<endl;
            index++;
            
        }
    }
};

class Triangle{
    public:
    Point A,B,C;
    double a,b,c;
    Triangle(){
    input();
    }

    void input(){
        A = Point();
        B = Point();
        C = Point();
        a = Distance(A, B);
        b = Distance(A, C);
        double max = a + b;
        double min = std::abs(a - b);
        c = min + (double)rand() / RAND_MAX * (max - min);
    }

    double Triangle_Perimeter(){
        return a+b+c;
    }

    double Triangle_Area(){
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void show(){
        int index=1;
        cout<< "\033[33m";
        cout << "|----------------------------------------------------------------------|"<< endl;
        cout << "|" << left << setw(15) << "Index:Triangle "<< "|"  << left << setw(11)<< "A点" << "|" << left << setw(11)
        <<"B点" << "|" << left << setw(10) <<"C点" << "|"<<left<<setw(11)<<"Permiter"<<"|"<<left<<setw(10)<<"Area"<<"|"<<endl;
        cout << "|----------------------------------------------------------------------|" << endl;
        for(int i=0;i<100;++i){
          // 重新生成点和计算边长
            input();
            cout << "|" << left << setw(15) << index << "|"   <<A<< " |"  <<B << " |" <<C<<"|"<<left << setw(11)
            <<Triangle_Perimeter()<< "|"<<left << setw(10)<<Triangle_Area()<<"|"<<endl;
            index++;
        }
    }

};

class Rectangle{
    public:
    double a,b;
    Rectangle(){
        input();
    };
    void input(){
        a=rand()%100;
        b=rand()%100;
    }
    double Rectangle_Perimeter(){
        return 2*(a+b);
    }

    double Rectangle_Area(){
        return a*b;
    }

    void show(){
        int index=1;
        cout<<"\033[34m";
        cout << "|-----------------------------------------------------------------|" << endl;
        cout << "|" << left << setw(16) << "Index:Rectangle "<< "|"  << left << setw(11)<< "Line 1" << "|" << left << setw(11)
        <<"Line 2" << "|" << left << setw(11) <<"Perimeter" << "|"<<left<<setw(12)<<"Area"<<"|"<<endl;
        cout << "|-----------------------------------------------------------------|" << endl;
        for(int i=0;i<100;++i){
            // 重新生成点和计算边长
              input();
              cout << "|" << left << setw(16) << index << "|" <<left<<setw(11)<<a<< "|"<<left<<setw(11)<<b<< "|" <<left << setw(11)
              <<Rectangle_Perimeter()<< "|"<<left << setw(12)<<Rectangle_Area()<<"|"<<endl;
              index++;
          }
      }
    };


class Polygon{
    public:
    const double PI=3.14;
    double n,a;
    Polygon(double b):n(b){
        a=rand()%100;
    }

    double Polygon_Perimeter(){
        return n*a;
    }

    double Polygon_Area(){
        double angle = PI / n; // 计算每个中心角的一半
        return 0.25 * n * a * a / tan(angle);
    }

    void show(){
        int index=1;
        cout<<"\033[35m";
        cout << "|-------------------------------------------------|" << endl;
        cout << "|" << left << setw(15) << "Index:Polygon "<< "|"  << left << setw(12)<< "边长" << "|" << left << setw(11)
        <<"Permiter"<<"|"<<left<<setw(10)<<"Area"<<"|"<<endl;
        cout << "|-------------------------------------------------|" << endl;
        for(int i=0;i<100;++i){
          // 重新生成点和计算边长
            a=rand()%100;
            cout << "|" << left << setw(15) << index << "|"<<left << setw(10)<<a<< "|"<<left << setw(11)
            <<Polygon_Perimeter()<< "|"<<left << setw(10)<<Polygon_Area()<<"|"<<endl;
            index++;
        }
    }

};

void menu(){
    cout<< "\033[0m";
    cout <<"\n输入数字\n";
    cout << "1.生成100个圆形\n";
    cout << "2. 生成100条线段\n";
    cout << "3. 生成100个正三角形\n";
    cout << "4. 生成100个矩形\n";
    cout << "5. 生成100个n正多边形(n>4)\n";
    cout << "0. 退出\n";
    cout << "请选择操作(数字): ";
}

int main(){
    srand(time(0));

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
            Point p1;
            Point p2;
            line.show(p1,p2);
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
   
}

