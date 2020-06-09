#ifndef __SPL_SYMBOLS_H__
#define __SPL_SYMBOLS_H__

#include <vector>

enum class Symbol: unsigned {
    input = 0,
    opt_func_list = 1,
    func_list = 2,
    func_decl = 3,
    func_listPrime = 4,
    opt_arg_list = 5,
    block = 6,
    arg_list = 7,
    arg_listPrime = 8,
    stmt_list = 9,
    stmt = 10,
    stmt_listPrime = 11,
    stmtPrime = 12,
    expr_list = 13,
    expr = 14,
    expr_listPrime = 15,
    term = 16,
    exprPrime = 17,
    factor = 18,
    termPrime = 19,
    factorPrime = 20,
    Eof = 21,
    IDENT = 22,
    OPEN_PARENTHESIS = 23,
    CLOSE_PARENTHESIS = 24,
    COMMA = 25,
    OPEN_BRACE = 26,
    CLOSE_BRACE = 27,
    EQUAL = 28,
    PLUS = 29,
    ASTERISK = 30,
    NUMBER = 31,
    Epsilon = 32
};

struct Rule {
    Rule() = default;
    Rule(const Rule&) = delete;

    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

using RuleRef = std::reference_wrapper<Rule>;

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 21) return index;
    else return (index - 21);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 21;
}

const Rule& getEntry(Symbol non_term, Symbol term);

#endif
