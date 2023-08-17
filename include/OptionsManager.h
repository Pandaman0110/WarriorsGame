#ifndef OPTIONSMANAGER_H
#define OPTIONSMANAGER_H

#include <iostream>
#include <memory>

#include <raylib.h>


#include "ResolutionManager.h"

class OptionsManager
{
private:
	std::shared_ptr<ResolutionManager> resolution_manager;
public:
	OptionsManager() ;

	inline std::shared_ptr<ResolutionManager> getResolutionManager() const { return this->resolution_manager; };

};

#endif // OPTIONSMANAGER_H

