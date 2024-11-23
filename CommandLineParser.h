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

private:
    int argc;
    char** argv;
    size_t frequency;
    size_t speed;
    size_t line_len;
    bool epilepsia;

    static void printHelp();
    bool parseFrequency();
    bool parseSpeed();
    bool parseLineLength();
    bool parseEpilepsia();
};



#endif //COMMANDLINEPARSER_H
