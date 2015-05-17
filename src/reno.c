#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *currentfont;

void *fonts[]=
{
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,
GLUT_BITMAP_HELVETICA_18,
GLUT_BITMAP_HELVETICA_12
};

static int progress = 0;

void mykey(unsigned char key, int x, int y)
{
	if(key)
		exit(0);
}


void setFont_reno(void *font)
{
	currentfont=font;
}


void drawstring_reno(float x,float y,float z,const char *string)
{
	const char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string; *c!='\0'; c++)
	{	
		glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void myInit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
}

void computer()									// to draw the sender and receiver computers
{


	glColor3f(0.0f,0.0f,0.0f);
	setFont_reno(GLUT_BITMAP_HELVETICA_18);
 	drawstring_reno(95.0,420.0,1.0,"SENDER");

 	glColor3f(0.0f,0.0f,0.0f);
	setFont_reno(GLUT_BITMAP_HELVETICA_18);
 	drawstring_reno(95.0,420.0-250,1.0,"SENDER");

	glColor3f(0.0f,0.0f,0.0f);
	setFont_reno(GLUT_BITMAP_HELVETICA_18);
 	drawstring_reno(345.0,420.0-135,1.0,"RECEIVER");

	glColor3f(0.0f,0.0f,0.0f);
	setFont_reno(GLUT_BITMAP_HELVETICA_18);
 	drawstring_reno(185.0,380.0,1.0,"SENDER CONGESTION WINDOW, RENO");

	glColor3f(0.0f,0.0f,0.0f);
	setFont_reno(GLUT_BITMAP_HELVETICA_18);
 	drawstring_reno(185.0,60.0,1.0,"SENDER CONGESTION WINDOW, RENO");

	glColor3f(0.0f,0.0f,0.0f);
	setFont_reno(GLUT_BITMAP_HELVETICA_18);
 	drawstring_reno(185.0,215.0,1.0,"NETWORK CHANNEL BANDWIDTH");

	glColor3f(0.0, 0.0, 0.0);
	setFont_reno(GLUT_BITMAP_HELVETICA_12);
	drawstring_reno(370, 10, 1.0, "Press any key to go back after animation is complete");

	
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

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_PROJECTION);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void window_prog_sender1_reno(int a)
{
	int width = 80, height = 15, x = 170, y = 90;
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
	glFlush();
}


void window_prog_sender2_reno(int a)
{
	int width = 80, height = 15, x = 170, y = 350;
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
	glFlush();
}

void fill_rect1_reno(int a)
{
	int width = 180, height = 35, x = 140, y = 230;
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
	glFlush();
}

void fill_rect2_reno(int a)
{
	int width = 180, height = 35, x = 140, y = 300;
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
	glFlush();
}

void idle_test()
{
	if(++progress == 139)
		progress = 70;

	glutPostRedisplay();
}

void display()
{
	computer();
	glFlush();

	window_prog_sender1_reno(progress/2);
	window_prog_sender2_reno(progress/2);
	fill_rect1_reno(progress);
	fill_rect2_reno(progress);

	glFlush();
}
/*
void display_reno(void)
{
	int i, fin_count = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	computer();
	glFlush();

	for(i = 0 ; i <= 140; i++)
	{
		window_prog_sender1_reno(i/2);
		window_prog_sender2_reno(i/2);
		if(i == 139)
		{
			i = 70;
			fin_count++;
			printf("%d", fin_count);
			fflush(NULL);
			blackify();
		}
		fill_rect1_reno(i);
		fill_rect2_reno(i);
		usleep(20000);
		//fin_count++;
		glFlush();

		if(fin_count == 20) {
			//usleep(2000000);
			//exit(0);
			return ;
		}
	}
	glFlush();
}
*/
int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
  	glutInitWindowPosition(0,0);
	glutInitWindowSize(1800,1000);
	glutCreateWindow("");
	glutDisplayFunc(display);
	glutIdleFunc(idle_test);
	glutKeyboardFunc(mykey);
	init();
	glutMainLoop();
	
	return 0;  

}
