//
// Created by Сергей Шорин on 21.10.2024.
//

#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <iostream>
#include <string>

class CommandLineParser {
public:
    CommandLineParser(int argc, char* argv[]);
    int parse();

    size_t getFrequency() const;
    size_t getSpeed() const;
    size_t getLineLength() const;
    bool isEpilepsia() const;
    size_t getChance() const;
    size_t getMinRadius() const;
    size_t getMaxRadius() const;

private:
    int argc;
    char** argv;
    size_t frequency;
    size_t speed;
    size_t line_len;
    bool epilepsia;
    size_t chance;
    size_t min_radius;
    size_t max_radius;

    static void printHelp();
    bool parseFrequency();
    bool parseSpeed();
    bool parseLineLength();
    bool parseEpilepsia();
    bool parseChance();
    bool parseMinRadius();
    bool parseMaxRadius();
};



#endif //COMMANDLINEPARSER_H
