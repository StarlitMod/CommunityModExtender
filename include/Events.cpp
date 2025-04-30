#include <mod/amlmod.h>
#include <mod/logger.h>
#include <include/Call.h>
#include <include/Events.h>
#include "sdk.h"

///////////// continuation of CEvents from Xmds /////////////

CEvents initGameEvent(initGame);
CEvents initScriptsEvent(initScripts);
CEvents initRwEvent(initRw);
CEvents shutdownRwEvent(shutdownRw); 
CEvents initPoolsEvent(initPools);
CEvents shutdownPoolsEvent(shutdownPools);

CEvents pedCtorEvent(pedCtor);
CEvents pedDtorEvent(pedDtor);
CEvents pedRenderEvent(pedRender);

CEvents objectCtorEvent(objectCtor);
CEvents objectDtorEvent(objectDtor);
CEvents objectRenderEvent(objectRender);
CEvents objectPreRenderEvent(objectPreRender);

CEvents processScriptsEvent(processScripts);
CEvents renderCloudsEvent(renderClouds); 
CEvents touchEvent(touch);

CEvents drawHudEvent(drawHud);
CEvents drawingEvent(drawing);
CEvents drawAfterFadeEvent(drawAfterFade);
CEvents drawRadarEvent(drawRadar);
CEvents drawBlipsEvent(drawBlips);
CEvents drawRadarOverlayEvent(drawRadarOverlay);
CEvents drawMenuEvent(drawMenu);

CEvents vehicleRenderEvent(vehicleRender);
CEvents vehicleCtorEvent(vehicleCtor);
CEvents vehicleDtorEvent(vehicleDtor);

// new events
CEvents updateWidgetsEvent(updateWidgets);

#define callFuncs(_eventPtr, _eventsList, _funcType, ...) for(_eventPtr = _eventsList.begin(); _eventPtr != _eventsList.end(); ++_eventPtr){ _funcType func = *_eventPtr; func(__VA_ARGS__);}

void CEvents::pedRenderCalls(CPed* ped) {
    callFuncs(pedRenderEvent.PedPtr, pedRenderEvent.PedEvents, EventPtrPed, ped)
}

DECL_HOOKv(PedRenderHook, CPed* ped) {
    PedRenderHook(ped);
    CEvents::pedRenderCalls(ped);
}

void CEvents::drawingCalls() {
    callFuncs(drawingEvent.actPtr, drawingEvent.events, EventPtr);
}

DECL_HOOKv(drawingHook) {
    drawingHook();
    CEvents::drawingCalls();
}

void CEvents::drawAfterFadeCalls() {
    callFuncs(drawAfterFadeEvent.actPtr, drawAfterFadeEvent.events, EventPtr);
}

DECL_HOOKv(drawAfterFadeHook) {
    drawAfterFadeHook();
    CEvents::drawAfterFadeCalls();
}

void CEvents::vehicleRenderCalls(CVehicle* veh) {
    callFuncs(vehicleRenderEvent.VehPtr, vehicleRenderEvent.VehEvents, EventPtrVeh, veh);
}

DECL_HOOKv(vehicleRenderHook, CVehicle* veh) {
    vehicleRenderHook(veh);
    CEvents::vehicleRenderCalls(veh);
}

void CEvents::drawBlipsCalls(float size) {
    callFuncs(drawBlipsEvent.blipsPtr, drawBlipsEvent.blipsEvents, EventPtrBlips, size);
}

DECL_HOOKp(drawBlipsHook, float size) {
    void* ret = drawBlipsHook(size);
    CEvents::drawBlipsCalls(size);
    return ret;
}

void CEvents::objectPreRenderCalls(CObject* obj) {
    callFuncs(objectPreRenderEvent.ObjPtr, objectPreRenderEvent.ObjEvents, EventPtrObj, obj);
}

DECL_HOOKv(objectPreRenderHook, CObject* obj) {
    objectPreRenderHook(obj);
    CEvents::objectPreRenderCalls(obj);
}

void CEvents::objectRenderCalls(CObject* obj) {
    callFuncs(objectRenderEvent.ObjPtr, objectRenderEvent.ObjEvents, EventPtrObj, obj);
}

DECL_HOOKv(objectRenderHook, CObject* obj) {
    objectRenderHook(obj);
    CEvents::objectRenderCalls(obj);
}

void CEvents::initRwCalls() {
    callFuncs(initRwEvent.actPtr, initRwEvent.events, EventPtr);
}

DECL_HOOKi(initRwHook) {
    int ret = initRwHook();
    CEvents::initRwCalls();
    return ret;
}

void CEvents::shutdownRwCalls() {
    callFuncs(shutdownRwEvent.actPtr, shutdownRwEvent.events, EventPtr);
}

DECL_HOOKv(shutdownRwHook) {
    CEvents::shutdownRwCalls();
    shutdownRwHook();
}

void CEvents::initPoolsCalls() {
    callFuncs(initPoolsEvent.actPtr, initPoolsEvent.events, EventPtr);
}

