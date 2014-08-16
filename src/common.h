/*
 * Pebble Stopwatch - common utility header file
 * Copyright (C) 2013 Katharine Berry
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#define PERSIST_STATE 1
#define PERSIST_LAPS 4
#define LAP_LENGTH 16
  
  #define TICK_BASE   1000 // 100

void format_lap(double lap_time, char* buffer);
double float_time_ms();

#define BUTTON_RECT        (GRect( 130, 22,  14, 136)) // GRect(130, 10, 14, 136));
#define OMNIPOD_RECT       (GRect(  15,  0,  96,  25))
#define BIG_TIME_RECT      (GRect(   0, 25,  96,  35))
#define SECONDS_TIME_RECT  (GRect(  96, 37,  49,  35))
#define LINE_RECT          (GRect(   0, 65, 144,   2))
#define HEADER_RECT        (GRect(   1, 67, 143,  21))
#define LAP_RECT           (GRect(   1, 84, 143,  26))  // orig (   5, 72, 139,  26)
#define LAP_HIDE_RECT      (GRect(-139, 84, 143,  30))
#define ENTRY_RECT         (GRect(-139, 84, 143,  26))  // orig (-139, 52, 139,  26)

/* Orig
#define BIG_TIME_RECT      (GRect(   0,  5,  96, 35))
#define SECONDS_TIME_RECT  (GRect(  96, 17,  49, 35))
#define LINE_RECT          (GRect(   0, 45, 144,  2))
#define LAP_RECT           (GRect(   5, 52, 139, 26))
#define LAP_HIDE_RECT      (GRect(-139, 52, 139, 30))
*/