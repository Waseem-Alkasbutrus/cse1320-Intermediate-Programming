#include <stdio.h>
#include <stdbool.h>


/*
takes location inputs x y w h, for two rectangles and looks for collision between the two.

user inputs
	x: the x coordinate for the center point of the rectangle
	y: the y coordinate for the center point of the rectangle
	w: the width of the rectangle 
	h: the hight of the rectangle

outputs
	prints "Collision detected!" if a collision is detected
	prints "No collision." if no collisions are detected
*/
int main(void) {
	float cords_R1[4] = {0}, cords_R2[4] = {0}; //coordinates for rectangles 1 and 2

	printf("Rectangle 1: ");
	//x (x coordinate of center point) y (y coordinate of center point) w (width) h (height)
	scanf("%f %f %f %f", &cords_R1[0], &cords_R1[1], &cords_R1[2], &cords_R1[3]);

	while(getchar() != '\n');

	printf("Rectangle 2: ");
	//x (x coordinate of center point) y (y coordinate of center point) w (width) h (height)
	scanf("%f %f %f %f", &cords_R2[0], &cords_R2[1], &cords_R2[2], &cords_R2[3]);

	while(getchar() != '\n');

	//boarders for rectangle 1 --> LB (left boarder), RB (right boarder), BB (bottom boarder), TB (top boarder)
	float boarders_R1[4] = {(cords_R1[0]-(cords_R1[2]/2)), (cords_R1[0]+(cords_R1[2]/2)), (cords_R1[1]-(cords_R1[3]/2)), (cords_R1[1]+(cords_R1[3]/2))};
	
	//boarders for rectangle 2 --> LB (left boarder), RB (right boarder), BB (bottom boarder), TB (top boarder)
	float boarders_R2[4] = {(cords_R2[0]-(cords_R2[2]/2)), (cords_R2[0]+(cords_R2[2]/2)), (cords_R2[1]-(cords_R2[3]/2)), (cords_R2[1]+(cords_R2[3]/2))};
	

	bool v_Collision = false; //if a vertical boarder of rectangle 2 is between the 2 vertical boarders of rectangle 1 (on the x axis)
	bool h_Collision = false; //if a horizontal boarder of rectangle 2 is between the 2 horizontal boarders of rectangle 1 (on the y axis)

	if ((boarders_R2[0] > boarders_R1[0]) && (boarders_R2[0] < boarders_R1[1])) {//if the LB of R2 is between LB and RB of R1
		v_Collision = true;
	} else if ((boarders_R2[1] > boarders_R1[0]) && (boarders_R2[1] < boarders_R1[1])) {//if the RB of R2 is between LB and RB of R1
		v_Collision = true;
	}

	if ((boarders_R2[2] > boarders_R1[2]) && (boarders_R2[2] < boarders_R1[3])) {//if the BB of R2 is between BB and TB of R1
		h_Collision = true;
	} else if ((boarders_R2[3] > boarders_R1[2]) && (boarders_R2[3] < boarders_R1[3])) {//if the TB of R2 is between BB and TB of R1
		h_Collision = true;
	}

	if (v_Collision && h_Collision) {//if there are both vertical and horizontal collisions
		printf("Collision detected!\n");
	} else {
		printf("No collision.\n");
	}


	return 0;
}