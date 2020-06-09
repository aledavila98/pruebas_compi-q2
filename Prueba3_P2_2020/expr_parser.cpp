#include <stack>
#include <tuple>
#include "expr_parser.h"

bool Parser::parse() {
    bool is_accepted = false;
    unsigned curr_state;
    Symbol curr_token = lexer.getNextToken();
    std::stack<std::tuple<Symbol, unsigned>> stk;

    stk.push(std::make_tuple(Symbol::input, 0));

    while(!is_accepted) {
        std::tie(std::ignore, curr_state) = stk.top();
        const PAction& pact =  lr::Action(curr_state, curr_token);  
    }

}