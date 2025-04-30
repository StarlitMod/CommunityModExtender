#pragma once 
#include <variant>
#include <list>

// We don't have the structures at the moment, so we will use forward declarations
class CVehicle;
class CPed;
class CObject;
class CWidget;
enum NVTouchEventType : int
{
    NV_TOUCHACTION_UP,
    NV_TOUCHACTION_DOWN,
    NV_TOUCHACTION_MOVE,
    NV_TOUCHACTION_FORCE_32BITS
};


#include "EventsList.h"

#define addArgs(_func, _eventType) void operator+=(_func p) { _eventType.push_back(p); }

///////////// continuation of CEvents from Xmds /////////////

enum EventsType {
	drawHud, //_ZN4CHud4DrawEv
	drawing, //_ZN9CPopCycle7DisplayEv
	drawAfterFade, //_ZN4CHud13DrawAfterFadeEv
	drawRadar, //_ZN4CHud9DrawRadarEv
	drawBlips, //_ZN6CRadar9DrawBlipsEf
	drawRadarOverlay, //_ZN6CRadar20DrawRadarGangOverlayEb
	drawMenu, //_ZN10MobileMenu6RenderEv

	initRw, //_ZN5CGame20InitialiseRenderWareEv
	shutdownRw, // _Z13RsRwTerminatev
	initPools, //_ZN6CPools10InitialiseEv
	shutdownPools,
	pedCtor, //_ZN4CPedC2Ej                       BLX CPhysical::CPhysical(void)
	pedDtor, //_ZN4CPedD2Ev                       B.W CPhysical::~CPhysical
	pedRender, //_ZN4CPed6RenderEv                BLX CEntity::Render(void)
	objectRender, // _ZN7CObject6RenderEv         BLX CEntity::Render(void)
	objectPreRender, // _ZN7CObject9PreRenderEv   BLX CEntity::PreRender(void)
	objectCtor,
	objectDtor,
	vehicleRender, // _ZN8CVehicle6RenderEv       B.W CEntity::Render(void)
	vehicleCtor,
	vehicleDtor,
	touch, //_Z14AND_TouchEventiiii
	processScripts, // _ZN7CCranes12UpdateCranesEv
	initScripts, // _ZN11CTheScripts4InitEv
	renderClouds, // _ZN7CClouds6RenderEv
	initGame, // _Z14InitialiseGamev   BLX InitialiseGame(void)
	updateWidgets 
};

using EventArgs = std::variant<
    std::function<void()>,
    std::function<void(CPed*)>,
    std::function<void(CObject*)>,
    std::function<void(CVehicle*)>,
    std::function<void(float)>,
    std::function<void(bool)>,
    std::function<void(int, int, int, int)>,
    std::function<void(CWidget*)>,
    std::function<void(void*)>
>;

class CEvents : public EventsList {
public:
	CEvents();
	CEvents(EventsType type);

	EventsType eventType;

	// arguments
	addArgs(EventPtr, events)
	addArgs(EventPtrPed, PedEvents)
	addArgs(EventPtrObj, ObjEvents)
	addArgs(EventPtrVeh, VehEvents)
	addArgs(EventPtrTouch, TouchEvents)
	addArgs(EventPtrBlips, blipsEvents)
	addArgs(EventPtrWidget, widgetEvents)

	static void initRwCalls();
	static void shutdownRwCalls();
	static void initPoolsCalls();
	static void shutdownPoolsCalls();
	static void initGameCalls();
	static void pedCtorCalls(CPed* ped);
	static void pedDtorCalls(CPed* ped);
	static void pedRenderCalls(CPed* ped);
	static void objectRenderCalls(CObject* obj);
	static void vehicleRenderCalls(CVehicle* veh);
	static void objectPreRenderCalls(CObject* obj);
	static void touchCalls(NVTouchEventType actionType, int trackNum, int x, int y);
	static void drawHudCalls();
	static void drawingCalls();
	static void drawAfterFadeCalls();
	static void drawRadarCalls();
	static void drawBlipsCalls(float size);
	static void drawRadarOverlayCalls(bool inMenu);
	static void drawMenuCalls(void* gMobileMenu);
	static void processScriptsCalls();
	static void initScriptsCalls();
	static void renderCloudsCalls();  
	static void vehicleCtorCalls(CVehicle* veh);
	static void vehicleDtorCalls(CVehicle* veh);
	static void objectCtorCalls(CObject* obj);
	static void objectDtorCalls(CObject* obj);

	// new events
	static void updateWidgetCalls(CWidget* w);
};