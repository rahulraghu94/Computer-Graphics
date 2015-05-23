#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include "computer.h"
//#include "bic.h"
//#include "reno.h"
//#include "both.h"

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#endif

#include <GL/glut.h>

int page = 0;

/*----------------------------------------------------------------------------------------
 *	Global Variables
 */

/*
 *	A structure to represent the mouse information
 *----------------------------------------------------------------------------------------
 */
struct Mouse 
{
	int x;		/*	the x coordinate of the mouse cursor	*/
	int y;		/*	the y coordinate of the mouse cursor	*/
	int lmb;	/*	is the left button pressed?		*/
	int mmb;	/*	is the middle button pressed?	*/
	int rmb;	/*	is the right button pressed?	*/
	int xpress; /*	stores the x-coord of when the first button press occurred	*/
	int ypress; /*	stores the y-coord of when the first button press occurred	*/
};

typedef struct Mouse Mouse;
//Create a global mouse structure to hold the mouse information.
 
Mouse TheMouse = {0,0,0,0,0,0,0};

int winw = 1800;	/*Set window width, global for use by my_init() and resize */
int winh = 1000;	/*Set window height, global for use by my_init() and resize */

typedef void (*ButtonCallback)();
/* Creating a fnction pointer for the button to use. Google, function pointers, LCTHW */

struct Button 
{
	int   x;							/* top left x coord of the button */
	int   y;							/* top left y coord of the button */
	int   w;							/* the width of the button */
	int   h;							/* the height of the button */
	int   state;						/* the state, 1 if pressed, 0 otherwise */
	int   highlighted;					/* is the mouse cursor over the control? */
	char* label;						/* the text label of the button */
	ButtonCallback callbackFunction;	/* A pointer to a function to call if the button is pressed */
};
typedef struct Button Button;


/* Static, since we wish it to remain constatnt through out execution.
 * We use a page count to determine which page is to be displayed.
 * In the display function, we SWITCH page_count to check which display is to be called.
 * We make that call accordingly. The allows us to even staverse back wards.
 * Call to glutPostRedisplay() ensures that Disaply() is called again with existing param.
 */

void TheBackButtonCallBack()
{
	page = 0;
	glutPostRedisplay();
}

void disp_data()
{
	switch (page)
	{
	case 1:
		system("./src/draw_bmp.o ~/Project_final/res/a.bmp");
		break;

	case 2:
		system("./src/draw_bmp.o ~/Project_final/res/2.png");
		break;

	case 3:
		system("./src/draw_bmp.o ~/Project_final/res/3.png");
		break;

	case 4:
		system("./src/draw_bmp.o ~/Project_final/res/4.bmp"); //Image left to upload
		break;
		
	}
}

void animate_buff()
{
	switch (page)
	{
	case 1:
		//do something;

	case 2:
		system("./src/reno.o");
		break;

	case 3:
		system("./src/bic.o");
		break;

	case 4:
		system("./src/both.o");
		break;
		
	}
}

Button my_exit = {200+200, 180, 150, 30, 0, 0, "Back", TheBackButtonCallBack};
Button disp_data_img = {800, 180, 150, 30, 0, 0, "Information", disp_data};
Button animate = {400+200, 180, 150, 30, 0, 0, "Simulate", animate_buff};
/*----------------------------------------------------------------------------------------
 *	This is a list callback functions. Notice that it's type is the same
 *	an the ButtonCallback type. We can assign a pointer to this function which
 *	we can store and later call. We call each of these functions based on what 
 * each function has been specified in button creation.
 * Eg: TheButtonCallBack5(), the exit button, simply exits the program.
 *----------------------------------------------------------------------------------------
 */
void TheButtonCallback1()
{
	page = 1;
	glutPostRedisplay();
}

void TheButtonCallBack5()
{
	exit(0);
}

void TheButtonCallback2()
{
	page = 2;
	glutPostRedisplay();	
}

void TheButtonCallback3()
{
	page = 3;
	glutPostRedisplay();
}

void TheButtonCallback4()
{
	page = 4;
	glutPostRedisplay();
}

/*
void TheBackButtonCallBack()
{
	page = 0;
	glutPostRedisplay();
}


/*----------------------------------------------------------------------------------------
 *	This is the button visible in the viewport. This is a shorthand way of 
 *	initialising the structure's data members. Notice that the last data
 *	member is a pointer to the above function. 
 *-----------------------------------------------------------------------------------------
 */
