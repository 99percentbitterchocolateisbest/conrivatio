// V = P(1+R)

#include <iostream>
class IntRate{
public:
  IntRate(double rate) : m_rate(rate){}
  IntRate(const IntRate &v): m_rate(v.m_rate){}
  IntRate &operator =(const IntRate &v){
  if(&v != this) this->m_rate = v.m_rate;
  return *this;
  }
  ~IntRate(){};
  inline double single_period(double value){
    return value * (1 + m_rate);
  }
private:
  double m_rate;
};


int main (int argc, const char * argv[]) {
  if(argc != 3){  std::cout<< "Usage: <program> <interest_rate> <value>" << std::endl; return 1; }

  IntRate x(atof(argv[1]));
  std::cout << x.single_period(atof(argv[2]));

  return 0;
}
