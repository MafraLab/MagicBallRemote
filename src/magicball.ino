#define DELAY_100_US         (100)               /* DelayCount value for delay of 100 micro seconds. */
#define DELAY_500_MS         (500)           /* DelayCount value for delay of 500 milliseconds. */

#define DELAY_4625           (4625)        /* Delay of 4625 microseconds. */
#define DELAY_1325           (1325)         /* Delay of 1325 microseconds. */
#define DELAY_675            (675)         /* Delay of 675 microseconds. */
#define DELAY_17             (17)                /* Delay of 17 microseconds. */

#define DELAY_KEY            (DELAY_500_MS)      /* Delay in between 2 different keys. */
#define DELAY_IDENTICAL_KEY  (DELAY_500_MS * 6)  /* Delay in between 2 identical keys. */

#define CLR(x,y) (x&=(~(1<<y)))

#define SET(x,y) (x|=(1<<y))

/*
** Definitions for emulating IR remote control keys.
** Whenever a key is pressed on the remote control then a sequence of 200 pulses is transmitted.
** The sequence is transmitted in blocks of 20 pulses with pauses in between the block:
**
**   Block P0 Block P1 Block P2 Block P3 Block P4 Block P5 Block P6 Block P7 Block P8 Block
**
**   where as:
**
**      P0 = 4625 microseconds (fixed, same for each key)
**      P1 = 1325 microseconds (fixed, same for each key)
**      P2 - P8 = either 0, 675 or 1325 microseconds.
**
**   The actual pause P2 - P8 determines the key that was pressed.
**   We encode the P2 - P8 in the following structure, using the following symbols:
**      0 = 0 microseconds pause.
**      1 = 675 microseconds pause.
**      2 = 1325 microseconds pause.
**      3 = 4625 microseconds pause.
**
*/
#define IR_KEYS                        (50)                /* Total number of keys on remote control. */
#define IR_PULSE_BLOCKS                (10)                /* Total number of pulse blocks. */
#define IR_PULSES_PER_BLOCK            (20)                /* Total number of pulses per pulse block. */
#define IR_MAX_KEY_SEQUENCE_LENGTH     (4)                 /* Maximum number of keys in a key sequence. */

/* Identifiers for remote control keys - used as index into IRKeyTable */
#define IR_KEY_F1       (0)           /* 'F1' key. */
#define IR_KEY_F2       (1)           /* 'F2' key. */
#define IR_KEY_F3       (2)           /* 'F3' key. */
#define IR_KEY_F4       (3)           /* 'F4' key. */
#define IR_KEY_F5       (4)           /* 'F5' key. */
#define IR_KEY_1        (5)           /* '1' key. */
#define IR_KEY_2        (6)           /* '2' key. */
#define IR_KEY_3        (7)           /* '3' key. */
#define IR_KEY_4        (8)           /* '4' key. */
#define IR_KEY_5        (9)           /* '5' key. */
#define IR_KEY_6        (10)          /* '6' key. */
#define IR_KEY_7        (11)          /* '7' key. */
#define IR_KEY_8        (12)          /* '8' key. */
#define IR_KEY_9        (13)          /* '9' key. */
#define IR_KEY_0        (14)          /* '0' key. */
#define IR_KEY_A        (15)          /* 'a' key. */
#define IR_KEY_B        (16)          /* 'b' key. */
#define IR_KEY_C        (17)          /* 'c' key. */
#define IR_KEY_D        (18)          /* 'd' key. */
#define IR_KEY_E        (19)          /* 'e' key. */
#define IR_KEY_F        (20)          /* 'f' key. */
#define IR_KEY_G        (21)          /* 'g' key. */
#define IR_KEY_H        (22)          /* 'h' key. */
#define IR_KEY_I        (23)          /* 'i' key. */
#define IR_KEY_J        (24)          /* 'j' key. */
#define IR_KEY_K        (25)          /* 'k' key. */
#define IR_KEY_L        (26)          /* 'l' key. */
#define IR_KEY_M        (27)          /* 'm' key. */
#define IR_KEY_N        (28)          /* 'n' key. */
#define IR_KEY_O        (29)          /* 'o' key. */
#define IR_KEY_P        (30)          /* 'p' key. */
#define IR_KEY_Q        (31)          /* 'q' key. */
#define IR_KEY_R        (32)          /* 'r' key. */
#define IR_KEY_S        (33)          /* 's' key. */
#define IR_KEY_T        (34)          /* 't' key. */
#define IR_KEY_U        (35)          /* 'u' key. */
#define IR_KEY_V        (36)          /* 'v' key. */
#define IR_KEY_W        (37)          /* 'w' key. */
#define IR_KEY_X        (38)          /* 'x' key. */
#define IR_KEY_Y        (39)          /* 'y' key. */
#define IR_KEY_Z        (40)          /* 'z' key. */
#define IR_KEY_SPACE    (41)          /* 'Space' key. */
#define IR_KEY_CAPS     (42)          /* 'Caps' key. */
#define IR_KEY_2ND      (43)          /* '2nd' key. */
#define IR_KEY_3RD      (44)          /* '3rd' key. */
#define IR_KEY_EDITOR   (45)          /* 'Editor' key. */
#define IR_KEY_INSERT   (46)          /* 'Insert' key. */
#define IR_KEY_BACK     (47)          /* 'Back' key. */
#define IR_KEY_ADV      (48)          /* 'Adv' key. */
#define IR_KEY_DELETE   (49)          /* 'Delete' key. */

