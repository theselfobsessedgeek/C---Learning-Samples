#include<iostream>
using namespace std;
class College;
class Student{
    string name;
    int roll;
    int marks;
    int package_offered;
    int age;
    char p_grade;
    char grade;
    int college_ID;

    public:
    Student(){
        cout << "Welcome!" << endl;
        name = "0";
        roll = 0;
        marks = 0;
        package_offered = 0;
        age = 0;
        p_grade = packageGrade();
        grade = ' ';
        college_ID = 0;
    }

    Student(string n, int r, int m, int po, int a, int g, int id){
        cout << "Welcome!" << endl;
        name = n;
        roll = r;
        marks = m;
        package_offered = po;
        age = a;
        p_grade = packageGrade();
        grade = g;
        college_ID = id;
    }

    string getName(){
        return name;
    }

    void getValues(string n, int r, int m, int po, int a, int g, int id){
        name = n;
        roll = r;
        marks = m;
        package_offered = po;
        age = a;
        p_grade = packageGrade();
        grade = g;
        college_ID = id;
    }

    char packageGrade(){
        if (package_offered > 15){
            return 'A';
        }
        else{
            return 'B';
        }
    }

    void nameAscii(){
        cout << "The ascii value of the first character of your name is: " << (int)name[0] << endl;
    }

    void marksGrade(){
        cout << "Your grade is: " << grade << endl;
    }

    void show_details(){
        cout << "Name: " << name << endl;
        cout << "Roll  number: " << roll << endl;
        cout << "Marks: " << marks << endl;
        cout << "Package Offered: " << package_offered << endl;
        cout << "Age: " << age << endl;
        cout << "Package grade: " << p_grade << endl;
        cout << "Grade: " << grade << endl;
        cout << "College ID: " << college_ID << endl;

    }

    friend void calcTax(Student s, College c);
};


class College{
    string name;
    int college_ID;
    string state;
    int sem_fees_btech;
    int percentage_student_placement;

    public:
    College(){
        cout << "Welcome to your college!" << endl;
        name = "0";
        college_ID = 0;
        state = "0";
        sem_fees_btech = 0;
        percentage_student_placement = 0;
    }

    College(string n, int c_id, string s, int fees, int perc){
        cout << "Welcome to your college!" << endl;
        name = n;
        college_ID = c_id;
        state = s;
        sem_fees_btech = fees;
        percentage_student_placement = perc;
    }

    string getName(){
        return name;
    }

    void getValues(string n, int c_id, string s, int fees, int perc){
        name = n;
        college_ID = c_id;
        state = s;
        sem_fees_btech = fees;
        percentage_student_placement = perc;
    }

    void remarksForCollege(){
        if(percentage_student_placement > 80){
            cout << "Good" << endl;
        }
        else{
            cout << "Not good" << endl;
        }
    }

    void show_details(){
        cout << "Name: " << name << endl;
        cout << "College ID: " << college_ID << endl;
        cout << "State: " << state << endl;
        cout << "Sem-wise fees: " << sem_fees_btech << endl;
        cout << "Percentage of students placed: " << percentage_student_placement << endl;
    }
    friend void calcTax(Student s, College c);
};

void calcTax(Student s, College c){
    cout << ((s.package_offered * 100000 / s.age) - (c.sem_fees_btech)) * 8 << endl;
}

int main(){
    Student s;
    s.getValues("Shubham", 131, 90, 14, 22, 'A', 11);
    s.show_details();
    s.nameAscii();
    s.marksGrade();

    College c1;
    c1.getValues("Delhi Technological University", 11, "Delhi", 30000, 90);
    c1.show_details();
    c1.remarksForCollege();

    College c2("Netaji Subhash University of Technology", 2, "Delhi", 40000, 85);
    Student st_arr[2] = {Student("Ansh", 142, 67, 12, 22, 'C', 2), Student("Kanishk", 156, 96, 17, 22, 'A', 2)};
    for(int i = 0; i < 2; i++){
        st_arr[i].show_details();
        st_arr[i].nameAscii();
        st_arr[i].marksGrade();
        c2.show_details();
        c2.remarksForCollege();
    }
    cout << "Tax to be paid by " << s.getName() << ":"<< endl;
    calcTax(s, c1);

    for(int i = 0; i < 2; i++){
        cout << "Tax to be paid by " << st_arr[i].getName() << ":" << endl;
        calcTax(st_arr[i], c2);
    }
}