/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AState.hpp
*/

#include <map>
#include <ISceneNode.h>
#include <functional>
#include "AStateShare.hpp"

#ifndef BOMBERMAN_ASTATE_HPP
#define BOMBERMAN_ASTATE_HPP

class AState {
public:
	AState(AStateShare &_share);
	virtual void update() = 0;
	virtual ~AState();
	bool isEnable() const;
	void setEnable(bool _enable);
	virtual void load();
	virtual void unload();
	virtual bool isLoaded() const;
	virtual void transitionPop();
	virtual void transitionPush();
	virtual void popping();
	virtual void pushing();
	AStateShare &getSharedRes() const;
	void addAlteredNode(
	irr::scene::ISceneNode *n,
	std::function<void(irr::scene::ISceneNode *)>
	fct);
private:
	bool _enable;
	bool _loaded;
	std::map<irr::scene::ISceneNode *,
	std::function<void(irr::scene::ISceneNode *)>>
	_alteredNodes;
protected:
	AStateShare &_share;
};

#endif /* !BOMBERMAN_ASTATE_HPP */