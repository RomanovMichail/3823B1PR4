
#include<stdexcept>
#include <gtest.h>
#include "E:\PROJECTS\3823B1PR4\lib_parser\Parser.h"
#include "E:\PROJECTS\3823B1PR4\lib_stack\Stack.h"


TEST(TestTParserLib, Check_Exp) {
    EXPECT_TRUE(correct_expression("((x+y*5)*[x/6-y])+{((8+19)+|14x+56|)*[18y-65]}"));
}
TEST(ParserTest, ValidExp) {
    EXPECT_TRUE(correct_expression("()"));
    EXPECT_TRUE(correct_expression("([])"));
    EXPECT_TRUE(correct_expression("{[()]}"));
    EXPECT_TRUE(correct_expression("|(text)|"));
    EXPECT_TRUE(correct_expression("(|[{}]|)"));
}
TEST(ParserTest, InvalidBrackets) {
    EXPECT_THROW(correct_expression("(]"), std::logic_error);
    EXPECT_THROW(correct_expression("({[)]}"), std::logic_error);
    EXPECT_THROW(correct_expression("("), std::logic_error);
    EXPECT_THROW(correct_expression(")"), std::logic_error);
}//((x+y*5)*[x/6-y])+{((8+19)+|14x+56|)*[18y-65]}