/*============================================== External function declarations ==============================================*/

/*============================================== External data declarations ==================================================*/

/*============================================== Local macro definitions =====================================================*/

/* Lookup table for IR transmission pauses per key. */
const unsigned int IRKeyTable[IR_KEYS][IR_PULSE_BLOCKS] =
{
   /* F1 */        { 3, 2, 1, 1, 1, 1, 1, 1, 0, },         /* Key 0 */
   /* F2 */        { 3, 2, 1, 1, 1, 1, 1, 2, 0, },
   /* F3 */        { 3, 2, 1, 1, 1, 1, 1, 0, 1, },
   /* F4 */        { 3, 2, 1, 1, 1, 1, 0, 2, 1, },
   /* F5 */        { 3, 2, 1, 1, 1, 1, 0, 2, 0, },

   /* 1 */         { 3, 2, 1, 0, 1, 2, 1, 1, 0, },
   /* 2 */         { 3, 2, 1, 0, 1, 2, 1, 0, 2, },
   /* 3 */         { 3, 2, 1, 0, 1, 2, 1, 0, 1, },
   /* 4 */         { 3, 2, 1, 0, 1, 2, 0, 2, 1, },
   /* 5 */         { 3, 2, 1, 0, 1, 2, 0, 2, 0, },

   /* 6 */         { 3, 2, 1, 0, 1, 2, 0, 1, 2, },
   /* 7 */         { 3, 2, 1, 0, 1, 2, 0, 1, 1, },
   /* 8 */         { 3, 2, 1, 0, 1, 1, 2, 1, 1, },
   /* 9 */         { 3, 2, 1, 0, 1, 1, 2, 1, 0, },
   /* 0 */         { 3, 2, 1, 0, 1, 2, 1, 1, 1, },

   /* a */         { 3, 2, 0, 2, 1, 1, 1, 1, 0, },
   /* b */         { 3, 2, 0, 2, 1, 1, 1, 0, 2, },
   /* c */         { 3, 2, 0, 2, 1, 1, 1, 0, 1, },
   /* d */         { 3, 2, 0, 2, 1, 1, 0, 2, 1, },
   /* e */         { 3, 2, 0, 2, 1, 1, 0, 2, 0, },

   /* f */         { 3, 2, 0, 2, 1, 1, 0, 1, 2, },
   /* g */         { 3, 2, 0, 2, 1, 1, 0, 1, 1, },
   /* h */         { 3, 2, 0, 2, 1, 0, 2, 1, 1, },
   /* i */         { 3, 2, 0, 2, 1, 0, 2, 1, 0, },
   /* j */         { 3, 2, 0, 2, 1, 0, 2, 0, 2, },

   /* k */         { 3, 2, 0, 2, 1, 0, 2, 0, 1, },
   /* l */         { 3, 2, 0, 2, 1, 0, 1, 2, 1, },
   /* m */         { 3, 2, 0, 2, 1, 0, 1, 2, 0, },
   /* n */         { 3, 2, 0, 2, 1, 0, 1, 1, 2, },
   /* o */         { 3, 2, 0, 2, 1, 0, 1, 1, 1, },

   /* p */         { 3, 2, 0, 2, 0, 2, 1, 1, 1, },
   /* q */         { 3, 2, 0, 2, 0, 2, 1, 1, 0, },
   /* r */         { 3, 2, 0, 2, 0, 2, 1, 0, 2, },
   /* s */         { 3, 2, 0, 2, 0, 2, 1, 0, 1, },
   /* t */         { 3, 2, 0, 2, 0, 2, 0, 2, 1, },

   /* u */         { 3, 2, 0, 2, 0, 2, 0, 2, 0, },
   /* v */         { 3, 2, 0, 2, 0, 2, 0, 1, 2, },
   /* w */         { 3, 2, 0, 2, 0, 2, 0, 1, 1, },
   /* x */         { 3, 2, 0, 2, 0, 1, 2, 1, 1, },
   /* y */         { 3, 2, 0, 2, 0, 1, 2, 1, 0, },

   /* z */         { 3, 2, 0, 2, 0, 1, 2, 0, 2, },
   /* Space */     { 3, 2, 1, 0, 2, 1, 1, 1, 1, },
   /* Caps */      { 3, 2, 1, 0, 2, 1, 1, 1, 0, },
   /* 2nd */       { 3, 2, 1, 0, 2, 1, 1, 0, 2, },
   /* 3rd */       { 3, 2, 1, 0, 2, 1, 1, 0, 1, },

   /* Editor */    { 3, 2, 1, 0, 2, 1, 0, 2, 1, },
   /* Insert */    { 3, 2, 1, 0, 2, 1, 0, 2, 0, },
   /* Back */      { 3, 2, 1, 0, 2, 1, 0, 1, 2, },
   /* Adv */       { 3, 2, 1, 0, 2, 1, 0, 1, 1, },
   /* Delete */    { 3, 2, 1, 0, 2, 0, 2, 1, 1, },         /* Key 49 */
};

