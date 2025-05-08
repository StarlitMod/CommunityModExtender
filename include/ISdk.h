#ifndef ISDK_H
#define ISDK_H

class ISdk {
public:
    // get the current version of the SDK
    virtual const char* GetVersion();
    
};

#endif