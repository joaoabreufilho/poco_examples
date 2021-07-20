/*!
 * @file main.cpp
 *
 * @brief Show Poco DateTime Arithmetics.
 */
#include <assert.h>
#include <iostream>

#include "Poco/DateTime.h"
#include "Poco/Exception.h"
#include "Poco/Timespan.h"
#include "Poco/Timestamp.h"

void testArithmetics() {
  Poco::DateTime dt1(2005, 1, 1, 0, 15, 30);
  Poco::DateTime dt2(2005, 1, 2, 0, 15, 30);

  Poco::Timespan s = dt2 - dt1;
  assert(s.days() == 1);

  Poco::DateTime dt3 = dt1 + s;
  assert(dt3 == dt2);

  dt3 -= s;
  assert(dt3 == dt1);
  dt1 += s;
  assert(dt1 == dt2);

  static const struct {
    int lineNum;        // source line number
    int year1;          // operand/result date1 year
    int month1;         // operand/result date1 month
    unsigned int day1;  // operand/result date1 day
    int numDays;        // operand/result 'int' number of days
    int year2;          // operand/result date2 year
    int month2;         // operand/result date2 month
    unsigned int day2;  // operand/result date2 day
  } data[] = {
      //          - - - -first- - - -           - - - second - - -
      // line no.  year   month   day   numDays  year   month   day
      //-------   -----  -----  -----  -------  -----  -----  -----
      {__LINE__, 1, 1, 1, 1, 1, 1, 2},
      {__LINE__, 10, 2, 28, 1, 10, 3, 1},
      {__LINE__, 100, 3, 31, 2, 100, 4, 2},
      {__LINE__, 1000, 4, 30, 4, 1000, 5, 4},
      {__LINE__, 1000, 6, 1, -31, 1000, 5, 1},
      {__LINE__, 1001, 1, 1, -365, 1000, 1, 1},
      {__LINE__, 1100, 5, 31, 30, 1100, 6, 30},
      {__LINE__, 1200, 6, 30, 32, 1200, 8, 1},
      {__LINE__, 1996, 2, 28, 367, 1997, 3, 1},
      {__LINE__, 1997, 2, 28, 366, 1998, 3, 1},
      {__LINE__, 1998, 2, 28, 365, 1999, 2, 28},
      {__LINE__, 1999, 2, 28, 364, 2000, 2, 27},
      {__LINE__, 1999, 2, 28, 1096, 2002, 2, 28},
      {__LINE__, 2002, 2, 28, -1096, 1999, 2, 28},
  };

  const int num_data = sizeof data / sizeof *data;
  for (int di = 0; di < num_data; ++di) {
    const int line = data[di].lineNum;
    const int num_days = data[di].numDays;
    Poco::DateTime x =
        Poco::DateTime(data[di].year1, data[di].month1, data[di].day1);
    const Poco::DateTime& X = x;
    x += Poco::Timespan(num_days, 0, 0, 0, 0);
    std::cout << "-----------------------" << std::endl;
    std::cout << "Year: " << X.year() << std::endl;
    std::cout << "Month: " << X.month() << std::endl;
    std::cout << "Day: " << X.day() << std::endl;

    /// @todo Needs cppunit libraries
    /// https://freedesktop.org/wiki/Software/cppunit/
    // loop_1_assert(line, data[di].year2 == X.year());
    // loop_1_assert(line, data[di].month2 == X.month());
    // loop_1_assert(line, data[di].day2 == X.day());
  }
  std::cout << "-----------------------" << std::endl;
}

int main(int argc, char* argv[]) {
  testArithmetics();
  return 0;
}