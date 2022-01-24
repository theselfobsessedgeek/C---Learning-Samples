#include<iostream>
#include<string>
using namespace std;
class Son{
    string sName;
    int pocketMoney;
    int grade;
    long sAccountNumber;
    int sAmountInBank;
public:
    Son(string name,int grade,long accountNumber,int amountInBank){
        sName=name;
        this->grade=grade;
        sAccountNumber=accountNumber;
        pocketMoney=calPocketMoney(grade);
        sAmountInBank=amountInBank+pocketMoney;
    }
    int calPocketMoney(int grade){
        if(grade>90)
        return 15000;
        else if(grade>80 && grade<=90)
        return 10000;
        else
        return 5000;
    }
    void showBalance(){
        cout<<"-------show balance function of son---------"<<endl;
        cout<<"Son's Balance after pocket money transfer = "<<sAmountInBank<<endl;
    }
    friend class Father;
    friend class Bank;
};
class Father{
string fName;
int fSalary;
string designation;
long fAccountNumber;
int fAmountInAccount;
int pocketMoneyGiven;
public:
Father(string name,int sal,string post,long accNo,int bankAmount){
fName=name;
fSalary=sal;
designation=post;
fAccountNumber=accNo;
fAmountInAccount=bankAmount;
}
void putPocketMoney(Son s){
pocketMoneyGiven=s.pocketMoney;
fAmountInAccount=fAmountInAccount-s.pocketMoney;
}
void showBalance(){
cout<<"-------show balance function of father---------"<<endl;
cout<<"Pocket money given to son = "<<pocketMoneyGiven<<endl;
cout<<"Amount of money in bank after giving pocketMoney = "<<fAmountInAccount<<endl;
}
friend class Bank;
};
class Bank{
int id;
long accountNum;
int taxCalculated;
public:
Bank(int ID,int accNo){
id=ID;
accountNum=accNo;
}
void calTax(Son s, Father &f){
taxCalculated=(s.sAmountInBank+f.fAmountInAccount)*0.1;
f.fAmountInAccount-=taxCalculated;
}
void show(Son s, Father f){
cout<<"--------Details of son and father----------"<<endl;
cout<<"---------Son's Details----------"<<endl;
cout<<"Son's Name ="<<s.sName<<endl;
cout<<"Son's PocketMoney ="<<s.pocketMoney<<endl;
cout<<"Son's Grade ="<<s.grade<<endl;
cout<<"Son's Account number ="<<s.sAccountNumber<<endl;
cout<<"Son's Amount in bank ="<<s.sAmountInBank<<endl;
cout<<"---------Father's Details----------"<<endl;
cout<<"Father's Name ="<<f.fName<<endl;
cout<<"Father's Salary ="<<f.fSalary<<endl;
cout<<"Father's Designation ="<<f.designation<<endl;
cout<<"Father's Account number ="<<f.fAccountNumber<<endl;
cout<<"Father's Amount in account ="<<f.fAmountInAccount<<endl;
}
};
int main(){
Son s("Rohan",81,10002356,100000);
s.showBalance();
Father f("Vishal",200000,"Engineer",297846533,5000000);
f.putPocketMoney(s);
f.showBalance();
Bank b(24,297846533);
b.calTax(s,f);
b.show(s,f);
}