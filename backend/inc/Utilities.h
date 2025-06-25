/**
* @file Utilities.h
* @brief header file for the Utilities class.
*/
#ifndef UTILITIES_H
#define UTILITIES_H

namespace Utilities {
    constexpr int DAY_S = 86400;
    constexpr int HOUR_S = 3600;
    constexpr int MINUTE_S = 60;
    inline int numberOfDecks = 0;

    /**
     * @brief Generates id
     *
     * @return generated id
     */
    int GenerateId();
}

#endif //UTILITIES_H
