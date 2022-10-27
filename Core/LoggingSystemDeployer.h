#ifndef GAME_CORE_LOGGINGSYSTEMDEPLOYER_H_
#define GAME_CORE_LOGGINGSYSTEMDEPLOYER_H_

#include <iostream>

#include "../Utility/Log/Log.h"
#include "../Observer/LogObserver.h"
#include "../Engine/View/ViewSystem.h"

class LoggingSystemDeployer {
public:
    static inline auto start(const std::shared_ptr<ViewSystem>& view_system) {
#ifdef LOGGING
        std::cout << "Enter logging level\n\t0 - Trace\n\t1 - Info\n\t2 - Warning\n\t3 - Error\n\tAny other symbol - exit logging setup";
        char level_ch;
        std::cin >> level_ch;

        auto log_observer = std::make_shared<LogObserver<ViewSystem>>(view_system);

        if (!(level_ch >= '0' && level_ch <= '9')) {
            return log_observer;
        }

        auto level = static_cast<Logger::Level>(level_ch);
        LOG.setFilterLevel(level);
#endif
        return log_observer;
    }
};

#endif //GAME_CORE_LOGGINGSYSTEMDEPLOYER_H_