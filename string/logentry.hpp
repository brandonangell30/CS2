//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

//
class Date {
public:
            Date() {};
            Date(String);
            friend std::ostream& operator<<(std::ostream&, const Date&);
private:
    String  day, month;
    int year;
};

//
class Time {
  public:
            Time() {};
            Time(String);
            friend std::ostream& operator<<(std::ostream&, const Time&);
  private:
    int  hour, minute, second;
};


// A single log entry
class LogEntry {
public:
            LogEntry() {};
            LogEntry(const String&);
            int getBytes() const {return number_of_bytes;};
            String getHost() const {return host;};
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);

#endif
