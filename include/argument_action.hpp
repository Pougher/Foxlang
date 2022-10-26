#pragma once

#include <string>

/* class to be overidden and have functionality added on top of it.
 * `requirements()` must return true if the number of arguments
 * remaining is equal to the number of arguments required by the action.
 * `parse()` provides functionality for the argument.
 * `docstring()` returns the docstring for the argument. */
class ArgumentAction_t {
public:
    /* override this */
    virtual void parse(int argc, char** argv) = 0;
    /* override this */
    virtual bool requirements(int argc) = 0;
    /* override this */
    virtual std::string docstring() = 0;
    /* do not override */
    virtual ~ArgumentAction_t() {}
};
