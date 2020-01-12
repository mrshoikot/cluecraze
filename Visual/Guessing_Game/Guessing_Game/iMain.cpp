#include "iGraphics.h"
using namespace std;
#include<iostream>

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

int result;

int screen = 1;

const int limit = 100;
const int show = 25;

int all[limit], temp[show];

int sWidth = 1200;
int sHeight = 700;

int c = 0;

char bmp[10][20] = {"bmp\\start.bmp"};



// Print an array
void printArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Return non zero element quantity in an array
int nonZeroLen(int arr[], int n){
    int i,c=0;
    for(i=0;i<n;i++){
        if(arr[i] != 0){
            c++;
        }
    }
    return c;
}


// Return a random integer
int randomInt(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}


// Check if an element is present in an array
int isPresent(int arr[],int n,int size){
    int i;
    for(i=0;i<size;i++){
        if(n==arr[i]){
            return 1;
        }
    }
    return 0;
}


// Generate Temp array
int generateTemp(){

    int x,y,check,i,j,randIndex,t,k;
    int tempLen;

    while(nonZeroLen(all, limit) > 1){

        tempLen = 0;
        k=0;

        // Generate random show'th number
        while(tempLen < show){

            randIndex  = randomInt(0,limit/2-1);
            x = all[randIndex];
            y = randomInt(1,limit);

            // Check if x is present in temp
            if(isPresent(temp,x,tempLen) == 0){
                temp[k] = x;
                tempLen++;
                k++;
            }else if(isPresent(temp,y,tempLen) == 0){
                temp[k] = y;
                tempLen++;
                k++;
            }

        }

        // Sort Temp
        for(i=0; i<tempLen; i++)
        {
            for(j=i+1; j<tempLen; j++)
            {
                if(temp[i] > temp[j])
                {
                    t       = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }

		return 0;


    }

}



// Show homescreen
void homeScreen(){

	// Background
	iSetColor(255,255,255);
	iFilledRectangle(0,0,sWidth,sHeight);
	
	// Start Button
	iShowBMP2(200, sHeight/2-100, bmp[0], 255);

}


// Show game box
void showBox(){

	// Background
	iSetColor(255,255,255);
	iFilledRectangle(0,0,sWidth,sHeight);

	//while(nonZeroLen(all, limit) > 1)

	int s = (sWidth - 200)/sqrt(show);
	int x = (sWidth - 1000)/2, y = sHeight;

	if(c==0){
		generateTemp();
	}

	c = 1;

	iSetColor(0,0,0);

	// Run loop for each row
	for(int i=0;i<show;i++){

		// Convert integer to string
		char str[10];
		sprintf(str, "%d", temp[i]);
		char *p = str;

		// Reset x and decrease y on new row
		if(i%5==0){
			y -= s/2;
			x = (sWidth-1000)/2;
		}

		// Print string integer on screen
		iText(x,y,p, GLUT_BITMAP_HELVETICA_18);

		// Increment x axis's value
		x += s + ((sWidth - 200)/sqrt(s))/2;

	}
	

}


void showResult(){
	// Background
	iSetColor(255,255,255);
	iFilledRectangle(0,0,sWidth,sHeight);

	iSetColor(255,0,0);
	
	// Convert integer to string
	char str[10];
	sprintf(str, "%d", result);
	char *p = str;

	// Start Button
	iText(sWidth/2, sHeight/2, p, GLUT_BITMAP_TIMES_ROMAN_24);
}


void iDraw()
{
	iClear();

	// Show screen depending on global variable
	if(screen == 1){
		homeScreen();
	}else if(screen == 2){
		showBox();
	}else if(screen == 3){
		showResult();
	}

}



void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		// Mouse event for home screen
		if(screen == 1){
		
			// Start button press
			if(mx>=197 && mx<=405 && my>=248 && my <= 457){
				screen = 2;
			}
		
		}

		// Mouse event for result screen
		if(screen == 3){
			
			screen = 1;

		}
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iKeyboard(unsigned char key)
{
	if (key == '0')
	{

        for(int i=0;i<limit;i++){
            if(isPresent(temp,all[i],show) == 0){
                all[i] = all[i];
            }else{
                all[i] = 0;
            }
        }

	}else if(key == '1'){

		for(int i=0;i<limit;i++){
            if(isPresent(temp,all[i],show)){
                all[i] = all[i];
            }else{
                all[i] = 0;
            }
        }

	}

	if(nonZeroLen(all, limit) > 1){
		generateTemp();
	}else{
		for(int i=0;i<limit;i++){
			if(all[i] != 0){
				result = all[i];
				screen = 3;
			}
		}
	}
	
	
	
}


void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


int main()
{
	iInitialize(sWidth, sHeight, "Guessing Game");

	// put 1 to limit in "all" array
    for(int i=1;i<=limit;i++){
        all[i-1] = i;
    }

	iStart();
	return 0;
}