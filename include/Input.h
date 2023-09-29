#ifndef INPUT_H
#define INPUT_H

#include <queue>
#include <array>
#include <map>
#include <string>
#include <functional>

#include <raylib.h>

enum class KeybindGroup
{
	DEFAULT,
	USER
};

class Input
{
private:
	std::map<int, std::string> key_names;

	std::array<std::string, 350> pressed_keybinds;
	std::array<std::string, 350> down_keybinds;
	//std::map<int, range or somethng> range_keybinds

	
	std::multimap<std::string, std::function<void(float)>> pressed_event_callbacks;
	std::multimap<std::string, std::function<void(float)>> down_event_callbacks;
	//std::multimap<range map
	

	//controller stuff
	auto getKeybindGroup(KeybindGroup group);
	void setKeybinds(KeybindGroup group);
	void saveKeybinds() const;

	void triggerEvent(std::string event, std::multimap<std::string, std::function<void(float)>> callbacks, float dt) const;

	void generateKeyNames();
public:
	Input();
	~Input();

	void pollInputs(float dt);

	void registerCallback(std::string event, std::function<void(float)> callback);

	//void setKeybind(KeyboardKey key_code, std::string event_pressed);
	//void setKeybind(KeyboardKey key_code, std::string event_down);

	void clearCallbacks();
};

extern Input input;

#endif