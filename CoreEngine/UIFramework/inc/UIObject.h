#pragma once
#include <list>
#include <SDL.h>
#include "IPropertyMethod.h"
#include "ISignalMethod.h"
#include "IProperty.h"
enum UI_TYPE : uint8_t
{
	NODE_2D_IMAGE_TYPE 		= 0U,
	NODE_2D_BUTTON_TYPE 	= 1U,
	NODE_2D_TEXT_TYPE		= 2U,
	NODE_2D_VIEWPORT_TYPE	= 3U,
	EMPTY_NODE				= 4U,
	STACK_LAYOUT_2D			= 5U,
	NODE_3D					= 6U,
};

class UIObject;
typedef std::shared_ptr<UIObject> UIObjectPtr;
typedef std::list<UIObjectPtr> ObjectListType;

class UIObject : public PropertyTable, public SignalTable, public PropertyMethodTable, public SignalMethodTable, public std::enable_shared_from_this<UIObject>
{
protected:
	std::unordered_map<std::string, IPropertyPtr> m_propertyTable;
protected:
	const std::string m_name;

	std::list<UIObjectPtr> m_childList;
	UIObjectPtr m_pParentUIObject = nullptr;

	bool m_bleftMouseButtonDown = false;
public:
	UIObject() = delete;
	UIObject(std::string name);
	virtual ~UIObject();
	virtual uint8_t getType() = 0;

	std::string getUrl() const;
	std::string getName() const;

	void moveTo(UIObjectPtr);
	void addChild(UIObjectPtr);
	void removeChild(std::string m_name);
	UIObjectPtr getChild(std::string m_name);

	void onInit();
	void onDraw();
	void onClean();

	void onKeyInputEvent(SDL_Event&);
};