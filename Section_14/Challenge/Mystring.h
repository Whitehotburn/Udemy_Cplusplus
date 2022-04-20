#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);  // insertion
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);        // extraction

    friend bool operator==(const Mystring &lhs, const Mystring &rhs);    // equality
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);    // non-equality
    friend Mystring operator-(const Mystring &obj);                      // lowercase
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs); // concatenate

    friend bool operator<(const Mystring &lhs, const Mystring &rhs);  // less than lexically
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);  // greater than lexically

    friend Mystring operator+=(Mystring &lhs, const Mystring &rhs); // += operator
    friend Mystring operator*(const Mystring &lhs, const int &rhs); // * operator
    friend Mystring operator*=(Mystring &lhs, const int &rhs);      // *= operator

    friend Mystring &operator++(Mystring &obj);      // pre-increment, make uppercase
    friend Mystring operator++(Mystring &obj, int);  // post-increment, make uppercase

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                   // No-args constructor
    Mystring(const char *s);                      // Overloaded constructor
    Mystring(const Mystring &source);             // Copy constructor
    Mystring( Mystring &&source);                 // Move constructor
    ~Mystring();                                  // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);          // Move assignment
    
    void display() const;
    
    int get_length() const;                       // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_