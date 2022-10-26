#include "token.hpp"

std::vector<tk_variant_t>& Token_t::get_data() { return this->m_data; }
void Token_t::set_type(TokenType_t t) { this->m_type = t; }
TokenType_t& Token_t::get_type() { return this->m_type; }

void Token_t::print()
{
    /* Loop through `this->m_data` and print each type along with its value
     * to the standard output */
    std::cout << "Token type: " << this->m_type << "\n";
    for (auto&& x : this->m_data) {
        size_t index = x.index();

        switch (index) {
            case LONG_TYPE_ID:
                std::cout << "long data: " << std::get<long>(x) << "\n";
                break;
            case DOUBLE_TYPE_ID:
                std::cout << "double data: " << std::get<double>(x) << "\n";
                break;
            case STRING_TYPE_ID:
                std::cout << "string data: " << std::get<std::string>(x) << \
                    "\n";
                break;
            case BOOL_TYPE_ID:
                std::cout << "bool data: " << std::get<bool>(x) << "\n";
                break;
            case VOID_PTR_TYPE_ID:
                std::cout << "void* pointer: 0x" << \
                    (unsigned long) std::get<void*>(x) << std::dec << "\n";
                break;
            default:
                std::cout << "Unknown type information found.\n";
                break;
        }
    }
    // Flush std::cout buffer
    std::cout << "-------------------------" << std::endl;
}

Token_t::Token_t(TokenType_t t)
{
    this->m_type = t;
}
