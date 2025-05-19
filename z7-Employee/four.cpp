#include <iostream>
#include <string>
#include <vector>
#include<limits>
using namespace std;

const double BASIC_SALARY =200.0;
const double JOB_SALARY = 3000.0;     
const double COMMISSION_RATE = 0.005;

//一般员工
class Employee{
    protected:
    string number;
    string name;
    double basicsalary;

    public:
    Employee(string num,string n,double salary =BASIC_SALARY):number(num),name(n),
    basicsalary(salary){}

    virtual void input(){
        cout<<"请输入员工编号:";
        cin>>number;
        cout<<"请输入员工姓名：";
        cin>>name;
    }

    virtual double pay()const{
        return basicsalary;
    }

    virtual void print()const{
        cout << "员工编号: " << number << endl;
        cout << "员工姓名: " << name << endl;
        cout << "基本工资: " << basicsalary << endl;
    }

    virtual ~Employee() = default;
};

class Technician: public Employee{
    protected:
    double jobsalary;
    double products;

    public:
    Technician(string num,string n,double s=0.0):Employee(num,n,s),
    jobsalary(JOB_SALARY),products(0){}

    void input()override{
        Employee::input();
        cout<<"完成的products量:";
        while (!(cin >> products) || products < 0) {
        cout << "输入无效，请输入一个非负数值: ";
        cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }

    double pay()const override{
        return basicsalary+jobsalary+products*COMMISSION_RATE;
    }

    void print()const override{
        Employee::print();
        cout<<"完成的products量:"<<products<<endl;
        cout<<"职务工资:"<<jobsalary<<endl;
        cout<<"应得工资:"<<pay()<<endl;
    }

};

class Salesman: public Employee{
    protected:
    double sales;

    public:
    Salesman(string num, string n, double s=0.0):Employee(num,n),sales(s){}

    void input() override{
        Employee::input();
        cout<<"请输入销售额：";
        while (!(cin >> sales) || sales < 0) {
            cout << "输入无效，请输入一个非负数值: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

    }

    double pay() const override{
        return basicsalary+sales*COMMISSION_RATE; 
    }

    void print()const override{
        Employee::print();
        cout<<"销售额:"<<sales<<endl;
        cout<<"应得工资"<<pay()<<endl;
    }
};

class SalesManager:public Salesman{
    protected:
    double jobsalary;

    public:
    SalesManager(string num,string n,double s=0.0):
    Salesman(num,n,s),jobsalary(JOB_SALARY){}

    void input()override{
        Salesman::input();
    }

    double pay() const override{
        return basicsalary+jobsalary+sales*COMMISSION_RATE;
    }

    void print() const override{
        Employee::print();
        cout<<"销售额："<<sales<<endl;
        cout<<"职务工资:"<<jobsalary<<endl;
        cout<<"应得工资:"<<pay()<<endl;
    }
};

void menu(){
    cout<<"--------------------------"<<endl;
    cout << "员工工资管理系统" << endl;
    cout << "1. 添加一般员工" << endl;
    cout << "2. 添加销售员工" << endl;
    cout << "3. 添加销售经理" << endl;
    cout << "4. 添加技术人员" << endl;
    cout << "5. 显示所有员工工资" << endl;
    cout << "0. 退出" << endl;
    cout<<"--------------------------"<<endl;

}

int main(){
    vector<Employee*> employees;
    int choice;

    while(1){
        menu();
        cout<<"请输入操作 ";
        cin>>choice;

        if(choice==0) break;

        string num,name;

        switch (choice){
        case 1:{
            Employee*emp=new Employee("","");
            emp->input();
            employees.push_back(emp);
            break;
        }
        case 2:{   
            Salesman*emp=new Salesman("","");
            emp->input();
            employees.push_back(emp);
            break;
        }
        case 3:{   
        SalesManager*emp=new SalesManager("","");
        emp->input();
        employees.push_back(emp);
        break;
        }
        case 4:{
        Technician*emp=new Technician("","");
        emp->input();
        employees.push_back(emp);
        break;        
        }
        case 5:{
            cout<<"-------------------------"<<endl;
            for(auto&emp:employees){
                emp->print();
                cout<<"-------------------------"<<endl;
            }
            break;
        }
        default:
            cout<<"无效选择,请重新输入"<<endl;
            break;
        }
    }

    for(auto emp:employees){
        delete emp;
    }


}
