#ifndef GAME_LOGGER_FIELDLOGGER_H_
#define GAME_LOGGER_FIELDLOGGER_H_

class Field;

class FieldLogger {
public:
    FieldLogger& operator<<(const Field& field);
};

#endif //GAME_LOGGER_FIELDLOGGER_H_