Button MyButton1 = {400, 350, 500, 40, 0, 0, "TCP Congestion Avoidance Algorithms", TheButtonCallback1};
Button MyButton2 = {400, 400, 500, 40, 0, 0, "TCP New Reno", TheButtonCallback2};
Button MyButton3 = {400, 450, 500, 40, 0, 0, "TCP BIC", TheButtonCallback3};
Button MyButton4 = {400, 500, 500, 40, 0, 0, "TCP New Renp and TCP BIC", TheButtonCallback4};
Button MyButton5 = {400, 550, 500, 40, 0, 0, "Exit", TheButtonCallBack5};


/*----------------------------------------------------------------------------------------
 *	\brief	This function draws a text string to the screen using glut bitmap fonts.
 *	\param	font	-	the font to use. it can be one of the following : 
 *
 *					GLUT_BITMAP_9_BY_15		
 *					GLUT_BITMAP_8_BY_13			
 *					GLUT_BITMAP_TIMES_ROMAN_10	
 *					GLUT_BITMAP_TIMES_ROMAN_24	
 *					GLUT_BITMAP_HELVETICA_10	
 *					GLUT_BITMAP_HELVETICA_12	
 *					GLUT_BITMAP_HELVETICA_18	
 *
 *	\param	text	-	the text string to output
 *	\param	x		-	the x co-ordinate
 *	\param	y		-	the y co-ordinate
 *--------------------------------------------------------------------------------------------
 */
void Font(void *font,char *text,int x,int y)
{
	glRasterPos2i(x, y);

	while( *text != '\0' )
	{
		glutBitmapCharacter( font, *text );
		++text;
	}
}


/*----------------------------------------------------------------------------------------
 *	\brief	This function is used to see if a mouse click or event is within a button 
 *			client area.
 *	\param	b	-	a pointer to the button to test
 *	\param	x	-	the x coord to test
 *	\param	y	-	the y-coord to test
 *----------------------------------------------------------------------------------------
 */
int ButtonClickTest(Button* b,int x,int y) 
{
	if( b) 
	{
	    if( x > b->x      && 
			x < b->x+b->w &&
			y > b->y      && 
			y < b->y+b->h ) {
				return 1;
		}
	}
	return 0;
}

/*----------------------------------------------------------------------------------------
 *	\brief	This function draws the specified button.
 *	\param	b	-	a pointer to the button to check.
 *	\param	x	-	the x location of the mouse cursor.
 *	\param	y	-	the y location of the mouse cursor.
 *----------------------------------------------------------------------------------------
 */
void ButtonRelease(Button *b,int x,int y)
{
	if(b) 
	{
		if( ButtonClickTest(b,TheMouse.xpress,TheMouse.ypress) && 
			ButtonClickTest(b,x,y) )
		{
			if (b->callbackFunction) {
				b->callbackFunction();
			}
		}

		b->state = 0;
	}
}

/*----------------------------------------------------------------------------------------
 *	\brief	This function draws the specified button.
 *	\param	b	-	a pointer to the button to check.
 *	\param	x	-	the x location of the mouse cursor.
 *	\param	y	-	the y location of the mouse cursor.
 *----------------------------------------------------------------------------------------
 */
void ButtonPress(Button *b,int x,int y)
{
	if(b)
	{
		if( ButtonClickTest(b,x,y) )
		{
			b->state = 1;
			b->callbackFunction();
		}
	}
}


/*----------------------------------------------------------------------------------------
 *	\brief	This function draws the specified button.
 *	\parameter	b	-	a pointer to the button to check.
 *	\parameter	x	-	the x location of the mouse cursor.
 *	\parameter	y	-	the y location of the mouse cursor.
 *----------------------------------------------------------------------------------------
 */
void ButtonPassive(Button *b,int x,int y)
{
	if(b)
	{
		if( ButtonClickTest(b,x,y) )
		{
			if( b->highlighted == 0 ) {
				b->highlighted = 1;
				glutPostRedisplay();
			}
		}
		else

		if( b->highlighted == 1 )
		{
			b->highlighted = 0;
			glutPostRedisplay();
		}
	}
}

/*----------------------------------------------------------------------------------------
 *	\brief	This function draws the specified button.
 *	\param	b	-	a pointer to the button to draw.
 *----------------------------------------------------------------------------------------
 */
