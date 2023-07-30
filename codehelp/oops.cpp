#include <iostream>
#include <cstring>
using namespace std;


    //       Human
    //         |
    //      Employee
    //        /   \
    //   Manager   Owner


    // Detailed from chatgpt

    //   +----------------------+
    //   |        Human         |
    //   +----------------------+
    //   | - age: int           |
    //   | - name: char*        |
    //   +----------------------+
    //   | + setName(name: const char*): void |
    //   | + setAge(age: int): void           |
    //   | + printDetails(): void            |
    //   +----------------------+
    //             ^
    //             |
    //      +--------------+
    //      | Employee     |
    //      +--------------+
    //      | - salary: int |
    //      | - email: string ("@employee.com") |
    //      +--------------+
    //      | + setPosition(position: char): void |
    //      | + setSalary(salary: int): void      |
    //      | + printDetails(): void             |
    //      +--------------+
    //             ^
    //             |
    //     +---------------+
    //     |    Manager    |
    //     +---------------+
    //     | - office: char |
    //     +---------------+
    //     | + setEmail(): void           |
    //     | + getEmail(): void           |
    //     | + setName(name: const char*): void  |
    //     | (Overrides) printDetails(): void   |
    //     +---------------+
    //            ^
    //            |
    //     +----------------+
    //     |     Owner      |
    //     +----------------+
    //     | (Inherits from Human and Manager) |
    //     +----------------+





class Human{
    protected:
    int age;
    char *name;

    public:
    void setName(char name[])
    {
        strcpy(this->name, name);
    }
    void setAge(int age) {
        this->age = age;
    }

    public:
    void printDetails()
    {
        cout<<endl;
        cout<<"[ Age -> "<< this->age <<", ";
        cout << "name -> "<<this->name <<" ]";
    }
};

class Employee: public Human{
    private:
    int salary;

    protected:
    string email = "@employee.com";

    public:
    char position;
    static string companyName;

    Employee()
    {
        name = new char[100];
        cout <<endl<< "Created Employee."<<endl;
    }

    // this is same as copy constructor
    // creates shallow constructor problem
    Employee(Employee& emp)
    {
        // following 2 lines solve shallow copy problem
        // create new ch[] and copy emp.name in it
        // called as deep copy
        char* ch = new char[strlen(emp.name + 1)];
        strcpy(ch, emp.name);

        this->name = ch;  // this copies address of name data member from temp
                                // if any changes in temp object will reflect in new object
        this->position = emp.position;
        this->salary = emp.salary;
    };

    void setSalary(int salary)
    {
        this->salary = salary;
    }
    void setPosition(char position)
    {
        this->position = position;
    }

    void printDetails() // --> polymorphism
    {
        cout << endl;
        cout << "[ name -> "<< this->name <<", ";
        cout << "position -> "<< this->position << ", ";
        cout << "salary - > "<< this->salary << ", ";
        cout << "age -> "<< this->age <<"]";
        cout << endl<<endl;
    }

    // destructor
    ~Employee()
    {
        delete [] name;
        cout <<endl<<endl<< "Destroyed Employee.";
    }
};

class Manager: public Employee{
    public:
    char office;

    void setName(char name[]) {
        strcpy(this->name, name);
        setEmail();
    }

    void getEmail(){
        cout << this->email;
    }

    private:
    void setEmail() {
        this->email = this->name + this->email;
    }
};


class Owner: public Human, public Manager{
    // Owner is the manager

};

// static data member
string Employee::companyName = "PPW";



int main()
{

    // created employee aman
    Employee aman;
    char name[] = "Aman";
    aman.setName(name);
    aman.setPosition('B');
    aman.setSalary(100000);
    // cout <<  aman.salary << endl; // private within this context

    // Specifying class to printdetails() is called scope resolution
    aman.Employee::printDetails();


    // shallow copy to baman
    // it creates new salary, position data members but just copies address for name
    Employee baman(aman);
    baman.Employee::printDetails();

    // change name of 1st object aman
    char name2[] = "Chaman";
    aman.setName(name2);

    // printing both objects 
    // name change in object 1 must reflect in obj2
    // this is called shallow copy constructor problem
    // to avoid this problem, updated constructor
    aman.Employee::printDetails();
    baman.Employee::printDetails();


    // static data members are same for all objects
    // it does not belongs to objects, related to class
    cout <<endl<< Employee::companyName;
    cout <<endl<< aman.companyName;
    cout <<endl<< baman.companyName<<endl;

    baman.companyName = "Apple";
    cout <<endl<< Employee::companyName;
    cout <<endl<< aman.companyName;
    cout <<endl<< baman.companyName;

    

    // manager inherited properties of class employee
    Manager ketan;
    char name3[] = "ketan";
    ketan.Manager::setName(name3);
    ketan.setAge(29);
    ketan.Employee::printDetails();
    ketan.getEmail();


    Owner pratik;
    char name4[] = "pratik";
    pratik.Manager::setName(name4);
    pratik.Manager::setAge(33);
    pratik.Manager::printDetails();
    

}