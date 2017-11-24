#pragma once

#include "colour.h"

template<template <typename Type, typename Colour> class Container, typename Type, typename Colour>
class QwixxRow {
	Container<Type> qwixxContainer;
	Colour c;

public:
	//+= operator to add RollOfDice of size 2, error checking throw exception on error

	//overload insertion operator print for ScoreSheet
};