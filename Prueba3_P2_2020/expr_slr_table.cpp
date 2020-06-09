#include <vector>
#include <functional>
#include "expr_slr_table.h"

Rule none;
static Rule rules[] = {
    /*0*/ {Symbol::input, {Symbol::stmt_list, Symbol::opt_eol, }},
    /*1*/ {Symbol::opt_eol, {Symbol::EOL, }},
    /*2*/ {Symbol::opt_eol, {Symbol::_epsilon, }},
    /*3*/ {Symbol::stmt_list, {Symbol::stmt_list, Symbol::EOL, Symbol::stmt, }},
    /*4*/ {Symbol::stmt_list, {Symbol::stmt, }},
    /*5*/ {Symbol::stmt, {Symbol::assign, }},
    /*6*/ {Symbol::stmt, {Symbol::PRINT, Symbol::expr, }},
    /*7*/ {Symbol::stmt, {Symbol::fun_decl, }},
    /*8*/ {Symbol::assign, {Symbol::IDENT, Symbol::EQUAL, Symbol::expr, }},
    /*9*/ {Symbol::fun_decl, {Symbol::IDENT, Symbol::arg_list, Symbol::EQUAL, Symbol::expr, }},
    /*10*/ {Symbol::arg_list, {Symbol::arg_list, Symbol::COMMA, Symbol::arg, }},
    /*11*/ {Symbol::arg_list, {Symbol::arg, }},
    /*12*/ {Symbol::arg, {Symbol::NUMBER, }},
    /*13*/ {Symbol::arg, {Symbol::IDENT, }},
    /*14*/ {Symbol::expr, {Symbol::expr, Symbol::PLUS, Symbol::term, }},
    /*15*/ {Symbol::expr, {Symbol::expr, Symbol::MINUS, Symbol::term, }},
    /*16*/ {Symbol::expr, {Symbol::term, }},
    /*17*/ {Symbol::term, {Symbol::term, Symbol::ASTERISK, Symbol::factor, }},
    /*18*/ {Symbol::term, {Symbol::term, Symbol::FORWARD_SLASH, Symbol::factor, }},
    /*19*/ {Symbol::term, {Symbol::factor, }},
    /*20*/ {Symbol::factor, {Symbol::IDENT, Symbol::opt_arg_list, }},
    /*21*/ {Symbol::factor, {Symbol::NUMBER, }},
    /*22*/ {Symbol::factor, {Symbol::OPEN_PARENTHESIS, Symbol::expr, Symbol::CLOSE_PARENTHESIS, }},
    /*23*/ {Symbol::opt_arg_list, {Symbol::arg_list, }},
    /*24*/ {Symbol::opt_arg_list, {Symbol::_epsilon, }},
};

static std::string rules_str[] = {
"input -> stmt_list opt_eol",
"opt_eol -> EOL",
"opt_eol -> %epsilon",
"stmt_list -> stmt_list EOL stmt",
"stmt_list -> stmt",
"stmt -> assign",
"stmt -> PRINT expr",
"stmt -> fun_decl",
"assign -> IDENT = expr",
"fun_decl -> IDENT arg_list = expr",
"arg_list -> arg_list , arg",
"arg_list -> arg",
"arg -> NUMBER",
"arg -> IDENT",
"expr -> expr + term",
"expr -> expr - term",
"expr -> term",
"term -> term * factor",
"term -> term / factor",
"term -> factor",
"factor -> IDENT opt_arg_list",
"factor -> NUMBER",
"factor -> ( expr )",
"opt_arg_list -> arg_list",
"opt_arg_list -> %epsilon",
};

inline PAction shift(int index)
{
    return PAction(PAction::Shift, index);
}

inline PAction reduce(int index)
{
    return PAction(PAction::Reduce, index);
}

