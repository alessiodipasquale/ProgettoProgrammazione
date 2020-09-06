#ifndef CONSTANTS_H
#define CONSTANTS_H

const int LEVELDOWNRANGE = 200;
const int LEVELUPRANGE = 1000;
const int MAPWIDTH = 31;
const int MAPHEIGHT = 31;
const int MAPTHRESHOLD = 37;
const int SCREENWIDTH = 71;
const int MAXDENSITY = 20; // percentage of a view surface
const int THRESHOLDLEVELFORMAXDENSITY = 100;
const int YCARSPAWN = MAPHEIGHT / 2;
const int STARTINGREFRESHTIME = 300000;
const int TIMETHRESHOLD = 45000; 
const int WALLPENALITY = -200;
const int BONUSPOINTS = 5;

/////////////////////////////////////////////SKIN
const int NUMBEROFCOMPONENTS_1 = 6;
const int XCOORDINATES_1[] = {((MAPWIDTH-1)/2)-1,((MAPWIDTH-1)/2)+1,(MAPWIDTH-1)/2,(MAPWIDTH-1)/2,((MAPWIDTH-1)/2)-1,((MAPWIDTH-1)/2)+1};
const int  YCOORDINATES_1[] = {MAPHEIGHT-1,MAPHEIGHT-1,MAPHEIGHT-1,MAPHEIGHT-2, MAPHEIGHT-2, MAPHEIGHT-2};
const char COMPONENTS_1[] = {'O','O','-','^',' ', ' '};
////////
const int NUMBEROFCOMPONENTS_2 = 6;
const int XCOORDINATES_2[] = {((MAPWIDTH-1)/2)-1,((MAPWIDTH-1)/2)+1,((MAPWIDTH-1)/2)-1,((MAPWIDTH-1)/2)+1,((MAPWIDTH-1)/2),((MAPWIDTH-1)/2)};
const int  YCOORDINATES_2[] = {MAPHEIGHT-1,MAPHEIGHT-1,MAPHEIGHT-2,MAPHEIGHT-2,MAPHEIGHT-1,MAPHEIGHT-2};
const char COMPONENTS_2[] = {'O','O','O','O','-','-'};
///////
const int NUMBEROFCOMPONENTS_3 = 6;
const int XCOORDINATES_3[] = {((MAPWIDTH-1)/2)-1,((MAPWIDTH-1)/2)+1,((MAPWIDTH-1)/2),((MAPWIDTH-1)/2)-1,((MAPWIDTH-1)/2),((MAPWIDTH-1)/2)+1};
const int  YCOORDINATES_3[] = {MAPHEIGHT-1,MAPHEIGHT-1,MAPHEIGHT-1,MAPHEIGHT-2,MAPHEIGHT-2,MAPHEIGHT-2};
const char COMPONENTS_3[] = {'O','O','=','/','-','\\'};
#endif

/*
 ^
O-O

O-O
O-O

"-"
O=O

*/