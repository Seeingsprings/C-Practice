#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <numeric> 
#include <algorithm>
using namespace std;

class Vector {
private:
    vector<int> data;  // 使用STL vector代替手动内存管理

public:
    // 构造函数
    Vector(int n = 0) {
        srand(time(nullptr));
        data.resize(n);
        for (auto& elem : data) {
            elem = rand() % 100;
        }
    }

    // 获取大小
    size_t size() const { return data.size(); }

    // 向量与标量相加（添加元素）
    Vector& operator+=(int value) {
        data.push_back(value);
        return *this;
    }
   
    // 向量与标量相减（删除元素）
    Vector& operator-=(size_t n) {
        if (n > size()) {
            cout << "错误: 不能删除超过向量大小的元素" << endl;
            return *this;
        }
        data.resize(size() - n);
        return *this;
    }
    
    // 向量乘以标量相乘
    Vector&operator*=(int scalar){
        // Vector result(size());
        // for (int i = 0; i < size(); ++i) {
        //     result.data[i] = data[i] * scalar;
        // }
        // return result;

        for (auto& elem : data) {
            elem *= scalar;
        }
        return *this;
    }    

    // 向量相加
    // friend Vector operator+(const Vector& v1, const Vector& v2) {
    //     Vector result(max(v1.size(), v2.size()));
    //     for (int i = 0; i < result.size(); ++i) {
    //         int val1 = (i < v1.size()) ? v1.data[i] : 0;
    //         int val2 = (i < v2.size()) ? v2.data[i] : 0;
    //         result.data[i] = val1 + val2;
    //     }
    //     return result;
    // }
    friend Vector operator+(Vector v1, const Vector& v2) {
        v1.data.resize(max(v1.size(), v2.size()));
        transform(v2.data.begin(), v2.data.end(), v1.data.begin(), 
                v1.data.begin(), plus<int>());
        return v1;
    }

    // 向量相减
    // friend Vector operator-(const Vector& v1, const Vector& v2) {
    //     Vector result(max(v1.size(), v2.size()));
    //     for (int i = 0; i < result.size(); ++i) {
    //         int val1 = (i < v1.size()) ? v1.data[i] : 0;
    //         int val2 = (i < v2.size()) ? v2.data[i] : 0;
    //         result.data[i] = val1 - val2;
    //     }
    //     return result;
    // }
    friend Vector operator-(Vector v1, const Vector& v2) {
        v1.data.resize(max(v1.size(), v2.size()));
        transform(v2.data.begin(), v2.data.end(), v1.data.begin(),
                v1.data.begin(), minus<int>());
        return v1;
    }


    // 向量点积
    friend int dot(const Vector& v1, const Vector& v2) {
        if (v1.size() != v2.size()) {
           cout<<"向量长度必须相同才能计算点积"<<endl;
           return 0;
        }
        return inner_product(v1.data.begin(), v1.data.end(), 
                                 v2.data.begin(), 0);
    }

    // 向量相除
    friend Vector operator/(const Vector& v1, const Vector& v2) {
        if (v1.size() != v2.size()) {
            cerr << "无法实现相除" << endl;
            return Vector(0);
        }
        Vector result(v1.size());
        for (size_t i = 0; i < result.size(); ++i) {
            if (v2.data[i] == 0) {
                cerr << "除数不能为0!" << endl;
                return Vector(0);
            }
            result.data[i] = v1.data[i] / v2.data[i];
        }
        return result;
    }

    // 输出运算符
    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << "(";
        for (size_t i = 0; i < v.size(); ++i) {
            os << v.data[i];
            if (i < v.size() - 1) os << ",";
        }
        os << ")";
        return os;
    }
};

int main() {
    int a;
    cout << "输入vec1的大小: ";
    cin >> a;
    if (cin.fail()) {
        cout << "请重新输入" << endl;
        return 1;
    }

    Vector vec1(a);
    cout << "vec1: " << vec1 << endl;

    int t;
    cout<<"vec1在末尾一个元素:";
    cin>>t;
    vec1+=t;
    cout<<"vec1="<<vec1<<endl;

    int k;
    cout<<"vec1减去末尾几个元素:";
    cin>>k;
    vec1-=k;
    cout<<"vec1="<<vec1<<endl;

    int m;
    cout<<"vec1乘以什么:";
    cin>>m;
    vec1*=m;
    cout<<"vec1="<<vec1<<endl;

    Vector vec2=vec1;
    cout<<"vec2="<<vec2<<endl;

    Vector vec3=vec1+vec2;
    cout<<"vec1+vec2:"<<vec3<<endl;

    Vector vec4=vec1-vec2;
    cout<<"vec1-vec2:"<<vec4<<endl;

    int dotproduct=dot(vec1,vec2);
    cout<<"vec1*vec2(点积):"<<dotproduct<<endl;

    // Vector vec5=vec1*vec2;
    // cout<<"vec1*vec2(逐个元素相乘):"<<endl;

    Vector vec6=vec1/vec2;
    cout<<"vec1/vec2:"<<vec6<<endl;

    return 0;
}