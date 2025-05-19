#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

class Vector {


public:
    int* p;
    int size;
    //这个size，如果是私有的话，main里面向量相乘除那里访问不了
    //要另外写getsize（），放在public里面

    // int getSize() const {
    //     return size;
    // }
    //int*p也是类似的问题

    Vector(int n) {
        size = n;
        p = new int[size];
        srand(static_cast<unsigned int>(time(nullptr)));
        //这个随机数，可以保证每次生成的都不一样
        for (int i = 0; i < size; ++i)
            p[i] = rand() % 100;
    }

    // 深拷贝构造函数
    Vector(const Vector& other) : size(other.size), p(new int[other.size]) {
        memcpy(p, other.p, size * sizeof(int));
    }

    //赋值运算符
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] p;
            size = other.size;
            p = new int[size];
            memcpy(p, other.p, size * sizeof(int));
        }
        return *this;
    }


    ~Vector() {
        delete[] p;
        p = nullptr;
    }

    friend Vector& operator+(Vector& v, int value);
    friend Vector& operator-(Vector& v, int value);

    // friend Vector& operator+(Vector& v1, Vector&v2);
    // friend Vector& operator-( Vector& v1, Vector&v2);
    // friend Vector& operator*( Vector& v1, Vector&v2);
    // friend Vector& operator/( Vector& v1, Vector&v2);
    friend Vector operator+(Vector& v1, Vector& v2); 
    friend Vector operator-(Vector& v1, Vector& v2);
    friend Vector operator*(Vector& v1, Vector& v2);
    friend Vector operator/(Vector& v1, Vector& v2);
    //为什么不加&？
    //因为你已经声明了友元函数+,后面又定义一个（向量相加那个），冲突了
    //所以，删除重复的声明

    //前置
    Vector& operator++(){
        for (int i = 0; i < size; ++i) {
            ++p[i];
        }
        return *this;
    }

    //后置
    Vector operator++(int){
        Vector temp(*this);   // 保存当前状态
        ++(*this);            // 调用前置++实现递增
        return temp;          // 返回递增前的值
    }
  
    friend ostream& operator<<(ostream& os, const Vector& v);
    
};


Vector& operator+(Vector& v, int value) {
    if(value==0){
        return v;
    }
    v.size+=value;
    int* t = new int[v.size];
    if (t == nullptr) {
        cout << "内存分配失败！" << endl;
        return v;
    }
    for (int i = 0; i < v.size - 1; ++i)
        t[i] = v.p[i];
    t[v.size - 1] = value;
    delete[] v.p;
    v.p = t;
    return v;
}

Vector& operator-(Vector& v, int value) {
    if (value > v.size) {
        cout << "错误:value 的值超过了数组大小！" << endl;
        return v;
    }
    v.size -= value;
    int* t = new int[v.size];
    if (t == nullptr) {
        cout << "内存分配失败！" << endl;
        return v;
    }
    for (int i = 0; i < v.size; ++i)
        t[i] = v.p[i];
    delete[] v.p;
    v.p = t;
    return v;
}

//两者相加
//注意，我们要返回的不是引用，是值
Vector operator+( Vector& v1, Vector&v2){
    int value=(v1.size>v2.size)?v1.size:v2.size;
    Vector T(value);
    for(int i=0;i<value;i++){
        int val1 = (i < v1.size) ? v1.p[i] : 0;
        int val2 = (i < v2.size) ? v2.p[i] : 0;
        T.p[i] = val1 + val2;
    }
    return T;

}

//两者相减
Vector operator-( Vector& v1, Vector&v2){
    int value=(v1.size>v2.size)?v1.size:v2.size;
    Vector T(value);
    for(int i=0;i<value;i++){
        int val1 = (i < v1.size) ? v1.p[i] : 0;
        int val2 = (i < v2.size) ? v2.p[i] : 0;
        T.p[i] = val1 -val2;
    }
    return T;

}

//两者相乘
Vector operator*( Vector& v1, Vector&v2){
    if(v1.size!=v2.size){
        cout<<"无法实现相乘"<<endl;
        return Vector(0);
    }
    int value=v1.size;
    Vector T(value);
    for(int i=0;i<value;i++){
        T.p[i] = v1.p[i]*v2.p[i];
    }
     return T;
    

}

//两者相除
Vector operator/( Vector& v1, Vector&v2){
    if(v1.size!=v2.size){
        cout<<"无法实现相除"<<endl;
        return Vector(0);
    }
 
    int value=v1.size;
    Vector T(value);
    for(int i=0;i<value;i++){
        if(v2.p[i]==0){
            cout<<"除数不能为0!"<<endl;
            return Vector(0);
        }
        T.p[i] = v1.p[i]/v2.p[i];

    }
     return T;

}




ostream& operator<<(ostream& os, const Vector& v) {
    os << "(";
    for (int i = 0; i < v.size; ++i) {
        os << v.p[i];
        if (i < v.size - 1) os << ",";
    }
    os << ")";
    return os;
    
}

int main() {
    int a;
    cout<<"输入vec1的大小: ";
    cin>>a;
    if(cin.fail()){
        cout<<"请重新输入"<<endl;
        main();
    }

    Vector vec1(a);
    cout << "vec1: " <<endl;
    cout<<vec1 << endl;

    vec1 = vec1 + 1; 
    cout << "vec1 增加一个元素: " <<endl;
    cout<< vec1 << endl;

    vec1 = vec1 - 2; 
    cout << "vec1 减去倒数两个元素: " << endl;
    cout<<vec1 << endl;

    Vector vec2 = vec1; 

    int b;
    cout<<"vec1增加多少个元素? ";
    cin>>b;
    vec1 = vec1 + b;
    cout << "vec1 增加"<<b<<"个: "<<endl;
    cout<<vec1<<endl;

    cout << "vec2: " <<endl;
    cout<< vec2 << endl<<endl;
    //vec1:a+b-1,vec2:a-1

    Vector vec3=vec1+vec2;
    cout<<"vec1+vec2=vec3= "<<endl;
    cout<<vec3<<endl;

    // Vector vec31=vec3++;
    cout<<"vec3++: "<<vec3++<<endl;
    cout<<"vec3: "<<vec3<<endl;

    cout<<"++vec3: "<<++vec3<<endl;
    cout<<"vec3: "<<vec3<<endl;
    



    Vector vec4=vec1-vec2;
    cout<<"vec1-vec2= "<<endl;
    cout<<vec4<<endl;

  
    if(vec1.size != vec2.size){
        cout<<"vec1*vec2不成立"<<endl;
    }else{
        Vector vec5=vec1*vec2;
        cout<<"vec1*vec2= "<<endl;
        cout<<vec5<<endl;
    }
 

     if (vec1.size != vec2.size) {
        cout << "vec1 / vec2 不成立" << endl;
    } else {
        Vector vec6 = vec1 / vec2;
        cout << "vec1 / vec2 = " << endl;
        cout<<vec6 << endl;
    }
}