DECL_HOOKi(initPoolsHook) {
    int ret = initPoolsHook();
    CEvents::initPoolsCalls();
    return ret;
}

void CEvents::shutdownPoolsCalls() {
    callFuncs(shutdownPoolsEvent.actPtr, shutdownPoolsEvent.events, EventPtr);
}

DECL_HOOKv(shutdownPoolsHook) {
    CEvents::shutdownPoolsCalls();
    shutdownPoolsHook();
}

void CEvents::drawMenuCalls(void* gMobileMenu) {
    callFuncs(drawMenuEvent.mobMenuPtr, drawMenuEvent.mobMenuEvents, EventPtrMob, gMobileMenu);
}

DECL_HOOKv(drawMenuHook, void* gMobileMenu) {
    drawMenuHook(gMobileMenu);
    CEvents::drawMenuCalls(gMobileMenu);
}

void CEvents::drawRadarCalls() {
    callFuncs(drawRadarEvent.actPtr, drawRadarEvent.events, EventPtr);
}

DECL_HOOKi(drawRadarHook) {
    int ret = drawRadarHook();
    CEvents::drawRadarCalls();
    return ret;
}

void CEvents::drawRadarOverlayCalls(bool inMenu) {
    callFuncs(drawRadarOverlayEvent.radarPtr, drawRadarOverlayEvent.radarEvents, EventPtrRadarOv, inMenu);
}

DECL_HOOKv(drawRadarOverlayHook, bool inMenu) {
    drawRadarOverlayHook(inMenu);
    CEvents::drawRadarOverlayCalls(inMenu);
}

void CEvents::processScriptsCalls() {
    callFuncs(processScriptsEvent.actPtr, processScriptsEvent.events, EventPtr);
}

DECL_HOOKv(processScriptsHook) {
    processScriptsHook();
    CEvents::processScriptsCalls();
}

void CEvents::touchCalls(NVTouchEventType actionType, int trackNum, int x, int y) {
    callFuncs(touchEvent.TouchPtr, touchEvent.TouchEvents, EventPtrTouch, actionType, trackNum, x, y);
}

DECL_HOOKv(touchHook, NVTouchEventType actionType, int trackNum, int x, int y) {
    touchHook(actionType, trackNum, x, y);
    CEvents::touchCalls(actionType, trackNum, x, y);
}

void CEvents::initScriptsCalls() {
    callFuncs(initScriptsEvent.actPtr, initScriptsEvent.events, EventPtr);
}

DECL_HOOKi(initScriptsHook) {
    int ret = initScriptsHook();
    CEvents::initScriptsCalls();
    return ret;
}

void CEvents::renderCloudsCalls() {
    callFuncs(renderCloudsEvent.actPtr, renderCloudsEvent.events, EventPtr);
}

DECL_HOOKi(renderCloudsHook) {
    return renderCloudsHook();
    CEvents::renderCloudsCalls();
}

void CEvents::pedCtorCalls(CPed* ped) {
    callFuncs(pedCtorEvent.PedPtr, pedCtorEvent.PedEvents, EventPtrPed, ped);
}

DECL_HOOKv(pedCtorHook, CPed* ped) {
    pedCtorHook(ped);
    CEvents::pedCtorCalls(ped);
}

void CEvents::pedDtorCalls(CPed* ped) {
    callFuncs(pedDtorEvent.PedPtr, pedDtorEvent.PedEvents, EventPtrPed, ped);
}

DECL_HOOKv(pedDtorHook, CPed* ped) {
    CEvents::pedDtorCalls(ped);
    pedDtorHook(ped);
}

void CEvents::vehicleCtorCalls(CVehicle* veh) {
    callFuncs(vehicleCtorEvent.VehPtr, vehicleCtorEvent.VehEvents, EventPtrVeh, veh);
}

DECL_HOOKv(vehicleCtorHook, CVehicle* veh) {
    vehicleCtorHook(veh);
    CEvents::vehicleCtorCalls(veh);
}

void CEvents::vehicleDtorCalls(CVehicle* veh) {
    callFuncs(vehicleDtorEvent.VehPtr, vehicleDtorEvent.VehEvents, EventPtrVeh, veh);
}

DECL_HOOKv(vehicleDtorHook, CVehicle* veh) {
    CEvents::vehicleDtorCalls(veh);
    vehicleDtorHook(veh);
}

void CEvents::initGameCalls() {
    callFuncs(initGameEvent.actPtr, initGameEvent.events, EventPtr);
}

DECL_HOOKv(initGameHook) {
    initGameHook();
    CEvents::initGameCalls();
}

void CEvents::objectCtorCalls(CObject* obj) {
    callFuncs(objectCtorEvent.ObjPtr, objectCtorEvent.ObjEvents, EventPtrObj, obj);
}

DECL_HOOKv(objectCtorHook, CObject* obj) {
    objectCtorHook(obj);
    CEvents::objectCtorCalls(obj);
}

