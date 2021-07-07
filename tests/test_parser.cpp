#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "spl_lexer.h"
#include "spl_parser.h"

std::ostream& operator <<(std::ostream& out, Symbol symb)
{
    out << SplLexer::tokenToString(symb);
    return out;
}

const char *test1 = "main() {\n"
                    "    print((10+7)*5);\n"
                    "}\n";

const char *test2 = "add(a, b) {\n"
                    "    result = a + b;\n"
                    "}\n\n"
                    "main(a, b) {\n"
                    "    x = add(a+10, b+20);\n"
                    "}\n";

const char *test3 = "add(a, b, c) {\n"
                    "    result = a + b;\n"
                    "    print ((c + b) * (c - b));\n"
                    "}\n\n"
                    "printer(a, b, c) {\n"
                    "    print(a + 10);\n"
                    "    print(b + 20);\n"
                    "    print(c + 30);\n"
                    "}\n\n"
                    "main(a, b) {\n"
                    "    x = add(a+10, b+20);\n"
                    "    printer(a, b, x);\n"
                    "}\n";

bool throwOnError() {
    std::istringstream in("x y z");
    SplLexer l(in);
    std::ostringstream out;
    SplParser p(l); 

    bool throwException = false;
    try {
        p.parse();
    } catch (...) {
        throwException = true;
    }
    return throwException;
}

TEST_CASE("One function") {
    REQUIRE(throwOnError());

    std::istringstream in(test1);
    SplLexer l(in);
    SplParser p(l);

    bool parseSuccess = false;
    try {
        CHECK(p.parse());
        parseSuccess = true;
    } catch (std::string& err) {
        std::cout << err << '\n';
        parseSuccess = false;
    }
    CHECK(l.getNextToken() == Symbol::Eof);
    CHECK(parseSuccess);
}

TEST_CASE("Two functions") {
    REQUIRE(throwOnError());

    std::istringstream in(test2);
    SplLexer l(in);
    SplParser p(l);

    bool parseSuccess = false;
    try {
        CHECK(p.parse());
        parseSuccess = true;
    } catch (std::string& err) {
        std::cout << err << '\n';
        parseSuccess = false;
    }
    CHECK(l.getNextToken() == Symbol::Eof);
    CHECK(parseSuccess);
}

TEST_CASE("Three functions") {
    REQUIRE(throwOnError());

    std::istringstream in(test2);
    SplLexer l(in);
    SplParser p(l);

    bool parseSuccess = false;
    try {
        CHECK(p.parse());
        parseSuccess = true;
    } catch (std::string& err) {
        std::cout << err << '\n';
        parseSuccess = false;
    }
    CHECK(l.getNextToken() == Symbol::Eof);
    CHECK(parseSuccess);
}