#include "Lexer.hpp"
#include <cstdlib>
#include <regex>

namespace Tethis
{
    Token Lexer::Next() noexcept
    {
        while (isspace(this->Peek())) this->Get();

        
    }
}