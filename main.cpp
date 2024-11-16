#include "AppManager.h"
#include "CommandLineParser.h"

int main(int argc, char* argv[]) {
    CommandLineParser parser(argc, argv);

    int parseResult = parser.parse();
    if (parseResult == 1) { // неправильный консольный ввод
        return 1;
    } else if (parseResult == 2) { // не было аргументов
        AppManager app(parser.isEpilepsia(), parser.getLineLength(), parser.getSpeed());
        app.inputParameters(); // ввод параметров через диалоговый режим
        app.run();
        return 0;
    } else if (parseResult == 3) { // три правильных параметра
        AppManager app(parser.isEpilepsia(), parser.getLineLength(), parser.getSpeed());
        app.run();
        return 0;
    }

}