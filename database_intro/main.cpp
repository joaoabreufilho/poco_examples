/*!
 * @file main.cpp
 *
 * @brief Use Poco C++ library to connect to SQLite Database.
 *
 * @details The Poco C++ library has been around for a while now. Poco includes
 * various libraries for building network-based and internet-based applications
 * that run on desktop, server, mobile, IoT, and embedded systems. Equipped with
 * latest industry standard libraries it is being seen as a competitor for boost
 * libraries.
 *
 * Here we will explore Poco::Data namespace and use Poco::Data::SQLite to
 * create, insert and read data from a SQLite Database. 
 * 
 * --------------------------------------------------------
 * Step 1: Create a new sample
 * database in SQLite3 
 * 
 * sudo apt install sqlite3
 * $sqlite3 sample.db
 */
#include <iostream>
#include <vector>
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/Session.h"

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

struct Person {
  std::string name;
  std::string address;
  int age;
};

int main() {
  // register SQLite connector
  Poco::Data::SQLite::Connector::registerConnector();

  // create a session
  Session session("SQLite", "sample.db");

  // drop sample table, if it exists
  session << "DROP TABLE IF EXISTS Person", now;

  // (re)create table
  session << "CREATE TABLE Person (Name VARCHAR(30), Address VARCHAR, Age "
             "INTEGER(3))",
      now;

  // insert some rows
  Person person = {"MS Dhoni", "Ranchi", 34};

  Statement insert(session);
  insert << "INSERT INTO Person VALUES(?, ?, ?)", use(person.name),
      use(person.address), use(person.age);

  insert.execute();

  person.name = "Virat Kohli";
  person.address = "Delhi";
  person.age = 28;

  insert.execute();

  // a simple query
  Statement select(session);
  select << "SELECT Name, Address, Age FROM Person", into(person.name),
      into(person.address), into(person.age),
      range(0, 1);  //  iterate over result set one row at a time

  while (!select.done()) {
    select.execute();
    std::cout << person.name << " " << person.address << " " << person.age
              << std::endl;
  }

  return 0;
}