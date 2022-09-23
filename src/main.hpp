/*
 * This is the C++ translation of the package 'brigadier' by Mojang.
 * from version 1.0.18 open-source on GitHub.
 * TNTErick
 * 12022-08-27
 * Licensed under MIT License.
 */

#include<string>

//all files that composes package com.mojang.brigadier

//Message.java
class Message{
    virtual const std::string& getString()=0;
};

//LiteralMessage inherits Message
class LiteralMessage : public Message{
private:
    std::string string;
public:
    LiteralMessage(const std::string& string)
        :string(string){}
    const std::string& getString() const override { return string;}
    const std::string& toString() const override { return string;}  
};

//ImmutableStringReader

//StringReader inherits ImmutableStringReader

