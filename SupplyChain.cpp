#include <iostream>
#include "SupplyChain.h"
using namespace std;

SupplyChain::SupplyChain(){
  name =  "Unknown";
  description = "No description";
  cost = 0;
}

SupplyChain::SupplyChain(string n, string d, double c){
   name = n;
   description = d;
   cost = c;
}

string SupplyChain::GetName() const{
   return name;
}

string SupplyChain::GetDescription() const{
   return description;
}

double SupplyChain::GetCost() const{
   return cost;
}
void SupplyChain::PrintInfo() const {
   cout << "Name: " << name << endl;
   cout << "Description: " << description << endl;
   cout << "Cost: $" << cost << endl;
}







