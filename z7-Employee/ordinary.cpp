#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

const double BASIC_SALARY = 3000.0;

class Employee {
protected:
    string id;
    string name;
    char sex;
    string time;
    string job;
    double basic_salary;

public:
    Employee(string i, string n, char s, string ti, string j)
        : id(i), name(n), sex(s), time(ti), job(j) {
        basic_salary = BASIC_SALARY;
    }

    virtual ~Employee() {} 

    virtual void Input() {
        cout << "请输入员工编号: ";
        cin >> id;
        cout << "请输入员工姓名: ";
        cin >> name;
        cout << "请输入员工职位: ";
        cin >> job;
        cout << "请输入员工性别 (M/F): ";
        cin >> sex;
        while (sex != 'M' && sex != 'F') {
            cout << "性别输入错误，请重新输入 (M/F): ";
            cin >> sex;
        }
        cout << "请输入员工入职时间 (year-month-day): ";
        cin >> time;
    }

    virtual double GetPay() const {
        return basic_salary;
    }

    virtual void ShowMessage() const {
        cout << "|-----------------------------------------------------------------|" << endl;
        cout << "员工编号: " << id << "\t员工姓名: " << name 
             << "\t员工职位: " << job << endl;
        cout << "员工性别: " << (sex == 'M' ? "男" : "女") 
             << "\t员工入职时间: " << time << endl;
    }
};

class Manager : public Employee {
protected:
    double bonus;

public:
    Manager(string i, string n, char s, string ti, string j) 
        : Employee(i, n, s, ti, j), bonus(0) {}

    void Input() override {
        Employee::Input();
        cout << "请输入奖金: ";
        cin >> bonus;
    }

    double GetPay() const override {
        return basic_salary + bonus;
    }

    void ShowMessage() const override {
        Employee::ShowMessage();
        cout << "员工奖金: " << bonus << "\t员工薪酬: " << GetPay() << endl;
        cout << "|-----------------------------------------------------------------|" << endl;
    }
};

class Technicist : public Employee {
public:
    Technicist(string i, string n, char s, string ti, string j) 
        : Employee(i, n, s, ti, j) {}

    void Input() override {
        Employee::Input();
    }

    double GetPay() const override {
        return basic_salary;
    }

    void ShowMessage() const override {
        Employee::ShowMessage();
        cout << "员工薪酬: " << GetPay() << endl;
        cout << "|-----------------------------------------------------------------|" << endl;
    }
};

class SalesPerson : public Employee {
protected:
    double profit;

public:
    SalesPerson(string i, string n, char s, string ti, string j) 
        : Employee(i, n, s, ti, j), profit(0) {}

    void Input() override {
        Employee::Input();
        cout << "请输入销售利润: ";
        cin >> profit;
    }

    double GetPay() const override {
        return basic_salary + profit * 0.05;
    }

    void ShowMessage() const override {
        Employee::ShowMessage();
        cout << "员工销售利润: " << profit << "\t员工薪酬: " << GetPay() << endl;
        cout << "|-----------------------------------------------------------------|" << endl;
    }
};

void menu() {
    cout << "1. 添加经理" << endl;
    cout << "2. 添加技术人员" << endl;
    cout << "3. 添加营销人员" << endl;
    cout << "4. 显示所有员工工资" << endl;

    cout << "0. 退出" << endl;
}

int main() {
    const int MAX_EMPLOYEES = 100;
    vector<Employee*> employees;

    menu();
    int choice;

    while (true) {
        cout << "\n请选择操作: ";
        cin >> choice;

        if (choice == 0) break;

        if (employees.size() >= MAX_EMPLOYEES) {
            cout << "员工数量已达上限(100人),无法添加更多员工" << endl;
            continue;
        }

        string id, name, time, job;


        switch (choice) {
            case 1: {  
                cout << "请输入经理信息:" << endl;
                Manager* emp = new Manager("", "", ' ', "", "");
                emp->Input();
                employees.push_back(emp);
                break;
            }
            case 2: {  
                cout << "请输入技术人员信息:" << endl;
                Technicist* emp = new Technicist("", "", ' ', "", "");
                emp->Input();
                employees.push_back(emp);
                break;
            }
            case 3: {  
                cout << "请输入营销人员信息:" << endl;
                SalesPerson* emp = new SalesPerson("", "", ' ', "", "");
                emp->Input();
                employees.push_back(emp);
                break;
            }
            case 4: {  
                cout << "\n所有员工工资信息:" << endl;
                for (const auto& emp : employees) {
                    emp->ShowMessage();
                }
                break;
            }
            default:
                cout << "无效选择，请重新输入!" << endl;
        }
    }

    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}