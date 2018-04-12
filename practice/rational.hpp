/*
 Implement a rational number class. The class must:
 
 Only allow the creation of valid rational numbers
    Support equality (==, !=)
    Support ordering (<, >, <=, >=)
    Support basic arithmetic operators (+, - , * /)
    Support input and output using istream (>>) and ostream (<<)
 
 The input and output format form rational numbers should be of the form "n / d".

 */



class Rational
{
private:
    // We need a numerator and denominator to correctly represent our rational number
    int num;
    int den;
    
public:
    // Constructor
    Rational(int n, int d)
    : num(n), den(d) {}
    
    
    
    
    
    
};


/*
 std::ostream& operator<<(std::ostream& os, const T& obj)
 {
 // write obj to stream
 return os;
 }
 std::istream& operator>>(std::istream& is, T& obj)
 {
 // read obj from stream
 if( //T could not be constructed )
is.setstate(std::ios::failbit);
return is;
}
 
 
 
 */
