#pragma once

#include "../party/Party.h"

class Command {
public:
    virtual void execute() = 0;
    virtual void execute(Party* party) = 0;
    virtual ~Command() = default;
};

// ~~~~~~~~~~~~~~~~~~~~~~~MAIN MENU COMMANDS~~~~~~~~~~~~~~~~~~~~~~~
class FightCommand : public Command {
public:
    void execute() override;
};

class PrintPartyStatsCommand : public Command {
public:
    void execute(Party* party) override;
};

class QuitCommand : public Command {
public:
    void execute() override;
};

// ~~~~~~~~~~~~~~~~~~~~~~BATTLE MENU COMMANDS~~~~~~~~~~~~~~~~~~~~~~
class BackCommand : public Command {
public:
    void execute() override;
};