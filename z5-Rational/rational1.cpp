#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include <iomanip>
#include<stdexcept>
#include<string>

using namespace std;

class Rational{
    private:
    int a;
    int b;

    int gcd(int x,int y){
        while(y!=0){
            int t=y;
            y=x%y;
            x=t;
        }
        return x;
    }

    void reduce() {
        if (b == 0) {
            throw invalid_argument("分母不能为零");
        }
        if(b<0){
            a=-a;
            b=-b;
        }

        int divisor = gcd(abs(a), abs(b)); // 计算最大公约数
        a /= divisor;
        b /= divisor;
    }        

    public:
    Rational(int x=0,int y=1):a(x),b(y){
        reduce();
    };



    double to_double() const {
        return static_cast<double>(a) / b;
    }

    float to_float()const{
        return a/(float)b;
    }

    operator int(){
        return a/(int)b;
    }

    friend istream& operator>>(istream& is, Rational& r);
    friend ostream& operator<<(ostream& os, const Rational& r);

    Rational operator+(const Rational& other) const {
        return Rational(a * other.b + other.a * b,b * other.b);
    }

    Rational operator-(const Rational& other) const {
        return Rational(a * other.b - other.a * b,b * other.b);
    }

    Rational operator*(const Rational& other) const {
        return Rational(a * other.a,b * other.b);
    }

    Rational operator/(const Rational& other) const {
        if (other.a == 0) {
            throw runtime_error("除数不能为零");
        }
        return Rational(a * other.b, b * other.a);
    }

    //前置
    Rational& operator++() {
        *this = *this + Rational(1, b); // 加上 1/b
        return *this;
    }

    Rational operator++(int) {
        Rational temp=*this;
        ++(*this);
        return temp;
    }

    // bool operator==(const Rational&other)const{

    // }

};


istream& operator>>(istream& is, Rational& r){
    char slash;
    is >> r.a >> slash >> r.b; 
    if (r.b == 0) {
        throw invalid_argument("分母不能为零");
    }
    r.reduce();
    return is;
}
ostream& operator<<(ostream& os, const Rational& r){
    if (r.b == 1) {
        os << r.a; 
    } else {
        os << r.a << "/" << r.b;
    }
    return os;

}

void display_menu() {
    cout << "\n有理数计算器\n";
    cout << "1. 加法 (+)\n";
    cout << "2. 减法 (-)\n";
    cout << "3. 乘法 (*)\n";
    cout << "4. 除法 (/)\n";
    cout << "5. 转换为小数\n";
    cout << "0. 退出\n";
    cout << "请选择操作(数字): ";
}



int main(){

        Rational r1, r2;
        cout<<"请输入两个有理数(格式:a/b):";
        cin>>r1>>r2;
    
    display_menu();

    char op;
    cin>>op;

    switch (op) {
        case '1':
            cout<<r1+r2<<endl;
            cout << r1<<'+'<<r2 << " = " << fixed << setprecision(6) << (r1+r2).to_double() << endl;
            break;
        case '2':
            cout<<r1-r2<<endl;
            cout << r1<<'-'<<r2 << " = " << fixed << setprecision(6) << (r1-r2).to_double() << endl;
            break;
        case '3':
            cout<<r1*r2<<endl;
            cout << r1<<'*'<<r2 << " = " << fixed << setprecision(6) << (r1*r2).to_double() << endl;
            break;
        case '4':
            cout<<r1/r2<<endl;
            cout << r1<<'/'<<r2 << " = " << fixed << setprecision(6) << (r1/r2).to_double() << endl;
            break;
        case '5':
            cout << r1 << " = " << fixed << setprecision(6) << r1.to_double() << endl;
            cout << r2 << " = " << fixed << setprecision(6) << r2.to_double() << endl;
            break;
        case '0':
            break;
        default:
            cout << "无效的运算符！" << endl;
            return 1;
    }


    return 0;


}