#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() { cout << "Name: " << name << ", Age: " << age << endl; }
};

class Student : public Person {
protected:
    int rollNumber;
    string branch;
    double marks;
public:
    Student(string n, int a, int roll, string b, double m) : Person(n, a), rollNumber(roll), branch(b), marks(m) {}
    double calculateCGPA() { return marks / 10; }
    void display() { Person::display(); cout << "Roll: " << rollNumber << ", Branch: " << branch << ", CGPA: " << calculateCGPA() << endl; }
};

class Faculty : public Person {
protected:
    int facultyID;
    string department;
    double salary;
public:
    Faculty(string n, int a, int id, string dep, double sal) : Person(n, a), facultyID(id), department(dep), salary(sal) {}
    void display() { Person::display(); cout << "ID: " << facultyID << ", Dept: " << department << ", Salary: " << salary << endl; }
};

class TeachingAssistant : public Student, public Faculty {
public:
    TeachingAssistant(string sn, int sa, int roll, string branch, double marks, string fn, int fa, int id, string dep, double sal) : Student(sn, sa, roll, branch, marks), Faculty(fn, fa, id, dep, sal) {}
    void display() { Student::display(); Faculty::display(); }
};

class Administration {
public:
    friend void showDetails(const Student& s, const Faculty& f);
};

void showDetails(const Student& s, const Faculty& f) {
    cout << "Admin: " << s.name << " scored " << s.marks << ", " << f.name << " teaches " << f.department << endl;
}

int main() {
    Student s("Raj", 20, 1, "CSE", 89);
    Faculty f("Dr. A", 45, 1001, "CS", 120000);
    TeachingAssistant ta("Priya", 25, 5, "AI", 90, "Dr. A", 45, 2005, "AI", 35000);
    s.display(); cout << endl;
    f.display(); cout << endl;
    ta.display(); cout << endl;
    showDetails(s, f);
    return 0;
}