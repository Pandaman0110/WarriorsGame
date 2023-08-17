#include "InputManager.h"

#include <iostream>
#include <fstream>
#include <algorithm>

#include <toml.hpp>

InputManager::InputManager()
{
	this->generateKeyNames();

	pressed_keybinds.fill("");
	down_keybinds.fill("");
	this->setKeybinds(KeybindGroup::USER);
}

InputManager::~InputManager()
{
	this->saveKeybinds();
}

void InputManager::pollInputs(float dt)
{
	//TODO allow the same key to have a pressed functionality and a held down functionality
	
	for (size_t key_code = 0; key_code < pressed_keybinds.size(); key_code++)
	{
		std::string event_name = pressed_keybinds.at(key_code);

		if (event_name != "" and IsKeyPressed(key_code))
		{
			this->triggerEvent(event_name, pressed_event_callbacks, dt);
		}
	}
	for (size_t key_code = 0; key_code < down_keybinds.size(); key_code++)
	{
		std::string event_name = down_keybinds.at(key_code);

		if (event_name != "" and IsKeyDown(key_code))
		{
			this->triggerEvent(event_name, down_event_callbacks, dt);
		}
	}
}

void InputManager::registerCallback(std::string event, std::function<void(float)> callback)
{
	if (std::find(pressed_keybinds.begin(), pressed_keybinds.end(), event) != pressed_keybinds.end())
		pressed_event_callbacks.insert({ event, callback });
	if (std::find(down_keybinds.begin(), down_keybinds.end(), event) != down_keybinds.end())
		down_event_callbacks.insert({ event, callback });
}

void InputManager::triggerEvent(std::string event, std::multimap<std::string, std::function<void(float)>> callbacks, float dt) const
{
	auto range = callbacks.equal_range(event);

	for (auto i = range.first; i != range.second; i++)
		i->second(dt);
}

void InputManager::clearCallbacks()
{
	pressed_event_callbacks.clear();
	down_event_callbacks.clear();
}

auto InputManager::getKeybindGroup(KeybindGroup group) 
{
	toml::table keybinds;

	switch (group)
	{
	case KeybindGroup::DEFAULT:
		keybinds = toml::parse_file("DefaultKeybinds.toml");
		break;
	case KeybindGroup::USER:
		keybinds = toml::parse_file("Keybinds.toml");
		break;
	}

	return keybinds;
}

void InputManager::setKeybinds(KeybindGroup group)
{
	auto keybinds = this->getKeybindGroup(group);

	auto pressed = keybinds["Pressed"];
	auto down = keybinds["Down"];

	for (auto i = pressed.as_table()->begin(); i != pressed.as_table()->end(); i++)
	{
		int key_code = std::stoi(i->first.str().data());
		std::string event_name = *i->second.value<std::string>();

		pressed_keybinds.at(key_code) = event_name;
	}

	for (auto i = down.as_table()->begin(); i != down.as_table()->end(); i++)
	{
		int key_code = std::stoi(i->first.str().data());
		std::string event_name = *i->second.value<std::string>();

		down_keybinds.at(key_code) = event_name;
	}
}

void InputManager::saveKeybinds() const
{
	auto keybinds = toml::parse_file("Keybinds.toml");

	auto pressed = keybinds["Pressed"];
	auto down = keybinds["Down"];

	for (size_t key_code = 0; key_code < pressed_keybinds.size(); key_code++)
	{
		std::string event_name = pressed_keybinds.at(key_code);

		if (event_name != "")
			pressed.as_table()->insert_or_assign(toml::key(std::to_string(key_code)), toml::value<std::string>(event_name));
	}

	for (size_t key_code = 0; key_code < down_keybinds.size(); key_code++)
	{
		std::string event_name = down_keybinds.at(key_code);

		if (event_name != "")
			down.as_table()->insert_or_assign(toml::key(std::to_string(key_code)), toml::value<std::string>(event_name));
	}

	std::ofstream output;
	output.open("Keybinds.toml");

	//this enum format_flags is a bitmask, the ~ operator is bitwise NOT and flips it off
	//literals strings in toml are surrounded by single quotes, and its ugly so its off
	//toml terse key value pairs is turned off to keep the pretty white space in the files too
	output << toml::toml_formatter(keybinds, ~toml::format_flags::allow_literal_strings & ~toml::format_flags::terse_key_value_pairs) << std::endl;

	output.close();
}

void InputManager::generateKeyNames()
{
	auto key_name = toml::parse_file("KeyNames.toml");

	for (auto i = key_name.as_table()->begin(); i != key_name.as_table()->end(); i++)
	{
		int key_code = std::stoi(i->first.str().data());
		std::string key_name = *i->second.value<std::string>();

		key_names.insert({ key_code, key_name });
	}
}
