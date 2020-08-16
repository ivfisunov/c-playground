//
// Created by Ivan Fisunov on 16.08.2020.
//
#include <iostream>

class Logger {
public:
    virtual ~Logger() = default;
    virtual void logTransfer(int from, int to, int amount) = 0;
};

class FileLogger : public Logger {
public:
    void logTransfer(int from, int to, int amount) override {
        std::cout << "[file] " << from << " --> " << to << " : " << amount << std::endl;
    }
};

class ConsoleLoger : public Logger {
    void logTransfer(int from, int to, int amount) override {
        std::cout << "[console] " << from << " --> " << to << " : " << amount << std::endl;
    }
};

class Bank {
public:
    void setLogger(Logger *log) {
        logger = log;
    }
    // transfer money from to amount
    void transferMoney(int from, int to, int amount) {
        if (logger) {
            logger->logTransfer(from, to, amount);
        }
    }

private:
    Logger *logger{};
};

void startBank() {
    std::cout << "--> Bank transfer. Interface implementation." << std::endl;
    Bank bank{};
    FileLogger fileLogger{};
    bank.setLogger(&fileLogger);
    bank.transferMoney(1000, 2000, 5555);
    ConsoleLoger consoleLoger{};
    bank.setLogger(&consoleLoger);
    bank.transferMoney(2020, 4040, 1000000);
}