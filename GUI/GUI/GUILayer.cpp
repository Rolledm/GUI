#include "GUIlayer.h"
#include <iostream>

GUILayer::GUILayer(RenderWindow &Swindow, Vector2f position_, Vector2f size_) : IDrawable(position_, size_)
{
	window = &Swindow;
}

std::shared_ptr<GUIBox> GUILayer::CreateBox(float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, x, y, width, height, text_, tstyle, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}
std::shared_ptr<GUIBox> GUILayer::CreateBox(Vector2f position_, Vector2f size_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, position_, size_, text_, tstyle, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}
std::shared_ptr<GUIBox> GUILayer::CreateBox(float x, float y, Vector2f size_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, x, y, size_, text_, tstyle, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}
std::shared_ptr<GUIBox> GUILayer::CreateBox(Vector2f position_, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, position_, width, height, text_, tstyle, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}

std::shared_ptr<GUIButton> GUILayer::CreateButton(float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(window, x, y, width, height, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}
std::shared_ptr<GUIButton> GUILayer::CreateButton(Vector2f position_, Vector2f size_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(window, position_, size_, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}
std::shared_ptr<GUIButton> GUILayer::CreateButton(Vector2f position_, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(window, position_, width, height, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}
std::shared_ptr<GUIButton> GUILayer::CreateButton(float x, float y, Vector2f size_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(window, x, y, size_, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}

std::shared_ptr<GUILabel> GUILayer::CreateLabel(float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle)
{
	std::shared_ptr<GUILabel> label(new GUILabel(window, x, y, width, height, text_, tstyle, gstyle));
	label->parent = this;
	elements.push_back(label);
	return label;
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(Vector2f position_, Vector2f size_, std::string text_, TextStyle * tstyle, GUIStyle * gstyle)
{
	std::shared_ptr<GUILabel> label(new GUILabel(window, position_, size_, text_, tstyle, gstyle));
	label->parent = this;
	elements.push_back(label);
	return label;
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(float x, float y, float width, float height, std::string text_, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle)
{
	std::shared_ptr<GUILabel> label(new GUILabel(window, x, y, width, height, text_, tstyle, texture, gstyle));
	label->parent = this;
	elements.push_back(label);
	return label;
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(Vector2f position_, Vector2f size_, std::string text_, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle)
{
	std::shared_ptr<GUILabel> label(new GUILabel(window, position_, size_, text_, tstyle, texture, gstyle));
	label->parent = this;
	elements.push_back(label);
	return label;
}

std::shared_ptr<GUIProgressBar> GUILayer::CreateProgressBar(float x, float y, float width, float height,
	std::string text_, TextStyle *tstyle, GUIStyle *gstyle,
	float leftBorder, float rightBorder, Color staticBarColor, Color dynamicBarColor)
{
	std::shared_ptr<GUIProgressBar> progressBar(new GUIProgressBar(window, x, y, width, height, text_, tstyle, gstyle, leftBorder, rightBorder, staticBarColor, dynamicBarColor));
	progressBar->parent = this;
	elements.push_back(progressBar);
	return progressBar;
}

void GUILayer::notifyAll(const sf::Event & event) const
{
	for (auto& element : elements)
		element->handleEvent(event);
}

void GUILayer::removeElement(IDrawable* observer)
{
	IDrawable* IDispPtr = dynamic_cast<IDrawable*> (observer);
	auto position = std::find_if(elements.begin(), elements.end(),
		[IDispPtr](std::shared_ptr<IDrawable> const& i)
	{ return i.get() == IDispPtr; });
	if (position != elements.end())
		std::cout << "found" << std::endl;
}

void GUILayer::handleEvent(const sf::Event & event)
{
	notifyAll(event);
}

void GUILayer::Draw()
{
	for (std::shared_ptr<IDrawable> bo : elements)
		bo->Draw();
}

std::shared_ptr<ScrollBar> GUILayer::CreateScrollBar(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, Orientation orientation) {
	std::shared_ptr<ScrollBar> scrollbar(new ScrollBar(window, orientation, text, tstyle, gstyle));
	scrollbar->parent = this;
	elements.push_back(scrollbar);
	return scrollbar;
}