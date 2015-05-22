#include <GL/glut.h>
#include <stdio.h>
#include "SOIL.h"

#define HEIGHT 1800
#define WIDTH 1000

double rotate_y = 0, rotate_x = 0;
GLuint texture;

static int flag;

float ver[4][3] = {
        {-2.0, -2.0, 0.5},
        {-2.0, 2.0, 0.5},
        {2.0, 2.0, 0.5},
        {2.0, -2.0, 0.5},
};


void my_key(unsigned char ch, int x, int y)
{
	if(ch)
		exit(0);
}


void quad(int a,int b,int c,int d)
{
        glPushMatrix();
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3fv(ver[a]);
        glTexCoord2f(1,0);
        glVertex3fv(ver[b]);
        glTexCoord2f(1,1);
        glVertex3fv(ver[c]);
        glTexCoord2f(0,1);
        glVertex3fv(ver[d]);
        glEnd();
        glPopMatrix();
}

void draw_background(GLuint texture)
{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glBindTexture(GL_TEXTURE_2D, texture);
        quad(0,3,2,1);

        glDisable(GL_TEXTURE_2D);
}

void display()
{
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        int w = glutGet(GLUT_WINDOW_WIDTH);
        int h = glutGet(GLUT_WINDOW_HEIGHT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluPerspective(5.0, w/h, 0.1, 100.0);
        gluLookAt(0, 0, 50, 0, 0, 40, 0, 1, 0);       
        draw_background(texture);
        glutSwapBuffers();
}

/*
void my_key(unsigned char ch, int x, int y)
{
	if(ch)
		exit(0);
}
*/

void get_texture(char *val)
{
        texture = SOIL_load_OGL_texture
                (
                        val,
                        SOIL_LOAD_AUTO,
                        SOIL_CREATE_NEW_ID,
                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                        );
}

int main(int argc, char *argv[])
{
        glutInit(&argc, argv);
	
        glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
        glutInitWindowSize(HEIGHT, WIDTH);
        glutCreateWindow("TCP AONGESTION AVOIDANCE");
        glutDisplayFunc(display);
	glutKeyboardFunc(my_key);
        glEnable(GL_DEPTH_TEST);
        get_texture(argv[1]);
        glutMainLoop();
        return 0;
}
