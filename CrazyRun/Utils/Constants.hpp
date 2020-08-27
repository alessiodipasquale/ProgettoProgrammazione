#ifndef CONSTANTS_H
#define CONSTANTS_H

const bool TESTMODE = true;
//const int STARTX = 16;
//const int STARTY = 30;
const int LEVELDOWNRANGE = 200;
const int LEVELUPRANGE = 1000;
const int MAPWIDTH = 31;
const int MAPHEIGHT = 31;
const int MAXDENSITY = 20; // percentage of a view surface
const int THRESHOLDLEVELFORMAXDENSITY = 100;
const int YCARSPAWN = MAPHEIGHT / 2;
const int STARTINGREFRESHTIME = 300000;
const int TIMETHRESHOLD = 30000; 

/////////////////////////////////////////////SKIN
const int NUMBEROFCOMPONENTS_1 = 4;
const int XCOORDINATES_1[] = {14,16,15,15};
const int  YCOORDINATES_1[] = {30,30,30,29};
const char COMPONENTS_1[] = {'O','O','-','^'};
////////
const int NUMBEROFCOMPONENTS_2 = 6;
const int XCOORDINATES_2[] = {14,16,14,16,15,15};
const int  YCOORDINATES_2[] = {30,30,29,29,30,29};
const char COMPONENTS_2[] = {'O','O','O','O','-','-'};
///////
const int NUMBEROFCOMPONENTS_3 = 6;
const int XCOORDINATES_3[] = {14,16,15,14,15,16};
const int  YCOORDINATES_3[] = {30,30,30,29,29,29};
const char COMPONENTS_3[] = {'O','O','=','"','-','"'};
#endif

/*
 ^
O-O

O-O
O-O

"-"
O=O

*/