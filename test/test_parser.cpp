#include "Lexema.h"
#include "LexicalAnalysis.h"
#include "SyntacticAnalysis.h"
#include "Translator.h"
#include "Stack.h"
#include <string>

#include <gtest.h>

TEST(Parser, cant_write_expressions_without_opening_parentheses)
{
	string in = "12 + 10) / 5";
	LexicalAnalysis lex;
	SyntacticAnalysis sin;
	lex.Analysis(in);
	ASSERT_ANY_THROW(sin.Analysis(lex.getResult()));
}

TEST(Parser, cant_write_expressions_without_closing_parentheses)
{
	string in = "(14 + 10 * 13";
	LexicalAnalysis lex;
	SyntacticAnalysis sin;
	lex.Analysis(in);
	ASSERT_ANY_THROW(sin.Analysis(lex.getResult()));
}

TEST(Parser, cant_write_expressions_without_missing_operands)
{
	string in = "(123 + ) / 44";
	LexicalAnalysis lex;
	SyntacticAnalysis sin;
	Translator trans;
	lex.Analysis(in);
	sin.Analysis(lex.getResult());
	ASSERT_ANY_THROW(trans.Ñalculate(sin.getResult()));
}

TEST(Parser, the_expression_is_correctly_considered)
{
	string in = "((1235 + 1243) + (15 * 12) - (18 / 6) + 44)/4";
	LexicalAnalysis lex;
	SyntacticAnalysis sin;
	Translator trans;
	lex.Analysis(in);
	sin.Analysis(lex.getResult());
	trans.Ñalculate(sin.getResult());
	EXPECT_EQ(trans.getResult(), 674.75);
}
