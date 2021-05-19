#include<math.h>
class ComplexNumbers
{
private:
    int re;
    int im; 
public:
    ComplexNumbers(int re,int im){
        this -> im = im;
        this -> re = re;
    }

    void plus(ComplexNumbers c2){
        re = re + c2.re;
        im = im + c2.im;
    }
    void multiply(ComplexNumbers c2){
        int a = re;
        re = (re * c2.re)-(c2.im * im) ;

        im = (a * c2.im)+(c2.re * im);
    }
    int magnitude(){
        int mag = pow(re,2)+pow(im,2);
        return mag;
    }
    int args(){
        int args = im/re ;
        return args;
    }
    void print(){
        cout<<re<<" + "<<"i"<<im<<endl;
    }
    ~ComplexNumbers();
};


