/*
 * Pebble Stopwatch - common utilities
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


#include <pebble.h>
#include "common.h"

int bg_vals[10] =      {86, 90, 95, 98, 99, 100, 101, 120, 123, 96}; 
int iob_dig_vals[10] = { 0,  0,  1,  5,  7,   9,  10,  12,  13, 14}; 
int iob_hund_vals[10] = {0,  4, 95, 98, 99,  45,   5,   0,  99,  1}; 
  
void format_lap_old(double lap_time, char* buffer) 
{
  int tenths = (int)(lap_time * 10) % 10;
  int seconds = (int)lap_time % 60;
  int minutes = (int)lap_time / 60 % 60;
  int hours = (int)lap_time / 3600;

	snprintf(buffer, LAP_LENGTH, "%02d:%02d:%02d.%d", hours, minutes, seconds, tenths);
}

void format_lap(double lap_time, char* buffer) 
{
//  int tenths = (int)(lap_time * 10) % 10;
  int seconds = (int)lap_time % 60;
  int minutes = (int)lap_time / 60 % 60;
  int bg_val = (int)lap_time / 3600;
  int time_ago;
  int iob_dig, iob_hund;

  bg_val = bg_vals[seconds % 10];
  time_ago = seconds;
  iob_dig = iob_dig_vals[seconds % 10];
  iob_hund = iob_hund_vals[seconds % 10];
  
  if (bg_val < 100)
  {
    if (iob_dig < 10)
    {
	        snprintf(buffer, LAP_LENGTH, "  %2d   %d.%02d %3d", bg_val, iob_dig, iob_hund, time_ago);
    }
    else
    {
	        snprintf(buffer, LAP_LENGTH, "  %2d %d.%02d %3d", bg_val, iob_dig, iob_hund, time_ago);
    }
  }
  else
  {
    if (iob_dig < 10)
    {
  	       snprintf(buffer, LAP_LENGTH, "%3d   %d.%02d %3d", bg_val, iob_dig, iob_hund, time_ago);  
    }
    else
    {
  	       snprintf(buffer, LAP_LENGTH, "%3d %d.%02d %3d", bg_val, iob_dig, iob_hund, seconds);  
    }
  }
//	snprintf(buffer, 11, "%02d:%02d:%02d.%d", hours, minutes, seconds, tenths);
}

double float_time_ms() 
{
	time_t seconds;
	uint16_t milliseconds;
	time_ms(&seconds, &milliseconds);
	return (double)seconds + ((double)milliseconds / 1000.0);
}
