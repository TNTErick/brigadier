/*
 * This is the C++ translation of the package 'brigadier' by Mojang.
 * from version 1.0.18 open-source on GitHub.
 * TNTErick
 * 12022-08-27
 * Licensed under MIT License.
 */

#include <string>
#ifdef //TODO: include string_view
#else
#endif

// all files that composes package com.mojang.brigadier

// Message.java
class Message
{
    virtual const std::string &getString() const = 0;
    virtual const std::string &toString() const = 0;
};

// LiteralMessage inherits Message
class LiteralMessage : public Message
{
private:
    std::string string; // final

public:
    LiteralMessage(const std::string &str) : string(str) {}
    const std::string &getString() const override { return string; }
    const std::string &toString() const override { return string; }
};

// ImmutableStringReader
class ImmutableStringReader
{
    virtual std::string &getString() = 0;
    virtual const std::string &getString() const = 0;
    virtual int getRemainingLength() const = 0;
    virtual int getTotalLength() const = 0;
    virtual int getCursor() const = 0;
    virtual const std::string &getRead() const = 0;
    virtual const std::string &getRemaining() const = 0;
    virtual bool canRead(int len = -1) const = 0;
    virtual char peek(int offset = 0) const = 0;
};

// StringReader inherits ImmutableStringReader
class StringReader : ImmutableStringReader
{
private:
    const static char SYNTAX_ESCAPE = '\\';
    const static char SYNTAX_DOUBLE_QUOTE = '"';
    const static char SYNTAX_SINGLE_QUOTE = '\'';

    std::string string;
    int cursor;

public:
    StringReader(const StringReader &that) : string(that.string),
                                             cursor(that.cursor) {}
    StringReader(const std::string &str) : string(str),
                                           cursor(0) {}

    const std::string &getString() const override { return string; }
    void setCursor(int i) { this->cursor = i; }
    int getRemainingLength() const override { return string.length() - cursor; }
    int getTotalLength() const override { return string.length(); }
    int getCursor() const override { return cursor; }
    // TODO
};

// AmbiguityConsumer
// Command
// CommandDispatcher
// ParseResults
// RedirectModifier
// ResultConsumer
// SingleRedirectModifier