/***************************************************************************
 *   Copyright (C) 2008-2021 by Andrzej Rybczak                            *
 *   andrzej@rybczak.net                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef NCMPCPP_ARTWORK_H
#define NCMPCPP_ARTWORK_H

#include "config.h"

#ifdef ENABLE_ARTWORK

#include "curses/window.h"
#include "interfaces.h"
#include "screens/screen.h"

struct Artwork: Screen<NC::Window>, Tabbable
{
	Artwork();
	
	virtual void resize() override;
	virtual void switchTo() override;
	
	virtual std::wstring title() override;
	virtual ScreenType type() override { return ScreenType::Artwork; }
	
	virtual void update() override { }
	virtual void scroll(NC::Scroll) override { }
	
	virtual void mouseButtonPressed(MEVENT) override { }
	
	virtual bool isLockable() override { return true; }
	virtual bool isMergable() override { return true; }

	static void removeArtwork();
	static void showArtwork(std::string path, int x_offset, int y_offset, int width, int height);
	static void updateArtwork(std::string path);

private:
	static void stopUeberzug();
};

extern Artwork *myArtwork;

#endif // ENABLE_ARTWORK

#endif // NCMPCPP_ARTWORK_H
