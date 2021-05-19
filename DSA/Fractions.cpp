
class Fractions
{
private:
    int num ;
    int den ; 
public:
    Fractions(int num,int den);
    void simplify(){
        int gcd = 1;
        int j = std::min(num,den);
        for(int i = 1; i<=j;i++){
            if (this-> num%i==0 && this -> den %i==0){
                gcd = i;
            }
        }
        this->num = this->num/gcd;
        this->den = this->den/gcd;
         
    }
    Fractions getSum(Fractions const &f2){
        int lcm = f2.den * den;

        int x = lcm / den;
        int y = lcm / f2.den;
        
        int nume = (num*x)+(f2.num*y);
        Fractions fNew(nume,lcm);
        fNew.simplify();
        return fNew;
    }
    Fractions operator+(Fractions f2){
        int lcm = f2.den * den;
        int x = lcm / den;
        int y = lcm / f2.den;
        int num = (this->num*x)+(f2.num*y);
        Fractions fNew(num,lcm);
        fNew.simplify();
        return fNew;
    }
    void getProduct(Fractions f2){
        num=num * f2.num;
        den=den * f2.num;
        simplify();
    }
    Fractions operator*(Fractions& f2){
        Fractions fNew(num * f2.num,den * f2.den);
        fNew.simplify();
        return fNew;
    }
    bool operator==(Fractions f2){
        if((num==f2.num)&&(den==f2.den)){
           return true; 
        }else{
            return false;
        }
    }

    Fractions& operator++(){
        int nume = num + den;
        Fractions fNew(nume,den);
        return *this;
    }

    Fractions operator++(int){
        Fractions fNew(num,den);
        num = num+den;
        return fNew;
    }
    int getNum(){
        return num;
    }
    int getDen(){
        return den;
    }
    void setNum(int num){
        this->num = num;
    }
    void setDen(int den ){
        this->den = den;
    }
    
};

Fractions::Fractions(int num,int den)
{
    this->den = den;
    this->num = num;
}




