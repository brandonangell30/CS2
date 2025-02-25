//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

// REQUIRES: log gets host, date, time, and num of bytes
// ENSURES:  it looks nice
    LogEntry::LogEntry(const String& line) {
    if(line.length() == 0) return;
    std::vector<String> logEntryParts = line.split(' ');
    std::vector<String> rq = line.split('\"');
    if (logEntryParts.back() != '-') {
        String byts = logEntryParts.back();
        number_of_bytes = 0; //getting bytes
        for(int i = 0; i < byts.length(); ++i) {
        number_of_bytes *= 10;
        number_of_bytes += byts[i] - '0';
        }
    } 
    else {
        number_of_bytes = 0;
    }
    logEntryParts.pop_back(); //removing bytes
    status = logEntryParts.back();
    rq.pop_back();
    request = rq.back();
    rq.pop_back();
    logEntryParts = rq.back().split(' '); //remove rq
    logEntryParts.pop_back();
    logEntryParts.pop_back();
    time = logEntryParts.back(); //get time
    date = logEntryParts.back(); //get date
    logEntryParts.pop_back(); //remove them
    logEntryParts.pop_back();
    logEntryParts.pop_back();
    host = logEntryParts.back(); //getting host
}

Date::Date(String yos) {
    day = yos.substr(1, 2); //find day
    month = yos.substr(4, 6); //find month
    String yr(yos.substr(8, 11)); //find year
    year = 0;
    for(int i = 0; i < yr.length(); ++i) {
        year *= 10;
        year += yr[i] - '0';
    }
}
Time::Time(String yo) {
    std::vector<String> v = yo.split(':');
    String seconds = v.back();
    second = (seconds[0] - '0') * 10 + (seconds[1] - '0');
    v.pop_back();
    String minutes = v.back();
    minute = (minutes[0] - '0') * 10 + (minutes[1] - '0');
    v.pop_back();
    String hours = v.back();
    hour = (hours[0] - '0') * 10 + (hours[1] - '0');
}


// REQUIRES: line is less than 511 char since gotta account for '0'
// ENSURES: 
std::vector<LogEntry> parse(std::istream& in) {
    //string literals have capacity of 512 chars
    std::vector<LogEntry> result;
    while(true) {
        char c[512];
        in.getline(c, 511);
        if(in.eof()) break;
        result.push_back(LogEntry(String(c)));
    }
    return result;
}
std::ostream& operator<<(std::ostream& out, const LogEntry& rhs) {
    out << "Host: " << rhs.host << std::endl;
    out << "Date: " << rhs.date << std::endl ;
    out << "Time: " << rhs.time << std::endl;
    out << "Request: " << rhs.request << std::endl;
    out << "Status: " << rhs.status << std::endl;
    if(rhs.number_of_bytes != 0) {
        out<< "Bytes: ";
        out << rhs.number_of_bytes;
        out << std::endl;
    } else {
        out << '-';
    }
    return out;
}
std::ostream& operator<<(std::ostream& out, const Date& rhs) {
    out << rhs.day << '/' << rhs.month << '/' << rhs.year;
    return out;
}
std::ostream& operator<<(std::ostream& out, const Time& rhs) {
    if(rhs.hour < 10) {
        out << '0' << rhs.hour << ':';
    } else {
        out << rhs.hour << ':';
    }
    if(rhs.minute < 10) {
        out << '0' << rhs.minute << ':';
    } else {
        out << rhs.minute << ':';
    }
    if(rhs.second < 10) {
        out << '0' << rhs.second;
    } else {
        out << rhs.second;
    }
    return out;
}
// REQUIRES: that the vector is printed
// ENSURES: everything is printed
void output_all(std::ostream& out, const std::vector<LogEntry>& v) {
    int size = v.size();

    for(int i = 0; i < size; ++i) {
        out << v[i] << std::endl;
    }
}
// REQUIRES: host information is printed
// ENSURES: everything is printed
void by_host(std::ostream& out, const std::vector<LogEntry>& v) {
    int size = v.size();
    for(int i = 0; i < size; ++i) {
        out << v[i].getHost() << std::endl;
    }
}
// REQUIRES: bytes are printed
// ENSURES: everything is printed
int byte_count(const std::vector<LogEntry>& v) {
    int size = v.size();
    int result = 0;
    for(int i = 0; i < size; ++i) {
        result += v[i].getBytes();
    }
    return result;
}

