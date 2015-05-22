#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *currentfont;

void *fonts_both[]=
{
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,
GLUT_BITMAP_HELVETICA_18,
GLUT_BITMAP_HELVETICA_12
};

void mykey(unsigned char key, int x, int y)
{
	if( key )
		exit(0);
}

void setFont_both(void *font_both)
{
	currentfont=font_both;
}


void drawstring_both(float x,float y,float z,const char *string)
{
	const char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string; *c!='\0'; c++)
	{	
		glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_PROJECTION);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void computer()						      		// to draw the sender and receiver computers
{


	glColor3f(0.0f,0.0f,0.0f);
	setFont_both(GLUT_BITMAP_HELVETICA_18);
 	drawstring_both(95.0,420.0,1.0,"SENDER");

 	glColor3f(0.0f,0.0f,0.0f);
	setFont_both(GLUT_BITMAP_HELVETICA_18);
 	drawstring_both(95.0,420.0-250,1.0,"SENDER");

	glColor3f(0.0f,0.0f,0.0f);
	setFont_both(GLUT_BITMAP_HELVETICA_18);
 	drawstring_both(345.0,420.0-135,1.0,"RECEIVER");

		glColor3f(0.0f,0.0f,0.0f);
	setFont_both(GLUT_BITMAP_HELVETICA_18);
 	drawstring_both(185.0,380.0,1.0,"SENDER CONGESTION WINDOW, RENO");

	glColor3f(0.0f,0.0f,0.0f);
	setFont_both(GLUT_BITMAP_HELVETICA_18);
 	drawstring_both(185.0,60.0,1.0,"SENDER CONGESTION WINDOW, BIC");

	glColor3f(0.0f,0.0f,0.0f);
	setFont_both(GLUT_BITMAP_HELVETICA_18);
 	drawstring_both(185.0,215.0,1.0,"NETWORK CHANNEL BANDWIDTH");

	glColor3f(0.0, 0.0, 0.0);
	setFont_both(GLUT_BITMAP_HELVETICA_12);
	drawstring_both(370, 10, 1.0, "Press any key to go back after animation is complete");
	
	glColor3f(0.137255, 0.556863, 0.137255);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(85,380);
	glVertex2f(85,440);
	glVertex2f(150,440);
	glVertex2f(150,380);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.2,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(87,382);
	glVertex2f(87,438);
	glVertex2f(148,438);
	glVertex2f(148,382);
	glEnd();
	glFlush();

	//Connection line rom system to buffer
	
	//glColor3f(0.7, 0.2, 0.0);
	glBegin(GL_LINES);
	glVertex2f(110, 325);
	glVertex2f(110, 290);
	glEnd();

	//glColor3f(0.7, 0.2, 0.0);
	glBegin(GL_LINES);
	glVertex2f(110, 290);
	glVertex2f(140, 290);
	glEnd();
	
	//glColor3f(0.7,0.0,0.2);//vertical stand
	glBegin(GL_LINES);
	glVertex2f(105,380);
	glVertex2f(105,375);
	glVertex2f(129,380);
	glVertex2f(129,375);
	glEnd();
	glFlush();

	//glColor3f(0.7,0.3,0.2); //horizontal stand
	glBegin(GL_QUADS);
	glVertex2f(98,370);
	glVertex2f(98,375);
	glVertex2f(138,375);
	glVertex2f(138,370);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.2,0.2);  //CPU
	glBegin(GL_LINE_LOOP);
	glVertex2f(80,350);
	glVertex2f(80,370);
	glVertex2f(155,370);
	glVertex2f(155,350);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.8,0.2);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(95,360);
	glVertex2f(95,365);
	glVertex2f(115,365);
	glVertex2f(115,360);
	glEnd();
	glFlush();



	//glColor3f(0.7,0.2,0.8);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(132,358);
	glVertex2f(132,361);
	glVertex2f(140,361);
	glVertex2f(140,358);
	glEnd();
	glFlush(); 


	//glColor3f(0.7,0.2,0.2);//keyboard outline
	glBegin(GL_LINE_LOOP);
	glVertex2f(77,325);
	glVertex2f(87,350);
	glVertex2f(148,350);
	glVertex2f(158,325);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.2,0.2);//keyboard outline
	glBegin(GL_POLYGON);
	glVertex2f(77,325);
	glVertex2f(158,325);
	glVertex2f(158,322);
	glVertex2f(77,322);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.0,0.2); //horizontal lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(85,345);
	glVertex2f(150,345);
	glVertex2f(83,340);
	glVertex2f(152,340);
	glVertex2f(81,335);
	glVertex2f(154,335);
	glVertex2f(79,330);
	glVertex2f(156,330);
	glVertex2f(77,325);
	glVertex2f(158,325);
	glEnd();
	glFlush();



	//glColor3f(0.7,0.0,0.2); //vertical lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(89,322);
	glVertex2f(97,350);
	glVertex2f(103,322);
	glVertex2f(107,350);
	glVertex2f(117,322);
	glVertex2f(117,350);
	glVertex2f(131,322);
	glVertex2f(127,350);
	glVertex2f(145,322);
	glVertex2f(137,350);
	glEnd();
	glFlush();

	//-----------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------

	glColor3f(0.184314 ,0.309804, 0.309804);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(85,380-250);
	glVertex2f(85,440-250);
	glVertex2f(150,440-250);
	glVertex2f(150,380-250);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.2,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(87,382-250);
	glVertex2f(87,438-250);
	glVertex2f(148,438-250);
	glVertex2f(148,382-250);
	glEnd();
	glFlush();


	//Connection wire 2
	glBegin(GL_LINES);
	glVertex2f(110, 440-250);
	glVertex2f(110, 490-250);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(110, 490-250);
	glVertex2f(140, 490-250);
	glEnd();
	
	//glColor3f(0.7,0.0,0.2);//vertical stand
	glBegin(GL_LINES);
	glVertex2f(105,380-250);
	glVertex2f(105,375-250);
	glVertex2f(129,380-250);
	glVertex2f(129,375-250);
	glEnd();
	glFlush();

	//glColor3f(0.7,0.3,0.2); //horizontal stand
	glBegin(GL_QUADS);
	glVertex2f(98,370-250);
	glVertex2f(98,375-250);
	glVertex2f(138,375-250);
	glVertex2f(138,370-250);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.2,0.2);  //CPU
	glBegin(GL_LINE_LOOP);
	glVertex2f(80,350-250);
	glVertex2f(80,370-250);
	glVertex2f(155,370-250);
	glVertex2f(155,350-250);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.8,0.2);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(95,360-250);
	glVertex2f(95,365-250);
	glVertex2f(115,365-250);
	glVertex2f(115,360-250);
	glEnd();
	glFlush();



	//glColor3f(0.7,0.2,0.8);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(132,358-250);
	glVertex2f(132,361-250);
	glVertex2f(140,361-250);
	glVertex2f(140,358-250);
	glEnd();
	glFlush(); 


	//glColor3f(0.7,0.2,0.2);//keyboard outline
	glBegin(GL_LINE_LOOP);
	glVertex2f(77,325-250);
	glVertex2f(87,350-250);
	glVertex2f(148,350-250);
	glVertex2f(158,325-250);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.2,0.2);//keyboard outline
	glBegin(GL_POLYGON);
	glVertex2f(77,325-250);
	glVertex2f(158,325-250);
	glVertex2f(158,322-250);
	glVertex2f(77,322-250);
	glEnd();
	glFlush();


	//glColor3f(0.7,0.0,0.2); //horizontal lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(85,345-250);
	glVertex2f(150,345-250);
	glVertex2f(83,340-250);
	glVertex2f(152,340-250);
	glVertex2f(81,335-250);
	glVertex2f(154,335-250);
	glVertex2f(79,330-250);
	glVertex2f(156,330-250);
	glVertex2f(77,325-250);
	glVertex2f(158,325-250);
	glEnd();
	glFlush();



	//glColor3f(0.7,0.0,0.2); //vertical lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(89,322-250);
	glVertex2f(97,350-250);
	glVertex2f(103,322-250);
	glVertex2f(107,350-250);
	glVertex2f(117,322-250);
	glVertex2f(117,350-250);
	glVertex2f(131,322-250);
	glVertex2f(127,350-250);
	glVertex2f(145,322-250);
	glVertex2f(137,350-250);
	glEnd();
	glFlush();

	//---------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------

	// COMPUTER AT RECEIVER

	glColor3f(0.7,0.2,0.0);//monitior
	glBegin(GL_LINE_LOOP);
	glVertex2f(335,380-130);
	glVertex2f(335,440-130);
	glVertex2f(400,440-130);
	glVertex2f(400,380-130);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.0);//monitior
	glBegin(GL_LINE_LOOP);
	glVertex2f(337,382-130);
	glVertex2f(337,438-130);
	glVertex2f(398,438-130);
	glVertex2f(398,382-130);
	glEnd();
	glFlush();

	
	glColor3f(0.7,0.0,0.2);//ver
	glBegin(GL_LINES);
	glVertex2f(355,380-130);
	glVertex2f(355,375-130);
	glVertex2f(379,380-130);
	glVertex2f(379,375-130);
	glEnd();
	glFlush();

	glColor3f(0.7,0.3,0.2);//hor
	glBegin(GL_QUADS);
	glVertex2f(348,370-130);
	glVertex2f(348,375-130);
	glVertex2f(388,375-130);
	glVertex2f(388,370-130);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.2);//CPU
	glBegin(GL_LINE_LOOP);
	glVertex2f(330,350-130);
	glVertex2f(330,370-130);
	glVertex2f(405,370-130);
	glVertex2f(405,350-130);
	glEnd();
	glFlush();

	
	glColor3f(0.7,0.8,0.2);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(345,360-130);
	glVertex2f(345,365-130);
	glVertex2f(365,365-130);
	glVertex2f(365,360-130);
	glEnd();
	glFlush();



	glColor3f(0.7,0.2,0.8);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(382,358-130);
	glVertex2f(382,361-130);
	glVertex2f(390,361-130);
	glVertex2f(390,358-130);
	glEnd();
	glFlush(); 

	glColor3f(0.7,0.2,0.2);//keyboard
	glBegin(GL_LINE_LOOP);
	glVertex2f(327,322-130);
	glVertex2f(337,350-130);
	glVertex2f(398,350-130);
	glVertex2f(408,322-130);
	glEnd();
	glFlush();

	glColor3f(0.7,0.2,0.2);//keyboard
	glBegin(GL_POLYGON);
	glVertex2f(327,325-130);
	glVertex2f(408,325-130);
	glVertex2f(408,322-130);
	glVertex2f(327,322-130);
	glEnd();
	glFlush();



	glColor3f(0.7,0.0,0.2); //horizontal lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(335,345-130);
	glVertex2f(400,345-130);
	glVertex2f(333,340-130);
	glVertex2f(402,340-130);
	glVertex2f(331,335-130);
	glVertex2f(404,335-130);
	glVertex2f(329,330-130);
	glVertex2f(406,330-130);
	glVertex2f(327,325-130);
	glVertex2f(408,325-130);
	glEnd();
	glFlush();



    glColor3f(0.7,0.0,0.2); //vertical lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(339,322-130);
	glVertex2f(347,350-130);
	glVertex2f(353,322-130);
	glVertex2f(357,350-130);
	glVertex2f(367,322-130);
	glVertex2f(367,350-130);
	glVertex2f(381,322-130);
	glVertex2f(377,350-130);
	glVertex2f(395,322-130);
	glVertex2f(387,350-130);
	glEnd();
	glFlush();


