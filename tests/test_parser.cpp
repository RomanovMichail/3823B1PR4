
#include<stdexcept>
#include <gtest.h>
#include "C:\Michail_Romanov\3823B1PR4\lib_parser\Parser.h"
#include "C:\Michail_Romanov\3823B1PR4\lib_stack\Stack.h"


TEST(ParserTest, Check_Exp) {
    EXPECT_TRUE(correct_expression("((x+y*5)*[x/6-y])+{((8+19)+|14x+56|)*[18y-65]}"));
}
TEST(ParserTest, ValidExp) {
    EXPECT_TRUE(correct_expression("()"));
    EXPECT_TRUE(correct_expression("([])"));
    EXPECT_TRUE(correct_expression("{[()]}"));
    EXPECT_TRUE(correct_expression("|()|"));
    EXPECT_TRUE(correct_expression("(|[{}]|)"));
}
TEST(ParserTest, InvalidBrackets) {
    EXPECT_THROW(correct_expression("(]"), std::logic_error);
    EXPECT_THROW(correct_expression("({[)]}"), std::logic_error);
    EXPECT_THROW(correct_expression("("), std::logic_error);
    EXPECT_THROW(correct_expression(")"), std::logic_error);
}