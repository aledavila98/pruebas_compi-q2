#ifndef __EXPR_SLR_TABLE_H__
#define __EXPR_SLR_TABLE_H__

#include <vector>

enum class Symbol: unsigned {
    input = 0,
    stmt_list = 1,
    opt_eol = 2,
    stmt = 3,
    assign = 4,
    expr = 5,
    fun_decl = 6,
    arg_list = 7,
    arg = 8,
    term = 9,
    factor = 10,
    opt_arg_list = 11,
    Eof = 12,
    EOL = 13,
    _epsilon = 14,
    PRINT = 15,
    IDENT = 16,
    EQUAL = 17,
    COMMA = 18,
    NUMBER = 19,
    PLUS = 20,
    MINUS = 21,
    ASTERISK = 22,
    FORWARD_SLASH = 23,
    OPEN_PARENTHESIS = 24,
    CLOSE_PARENTHESIS = 25,
    Epsilon = 26
};

struct Rule {
    Rule() = default;
    Rule(const Rule&) = delete;

    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

using RuleRef = std::reference_wrapper<Rule>;

class PAction {
public:
    enum { Shift, Reduce, Empty };

    PAction(): action(Empty), value(0) {}
    PAction(unsigned action, int value)
        : action(action), value(value) {}
    bool isShift() const { return action == Shift; }
    bool isReduce() const { return action == Reduce; }
    bool isEmpty() const { return action >= Empty; }
    int getValue() const { return value; }
private:
    unsigned action;
    int value;
};

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 12) return index;
    else return (index - 12);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 12;
}

namespace lr
{
    const Rule& rule(int index);
    PAction Action(int state, Symbol term);
    int Goto(int state, Symbol non_term);
    std::string ruleString(int index);
}

#endif
