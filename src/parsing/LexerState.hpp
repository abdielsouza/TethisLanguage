#ifndef CA4BD756_DBB6_4874_A9E9_7D67C848A1B1
#define CA4BD756_DBB6_4874_A9E9_7D67C848A1B1

#pragma once

namespace Tethis
{
    class Lexer;

    class LexerState
    {
        friend class Lexer;
        
    public:
        explicit LexerState() = default;

        bool IsValid() const {}

        LexerState Advance(unsigned offset) const
        {
            return LexerState();
        }
    };
}

#endif /* CA4BD756_DBB6_4874_A9E9_7D67C848A1B1 */
