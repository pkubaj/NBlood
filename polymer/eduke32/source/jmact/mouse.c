/*
 * mouse.c
 * MACT library -to- JonoF's Build Port Mouse Glue
 *
 * by Jonathon Fowler
 *
 * Since we don't have the source to the MACT library I've had to
 * concoct some magic to glue its idea of controllers into that of
 * my Build port.
 *
 */
//-------------------------------------------------------------------------
/*
Duke Nukem Copyright (C) 1996, 2003 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
//-------------------------------------------------------------------------

#include "compat.h"

#include "mouse.h"
#include "baselayer.h"

int32_t Mouse_Init(void)
{
    initmouse();
    return ((inputdevices & 2) == 2);
}


void MOUSE_Shutdown(void)
{
    uninitmouse();
}


void MOUSE_ShowCursor(void)
{
}


void MOUSE_HideCursor(void)
{
}


int32_t MOUSE_GetButtons(void)
{
    int32_t buttons;

    readmousebstatus(&buttons);

#ifdef GEKKO
    buttons |= (joyb&3)<<8;
    switch (joyhat[0]) { // stupid hat values....
        case 0:
        case 4500:
        case 27500:
            buttons |= 4096;
            break;
        case 18000:
        case 13500:
        case 22500:
            buttons |= 8192;
        default:
            break;
    }
#endif

    return buttons;
}


int32_t MOUSE_ClearButton(int32_t b)
{
    return (mouseb &= ~b);
}


void MOUSE_GetDelta(int32_t*x, int32_t*y)
{
    readmousexy(x,y);
}



