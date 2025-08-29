# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is an embedded C module repository designed for mbed/embedded scenarios. Each source file implements a standalone module with a specific functionality. The codebase emphasizes efficiency, readability, and simplicity for embedded systems.

## Code Standards and Requirements

### Documentation and Comments
- All comments must be in English using Doxygen format
- Each module requires a comprehensive file header explaining its purpose
- Function documentation should include @brief, @param, and @return tags
- Use `/** */` for Doxygen comments and `/* */` for regular comments

### Code Style
- Use clang-format with the provided `.clang-format` configuration (Microsoft-based style)
- Column limit: 100 characters
- Brace style: Custom with function braces on new lines
- Indentation: 4 spaces, no tabs
- Pointer alignment: Right (`char *ptr`)

### Naming Conventions (enforced by clang-tidy)
- Functions, variables, parameters: `snake_case`
- Constants, macros, enum constants: `UPPER_CASE`
- Structs, enums, typedefs: `snake_case`
- Private member variables: suffix with underscore (`member_`)

### Quality Checks
- Run `clang-tidy` for static analysis using the provided `.clang-tidy` configuration
- Enabled checks: bugprone, misc, performance, readability, cert
- Key disabled checks: magic-numbers, identifier-length, braces-around-statements

## Module Structure

Each module should follow this pattern:
1. File header with copyright, brief description, author, and date
2. Include statements
3. Doxygen-documented function implementations
4. Static functions preferred for internal module functions

## Code Quality Focus

- Expert-level module code prioritizing efficiency for embedded systems
- Strong readability and maintainability
- Concise implementations without sacrificing clarity
- Memory-efficient patterns suitable for resource-constrained environments

## Development Commands

Format code: `clang-format -i *.c`
Static analysis: `clang-tidy *.c`