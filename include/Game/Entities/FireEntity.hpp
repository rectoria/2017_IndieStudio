/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** FireEntity.hpp
*/

#ifndef BOMBERMAN_FIREENTTITY_HPP
#define BOMBERMAN_FIREENTTITY_HPP

#include "../../../include/Game/AEntity.hpp"

class FireEntity : public AEntity {
public:
	FireEntity(const irr::core::vector2di &spread, size_t size);
	void update(EntitiesMap *map) override;
	void spread(EntitiesMap *map);
	void collide(AEntity &entity) override;
	virtual ~FireEntity();
private:
	irr::core::vector2di _spreadDir;
	size_t _spreadSize;
	bool _spreaded;
	size_t _start;
	size_t _duration;
};


#endif /* !BOMBERMAN_FIREENTTITY_HPP */