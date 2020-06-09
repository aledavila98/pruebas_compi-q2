#include "spl_lexer.h"
#include "spl_symbols.h"

enum class State {
    Start_q0,
    Arithmetic_q0,
    Decimal_q0,
    Decimal_q1,
    Delimiters_q0,
    Ident_q0,
    Ident_q1,
    Punctuation_q0,
};

Symbol SplLexer::getNextToken()
{
    text = "";
        State state = State::Start_q0;
    int ch = getNextChar();

    while (true) {
        switch (state) {
            // Start
            case State::Start_q0:
                if ((ch == '\n') || (ch == ' ') || (ch == '\t')) {
                    state = State::Start_q0;
                    ch = getNextChar();
                } else if (ch == EOF) {
                    text += ch;
                    return Symbol::Eof;
                } else {
                    // Trying next automaton 'Arithmetic'
                    state = State::Arithmetic_q0;
                }
                break;
            // Arithmetic
            case State::Arithmetic_q0:
                if (ch == '*') {
                    text += ch;
                    return Symbol::ASTERISK;
                } else if (ch == '+') {
                    text += ch;
                    return Symbol::PLUS;
                } else if (ch == '=') {
                    text += ch;
                    return Symbol::EQUAL;
                } else {
                    // Trying next automaton 'Decimal'
                    state = State::Decimal_q0;
                }
                break;
            // Decimal
            case State::Decimal_q0:
                if ((ch >= '1') && (ch <= '9')) {
                    text += ch;
                    state = State::Decimal_q1;
                    ch = getNextChar();
                } else {
                    // Trying next automaton 'Delimiters'
                    state = State::Delimiters_q0;
                }
                break;
            case State::Decimal_q1:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::Decimal_q1;
                    ch = getNextChar();
                } else {
                    ungetChar(ch);
                    return Symbol::NUMBER;
                }
                break;
            // Delimiters
            case State::Delimiters_q0:
                if (ch == '{') {
                    text += ch;
                    return Symbol::OPEN_BRACE;
                } else if (ch == ')') {
                    text += ch;
                    return Symbol::CLOSE_PARENTHESIS;
                } else if (ch == '}') {
                    text += ch;
                    return Symbol::CLOSE_BRACE;
                } else if (ch == '(') {
                    text += ch;
                    return Symbol::OPEN_PARENTHESIS;
                } else {
                    // Trying next automaton 'Ident'
                    state = State::Ident_q0;
                }
                break;
            // Ident
            case State::Ident_q0:
                if ((ch == '_') || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'z'))) {
                    text += ch;
                    state = State::Ident_q1;
                    ch = getNextChar();
                } else {
                    // Trying next automaton 'Punctuation'
                    state = State::Punctuation_q0;
                }
                break;
            case State::Ident_q1:
                if (((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || (ch == '_')) {
                    text += ch;
                    state = State::Ident_q1;
                    ch = getNextChar();
                } else {
                    ungetChar(ch);
                    return Symbol::IDENT;
                }
                break;
            // Punctuation
            case State::Punctuation_q0:
                if (ch == ',') {
                    text += ch;
                    return Symbol::COMMA;
                } else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::Start_q0;
                }
                break;
        }
    }

}

const char *SplLexer::tokenToString(Symbol sy)
{
        switch (sy) {
        case Symbol::OPEN_PARENTHESIS: return "OPEN_PARENTHESIS";
        case Symbol::IDENT: return "IDENT";
        case Symbol::CLOSE_BRACE: return "CLOSE_BRACE";
        case Symbol::Eof: return "Eof";
        case Symbol::CLOSE_PARENTHESIS: return "CLOSE_PARENTHESIS";
        case Symbol::PLUS: return "PLUS";
        case Symbol::COMMA: return "COMMA";
        case Symbol::ASTERISK: return "ASTERISK";
        case Symbol::EQUAL: return "EQUAL";
        case Symbol::NUMBER: return "NUMBER";
        case Symbol::OPEN_BRACE: return "OPEN_BRACE";
        default: return "Unknown";
    }

}