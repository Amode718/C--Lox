#include <iostream>    
#include <string>
#include <vector>
#include <cstring>      
#include <fstream>     
#include "Error.h"
#include "Interpreter.h"
#include "Parser.h"
#include "Scanner.h"
#include "Stmt.h"
//#include "AstPrinter.h"
//#include "RpnPrinter.h"

std::string readFile(std::string_view path) {
  std::ifstream file{path.data(), std::ios::in | std::ios::binary | std::ios::ate};
  if (!file) 
  {
    std::cout << "Failed to open file " << path << ": " << std::strerror(errno) << "\n";
    std::exit(74);
  }

  std::string contents;
  contents.resize(file.tellg());

  file.seekg(0, std::ios::beg);
  file.read(contents.data(), contents.size());

  return contents;
}

Interpreter interpreter{};

void run(std::string_view source) {
  Scanner scanner {source};
  std::vector<Token> tokens = scanner.scanTokens();
  Parser parser{tokens};
  std::vector<std::shared_ptr<Stmt>> statements = parser.parseRepl();

  // Stop if there was a syntax error.
  if (hadError) return;

  // Stop if there was a resolution error.
  if (hadError) return;


  interpreter.interpret(statements);
}


void runFile(std::string_view path) {
  std::string contents = readFile(path);
  run(contents);

  // Indicate an error in the exit code.
  if (hadError) std::exit(65);
  if (hadRuntimeError) std::exit(70);
}

void runPrompt() 
{
  for (;;) 
  {
    hadError = false;
    //std::cout << "> ";
    std::string line;
    if (!std::getline(std::cin, line)) break;
    // run(line);
    // hadError = false;
 
  
    Scanner scanner{line};
    std::vector<Token> tokens = scanner.scanTokens();
    Parser parser{tokens};
    std::vector<std::shared_ptr<Stmt>> syntax = parser.parseRepl();
    if (hadError) 
    {
        continue;
    }

    if (std::dynamic_pointer_cast<Expression>(syntax[0]) == nullptr && syntax.size() >= 1)
    {
        interpreter.interpret(syntax);
    }
    else
    {
      std::string result = interpreter.interpretExpr(syntax);
      if (!result.empty())
      {
        std::cout << result << std::endl;
        }
        else
        {
          std::cout << "nil" << std::endl;
          break;
        }
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc > 2) {
    std::cout << "Usage: mylox [script]" << std::endl;
    std::exit(64);
  } else if (argc == 2) {
    runFile(argv[1]);
  } else {
    runPrompt();
  }
}