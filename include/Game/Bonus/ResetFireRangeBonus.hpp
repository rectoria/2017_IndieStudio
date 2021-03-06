/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** ResetFireRangeBonus.hpp
*/

#ifndef BOMBERMAN_RESETFIRERANGEBONUS_HPP
	#define BOMBERMAN_RESETFIRERANGEBONUS_HPP

	#include "../Entities/ABonusEntity.hpp"

class ResetFireRangeBonus : public ABonusEntity {
public:
	ResetFireRangeBonus();

	void playerChanging(PlayerEntity *entity) override;
};

#endif /* !BOMBERMAN_RESETFIRERANGEBONUS_HPP */
