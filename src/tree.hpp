/*
 * corresponds to the "tree" folder of Mojang's code.
 * TNTErick
 * 12022-08-31
 * MIT License.
 */

#include<map>

template<typename T>
class CommandNode{
private:
    std::map<const char*, CommandNode*>         children; //puts only CommandNode into it
    std::map<const char*, LiteralCommandNode*>  literals;
    std::map<const char*, ArgumentCommandNode*> arguments;
    
protected:

public:
    
    //Equivilent to (java.util.function.)Predicate
    //Tho the Predicate member class is private, its method is public. 
    bool operator bool();

    //Equivilent to Comparable
    bool operator >
    bool operator ==(const CommandNode& that);
    bool operator !=(const CommandNode& that);
};