/*
	glColor3f(0.3,0.6,0.8);//connectin wire
	glBegin(GL_LINES);
	glVertex2f(155,360);
	glVertex2f(330,360);
	glEnd();
	glFlush();

	//Rectangle to slowly be filled
				
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(140, 230);
	glVertex2f(140, 300);
	glVertex2f(320, 300);
	glVertex2f(320, 230);
	glEnd();
*/

	glFlush();

}

void window_prog_sender1_both(float a)
{
	int width = 80, height = 10, x = 170, y = 90;
	float progress, value = a, max_value = 140;
	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();

	progress = value / max_value;
	
	glColor3f(0.184314 ,0.309804 ,0.309804);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x+progress*width, y);
	glVertex2f(x+progress*width, y+height);
	glVertex2f(x, y+height);
	glEnd();
	
}


void window_prog_sender2_both(float a)
{
	int width = 80, height = 10, x = 170, y = 350;
	float progress, value = a, max_value = 140;
	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();

	progress = value / max_value;
	
	glColor3f(0.137255, 0.556863, 0.137255);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x+progress*width, y);
	glVertex2f(x+progress*width, y+height);
	glVertex2f(x, y+height);
	glEnd();
	
}

void draw_packet(float x, float y)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x+5, y);
	glVertex2f(x+5, y+5);
	glVertex2f(x, y+5);
	glEnd();
}

