#pragma once

#include <stdexcept>

class IOException : public std::exception
{
private:
    std::string msg;

public:
    IOException(const std::string& message = "") : msg(message)
    {
    }

    const char * what() const throw()
    {
        return msg.c_str();
    }
	
	~IOException() throw(){};
};