/*
** Conversion table for converting ASCII code into IR key sequence.
** Value 0xFF is used to indicate no key.
** Not supported codes are translated into space character (0x20).
*/
const unsigned int ASCIIToIRKeyTable[256][IR_MAX_KEY_SEQUENCE_LENGTH] =
{
   /* 0x00 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x01 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x02 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x03 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x04 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x05 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF,},                 /* -not supported character- */
   /* 0x06 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x07 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x08 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x09 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x0A */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x0B */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x0C */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x0D */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x0E */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x0F */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */

   /* 0x10 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x11 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x12 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x13 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x14 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x15 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x16 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x17 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x18 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x19 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x1A */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x1B */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x1C */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x1D */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x1E */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x1F */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */

   /* 0x20 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },
   /* 0x21 */   { IR_KEY_2ND, IR_KEY_SPACE, 0xFF, 0xFF, },           /* ! */
   /* 0x22 */   { IR_KEY_2ND, IR_KEY_U, 0xFF, 0xFF, },               /* " */
   /* 0x23 */   { IR_KEY_2ND, IR_KEY_Y, 0xFF, 0xFF, },               /* # */
   /* 0x24 */   { IR_KEY_3RD, IR_KEY_A, 0xFF, 0xFF, },               /* $ */
   /* 0x25 */   { IR_KEY_2ND, IR_KEY_W, 0xFF, 0xFF, },               /* % */
   /* 0x26 */   { IR_KEY_2ND, IR_KEY_X, 0xFF, 0xFF, },               /* & */
   /* 0x27 */   { IR_KEY_2ND, IR_KEY_P, 0xFF, 0xFF, },               /* ' */
   /* 0x28 */   { IR_KEY_2ND, IR_KEY_B, 0xFF, 0xFF, },               /* ( */
   /* 0x29 */   { IR_KEY_2ND, IR_KEY_C, 0xFF, 0xFF, },               /* ) */
   /* 0x2A */   { IR_KEY_2ND, IR_KEY_N, 0xFF, 0xFF, },               /* * */
   /* 0x2B */   { IR_KEY_2ND, IR_KEY_K, 0xFF, 0xFF, },               /* + */
   /* 0x2C */   { IR_KEY_2ND, IR_KEY_Q, 0xFF, 0xFF, },               /* , */
   /* 0x2D */   { IR_KEY_2ND, IR_KEY_L, 0xFF, 0xFF, },               /* - */
   /* 0x2E */   { IR_KEY_2ND, IR_KEY_T, 0xFF, 0xFF, },               /* . */
   /* 0x2F */   { IR_KEY_2ND, IR_KEY_H, 0xFF, 0xFF, },               /* / */

   /* 0x30 */   { IR_KEY_0,  0xFF, 0xFF, 0xFF, },
   /* 0x31 */   { IR_KEY_1,  0xFF, 0xFF, 0xFF, },
   /* 0x32 */   { IR_KEY_2,  0xFF, 0xFF, 0xFF, },
   /* 0x33 */   { IR_KEY_3,  0xFF, 0xFF, 0xFF, },
   /* 0x34 */   { IR_KEY_4,  0xFF, 0xFF, 0xFF, },
   /* 0x35 */   { IR_KEY_5,  0xFF, 0xFF, 0xFF, },
   /* 0x36 */   { IR_KEY_6,  0xFF, 0xFF, 0xFF, },
   /* 0x37 */   { IR_KEY_7,  0xFF, 0xFF, 0xFF, },
   /* 0x38 */   { IR_KEY_8,  0xFF, 0xFF, 0xFF, },
   /* 0x39 */   { IR_KEY_9,  0xFF, 0xFF, 0xFF, },
   /* 0x3A */   { IR_KEY_2ND, IR_KEY_R, 0xFF, 0xFF, },               /* : */
   /* 0x3B */   { IR_KEY_2ND, IR_KEY_S, 0xFF, 0xFF, },               /* ; */
   /* 0x3C */   { IR_KEY_2ND, IR_KEY_I, 0xFF, 0xFF, },               /* < */
   /* 0x3D */   { IR_KEY_2ND, IR_KEY_O, 0xFF, 0xFF, },               /* = */
   /* 0x3E */   { IR_KEY_2ND, IR_KEY_J, 0xFF, 0xFF, },               /* > */
   /* 0x3F */   { IR_KEY_2ND, IR_KEY_Z, 0xFF, 0xFF, },               /* ? */

   /* 0x40 */   { IR_KEY_2ND, IR_KEY_V, 0xFF, 0xFF, },               /* @ */
   /* 0x41 */   { IR_KEY_CAPS, IR_KEY_A, 0xFF, 0xFF, },
   /* 0x42 */   { IR_KEY_CAPS, IR_KEY_B, 0xFF, 0xFF, },
   /* 0x43 */   { IR_KEY_CAPS, IR_KEY_C, 0xFF, 0xFF, },
   /* 0x44 */   { IR_KEY_CAPS, IR_KEY_D, 0xFF, 0xFF, },
   /* 0x45 */   { IR_KEY_CAPS, IR_KEY_E, 0xFF, 0xFF, },
   /* 0x46 */   { IR_KEY_CAPS, IR_KEY_F, 0xFF, 0xFF, },
   /* 0x47 */   { IR_KEY_CAPS, IR_KEY_G, 0xFF, 0xFF, },
   /* 0x48 */   { IR_KEY_CAPS, IR_KEY_H, 0xFF, 0xFF, },
   /* 0x49 */   { IR_KEY_CAPS, IR_KEY_I, 0xFF, 0xFF, },
   /* 0x4A */   { IR_KEY_CAPS, IR_KEY_J, 0xFF, 0xFF, },
   /* 0x4B */   { IR_KEY_CAPS, IR_KEY_K, 0xFF, 0xFF, },
   /* 0x4C */   { IR_KEY_CAPS, IR_KEY_L, 0xFF, 0xFF, },
   /* 0x4D */   { IR_KEY_CAPS, IR_KEY_M, 0xFF, 0xFF, },
   /* 0x4E */   { IR_KEY_CAPS, IR_KEY_N, 0xFF, 0xFF, },
   /* 0x4F */   { IR_KEY_CAPS, IR_KEY_O, 0xFF, 0xFF, },

   /* 0x50 */   { IR_KEY_CAPS, IR_KEY_P, 0xFF, 0xFF, },
   /* 0x51 */   { IR_KEY_CAPS, IR_KEY_Q, 0xFF, 0xFF, },
   /* 0x52 */   { IR_KEY_CAPS, IR_KEY_R, 0xFF, 0xFF, },
   /* 0x53 */   { IR_KEY_CAPS, IR_KEY_S, 0xFF, 0xFF, },
   /* 0x54 */   { IR_KEY_CAPS, IR_KEY_T, 0xFF, 0xFF, },
   /* 0x55 */   { IR_KEY_CAPS, IR_KEY_U, 0xFF, 0xFF, },
   /* 0x56 */   { IR_KEY_CAPS, IR_KEY_V, 0xFF, 0xFF, },
   /* 0x57 */   { IR_KEY_CAPS, IR_KEY_W, 0xFF, 0xFF, },
   /* 0x58 */   { IR_KEY_CAPS, IR_KEY_X, 0xFF, 0xFF, },
   /* 0x59 */   { IR_KEY_CAPS, IR_KEY_Y, 0xFF, 0xFF, },
   /* 0x5A */   { IR_KEY_CAPS, IR_KEY_Z, 0xFF, 0xFF, },
   /* 0x5B */   { IR_KEY_2ND, IR_KEY_D, 0xFF, 0xFF, },               /* [ */
   /* 0x5C */   { IR_KEY_2ND, IR_KEY_F, 0xFF, 0xFF, },               /* \ */
   /* 0x5D */   { IR_KEY_2ND, IR_KEY_E, 0xFF, 0xFF, },               /* [ */
   /* 0x5E */   { IR_KEY_2ND, IR_KEY_0, 0xFF, 0xFF, },               /* ^ */
   /* 0x5F */   { IR_KEY_3RD, IR_KEY_M, 0xFF, 0xFF, },               /* _ */

   /* 0x60 */   { IR_KEY_SPACE, 0xFF, 0xFF, 0xFF, },                 /* -not supported character- */
   /* 0x61 */   { IR_KEY_A,  0xFF, 0xFF, 0xFF, },
   /* 0x62 */   { IR_KEY_B,  0xFF, 0xFF, 0xFF, },
   /* 0x63 */   { IR_KEY_C,  0xFF, 0xFF, 0xFF, },
   /* 0x64 */   { IR_KEY_D,  0xFF, 0xFF, 0xFF, },
   /* 0x65 */   { IR_KEY_E,  0xFF, 0xFF, 0xFF, },
   /* 0x66 */   { IR_KEY_F,  0xFF, 0xFF, 0xFF, },
   /* 0x67 */   { IR_KEY_G,  0xFF, 0xFF, 0xFF, },
   /* 0x68 */   { IR_KEY_H,  0xFF, 0xFF, 0xFF, },
   /* 0x69 */   { IR_KEY_I,  0xFF, 0xFF, 0xFF, },
   /* 0x6A */   { IR_KEY_J,  0xFF, 0xFF, 0xFF, },
   /* 0x6B */   { IR_KEY_K,  0xFF, 0xFF, 0xFF, },
   /* 0x6C */   { IR_KEY_L,  0xFF, 0xFF, 0xFF, },
   /* 0x6D */   { IR_KEY_M,  0xFF, 0xFF, 0xFF, },
   /* 0x6E */   { IR_KEY_N,  0xFF, 0xFF, 0xFF, },
   /* 0x6F */   { IR_KEY_O,  0xFF, 0xFF, 0xFF, },

   /* 0x70 */   { IR_KEY_P,  0xFF, 0xFF, 0xFF, },
   /* 0x71 */   { IR_KEY_Q,  0xFF, 0xFF, 0xFF, },
   /* 0x72 */   { IR_KEY_R,  0xFF, 0xFF, 0xFF, },
   /* 0x73 */   { IR_KEY_S,  0xFF, 0xFF, 0xFF, },
   /* 0x74 */   { IR_KEY_T,  0xFF, 0xFF, 0xFF, },
   /* 0x75 */   { IR_KEY_U,  0xFF, 0xFF, 0xFF, },
   /* 0x76 */   { IR_KEY_V,  0xFF, 0xFF, 0xFF, },
   /* 0x77 */   { IR_KEY_W,  0xFF, 0xFF, 0xFF, },
   /* 0x78 */   { IR_KEY_X,  0xFF, 0xFF, 0xFF, },
   /* 0x79 */   { IR_KEY_Y,  0xFF, 0xFF, 0xFF, },
   /* 0x7A */   { IR_KEY_Z,  0xFF, 0xFF, 0xFF, },
   /* 0x7B */   { IR_KEY_3RD, IR_KEY_U, 0xFF, 0xFF, },               /* { */
   /* 0x7C */   { IR_KEY_2ND, IR_KEY_G, 0xFF, 0xFF, },               /* | */
   /* 0x7D */   { IR_KEY_3RD, IR_KEY_V, 0xFF, 0xFF, },               /* } */
   /* 0x7E */   { IR_KEY_3RD, IR_KEY_P, 0xFF, 0xFF, },               /* ~ */
   /* 0x7F */   { IR_KEY_F3, IR_KEY_0, 0xFF, 0xFF, },                /* Graphic: Magic Ball logo. */

   /* Extended ASCII characters. */

   /* 0x80 */   { IR_KEY_F3, IR_KEY_1, 0xFF, 0xFF, },                /* Graphic: Euro. */
   /* 0x81 */   { IR_KEY_F3, IR_KEY_2, 0xFF, 0xFF, },                /* Graphic: Bottle and glasses. */
   /* 0x82 */   { IR_KEY_2ND, IR_KEY_Q, 0xFF, 0xFF, },               /* , */
   /* 0x83 */   { IR_KEY_3RD, IR_KEY_S, 0xFF, 0xFF, },               /* Florin */
   /* 0x84 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x85 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF,},                 /* -not supported character- */
   /* 0x86 */   { IR_KEY_3RD, IR_KEY_Q, 0xFF, 0xFF, },               /* RIP */
   /* 0x87 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x88 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x89 */   { IR_KEY_3RD, IR_KEY_W, 0xFF, 0xFF, },               /* Promille */
   /* 0x8A */   { IR_KEY_3RD, IR_KEY_0, IR_KEY_CAPS, IR_KEY_S, },    /* S with ^ */
   /* 0x8B */   { IR_KEY_3RD, IR_KEY_G, 0xFF, 0xFF, },               /* Small < */
   /* 0x8C */   { IR_KEY_3RD, IR_KEY_6, IR_KEY_CAPS, IR_KEY_O, },    /* OE */
   /* 0x8D */   { IR_KEY_F3, IR_KEY_3, 0xFF, 0xFF, },                /* Graphic: Arrow right. */
   /* 0x8E */   { IR_KEY_F3, IR_KEY_4, 0xFF, 0xFF, },                /* Graphic: Arrow left. */
   /* 0x8F */   { IR_KEY_F3, IR_KEY_5, 0xFF, 0xFF, },                /* Graphic: House. */

   /* 0x90 */   { IR_KEY_F3, IR_KEY_6, 0xFF, 0xFF, },                /* Graphic: Aeroplane. */
   /* 0x91 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x92 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x93 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x94 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x95 */   { IR_KEY_F3, IR_KEY_7, 0xFF, 0xFF, },                /* Graphic: Car. */
   /* 0x96 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x97 */   { IR_KEY_3RD, IR_KEY_O, 0xFF, 0xFF, },               /* - */
   /* 0x98 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0x99 */   { IR_KEY_3RD, IR_KEY_E, 0xFF, 0xFF, },               /* Tm */
   /* 0x9A */   { IR_KEY_3RD, IR_KEY_0, IR_KEY_S, 0xFF},             /* s with ^ */
   /* 0x9B */   { IR_KEY_3RD, IR_KEY_H, 0xFF, 0xFF, },               /* Small > */
   /* 0x9C */   { IR_KEY_3RD, IR_KEY_6, IR_KEY_O, 0xFF, },           /* oe */
   /* 0x9D */   { IR_KEY_F3, IR_KEY_8, 0xFF, 0xFF, },                /* Graphic: Heart. */
   /* 0x9E */   { IR_KEY_F3, IR_KEY_9, 0xFF, 0xFF, },                /* Graphic: Tree. */
   /* 0x9F */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_CAPS, IR_KEY_Y, },    /* Y with .. */

   /* 0xA0 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xA1 */   { IR_KEY_3RD, IR_KEY_SPACE, 0xFF, 0xFF, },           /* ! upside down */
   /* 0xA2 */   { IR_KEY_3RD, IR_KEY_7, IR_KEY_C, 0xFF},             /* Dollar cent */
   /* 0xA3 */   { IR_KEY_3RD, IR_KEY_F, 0xFF, 0xFF, },               /* Pound */
   /* 0xA4 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xA5 */   { IR_KEY_3RD, IR_KEY_H, 0xFF, 0xFF, },               /* Yen */
   /* 0xA6 */   { IR_KEY_SPACE, 0xFF, 0xFF, 0xFF, },                 /* -not supported character- */
   /* 0xA7 */   { IR_KEY_3RD, IR_KEY_B, 0xFF, 0xFF, },               /* Paragraph */
   /* 0xA8 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xA9 */   { IR_KEY_3RD, IR_KEY_C, 0xFF, 0xFF, },               /* Copyright */
   /* 0xAA */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xAB */   { IR_KEY_3RD, IR_KEY_I, 0xFF, 0xFF, },               /* << */
   /* 0xAC */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xAD */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xAE */   { IR_KEY_3RD, IR_KEY_D, 0xFF, 0xFF, },               /* Registered Trademark */
   /* 0xAF */   { IR_KEY_3RD, IR_KEY_M, 0xFF, 0xFF, },               /* - */

   /* 0xB0 */   { IR_KEY_2ND, IR_KEY_6, 0xFF, 0xFF, },               /* 0 (small) */
   /* 0xB1 */   { IR_KEY_2ND, IR_KEY_4, 0xFF, 0xFF, },               /* +- */
   /* 0xB2 */   { IR_KEY_2ND, IR_KEY_8, 0xFF, 0xFF, },               /* 2 (small) */
   /* 0xB3 */   { IR_KEY_2ND, IR_KEY_9, 0xFF, 0xFF, },               /* 3 (small) */
   /* 0xB4 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xB5 */   { IR_KEY_3RD, IR_KEY_T, 0xFF, 0xFF, },               /* Mu */
   /* 0xB6 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xB7 */   { IR_KEY_2ND, IR_KEY_5, 0xFF, 0xFF, },               /* 0 (small, filled) */
   /* 0xB8 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xB9 */   { IR_KEY_2ND, IR_KEY_7, 0xFF, 0xFF, },               /* 1 (small) */
   /* 0xBA */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xBB */   { IR_KEY_3RD, IR_KEY_J, 0xFF, 0xFF, },               /* >> */
   /* 0xBC */   { IR_KEY_2ND, IR_KEY_1, 0xFF, 0xFF, },               /* 1/4 */
   /* 0xBD */   { IR_KEY_2ND, IR_KEY_2, 0xFF, 0xFF, },               /* 1/2 */
   /* 0xBE */   { IR_KEY_2ND, IR_KEY_3, 0xFF, 0xFF, },               /* 3/4 */
   /* 0xBF */   { IR_KEY_3RD, IR_KEY_Z, 0xFF, 0xFF, },               /* ? upside down */

   /* 0xC0 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_CAPS, IR_KEY_A, },    /*  A with ` */
   /* 0xC1 */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_CAPS, IR_KEY_A, },    /*  A with ' */
   /* 0xC2 */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_CAPS, IR_KEY_A, },    /*  A with ^ */
   /* 0xC3 */   { IR_KEY_3RD, IR_KEY_5, IR_KEY_CAPS, IR_KEY_A, },    /*  A with ~ */
   /* 0xC4 */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_CAPS, IR_KEY_A, },    /*  A with .. */
   /* 0xC5 */   { IR_KEY_3RD, IR_KEY_8, IR_KEY_CAPS, IR_KEY_A, },    /*  A with small o */
   /* 0xC6 */   { IR_KEY_3RD, IR_KEY_6, IR_KEY_CAPS, IR_KEY_A, },    /*  AE */
   /* 0xC7 */   { IR_KEY_3RD, IR_KEY_9, IR_KEY_CAPS, IR_KEY_C, },    /*  C with , */
   /* 0xC8 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_CAPS, IR_KEY_E, },    /*  E with ` */
   /* 0xC9 */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_CAPS, IR_KEY_E, },    /*  E with ' */
   /* 0xCA */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_CAPS, IR_KEY_E, },    /*  E with ^ */
   /* 0xCB */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_CAPS, IR_KEY_E, },    /*  E with .. */
   /* 0xCC */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_CAPS, IR_KEY_I, },    /*  I with ` */
   /* 0xCD */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_CAPS, IR_KEY_I, },    /*  I with ' */
   /* 0xCE */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_CAPS, IR_KEY_I, },    /*  I with ^ */
   /* 0xCF */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_CAPS, IR_KEY_I, },    /*  I with .. */

   /* 0xD0 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },                /* -not supported character- */
   /* 0xD1 */   { IR_KEY_3RD, IR_KEY_5, IR_KEY_CAPS, IR_KEY_N, },    /*  N with ~ */
   /* 0xD2 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_CAPS, IR_KEY_O, },    /*  O with ` */
   /* 0xD3 */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_CAPS, IR_KEY_O, },    /*  O with ' */
   /* 0xD4 */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_CAPS, IR_KEY_O, },    /*  O with ^ */
   /* 0xD5 */   { IR_KEY_3RD, IR_KEY_5, IR_KEY_CAPS, IR_KEY_O, },    /*  O with ~ */
   /* 0xD6 */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_CAPS, IR_KEY_O, },    /*  O with .. */
   /* 0xD7 */   { IR_KEY_3RD, IR_KEY_K, 0xFF, 0xFF, },               /* x (small) */
   /* 0xD8 */   { IR_KEY_3RD, IR_KEY_7, IR_KEY_CAPS, IR_KEY_C, },    /* O with / */
   /* 0xD9 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_CAPS, IR_KEY_U, },    /*  U with ` */
   /* 0xDA */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_CAPS, IR_KEY_U, },    /*  U with ' */
   /* 0xDB */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_CAPS, IR_KEY_U, },    /*  U with ^ */
   /* 0xDC */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_CAPS, IR_KEY_U, },    /*  U with .. */
   /* 0xDD */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_CAPS, IR_KEY_Y, },    /*  Y with ' */
   /* 0xDE */   { IR_KEY_SPACE, 0xFF, 0xFF, 0xFF, },                 /* -not supported character- */
   /* 0xDF */   { IR_KEY_2ND, IR_KEY_A, 0xFF, 0xFF, },               /* Ringel S */

   /* 0xE0 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_A, 0xFF, },           /*  a with ` */
   /* 0xE1 */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_A, 0xFF, },           /*  a with ' */
   /* 0xE2 */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_A, 0xFF, },           /*  a with ^ */
   /* 0xE3 */   { IR_KEY_3RD, IR_KEY_5, IR_KEY_A, 0xFF, },           /*  a with ~ */
   /* 0xE4 */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_A, 0xFF, },           /*  a with .. */
   /* 0xE5 */   { IR_KEY_3RD, IR_KEY_8, IR_KEY_A, 0xFF, },           /*  a with small o */
   /* 0xE6 */   { IR_KEY_3RD, IR_KEY_6, IR_KEY_A, 0xFF, },           /*  ae */
   /* 0xE7 */   { IR_KEY_3RD, IR_KEY_9, IR_KEY_C, 0xFF, },           /*  c with , */
   /* 0xE8 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_E, 0xFF, },           /*  e with ` */
   /* 0xE9 */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_E, 0xFF, },           /*  e with ' */
   /* 0xEA */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_E, 0xFF, },           /*  e with ^ */
   /* 0xEB */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_E, 0xFF, },           /*  e with .. */
   /* 0xEC */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_I, 0xFF, },           /*  i with ` */
   /* 0xED */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_I, 0xFF, },           /*  i with ' */
   /* 0xEE */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_I, 0xFF, },           /*  i with ^ */
   /* 0xEF */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_I, 0xFF, },           /*  i with .. */

   /* 0xF0 */   { IR_KEY_SPACE,  0xFF, 0xFF, 0xFF, },
   /* 0xF1 */   { IR_KEY_3RD, IR_KEY_5, IR_KEY_N, 0xFF, },           /*  n with ~ */
   /* 0xF2 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_O, 0xFF, },           /*  o with ` */
   /* 0xF3 */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_O, 0xFF, },           /*  o with ' */
   /* 0xF4 */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_O, 0xFF, },           /*  o with ^ */
   /* 0xF5 */   { IR_KEY_3RD, IR_KEY_5, IR_KEY_O, 0xFF, },           /*  o with ~ */
   /* 0xF6 */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_O, 0xFF, },           /*  o with .. */
   /* 0xF7 */   { IR_KEY_2ND, IR_KEY_M, 0xFF, 0xFF, },               /* -: */
   /* 0xF8 */   { IR_KEY_3RD, IR_KEY_7, IR_KEY_C, 0xFF, },           /* o with / */
   /* 0xF9 */   { IR_KEY_3RD, IR_KEY_2, IR_KEY_U, 0xFF, },           /*  u with ` */
   /* 0xFA */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_U, 0xFF, },           /*  u with ' */
   /* 0xFB */   { IR_KEY_3RD, IR_KEY_4, IR_KEY_U, 0xFF, },           /*  u with ^ */
   /* 0xFC */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_U, 0xFF, },           /*  u with .. */
   /* 0xFD */   { IR_KEY_3RD, IR_KEY_3, IR_KEY_Y, 0xFF, },           /*  y with ' */
   /* 0xFE */   { IR_KEY_3RD, IR_KEY_Y, 0xFF, 0xFF, },               /* |) */
   /* 0xFF */   { IR_KEY_3RD, IR_KEY_1, IR_KEY_Y, 0xFF, },           /*  y with .. */
};



