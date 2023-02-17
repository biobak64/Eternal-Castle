
/*====================================================================
 * os_cont.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)

        $RCSfile: os_cont.h,v $
        $Revision: 1.1 $
        $Date: 1998/10/09 08:01:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_CONT_H_
#define	_OS_CONT_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure for controllers
 */

typedef struct {
	u16 type;                   /* Controller Type */
	u8  status;                 /* Controller status */
	u8	error;
} OSContStatus;

typedef struct {
	u16 button;
	s8  stick_x;		/* -80 <= stick_x <= 80 */
	s8  stick_y;		/* -80 <= stick_y <= 80 */
	u8  error;
} OSContPad;

// Custom extended controller pad struct that contains fields for gamecube controllers
typedef struct {
	u16 button;
	s8  stick_x;		/* -80 <= stick_x <= 80 */
	s8  stick_y;		/* -80 <= stick_y <= 80 */
	s8  c_stick_x;
	s8  c_stick_y;
	u8  l_trig;
	u8  r_trig;
	u8	errno;
} OSContPadEx;

typedef struct {
	void *address;               /* Ram pad Address:  11 bits */
	u8   databuffer[32];         /* address of the data buffer */
    u8   addressCrc;             /* CRC code for address */
	u8   dataCrc;                /* CRC code for data */
	u8   error;
} OSContRamIo;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Number of controllers
 */

#ifndef _HW_VERSION_1
#define MAXCONTROLLERS  4
#else
#define MAXCONTROLLERS  6
#endif

/* Controller errors */
#define CONT_NO_RESPONSE_ERROR          0x8
#define CONT_OVERRUN_ERROR              0x4
#ifdef _HW_VERSION_1
#define CONT_FRAME_ERROR                0x2
#define CONT_COLLISION_ERROR            0x1
#endif

/* Controller types (byteswapped due to __osContGetInitData/__osContGetInitDataEx) */

#define CONT_NONE                           0x0000

// N64:
#define CONT_ABSOLUTE                       0x0001
#define CONT_RELATIVE                       0x0002
#define CONT_JOYPORT                        0x0004

// Console ID:
#define CONT_CONSOLE_MASK                   0x0018 // 0: N64, 1: Dolphin
#define CONT_CONSOLE_N64                    0x0000
#define CONT_CONSOLE_GCN                    0x0008

// Gamecube:
#define CONT_GCN_WIRELESS                   0x0080 // 0: wired, 1: wireless
#define CONT_GCN_MOMOTOR                    0x0020 // 0: available, 1: not available
#define CONT_GCN_STANDARD                   0x0001 // 0: non standard controller, 1: Dolphin Standard Controller

// Wireless (WaveBird):
#define CONT_GCN_RECEIVED                   0x0040 // 0: not wireless, 1: wireless
#define CONT_GCN_WIRELESS_RF                0x0004 // 0: IF, 1: RF
#define CONT_GCN_WIRELESS_STATE_FIXED       0x0002 // 0: variable, 1: fixed
#define CONT_GCN_WIRELESS_VALID_ORIGIN      0x2000 // 0: invalid, 1: valid
#define CONT_GCN_WIRELESS_FIX_ID            0x1000 // 0: not fixed, 1: fixed
#define CONT_GCN_WIRELESS_TYPE_MASK         0x0F00 // 0x0: normal, 0x4: lite, 0x8: non-controller
#define CONT_GCN_WIRELESS_LITE_MASK         0x0C00
#define CONT_GCN_WIRELESS_LITE              0x0400 // 0: normal, 1: lite controller
#define CONT_GCN_WIRELESS_NON_CONTROLLER    0x0800 // 0: normal, 1: non-controller (?)

#define CONT_GCN_WIRELESS_ID                0xC000
#define CONT_GCN_WIRELESS_TYPE_ID           (CONT_GCN_WIRELESS_TYPE_MASK | CONT_GCN_WIRELESS_ID)


#define CONT_EEPROM             0x8000
#define CONT_EEP16K             0x4000

