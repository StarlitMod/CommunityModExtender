#ifndef SDKLIBRARY_H
#define SDKLIBRARY_H

#include "Events.h"
#include "ISdk.h"

class Sdk : public ISdk {
public:
    uintptr_t m_pGameBase;

    Sdk() { 
        // At the moment we will focus on GTA SA and Vice City
        uintptr_t m_pSA = aml->GetLib("libGTASA.so"), m_pVC = aml->GetLib("libGTAVC.so");
        
        logger->SetTag("GtaSdk"); 
        if(!m_pSA && !m_pVC) {
            logger->Error("GtaSdk is not supported on this game");
        } else {
            if(m_pSA) m_pGameBase = m_pSA;
            else m_pGameBase = m_pVC;
            logger->Info("GtaSdk v%s loaded successfully", GetVersion());
        }
    }

    // get the current version of the SDK
    const char* GetVersion();
};

extern Sdk* sdk;

extern CEvents renderCloudsEvent;
extern CEvents initScriptsEvent;
extern CEvents processScriptsEvent;
extern CEvents initRwEvent;
extern CEvents shutdownRwEvent;
extern CEvents initPoolsEvent;
extern CEvents pedCtorEvent;
extern CEvents pedDtorEvent;
extern CEvents pedRenderEvent;
extern CEvents objectRenderEvent;
extern CEvents objectPreRenderEvent;
extern CEvents touchEvent;
extern CEvents drawHudEvent;
extern CEvents drawingEvent;
extern CEvents drawAfterFadeEvent;
extern CEvents drawRadarEvent;
extern CEvents drawBlipsEvent;
extern CEvents drawRadarOverlayEvent;
extern CEvents drawMenuEvent;
extern CEvents vehicleRenderEvent;
extern CEvents vehicleCtorEvent;
extern CEvents vehicleDtorEvent;
extern CEvents objectCtorEvent;
extern CEvents objectDtorEvent;
extern CEvents initGameEvent;

// new events
extern CEvents updateWidgetsEvent;

#endif 
