#ifndef SDKMOD_H
#define SDKMOD_H

// use this in your plugins to get the sdk interface
#include <sdk.h>
#include <mod/interface.h>
#include <include/Events.h>

#define MYSDKDECL()
    Sdk* sdk = (Sdk*)GetInterface("GtaSdk");
    
#endif 