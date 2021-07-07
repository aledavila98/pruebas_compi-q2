cmake_minimum_required (VERSION 3.0)
project (test_parser)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FA_DIR "${PROJECT_SOURCE_DIR}/../fa")
file(GLOB JFF_FILES "${FA_DIR}/*.jff")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)

# Run ECC to generate the LL1 table
add_custom_command (
  OUTPUT spl_ll1_table.cpp spl_symbols.h
  COMMAND ecc -g ${PROJECT_SOURCE_DIR}/../spl_grammar_ll1.txt --src spl_ll1_table.cpp --hdr spl_symbols.h --alg ll1
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/../spl_grammar_ll1.txt
  )

# Run FA2LEXER to generate the lexer
add_custom_command (
  OUTPUT spl_lexer.cpp
  COMMAND fa2lexer --src spl_lexer.cpp --tpl ${FA_DIR}/spl_lexer.fa2l
  MAIN_DEPENDENCY ${FA_DIR}/spl_lexer.fa2l
  DEPENDS ${JFF_FILES}
  )
  
add_executable(${PROJECT_NAME}  spl_ll1_table.cpp
                                spl_lexer.cpp
                                ${PROJECT_SOURCE_DIR}/../spl_parser.cpp
                                test_parser.cpp)
