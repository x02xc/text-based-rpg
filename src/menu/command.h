#pragma once

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class BackCommand : public Command {
public:
    void execute() override;
};