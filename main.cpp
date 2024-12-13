#include "AppManager.h"
#include "CommandLineParser.h"

int main(const int argc, char* argv[]) {
    CommandLineParser parser(argc, argv);

    const int parseResult = parser.parse();

    if (parseResult == 1) { // неправильный консольный ввод
        return 1;
    }
    if (parseResult == 2) { // не было аргументов
        AppManager app(parser.isEpilepsia(), parser.getLineLength(), parser.getSpeed(), parser.getFrequency(), parser.getChance(), parser.getMinRadius(), parser.getMaxRadius()); // передаются параметры по умолчанию из CommandLineParser надо избавиться перегрузкой конструктора
        app.inputParameters(); // ввод параметров через диалоговый режим
        app.run();
        return 0;
    }
    if (parseResult == 3) { // три правильных параметра
        AppManager app(parser.isEpilepsia(), parser.getLineLength(), parser.getSpeed(), parser.getFrequency(), parser.getChance(), parser.getMinRadius(), parser.getMaxRadius());
        app.run();
        return 0;
    }
}
