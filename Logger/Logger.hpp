#include <iostream>

struct Logger
{
   std::fstream logs;
   void log(const std::string& msg);
   ~Logger();
};

