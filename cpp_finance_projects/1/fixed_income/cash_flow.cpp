/*
 * PV = FV/ (1+ R)^N
*/

#include <iostream>
#include <vector>
#include <cmath>

class CashFlowCalculator{
    std::vector<double> m_cashPayments;
    std::vector<int> m_timePeriods;  
    double m_rate;
  double presentValue(double futureVal, int TimePeriods){
    
    return futureVal / pow(1+ m_rate, TimePeriods);
  }

public:
  CashFlowCalculator(double rate): m_rate(rate){}

  CashFlowCalculator(const CashFlowCalculator &v): m_rate(v.m_rate){}

  CashFlowCalculator &operator =(const CashFlowCalculator &v){
    if (this != &v){
      this->m_cashPayments = v.m_cashPayments;
      this->m_timePeriods = v.m_timePeriods;
      this->m_rate = v.m_rate;
    }
    return *this;
  }

  ~CashFlowCalculator(){}
  double presentValue(){
    double total = 0;
    for(int i =0; i<m_cashPayments.size(); i++) total += presentValue(m_cashPayments[i], m_timePeriods[i]);
    return total;
  }

  void addCashPayment(double value, int TimePeriod){
    m_cashPayments.push_back(value);
    m_timePeriods.push_back(TimePeriod);
    
  }

};



int main (int argc, char *argv[]) {
  if (argc != 2){
  std::cout << "usage: progName <interest rate>" << std::endl;
  return 1;
  }
  double rate = atof(argv[1]);
  CashFlowCalculator cfc(rate);
  do {
    int period;
    std::cin >> period;
    if (period == -1) {
    break;
    }
    double value;
    std::cin >> value;
    cfc.addCashPayment(value, period);
  } while(1);

  double result = cfc.presentValue();
  std::cout << " The present value is " << result << std::endl;
  return 0;
}
