#ifndef _PARSER_H_
#define _PARSER_H_

#include "spl_lexer.h"

class SplParser {
    public:
        SplParser(SplLexer &lexer):lexer(lexer) {}

        bool parse();

        void SyntaxError(Symbol tk){
            std::cerr<<"Unexpected token found: " << lexer.tokenToString(tk) << "\n";
        }

    private:
        std::vector<Symbol> stack;
        Symbol firstElement;
        SplLexer &lexer;
        Symbol currtoken;
};

#endif
