//The override keyword serves two purposes:
//It shows the reader of the code that "this is a virtual method, that is overriding a virtual method of the base class."
//The compiler also knows that it's an override, so it can "check" 
//that you are not altering/adding new methods that you think are overrides.
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <any>
#include <cassert>
#include <memory>
#include <type_traits>
#include "Expr.h"


class AstPrinter: public ExprVisitor 
{
public:
  std::string print(std::shared_ptr<Expr> expr) 
  {
    return std::any_cast<std::string>(expr->accept(*this));
  }

  //Visit Binary Expression
  std::any visitBinaryExpr(std::shared_ptr<Binary> expr) override 
  {
    return parenthesize(expr->op.lexeme, expr->left, expr->right);
  }

  //Visit Grouping Expression
  std::any visitGroupingExpr(std::shared_ptr<Grouping> expr) override 
  {
    return parenthesize("group", expr->expression);
  }

  //Visit Literal Exprpression
  std::any visitLiteralExpr(std::shared_ptr<Literal> expr) override 
  {
    auto& value_type = expr->value.type();

    if (value_type == typeid(nullptr)) {
      return "nil";
    } else if (value_type == typeid(std::string)) {
      return std::any_cast<std::string>(expr->value);
    } else if (value_type == typeid(double)) {
      return std::to_string(std::any_cast<int>(expr->value));
    } else if (value_type == typeid(bool)) {
      return std::any_cast<bool>(expr->value) ? "true" : "false";
    }

    return "Error in visitLiteralExpr: literal type not recognized.";
  }
  //Visit Unary Expression
  std::any visitUnaryExpr(std::shared_ptr<Unary> expr) override {
    return parenthesize(expr->op.lexeme, expr->right);
  }

  //Visit Ternary Expr
  //std::any visitTernaryExpr(std::shared_ptr<Ternary> expr) override {
    //return parenthesize("ternary", expr->condition, expr->if_false, expr->if_true);
  //}

private:
  template <class... E> 
  std::string parenthesize(std::string_view name, E... expr)
  {
    assert((... && std::is_same_v<E, std::shared_ptr<Expr>>));

    std::ostringstream builder;

    builder << "(" << name;
    ((builder << " " << print(expr)), ...);
    builder << ")";

    return builder.str();
  }
};