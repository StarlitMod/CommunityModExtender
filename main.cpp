#include <mod/amlmod.h>
#include <mod/logger.h>

MYMOD(net.Android.GtaSdk, Gta Android SDK, 1.0, XMDS and KillerSA)

#include <include/sdk.h>

Sdk* sdk = new Sdk();

inline const char* Sdk::GetVersion(){ return modinfo->VersionString(); }

extern "C" void OnModPreLoad()
{
    RegisterInterface("GtaSdk", sdk);
}
