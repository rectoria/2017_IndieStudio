/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameState.cpp
*/

#include "../../include/States/GameState.hpp"
#include "../../include/Singletons/IrrManager.hpp"
#include "../../include/Singletons/EventReceiver.hpp"
#include "../../include/Singletons/StateMachine.hpp"
#include "../../include/Singletons/AssetsPool.hpp"
#include "../../include/Game/SaveManager.hpp"
#include "../../include/Game/BKeyboardController.hpp"

GameState::GameState(AStateShare &_share) : AState(_share)
{
	auto *controller = new BKeyboardController;

	controller->registerBind(irr::KEY_UP, MOVE_UP);
	controller->registerBind(irr::KEY_DOWN, MOVE_DOWN);
	controller->registerBind(irr::KEY_LEFT, MOVE_LEFT);
	controller->registerBind(irr::KEY_RIGHT, MOVE_RIGHT);
	PlayerEntity *player = new PlayerEntity();

	AController::bindEntityToController(*controller, *player);
	_entity = player;
}

GameState::GameState(AStateShare &_share, std::string &filename) : GameState(_share)
{
	auto *controller = new BKeyboardController;

	controller->registerBind(irr::KEY_UP, MOVE_UP);
	controller->registerBind(irr::KEY_DOWN, MOVE_DOWN);
	controller->registerBind(irr::KEY_LEFT, MOVE_LEFT);
	controller->registerBind(irr::KEY_RIGHT, MOVE_RIGHT);
	PlayerEntity *player = new PlayerEntity();
	AController::bindEntityToController(*controller, *player);

	_entity = player;
	SaveManager::save(_emap, filename);
}

void GameState::update()
{
	_entity->update();
}

void GameState::load()
{
	//auto &er = EventReceiver::getInstance();
	//auto &gm = IrrManager::getInstance();
	//auto &ap = AssetsPool::getInstance();

	auto &n = _share.getSharedNode("menu");
	n.setVisible(false);
	addAlteredNode(&n, [](irr::scene::ISceneNode *n) {
		n->setVisible(true);
	});
//	auto mesh = ap.loadMesh("sydney.md2");
//	_node = gm.getSmgr()->addMeshSceneNode(mesh);
//	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
//	_node->setMaterialTexture(0, ap.loadTexture("sydney.bmp"));
	AState::load();
}

void GameState::updateRender()
{
	_entity->updateRender();
	AState::updateRender();
}
