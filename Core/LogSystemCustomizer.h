#ifndef GAME_CORE_LOGSYSTEMCUSTOMIZER_H_
#define GAME_CORE_LOGSYSTEMCUSTOMIZER_H_

#include <iostream>
#include "../Utility/Log/Log.h"

class LogSystemCustomizer {
public:
    static inline void execute(bool& console_logging, bool& file_logging) {
        std::cout << "Select level of logging\n\t0 - Trace\n\t1 - Info\n\t2 - Warning\n\t3 - Error\n";
        char temp;
        std::cin >> temp;

        if (!(temp >= '0' && temp <= '3')) {
            return;
        }

        LOG.setFilterLevel(static_cast<Logger::Level>(temp - 48));

        std::cout << "Enable console logging? (y/n)\n";
        std::cin >> temp;
        switch (temp) {
            case 'y':
            case 'Y':
                console_logging = true;
                break;
            default:
                console_logging = false;
                break;
        }

        std::cout << "Enable file logging? (y/n)\n";
        std::cin >> temp;
        switch (temp) {
            case 'y':
            case 'Y':
                file_logging = true;
                break;
            default:
                file_logging = false;
                break;
        }

        system("cls");
    }
};

#endif //GAME_CORE_LOGSYSTEMCUSTOMIZER_H_