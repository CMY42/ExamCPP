#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP
#include "ATarget.hpp"
#include <string>
#include <iostream>

class BrickWall : public ATarget
{
	public:
	BrickWall();
	~BrickWall();
	ATarget * clone() const;
};
#endif
