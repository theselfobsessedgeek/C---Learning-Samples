
class Student{
    public :     
    int rollNumber;

    private : 
    int age;

    public:

    Student(){
        cout<<"Constructor called"<<endl;

    }
    //PARAMETERISED CONSTRUCTOR

    Student(int rollNumber){
        cout<<"Constructor 2 called !!"<<endl;
        this -> rollNumber = rollNumber;
    }    

    void setAge(int a,int password){
        if(a<0||password!=123){
            return;
        }
        
        age = a;
    }
    void printDetails(){
        cout << age<<" "<<rollNumber<< endl;
    }
    int getAge(){
        return age;
    }
    
};