void ButtonDraw(Button *b)
{
	int fontx;
	int fonty;

	if(b)
	{
		if (b->highlighted) 
			glColor3f (0.258824, 0.435294, 0.258824);
		else 
			glColor3f (0.309804, 0.309804, 0.184314);

		glBegin(GL_QUADS);
			glVertex2i( b->x     , b->y      );
			glVertex2i( b->x     , b->y+b->h );
			glVertex2i( b->x+b->w, b->y+b->h );
			glVertex2i( b->x+b->w, b->y      );
		glEnd();

		glLineWidth(3);

		if (b->state) 
			glColor3f(0.4f,0.4f,0.4f);
		else 
			glColor3f(0.8f,0.8f,0.8f);

		glBegin(GL_LINE_STRIP);
			glVertex2i( b->x+b->w, b->y      );
			glVertex2i( b->x     , b->y      );
			glVertex2i( b->x     , b->y+b->h );
		glEnd();

		if (b->state) 
			glColor3f(0.8f,0.8f,0.8f);
		else 
			glColor3f(0.4f,0.4f,0.4f);

		glBegin(GL_LINE_STRIP);
			glVertex2i( b->x     , b->y+b->h );
			glVertex2i( b->x+b->w, b->y+b->h );
			glVertex2i( b->x+b->w, b->y      );
		glEnd();

		glLineWidth(1);

		fontx = b->x + (b->w - glutBitmapLength(GLUT_BITMAP_HELVETICA_10,b->label)) / 2 ;
		fonty = b->y + (b->h+10)/2;

		if (b->state) {
			fontx+=2;
			fonty+=2;
		}
		if(b->highlighted)
		{
			glColor3f(0,0,0);
			Font(GLUT_BITMAP_HELVETICA_10,b->label,fontx,fonty);
			fontx--;
			fonty--;
		}

		glColor3f(1,1,1);
		Font(GLUT_BITMAP_HELVETICA_10,b->label,fontx,fonty);
	}
}

void Init()
{
	glEnable(GL_LIGHT0);
}


void draw_main()
{
	char s[] = "TCP Congestion Avoidance Algorithms";
	char t[] = "Rahul J Raghunath";
	char u[] = "Sanheeta Shankar";
	char v[] = "1BY12CS046";
	char w[] = "1BY12CS064";
	char x[] = "BMS Institute of Technoogy and Management";
	
	glColor3f (0.258824, 0.435294, 0.258824);
	Font(GLUT_BITMAP_TIMES_ROMAN_24, s, 450, 150);
	Font(GLUT_BITMAP_HELVETICA_18, t, 150, 200);
	Font(GLUT_BITMAP_HELVETICA_18, u, 1000, 200);
	Font(GLUT_BITMAP_HELVETICA_18, v, 160, 240);
	Font(GLUT_BITMAP_HELVETICA_18, w, 1010, 240);
	Font(GLUT_BITMAP_TIMES_ROMAN_24, x, 410, 260);
	
	glFlush();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	ButtonDraw(&MyButton1);
	ButtonDraw(&MyButton2);
	ButtonDraw(&MyButton3);
	ButtonDraw(&MyButton4);
	ButtonDraw(&MyButton5);
}

void draw_tcp()
{
	char s[] = "TCP Congestion Avoidance Algorithms";
	glColor3f (0.258824, 0.435294, 0.258824);
	Font(GLUT_BITMAP_TIMES_ROMAN_24, s, 450, 300);
	ButtonDraw(&my_exit);
	ButtonDraw(&disp_data_img);
	//ButtonDraw(&animate);
	glFlush();	
}

void draw_reno()
{
	char s[] = "TCP Reno Congestion Avoidance Algorithms";
	glColor3f (0.258824, 0.435294, 0.258824);
	Font(GLUT_BITMAP_TIMES_ROMAN_24, s, 450, 300);
	ButtonDraw(&my_exit);
	ButtonDraw(&disp_data_img);
	ButtonDraw(&animate);
	//system("./reno");
	glFlush();
}

void draw_bic()
{
	char s[] = "TCP BIC Congestion Avoidance Algorithms";
	glColor3f (0.258824, 0.435294, 0.258824);
	Font(GLUT_BITMAP_TIMES_ROMAN_24, s, 450, 300);
	ButtonDraw(&my_exit);
	ButtonDraw(&disp_data_img);
	ButtonDraw(&animate);
	//system("./bic");
	glFlush();
}

void draw_both()
{
	char s[] = "Hetrogenous Reno/BIC Congestion Avoidance Algorithms";
	glColor3f (0.258824, 0.435294, 0.258824);
	Font(GLUT_BITMAP_TIMES_ROMAN_24, s, 445, 300);
	ButtonDraw(&my_exit);
	ButtonDraw(&disp_data_img);
	ButtonDraw(&animate);
	//system("./both");
	glFlush();	
}

void Display()
{
	//char s[] = "TCP Congestion Avoidance Algorithms";
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,winw,winh,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f (0.258824, 0.435294, 0.258824);
	//Font(GLUT_BITMAP_TIMES_ROMAN_24, s, 450, 150);
	glFlush();

	switch(page)
	{
		case 0:
			draw_main();
			break;

		case 1:
			draw_tcp();
			break;

		case 2:
			draw_reno();
			break;

		case 3:
			draw_bic();
			break;

		case 4:
			draw_both();
			break;

		default:
			printf("ERROR: Page requested was not found.");
	}
	glutSwapBuffers();
}