PAction empty;
namespace lr
{
    PAction Action(int state, Symbol term)
    {
        switch(state)
        {
            case 0:
                switch(term)
                {
                    case Symbol::PRINT:
                        return shift(2);
                    case Symbol::IDENT:
                        return shift(1);
                }
                break;
            case 1:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(7);
                    case Symbol::EQUAL:
                        return shift(10);
                    case Symbol::NUMBER:
                        return shift(8);
                }
                break;
            case 2:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 3:
                switch(term)
                {
                    case Symbol::_epsilon:
                    case Symbol::EOL:
                        return reduce(5);
                }
                break;
            case 4:
                switch(term)
                {
                    case Symbol::EOL:
                        return shift(20);
                    case Symbol::_epsilon:
                        return shift(18);
                }
                break;
            case 5:
                switch(term)
                {
                    case Symbol::_epsilon:
                    case Symbol::EOL:
                        return reduce(7);
                }
                break;
            case 6:
                switch(term)
                {
                    case Symbol::EOL:
                    case Symbol::_epsilon:
                        return reduce(4);
                }
                break;
            case 7:
                switch(term)
                {
                    case Symbol::COMMA:
                    case Symbol::_epsilon:
                    case Symbol::EQUAL:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::MINUS:
                    case Symbol::EOL:
                    case Symbol::PLUS:
                    case Symbol::ASTERISK:
                    case Symbol::FORWARD_SLASH:
                        return reduce(13);
                }
                break;
            case 8:
                switch(term)
                {
                    case Symbol::COMMA:
                    case Symbol::_epsilon:
                    case Symbol::EQUAL:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::MINUS:
                    case Symbol::EOL:
                    case Symbol::PLUS:
                    case Symbol::ASTERISK:
                    case Symbol::FORWARD_SLASH:
                        return reduce(12);
                }
                break;
            case 9:
                switch(term)
                {
                    case Symbol::FORWARD_SLASH:
                    case Symbol::ASTERISK:
                    case Symbol::PLUS:
                    case Symbol::EOL:
                    case Symbol::MINUS:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::EQUAL:
                    case Symbol::_epsilon:
                    case Symbol::COMMA:
                        return reduce(11);
                }
                break;
            case 10:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 11:
                switch(term)
                {
                    case Symbol::EQUAL:
                        return shift(23);
                    case Symbol::COMMA:
                        return shift(22);
                }
                break;
            case 12:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 13:
                switch(term)
                {
                    case Symbol::FORWARD_SLASH:
                    case Symbol::ASTERISK:
                    case Symbol::PLUS:
                    case Symbol::EOL:
                    case Symbol::MINUS:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::_epsilon:
                        return reduce(21);
                }
                break;
            case 14:
                switch(term)
                {
                    case Symbol::_epsilon:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::MINUS:
                    case Symbol::EOL:
                    case Symbol::PLUS:
                    case Symbol::ASTERISK:
                    case Symbol::FORWARD_SLASH:
                        return reduce(19);
                }
                break;
            case 15:
                switch(term)
                {
                    case Symbol::PLUS:
                        return shift(26);
                    case Symbol::MINUS:
                        return shift(25);
                    case Symbol::_epsilon:
                    case Symbol::EOL:
                        return reduce(6);
                }
                break;
            case 16:
                switch(term)
                {
                    case Symbol::_epsilon:
                        return shift(27);
                    case Symbol::IDENT:
                        return shift(7);
                    case Symbol::NUMBER:
                        return shift(8);
                }
                break;
            case 17:
                switch(term)
                {
                    case Symbol::ASTERISK:
                        return shift(31);
                    case Symbol::FORWARD_SLASH:
                        return shift(30);
                    case Symbol::EOL:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::_epsilon:
                    case Symbol::PLUS:
                    case Symbol::MINUS:
                        return reduce(16);
                }
                break;
            case 18:
                switch(term)
                {
                    case Symbol::Eof:
                        return reduce(2);
                }
                break;
            case 19:
                switch(term)
                {
                    case Symbol::Eof:
                        return reduce(0);
                }
                break;
            case 20:
                switch(term)
                {
                    case Symbol::PRINT:
                        return shift(2);
                    case Symbol::IDENT:
                        return shift(1);
                    case Symbol::Eof:
                        return reduce(1);
                }
                break;
            case 21:
                switch(term)
                {
                    case Symbol::PLUS:
                        return shift(26);
                    case Symbol::MINUS:
                        return shift(25);
                    case Symbol::EOL:
                    case Symbol::_epsilon:
                        return reduce(8);
                }
                break;
            case 22:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(7);
                    case Symbol::NUMBER:
                        return shift(8);
                }
                break;
            case 23:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 24:
                switch(term)
                {
                    case Symbol::PLUS:
                        return shift(26);
                    case Symbol::MINUS:
                        return shift(25);
                    case Symbol::CLOSE_PARENTHESIS:
                        return shift(35);
                }
                break;
            case 25:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 26:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 27:
                switch(term)
                {
                    case Symbol::_epsilon:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::MINUS:
                    case Symbol::EOL:
                    case Symbol::PLUS:
                    case Symbol::ASTERISK:
                    case Symbol::FORWARD_SLASH:
                        return reduce(24);
                }
                break;
            case 28:
                switch(term)
                {
                    case Symbol::FORWARD_SLASH:
                    case Symbol::ASTERISK:
                    case Symbol::PLUS:
                    case Symbol::EOL:
                    case Symbol::MINUS:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::_epsilon:
                        return reduce(20);
                }
                break;
            case 29:
                switch(term)
                {
                    case Symbol::COMMA:
                        return shift(22);
                    case Symbol::_epsilon:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::MINUS:
                    case Symbol::EOL:
                    case Symbol::PLUS:
                    case Symbol::ASTERISK:
                    case Symbol::FORWARD_SLASH:
                        return reduce(23);
                }
                break;
            case 30:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 31:
                switch(term)
                {
                    case Symbol::IDENT:
                        return shift(16);
                    case Symbol::NUMBER:
                        return shift(13);
                    case Symbol::OPEN_PARENTHESIS:
                        return shift(12);
                }
                break;
            case 32:
                switch(term)
                {
                    case Symbol::EOL:
                    case Symbol::_epsilon:
                        return reduce(3);
                }
                break;
            case 33:
                switch(term)
                {
                    case Symbol::FORWARD_SLASH:
                    case Symbol::ASTERISK:
                    case Symbol::PLUS:
                    case Symbol::EOL:
                    case Symbol::MINUS:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::EQUAL:
                    case Symbol::_epsilon:
                    case Symbol::COMMA:
                        return reduce(10);
                }
                break;
            case 34:
                switch(term)
                {
                    case Symbol::PLUS:
                        return shift(26);
                    case Symbol::MINUS:
                        return shift(25);
                    case Symbol::EOL:
                    case Symbol::_epsilon:
                        return reduce(9);
                }
                break;
            case 35:
                switch(term)
                {
                    case Symbol::FORWARD_SLASH:
                    case Symbol::ASTERISK:
                    case Symbol::PLUS:
                    case Symbol::EOL:
                    case Symbol::MINUS:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::_epsilon:
                        return reduce(22);
                }
                break;
            case 36:
                switch(term)
                {
                    case Symbol::ASTERISK:
                        return shift(31);
                    case Symbol::FORWARD_SLASH:
                        return shift(30);
                    case Symbol::EOL:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::_epsilon:
                    case Symbol::PLUS:
                    case Symbol::MINUS:
                        return reduce(15);
                }
                break;
            case 37:
                switch(term)
                {
                    case Symbol::ASTERISK:
                        return shift(31);
                    case Symbol::FORWARD_SLASH:
                        return shift(30);
                    case Symbol::EOL:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::_epsilon:
                    case Symbol::PLUS:
                    case Symbol::MINUS:
                        return reduce(14);
                }
                break;
            case 38:
                switch(term)
                {
                    case Symbol::_epsilon:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::MINUS:
                    case Symbol::EOL:
                    case Symbol::PLUS:
                    case Symbol::ASTERISK:
                    case Symbol::FORWARD_SLASH:
                        return reduce(18);
                }
                break;
            case 39:
                switch(term)
                {
                    case Symbol::_epsilon:
                    case Symbol::CLOSE_PARENTHESIS:
                    case Symbol::MINUS:
                    case Symbol::EOL:
                    case Symbol::PLUS:
                    case Symbol::ASTERISK:
                    case Symbol::FORWARD_SLASH:
                        return reduce(17);
                }
                break;
        }

        return empty;
    }

    int Goto(int state, Symbol non_term)
    {
        switch(state)
        {
            case 0:
                switch(non_term)

                {
                    case Symbol::stmt_list:
                        return 4;
                    case Symbol::stmt:
                        return 6;
                    case Symbol::assign:
                        return 3;
                    case Symbol::fun_decl:
                        return 5;
                }
                break;
            case 1:
                switch(non_term)

                {
                    case Symbol::arg_list:
                        return 11;
                    case Symbol::arg:
                        return 9;
                }
                break;
            case 2:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 15;
                    case Symbol::term:
                        return 17;
                    case Symbol::factor:
                        return 14;
                }
                break;
            case 4:
                switch(non_term)

                {
                    case Symbol::opt_eol:
                        return 19;
                }
                break;
            case 10:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 21;
                    case Symbol::term:
                        return 17;
                    case Symbol::factor:
                        return 14;
                }
                break;
            case 12:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 24;
                    case Symbol::term:
                        return 17;
                    case Symbol::factor:
                        return 14;
                }
                break;
            case 16:
                switch(non_term)

                {
                    case Symbol::arg_list:
                        return 29;
                    case Symbol::arg:
                        return 9;
                    case Symbol::opt_arg_list:
                        return 28;
                }
                break;
            case 20:
                switch(non_term)

                {
                    case Symbol::stmt:
                        return 32;
                    case Symbol::assign:
                        return 3;
                    case Symbol::fun_decl:
                        return 5;
                }
                break;
            case 22:
                switch(non_term)

                {
                    case Symbol::arg:
                        return 33;
                }
                break;
            case 23:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 34;
                    case Symbol::term:
                        return 17;
                    case Symbol::factor:
                        return 14;
                }
                break;
            case 25:
                switch(non_term)

                {
                    case Symbol::term:
                        return 36;
                    case Symbol::factor:
                        return 14;
                }
                break;
            case 26:
                switch(non_term)

                {
                    case Symbol::term:
                        return 37;
                    case Symbol::factor:
                        return 14;
                }
                break;
            case 30:
                switch(non_term)

                {
                    case Symbol::factor:
                        return 38;
                }
                break;
            case 31:
                switch(non_term)

                {
                    case Symbol::factor:
                        return 39;
                }
                break;
        }

        return -1;
    }

    const Rule& rule(int index)
    {
        return rules[index];
    }

    std::string ruleString(int index)
    {
        return rules_str[index];
    }
}
