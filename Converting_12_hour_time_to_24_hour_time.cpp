
#include <iostream>
#include <string>
using namespace std;
//* Converting 12-hour time to 24-hour time
string to24HourTime(int hour, int minute, const string &period)
{
  string result="";
  if (period == "am" && hour == 12)
  {
    hour = 0;
  }
  else if (period == "pm" && hour < 12)
  {
    hour += 12;
  }
  if (hour < 10)
  {
    result += "0";
  }

    result += to_string(hour);
  
  if (minute < 10)
  {
    result += "0";
  }
  
    result += to_string(minute);


  return result;
}