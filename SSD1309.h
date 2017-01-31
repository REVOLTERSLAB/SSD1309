/**
 * @file	ssd1309.h
 * @author	Robert Steigemann
 * @date	18 June 2016
 * @brief	Header file of SSD1309 OLED Driver library.
 *
 * This library provides you high level functions to use an OLED Display with SSD1309 controller.
 * You have to configure this library in this header file with the used interface and pins.
 *
 * @license creative commons license CC BY-NC 4.0 http://creativecommons.org/licenses/by-nc/4.0/
 */

#ifndef SSD1309_H_
#define SSD1309_H_

/*#############################################################################
########################## select your interface here #########################
#############################################################################*/

//#define SSD1309_68XX		// 68XX 8-Bit interface, not implemented yet
//#define SSD1309_80XX		// 80XX 8-Bit interface, not implemented yet
#define	SSD1309_SPI			// SPI (5-Wire) interface, not tested


/*#############################################################################
######################### config 68XX here, if chosen #########################
#############################################################################*/

#ifdef SSD1309_68XX

// TODO

#endif


/*#############################################################################
######################## config 80XX here, if chosen ##########################
#############################################################################*/

#ifdef SSD1309_80XX

// TODO

#endif


/*#############################################################################
######################### config SPI here, if chosen ##########################
#############################################################################*/

#ifdef SSD1309_SPI

#define SSD1309_PORT	PORTC_OUT	// The used PORT
#define SSD1309_DIR		PORTC_DIR	// The corresponding DDR Register

#define SSD1309_SPI_I	SPIC		// the used SPI port

#define SSD1309_CS		4			// Serial Data Out (TXD)
#define SSD1309_DC		0			// Serial Clock Out (XCK)
#define SSD1309_RES		1			// Latch Signal (GPIO)
#define SSD1309_SCK		7			// Serial Clock
#define SSD1309_MOSI	5			// Master Out Display In

#endif


/*#############################################################################
############################# select display size #############################
#############################################################################*/

#define SSD1309_COL		128			
#define SSD1309_ROW		64


/*#############################################################################
########################### function prototypes ###############################
#############################################################################*/

/**
  * @brief  initialize the display
  *			This function will configure the SPI-Interface and initialize and clean the display.
  *			Have to be executed before any other display function.
  */
void ssd1309_init(void);

/**
  * @brief  clears the whole display by writing 0x00 to memory
  */
void ssd1309_clear(void);

/**
  * @brief  puts a single 5x7 char at specified position
  *
  * @param	aChar		the ASCII char to display (see font for available chars)
  * @param  page		the page (line) where the char is displayed
  * @param  startColumn	the column where the char starts
  */
void ssd1309_putc(unsigned char aChar, UINT8 page, UINT8 startColumn);

/**
  * @brief  puts a single 13x16 digit at specified position
  *
  * Only the following chars and white spaces are allowed: 0123456789,./+-
  *
  * @param	aDigit		the ASCII digit to display (see bigDigit for available chars)
  * @param  page		the upper page (line) where the char is displayed, char needs one more page below
  * @param  startColumn	the column where the char starts
  */
void ssd1309_putBigDigit(unsigned char aDigit, UINT8 page, UINT8 startColumn);

/**
  * @brief  prints a string at specified position
  *
  * @param	*aString	pointer to the string to print (0 terminated)
  * @param  page		the page (line) where the string is displayed
  * @param  startColumn	the column where the string starts
  */
void ssd1309_print(char *aString, UINT8 page, UINT8 startColumn);

/**
  * @brief  prints a string containing a number at specified position
  *
  * Only the following chars and white spaces are allowed: 0123456789,./+-
  *
  * @param	*aString	pointer to the string to print (0 terminated)
  * @param  page		the upper page (line) where the string is displayed, string needs one more page below
  * @param  startColumn	the column where the string starts
  */
void ssd1309_print_bigDigit(char *aString, UINT8 page, UINT8 startColumn);

/**
  * @brief  prints a string from program memory at specified position
  *
  * @param	aString	    pointer to the PROGMEM string to print (0x00 terminated)
  * @param  page		the page (line) where the string is displayed
  * @param  startColumn	the column where the string starts
  */
void ssd1309_print_P(const char* aString, UINT8 page, UINT8 startColumn);

/**
  * @brief  prints a formatted string at specified position
  *
  * @param  page		the page (line) where the string is displayed
  * @param  startColumn	the column where the string starts
  */
void ssd1309_printf(UINT8 page, UINT8 startColumn, const char* __fmt, ...);

/**
  * @brief  prints a formatted string at specified position, format string in program memory
  *
  * @param  page		the page (line) where the string is displayed
  * @param  startColumn	the column where the string starts
  */
void ssd1309_printf_P(UINT8 page, UINT8 startColumn, const char* __fmt, ...);

/**
  * @brief  shows a picture at specified position
  *         Use the Image2GLCD tool from http://www.avrportal.com/?page=image2glcd to generate
  *         pattern from an image. Select setting "LSB to MSB Top to Bottom" and correct size.
  *
  * @param	*pic		pointer to the picture data generated by the Image2GLCD tool, type have to be a "const UINT8 PROGMEM" array
  * @param  startPage	the page where the picture starts, each page is 8 pixels high
  * @param  endPage		the page where the picture ends, height of the picture have to be a multiple of 8 and >= startPage
  * @param  startCol	x offset for display position 
  * @param  totalCol	with of the picture
  */
void ssd1309_showPic(const UINT8 *pic, UINT8 startPage, UINT8 endPage, UINT8 startCol, UINT8 totalCol);

/**
  * @brief  draws a bar graph at specified position
  *
  * @param	percent		the filling of the graph (0-100%)
  * @param  startPage	the page where the bar graph starts, each page is 8 pixels high
  * @param  endPage		the page where the bar graph ends, height of the bar graph have to be a multiple of 8 and >= startPage
  * @param  startCol	x offset for display position 
  * @param  totalCol	with of the bar graph
  */
void ssd1309_drawBargraph(UINT8 percent, UINT8 startPage, UINT8 endPage, UINT8 startCol, UINT8 totalCol);

void cmd_ContrastControl(UINT8 contrast);

#endif /* SSD1309_H_ */