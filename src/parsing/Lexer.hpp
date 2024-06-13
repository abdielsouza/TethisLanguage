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
        using State = LexerState;

        const char *buffer_start;
        const char *buffer_end;
        const char *artificial_eof = nullptr;
        const char *code_completion_ptr = nullptr;
        const char *content_start;
        const char *current_ptr;

        std::string line_to_read;
        unsigned int position;

        Token next_token;

        Lexer(const Lexer&) = delete;
        void operator=(const Lexer&) = delete;

    public:
        bool IsCodeCompletion() const { return code_completion_ptr != nullptr; }

        void Lex(Token& token)
        {
            token = next_token;

            if (token.IsNot(TokenKind::eof)) LexImpl();
        }

        void LexImpl();
    };
}

#endif /* D1BFD6D6_7B42_47B9_A65D_1859581903C7 */
