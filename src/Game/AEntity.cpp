/*
** EPITECH PROJECT, 2018
** indie
** File description:
** indie
*/

#include "../../include/Game/AEntity.hpp"

AEntity::AEntity(const std::string &type)
: _type(type),
_origin(),
_staticPosition(),
_node()
{
}

void AEntity::update(EntitiesMap *)
{
}

void AEntity::updateRender()
{
}

//region Save & load

void AEntity::dump(std::ostream &s) const
{
	struct AEntity::serialize ser = {
//		x: _mapPos.X,
//		y: _mapPos.Y,
	};
	auto *se = new char[sizeof(ser)];
	memcpy(se, &ser, sizeof(ser));
	s << _type;
	s.write("\0", 1);
	s.write(se, sizeof(ser));
}

void AEntity::load(std::istream &s)
{
	struct AEntity::serialize ser{};
	auto *se = new char[sizeof(ser)];

	s.read(se, sizeof(ser));
	memcpy(&ser, se, sizeof(ser));
//	_mapPos.X = ser.x;
//	_mapPos.Y = ser.y;
}

std::ostream &operator<<(std::ostream &s, const AEntity &e)
{
	e.dump(s);
	return s;
}

AEntity &operator>>(std::istream &s, AEntity &e)
{
	e.load(s);
	return e;
}

//endregion

void AEntity::collide(AEntity &)
{

}

const Vector3DF &AEntity::getOrigin() const
{
	return _origin;
}

const Vector2DI &AEntity::getMapPos() const
{
	auto x = static_cast<int>(_staticPosition.X);
	auto y = static_cast<int>(_staticPosition.Y);

	return irr::core::vector2di(x, y);
}

void AEntity::setMapPos(const Vector2DI &position)
{
	_staticPosition =  irr::core::vector2df(position.X, position.Y);
}


const Vector2DF &AEntity::getStaticPos() const
{
	return _staticPosition;
}

void AEntity::setStaticPos(const Vector2DF &position)
{
	_staticPosition = position;
}