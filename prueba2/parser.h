#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H

#include <iosfwd>
#include "lexer.h"

class Parser {
public:
	Parser(Lexer &lexer): lexer (lexer) { }
	void parse();
	void input();
	void opt_eol();
	void stmt_list();
	void stmt_list_p();
	void stmt();
	void assign();
	void func_decl();
	void opt_arg_list();
	void arg_list();
	void arg();
	void expr();
	void term();
	void factor();
	void print();
private:
	Token currToken;
	Lexer &lexer;
};

#endif
