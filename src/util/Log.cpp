#include "src/util/Log.h"
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>

using namespace std;

bool Log::debugMode = false;

void Log::log(const string s) {
  cout << KNRM <<  s << KNRM << endl;
}

void Log::error(const string s) {
  cerr << KRED << s << KNRM << endl;
}

void Log::warn(const string s) {
  cerr << KYEL << s << KNRM << endl;
}

void Log::debug(const string s) {
  if (debugMode) {
    boost::posix_time::ptime mst1 = boost::posix_time::microsec_clock::local_time();
    cout << boost::posix_time::to_simple_string(mst1) << ": "<< KBLU << s << KNRM << endl;
  }
}

void Log::success(const string s) {
  cout << KGRN << s << KNRM << endl;
}
