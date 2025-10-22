#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Sportsman {
protected:
    string sportsmanName;
    string abonement;

public:
    Sportsman(string name, string abon) : sportsmanName(name), abonement(abon) {
        cout << "Sportsman created: " << sportsmanName << endl;
    }

    Sportsman() {
        sportsmanName = "Unknown";
        abonement = "None";
    }

    virtual ~Sportsman() {
        cout << "Sportsman destroyed: " << sportsmanName << endl;
    }

    string GetName() const { return sportsmanName; }
    string GetAbonement() const { return abonement; }

    virtual void PrintInfo(ostream& out) const {
        out << "  Sportsman name: " << sportsmanName
            << "\n  Type of abonement: " << abonement << "\n";
    }
};




class Coach : public Sportsman {
protected:
    string role;
    vector<Sportsman> sportsmen;

public:
    Coach(string name, string r) : Sportsman(name, "Coach"), role(r) {
        cout << "Coach created: " << name << endl;
    }

    Coach() : Sportsman("Unknown coach", "Coach") {}

    ~Coach() override {
        cout << "Coach destroyed: " << sportsmanName << endl;
    }

    void AddSportsman(const Sportsman& s) {
        if (sportsmen.size() < 5)
            sportsmen.push_back(s);
        else
            cout << "Cannot add more sportsmen " << endl;
    }

    void PrintInfo(ostream& out) const override {
        out << "\nCoach name: " << sportsmanName
            << "\nRole: " << role << "\n--- Assigned sportsmen ---\n";
        if (sportsmen.empty())
            out << "  No sportsmen assigned.\n";
        else {
            for (const auto& s : sportsmen)
                s.PrintInfo(out);
        }
    }
};

  


class Teacher : public Coach {
private:
    string subject;
    vector<Coach> coaches;

public:
    Teacher(string name, string subj)
        : Coach(name, "Teacher"), subject(subj) {
        cout << "Teacher created: " << name << endl;
    }

    Teacher() : Coach("Unknown teacher", "Teacher"), subject("None") {}

    ~Teacher() override {
        cout << "Teacher destroyed: " << sportsmanName << endl;
    }

    void AddCoach(const Coach& c) {
        if (coaches.size() < 3)
            coaches.push_back(c);
        else
            cout << "Cannot add more coaches" << endl;
    }

    void PrintInfo(ostream& out) const override {
        out << "\n==============================\n"
            << "Teacher: " << sportsmanName
            << "\nSubject: " << subject
            << "\n==============================\n";

        if (coaches.empty())
            out << "No coaches assigned.\n";
        else {
            for (size_t i = 0; i < coaches.size(); ++i) {
                out << "\n>> Coach " << i + 1 << ":\n";
                coaches[i].PrintInfo(out);
            }
        }
    }
};

int main() {

    Sportsman s1("Bondarenko Oleg", "Full abonement");
    Sportsman s2("Ivan Petrenko", "Half abonement");
    Sportsman s3("Andriy Koval", "Monthly abonement");

    Coach Coach1("Kovalenko Andriy", "Trainer");
    Coach1.AddSportsman(s1);
    Coach1.AddSportsman(s2);

    Coach Coach2("Petrenko Roman", "Assistant");
    Coach2.AddSportsman(s3);

    Teacher teacher("Maria Shevchenko", "Physical Education");
    teacher.AddCoach(Coach1);
    teacher.AddCoach(Coach2);

    teacher.PrintInfo(cout);

  
    ofstream fout("teacher.txt");
    if (fout.is_open()) {
        teacher.PrintInfo(fout);
        fout.close();
        cout << "\n\nData successfully written to 'teacher_info.txt'" << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }

    return 0;
}
