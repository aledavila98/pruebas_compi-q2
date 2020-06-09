#include "expr_lexer.h"

std::string Lexer::tokenToString(Symbol tk)
{
    switch (tk)
    {
        case Symbol::Eof: return "Eof";
        case Symbol::EOL : return "Eol";
        case Symbol::PRINT: return "KwPrint";
        case Symbol::IDENT: return "Ident";
        case Symbol::EQUAL: return "OpAssign";
        case Symbol::COMMA: return "Comma";
        case Symbol::NUMBER: return "Number";
        case Symbol::PLUS: return "OpAdd";
        case Symbol::MINUS: return "OpSub";
        case Symbol::ASTERISK: return "OpMul";
        case Symbol::FORWARD_SLASH: return "OpDiv";
        case Symbol::OPEN_PARENTHESIS: return "OpenPar";
        case Symbol::CLOSE_PARENTHESIS: return "ClosePar";
        default:
            return "Unknown:" + std::to_string(static_cast<unsigned>(tk));
    }
}