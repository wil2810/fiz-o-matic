/*
 * Layout and Logo for
 * OLED with SH1106
 */

#ifdef SH1106

U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ DISPLAY_CS, /* dc=*/ DISPLAY_DC, /* reset=*/ DISPLAY_RST);


#define small_font u8g2_font_profont10_tf
#define small_font_high 8
#define medium_font u8g2_font_profont12_tf
#define medium_font_high 10
#define big_font u8g2_font_profont29_tn
#define big_font_high 24



//Menu defination
//#define MENU_clock 1
//#define MENU_speed 2
//#define MENU_temp 3
//#define MENU_fuel 4
//#define MENU_oil_temp 5
//#define MENU_oil_pressure 6
//#define MENU_batt1_voltage 7
//#define MENU_batt2_voltage 8
//#define MENU_bord_voltage 9
//#define MENU_altitude 10
//#define MENU_rpm 11
//#define MENU_gps 12


#define LAYOUT_CLOCK_1 24, 16
#define LAYOUT_CLOCK_2 46, 40


#define LAYOUT1_1_X 128/2 + 0 - 40
#define LAYOUT1_1_Y 48/2 + 16 - 24/2 - 12
#define LAYOUT1_2_X LAYOUT1_1_X
#define LAYOUT1_2_Y LAYOUT1_1_Y + big_font_high

#define MACRO_DISPLAY_VALUE(DESC, VALUE, DIGITS, SUFFIX) ({\
  u8g2.setFont(small_font);\
  u8g2.setFontPosTop();\
  u8g2.setCursor(0, 16);\
  u8g2.print(F(DESC));\
  u8g2.setCursor(0, 32);\
  u8g2.setFont(big_font);\
  u8g2.setCursor(0, 32);\
  if ( VALUE <= 10 ) {\
    u8g2.print(F("   "));\
  }\
  else if ( VALUE <= 100 ) {\
    u8g2.print(F("  "));\
  }\
  else if ( VALUE <= 1000 ) {\
    u8g2.print(F(" "));\
  }\
  if ( DIGITS != 1 ) {\
    u8g2.print(F("  "));\
  }\
  u8g2.print(VALUE,DIGITS);\
  u8g2.setFont(medium_font);\
  u8g2.setCursor(98, 32);\
  u8g2.print(F(SUFFIX));\
 })

#define LOGO_width 120
#define LOGO_height 62
#define LOGO_Xpos 0
#define LOGO_Ypos 0
static const unsigned char logo[] U8X8_PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1c, 0x38, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
  0x0a, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xf0, 0x03, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x73, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x8f, 0x3b, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb8,
  0xcf, 0x39, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x38, 0xc7, 0x3d, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xc7, 0x9d, 0xc0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0xe7, 0x8c, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x1c,
  0xe7, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7f, 0x9c, 0xe3, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x73, 0x9e, 0xf3, 0x30, 0x60, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x71, 0x8e, 0xf3, 0x1d, 0x60,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe3, 0x38, 0xce,
  0xf3, 0x0f, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
  0xe3, 0x38, 0xce, 0xe9, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xfe, 0xe3, 0x38, 0xc7, 0x0f, 0x00, 0x38, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x73, 0x1c, 0xe7, 0x07, 0x00, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb8, 0xcf, 0x71, 0x9c, 0xdf,
  0x01, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xcf,
  0x79, 0x9c, 0x1f, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x78, 0xce, 0x39, 0x7c, 0x0f, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x38, 0xe7, 0x39, 0x7e, 0x00, 0x00, 0xe0, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xe7, 0x38, 0x3f, 0x00,
  0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x38, 0xe7,
  0xfc, 0x0d, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
  0x00, 0x9c, 0xe3, 0xfe, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xee, 0x80, 0x9c, 0xf3, 0x33, 0x00, 0x00, 0xf8, 0x1f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0xf0, 0x9c, 0xf3, 0x01, 0x00, 0x00,
  0xff, 0x07, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0xe7, 0xf8, 0x8e, 0xf3,
  0x00, 0x00, 0xf0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x80, 0xe3,
  0x38, 0xce, 0x07, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x30, 0x0e,
  0x30, 0x80, 0xf3, 0x04, 0xce, 0x03, 0x00, 0xf8, 0xff, 0x1f, 0x00, 0x00,
  0x00, 0x7c, 0x0e, 0x1e, 0xc0, 0x71, 0x00, 0x1e, 0x00, 0xc0, 0xff, 0xff,
  0x03, 0x00, 0x00, 0x00, 0x46, 0xc0, 0x1f, 0xc0, 0x71, 0x00, 0x1e, 0x00,
  0xfe, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x77, 0xe0, 0x1e, 0xc8, 0x71,
  0x00, 0x06, 0xe0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x80, 0x7b, 0x02,
  0x0f, 0xee, 0x39, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00,
  0x80, 0xbb, 0x87, 0x87, 0xe7, 0x18, 0x00, 0xc0, 0xff, 0xff, 0x3f, 0x00,
  0x00, 0x00, 0x00, 0xc0, 0xbd, 0xc7, 0xc3, 0xe3, 0x1c, 0x00, 0xf8, 0xff,
  0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdd, 0xc3, 0x41, 0xe0, 0x0c,
  0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xcd, 0xe3,
  0x00, 0xe0, 0x07, 0xe0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xe0, 0xa0, 0x73, 0x00, 0xc0, 0x01, 0xf8, 0xff, 0xff, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xe0, 0xb0, 0xf3, 0x07, 0x00, 0x00, 0xfe, 0xff, 0x7f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xdc, 0xf1, 0x07, 0x00, 0x80,
  0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xc7, 0x99,
  0x07, 0x00, 0xe0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf0, 0xe1, 0x89, 0x07, 0x00, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x70, 0xe1, 0x94, 0x07, 0x00, 0xfc, 0xff, 0x3f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xe1, 0xbf, 0x03, 0x00, 0xff,
  0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xe1, 0x9f,
  0x03, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x38, 0xf1, 0xdd, 0x01, 0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xb8, 0xe1, 0xde, 0x01, 0xe0, 0xff, 0x3f, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x01, 0xce, 0x00, 0xf0, 0xff,
  0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x00, 0x62,
  0x00, 0xf8, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x9c, 0x00, 0x32, 0x00, 0xfc, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xce, 0x00, 0x1e, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00,
  0x80, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3e, 0x00, 0x00, 0x80, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0xc0, 0xff, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0xe0, 0x03, 0x0e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
  0x60, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif
