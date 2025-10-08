#include <iostream>
#include <string>
using namespace std;

class Salary {
private:
    string FirstName;
    string LastName;
    string MiddleName;
    string PhoneNumber;
    string JobTittle;
    int SalaryAmount;

public:
    int GetSalary() const {
        if (SalaryAmount < 0)
            throw invalid_argument("Error: Salary cannot be negative!");
        return SalaryAmount;
    }

    void SetSalary(int amount) {
        if (amount < 0)
            throw invalid_argument("Error: Salary cannot be negative!");
        SalaryAmount = amount;
    }

    Salary(string name1, string name2, string name3, string number, string role, int money) {
        FirstName = name1;
        LastName = name2;
        MiddleName = name3;
        PhoneNumber = number;
        JobTittle = role;
        SetSalary(money);
    }

    Salary() {
        FirstName = LastName = MiddleName = PhoneNumber = JobTittle = "";
        SalaryAmount = 0;
    }
    void Print() const {
        cout << FirstName << " " << MiddleName << " " << LastName << endl;
        cout << "Phone: " << PhoneNumber << endl;
        cout << "Job: " << JobTittle << endl;
        cout << "Salary: " << SalaryAmount << endl;
        cout << "\n";
    }

    Salary& operator+=(double bonus) {
        SalaryAmount += bonus;
        return *this;
    }

    Salary operator-(int) {
        return Salary(FirstName, LastName, MiddleName, PhoneNumber, "Fired", 0);
    }

    Salary operator+(int) {
        cout << "First: "; cin >> FirstName;
        cout << "LastName: "; cin >> LastName;
        cout << "MiddleName: "; cin >> MiddleName;
        cout << "Phone number: "; cin >> PhoneNumber;
        return Salary(FirstName, LastName, MiddleName, PhoneNumber, "new worker", 0);
    }

    bool Find(string lastName) const { 
        return LastName == lastName;
    }

    bool Find(int salary) const { 
        return SalaryAmount == salary;
    }
};

int main() {
    const int SIZE = 4;
    Salary workers[SIZE] = {
        Salary("Serhiy", "Ivanov", "Tarasovych", "+380977256616", "Senior Developer", 1200),
        Salary("Oksana", "Petrenko", "Vasylivna", "+380671112233", "Manager", 900),
        Salary("Andriy", "Koval", "Stepanovych", "+380503334455", "Designer", 1000)
    };

    cout << "\n===All workers===\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Worker ¹" << i + 1 << ":\n";
        workers[i].Print();
    }

    cout << "\n===Bonus===\n";
    workers[0] += 300;
    workers[0].Print();

    cout << "\n===Firing===\n";
    workers[1] = workers[1] - 1;
    workers[1].Print();

    cout << "\n===Add new worker===\n";
    Salary temp;
    temp = temp + 1; 
    workers[3] = temp;

    cout << "\n===All workers===\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Worker ¹" << i + 1 << ":\n";
        workers[i].Print();
    }



    cout << "\n===Search by Last Name (Ivanov)===" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (workers[i].Find("Ivanov"))
            workers[i].Print();
    }

    cout << "\n===Search by Salary (1500)===" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (workers[i].Find(1500))
            workers[i].Print();
    }

    cout << "\n===Exception test===\n";
    try {
        workers[0].SetSalary(-500);
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
