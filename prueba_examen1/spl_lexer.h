#ifndef _LEXER_H
#define _LEXER_H

#include <iostream>
#include <string>
#include <fstream>
#include "spl_symbols.h"

class SplLexer {
    public:
        SplLexer(std::istream& input): input(input) {}

        std::string getText() { return text; }
        int getNextChar() { return input.get(); }
        void ungetChar(int ch) { input.unget(); }

        void reportError(int ch) {
            std::cerr << "Error: Invalid character: '" << ch << "'\n";
        }
        
        Symbol getNextToken();
        static const char *tokenToString(Symbol sy);
    private:
        std::string text;
        std::istream& input;
};

#endif