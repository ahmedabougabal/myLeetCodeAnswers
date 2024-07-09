#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  double averageWaitingTime(vector<vector<int>> &customers)
  {
    double sum = 0;
    double average;
    double currentTime = 0; // Current time the chef has worked till now
    double arrivalTime;
    double cookingTime; // How long it takes to make the food

    for (vector<int> vec : customers)
    {
      //! splitting the 2d vector to two separate variables since customers vector is a 2d vector
      arrivalTime = vec[0];
      cookingTime = vec[1]; // Get the cooking time for the customer's food

      // If the chef is free before the customer arrives, wait till the customer arrives
      if (currentTime < arrivalTime)
      {
        currentTime = arrivalTime;
      }

      currentTime += cookingTime;         // Add the cooking time to the current time
      sum += (currentTime - arrivalTime); // the waiting time for this customer
    }

    average = sum / customers.size();
    return average;
  }
};
