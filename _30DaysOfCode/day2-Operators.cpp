#include <bits/stdc++.h>

using namespace std;

int main()
{
    // input
    double meal_cost;
    cin >> meal_cost;
    int tip_percent;
    cin >> tip_percent;
    int tax_percent;
    cin >> tax_percent;
    
    // crazy math
    double tip = meal_cost * (tip_percent/100.f);
    double tax = meal_cost * (tax_percent/100.f);
    double total_cost = meal_cost + tip + tax;
    
    // output
    cout << "The total meal cost is "<< round(total_cost) 
         << " dollars." << endl;

    return 0;
}