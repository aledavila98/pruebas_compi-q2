#include "spl_parser.h"

bool SplParser::parse() {
    stack.push_back(Symbol::input);
    currtoken = lexer.getNextToken();

    while (stack.size() > 0) {
        if (isTerminal(firstElement)) {
            if (firstElement == Symbol::Epsilon) {
                stack.pop_back();
            } else if (firstElement == currtoken) {
                stack.pop_back();
                currtoken = lexer.getNextToken();
            } else {
                throw std::exception();
                return true;
            }
        } else {
            const Rule& prod = getEntry(firstElement, currtoken);
            if (prod.isEmpty()) {
                throw std::exception();
                return true;
            }
            stack.pop_back();
            for (int i = prod.rhs.size() - 1; i >= 0; i--)
            {
                stack.push_back(prod.rhs.at(i));
            }
        }

        return true;
    }
}