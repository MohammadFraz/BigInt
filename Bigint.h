#include <string>
#include <iostream>
 
class Bigint
{
public:
  Bigint(): s(0), n() {}
  Bigint(const std::string&);
  Bigint(long long);
 
  Bigint(const Bigint& b): s(b.s), n(b.n) {}
  const Bigint& operator=(const Bigint& b) {s = b.s; n = b.n; return *this;}
 
  Bigint operator+(const Bigint& b) const;
  Bigint operator-(const Bigint& b) const {return *this + (-b);}
  Bigint operator-()              const {return Bigint(-s, n);}
  Bigint operator*(const Bigint& b) const;
  Bigint operator/(const Bigint& b) const;
  Bigint operator%(const Bigint& b) const;
  
  bool operator==(const Bigint& b) const {return s == b.s && n == b.n;}
  bool operator!=(const Bigint& b) const {return !(*this == b);}
  bool operator< (const Bigint& b) const;
  bool operator<=(const Bigint& b) const {return *this == b || *this < b;}
  bool operator> (const Bigint& b) const {return !(*this <= b);}
  bool operator>=(const Bigint& b) const {return !(*this < b);}
  
  const Bigint& operator+=(const Bigint& b) {*this = *this + b; return *this;}
  const Bigint& operator-=(const Bigint& b) {*this = *this - b; return *this;}
  const Bigint& operator*=(const Bigint& b) {*this = *this * b; return *this;}
  const Bigint& operator/=(const Bigint& b) {*this = *this / b; return *this;}
  const Bigint& operator%=(const Bigint& b) {*this = *this % b; return *this;}
  
  Bigint& operator++()    {*this += 1; return *this;}
  Bigint& operator--()    {*this -= 1; return *this;}
  Bigint  operator++(int) {Bigint t(*this); *this += 1; return t;}
  Bigint  operator--(int) {Bigint t(*this); *this -= 1; return t;}
  
  friend std::ostream& operator<<(std::ostream&, const Bigint&);
 
  long long  toLong()         const;
  Bigint     Bpow(int pot)    const;
  size_t     numberOfDigits() const {return n.size();}
  long long  sumOfDigits()    const;
  Bigint     abs()            const {return Bigint(s!=0, n);}
  Bigint     reverse()        const {std::string t; t.assign(n.rbegin(),n.rend()); return Bigint(s, t);}
  bool       isPalindrome()   const {return *this == this->reverse();}
  bool       isEven()         const {return (n[0]-'0')%2==0;}
  bool       isOdd()          const {return (n[0]-'0')%2==1;}
  Bigint     factorial()      const;
  bool       isPrime()        const;
  
private:
  int s;         // sign: -1, 0 or 1
  std::string n; // reversed number -aka little-endian format- allows easy carry propagation
 
  Bigint(int i, const std::string& str): s(i), n(str) {};
};
 
std::istream& operator>>(std::istream&, Bigint&);
 
inline long long  toLong(const Bigint& b)         {return b.toLong();}
inline Bigint       Bpow(const Bigint& b, int p)    {return b.Bpow(p);}
inline size_t     numberOfDigits(const Bigint& b) {return b.numberOfDigits();}
inline long long  sumOfDigits(const Bigint& b)    {return b.sumOfDigits();}
inline Bigint       abs(const Bigint& b)            {return b.abs();}
inline Bigint       reverse(const Bigint& b)        {return b.reverse();}
inline bool       isPalindrome(const Bigint& b)   {return b.isPalindrome();}
inline bool       isEven(const Bigint& b)         {return b.isEven();}
inline bool       isOdd(const Bigint& b)          {return b.isOdd();}
inline Bigint       factorial(const Bigint& b)      {return b.factorial();}
inline bool       isPrime(const Bigint& b)        {return b.isPrime();}
