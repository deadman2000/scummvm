/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ULTIMA_SHARED_MAPS_MAP_TILE_H
#define ULTIMA_SHARED_MAPS_MAP_TILE_H

namespace Ultima {
namespace Shared {
namespace Maps {

class MapWidget;

/**
 * Contains data about a given position within the map
 */
class MapTile {
public:
	int _tileId;							// Tile Id
	int _tileNum;							// Tile number to display. Normally equals Tile Id, but can differ in rare cases
	int _widgetNum;							// Widget number, if any
	MapWidget *_widget;						// Widget pointer
	int _itemNum;							// Item number, if any
	// Dungeon tile flags 
	bool _isDoor, _isSecretDoor;
	bool _isLadderUp, _isLadderDown;
	bool _isWall, _isHallway, _isBeams;
public:
	/**
	 * Constructor
	 */
	MapTile() : _tileNum(-1), _tileId(-1), _widgetNum(-1), _widget(0), _itemNum(-1),
		_isDoor(false), _isSecretDoor(false), _isLadderUp(false), _isLadderDown(false), _isWall(false),
		_isHallway(false), _isBeams(false) {}

	/**
	 * Destructor
	 */
	virtual ~MapTile() {}

	/**
	 * Clears the map tile information
	 */
	virtual void clear();

	/**
	 * Returns true if the tile is a door in a dungeon
	 */
	bool isDoor() const { return _isDoor; }

	/**
	 * Returns true if the tile is a wall or secret door in a dungeon
	 */
	bool isWallOrSecretDoor() const { return _isWall || _isSecretDoor; }

	/**
	 * Returns true if the tile in a dungeon is a type that has walls on it: walls, doors, or secret doors
	 */
	bool isWallOrDoorway() const { return _isWall || _isDoor || _isSecretDoor; }

	/**
	 * Returns true if a tile is a solid type within a dungeon
	 */
	bool isSolid() const { return !(_isHallway || _isLadderUp || _isLadderDown || _isBeams); }
};

} // End of namespace Maps
} // End of namespace Shared
} // End of namespace Ultima

#endif