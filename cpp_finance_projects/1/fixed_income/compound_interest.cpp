/*
 *  V=P(1+R)^2
 *  V=Pe^(RN)
 */
#include <iostream>
#include <cmath>

class cmp{
  double m_rate;
  public:
  cmp(double rate): m_rate(rate) {}
  cmp &operator =(const cmp &v){
     if(this != &v) this->m_rate = v.m_rate;
    return *this;
  }
  cmp(const cmp  &v) : m_rate(v.m_rate) {}
  ~cmp(){}
  double multiplePeriod(double value, int numPeriods){
    return value * pow(1 + m_rate, numPeriods);
  }
  double continuousCompounding(double value, int numPeriods){
    return value * exp(m_rate * numPeriods);
  }


};



int main (int argc, char *argv[]) {
  if (argc != 4){std::cout << "usage: progName <interest rate> <present value> <numperiods>" << std::endl;
  return 1;
}
  double rate = atof(argv[1]);
  double value = atof(argv[2]);
  int num_periods = atoi(argv[3]);

  cmp x(rate);
  
  
 std::cout << " future value for multiple period compounding is " << x.multiplePeriod(value, num_periods) << std::endl;

 std::cout << " future value for continuous compounding is " << x.continuousCompounding(value, num_periods)<< std::endl;

  return 0;
}