void CEvents::objectDtorCalls(CObject* obj) {
    callFuncs(objectDtorEvent.ObjPtr, objectDtorEvent.ObjEvents, EventPtrObj, obj);
}

DECL_HOOKv(objectDtorHook, CObject* obj) {
    CEvents::objectDtorCalls(obj);
    objectDtorHook(obj);
}

void CEvents::updateWidgetCalls(CWidget* w) {
    callFuncs(updateWidgetsEvent.widgetPtr, updateWidgetsEvent.widgetEvents, EventPtrWidget, w);
}

DECL_HOOKi(updateWidgetsHook, CWidget* w) {
    int ret = updateWidgetsHook(w);
    CEvents::updateWidgetCalls(w);
    return ret;
}

// at the moment, it's just the addresses of gta sa 32 bits
CEvents::CEvents(EventsType type) {
    eventType = type;
    switch(type){
        case updateWidgets:
            HOOKPLT(updateWidgetsHook, 0x66FBCC + sdk->m_pGameBase);
            break;
        case initGame:
            HOOKBLX(initGameHook, 0x5E4714 + 0x226); // _Z11DoGameStatev
            break;
        case drawBlips:
            HOOKPLT(drawBlipsHook, 0x66E910 + sdk->m_pGameBase);
            break;
        case initPools:
            HOOKPLT(initPoolsHook, 0x672468 + sdk->m_pGameBase);
            break;
        case shutdownPools:
            HOOKBLX(shutdownPoolsHook, 0x3F37F4 + 0x15C); // _ZN5CGame8ShutdownEv
            break;
        case initRw:
            HOOKPLT(initRwHook, 0x66F2D0 + sdk->m_pGameBase);
            break;
        case objectPreRender:
            HOOKBLX(objectPreRenderHook, 0x454CA8 + 0x1B0); // _ZN7CObject9PreRenderEv
            break;
        case objectRender:
            HOOKBLX(objectRenderHook, 0x454EF0 + 0x6A); // _ZN7CObject6RenderEv
            break;
        case objectCtor:
            HOOKBLX(objectCtorHook, 0x452C1C + 0x6); // _ZN7CObjectC2Ev
            HOOKBLX(objectCtorHook, 0x452FAC + 0xE); // _ZN7CObjectC2Eib
            HOOKBLX(objectCtorHook, 0x452FF4 + 0xC); // _ZN7CObjectC2EP12CDummyObject
            HOOKBLX(objectCtorHook, 0x4533D8 + 0x62); // _ZN7CObject6CreateEib
            HOOKBLX(objectCtorHook, 0x4533D8 + 0x158); // _ZN7CObject6CreateEib
            break;
        case objectDtor:
            HOOKB(objectDtorHook, 0x453098 + 0x198); // _ZN7CObjectD2Ev
            break;
        case drawMenu:
            HOOKPLT(drawMenuHook, 0x674254 + sdk->m_pGameBase);
            break;
        case drawRadar:
            HOOKPLT(drawRadarHook, 0x66F618 + sdk->m_pGameBase);
            break;
        case drawRadarOverlay:
            HOOKPLT(drawRadarOverlayHook, 0x67196C + sdk->m_pGameBase);
            break;
        case touch:
            HOOKPLT(touchHook, 0x675DE4 + sdk->m_pGameBase);
            break;
        case initScripts:
            HOOKPLT(initScriptsHook, 0x671B14 + sdk->m_pGameBase);
            break;
        case renderClouds:
            HOOKPLT(renderCloudsHook, 0x672FFC + sdk->m_pGameBase);
            break;
        case vehicleRender:
            HOOKB(vehicleRenderHook, 0x5823BC + 0xE6); // _ZN8CVehicle6RenderEv
            break;
        case vehicleCtor:
            HOOKBLX(vehicleCtorHook, 0x581634 + 0xC); // _ZN8CVehicleC2Eh
            break;
        case vehicleDtor:
            HOOKB(vehicleDtorHook, 0x581988 + 0x20C); // _ZN8CVehicleD2Ev
            break;
        case processScripts:
            HOOKPLT(processScriptsHook, 0x672AAC + sdk->m_pGameBase);
            break;
        case pedCtor:
            HOOKBLX(pedCtorHook, 0x49F040 + 0x12); // _ZN4CPedC2Ej
            break;
        case pedDtor:
            HOOKB(pedDtorHook, 0x49F634 + 0x156); // _ZN4CPedD2Ev
            break;
        case pedRender:
            HOOKBLX(PedRenderHook, 0x4A68F4 + 0xBE); // _ZN4CPed6RenderEv
            break;
        case drawing:   
            HOOKBLX(drawingHook, 0x3F641C + 0x48); // _Z13Render2dStuffv
            break;
        case drawAfterFade:
            HOOKPLT(drawAfterFadeHook, 0x673C4C + sdk->m_pGameBase);
            break;    
        case shutdownRw:
            HOOKBLX(shutdownRwHook, 0x3F6EE0 + 0x94); // _Z15AppEventHandler7RsEventPv
            break;
        default:
            break;
    }
}