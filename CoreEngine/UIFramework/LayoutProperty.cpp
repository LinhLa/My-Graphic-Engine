#include "stdafx.h"
#include <string>
#include <LayoutProperty.h>
#include "PropertyDefine.h"
#include "UIHelper.h"
LayoutProperty::LayoutProperty(PropertyTable* propertyTable):m_PropertyTable(propertyTable)
{
	if (!m_PropertyTable)
	{
		throw std::logic_error("invalid_argument");
	}
}

LayoutProperty::~LayoutProperty() {}

LayoutProperty& LayoutProperty::operator=(const LayoutProperty& rhs)
{
	SetLayoutInformation(rhs.GetLayoutInformation());
	return *this;
}

void LayoutProperty::init()
{
	m_PropertyTable->AddProperty(X_COORDINATOR, Property<int>::create(X_COORDINATOR));
	m_PropertyTable->AddProperty(Y_COORDINATOR, Property<int>::create(Y_COORDINATOR));
	m_PropertyTable->AddProperty(LAYOUT_WIDTH, Property<int>::create(LAYOUT_WIDTH));
	m_PropertyTable->AddProperty(LAYOUT_HEIGHT, Property<int>::create(LAYOUT_HEIGHT));
	m_PropertyTable->AddProperty(SCALE_X, Property<float>::create(SCALE_X));
	m_PropertyTable->AddProperty(SCALE_Y, Property<float>::create(SCALE_Y));

	//<Set default value
	SDL_Rect window_rect = UIHelper::GetWindowRect();
	SetLayoutInformation(window_rect);
	SetLayoutScaleX(1.0F);
	SetLayoutScaleY(1.0F);
}

int LayoutProperty::GetLayoutWidth() const
{
	return m_PropertyTable->GetPropertyValue<int>(LAYOUT_WIDTH);
}

void LayoutProperty::SetLayoutWidth(int value)
{
	m_PropertyTable->SetPropertyValue<int>(LAYOUT_WIDTH, std::move(value));
}

int LayoutProperty::GetLayoutHeight() const
{
	return m_PropertyTable->GetPropertyValue<int>(LAYOUT_HEIGHT);
}

void LayoutProperty::SetLayoutHeight(int value)
{
	m_PropertyTable->SetPropertyValue<int>(LAYOUT_HEIGHT, std::move(value));
}

void LayoutProperty::SetLayoutPosition(int x, int y)
{
	m_PropertyTable->SetPropertyValue<int>(X_COORDINATOR, std::move(x));
	m_PropertyTable->SetPropertyValue<int>(Y_COORDINATOR, std::move(y));
}

SDL_Point LayoutProperty::GetLayoutPosition() const
{
	SDL_Rect display_rect = GetLayoutInformation();
	return { display_rect.x , display_rect.y };
}

void LayoutProperty::SetLayoutScaleX(float value)
{
	m_PropertyTable->SetPropertyValue<float>(SCALE_X, std::move(value));
}

float LayoutProperty::GetLayoutScaleX() const
{
	return m_PropertyTable->GetPropertyValue<float>(SCALE_X);
}

void LayoutProperty::SetLayoutScaleY(float value)
{
	m_PropertyTable->SetPropertyValue<float>(SCALE_Y, std::move(value));
}

float LayoutProperty::GetLayoutScaleY() const
{
	return m_PropertyTable->GetPropertyValue<float>(SCALE_Y);
}

SDL_Rect LayoutProperty::GetLayoutInformation() const
{
	SDL_Rect display_rect;
	display_rect.x = m_PropertyTable->GetPropertyValue<int>(X_COORDINATOR);
	display_rect.y = m_PropertyTable->GetPropertyValue<int>(Y_COORDINATOR);
	display_rect.w = m_PropertyTable->GetPropertyValue<int>(LAYOUT_WIDTH);
	display_rect.h = m_PropertyTable->GetPropertyValue<int>(LAYOUT_HEIGHT);
	return display_rect;
}

void LayoutProperty::SetLayoutInformation(const SDL_Rect& r)
{
	SetLayoutPosition(r.x, r.y);
	SetLayoutHeight(r.h);
	SetLayoutWidth(r.w);
}