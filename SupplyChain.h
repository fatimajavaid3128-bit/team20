#ifndef SUPPLYCHAIN_H
#define SUPPLYCHAIN_H
#include <string>
using namespace std;

class SupplyChain {
   private:
   string name;
   string description;
   double cost;
    
   public:
   SupplyChain();
   SupplyChain(string name, string description, double cost);
   string GetName() const;
   string GetDescription() const;
   double GetCost() const;
   void PrintInfo() const;
};
#endif



