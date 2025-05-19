#include <iostream>
#include<string>
#include<cstring>
#include<typeinfo>
#include<stdexcept>
using namespace std;

template<typename T>
struct TypeName {
    static string get() { return "未知类型"; }
};

template<>
struct TypeName<int> {
    static string get() { return "int"; }
};

template<>
struct TypeName<double> {
    static string get() { return "double"; }
};

template<typename T>
class T_Counter{
    private:
        T*arr;
        int size;
    public:
        T_Counter(int n):size(n){
            arr=new T[size];
            for(int i=0;i<size;i++){
                arr[i]=T();
            }
        }

        ~T_Counter(){
            delete[]arr;
        }

        void addvalue(){
            cout<<"请输入"<<TypeName<T>::get()<<"类型的数据："<<endl;
            for(int i=0;i<size;i++){
                cin>>arr[i];
            }
        }

        void deletecvalue(){
                cout<<"请输入要删除的数据下标(输入一个）:";
                int n;
                cin>>n;
                if(n<0||n>size||cin.fail()){
                    throw invalid_argument("输入有误！");
                }
            
                for(int i=n;i<size-1;i++){
                    arr[n]=arr[n+1];
                }
    
                cout<<"删除元素后的数组:"<<endl;
                for(int i=0;i<size-1;i++){
                    cout<<"arr["<<i<<"]: "<<arr[i]<<endl;
                }
            
        }   

        T sum(){

            T total=0;
            for(int i=0;i<size;i++){
                total+=arr[i];
            }
            return total;
        }

        T average(){

            return static_cast<double>(sum()/size);
        }

        T show(){
         
            for(int i=0;i<size;i++){
                cout<<"arr["<<i<<"]: "<<arr[i]<<endl;
            }
        }        

};

int main(){
    int size=0;
    cout<<"输入数组的大小:";
    cin>>size;
    if(cin.fail()){
        throw invalid_argument("输入有误!");
    }

    T_Counter<int>thearray(size);
    thearray.addvalue();
    thearray.show();
    cout<<"数组各个元素总数和:"<<thearray.sum()<<endl;
    cout<<"数组各个元素的平均值:"<<thearray.average()<<endl;

    //double
    int doublesize;
    cout<<"输入数组的大小:";
    cin>>doublesize;
    if(cin.fail()){
        throw invalid_argument("输入有误!");
    }

    T_Counter<double>doublearray(doublesize);
    doublearray.addvalue();
    cout<<"数组各个元素总数和:"<<doublearray.sum()<<endl;
    cout<<"数组各个元素的平均值:"<<doublearray.average()<<endl;
    thearray.show();
}

