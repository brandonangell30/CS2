#include <iostream>
#include <string>

const int STRING_SIZE = 512;

int calculatePopulation(int, int);

bool isValidInteger(const std::string& str) { //make sure nobody types strings instead of ints
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return !str.empty();
}

int stringToInt(const std::string& str) {
    int result = 0;
    for (char ch : str) {
        result = result * 10 + (ch - '0'); // make ch into int
    }
    return result;
}

int main(int argc, const char * argv[]) {

    std::cout << "Enter the name of the university\n";
    char univName[STRING_SIZE];
    std::cin.getline(univName, STRING_SIZE);

    char done = 'N';
    while (done != 'Y' && done != 'y') {

        int pop;
        while (true) {
            std::cout << "What is the current population? ";
            std::string input;
            std::cin >> input;

            if (isValidInteger(input)) {
                pop = stringToInt(input);
                if (pop > 0) break; // if pos int break
            }
            std::cout << argv[0] << " Invalid input! Population must be a positive integer.\n";
        }

        int growth;
        while (true) {
            std::cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
            std::string input;
            std::cin >> input;

            if (isValidInteger(input)) {
                growth = stringToInt(input);
                if (growth >= 0) break; // if !negative break
            }
            std::cout << argv[0] << " Invalid input! Growth rate must be a non-negative integer.\n";
        }

        std::cout << "\nYear\tNew Population" << std::endl;
        int newpop;
        for (int i = 1; i <= 5; i++) {
            newpop = calculatePopulation(pop, growth);
            pop = newpop;
            std::cout << i << "\t\t" << newpop << std::endl;
        }

        std::cout << "\nFinal population of " << univName;
        std::cout << " is " << newpop << std::endl;

        std::cout << "Done? (Y/N) ";
        std::cin >> done;
        switch (toupper(done)) {
            case 'Y':
                std::cout << "Exiting...\n";
                break;
            case 'N':
                std::cout << "Starting again\n";
                std::cout << "------------------------------\n";
                break;
            default:
            if(argc == 1)
              std::cout << argv[0] << ": Invalid input\n"; //fix argv[2]
                std::cout << "The program will exit\n";
                std::cout << "------------------------------\n";
                return -1;
        }
    }
    return 0;
}

int calculatePopulation(int pop, int growth) {
    double growthRate = static_cast<double>(growth) / 100;
    double increase = static_cast<double>(pop) * growthRate;
    return static_cast<int>(pop + increase);
}

