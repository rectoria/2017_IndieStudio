/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AState.cpp
*/

#include <iostream>
#include "../../include/Abstracts/AState.hpp"

AState::AState(AStateShare &_share) : _share(_share)
{
}

bool AState::isEnable() const
{
	return _enable;
}

void AState::setEnable(bool _enable)
{
	AState::_enable = _enable;
}

bool AState::isLoaded() const
{
	return _loaded;
}

void AState::load()
{
	_loaded = true;
}

void AState::unload()
{
	_loaded = false;
}

AState::~AState()
{
	if (_loaded)
		unload();
}

void AState::transitionPop()
{
}

void AState::transitionPush()
{
}

void AState::addAlteredNode
(irr::scene::ISceneNode *n, std::function<void(irr::scene::ISceneNode *)> fct)
{
	if (_alteredNodes.count(n) > 0)
		throw std::runtime_error("Node is already Altered");
	_alteredNodes[n] = fct;
}

AStateShare &AState::getSharedRes() const
{
	return _share;
}

void AState::pushing()
{

}

void AState::popping()
{
	for (auto &n : _alteredNodes) {
		n.second(n.first);
	}
}
