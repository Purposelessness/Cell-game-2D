#ifndef GAME_CORE_LOGSYSTEMCUSTOMIZER_H_
#define GAME_CORE_LOGSYSTEMCUSTOMIZER_H_

#include <iostream>

#include "../Utility/Log/Log.h"

class LogSystemCustomizer final {
 public:
  struct Result {
    bool console_logging;
    bool file_logging;
  };

  static inline Result execute() {
    std::cout << "Select level of logging\n\t0 - Trace\n\t1 - Info\n\t2 - "
                 "Warning\n\t3 - Error\n";
    char temp = 0;
    std::cin >> temp;

    if (temp < '0' || temp > '3') {
      return {false, true};
    }

    const char kOffset = 48;
    LOG.setFilterLevel(static_cast<Logger::Level>(temp - kOffset));

    std::cout << "Enable console logging? (y/n)\n";
    std::cin >> temp;
    bool console_logging = temp == 'y' || temp == 'Y';

    std::cout << "Enable file logging? (y/n)\n";
    std::cin >> temp;
    bool file_logging = temp == 'y' || temp == 'Y';
    
    return {console_logging, file_logging};
  }
};

#endif  // GAME_CORE_LOGSYSTEMCUSTOMIZER_H_
