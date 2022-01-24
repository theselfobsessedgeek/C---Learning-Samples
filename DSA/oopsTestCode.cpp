// #include<bits/stdc++.h> 

// using namespace std;

// class College{
//     protected:
//         string name;
//         int ranking;
//     public:
//         College(string s, int r){
//             name =  s;
//             ranking = r;
//         }
        
//         /*

//         -----------NOTE-----------
//         - The following declaration of function is called a pure virrutal function.
//         - This is the function that will be overridden in the derived class.
//         - The way to override a function is by defining the function in the derived class.
//         - If we don't define the function in the derived class, then the compiler will throw an error.
        
//         */
//         virtual void display()=0;   
// };
// class Student: public College
// {
//     string sname;
//     int year;
//     public:
//         Student(string s, int r,string sn, int yr): College(s, r){
//             sname = sn;
//             year = yr;
//         }
//         void display(){
//             cout<<"College's Name : "<<name<<endl;
//             cout<<"Ranking: "<<ranking<<endl;
//             cout<<"Student's Name: "<<sname<<endl;
//             cout<<"Year: "<<year<<endl;
//         }
// };
// class Professor: public College
// {
//     string pname;
//     int publications;
//     public:
//         Professor(string s, int r,string pn, int pub): College(s, r){
//             pname = pn;
//             publications = pub;
//         }
//         // void display(){
//         //     cout<<"College's Name : "<<name<<endl;
//         //     cout<<"Ranking: "<<ranking<<endl;
//         //     cout<<"Professor's Name: "<<pname<<endl;
//         //     cout<<"Publications: "<<publications<<endl;
//         // }

// };


// int main(){

//     Student s1("Harvard", 1, "Shubham", 2);

//     Professor p1("MIT", 2, "Shubham", 3);

//     s1.display();
//     cout<<endl;
//     p1.display();
//     return 0;
// }

//----------------------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h> 

using namespace std;

class College{
    string name;
    int ranking;
    public:
        College(string s, int r){
            cout<<"parameterized constructor of College called"<<endl;
            name =  s;
            ranking = r;
        }
        College(){
            cout<<"default constructor of College called"<<endl;
            name = "No College";
            ranking = 0;
        }
        College(College &c){
            cout<<"copy constructor of College called"<<endl;
            name = c.name;
            ranking = c.ranking;
        }
        ~College(){
            cout<<"Destructor called"<<endl;
        }
        void display(){
            cout<<"College's Name : "<<name<<endl;
            cout<<"Ranking: "<<ranking<<endl;
        }
        
};


int main(){
    
    cout<<endl;

    College c1("MIT", 1);
    College c2;
    College c3(c1);
    
    cout<<endl;
    
    c1.display();
    cout<<endl;

    c2.display();
    cout<<endl;

    c3.display();
    cout<<endl;



    return 0;
}