/*============================================== Function definitions ========================================================*/

/*
**------------------------------------------------------------------------------------------------------------------------------
**
** SYNTAX
**    void irTransmitKey(un8 key)
**
** DESCRIPTION
**    This function emulates the pressing of a key on the remote control by transmitting the IR sequence for that key.
**
** PARAMETERS
**    key
**       The identifier for the key. (value in range IR_KEY_F1 - IR_KEY_DELETE)
**
** RETURN VALUE
**
** NOTES
**
**------------------------------------------------------------------------------------------------------------------------------
*/
void irTransmitKey(unsigned int key)
{
   unsigned int *pntr;
   unsigned int block, pulse, i;
   unsigned long delay_count;

   delay_count = 0;
   for (i = 0; i < 2; i++)
   {
      pntr = ((unsigned int *) (IRKeyTable + key ));//* IR_PULSE_BLOCKS));
      for (block = 0; block < IR_PULSE_BLOCKS; block++)
      {
   
         for (pulse = 0; pulse < IR_PULSES_PER_BLOCK; pulse++)
         {
           
           SET(PORTB,5);                   /* IR LED on. */
           delayMicroseconds(17);
           
           
                CLR(PORTB,5);             /* IR LED off. */

            
            delayMicroseconds(15);
         }
      
         if (*pntr == 0)
         {
         }
         else if (*pntr == 1)
         {
                 delayMicroseconds(DELAY_675-5);
               
         }
         else if (*pntr == 2)
         {
                 delayMicroseconds(DELAY_1325-15);
               

         }
         else if (*pntr == 3)
         {
                     delayMicroseconds(DELAY_4625-55);
             
         }
         pntr++;
      }

      delayMicroseconds(DELAY_4625);
   }
}  

