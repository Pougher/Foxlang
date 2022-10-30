#include "error_messages.hpp"

const std::string ErrorMessage::IDENTIFIER_ALREADY_DECLARED_ERROR(
    const std::string& name)
{
    return "Identifier already declared: '" + name + "'";
}

const std::string ErrorMessage::NAMESPACE_IDENT_NOT_FOUND(
    const std::string& name)
{
    return "Namespace identifier not found: '" + name + "'";
}

const std::string ErrorMessage::IDENT_NOT_IN_NAMESPACE(const std::string& name,
    const std::string& child_name)
{
    return "Namespace identifier '" + child_name + "' not found in namespace "
        "'" + name + "'";
}

const std::string ErrorMessage::IDENT_NOT_DEFINED(const std::string& name)
{
    return "Identifier not defined: '" + name + "'";
}

const std::string ErrorMessage::ONLY_IN_EXTERN_BLOCKS(const std::string& name)
{
    return name + " keyword may only be used in extern blocks";
}

const std::string ErrorMessage::STRAY_WITHOUT(char brack)
{
    std::string complete = "Stray '";
    complete += brack;
    complete += "' without matching '";
    switch (brack) {
        case '}': {
            complete += "{";
            break;
        }
        case ']': {
            complete += "[";
            break;
        }
        case ')': {
            complete += "(";
            break;
        }
    }
    complete += "'";
    return complete;
}

const std::string ErrorMessage::UNMATCHED_IN_FILE(const std::string& brace)
{
    if (brace == "") {
        return "Unmatched braces in file";
    }
    return "Unmatched " + brace + " braces in file";
}
