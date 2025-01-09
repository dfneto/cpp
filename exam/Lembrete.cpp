



Constructor: 
    ClassName::ClassName(Args);
Destructor: 
    ClassName::~ClassName();

<return_type>       ClassName::     <function_name>     (<parameters>)          [qualifiers] [noexcept];
ClassName &         ClassName::     operator=           (const ClassName &ref)              {}
void                Warlock::       introduce           ()                      const       {}
const std::string&  Warlock::       getName             ()                      const       {}


Abstract class has a pure method: virtual =0
Also add a clone pure method that returns a pointer to ASpell:
virtual ASpell* clone() const = 0;

#include <string>
#include <iostream>

getHitBySpell eh const!