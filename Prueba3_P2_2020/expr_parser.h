#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H

#include "expr_lexer.h"

class Parser {
    public:
        Parser(Lexer &lexer):lexer(lexer) {}

        bool parse();

        void SyntaxError(Symbol tk){
            std::cerr<<"Unexpected token found: " << lexer.tokenToString(tk) << "\n";
        }

    private:
        std::vector<Symbol> stack;
        Symbol firstElement;
        Lexer &lexer;
        Symbol currtoken;
};

#endif