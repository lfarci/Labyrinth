#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Represents a command of the game.
 */
class ExitCommand : public Command {

public:

    ExitCommand(labyrinth::view::View & view, Game &game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() const override {
        exit(0);
    }

};

}}

#endif