void setup()
{
  pinMode(13, OUTPUT);
  /*
  irTransmitKey(IR_KEY_F1);
  delay(500);
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_M);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_F);
  delay(500);
  irTransmitKey(IR_KEY_R);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_B);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_M);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_K);
  delay(500);
  irTransmitKey(IR_KEY_E);
  delay(500);
  irTransmitKey(IR_KEY_R);
  delay(500);
  irTransmitKey(IR_KEY_S);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_C);
  delay(500);
  irTransmitKey(IR_KEY_O);
  delay(500);
  irTransmitKey(IR_KEY_M);
  delay(500);
  irTransmitKey(IR_KEY_M);
  delay(500);
  irTransmitKey(IR_KEY_U);
  delay(500);
  irTransmitKey(IR_KEY_N);
  delay(500);
  irTransmitKey(IR_KEY_I);
  delay(500);
  irTransmitKey(IR_KEY_T);
  delay(500);
  irTransmitKey(IR_KEY_Y);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  irTransmitKey(IR_KEY_2ND);
  delay(500);
  irTransmitKey(IR_KEY_V);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_F);
  delay(500);
  irTransmitKey(IR_KEY_E);
  delay(500);
  irTransmitKey(IR_KEY_S);
  delay(500);
  irTransmitKey(IR_KEY_T);
  delay(500);
  irTransmitKey(IR_KEY_I);
  delay(500);
  irTransmitKey(IR_KEY_V);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_I);
  delay(500);
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_N);
  delay(500);
  irTransmitKey(IR_KEY_F1);
  delay(500);
  */
  
  

  delay(500);
 
  //Apaga();
 
  irTransmitKey(IR_KEY_CAPS);
  delay(500);
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_E);
  delay(500);
  irTransmitKey(IR_KEY_G);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_Y);
  delay(500);
  irTransmitKey(IR_KEY_R);
  delay(500);
  irTransmitKey(IR_KEY_I);
  delay(500);
  irTransmitKey(IR_KEY_C);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  
  irTransmitKey(IR_KEY_T);
  delay(500);
  irTransmitKey(IR_KEY_R);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_N);
  delay(500);
  irTransmitKey(IR_KEY_S);
  delay(500);
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_T);
  delay(500);
  irTransmitKey(IR_KEY_I);
  delay(500);
  irTransmitKey(IR_KEY_O);
  delay(500);
  irTransmitKey(IR_KEY_N);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  
  irTransmitKey(IR_KEY_T);
  delay(500);
  irTransmitKey(IR_KEY_R);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_D);
  delay(500);
  irTransmitKey(IR_KEY_U);
  delay(500);
  irTransmitKey(IR_KEY_Ç);
  delay(500);
  irTransmitKey(IR_KEY_3RD);
  delay(500);
  irTransmitKey(IR_KEY_5);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_O);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_E);
  delay(500);
  irTransmitKey(IR_KEY_G);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  
  irTransmitKey(IR_KEY_D);
  delay(500);
  irTransmitKey(IR_KEY_E);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  
  irTransmitKey(IR_KEY_L);
  delay(500);
  irTransmitKey(IR_KEY_E);
  delay(500);
  irTransmitKey(IR_KEY_T);
  delay(500);
  irTransmitKey(IR_KEY_R);
  delay(500);
  irTransmitKey(IR_KEY_A);
  delay(500);
  irTransmitKey(IR_KEY_S);
  delay(500);
  irTransmitKey(IR_KEY_SPACE);
  delay(500);
  
  delay(500);
    irTransmitKey(IR_KEY_2ND);
  delay(500);
  irTransmitKey(IR_KEY_F);
  delay(500);
 
   irTransmitKey(IR_KEY_F1);
  delay(500);
  
  
  delay(500);
  
  //
  delay(500);
  
  //Apaga();
}

void loop()
{
  
    
}

void Apaga()
{
  irTransmitKey(IR_KEY_F1);
  delay(500);
  
  for(int i = 0; i < 100; i++)
  {
    irTransmitKey(IR_KEY_DELETE);
    delay(500);
  }
  
  irTransmitKey(IR_KEY_F1);
  delay(500);
}

