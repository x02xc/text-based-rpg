#include "command.h"

void PrintPartyStatsCommand::execute(Party* party) {
    for (size_t i = 0; i < party->getPartySize(); i++) {
        party[i].printInfo();
    }
}