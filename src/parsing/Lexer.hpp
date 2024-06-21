#ifndef D1BFD6D6_7B42_47B9_A65D_1859581903C7
#define D1BFD6D6_7B42_47B9_A65D_1859581903C7

#pragma once

#include "LexerState.hpp"
#include "Token.hpp"
#include <string>

namespace Tethis
{
    class Lexer
    {
        const char* beg = nullptr;

    public:
        explicit Lexer(const char* _beg) noexcept : beg(_beg) {}

        Token Next() noexcept;

    private:
        // PRIVATE METHODS
        char Peek() const noexcept { return *beg; }
        char Get() noexcept { return *beg++; }

        Token GetAtom(TokenKind kind) noexcept { return Token(kind, beg, 1); }
    };
}

#endif /* D1BFD6D6_7B42_47B9_A65D_1859581903C7 */
