#include "AppManager.h"
#include "CommandLineParser.h"
#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]) {
    CommandLineParser parser(argc, argv);

    if (parser.parse() == 1) { // неправильный консольный ввод
        return 1;
    } else if (parser.parse() == 2) { // не было аргументов
        AppManager app(parser.isEpilepsia(), parser.getLineLength(), parser.getSpeed());
        app.inputParameters(); // ввод параметров через диалоговый режим
        app.run();
        return 0;
    } else if (parser.parse() == 3) { // три правильных параметра
        AppManager app(parser.isEpilepsia(), parser.getLineLength(), parser.getSpeed());
        app.run();
        return 0;
    }

}