#define CONT_TYPE_NULL          (0xFFFF)
#define CONT_TYPE_UNKNOWN       (0x0000)
// N64:
#define	CONT_TYPE_NORMAL        (0x0000 | CONT_CONSOLE_N64 | CONT_ABSOLUTE | CONT_JOYPORT) // 0x0005
#define	CONT_TYPE_MOUSE         (0x0000 | CONT_CONSOLE_N64 | CONT_RELATIVE) // 0x0002
#define	CONT_TYPE_VOICE         (0x0100 | CONT_CONSOLE_N64) // 0x0100
#define CONT_TYPE_KEYBOARD      (0x0200 | CONT_CONSOLE_N64) // 0x0200
#define CONT_TYPE_DANCEPAD      CONT_TYPE_NORMAL
#define CONT_TYPE_DENSHA        CONT_TYPE_NORMAL
#define CONT_TYPE_FISHING       CONT_TYPE_NORMAL
// GBA:
#define CONT_TYPE_64GB          (0x0003) // 0x0003
#define CONT_TYPE_GBA           (0x0400) // 0x0400
// Gamecube:
#define CONT_TYPE_GCN_NORMAL    (0x0000 | CONT_CONSOLE_GCN | CONT_GCN_STANDARD) // 0x0009
#define CONT_TYPE_GCN_RECEIVER  (0x0000 | CONT_CONSOLE_GCN | CONT_GCN_WIRELESS) // 0x0088
#define CONT_TYPE_GCN_WAVEBIRD  (0x0000 | CONT_CONSOLE_GCN | CONT_GCN_WIRELESS | CONT_GCN_STANDARD | CONT_GCN_WIRELESS_STATE_FIXED | CONT_GCN_WIRELESS_FIX_ID) // 0x108B
#define CONT_TYPE_GCN_WHEEL     (0x0000 | CONT_CONSOLE_GCN) // 0x0008
#define CONT_TYPE_GCN_KEYBOARD  (0x2000 | CONT_CONSOLE_GCN) // 0x2008
#define CONT_TYPE_GCN_DANCEPAD  (0x0800 | CONT_CONSOLE_GCN | CONT_GCN_STANDARD) // 0x0808
#define CONT_TYPE_GCN_DKONGAS   CONT_TYPE_GCN_NORMAL

/* Controller status */

#define CONT_CARD_ON            0x01
#define CONT_CARD_PULL          0x02
#define CONT_ADDR_CRC_ER        0x04
#define CONT_EEPROM_BUSY        0x80

/* Buttons */

#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G      0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_RESET  0x0080
#define CONT_UNUSED 0x0040
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001

/* Nintendo's official button names */

#define A_BUTTON        CONT_A      // 0x8000
#define B_BUTTON        CONT_B      // 0x4000
#define X_BUTTON        CONT_RESET  // 0x0080
#define Y_BUTTON        CONT_UNUSED // 0x0040
#define L_TRIG          CONT_L      // 0x0020
#define R_TRIG          CONT_R      // 0x0010
#define Z_TRIG          CONT_G      // 0x2000
#define START_BUTTON    CONT_START  // 0x1000
#define U_JPAD          CONT_UP     // 0x0800
#define L_JPAD          CONT_LEFT   // 0x0200
#define R_JPAD          CONT_RIGHT  // 0x0100
#define D_JPAD          CONT_DOWN   // 0x0400
#define U_CBUTTONS      CONT_E      // 0x0008
#define L_CBUTTONS      CONT_C      // 0x0002
#define R_CBUTTONS      CONT_F      // 0x0001
#define D_CBUTTONS      CONT_D      // 0x0004

/* Gamecube controller buttons */

#define CONT_GCN_ERRSTAT     0x8000
#define CONT_GCN_ERRLATCH    0x4000
#define CONT_GCN_GET_ORIGIN  0x2000
#define CONT_GCN_START       0x1000
#define CONT_GCN_Y           0x0800
#define CONT_GCN_X           0x0400
#define CONT_GCN_B           0x0200
#define CONT_GCN_A           0x0100
#define CONT_GCN_USE_ORIGIN  0x0080
#define CONT_GCN_L           0x0040
#define CONT_GCN_R           0x0020
#define CONT_GCN_Z           0x0010
#define CONT_GCN_UP          0x0008
#define CONT_GCN_DOWN        0x0004
#define CONT_GCN_RIGHT       0x0002
#define CONT_GCN_LEFT        0x0001

/* Controller error number */

#define	CONT_ERR_NO_CONTROLLER		PFS_ERR_NOPACK 		/* 1 */
#define	CONT_ERR_CONTRFAIL		CONT_OVERRUN_ERROR	/* 4 */
#define	CONT_ERR_INVALID		PFS_ERR_INVALID		/* 5 */
#define	CONT_ERR_DEVICE			PFS_ERR_DEVICE 		/* 11 */
#define	CONT_ERR_NOT_READY		12
#define	CONT_ERR_VOICE_MEMORY		13
#define	CONT_ERR_VOICE_WORD		14
#define	CONT_ERR_VOICE_NO_RESPONSE	15


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Controller interface */

extern s32		osContInit(         OSMesgQueue *mq, u8 *bitpattern, OSContStatus *status);
extern s32		osContReset(        OSMesgQueue *mq,                 OSContStatus *status);
extern s32		osContStartQuery(   OSMesgQueue *mq);
extern s32		osContStartReadData(OSMesgQueue *mq);
extern s32		osContStartReadDataEx(OSMesgQueue *mq);
#ifndef _HW_VERSION_1
extern s32		osContSetCh(u8 ch);
#endif
extern void		osContGetQuery(OSContStatus *status);
extern void		osContGetQueryEx(u8 *bitpattern, OSContStatus *status);
extern void		osContGetReadData(OSContPad *pad);
extern void		osContGetReadDataEx(OSContPadEx *pad);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_CONT_H_ */
