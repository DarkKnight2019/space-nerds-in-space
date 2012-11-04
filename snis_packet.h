#ifndef __SNIS_PACKET_H__
#define __SNIS_PACKET_H__
/*
        Copyright (C) 2010 Stephen M. Cameron 
        Author: Stephen M. Cameron

        This file is part of Spacenerds In Space.

        Spacenerds in Space is free software; you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation; either version 2 of the License, or
        (at your option) any later version.

        Spacenerds in Space is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with Spacenerds in Space; if not, write to the Free Software
        Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "snis_marshal.h"

#define OPCODE_UPDATE_SHIP		100
#define OPCODE_UPDATE_STARBASE	101
#define OPCODE_UPDATE_LASER	102
#define OPCODE_UPDATE_TORPEDO	103
#define OPCODE_UPDATE_PLAYER	104
#define OPCODE_ACK_PLAYER	105	
#define OPCODE_ID_CLIENT_SHIP	106
#define OPCODE_UPDATE_PLANET	107
#define OPCODE_REQUEST_YAW	108
#define OPCODE_REQUEST_THRUST	109
#define OPCODE_REQUEST_GUNYAW	110
#define OPCODE_REQUEST_TORPEDO	111
#define OPCODE_DELETE_OBJECT    112

#define OPCODE_POS_SHIP		200
#define OPCODE_POS_STARBASE	201
#define OPCODE_POS_LASER	202
#define OPCODE_NOOP		0xffff

#pragma pack(1)
struct update_ship_packet {
	uint16_t opcode;
	uint32_t id;
	uint32_t alive;
	uint32_t x, y, vx, vy, heading;
        uint32_t ntorpedoes;
        uint32_t energy;
        uint32_t sheilds;
	uint32_t gun_heading;
};

struct client_ship_id_packet {
	uint16_t opcode;
	uint32_t shipid;
};

struct update_planet_packet {
	uint16_t opcode;
	uint32_t id;
	uint32_t x, y;
};

struct update_starbase_packet {
	uint16_t opcode;
	uint32_t id;
	uint32_t x, y;
};

struct add_laser_packet {
	uint16_t opcode;
	uint32_t id;
	uint32_t power;
	uint32_t color;
	struct packed_double x, y;
	struct packed_double vx, vy;
};

struct delete_object_packet {
	uint16_t opcode;
	uint32_t id;
};

struct update_torpedo_packet {
	uint16_t opcode;
	uint32_t id;
	uint32_t x, y;
	uint32_t vx, vy;
}; 

struct request_torpedo_packet {
	uint16_t opcode;
};

struct request_yaw_packet {
	uint16_t opcode;
	uint8_t direction;
#define YAW_LEFT 1
#define YAW_RIGHT 2
};

struct request_thrust_packet {
	uint16_t opcode;
	uint8_t direction;
#define THRUST_FORWARDS 1
#define THRUST_BACKWARDS 2
};

#define ROLE_MAIN 0
#define ROLE_HELM 1
#define ROLE_WEAPONS 2
#define ROLE_ENGINEERING 3
#define ROLE_SCIENCE 4
#define ROLE_COMMS 5


#define SNIS_ALLOW_DEBUG_CONSOLE 1
#ifdef SNIS_ALLOW_DEBUG_CONSOLE
#define ROLE_DEBUG 6
#define ROLE_MAXROLE 6
#else
#define ROLE_MAXROLE 5
#endif

struct add_player_packet {
	uint16_t opcode;
	uint8_t role;
	unsigned char shipname[20];
	unsigned char password[20];
};

struct ack_player_packet {
	uint16_t opcode;
	uint8_t allowed;
};

struct pos_ship_packet {
	uint16_t opcode;
	uint32_t id;
	struct packed_double x, y;
	struct packed_double vx, vy;
	struct packed_double heading;
};

struct pos_starbase_packet {
	uint16_t opcode;
	uint32_t id;
	struct packed_double x, y;
	struct packed_double vx, vy;
	struct packed_double heading;
};

struct pos_laser_packet {
	uint16_t opcode;
	uint32_t id;
	struct packed_double x, y;
};

struct pos_torpedo_packet {
	uint16_t opcode;
	uint32_t id;
	struct packed_double x, y;
}; 

#endif	
