#pragma once 

template<typename T>
class sdkClass {
public:
    std::string symbol;

    uintptr_t Get();       
    uintptr_t GetGot();        

    void Hook(void* new_func);     
    void HookGot();              

    void Unhook();             
    uintptr_t Find(const std::string& pattern);    // pattern scan (hex)
    uintptr_t FindAsm(const std::string& asmcode); // pattern scan (asm)

    void Write(const void* value, size_t size);    
    //...
};

#include "sdkClass.inl"