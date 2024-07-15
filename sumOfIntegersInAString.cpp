//! first solution
#include <iostream>
#include <string>
using namespace std;

int sumOfIntegers(const string &str)
{
  int sum = 0;
  int current = 0;
  for (auto num : str)
  {
    if (isdigit(num))
    {
      current *= 10;
      current += (num - '0');
    }
    else
    {
      sum += current;
      current = 0; // resets the current to hold another val
    }
  }
  sum += current;
  return sum;
}

int main()
{
  cout << sumOfIntegers("12.4") << endl;       // Should print 16 (12 + 4)
  cout << sumOfIntegers("h3ll0w0rld") << endl; // Should print 3 (3 + 0 + 0)
  return 0;
}

//! second solution
// #include <iostream>
// #include <string>
// using namespace std;

// int sumOfIntegers(const string &str)
// {
//   int sum = 0;
//   string temp = ""; // Temporary string to hold numbers

//   for (int i = 0; i < str.size(); i++)
//   {
//     if (isdigit(str[i]))
//     {
//       temp += str[i]; // Build the number
//     }
//     else
//     {
//       if (!temp.empty())
//       {
//         sum += stoi(temp); // Convert the collected string to an integer and add to sum
//         temp = "";         // Reset the temporary string
//       }
//     }
//   }

//   if (!temp.empty()) // Add the last number if any
//   {
//     sum += stoi(temp);
//   }

//   return sum;
// }

// int main()
// {
//   cout << sumOfIntegers("12.4") << endl;       // Should print 16 (12 + 4)
//   cout << sumOfIntegers("h3ll0w0rld") << endl; // Should print 3 (3 + 0 + 0)
//   return 0;
// }