void Resize(int w, int h)
{
	winw = w;
	winh = h;

	glViewport(0,0,w,h);
}


/*----------------------------------------------------------------------------------------
 *	\brief	This function is called whenever a mouse button is pressed or released
 *	\param	button	-	GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, or GLUT_MIDDLE_BUTTON
 *	\param	state	-	GLUT_UP or GLUT_DOWN depending on whether the mouse was released
 *						or pressed respectivly. 
 *	\param	x		-	the x-coord of the mouse cursor.
 *	\param	y		-	the y-coord of the mouse cursor.
 *----------------------------------------------------------------------------------------
 */
void MouseButton(int button,int state,int x, int y)
{

	TheMouse.x = x;
	TheMouse.y = y;

	if (state == GLUT_DOWN) 
	{

		if ( !(TheMouse.lmb || TheMouse.mmb || TheMouse.rmb) ) {
			TheMouse.xpress = x;
			TheMouse.ypress = y;
		}

		switch(button) 
		{
		case GLUT_LEFT_BUTTON:
			TheMouse.lmb = 1;
			ButtonPress(&MyButton1, x, y);
			ButtonPress(&MyButton2, x, y);
			ButtonPress(&MyButton3, x, y);
			ButtonPress(&MyButton4, x, y);
			ButtonPress(&MyButton5, x, y);
			ButtonPress(&my_exit, x, y);
			ButtonPress(&animate, x, y);
			ButtonPress(&disp_data_img, x, y);
		case GLUT_MIDDLE_BUTTON:
			TheMouse.mmb = 1;
			break;
		case GLUT_RIGHT_BUTTON:
			TheMouse.rmb = 1;
			break;
		}
	}
	else 
	{
		switch(button) 
		{
		case GLUT_LEFT_BUTTON:
			TheMouse.lmb = 0;
			ButtonRelease(&MyButton1, x, y);
			ButtonRelease(&MyButton2, x, y);
			ButtonRelease(&MyButton3, x, y);
			ButtonRelease(&MyButton4, x, y);
			ButtonRelease(&MyButton5, x, y);
			ButtonRelease(&my_exit, x, y);
			ButtonRelease(&animate, x, y);
			ButtonRelease(&disp_data_img, x, y);
			break;
		case GLUT_MIDDLE_BUTTON:
			TheMouse.mmb = 0;
			break;
		case GLUT_RIGHT_BUTTON:
			TheMouse.rmb = 0;
			break;
		}
	}

	glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------
 *	\brief	This function is called whenever the mouse cursor is moved AND A BUTTON IS HELD.
 *	\param	x	-	the new x-coord of the mouse cursor.
 *	\param	y	-	the new y-coord of the mouse cursor.
 *----------------------------------------------------------------------------------------
 */
void MouseMotion(int x, int y)
{
	int dx = x - TheMouse.x;
	int dy = y - TheMouse.y;

	TheMouse.x = x;
	TheMouse.y = y;

	ButtonPassive(&MyButton1, x, y);
	ButtonPassive(&MyButton2, x, y);
	ButtonPassive(&MyButton3, x, y);
	ButtonPassive(&MyButton4, x, y);
	ButtonPassive(&MyButton5, x, y);
	ButtonPassive(&my_exit, x, y);
	ButtonPassive(&animate, x, y);
	ButtonPassive(&disp_data_img, x, y);

	glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------
 *	\brief	This function is called whenever the mouse cursor is moved AND NO BUTTONS ARE HELD.
 *	\param	x	-	the new x-coord of the mouse cursor.
 *	\param	y	-	the new y-coord of the mouse cursor.
 *-------------------------------------------------------------------------------------------
 */
void MousePassiveMotion(int x, int y)
{
	int dx = x - TheMouse.x;
	int dy = y - TheMouse.y;

	TheMouse.x = x;
	TheMouse.y = y;

	ButtonPassive(&MyButton1, x, y);
	ButtonPassive(&MyButton2, x, y);
	ButtonPassive(&MyButton3, x, y);
	ButtonPassive(&MyButton4, x, y);
	ButtonPassive(&MyButton5, x, y);
	ButtonPassive(&my_exit, x, y);
	ButtonPassive(&animate, x, y);
	ButtonPassive(&disp_data_img, x, y);
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(winw,winh);
	glutInitWindowPosition(0,0);
	glutCreateWindow("TCP Congestion Avoidance Algorithms");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(Display);
	glutReshapeFunc(Resize);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutPassiveMotionFunc(MousePassiveMotion);

	Init();

	glutMainLoop();

	return 0;
}
