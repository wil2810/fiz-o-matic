/****************************************************
   FIZ-o-Matic Hardware configuration
   for detailed informations see
   https://github.com/brvdg/busputer/wiki
****************************************************/



#ifdef OLED
#define ENABLE_DISPLAY
#define U8G2_DISPLAY
#define DSP_PWRSAVE
#define DISPLAY_CS 11
#define DISPLAY_DC 12
#define DISPLAY_RST 10
#endif

#ifdef OLEDFULL
#define ENABLE_DISPLAY
#define U8G2_DISPLAY
#define DSP_PWRSAVE
#define DISPLAY_CS 11
#define DISPLAY_DC 12
#define DISPLAY_RST 10
#endif

#if defined DOGS102
#define ENABLE_DISPLAY
#define U8G2_DISPLAY
#define DISPLAY_BG_LED 10
#define DISPLAY_CS 11
#define DISPLAY_DC 12
#endif

#if defined ST7735
#define ENABLE_DISPLAY
#define DISPLAY_CS 10
#define DISPLAY_DC 12
#define DISPLAY_RST 11
#endif

#if defined TOUCHBUTTON
#define BUTTON_PRESSED HIGH
bool no_long_press = true;
#else
#define BUTTON_PRESSED LOW
bool no_long_press = false;
#endif

#if defined HW_TRINKET
/*
   analog input multiplicator
   A0/A1 range 0-15.6V
   15.6 / 1024 = 0.015234
   A2/A3 range 0-10V
   10 / 1024 = 0.009765
*/
#define A0_MULTIPLICATOR 0.015234


#endif //HW_TRINKET

#if defined HW_FEATHER
#define TinyGSM
// enable SD card
//#define SDCARD
//#define SD_CS 4
#define SDU

// LED on Feather board for running status
#define FeatherLED8 8

#if defined TinyGSM
// TinyGSM Reset
#define TinyGSM_PWRKEY 5
#endif

/*
   analog input multiplicator
   A0/A1 range 0-15.6V
   15.6 / 1024 = 0.015234
   A2/A3 range 0-10V
   10 / 1024 = 0.009765
*/
#define A0_MULTIPLICATOR 0.015234
#define A1_MULTIPLICATOR 0.015234
#define A2_MULTIPLICATOR 0.009765
#define A3_MULTIPLICATOR 0.009765
#define A5_MULTIPLICATOR 0.015234

// digital Ports
#define A4_COUNTER
//#define A5_COUNTER

#define GPIO6
#define GPIO13

#endif //HW_FEATHER




#if defined (DOGS102) && defined (OLED)
#pragma message ( "Only one display can be configured" )
#error "Only one display can be configured"
#endif

//#if defined (U8G2_DISPLAY_BG_LED) && defined (OLED)
//#pragma message ( "U8G2_DISPLAY_BG_LED and OLDE can't used together" )
//#error "U8G2_DISPLAY_BG_LED and OLED can't used together"
//#endif
