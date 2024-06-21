#ifndef C0B435BC_8D30_4BAB_85C4_F10B9085CA4B
#define C0B435BC_8D30_4BAB_85C4_F10B9085CA4B

#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <cassert>

namespace Tethis
{
    enum class TokenKind : uint8_t
    {
        #define TOKEN(x) x,
        #include "definitions/Tokens.def"
        NUM_TOKENS
    };
    
    std::string_view GetTokenText(TokenKind kind);

    class Token
    {
        TokenKind kind;

        unsigned at_line_start : 1;
        unsigned multiline_string : 1;
        unsigned custom_delimiter_length : 8;

        unsigned comment_length;
        std::string_view lexeme;

    public:
        // CONSTRUCTORS

        Token(TokenKind _kind) : kind(_kind) {}
        Token(TokenKind _kind, const char* _beg, std::size_t _len) : kind(_kind), lexeme(_beg, _len) {}
        Token(TokenKind _kind, const char* _beg, const char* _end) : kind(_kind), lexeme(_beg, std::distance(_beg, _end)) {}

        // OTHER PUBLIC STUFFS

        bool HasComment() const
        {
            return comment_length != 0;
        }

        bool Is(TokenKind _kind) const { return kind == _kind; }
        bool IsNot(TokenKind _kind) const { return kind != _kind; }
        bool IsAny(TokenKind _kind) const { return Is(_kind); }

        template <typename ...T>
        bool IsAny(TokenKind k1, TokenKind k2, T... k) const
        {
            return Is(k1) ? true : IsAny(k2, k...);
        }

        template <typename ...T>
        bool IsNot(TokenKind k1, T... k) const { return !IsAny(k1, k...); }

        bool IsPunctuation() const
        {
            switch (kind)
            {
                #define PUNCTUATOR(name, str) case TokenKind::name: return true,
                #include "definitions/Tokens.def"
                default: return false;
            }
        }

        bool IsMultilineString() const
        {
            return multiline_string;
        }

        bool IsAtLineStart() const { return at_line_start; }
        void SetAtLineStart(bool value) { at_line_start = value; }

        std::string_view GetLexeme() const { return lexeme; }
        void SetLexeme(std::string_view _lexeme) { lexeme = std::move(_lexeme); }
    };
}

#endif /* C0B435BC_8D30_4BAB_85C4_F10B9085CA4B */
