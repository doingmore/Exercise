#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include "CommandInterface.h"

#include <string>


std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text)
{
	CommandInterface object{ text };


}



#endif // !INITIALIZATION_H