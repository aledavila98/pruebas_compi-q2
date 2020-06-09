#ifndef _LEXER_H
#define _LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "expr_slr_table.h"

#define _Print {Symbol::PRINT, "Print" }
#define _Eol {Symbol::EOL, "\\n" }
#define _OpenPar {Symbol::OPEN_PARENTHESIS, "(" }
#define _ClosePar {Symbol::CLOSE_PARENTHESIS, ")" }
#define _Comma {Symbol::COMMA, "," }
#define _OpAssign {Symbol::EQUAL, "=" }
#define _OpAdd {Symbol::PLUS, "+" }
#define _OpSub {Symbol::MINUS, "-" }
#define _OpMul {Symbol::ASTERISK, "*" }
#define _OpDiv {Symbol::FORWARD_SLASH, "/" }
#define _Number(txt) {Symbol::NUMBER, txt }
#define _Ident(txt) {Symbol::IDENT, txt }
#define _Eof {Symbol::Eof, "<Eof>" }

struct TokenInfo {
    Symbol token_id;
    std::string token_text;
};

class Lexer {
public:
	Lexer(const std::vector<TokenInfo>& tklst): tklist(tklst) {
        it = tklist.begin();
    }

    int getLineNo() { return 1; }

    Symbol getNextToken()
    {
        if (it == tklist.end())
        {
            return Symbol::Eof;
        }

        Symbol tk = it->token_id;
        text = it->token_text;
        it++;
        
        return tk;
    }
    
    bool hasTokens() { return it != tklist.end(); }
    std::string getText() { return text; }
    static std::string tokenToString(Symbol tk);

private:
    std::string text;
    std::vector<TokenInfo> tklist;
    std::vector<TokenInfo>::iterator it;
};
#endif
