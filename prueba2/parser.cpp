#include "parser.h"

void Parser::parse() {

}

void Parser::input()  {
    if (currToken == Token::Eof) {
        currToken = lexer.getNextToken();
        opt_eol();
    } else {
        currToken = lexer.getNextToken();
        stmt_list();
    }
}

void Parser::opt_eol() {
    if (currToken == Token::Eol) {
        currToken = lexer.getNextToken(); 
    } else {
        //
    }
}

void Parser::stmt_list() {
    if (currToken == Token::Eol) {
        currToken = lexer.getNextToken();
        stmt();
        stmt_list_p();
    } else {
        //
    }
}

void Parser::stmt() {
    if (currToken == Token::OpAssign) {
        currToken = lexer.getNextToken();
        assign();
    } else if (currToken == Token::KwPrint) {
        currToken = lexer.getNextToken();
        print();
    } else {
        func_decl();
    }
}

void Parser::assign() {
    if (currToken == Token::Ident) {
        currToken = lexer.getNextToken();
        if (currToken == Token::OpAssign) {
            currToken = lexer.getNextToken();
            expr();
        }
    } else {

    }
}

void Parser::print() {
    
}

void Parser::stmt_list_p() {
    if (currToken == Token::Eol) {
        currToken = lexer.getNextToken();
        stmt();
        stmt_list_p();
    } else {

    }
}

void Parser::func_decl() {

}

void Parser::expr() {
    
}