static float pac_x = 107.5, pac_y = 325;
static float px = 107.5, py = 190;

void fill_rect1_both(int a, int low)
{
	int width = 180, height = low, x = 140, y = 230;
	float progress, value = a, max_value = 140;
	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();

	progress = value / max_value;
	
	glColor3f(0.184314 ,0.309804 ,0.309804);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x+width, y);
	glVertex2f(x+width, y+progress*height);
	glVertex2f(x, y+progress*height);
	glEnd();
}

void fill_rect2_both(int a, int high)
{
	int width = 180, height = high, x = 140, y = 300;
	float progress, value = a, max_value = 140;
	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y - height);
	glVertex2f(x, y - height);
	glEnd();

	progress = value / max_value;
	
	glColor3f(0.137255, 0.556863, 0.137255);

	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x+width, y);
	glVertex2f(x+width, y-progress*height);
	glVertex2f(x, y-progress*height);
	glEnd();

}

static int progress1 = 0, progress2 = 0, height1 = 35, height2 = 35;
static int updater = 5, count = 0;
static int cur, prev;
static float p1, p2;

static int vec[] = {};

void print_data()
{
	system("clear");
	printf("Heaight 1:%d\nHeaight 2:%d\nWindow_size1:%d\nWindow_size2:%d\nProgress sum:%d\nCount = %d\n\n", height1, height2, progress1, progress2, progress1+progress2, count);
	printf("\n%d\n", cur/2);
}

