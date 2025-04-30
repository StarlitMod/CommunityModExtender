#pragma once
#include <functional>

using EventPtr = std::function<void()>;
using EventPtrPed = std::function<void(CPed*)>;
using EventPtrObj = std::function<void(CObject*)>;
using EventPtrVeh = std::function<void(CVehicle*)>;
using EventPtrBlips = std::function<void(float)>;
using EventPtrRadarOv = std::function<void(bool)>;
using EventPtrMob = std::function<void(void*)>;
using EventPtrTouch = std::function<void(int, int, int, int)>;
using EventPtrWidget = std::function<void(CWidget*)>;

class EventsList {
public:
	std::vector<EventPtr> events; // parameterless events
	std::vector<EventPtrPed> PedEvents;
	std::vector<EventPtrObj> ObjEvents;
	std::vector<EventPtrVeh> VehEvents;
	std::vector<EventPtrBlips> blipsEvents;
	std::vector<EventPtrTouch> TouchEvents;
	std::vector<EventPtrRadarOv> radarEvents;
	std::vector<EventPtrWidget> widgetEvents;
	std::vector<EventPtrMob> mobMenuEvents;

	std::vector<EventPtr>::iterator actPtr;
	std::vector<EventPtrPed>::iterator PedPtr;
	std::vector<EventPtrObj>::iterator ObjPtr;
	std::vector<EventPtrVeh>::iterator VehPtr;
	std::vector<EventPtrBlips>::iterator blipsPtr;
	std::vector<EventPtrTouch>::iterator TouchPtr;
	std::vector<EventPtrRadarOv>::iterator radarPtr;
	std::vector<EventPtrWidget>::iterator widgetPtr;
	std::vector<EventPtrMob>::iterator mobMenuPtr;
};