void idle()
{
	if(height1 <= 70 && height1 >= 0){
		
		print_data();
	
		progress1++;
		progress2++;

		p1++;
		p2++;

		cur++;

		if(progress1 + progress2 > 280)
		{
			count ++;
			height1 = height1 + 2;
			height2 = height2 - 2;

			progress1 = (70 - updater) ;
			progress2 = (70 + updater) ;

			cur = (prev + cur) /2;
			prev = cur;
			
			prev = cur;

			p1 = p1 + 0.5;
			p2 = p2 - 0.5;

			printf("%d", count++);
		}

		if (pac_x == 107.5 && pac_y <= 325 && pac_y >290)
		pac_y--;

	else if (pac_y == 290 )
		pac_x ++;

	if(pac_y == 290 && pac_x == 140.5)
	{
		pac_x = 107.5;
		pac_y = 325;
	}

	if(px == 107.5 && py <=240 && py >= 190)
		py++;

	else if (py == 241)
		px ++;	
	
	if (px >= 140.5 && py == 241)
	{
	
		px = 107.5;
		py = 190;
	}
/*
		else if(progress1 + progress2 == 280)
		{
			height1 = 35;
			height2 = 35;
			progress1 = 0;
			progress2 = 0;
		}
*/				
		count ++;
	}
	
	glutPostRedisplay();
}
 

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	computer();
	glFlush();

	window_prog_sender1_both(p1 / 2);
	window_prog_sender2_both(p2 / 2);
	fill_rect1_both(progress1, height1);
	fill_rect2_both(progress2, height2);

	glPushMatrix();
	draw_packet(px, py);
	draw_packet(pac_x, pac_y);
	glutSwapBuffers();
	glPopMatrix();

	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
  	glutInitWindowPosition(0,0);
	glutInitWindowSize(1800,1000);
	glutCreateWindow("");
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	init();
	glutIdleFunc(idle);
	glutMainLoop();
	
	return 0;  

}
