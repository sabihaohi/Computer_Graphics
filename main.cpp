#include<cstdio>
#include <windows.h>
#include <GL/glut.h>
#include<math.h>
# define PI 3.14159265358979323846

//----dayRiver----
void dayRiver(){
    //GL_QUADS
    glBegin(GL_QUADS);
        glColor3ub(214, 234, 248);
    glVertex2f(-1.0f, -0.3f); //down left
        glColor3ub(36, 113, 163);
    glVertex2f(-1.0f, 0.2f); //top left
        glColor3ub(36, 113, 163);
    glVertex2f(1.0f, 0.2f); //top right
        glColor3ub(214, 234, 248);
    glVertex2f(1.0f, -0.08f); //down right

    glEnd();
}

//------nightRiver---
void nightRiver(){
    //GL_QUADS
    glBegin(GL_QUADS);
	glColor3ub(21, 67, 96);

    glVertex2f(-1.0f, -0.4f);
	glVertex2f(-1.0f, 0.2f);
	glVertex2f(1.0f, 0.2f);
    glColor3ub(133, 193, 233); //color mixing
	glVertex2f(1.0f, -0.15f);

	glEnd();
}


void rainyRiver(){
    //GL_QUADS
    glBegin(GL_QUADS);
	glColor3ub(21, 67, 96);

    glVertex2f(-1.0f, -0.4f);
	glVertex2f(-1.0f, 0.2f);
        glColor3ub(153, 163, 164); //color mixing
	glVertex2f(1.0f, 0.2f);
	glVertex2f(1.0f, -0.15f);

	glEnd();
}

void eveningRiver(){
    //GL_QUADS
    glBegin(GL_QUADS);
	glColor3ub(191, 201, 202);

    glVertex2f(-1.0f, -0.4f);
        glColor3ub(93, 109, 126); //color mixing
	glVertex2f(-1.0f, 0.2f);
        glColor3ub(133, 146, 158); //color mixing
	glVertex2f(1.0f, 0.2f);
        glColor3ub(214, 234, 248); //color mixing
	glVertex2f(1.0f, -0.15f);

	glEnd();
}

void daySky(){
    //GL_QUADS
    glBegin(GL_QUADS);
        glColor3ub(84, 153, 199); //up left corner
    glVertex2f(-1.1f, 1.0f);
        glColor3ub(135, 206, 235); //up right corner
    glVertex2f(1.1f, 1.0f);
        glColor3ub(251, 252, 252); //color mixing
    glVertex2f(1.1f, -0.1f);
        glColor3ub(251, 252, 252); //color mixing
    glVertex2f(-1.1f, -0.4f);



    glEnd();
}

void eveningSky(){
    //GL_QUADS
    glBegin(GL_QUADS);
    glColor4f(0.8f, 0.7f, 0.5f, 1.0f);
    glVertex2f(-1.1f, 1.0f);
        glColor3ub(235, 222, 240); //color mixing
	glVertex2f(1.1f, 1.0f);
        glColor3ub(250, 215, 160); //color mixing
	glVertex2f(1.1f, -0.1f);
        glColor3ub(215, 189, 226); //color mixing
	glVertex2f(-1.1f, -0.4f);
	glEnd();
}

void rainySky(){
    //GL_QUADS
    glBegin(GL_QUADS);
    glColor3ub(242, 243, 244);
    glVertex2f(-1.1f, 1.0f);
        glColor3ub(178, 186, 187); //color mixing
	glVertex2f(1.1f, 1.0f);
        glColor3ub(113, 125, 126); //color mixing
	glVertex2f(1.1f, -0.1f);
        glColor3ub(97, 106, 107); //color mixing
	glVertex2f(-1.1f, -0.4f);

	glEnd();
}

void dayBeach(){
    //GL_QUADS
    glBegin(GL_QUADS);
        glColor3ub(194, 178, 128);
    glVertex2f(-1.0f, -0.3f); //top left
        glColor3ub(194, 178, 128);
    glVertex2f(1.0f, -0.08f); //top right
        glColor3ub(246, 221, 204);
    glVertex2f(1.0f, -1.0f); //down right
        glColor3ub(246, 221, 204);
    glVertex2f(-1.0f, -1.0f); //down left



    glEnd();
}

float shipXPosition = 0.0f; // Initial position of the ship on the x-axis
float shipYPosition = 0.15f; // Initial position of the ship on the y-axis
float shipSpeed = 0.001f;

void nightBeach(){
	//GL_QUADS
    glBegin(GL_QUADS);
        glColor3ub(102, 99, 98);
    glVertex2f(-1.0f, -0.4f); //top left
        glColor3ub(147, 111, 93);
    glVertex2f(1.0f, -0.1f); //top right
        glColor3ub(102, 99, 98);
	glVertex2f(1.0f, -1.0f); //down right
        glColor3ub(147, 111, 93);
	glVertex2f(-1.0f, -1.0f); //down left

	glEnd();
}

void eveningBeach(){
	//GL_QUADS
    glBegin(GL_QUADS);
        glColor3ub(213, 219, 219);
    glVertex2f(-1.0f, -0.4f); //top left
        glColor3ub(213, 219, 219);
    glVertex2f(1.0f, -0.15f); //top right
        glColor3ub(246, 221, 204);
	glVertex2f(1.0f, -1.0f); //down right
        glColor3ub(246, 221, 204);
	glVertex2f(-1.0f, -1.0f); //down left

	glEnd();
}

GLfloat positionCloud1 = 0.4f;
GLfloat speed = 0.009f; //declared globally for every movable object... ... ...SPEED... ... ...!!! !!! !!!

void updateCloud1(int value) {

    if(positionCloud1 <-1.0)
        positionCloud1 = 1.0f;

    positionCloud1 -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, updateCloud1, 0);
}
void cloud1(){

    glPushMatrix();
    glTranslatef(-positionCloud1,0.0f,0.0f);


    //circle-1
	int jeight;
	GLfloat p8=.34f; GLfloat q8=.8f; GLfloat radius8 =.08f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p8, q8); // center of circle
		for(jeight = 0; jeight <= triangleAmount8; jeight++) {
			glVertex2f(
		            p8 + (radius8 * cos(jeight *  twicePi8 / triangleAmount8)),
			    q8 + (radius8 * sin(jeight * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	//circle-2
	int jnine;

	GLfloat p9=.41f; GLfloat q9=.87f; GLfloat radius9 =.07f;
	int triangleAmount9 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p9, q9); // center of circle
		for(jnine = 0; jnine <= triangleAmount9; jnine++) {
			glVertex2f(
		            p9 + (radius9 * cos(jnine *  twicePi9 / triangleAmount9)),
			    q9 + (radius9 * sin(jnine * twicePi9 / triangleAmount9))
			);
		}
	glEnd();

	//circle-3
	int jten;

	GLfloat p10=.30f; GLfloat q10=.87f; GLfloat radius10 =.08f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p10, q10); // center of circle
		for(jten = 0; jten <= triangleAmount10; jten++) {
			glVertex2f(
		            p10 + (radius10 * cos(jten *  twicePi10 / triangleAmount10)),
			    q10 + (radius10* sin(jten * twicePi10 / triangleAmount10))
			);
		}
	glEnd();

	//circle-4
	int jeleven;

	GLfloat p11=.45f; GLfloat q11=.8f; GLfloat radius11 =.08f;
	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p11, q11); // center of circle
		for(jeleven = 0; jeleven <= triangleAmount11; jeleven++) {
			glVertex2f(
		            p11 + (radius11 * cos(jeleven *  twicePi11 / triangleAmount11)),
			    q11 + (radius11* sin(jeleven * twicePi11 / triangleAmount11))
			);
		}
	glEnd();

	glPopMatrix();
}


GLfloat positionCloud2 = 0.5f;
//GLfloat speed = 0.1f;

void updateCloud2(int value) {

    if(positionCloud2 <-1.5)
        positionCloud2 = 1.0f;

    positionCloud2 -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, updateCloud2, 0);
}


void cloud2(){

    glPushMatrix();
    glTranslatef(-positionCloud2, 0.0f, 0.0f);

    //circle-1
	int j;

	GLfloat p=-.5f; GLfloat q=.77f; GLfloat radius1 =.09f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p, q); // center of circle
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f(
		            p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
			    q + (radius1 * sin(j * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	//circle-2
	int jj;

	GLfloat p2=-.4f; GLfloat q2=.77f; GLfloat radius2 =.09f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p2, q2); // center of circle
		for(jj = 0; jj <= triangleAmount1;jj++) {
			glVertex2f(
		            p2 + (radius2 * cos(jj *  twicePi2 / triangleAmount2)),
			    q2 + (radius2 * sin(jj * twicePi2 / triangleAmount2))
			);
		}
	glEnd();
	//circle-3
	int jjj;

	GLfloat p3=-.3f; GLfloat q3=.77f; GLfloat radius3 =.09f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p3, q3); // center of circle
		for(jjj = 0; jjj <= triangleAmount1;jjj++) {
			glVertex2f(
		            p3 + (radius3 * cos(jjj *  twicePi3 / triangleAmount3)),
			    q3 + (radius3 * sin(jjj * twicePi3 / triangleAmount3))
			);
		}
	glEnd();



	//circle-4
	int jfour;

	GLfloat p4=-.2f; GLfloat q4=.77f; GLfloat radius4 =.09f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p4, q4); // center of circle
		for(jfour = 0; jfour <= triangleAmount4;jfour++) {
			glVertex2f(
		            p4 + (radius4 * cos(jfour *  twicePi4 / triangleAmount4)),
			    q4 + (radius4 * sin(jfour * twicePi4 / triangleAmount4))
			);
		}
	glEnd();

	//circle-5
	int jfive;

	GLfloat p5=-.25f; GLfloat q5=.82f; GLfloat radius5 =.09f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p5, q5); // center of circle
		for(jfive = 0; jfive <= triangleAmount5; jfive++) {
			glVertex2f(
		            p5 + (radius5 * cos(jfive *  twicePi5 / triangleAmount5)),
			    q5 + (radius5 * sin(jfive * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	//circle-6
	int jsix;

	GLfloat p6=-.35f; GLfloat q6=.86f; GLfloat radius6 =.09f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p6, q6); // center of circle
		for(jsix = 0; jsix <= triangleAmount6; jsix++) {
			glVertex2f(
		            p6 + (radius6 * cos(jsix *  twicePi6 / triangleAmount6)),
			    q6 + (radius6 * sin(jsix * twicePi6 / triangleAmount6))
			);
		}
	glEnd();

	//circle-7
	int jsvn;

	GLfloat p7=-.45f; GLfloat q7=.82f; GLfloat radius7 =.09f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(253, 254, 254);
		glVertex2f(p7, q7); // center of circle
		for(jsvn = 0; jsvn <= triangleAmount7; jsvn++) {
			glVertex2f(
		            p7 + (radius6 * cos(jsvn *  twicePi7 / triangleAmount7)),
			    q7 + (radius6 * sin(jsvn * twicePi7 / triangleAmount7))
			);
		}
	glEnd();

	glPopMatrix();
}
GLfloat position = 0.0f;
//GLfloat speed = 0.009f;

void update(int value) {

    if(position <-1.0)
        position = 1.0f;

    position -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}


GLfloat position1 = 0.0f;
//GLfloat speed = 0.1f;

void update1(int value) {

    if(position1 <-1.0)
        position1 = 1.0f;

    position1 -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}



GLfloat positionBellon = 0.0f;
void updateBellon(int value) {

    if(positionBellon >1.0)
        positionBellon = -1.0f;

    positionBellon += speed;

	glutPostRedisplay();


	glutTimerFunc(300, updateBellon, 0);
}


void hotBellon(){
    glPushMatrix();
     glTranslatef(positionBellon,0.0f, 0.0f);

glColor3ub(205, 92 ,92);
	int j;
	GLfloat x=-0.3f; GLfloat y=0.7f; GLfloat radius =.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(255 ,255 ,0);

	glVertex2f(-0.35f,  0.35f);
	glVertex2f(-0.3f, 0.425f);
	glVertex2f(-0.25f, 0.35f);

	glEnd();

			//GL_QUADS
    glBegin(GL_QUADS);
	glColor3ub(139, 69 ,19);

	glVertex2f(-0.35f, 0.3f);
	glVertex2f(-0.4f, 0.4f);
	glVertex2f(-0.2f, 0.4f);
	glVertex2f(-0.25f, 0.3f);

	glEnd();

	    glBegin(GL_TRIANGLES);
	glColor3ub(205,92,92);

	glVertex2f(-0.4f,  0.675f);
	glVertex2f(-0.2f, 0.675f);
	glVertex2f(-0.3f, 0.5f);

	glEnd();

    glBegin(GL_LINES);
	glColor3ub(139, 69 ,19);
	glVertex2f(-0.4f, 0.7f);
	glVertex2f(-0.35f, 0.3f);

	glEnd();

    glBegin(GL_LINES);
	glColor3ub(139, 69 ,19);
	glVertex2f(-0.2f, 0.7f);
	glVertex2f(-0.25f, 0.3f);

	glEnd();

    glBegin(GL_LINES);
	glColor3ub(139, 69 ,19);
	glVertex2f(-0.3f, 0.7f);
	glVertex2f(-0.3f, 0.3f);

	glEnd();

	glPopMatrix();



   glFlush();


}

//plane
GLfloat position2 = -0.7f;
GLfloat speedn = 0.015f;

void update2(int value){

    if(position2 >1.4)
        position2 = -1.0f;

    position2 += speedn;

	glutPostRedisplay();


	glutTimerFunc(100, update2, 0);
}

void plane(){
    glPushMatrix();
   glTranslatef(position2,0.0f, 0.0f);

    //main body
    glBegin(GL_POLYGON);
            glColor3ub(255, 212, 128);
        glVertex2f(0.0f, 0.72f);
        glVertex2f(0.3f, 0.72f);
        glVertex2f(0.31f, 0.715f);
        glVertex2f(0.32f, 0.705f);
        glVertex2f(0.33f, 0.695f);
        glVertex2f(0.34f, 0.683f);
        glVertex2f(0.36f, 0.67f);
        glVertex2f(0.37f, 0.66f);
        glVertex2f(0.376f, 0.64f);
        glVertex2f(0.37f, 0.63f);
            glColor3ub(255, 187, 51);
        glVertex2f(0.3f, 0.605f);
        glVertex2f(0.07f, 0.6f);
        glVertex2f(0.05f, 0.605f);
        glVertex2f(0.03f, 0.610f);
        glVertex2f(0.0f, 0.615f);
        glVertex2f(-0.02f, 0.620f);
        glVertex2f(-0.05f, 0.628f);
        glVertex2f(-0.075f, 0.636f);
        glVertex2f(-0.085f, 0.645f);
        glVertex2f(-0.092f, 0.645f);
        glVertex2f(-0.1f, 0.658f);
        glVertex2f(-0.13f, 0.665f);
        glVertex2f(-0.11f, 0.680f);
        glVertex2f(-0.1f, 0.688f);
        glVertex2f(-0.05f, 0.7f);
        glVertex2f(-0.04f, 0.71f);
	glEnd();

    //Back stand
    glBegin(GL_POLYGON);
            glColor3ub(230, 138, 0);
        glVertex2f(-0.13f, 0.68f);
            glColor3ub(255, 194, 102);
        glVertex2f(-0.045f, 0.680f);
        glVertex2f(-0.04f, 0.67f);
        glVertex2f(-0.045f, 0.66f);
        glVertex2f(-0.13f, 0.66f);
        glVertex2f(-0.135f, 0.67f);
	glEnd();

	//back rudder
    glBegin(GL_POLYGON);
            glColor3ub(255, 133, 102);
        glVertex2f(-0.12f, 0.83f);
        glVertex2f(-0.1f, 0.828f);
        glVertex2f(-0.096f, 0.825f);
        glVertex2f(-0.086f, 0.820f);
        glVertex2f(-0.074f, 0.810f);
        glVertex2f(-0.045f, 0.74f);
        glVertex2f(-0.043f, 0.720f);
        glVertex2f(0.01f, 0.72f);
            glColor3ub(255, 184, 77);
        glVertex2f(-0.085f, 0.693f);
	glEnd();

	//right wing
    glBegin(GL_QUADS);
            glColor3ub(255, 204, 153);
        glVertex2f(0.05f, 0.55f);
        glVertex2f(0.0f, 0.55f);
            glColor3ub(255, 166, 77);
        glVertex2f(0.1f, 0.62f);
        glVertex2f(0.2f, 0.62f);
	glEnd();

    //left wing
    glBegin(GL_QUADS);
            glColor3ub(255, 166, 77);
        glVertex2f(0.2f, 0.72f);
        glVertex2f(0.1f, 0.72f);
            glColor3ub(255, 204, 153);
        glVertex2f(0.0f, 0.78f);
        glVertex2f(0.08f, 0.78f);
	glEnd();

	//door
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(-0.01f, 0.68f);
        glVertex2f(0.0f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.0f, 0.64f);
        glVertex2f(-0.01f, 0.64f);
	glEnd();

    //side windows --- from LEFT_TO_RIGHT
    //1
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.03f, 0.68f);
        glVertex2f(0.02f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.02f, 0.66f);
        glVertex2f(0.03f, 0.66f);
	glEnd();
	//2
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.05f, 0.68f);
        glVertex2f(0.04f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.04f, 0.66f);
        glVertex2f(0.05f, 0.66f);
	glEnd();
	//3
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.07f, 0.68f);
        glVertex2f(0.06f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.06f, 0.66f);
        glVertex2f(0.07f, 0.66f);
	glEnd();
	//4
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.09f, 0.68f);
        glVertex2f(0.08f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.08f, 0.66f);
        glVertex2f(0.09f, 0.66f);
	glEnd();
	//5
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.11f, 0.68f);
        glVertex2f(0.10f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.10f, 0.66f);
        glVertex2f(0.11f, 0.66f);
	glEnd();
	//6
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.13f, 0.68f);
        glVertex2f(0.12f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.12f, 0.66f);
        glVertex2f(0.13f, 0.66f);
	glEnd();
	//7
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.15f, 0.68f);
        glVertex2f(0.14f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.14f, 0.66f);
        glVertex2f(0.15f, 0.66f);
	glEnd();
	//8
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.17f, 0.68f);
        glVertex2f(0.16f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.16f, 0.66f);
        glVertex2f(0.17f, 0.66f);
	glEnd();
	//9
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.19f, 0.68f);
        glVertex2f(0.18f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.18f, 0.66f);
        glVertex2f(0.19f, 0.66f);
	glEnd();
	//10
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.21f, 0.68f);
        glVertex2f(0.20f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.20f, 0.66f);
        glVertex2f(0.21f, 0.66f);
	glEnd();
	//11
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.23f, 0.68f);
        glVertex2f(0.22f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.22f, 0.66f);
        glVertex2f(0.23f, 0.66f);
	glEnd();
	//12
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.25f, 0.68f);
        glVertex2f(0.24f, 0.68f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.24f, 0.66f);
        glVertex2f(0.25f, 0.66f);
	glEnd();


	//front windows
    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.34f, 0.68f);
        glVertex2f(0.33f, 0.67f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.31f, 0.694f);
        glVertex2f(0.32f, 0.705f);
	glEnd();

    glBegin(GL_QUADS);
            glColor3ub(173, 173, 133);
        glVertex2f(0.327f, 0.670f);
        glVertex2f(0.31f, 0.662f);
            glColor3ub(194, 194, 163);
        glVertex2f(0.295f, 0.69f);
        glVertex2f(0.309f, 0.693f);
	glEnd();


    glPopMatrix();
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void chair1(){


//Chair3 Umbrella
glBegin(GL_TRIANGLES);
    glColor3ub(199, 0, 57);
    glVertex2f(0.25f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.1f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.175f + 0.7f + 0.05f + 0.06f, 0.025f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
glEnd();

//Chair3 Umbrella Stand
glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.06f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.06f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
glEnd();




//Chair
glBegin(GL_QUADS);
    glColor3ub(115, 147, 179);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair left label
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair back label
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.725f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair relaxer
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.725f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.675f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.68f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.635f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair legs - left front
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair legs - right front
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.8f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.8f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair legs - right back
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair legs - left back
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
glEnd();

//Chair2 Umbrella Stand
glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.04f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.04f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
glEnd();



//chair 2
glBegin(GL_QUADS);
    glColor3ub(115, 147, 179);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();

//chair 2 left label
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();

//chair 2 back label
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.725f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();

//chair 2 relaxer
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.725f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.675f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.68f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.635f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();

//chair 2 legs - left front
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();

//chair 2 legs - right front
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.8f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.8f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();

//chair 2 legs - right back
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();

//chair 2 legs - left back
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
glEnd();


//chair1 Umbrella
glBegin(GL_TRIANGLES);
glColor3ub(144, 12, 63);
glVertex2f(0.25f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
glVertex2f(0.1f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
glVertex2f(0.175f + 0.7f + 0.05f - 0.02f + 0.02f, 0.025f - 0.7f - 0.05f);
glEnd();

//Chair2 Umbrella
glBegin(GL_TRIANGLES);
    glColor3ub(88, 24, 69 );
    glVertex2f(0.25f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.1f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.175f + 0.7f + 0.05f + 0.04f, 0.025f - 0.7f - 0.05f + 0.2f - 0.06f);
glEnd();



//chair1 Umbrella Stand
glBegin(GL_QUADS);
glColor3ub(139, 69, 19);
glVertex2f(0.17875f + 0.7f + 0.05f - 0.02f + 0.02f, -0.225f - 0.7f - 0.05f);
glVertex2f(0.17125f + 0.7f + 0.05f - 0.02f + 0.02f, -0.225f - 0.7f - 0.05f);
glVertex2f(0.17125f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
glVertex2f(0.17875f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
glEnd();
//chair1
glBegin(GL_QUADS);
    glColor3ub(115, 147, 179);
    glVertex2f((0.65f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.4f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
glEnd();

//chair1 left label
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
glEnd();

//chair1 back label
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f ) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.65f + 1.05f + 0.1f ) * 0.5f, (-0.725f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
glEnd();

//chair1 relaxer
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f ) * 0.5f, (-0.725f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.625f + 1.05f + 0.1f ) * 0.5f, (-0.675f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.68f + 1.05f + 0.1f ) * 0.5f, (-0.635f - 1.0f - 0.1f) * 0.5f);
glEnd();

//chair1 legs - left front
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.365f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.365f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
glEnd();

//chair1 legs - right front
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.4f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.415f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.415f + 1.05f + 0.1f ) * 0.5f, (-0.8f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.4f + 1.05f + 0.1f ) * 0.5f, (-0.8f - 1.0f - 0.1f) * 0.5f);
glEnd();

//chair1 legs - right back
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.645f + 1.05f + 0.1f ) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.645f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.625f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.625f + 1.05f + 0.1f ) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
glEnd();

//chair1 legs - left back
glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.58f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.58f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
glEnd();



}



//Horse
void horse(){
    glPushMatrix();
    glTranslatef(0.0f ,0.17f, 0.0f);
    glScalef(0.7f ,1.3f, 0.0f);

    glBegin(GL_POLYGON);
        glColor3ub(92, 65, 45);
        glVertex2f(-0.038f, -0.48f);
        glVertex2f(-0.038f, -0.487f);
        glVertex2f(-0.027f, -0.494f);
        glVertex2f(-0.005f, -0.494f);
        glVertex2f(-0.005f, -0.49f);
        glVertex2f(-0.023f, -0.48f);
        glVertex2f(-0.038f, -0.48f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.05f, -0.44f);
        glVertex2f(-0.06f, -0.44f);
        glVertex2f(-0.07f, -0.458f);
        glVertex2f(-0.069f, -0.464f);
        glVertex2f(-0.06f, -0.464f);
        glVertex2f(-0.05f, -0.46f);
        glVertex2f(-0.05f, -0.44f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.162f, -0.452f);
        glVertex2f(-0.17f, -0.46f);
        glVertex2f(-0.17f, -0.47f);
        glVertex2f(-0.15f, -0.483f);
        glVertex2f(-0.14f, -0.483f);
        glVertex2f(-0.14f, -0.47f);
        glVertex2f(-0.15f, -0.452f);
        glVertex2f(-0.162f, -0.452f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.212f, -0.472f);
        glVertex2f(-0.212f, -0.49f);
        glVertex2f(-0.200f, -0.492f);
        glVertex2f(-0.177f, -0.49f);
        glVertex2f(-0.192f, -0.472f);
        glVertex2f(-0.212f, -0.472f);
    glEnd();


    //leg
    glBegin(GL_POLYGON);
        glColor3ub(140, 63, 4);
        glVertex2f(-0.05f, -0.44f);
        glVertex2f(-0.05f, -0.46f);
        glVertex2f(-0.00f, -0.42f);
        glVertex2f(-0.002f, -0.4f);
        glVertex2f(-0.02f, -0.36f);
        glVertex2f(-0.03f, -0.4f);
        glVertex2f(-0.02f, -0.416f);
        glVertex2f(-0.05f, -0.44f);
    glEnd();

       glBegin(GL_POLYGON);
        glColor3ub(140, 63, 4);
        glVertex2f(-0.038f, -0.48f);
        glVertex2f(-0.023f, -0.48f);
        glVertex2f(-0.023f, -0.4654f);
        glVertex2f(-0.022f, -0.46f);
        glVertex2f(-0.03f, -0.42f);
        glVertex2f(-0.02f, -0.38f);
        glVertex2f(-0.06f, -0.38f);
        glVertex2f(-0.06f, -0.41f);
        glVertex2f(-0.05f, -0.42f);
        glVertex2f(-0.045f, -0.45f);
        glVertex2f(-0.038f, -0.48f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(140, 63, 4);
        glVertex2f(-0.162f, -0.452f);
        glVertex2f(-0.15f, -0.452f);
        glVertex2f(-0.155f, -0.4458f);
        glVertex2f(-0.158f, -0.39f);
        glVertex2f(-0.18f, -0.38f);
        glVertex2f(-0.167f, -0.44f);
        glVertex2f(-0.162f, -0.452f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(140, 63, 4);
        glVertex2f(-0.212f, -0.472f);
        glVertex2f(-0.192f, -0.472f);
        glVertex2f(-0.205f, -0.455f);
        glVertex2f(-0.205f, -0.430f);
        glVertex2f(-0.175f, -0.42f);
        glVertex2f(-0.17f, -0.41f);
        glVertex2f(-0.16f, -0.39f);
        glVertex2f(-0.16f, -0.38f);
        glVertex2f(-0.215f, -0.38f);
        glVertex2f(-0.21f, -0.4f);
        glVertex2f(-0.2f, -0.41f);
        glVertex2f(-0.225f, -0.424f);
        glVertex2f(-0.225f, -0.44f);
        glVertex2f(-0.225f, -0.455f);
        glVertex2f(-0.212f, -0.472f);
    glEnd();


    //Body
    glBegin(GL_POLYGON);
        glColor3ub(140, 63, 4);
        glVertex2f(-0.215f, -0.38f);
        glVertex2f(-0.20f, -0.34f);
        glVertex2f(-0.18f, -0.32f);
        glVertex2f(-0.15f, -0.32f);
        glVertex2f(-0.1f, -0.33f);
        glVertex2f(-0.06f, -0.32f);
        glVertex2f(-0.01f, -0.384f);
        glVertex2f(-0.02f, -0.38f);
        glVertex2f(-0.08f, -0.41f);
        glVertex2f(-0.1f, -0.42f);
        glVertex2f(-0.12f, -0.42f);
        glVertex2f(-0.13f, -0.41f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(140, 63, 4);
        glVertex2f(-0.06f, -0.32f);
        glVertex2f(-0.02f, -0.23f);
        glVertex2f(0.00f, -0.24f);
        glVertex2f(0.03f, -0.32f);
        glVertex2f(0.02f, -0.34f);
        glVertex2f(0.01f, -0.3f);
        glVertex2f(-0.02f, -0.38f);


    glEnd();


    //Tail
    glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.19f, -0.34f);
        glVertex2f(-0.22f, -0.33f);
	glEnd();
	glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.22f, -0.33f);
        glVertex2f(-0.25f, -0.37f);
	glEnd();

	glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.22f, -0.33f);
        glVertex2f(-0.25f, -0.36f);
	glEnd();

	glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.22f, -0.33f);
        glVertex2f(-0.25f, -0.38f);
	glEnd();

	//Eye
	glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.01f, -0.27f);
        glVertex2f(0.0f, -0.28f);
	glEnd();

	//Hair
	glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.01f, -0.24f);
        glVertex2f(-0.05f, -0.32f);
	glEnd();

	glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.01f, -0.24f);
        glVertex2f(-0.05f, -0.33f);
	glEnd();
	glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.01f, -0.24f);
        glVertex2f(-0.05f, -0.31f);
	glEnd();
	glBegin(GL_LINES);
        glColor3ub(101, 42, 11);
        glVertex2f(-0.01f, -0.233f);
        glVertex2f(-0.05f, -0.3f);
	glEnd();

    //man
    glBegin(GL_POLYGON);
        glColor3ub(195, 53, 38);
        glVertex2f(-0.145f, -0.32f);
        glVertex2f(-0.145f, -0.37f);
        glVertex2f(-0.08f, -0.37f);
        glVertex2f(-0.08f, -0.32f);
    glEnd();


    glBegin(GL_POLYGON);
        glColor3ub(200, 93, 120);
        glVertex2f(-0.095f, -0.32f);
        glVertex2f(-0.08f, -0.37f);
        glVertex2f(-0.11f, -0.41f);
        glVertex2f(-0.1f, -0.41f);
        glVertex2f(-0.13f, -0.41f);
        glVertex2f(-0.1f, -0.39f);
        glVertex2f(-0.145f, -0.32f);
        glVertex2f(-0.145f, -0.3f);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 110, 40);
        glVertex2f(-0.095f, -0.32f);
        glVertex2f(-0.145f, -0.3f);
        glVertex2f(-0.14f, -0.28f);
        glVertex2f(-0.12f, -0.24f);
        glVertex2f(-0.11f, -0.25f);
        glVertex2f(-0.1f, -0.28f);


    glEnd();

    //Hand
	glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.12f, -0.25f);
        glVertex2f(-0.09f, -0.3f);
	glEnd();
	glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.095f, -0.3f);
        glVertex2f(-0.06f, -0.3f);
	glEnd();

	//Man Hair
    glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.12f, -0.24f);
        glVertex2f(-0.135f, -0.22f);
        glVertex2f(-0.13f, -0.2f);
        glVertex2f(-0.11f, -0.2f);


    glEnd();

    //Man Face
    glBegin(GL_POLYGON);
        glColor3ub(250, 200, 170);
        glVertex2f(-0.12f, -0.24f);
        glVertex2f(-0.11f, -0.2f);
        glVertex2f(-0.09f, -0.2f);
        glVertex2f(-0.09f, -0.22f);
        glVertex2f(-0.08f, -0.23f);
        glVertex2f(-0.09f, -0.21f);
        glVertex2f(-0.1f, -0.26f);


    glEnd();


    //cap
    glBegin(GL_POLYGON);
        glColor3ub(250, 20, 55);
        glVertex2f(-0.13f, -0.2f);
        glVertex2f(-0.11f, -0.2f);
        glVertex2f(-0.09f, -0.2f);
        glVertex2f(-0.07f, -0.18f);
        glVertex2f(-0.09f, -0.2f);
        glVertex2f(-0.105f, -0.18f);
        glVertex2f(-0.12f, -0.18f);


    glEnd();

glPopMatrix();
}


bool objectVisible = false; // Flag to control object visibility
bool objectVisible2 = false; // Flag to control object visibility

// Timer callback function to hide the object after the specified time


void hideObject(int value) {
    objectVisible = false;
    glutPostRedisplay(); // Mark the window for redrawing

}

void hideObject2(int value) {
    objectVisible2 = false;
    glutPostRedisplay(); // Mark the window for redrawing
}

void horsepic(){
    if (objectVisible) {
            glPushMatrix();
            glTranslatef(0.3f ,-0.4f, 0.0f);
            glScalef(0.5f ,0.7f, 0.0f);

            glBegin(GL_POLYGON);
                glColor3ub(255,255, 255);
                glVertex2f(0.05f, -0.05f);
                glVertex2f(-0.2f, -0.05f);
                glVertex2f(-0.2f, -0.5f);
                glVertex2f(0.05f, -0.5f);
            glEnd();

            horse();
            glPopMatrix();

        }
        if(objectVisible2){
        glBegin(GL_POLYGON);
            glColor3ub(255,255, 255);
            glVertex2f(1.00f, 1.00f);
            glVertex2f(-1.0f, 1.0f);
            glVertex2f(-1.0f, -1.0f);
            glVertex2f(1.0f, -1.0f);
        glEnd();
    }


}


GLfloat positionBoat = 0.0f;

void updateBoat(int value) {

    if(positionBoat <-1.5)
        positionBoat = 1.0f;

    positionBoat -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, updateBoat, 0);
}


void boat(){
    glPushMatrix();
     glTranslatef(positionBoat,0.0f, 0.0f);

    //Man
    glBegin(GL_POLYGON);
        glColor3ub(254, 25, 172);
        glVertex2f(0.16f, 0.04f);
        glVertex2f(0.17f, 0.06f);
        glVertex2f(0.18f, 0.06f);
        glVertex2f(0.18f, 0.03f);

    glEnd();

    //circle-1
	int j;

	GLfloat p=0.175f; GLfloat q=.07f; GLfloat radius1 =.01f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0, 0, 0);
		glVertex2f(p, q); // center of circle
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f(
		            p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
			    q + (radius1 * sin(j * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	//circle-1
	int jj;

	GLfloat pp=0.17f; GLfloat qq=.065f; GLfloat radius11 =.01f;
	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(254, 198, 172);
		glVertex2f(pp, qq); // center of circle
		for(jj = 0; jj <= triangleAmount11;jj++) {
			glVertex2f(
		            pp + (radius1 * cos(jj *  twicePi1 / triangleAmount11)),
			    qq + (radius1 * sin(jj * twicePi1 / triangleAmount11))
			);
		}
	glEnd();

        //glBegin(GL_POLYGON);
        //glColor3ub(0, 0, 0);
        //glVertex2f(0.17f, 0.06f);
        //glVertex2f(0.18f, 0.06f);
        //glVertex2f(0.18f, 0.07f);
        //glVertex2f(0.17f, 0.07f);

    //glEnd();


    glBegin(GL_POLYGON);
        glColor3ub(230, 117, 85);
        glVertex2f(0.0f, 0.06f);
        glVertex2f(0.1f, 0.06f);
        glVertex2f(0.14f, 0.05f);
        glVertex2f(0.22f, 0.04f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.02f, 0.04f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(35, 40, 131);
        glVertex2f(0.1f, 0.06f);
        glVertex2f(0.14f, 0.05f);
        glVertex2f(0.16f, 0.07f);
        glVertex2f(0.12f, 0.08f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(35, 40, 131);
        glVertex2f(0.01f, 0.05f);
        glVertex2f(0.2f, 0.015f);
        glVertex2f(0.015f, 0.04f);
    glEnd();

    //water
    glBegin(GL_POLYGON);
        glColor3ub(135, 181, 210);
        glVertex2f(0.16f, 0.00f);
        glVertex2f(0.18f, 0.01f);
        glVertex2f(0.17f, 0.00f);
        glVertex2f(0.22f, 0.04f);
        glVertex2f(0.21f, 0.02f);
        glVertex2f(0.25f, 0.06f);
        glVertex2f(0.25f, 0.04f);
        glVertex2f(0.3f, 0.07f);
        glVertex2f(0.32f, 0.02f);
        glVertex2f(0.25f, -0.03f);
        glVertex2f(0.2f, -0.04f);
        glVertex2f(0.15f, -0.03f);
        glVertex2f(0.1f, -0.03f);
        glVertex2f(0.05f, -0.00f);
        glVertex2f(0.01f, 0.04f);
    glEnd();

glPopMatrix();

}


GLfloat positionBoat2 = 0.2f;

void updateBoat2(int value) {

    if(positionBoat2 <-1.5)
        positionBoat2 = 1.0f;

    positionBoat2 -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, updateBoat2, 0);
}

void boat2(){
    glPushMatrix();
     glTranslatef(positionBoat2,0.0f, 0.0f);

    //Man
    glBegin(GL_POLYGON);
        glColor3ub(254, 25, 172);
        glVertex2f(0.16f, 0.04f);
        glVertex2f(0.17f, 0.06f);
        glVertex2f(0.18f, 0.06f);
        glVertex2f(0.18f, 0.03f);

    glEnd();

    //circle-1
	int j;

	GLfloat p=0.175f; GLfloat q=.07f; GLfloat radius1 =.01f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0, 0, 0);
		glVertex2f(p, q); // center of circle
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f(
		            p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
			    q + (radius1 * sin(j * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	//circle-1
	int jj;

	GLfloat pp=0.17f; GLfloat qq=.065f; GLfloat radius11 =.01f;
	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(254, 198, 172);
		glVertex2f(pp, qq); // center of circle
		for(jj = 0; jj <= triangleAmount11;jj++) {
			glVertex2f(
		            pp + (radius1 * cos(jj *  twicePi1 / triangleAmount11)),
			    qq + (radius1 * sin(jj * twicePi1 / triangleAmount11))
			);
		}
	glEnd();

        //glBegin(GL_POLYGON);
        //glColor3ub(0, 0, 0);
        //glVertex2f(0.17f, 0.06f);
        //glVertex2f(0.18f, 0.06f);
        //glVertex2f(0.18f, 0.07f);
        //glVertex2f(0.17f, 0.07f);

    //glEnd();


    glBegin(GL_POLYGON);
        glColor3ub(230, 117, 85);
        glVertex2f(0.0f, 0.06f);
        glVertex2f(0.1f, 0.06f);
        glVertex2f(0.14f, 0.05f);
        glVertex2f(0.22f, 0.04f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.02f, 0.04f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(35, 40, 131);
        glVertex2f(0.1f, 0.06f);
        glVertex2f(0.14f, 0.05f);
        glVertex2f(0.16f, 0.07f);
        glVertex2f(0.12f, 0.08f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(35, 40, 131);
        glVertex2f(0.01f, 0.05f);
        glVertex2f(0.2f, 0.015f);
        glVertex2f(0.015f, 0.04f);
    glEnd();

    //water
    glBegin(GL_POLYGON);
        glColor3ub(135, 181, 210);
        glVertex2f(0.16f, 0.00f);
        glVertex2f(0.18f, 0.01f);
        glVertex2f(0.17f, 0.00f);
        glVertex2f(0.22f, 0.04f);
        glVertex2f(0.21f, 0.02f);
        glVertex2f(0.25f, 0.06f);
        glVertex2f(0.25f, 0.04f);
        glVertex2f(0.3f, 0.07f);
        glVertex2f(0.32f, 0.02f);
        glVertex2f(0.25f, -0.03f);
        glVertex2f(0.2f, -0.04f);
        glVertex2f(0.15f, -0.03f);
        glVertex2f(0.1f, -0.03f);
        glVertex2f(0.05f, -0.00f);
        glVertex2f(0.01f, 0.04f);
    glEnd();

glPopMatrix();

}


void wheel(float x, float y, float radius){
        int j;

        GLfloat p= x; GLfloat q = y; GLfloat radius1=radius;
        int triangleAmount1 = 20; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi1 = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(p, q); // center of circle
            for(j = 0; j <= triangleAmount1;j++) {
                glVertex2f(
                        p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
                    q + (radius1 * sin(j * twicePi1 / triangleAmount1))
                );
            }
    glEnd();
}

void wheel2(float x, float y, float radius){
        int j;

        GLfloat p= x; GLfloat q = y; GLfloat radius1=radius;
        int triangleAmount1 = 20; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi1 = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(200, 200, 200);
            glVertex2f(p, q); // center of circle
            for(j = 0; j <= triangleAmount1;j++) {
                glVertex2f(
                        p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
                    q + (radius1 * sin(j * twicePi1 / triangleAmount1))
                );
            }
    glEnd();
}


void face(float x, float y, float radius){
        int j;

        GLfloat p= x; GLfloat q = y; GLfloat radius1=radius;
        int triangleAmount1 = 20; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi1 = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(254, 198, 172);
            glVertex2f(p, q); // center of circle
            for(j = 0; j <= triangleAmount1;j++) {
                glVertex2f(
                        p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
                    q + (radius1 * sin(j * twicePi1 / triangleAmount1))
                );
            }
    glEnd();
}



GLfloat positioncar = 0.0f;

void updatecar(int value) {

    if(positioncar <-1.0)
        positioncar = 1.5f;

    positioncar -= speed;

	glutPostRedisplay();


	glutTimerFunc(100, updatecar, 0);
}

void car2(){
    glPushMatrix();
     glTranslatef(positioncar,0.0f, 0.0f);


        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.51f, -0.21f);
        glVertex2f(-0.53f, -0.23f);
        glVertex2f(-0.55f, -0.3f);
        glVertex2f(-0.49f, -0.23f);

        glEnd();


     //2nd
     wheel(-0.48f, -0.26f, 0.035f);

     glBegin(GL_POLYGON);
        glColor3ub(254, 201, 55);
        glVertex2f(-0.53f, -0.33f);
        glVertex2f(-0.47f, -0.33f);
        glVertex2f(-0.46f, -0.28f);
        glVertex2f(-0.37f, -0.23f);
        glVertex2f(-0.46f, -0.23f);
        glVertex2f(-0.46f, -0.21f);
        glVertex2f(-0.5f, -0.21f);


        glEnd();

    //circle-1
    //1st
	wheel(-0.6f, -0.25f, 0.035f);

    //4th
    wheel(-0.43f, -0.32f, 0.035f);
	wheel2(-0.43f, -0.32f, 0.02f);


        glBegin(GL_POLYGON);
        glColor3ub(254, 201, 55);
        glVertex2f(-0.58f, -0.25f);
        glVertex2f(-0.58f, -0.32f);
        glVertex2f(-0.52f, -0.32f);
        glVertex2f(-0.55f, -0.195f);
        glVertex2f(-0.57f, -0.2f);
        glVertex2f(-0.63f, -0.19f);
        glVertex2f(-0.63f, -0.23f);
        glVertex2f(-0.61f, -0.25f);


        glEnd();

        //3rd
        wheel(-0.55f, -0.33f, 0.035f);
        wheel2(-0.55f, -0.33f, 0.02f);

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.59f, -0.23f);
        glVertex2f(-0.57f, -0.17f);
        glVertex2f(-0.615f, -0.165f);
        glVertex2f(-0.61f, -0.23f);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(-0.63f, -0.17f);
        glVertex2f(-0.55f, -0.18f);
        glEnd();

        //man
        wheel(-0.5f, -0.12f, 0.02f);

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.5f, -0.12f);
        glVertex2f(-0.48f, -0.18f);
        glVertex2f(-0.49f, -0.23f);
        glVertex2f(-0.51f, -0.23f);
        glEnd();


        //Hand
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(-0.57f, -0.15f);
        glVertex2f(-0.5f, -0.15f);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(-0.53f, -0.165f);
        glVertex2f(-0.5f, -0.165f);
        glEnd();


    //Handle
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(-0.63f, -0.17f);
        glVertex2f(-0.57f, -0.15f);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(-0.55f, -0.18f);
        glVertex2f(-0.53f, -0.165f);
        glEnd();




glPopMatrix();

}


void car(){
    glPushMatrix();
   glTranslatef(positioncar,0.0f, 0.0f);


   //man
   glBegin(GL_POLYGON);
        glColor3ub(200, 39, 116);
        glVertex2f(-0.46f, -0.21f);
        glVertex2f(-0.46f, -0.26f);
        glVertex2f(-0.49f, -0.26f);
        glVertex2f(-0.48f, -0.21f);

    glEnd();
    wheel(-0.46f, -0.2f, 0.015f);
    face(-0.47f, -0.21f, 0.015f);



    glBegin(GL_POLYGON);
        glColor3ub(254, 201, 55);

        glVertex2f(-0.589f, -0.24f);  //1
        glVertex2f(-0.515f, -0.20f);//2
        glVertex2f(-0.475f, -0.23f);//3
        glVertex2f(-0.480f,-0.245f);//4
        glVertex2f(-0.395f,-0.258f);//5
        glVertex2f(-0.43f,-0.260f);//6
        glVertex2f(-0.475f,-0.295f);//7
        glVertex2f(-0.475f,-0.33f);//8
        glVertex2f(-0.510f,-0.33f);//9
        glVertex2f(-0.510f, -0.295f);//10
        glVertex2f(-0.55f, -0.275f);//11
        glVertex2f(-0.595f, -0.295f);//12
        glEnd();


    ///////////////////1

    wheel(-0.57f, -0.33f, 0.035f);

    wheel2(-0.57f, -0.33f, 0.02f);

    ///////////////////2

    wheel(-0.43f, -0.32f, 0.035f);

    wheel2(-0.43f, -0.32f, 0.02f);





   glPopMatrix();

}





GLfloat positionBird = 0.0f;

void updateBird(int value) {

    if(positionBird >1.0)
        positionBird = -1.0f;

    positionBird += speed;

	glutPostRedisplay();


	glutTimerFunc(100, updateBird, 0);
}

void bird1(){
//bird-1
    glPushMatrix();
     glTranslatef(positionBird,0.0f, 0.0f);
    //bird left wing
	glBegin(GL_TRIANGLES);
        glColor3ub(248, 196, 113); //light orange
        glVertex2f(0.37f, 0.42f);
        glVertex2f(0.32f, 0.44f);
        glVertex2f(0.37f, 0.4f);
	glEnd();

    //bird leaps
	glBegin(GL_TRIANGLES);
        glColor3ub(34, 153, 84); //green
        glVertex2f(0.45f, 0.41f);
        glVertex2f(0.45f, 0.43f);
        glVertex2f(0.47f, 0.41f);
	glEnd();

    //bird legs
	glBegin(GL_LINES);
        glColor3ub(44, 62, 80); //black
        glVertex2f(0.37f, 0.36f);
        glVertex2f(0.39f, 0.37f);
	glEnd();
    glBegin(GL_LINES);
        glColor3ub(44, 62, 80); //black
        glVertex2f(0.39f, 0.35f);
        glVertex2f(0.41f, 0.37f);
	glEnd();


	//circle-1 --- bird body
	int i;
	GLfloat x=.4f; GLfloat y=.4f; GLfloat radius =.04f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(213, 244, 13); //yellow
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();




    //circle-2 --- bird head
    int i1;
	GLfloat x1=.44f; GLfloat y1=.42f; GLfloat radius1 =.02f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 156, 18); //orange
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();



    //circle-3 --- bird eye
    int i11;
	GLfloat x11=.45f; GLfloat y11=.42f; GLfloat radius11 =.005f;
	int triangleAmount11 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 55, 70); //black
		glVertex2f(x11, y11); // center of circle
		for(i11 = 0; i11 <= triangleAmount11;i11++) {
			glVertex2f(
		            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
			);
		}
	glEnd();

    //bird right wing
	glBegin(GL_TRIANGLES);
        glColor3ub(248, 196, 113); //light orange
        glVertex2f(0.4f, 0.42f);
        glVertex2f(0.35f, 0.45f);
        glVertex2f(0.4f, 0.4f);
	glEnd();

	glPopMatrix();

	glFlush();
}


GLfloat positionBird2 = 0.0f;

void updateBird2(int value) {

    if(positionBird2 >1.0)
        positionBird2 = -1.0f;

    positionBird2 += speed;

	glutPostRedisplay();


	glutTimerFunc(100, updateBird2, 0);
}
void bird2(){
//bird-2

    glPushMatrix();
    glTranslatef(positionBird2,0.0f, 0.0f);

    //bird left wing
	glBegin(GL_TRIANGLES);
        glColor3ub(248, 196, 113); //light orange
        glVertex2f(0.57f, 0.62f);
        glVertex2f(0.52f, 0.63f);
        glVertex2f(0.57f, 0.6f);
	glEnd();

    //bird leaps
	glBegin(GL_TRIANGLES);
        glColor3ub(34, 153, 84); //green
        glVertex2f(0.65f, 0.61f);
        glVertex2f(0.65f, 0.63f);
        glVertex2f(0.67f, 0.61f);
	glEnd();

    //bird legs
	glBegin(GL_LINES);
        glColor3ub(44, 62, 80); //black
        glVertex2f(0.57f, 0.56f);
        glVertex2f(0.59f, 0.57f);
	glEnd();
    glBegin(GL_LINES);
        glColor3ub(44, 62, 80); //black
        glVertex2f(0.59f, 0.55f);
        glVertex2f(0.61f, 0.57f);
	glEnd();


	//circle-1 --- bird body
	int i2;
	GLfloat x2=.6f; GLfloat y2=.6f; GLfloat radius2 =.04f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(213, 244, 13); //yellow
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();




    //circle-2 --- bird head
    int i12;
	GLfloat x12=.64f; GLfloat y12=.62f; GLfloat radius12 =.02f;
	int triangleAmount12 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(243, 156, 18); //orange
		glVertex2f(x12, y12); // center of circle
		for(i12 = 0; i12 <= triangleAmount12;i12++) {
			glVertex2f(
		            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
			);
		}
	glEnd();



    //circle-3 --- bird eye
    int i112;
	GLfloat x112=.65f; GLfloat y112=.62f; GLfloat radius112 =.005f;
	int triangleAmount112 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi112 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(39, 55, 70); //black
		glVertex2f(x112, y112); // center of circle
		for(i112 = 0; i112 <= triangleAmount112;i112++) {
			glVertex2f(
		            x112 + (radius112 * cos(i112 *  twicePi112 / triangleAmount112)),
			    y112 + (radius112 * sin(i112 * twicePi112 / triangleAmount112))
			);
		}
	glEnd();

    //bird right wing
	glBegin(GL_TRIANGLES);
        glColor3ub(248, 196, 113); //light orange
        glVertex2f(0.6f, 0.62f);
        glVertex2f(0.55f, 0.65f);
        glVertex2f(0.6f, 0.6f);
	    glEnd();


		glPopMatrix();
        glFlush();
}

void ship() {
   glPushMatrix();
    //glTranslated(0.00, 0.0, 0.00);
    glScaled(0.015, 0.015, 1.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(3.5, 5.5);
    glVertex2f(3.5, 8.5);
    glVertex2f(19.5, 8.5);
    glVertex2f(19.5, 5.5);
    glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1,5.5);
		glVertex2f(4,1);
		glVertex2f(19,1);
		glVertex2f(21.5,5.5);
	glEnd();
	glColor3f(0.7,0.4,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(4,5.5);
		glVertex2f(4,8);
		glVertex2f(5,8);
		glVertex2f(5,5.5);
	glEnd();
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
		glVertex2f(7,7.5);
		glVertex2f(7,8);
		glVertex2f(10,8);
		glVertex2f(10,7.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(11.5,7.5);
		glVertex2f(11.5,8);
		glVertex2f(15,8);
		glVertex2f(15,7.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(16,7.5);
		glVertex2f(16,8);
		glVertex2f(19,8);
		glVertex2f(19,7.5);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(4.5,8.5);
		glVertex2f(4.5,10);
		glVertex2f(18.5,10);
		glVertex2f(18.5,8.5);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,10);
		glVertex2f(5.5,12.9);
		glVertex2f(7,12.9);
		glVertex2f(7,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,12.9);
		glVertex2f(5.5,13.5);
		glVertex2f(7,13.5);
		glVertex2f(7,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,10);
		glVertex2f(8.5,12.9);
		glVertex2f(10,12.9);
		glVertex2f(10,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(8.5,12.9);
		glVertex2f(8.5,13.5);
		glVertex2f(10,13.5);
		glVertex2f(10,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,10);
		glVertex2f(11.5,12.9);
		glVertex2f(13,12.9);
		glVertex2f(13,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(11.5,12.9);
		glVertex2f(11.5,13.5);
		glVertex2f(13,13.5);
		glVertex2f(13,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,10);
		glVertex2f(14.5,12.9);
		glVertex2f(16,12.9);
		glVertex2f(16,10);
	glEnd();
	glColor3f(0.9,0.5,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(14.5,12.9);
		glVertex2f(14.5,13.5);
		glVertex2f(16,13.5);
		glVertex2f(16,12.9);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(1.5,5.5);
		glVertex2f(1.5,6.5);
		glVertex2f(2,6.2);
		glVertex2f(3,6.2);
		glVertex2f(3.5,6.5);
		glVertex2f(3.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(3.5,5.5);
		glVertex2f(3.5,6.5);
		glVertex2f(4,6.2);
		glVertex2f(5,6.2);
		glVertex2f(5.5,6.5);
		glVertex2f(5.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(5.5,5.5);
		glVertex2f(5.5,6.5);
		glVertex2f(6,6.2);
		glVertex2f(7,6.2);
		glVertex2f(7.5,6.5);
		glVertex2f(7.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7.5,5.5);
		glVertex2f(7.5,6.5);
		glVertex2f(8,6.2);
		glVertex2f(9,6.2);
		glVertex2f(9.5,6.5);
		glVertex2f(9.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,5.5);
		glVertex2f(9.5,6.5);
		glVertex2f(10,6.2);
		glVertex2f(11,6.2);
		glVertex2f(11.5,6.5);
		glVertex2f(11.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(11.5,5.5);
		glVertex2f(11.5,6.5);
		glVertex2f(12,6.2);
		glVertex2f(13,6.2);
		glVertex2f(13.5,6.5);
		glVertex2f(13.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(13.5,5.5);
		glVertex2f(13.5,6.5);
		glVertex2f(14,6.2);
		glVertex2f(15,6.2);
		glVertex2f(15.5,6.5);
		glVertex2f(15.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15.5,5.5);
		glVertex2f(15.5,6.5);
		glVertex2f(16,6.2);
		glVertex2f(17,6.2);
		glVertex2f(17.5,6.5);
		glVertex2f(17.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17.5,5.5);
		glVertex2f(17.5,6.5);
		glVertex2f(18,6.2);
		glVertex2f(19,6.2);
		glVertex2f(19.5,6.5);
		glVertex2f(19.5,5.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(19.5,5.5);
		glVertex2f(19.5,6.5);
		glVertex2f(20,6.2);
		glVertex2f(20.5,6.2);
		glVertex2f(21,6.5);
		glVertex2f(21,5.5);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(4.5,3.5);
		glVertex2f(4.5,4.5);
		glVertex2f(5.5,4.5);
		glVertex2f(5.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7,3.5);
		glVertex2f(7,4.5);
		glVertex2f(8,4.5);
		glVertex2f(8,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9.5,3.5);
		glVertex2f(9.5,4.5);
		glVertex2f(10.5,4.5);
		glVertex2f(10.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(12,3.5);
		glVertex2f(12,4.5);
		glVertex2f(13,4.5);
		glVertex2f(13,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(14.5,3.5);
		glVertex2f(14.5,4.5);
		glVertex2f(15.5,4.5);
		glVertex2f(15.5,3.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(17,3.5);
		glVertex2f(17,4.5);
		glVertex2f(18,4.5);
		glVertex2f(18,3.5);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(5,10);
		glVertex2f(5,11);
		glVertex2f(5.5,10.8);
		glVertex2f(6.5,10.8);
		glVertex2f(7,11);
		glVertex2f(7,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(7,10);
		glVertex2f(7,11);
		glVertex2f(7.5,10.8);
		glVertex2f(8.5,10.8);
		glVertex2f(9,11);
		glVertex2f(9,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(9,10);
		glVertex2f(9,11);
		glVertex2f(9.5,10.8);
		glVertex2f(10.5,10.8);
		glVertex2f(11,11);
		glVertex2f(11,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(11,10);
		glVertex2f(11,11);
		glVertex2f(11.5,10.8);
		glVertex2f(12.5,10.8);
		glVertex2f(13,11);
		glVertex2f(13,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(13,10);
		glVertex2f(13,11);
		glVertex2f(13.5,10.8);
		glVertex2f(14.5,10.8);
		glVertex2f(15,11);
		glVertex2f(15,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(15,10);
		glVertex2f(15,11);
		glVertex2f(15.5,10.8);
		glVertex2f(16.5,10.8);
		glVertex2f(17,11);
		glVertex2f(17,10);
	glEnd();


    glPopMatrix();
}

void star(){
//star-1
	glBegin(GL_TRIANGLES);
        glColor3ub(226, 227, 244);
        glVertex2f(0.3f, 0.7f);
        glVertex2f(0.32f, 0.7f);
        glVertex2f(0.31f, 0.735f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(226, 227, 244);
        glVertex2f(0.3f, 0.72f);
        glVertex2f(0.32f, 0.72f);
        glVertex2f(0.31f, 0.69f);
	glEnd();

    //star-2
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.5f, 0.7f);
        glVertex2f(0.52f, 0.7f);
        glVertex2f(0.51f, 0.735f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.5f, 0.72f);
        glVertex2f(0.52f, 0.72f);
        glVertex2f(0.51f, 0.69f);
	glEnd();

    //star-3
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.4f, 0.8f);
        glVertex2f(0.42f, 0.8f);
        glVertex2f(0.41f, 0.835f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.4f, 0.82f);
        glVertex2f(0.42f, 0.82f);
        glVertex2f(0.41f, 0.79f);
	glEnd();

    //star-4
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.4f, 0.4f);
        glVertex2f(0.42f, 0.4f);
        glVertex2f(0.41f, 0.435f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.4f, 0.42f);
        glVertex2f(0.42f, 0.42f);
        glVertex2f(0.41f, 0.39f);
	glEnd();

    //star-5
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.8f, 0.4f);
        glVertex2f(0.82f, 0.4f);
        glVertex2f(0.81f, 0.435f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.8f, 0.42f);
        glVertex2f(0.82f, 0.42f);
        glVertex2f(0.81f, 0.39f);
	glEnd();

    //star-6
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.9f, 0.6f);
        glVertex2f(0.92f, 0.6f);
        glVertex2f(0.91f, 0.635f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.9f, 0.62f);
        glVertex2f(0.92f, 0.62f);
        glVertex2f(0.91f, 0.59f);
	glEnd();

    //star-7
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.9f, 0.6f);
        glVertex2f(-0.92f, 0.6f);
        glVertex2f(-0.91f, 0.635f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.9f, 0.62f);
        glVertex2f(-0.92f, 0.62f);
        glVertex2f(-0.91f, 0.59f);
	glEnd();

    //star-8
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.5f, 0.7f);
        glVertex2f(-0.52f, 0.7f);
        glVertex2f(-0.51f, 0.735f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.5f, 0.72f);
        glVertex2f(-0.52f, 0.72f);
        glVertex2f(-0.51f, 0.69f);
	glEnd();

    //star-9
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.7f, 0.7f);
        glVertex2f(-0.72f, 0.7f);
        glVertex2f(-0.71f, 0.735f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.7f, 0.72f);
        glVertex2f(-0.72f, 0.72f);
        glVertex2f(-0.71f, 0.69f);
	glEnd();

    //star-10
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.8f, 0.5f);
        glVertex2f(-0.82f, 0.5f);
        glVertex2f(-0.81f, 0.535f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.8f, 0.52f);
        glVertex2f(-0.82f, 0.52f);
        glVertex2f(-0.81f, 0.49f);
	glEnd();

    //star-11
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.2f, 0.6f);
        glVertex2f(-0.22f, 0.6f);
        glVertex2f(-0.21f, 0.635f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.2f, 0.62f);
        glVertex2f(-0.22f, 0.62f);
        glVertex2f(-0.21f, 0.59f);
	glEnd();

    //star-12
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(-0.02f, 0.7f);
        glVertex2f(-0.01f, 0.735f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.0f, 0.72f);
        glVertex2f(-0.02f, 0.72f);
        glVertex2f(-0.01f, 0.69f);
	glEnd();

    //star-13
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.05f, 0.9f);
        glVertex2f(0.07f, 0.9f);
        glVertex2f(0.06f, 0.935f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.05f, 0.92f);
        glVertex2f(0.07f, 0.92f);
        glVertex2f(0.06f, 0.89f);
	glEnd();

    //star-14
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.9f, 0.9f);
        glVertex2f(-0.92f, 0.9f);
        glVertex2f(-0.91f, 0.935f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(-0.9f, 0.92f);
        glVertex2f(-0.92f, 0.92f);
        glVertex2f(-0.91f, 0.89f);
	glEnd();

    //star-15
	glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.7f, 0.8f);
        glVertex2f(0.72f, 0.8f);
        glVertex2f(0.71f, 0.835f);
	glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(36, 113, 163);
        glVertex2f(0.7f, 0.82f);
        glVertex2f(0.72f, 0.82f);
        glVertex2f(0.71f, 0.79f);
	glEnd();


}


GLfloat positionRain = 0.0f;
GLfloat speed1 = 0.6f;

void updateRain(int value) {

    if(positionRain >1.0)
        positionRain = -1.0f;

    positionRain += speed1;

	glutPostRedisplay();


	glutTimerFunc(100, updateRain, 0);
}

void displayRain(){

    glPushMatrix();
    glTranslatef(0.0f,-positionRain, 0.0f);

//line1
    glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.9f, 1.0f);
	glVertex2f(-1.0f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.7f, 1.0f);
	glVertex2f(-0.8f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.5f, 1.0f);
	glVertex2f(-0.6f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.3f, 1.0f);
	glVertex2f(-0.4f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.1f, 1.0f);
	glVertex2f(-0.2f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.1f, 1.0f);
	glVertex2f(0.0f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.3f, 1.0f);
	glVertex2f(0.2f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.5f, 1.0f);
	glVertex2f(0.4f, 0.8f);

   glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.7f, 1.0f);
	glVertex2f(0.6f, 0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.9f, 1.0f);
	glVertex2f(0.8f, 0.8f);

	//line2
    glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.9f, 0.7f);
	glVertex2f(-1.0f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.7f, 0.7f);
	glVertex2f(-0.8f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.5f, 0.7f);
	glVertex2f(-0.6f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.3f, 0.7f);
	glVertex2f(-0.4f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.1f, 0.7f);
	glVertex2f(-0.2f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.1f, 0.7f);
	glVertex2f(0.0f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.3f, 0.7f);
	glVertex2f(0.2f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.5f, 0.7f);
	glVertex2f(0.4f, 0.5f);

   glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.7f, 0.7f);
	glVertex2f(0.6f, 0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.9f, 0.7f);
	glVertex2f(0.8f, 0.5f);


	//line3
    glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.9f, 0.4f);
	glVertex2f(-1.0f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.7f, 0.4f);
	glVertex2f(-0.8f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.5f, 0.4f);
	glVertex2f(-0.6f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.3f, 0.4f);
	glVertex2f(-0.4f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.1f, 0.4f);
	glVertex2f(-0.2f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.1f, 0.4f);
	glVertex2f(0.0f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.3f, 0.4f);
	glVertex2f(0.2f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.5f, 0.4f);
	glVertex2f(0.4f, 0.2f);

   glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.7f, 0.4f);
	glVertex2f(0.6f, 0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.9f, 0.4f);
	glVertex2f(0.8f, 0.2f);


		//line4
    glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.9f, 0.0f);
	glVertex2f(-1.0f, -0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.7f, 0.0f);
	glVertex2f(-0.8f, -0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.6f, -0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.4f, -0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.2f, -0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.0f, -0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.2f,-0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.4f, -0.2f);

   glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.7f, 0.0f);
	glVertex2f(0.6f, -0.2f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.9f, 0.0f);
	glVertex2f(0.8f, -0.2f);

		//line4
    glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.9f, -0.3f);
	glVertex2f(-1.0f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.7f, -0.3f);
	glVertex2f(-0.8f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.5f, -0.3f);
	glVertex2f(-0.6f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.4f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.1f, -0.3f);
	glVertex2f(-0.2f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.1f, -0.3f);
	glVertex2f(0.0f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.2f,-0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.5f, -0.3f);
	glVertex2f(0.4f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.7f, -0.3f);
	glVertex2f(0.6f, -0.5f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.9f, -0.3f);
	glVertex2f(0.8f, -0.5f);

    //line5
	glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.9f, -0.6f);
	glVertex2f(-1.0f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.7f, -0.6f);
	glVertex2f(-0.8f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.5f, -0.6f);
	glVertex2f(-0.6f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.3f, -0.6f);
	glVertex2f(-0.4f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.1f, -0.6f);
	glVertex2f(-0.2f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.0f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.3f, -0.6f);
	glVertex2f(0.2f,-0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.5f, -0.6f);
	glVertex2f(0.4f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.6f, -0.8f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.9f, -0.6f);
	glVertex2f(0.8f, -0.8f);

	    //line6
	glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.9f, -0.9f);
	glVertex2f(-1.0f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.7f, -0.9f);
	glVertex2f(-0.8f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.5f, -0.9f);
	glVertex2f(-0.6f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.3f, -0.9f);
	glVertex2f(-0.4f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.1f, -0.9f);
	glVertex2f(-0.2f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.1f, -0.9f);
	glVertex2f(0.0f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.3f, -0.9f);
	glVertex2f(0.2f,-1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.5f, -0.9f);
	glVertex2f(0.4f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.7f, -0.9f);
	glVertex2f(0.6f, -1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(0.9f, -0.9f);
	glVertex2f(0.8f, -1.0f);
	glEnd();

    glPopMatrix();

    glFlush();
}

void photographer(){


glPushMatrix();
glTranslatef(0.2f, -0.3f, 0.0f);
    glScalef(0.5, 0.5, 1.0);

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(55,55,0);
            glVertex2f(0.653f, -0.283f);
            glVertex2f(0.644f, -0.271f);
            glVertex2f(0.647f, -0.259f);
            glVertex2f(0.684f, -0.243f);
            glVertex2f(0.711f, -0.275f);
            glEnd();



            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(55,55,0);
            glVertex2f(0.840f, -0.243f);
            glVertex2f(0.840f, -0.235f);
            glVertex2f(0.849f, -0.219f);
            glVertex2f(0.853f, -0.188f);
            glVertex2f(0.851f, -0.176f);
            glVertex2f(0.864f, -0.215f);
            glVertex2f(0.864f, -0.243f);
            glVertex2f(0.860f, -0.259f);
            glVertex2f(0.856f, -0.271f);
            glVertex2f(0.847f, -0.287f);
            glVertex2f(0.827f, -0.283f);
            glVertex2f(0.827f, -0.267f);
            glVertex2f(0.833f, -0.251f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0,74,111);
            glVertex2f(0.776f, -0.172f);
            glVertex2f(0.776f, -0.211f);
            glVertex2f(0.778f, -0.243f);
            glVertex2f(0.780f, -0.271f);
            glVertex2f(0.789f, -0.283f);
            glVertex2f(0.798f, -0.287f);
            glVertex2f(0.816f, -0.251f);
            glVertex2f(0.831f, -0.235f);
            glVertex2f(0.842f, -0.227f);
            glVertex2f(0.853f, -0.196f);
            glVertex2f(0.853f, -0.18f);
            glVertex2f(0.849f, -0.172f);
            glVertex2f(0.840f, -0.172f);
            glVertex2f(0.831f, -0.188f);
            glVertex2f(0.804f, -0.211f);
            glVertex2f(0.804f, -0.188f);
            glVertex2f(0.811f, -0.148f);
            glVertex2f(0.820f, -0.125f);
            glVertex2f(0.829f, -0.097f);
            glVertex2f(0.793f, -0.073f);
            glVertex2f(0.771f, -0.061f);
            glVertex2f(0.716f, -0.061f);
            glVertex2f(0.707f, -0.073f);
            glVertex2f(0.696f, -0.105f);
            glVertex2f(0.691f, -0.148f);
            glVertex2f(0.684f, -0.204f);
            glVertex2f(0.682f, -0.239f);
            glVertex2f(0.709f, -0.279f);
            glVertex2f(0.720f, -0.128f);
            glVertex2f(0.731f, -0.097f);
            glVertex2f(0.784f, -0.117f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(255,255,9);
            glVertex2f(0.798f, 0.034f);
            glVertex2f(0.784f, -0.022f);
            glVertex2f(0.776f, -0.034f);
            glVertex2f(0.767f, -0.057f);
            glVertex2f(0.827f, -0.093f);
            glVertex2f(0.829f, -0.026f);
            glVertex2f(0.831f, 0.026f);
            glVertex2f(0.822f, 0.085f);
            glVertex2f(0.807f, 0.128f);
            glVertex2f(0.798f, 0.053f);
            glVertex2f(0.831f, 0.006f);
            glVertex2f(0.836f, -0.022f);
            glEnd();



            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(255,255,9);
            glVertex2f(0.764f, 0.105f);
            glVertex2f(0.773f, 0.121f);
            glVertex2f(0.780f, 0.144f);
            glVertex2f(0.787f, 0.144f);
            glVertex2f(0.778f, 0.101f);
            glVertex2f(0.780f, 0.069f);
            glVertex2f(0.773f, 0.042f);
            glVertex2f(0.767f, 0.065f);
            glVertex2f(0.760f, 0.081f);
            glVertex2f(0.753f, 0.105f);
            glVertex2f(0.764f, 0.109f);
            glVertex2f(0.760f, 0.109f);
            glEnd();


            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0,0,0);
            glVertex2f(0.833f, 0.038f);
            glVertex2f(0.836f, 0.014f);
            glVertex2f(0.836f, -0.002f);
            glVertex2f(0.836f, -0.014f);
            glVertex2f(0.798f, 0.053f);
            glVertex2f(0.796f, 0.042f);
            glVertex2f(0.836f, -0.022f);
            glVertex2f(0.836f, -0.089f);
            glVertex2f(0.831f, -0.077f);
            glVertex2f(0.844f, -0.081f);
            glVertex2f(0.856f, -0.061f);
            glVertex2f(0.862f, -0.045f);
            glVertex2f(0.862f, -0.026f);
            glVertex2f(0.862f, 0.002f);
            glVertex2f(0.856f, 0.018f);
            glVertex2f(0.853f, 0.042f);
            glVertex2f(0.829f, 0.117f);
            glVertex2f(0.816f, 0.148f);
            glVertex2f(0.791f, 0.16f);
            glVertex2f(0.784f, 0.148f);
            glVertex2f(0.807f, 0.128f);
            glVertex2f(0.816f, 0.113f);
            glVertex2f(0.822f, 0.097f);
            glVertex2f(0.829f, 0.077f);
            glVertex2f(0.833f, 0.057f);
            glEnd();



            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(128,128,0);
            glVertex2f(0.753f, 0.042f);
            glVertex2f(0.749f, 0.065f);
            glVertex2f(0.744f, 0.069f);
            glVertex2f(0.716f, -0.014f);
            glVertex2f(0.702f, -0.01f);
            glVertex2f(0.680f, 0.101f);
            glVertex2f(0.698f, 0.121f);
            glVertex2f(0.713f, 0.042f);
            glVertex2f(0.733f, 0.109f);
            glVertex2f(0.753f, 0.097f);
            glVertex2f(0.773f, 0.026f);
            glVertex2f(0.780f, 0.065f);
            glVertex2f(0.780f, 0.101f);
            glVertex2f(0.811f, 0.117f);
            glVertex2f(0.787f, -0.01f);
            glVertex2f(0.780f, -0.026f);
            glVertex2f(0.769f, -0.026f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(232,190,172);
            glVertex2f(0.738f, 0.164f);
            glVertex2f(0.733f, 0.132f);
            glVertex2f(0.736f, 0.109f);
            glVertex2f(0.740f, 0.105f);
            glVertex2f(0.742f, 0.093f);
            glVertex2f(0.749f, 0.093f);
            glVertex2f(0.751f, 0.093f);
            glVertex2f(0.753f, 0.097f);
            glVertex2f(0.760f, 0.101f);
            glVertex2f(0.762f, 0.101f);
            glVertex2f(0.762f, 0.101f);
            glVertex2f(0.764f, 0.101f);
            glVertex2f(0.764f, 0.105f);
            glVertex2f(0.773f, 0.121f);
            glVertex2f(0.782f, 0.136f);
            glVertex2f(0.782f, 0.164f);
            glVertex2f(0.789f, 0.211f);
            glVertex2f(0.787f, 0.231f);
            glVertex2f(0.787f, 0.251f);
            glVertex2f(0.780f, 0.263f);
            glVertex2f(0.771f, 0.271f);
            glVertex2f(0.762f, 0.275f);
            glVertex2f(0.742f, 0.279f);
            glVertex2f(0.722f, 0.271f);
            glVertex2f(0.713f, 0.259f);
            glVertex2f(0.702f, 0.223f);
            glVertex2f(0.693f, 0.2f);
            glVertex2f(0.711f, 0.184f);
            glVertex2f(0.722f, 0.196f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(128,128,0);
            glVertex2f(0.793f, 0.093f);
            glVertex2f(0.787f, 0.093f);
            glVertex2f(0.784f, 0.097f);
            glVertex2f(0.776f, 0.113f);
            glVertex2f(0.787f, 0.156f);
            glVertex2f(0.796f, 0.148f);
            glVertex2f(0.813f, 0.132f);
            glVertex2f(0.811f, 0.117f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(128,128,0);
            glVertex2f(0.758f, 0.085f);
            glVertex2f(0.760f, 0.057f);
            glVertex2f(0.756f, 0.053f);
            glVertex2f(0.736f, 0.089f);
            glVertex2f(0.749f, 0.136f);
            glVertex2f(0.753f, 0.109f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(78,78,78);
            glVertex2f(0.678f, 0.188f);
            glVertex2f(0.671f, 0.18f);
            glVertex2f(0.731f, 0.184f);
            glVertex2f(0.731f, 0.109f);
            glVertex2f(0.676f, 0.113f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(206,206,206);
            glVertex2f(0.698f, 0.152f);
            glVertex2f(0.704f, 0.156f);
            glVertex2f(0.711f, 0.148f);
            glVertex2f(0.707f, 0.128f);
            glVertex2f(0.700f, 0.125f);
            glVertex2f(0.696f, 0.132f);
            glVertex2f(0.693f, 0.152f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(22,22,22);
            glVertex2f(0.750f, 0.194f);
            glVertex2f(0.757f, 0.23f);
            glVertex2f(0.735f, 0.202f);
            glVertex2f(0.735f, 0.23f);
            glVertex2f(0.724f, 0.214f);
            glVertex2f(0.721f, 0.198f);
            glVertex2f(0.719f, 0.206f);
            glVertex2f(0.717f, 0.174f);
            glVertex2f(0.710f, 0.206f);
            glVertex2f(0.699f, 0.194f);
            glVertex2f(0.697f, 0.202f);
            glVertex2f(0.715f, 0.261f);
            glVertex2f(0.732f, 0.281f);
            glVertex2f(0.757f, 0.285f);
            glVertex2f(0.775f, 0.277f);
            glVertex2f(0.790f, 0.253f);
            glVertex2f(0.788f, 0.186f);
            glVertex2f(0.781f, 0.143f);
            glVertex2f(0.777f, 0.163f);
            glVertex2f(0.779f, 0.182f);
            glVertex2f(0.781f, 0.206f);
            glVertex2f(0.775f, 0.222f);
            glVertex2f(0.772f, 0.214f);
            glVertex2f(0.766f, 0.202f);
            glVertex2f(0.766f, 0.222f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(198,134,66);
            glVertex2f(0.732f, 0.139f);
            glVertex2f(0.739f, 0.143f);
            glVertex2f(0.735f, 0.123f);
            glVertex2f(0.730f, 0.115f);
            glVertex2f(0.730f, 0.103f);
            glVertex2f(0.741f, 0.107f);
            glVertex2f(0.746f, 0.119f);
            glVertex2f(0.755f, 0.127f);
            glVertex2f(0.750f, 0.127f);
            glVertex2f(0.746f, 0.159f);
            glVertex2f(0.741f, 0.17f);
            glVertex2f(0.730f, 0.186f);
            glVertex2f(0.721f, 0.186f);
            glVertex2f(0.721f, 0.174f);
            glVertex2f(0.732f, 0.163f);
            glVertex2f(0.737f, 0.159f);
            glVertex2f(0.726f, 0.151f);
            glVertex2f(0.719f, 0.143f);
            glVertex2f(0.724f, 0.127f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0,0,0);
            glVertex2f(0.830f, 0.008f);
            glVertex2f(0.830f, -0.011f);
            glVertex2f(0.832f, -0.023f);
            glVertex2f(0.832f, -0.047f);
            glVertex2f(0.830f, -0.079f);
            glVertex2f(0.830f, -0.102f);
            glVertex2f(0.830f, -0.094f);
            glVertex2f(0.839f, -0.079f);
            glVertex2f(0.837f, 0.04f);
            glVertex2f(0.815f, 0.123f);
            glVertex2f(0.812f, 0.111f);
            glVertex2f(0.821f, 0.076f);
            glVertex2f(0.826f, 0.068f);
            glVertex2f(0.830f, 0.044f);
            glVertex2f(0.830f, 0.032f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(232,190,172);
            glVertex2f(0.710f, 0.206f);
            glVertex2f(0.732f, 0.226f);
            glVertex2f(0.719f, 0.178f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(232,190,172);
            glVertex2f(0.715f, 0.174f);
            glVertex2f(0.715f, 0.202f);
            glVertex2f(0.724f, 0.174f);
            glVertex2f(0.715f, 0.174f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(53,53,0);
            glVertex2f(0.870f, -0.213f);
            glVertex2f(0.864f, -0.233f);
            glVertex2f(0.850f, -0.177f);
            glVertex2f(0.872f, -0.185f);
            glEnd();
glPopMatrix();
}
void Tower()        ///TOWER STRUCTURE
{
    glTranslatef(0.9, -0.3, 0.0);
    glScalef(0.4, 0.4, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2f(-0.15f, 0.28f);
    glVertex2f(-0.18f, 0.28f);
    glVertex2f(-0.18f, 0.1f);
    glVertex2f(-0.15f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2f(0.15f, 0.28f);
    glVertex2f(0.18f, 0.28f);
    glVertex2f(0.18f, 0.1f);
    glVertex2f(0.15f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2f, 0.32f);
    glVertex2f(0.2f, 0.32f);
    glVertex2f(0.2f, 0.28f);
    glVertex2f(-0.2f, 0.28f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2, 0.32);
    glVertex2f(0.0, 0.52);
    glVertex2f(0.2, 0.32);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, 0.65);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(188, 0, 0);
    glVertex2f(0.0, 0.6);
    glVertex2f(0.05, 0.625);
    glVertex2f(0.0, 0.65);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.3, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.3, -0.5);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(0.28, -0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.2, -0.1);
    glVertex2f(-0.28, -0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(0.08, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.08, -0.1);
    glVertex2f(-0.08, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glTranslatef(0.0, -0.05, 0.0);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glTranslatef(0.0, -0.05, 0.0);   ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);   ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glLoadIdentity();
}

void sun(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i = 0;
    float angle;

    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    for (i = 0; i <= 360; i++)
    {
        angle = i * PI / 180;
        glVertex2f(x + (cos(angle) * rx), y + (sin(angle) * ry));
    }
    glEnd();
}

void bamboo(){
    // water balloon
    glColor3f(1, 0, 0);
    sun(0.05, 0.02, 0.8, -0.3);
    glColor3f(0.0, 0.0, 0.1);
    sun(0.05, 0.02, 0.8, -0.28);
    glColor3f(0.0, 1, 0.0);
    sun(0.05, 0.02, 0.8, -0.26);
    glColor3f(1.0, 0, 1.0);
    sun(0.05, 0.02, 0.8, -0.24);
    glColor3f(0.4, 0.55, 0.05);
    sun(0.05, 0.02, 0.8, -0.22);
    glColor3f(1, 0.0, 0);
    sun(0.05, 0.02, 0.8, -0.20);
    glColor3f(0.4, 0.55, 0.05);
    sun(0.02, 0.005, 0.8, -0.20);

    // water balloon Bamboo
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.19, 0.12);
    glVertex3f(0.795, -0.16, 0);
    glVertex3f(0.805, -0.16, 0.0);
    glVertex3f(0.805, -0.207, 0);
    glVertex3f(0.795, -0.207, 0.0);
    glEnd();
}


//########################### SKY LOUNGE CODES START ############################

// Global Variables
GLfloat skyLoungePos = -0.87f;
GLfloat sittingPerPos = -4.0f;
GLfloat foodsPos1 = -4.0f;
GLfloat foodsPos2 = 4.0f;
GLfloat holderRopePos = -0.3f;
GLfloat standPerPos = -0.73f;
GLfloat waiterPos = 0.68f;
GLfloat personleg1Pos = -0.324f;
GLfloat personleg2Pos = -0.356f;

char standPerStatus = 'c';
char skyLoungeStatus = 'i';
char walkingFront = 'y';

void skl_sun(){
    glColor3ub(245, 176, 65);
	int j;
	GLfloat x=-0.8f; GLfloat y=0.9f; GLfloat radius =.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
			glColor3ub(245, 249, 10);
		}
	glEnd();
}

void skl_ship(){
    glPushMatrix();
    glTranslatef(shipXPosition, shipYPosition, 0.0);
    ship();
    glPopMatrix();
    shipXPosition += shipSpeed;
    if (shipXPosition > 1.0f) {
        shipXPosition = -1.0f;
    }
}

void skl_head(float x, float y){
    // Hair
    glColor3ub(1, 1, 1);
    GLfloat radius=0.025f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

	// Head
	float y2 = y-0.007f;
    glColor3ub(250, 250, 250);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y2); // center of circle
    for(int j = 0; j <= triangleAmount+1;j++) {
        glVertex2f(
            x + (radius * cos(j *  twicePi / triangleAmount)),
            y2 + (radius * sin(j * twicePi / triangleAmount))
        );
    }
	glEnd();

	// Mouth
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(1,1,1);
        glVertex2f(x+0.01f, y-0.015f);
        glVertex2f(x-0.01f, y-0.015f);
    glEnd();

    // Eyes
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(1,1,1);
        glVertex2f(x+0.015f, y);
        glVertex2f(x+0.005f, y);

        glVertex2f(x-0.005f, y);
        glVertex2f(x-0.015f, y);
    glEnd();
}

void skl_head2(float x, float y){
    glPushMatrix();
    // Hair
    glColor3ub(1, 1, 1);
    GLfloat radius=0.025f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

	// Head
	float x2 = x+0.007f;
	float y2 = y-0.004f;
	GLfloat radius2=0.023f;
    glColor3ub(250, 250, 250);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int j = 0; j <= triangleAmount+1;j++) {
        glVertex2f(
            x2 + (radius2 * cos(j *  twicePi / triangleAmount)),
            y2 + (radius2 * sin(j * twicePi / triangleAmount))
        );
    }
	glEnd();

    glPopMatrix();

	// Mouth
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(1,1,1);
        glVertex2f(x+0.02f, y-0.015f);
        glVertex2f(x+0.005f, y-0.015f);
    glEnd();

    // Eyes
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(1,1,1);
        glVertex2f(x+0.02f, y);
        glVertex2f(x+0.01f, y);

        glVertex2f(x+0.005f, y);
        glVertex2f(x-0.005f, y);
    glEnd();
}

void skl_plate(float x){
    glPushMatrix();

    //Plate Outer
	glColor3ub(250, 250, 250);
	int j;
	GLfloat y=0.068f; GLfloat radius=0.05f;
	int triangleAmount = 20; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

    //Plate Inner
	glColor3ub(178, 190, 181);
	int k;
	GLfloat x2=x; GLfloat y2=0.068f; GLfloat radius2=0.040f;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(k = 0; k <= triangleAmount+1;k++) {
			glVertex2f(
		            x2 + (radius2 * cos(k *  twicePi / triangleAmount)),
			    y2 + (radius2 * sin(k * twicePi / triangleAmount))
			);
		}
	glEnd();

	// Food
    glTranslatef(foodsPos1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glColor3ub(246, 226, 178);
        glVertex2f(x+0.015f, 0.1f);
        glVertex2f(x-0.03f, 0.05f);
        glVertex2f(x-0.03f, 0.05f);
        glVertex2f(x+0.015f, 0.05f);
	glEnd();

	glPopMatrix();
}

void skl_foods(){
    glPushMatrix();
    glScalef(0.9f, 0.9f, 0.0f);
    // Glass1
    // Glass Bottom
    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(250,250,250);
        glVertex2f(-0.215f, 0.05f);
        glVertex2f(-0.185f, 0.05f);
    glEnd();

    // Glass Stand
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(250,250,250);
        glVertex2f(-0.20f, 0.07f);
        glVertex2f(-0.20f, 0.05f);
    glEnd();

    // Glass
    glBegin(GL_QUADS);
        glColor3ub(250,250,250);
        glVertex2f(-0.22f, 0.12f);
        glVertex2f(-0.18f, 0.12f);
	    glVertex2f(-0.19f, 0.07f);
        glVertex2f(-0.21f, 0.07f);
	glEnd();

    // Drink
    glTranslatef(foodsPos1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glColor3ub(246,181,67);
        glVertex2f(-0.215f, 0.11f);
        glVertex2f(-0.185f, 0.11f);
	    glVertex2f(-0.193f, 0.075f);
        glVertex2f(-0.207f, 0.075f);
	glEnd();

	// Glass2
    glTranslatef(foodsPos2, 0.0f, 0.0f);
    // Glass Bottom
    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(250,250,250);
        glVertex2f(0.215f, 0.05f);
        glVertex2f(0.185f, 0.05f);
    glEnd();

    // Glass Stand
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(250,250,250);
        glVertex2f(0.20f, 0.07f);
        glVertex2f(0.20f, 0.05f);
    glEnd();

    // Glass
    glBegin(GL_QUADS);
        glColor3ub(250,250,250);
        glVertex2f(0.22f, 0.12f);
        glVertex2f(0.18f, 0.12f);
	    glVertex2f(0.19f, 0.07f);
        glVertex2f(0.21f, 0.07f);
	glEnd();

    // Drink
    glTranslatef(foodsPos1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glColor3ub(246,181,67);
        glVertex2f(0.215f, 0.11f);
        glVertex2f(0.185f, 0.11f);
	    glVertex2f(0.193f, 0.075f);
        glVertex2f(0.207f, 0.075f);
	glEnd();

    glTranslatef(foodsPos2, 0.0f, 0.0f);
    skl_plate(0.07f);
    skl_plate(-0.07f);

    glPopMatrix();
}

void skl_floor(){
    // Floor
    glBegin(GL_QUADS);
        glColor3ub(119,127,114);
        glVertex2f(-0.50f, -0.08f);

        glColor3ub(255,241,202);
        glVertex2f(0.50f, -0.08f);

        glColor3ub(255,241,202);
	    glVertex2f(0.55f, -0.35f);

	    glColor3ub(255,241,202);
        glVertex2f(-0.55f, -0.35f);
	glEnd();

	// Floor Shadow
    glBegin(GL_QUADS);
        glColor3ub(119,127,114);
        glVertex2f(-0.55f, -0.35f);
        glVertex2f(0.55f, -0.35f);
	    glVertex2f(0.55f, -0.42f);
        glVertex2f(-0.55f, -0.42f);
	glEnd();
}

void skl_roof(){
    // Roof Top
    glBegin(GL_QUADS);
        glColor3ub(249,246,241);
        glVertex2f(-0.40f, 0.55f);

	    glColor3ub(187,197,199);
        glVertex2f(0.40f, 0.55f);

        glColor3ub(198,206,209);
        glVertex2f(0.535f, 0.40f);

        glColor3ub(146,150,164);
        glVertex2f(-0.57f, 0.40f);
	glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.40f, 0.55f);
        glVertex2f(0.40f, 0.55f);

        glVertex2f(0.40f, 0.55f);
        glVertex2f(0.535f, 0.40f);

        glVertex2f(0.535f, 0.40f);
        glVertex2f(-0.57f, 0.40f);

        glVertex2f(-0.57f, 0.40f);
        glVertex2f(-0.40f, 0.55f);

        glVertex2f(-0.52f, 0.40f);
        glVertex2f(-0.40f, 0.55f);
    glEnd();

    // Ropes
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(0.45f, 0.40f);
        glVertex2f(0.45f, -0.10f);

        glVertex2f(0.50f, 0.40f);
        glVertex2f(0.50f, -0.30f);

        glVertex2f(-0.45f, 0.40f);
        glVertex2f(-0.45f, -0.10f);

        glVertex2f(-0.50f, 0.40f);
        glVertex2f(-0.50f, -0.30f);

        // Top Ropes
        glVertex2f(-0.005f, 0.65f);
        glVertex2f(-0.20f, 0.55f);

        glVertex2f(-0.005f, 0.65f);
        glVertex2f(-0.10f, 0.55f);

        glVertex2f(0.005f, 0.65f);
        glVertex2f(0.20f, 0.55f);

        glVertex2f(0.005f, 0.65f);
        glVertex2f(0.10f, 0.55f);
    glEnd();

    glColor3ub(20, 20, 20);
	int j;
	GLfloat x=0.0f; GLfloat y=0.65f; GLfloat radius=0.02f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void skl_table(){
    // Table Top
    glBegin(GL_QUADS);
        glColor3ub(119,127,114);
        glVertex2f(-0.25f, 0.12f);

        glColor3ub(203,174,140);
        glVertex2f(0.25f, 0.12f);

        glColor3ub(226,199,156);
	    glVertex2f(0.3f, 0.0f);

	    glColor3ub(53,89,93);
        glVertex2f(-0.3f, 0.0f);
	glEnd();

	// Table Top Shade
    glBegin(GL_QUADS);
        glColor3ub(119,127,114);
        glVertex2f(-0.3f, 0.0f);
	    glVertex2f(0.3f, 0.0f);
	    glVertex2f(0.3f, -0.025f);
        glVertex2f(-0.3f, -0.025f);
	glEnd();

    // Table Stand Right
    glBegin(GL_QUADS);
        glColor3ub(1,45,58);
	    glVertex2f(0.15f, -0.025f);
        glVertex2f(0.2f, -0.025f);
	    glVertex2f(0.15f, -0.2f);
        glVertex2f(0.10f, -0.2f);
	glEnd();

	// Table Stand Left
    glBegin(GL_QUADS);
        glColor3ub(1,45,58);
	    glVertex2f(-0.15f, -0.025f);
        glVertex2f(-0.2f, -0.025f);
	    glVertex2f(-0.15f, -0.2f);
        glVertex2f(-0.10f, -0.2f);
	glEnd();

	// Table Stand Bottom
    glBegin(GL_QUADS);
        glColor3ub(1,45,58);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(0.20f, -0.2f);
	    glVertex2f(0.20f, -0.208f);
        glVertex2f(-0.2f, -0.208f);
	glEnd();
}

void skl_chair1(){
    // Chair Ground
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.28f, -0.2f);
        glVertex2f(-0.38f, -0.2f);
    glEnd();

    // Chair Stand
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.33f, -0.2f);
        glVertex2f(-0.33f, -0.1f);
    glEnd();

    // Seat
    glBegin(GL_QUADS);
        glColor3ub(111,67,39);
        glVertex2f(-0.38f, -0.05f);
        glVertex2f(-0.29f, -0.05f);
	    glVertex2f(-0.28f, -0.10f);
        glVertex2f(-0.37f, -0.10f);
	glEnd();

    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.39f, 0.07f);
        glVertex2f(-0.37f, -0.10f);
    glEnd();
}

void skl_chair2(){
    // Chair Ground
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(0.28f, -0.2f);
        glVertex2f(0.38f, -0.2f);
    glEnd();

    // Chair Stand
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(0.33f, -0.2f);
        glVertex2f(0.33f, -0.1f);
    glEnd();

    // Seat
    glBegin(GL_QUADS);
        glColor3ub(111,67,39);
        glVertex2f(0.38f, -0.05f);
        glVertex2f(0.29f, -0.05f);
	    glVertex2f(0.28f, -0.10f);
        glVertex2f(0.37f, -0.10f);
	glEnd();

    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(0.39f, 0.07f);
        glVertex2f(0.37f, -0.10f);
    glEnd();
}

void skl_chair3(){
    // Chair Ground
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.03f, -0.3f);
        glVertex2f(0.07f, -0.3f);
    glEnd();

    // Chair Stand
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(0.02f, -0.3f);
        glVertex2f(0.02f, -0.2f);
    glEnd();

    // Seat
    glBegin(GL_QUADS);
        glColor3ub(111,67,39);
        glVertex2f(-0.03f, -0.15f);
        glVertex2f(0.06f, -0.15f);
	    glVertex2f(0.07f, -0.20f);
        glVertex2f(-0.02f, -0.20f);
	glEnd();

    glBegin(GL_QUADS);
        glColor3ub(10,10,10);
        glVertex2f(0.00f, -0.07f);
        glVertex2f(0.08f, -0.07f);
	    glVertex2f(0.06f, -0.21f);
        glVertex2f(-0.02f, -0.21f);
	glEnd();
}

void skl_chair4(){
    // Chair Ground
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.07f, -0.1f);
        glVertex2f(0.03f, -0.1f);
    glEnd();

    // Chair Stand
    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.02f, -0.1f);
        glVertex2f(-0.02f, 0.00f);
    glEnd();

    // Seat
    glBegin(GL_QUADS);
        glColor3ub(111,67,39);
        glVertex2f(-0.07f, 0.05f);
        glVertex2f(0.02f, 0.05f);
	    glVertex2f(0.03f, 0.00f);
        glVertex2f(-0.06f, 0.00f);
	glEnd();

    glBegin(GL_QUADS);
        glColor3ub(10,10,10);
        glVertex2f(-0.075f, 0.18f);
        glVertex2f(0.005f, 0.18f);
	    glVertex2f(0.015f, 0.05f);
        glVertex2f(-0.065f, 0.05f);
	glEnd();
}

void updatePersonStanding(int value){
    if(standPerStatus == 'c'){
        standPerPos = standPerPos + 0.006f;
    }
    else if(standPerStatus == 'g'){
        standPerPos = standPerPos + 0.006f;
    }


    if(standPerStatus == 'h'){
        standPerPos = -4.0f;
        sittingPerPos = 0.0f;
    }
    if(standPerPos > 0.50f && standPerStatus == 'c'){
        standPerStatus = 'h';
    }
    if(standPerPos > 1.65f && standPerStatus == 'g'){
        standPerStatus = 'c';
        standPerPos = -0.73f;
    }
    if(skyLoungeStatus == 'd'){
        standPerPos = 0.50f;
        sittingPerPos = -4.0f;
        standPerStatus = 'g';
        skyLoungeStatus = 'i';
    }

    if(walkingFront == 'y'){
        personleg1Pos = personleg1Pos - 0.002f;
        personleg2Pos = personleg2Pos + 0.002f;
    }
    else if(walkingFront == 'n'){
        personleg1Pos = personleg1Pos + 0.002f;
        personleg2Pos = personleg2Pos - 0.002f;
    }

    if(personleg1Pos < -0.355f){
        walkingFront = 'n';
    }
    if(personleg1Pos > -0.323f){
        walkingFront = 'y';
    }

    glutPostRedisplay();
	glutTimerFunc(100, updatePersonStanding, 0);
}

void skl_personStanding() {
    glPushMatrix();
    glTranslatef(standPerPos, -0.80f, 0.0f);

    // Person 2
    //Hand 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg1Pos, 0.01f);
    glEnd();

    // Body
    glBegin(GL_QUADS);
        glColor3ub(0,255,155);
        glVertex2f(-0.355f, 0.07f);
        glVertex2f(-0.327f, 0.07f);
	    glVertex2f(-0.327f, -0.03f);
        glVertex2f(-0.355f, -0.03f);
	glEnd();

    //Hand2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg2Pos, 0.01f);
    glEnd();

    // Head
    skl_head2(-0.345f, 0.1f);

    // Legs
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg1Pos, -0.09f);

        glVertex2f(personleg1Pos-0.002f, -0.09f);
        glVertex2f(personleg1Pos+0.015f, -0.09f);

        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg2Pos, -0.09f);

        glVertex2f(personleg2Pos-0.002f, -0.09f);
        glVertex2f(personleg2Pos+0.015f, -0.09f);
    glEnd();

    // Person 3
    glTranslatef(-0.075f, 0.0f, 0.0f);
    //Hand 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg1Pos, 0.01f);
    glEnd();

    // Body
    glBegin(GL_QUADS);
        glColor3ub(255,0,255);
        glVertex2f(-0.355f, 0.07f);
        glVertex2f(-0.327f, 0.07f);
	    glVertex2f(-0.327f, -0.03f);
        glVertex2f(-0.355f, -0.03f);
	glEnd();

    //Hand2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg2Pos, 0.01f);
    glEnd();


    // Head
    skl_head2(-0.345f, 0.1f);

    // Legs
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg1Pos, -0.09f);

        glVertex2f(personleg1Pos-0.002f, -0.09f);
        glVertex2f(personleg1Pos+0.015f, -0.09f);

        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg2Pos, -0.09f);

        glVertex2f(personleg2Pos-0.002f, -0.09f);
        glVertex2f(personleg2Pos+0.015f, -0.09f);
    glEnd();

    // Person 4
    glTranslatef(-0.075f, 0.0f, 0.0f);
    //Hand 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg1Pos, 0.01f);
    glEnd();

    // Body
    glBegin(GL_QUADS);
        glColor3ub(120, 120,120);
        glVertex2f(-0.355f, 0.07f);
        glVertex2f(-0.327f, 0.07f);
	    glVertex2f(-0.327f, -0.03f);
        glVertex2f(-0.355f, -0.03f);
	glEnd();

    //Hand2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg2Pos, 0.01f);
    glEnd();


    // Head
    skl_head2(-0.345f, 0.1f);

    // Legs
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg1Pos, -0.09f);

        glVertex2f(personleg1Pos-0.002f, -0.09f);
        glVertex2f(personleg1Pos+0.015f, -0.09f);

        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg2Pos, -0.09f);

        glVertex2f(personleg2Pos-0.002f, -0.09f);
        glVertex2f(personleg2Pos+0.015f, -0.09f);
    glEnd();

    // Person 1
    glTranslatef(-0.075f, 0.0f, 0.0f);
    //Hand 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg1Pos, 0.01f);
    glEnd();

    // Body
    glBegin(GL_QUADS);
        glColor3ub(0,0,255);
        glVertex2f(-0.355f, 0.07f);
        glVertex2f(-0.327f, 0.07f);
	    glVertex2f(-0.327f, -0.03f);
        glVertex2f(-0.355f, -0.03f);
	glEnd();

    //Hand2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, 0.06f);
        glVertex2f(personleg2Pos, 0.01f);
    glEnd();

    // Head
    skl_head2(-0.345f, 0.1f);

    // Legs
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg1Pos, -0.09f);

        glVertex2f(personleg1Pos-0.002f, -0.09f);
        glVertex2f(personleg1Pos+0.015f, -0.09f);

        glVertex2f(-0.341f, -0.03f);
        glVertex2f(personleg2Pos, -0.09f);

        glVertex2f(personleg2Pos-0.002f, -0.09f);
        glVertex2f(personleg2Pos+0.015f, -0.09f);
    glEnd();

    glPopMatrix();
}

void skl_personSitting1(){
    glPushMatrix();
    glTranslatef(sittingPerPos, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);
        glColor3ub(0,0,255);
        glVertex2f(-0.365f, 0.07f);
        glVertex2f(-0.315f, 0.07f);
	    glVertex2f(-0.315f, -0.03f);
        glVertex2f(-0.365f, -0.03f);
	glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(240,240,240);
        glVertex2f(-0.340f, 0.05f);
        glVertex2f(-0.340f, -0.03f);
    glEnd();

    // Hands
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.315f, 0.06f);
        glVertex2f(-0.27f, 0.04f);

        glVertex2f(-0.365f, 0.06f);
        glVertex2f(-0.29f, 0.01f);
    glEnd();

    skl_head(-0.340f, 0.1f);

    //Legs
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(1,1,1);
        glVertex2f(-0.32f, -0.03f);
        glVertex2f(-0.27f, -0.05f);

        glVertex2f(-0.27f, -0.05f);
        glVertex2f(-0.25f, -0.12f);

        glVertex2f(-0.365f, -0.03f);
        glVertex2f(-0.29f, -0.07f);

        glVertex2f(-0.295f, -0.07f);
        glVertex2f(-0.27f, -0.14f);
    glEnd();
    glPopMatrix();
}

void skl_personSitting2(){
    glPushMatrix();
    glTranslatef(sittingPerPos, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);
        glColor3ub(0,255,155);
        glVertex2f(0.365f, 0.07f);
        glVertex2f(0.315f, 0.07f);
	    glVertex2f(0.315f, -0.03f);
        glVertex2f(0.365f, -0.03f);
	glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(240,240,240);
        glVertex2f(0.340f, 0.05f);
        glVertex2f(0.340f, -0.03f);
    glEnd();

    // Hands
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(0.315f, 0.06f);
        glVertex2f(0.27f, 0.04f);

        glVertex2f(0.365f, 0.06f);
        glVertex2f(0.29f, 0.01f);
    glEnd();

    skl_head(0.340f, 0.1f);

    //Legs
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(1,1,1);
        glVertex2f(0.32f, -0.03f);
        glVertex2f(0.27f, -0.05f);

        glVertex2f(0.27f, -0.05f);
        glVertex2f(0.25f, -0.12f);

        glVertex2f(0.365f, -0.03f);
        glVertex2f(0.29f, -0.07f);

        glVertex2f(0.295f, -0.07f);
        glVertex2f(0.27f, -0.14f);
    glEnd();
    glPopMatrix();
}

void skl_personSitting3(){
    glPushMatrix();
    glTranslatef(sittingPerPos, 0.0f, 0.0f);
    // Hair
    glColor3ub(1, 1, 1);
    GLfloat x= 0.03f; GLfloat y = 0.035f; GLfloat radius=0.035f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();

    // Body
    glBegin(GL_QUADS);
        glColor3ub(255,0,255);
        glVertex2f(0.06f, 0.00f);
        glVertex2f(0.0f, 0.00f);
	    glVertex2f(0.0f, -0.1f);
        glVertex2f(0.06f, -0.1f);
	glEnd();

    // Hands
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.02f, 0.035f);
        glVertex2f(0.00f, -0.03f);

        glVertex2f(0.08f, 0.035f);
        glVertex2f(0.06f, -0.03f);
    glEnd();
    glPopMatrix();
}

void skl_personSitting4(){
    glPushMatrix();
    glTranslatef(sittingPerPos, 0.0f, 0.0f);
    // Body
    glBegin(GL_QUADS);
        glColor3ub(120, 120,120);
        glVertex2f(0.00f, 0.16f);
        glVertex2f(-0.06f, 0.16f);
	    glVertex2f(-0.06f, 0.06f);
        glVertex2f(0.00f, 0.06f);
	glEnd();

    skl_head(-0.03f, 0.19f);
    glPopMatrix();
}

void skl_waiter(){
    glPushMatrix();
    glScalef(1.25f, 1.25f, 0.0f);
    glTranslatef(waiterPos, 0.02f, 0.0f);

    // Body
    glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(-0.365f, 0.07f);
        glVertex2f(-0.315f, 0.07f);
	    glVertex2f(-0.315f, -0.03f);
        glVertex2f(-0.365f, -0.03f);
	glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(240,240,240);
        glVertex2f(-0.340f, 0.05f);
        glVertex2f(-0.340f, -0.03f);
    glEnd();

    // Head
    skl_head(-0.340f, 0.1f);

    //Hands
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.315f, 0.07f);
        glVertex2f(-0.29f, 0.02f);

        glVertex2f(-0.365f, 0.07f);
        glVertex2f(-0.39f, 0.12f);
    glEnd();

    // Legs
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.325f, -0.03f);
        glVertex2f(-0.325f, -0.09f);

        glVertex2f(-0.355f, -0.03f);
        glVertex2f(-0.355f, -0.09f);
    glEnd();


    // Foods on hand
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.36f, 0.12f);
        glVertex2f(-0.42f, 0.12f);
    glEnd();

    glScalef(0.65f, 0.65f, 0.0f);
    glTranslatef(-0.4f, 0.15f, 0.0f);
    // Glass1
    // Glass Bottom
    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(250,250,250);
        glVertex2f(-0.215f, 0.05f);
        glVertex2f(-0.185f, 0.05f);
    glEnd();

    // Glass Stand
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(250,250,250);
        glVertex2f(-0.20f, 0.07f);
        glVertex2f(-0.20f, 0.05f);
    glEnd();

    // Glass
    glBegin(GL_QUADS);
        glColor3ub(250,250,250);
        glVertex2f(-0.22f, 0.12f);
        glVertex2f(-0.18f, 0.12f);
	    glVertex2f(-0.19f, 0.07f);
        glVertex2f(-0.21f, 0.07f);
	glEnd();

    // Drink
    glBegin(GL_QUADS);
        glColor3ub(246,181,67);
        glVertex2f(-0.215f, 0.11f);
        glVertex2f(-0.185f, 0.11f);
	    glVertex2f(-0.193f, 0.075f);
        glVertex2f(-0.207f, 0.075f);
	glEnd();
    glPopMatrix();
}

GLfloat parachuteX = -1.2f;
GLfloat parachuteY = 0.9f;

void updateParachute(int value){
    if(parachuteX < 2.0f){
        parachuteX = parachuteX + 0.007f;
        parachuteY = parachuteY - 0.002f;
    }
    if(parachuteX > 2.0f){
        parachuteX = -1.2f;
        parachuteY = 0.9f;
    }

    glutPostRedisplay();
	glutTimerFunc(100, updateParachute, 0);
}

void skl_parachute(){
    glPushMatrix();
    glScalef(0.6f, 0.6f, 0.0f);
    glTranslatef(parachuteX, parachuteY, 0.0f);

    // Body
    glBegin(GL_QUADS);
        glColor3ub(255,153,204);
        glVertex2f(-0.365f, 0.07f);
        glVertex2f(-0.315f, 0.07f);
	    glVertex2f(-0.315f, -0.03f);
        glVertex2f(-0.365f, -0.03f);
	glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3ub(240,240,240);
        glVertex2f(-0.340f, 0.05f);
        glVertex2f(-0.340f, -0.03f);
    glEnd();

    // Head
    skl_head(-0.340f, 0.1f);

    //Hands
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.315f, 0.07f);
        glVertex2f(-0.29f, 0.10f);

        glVertex2f(-0.315f, 0.13f);
        glVertex2f(-0.29f, 0.10f);

        glVertex2f(-0.365f, 0.07f);
        glVertex2f(-0.39f, 0.10f);

        glVertex2f(-0.365f, 0.13f);
        glVertex2f(-0.39f, 0.10f);
    glEnd();

    // Legs
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 25);
        glVertex2f(-0.325f, -0.03f);
        glVertex2f(-0.305f, -0.09f);

        glVertex2f(-0.355f, -0.03f);
        glVertex2f(-0.335f, -0.09f);
    glEnd();


    // Parachute
    glBegin(GL_QUADS);
        glColor3ub(255,153,204);
        glVertex2f(-0.39f, 0.35f);
        glVertex2f(-0.29f, 0.35f);
        glColor3ub(255,0,0);
	    glVertex2f(-0.29f, 0.26f);
        glVertex2f(-0.39f, 0.26f);
	glEnd();

    glBegin(GL_QUADS);
        glColor3ub(255,153,204);
        glVertex2f(-0.47f, 0.26f);
        glVertex2f(-0.39f, 0.35f);
        glColor3ub(128,0,0);
        glVertex2f(-0.39f, 0.26f);
        glVertex2f(-0.47f, 0.20f);
	glEnd();

    glBegin(GL_QUADS);
        glColor3ub(255,153,0);
        glVertex2f(-0.29f, 0.35f);
        glVertex2f(-0.21f, 0.26f);
        glColor3ub(255,0,0);
        glVertex2f(-0.21f, 0.20f);
	    glVertex2f(-0.29f, 0.26f);
	glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.365f, 0.13f);
        glVertex2f(-0.39f, 0.26f);

        glVertex2f(-0.365f, 0.13f);
        glVertex2f(-0.47f, 0.20f);

        glVertex2f(-0.365f, 0.13f);
        glVertex2f(-0.43f, 0.23f);

        glVertex2f(-0.315f, 0.13f);
	    glVertex2f(-0.29f, 0.26f);

        glVertex2f(-0.315f, 0.13f);
        glVertex2f(-0.21f, 0.20f);

        glVertex2f(-0.315f, 0.13f);
        glVertex2f(-0.25f, 0.23f);
    glEnd();
    glPopMatrix();
}

GLfloat skyLoungeSpeed = 0.010f;
GLfloat ropeSpeed = 0.008f;

void updateSkyLounge(int value){

    if(skyLoungeStatus == 'g'){
        skyLoungePos = skyLoungePos + skyLoungeSpeed;
        holderRopePos = holderRopePos + ropeSpeed;
    }
    else if(skyLoungeStatus == 'c'){
        skyLoungePos = skyLoungePos - skyLoungeSpeed;
        holderRopePos = holderRopePos - ropeSpeed;
    }
    else if(standPerStatus == 'h' && skyLoungeStatus == 'i'){
        skyLoungeStatus = 'g';
    }



    if(skyLoungePos > 0.58f && skyLoungeStatus == 'g'){
        skyLoungeStatus = 'u';
    }
    else if(skyLoungePos < -0.87f && skyLoungeStatus == 'c'){
        skyLoungeStatus = 'd';
    }
    else if(skyLoungeStatus == 'u'){
        if(waiterPos > 0.18f && foodsPos1 != 0.0f){
            waiterPos = waiterPos - 0.008f;
        }
        if(waiterPos < 0.18f){
            foodsPos1 = 0.0f;
            foodsPos2 = 0.0f;
        }
        if(foodsPos1 == 0.0f){
            waiterPos = waiterPos + 0.008f;
            if(waiterPos > 0.67f){
                skyLoungeStatus = 'c';
                foodsPos1 = -4.0f;
                foodsPos2 = 4.0f;
            }
        }
    }
    glutPostRedisplay();
	glutTimerFunc(100, updateSkyLounge, 0);
}

void skl_loungeHolder(){
    glBegin(GL_QUADS);
        glColor3ub(12, 12,12);
        glVertex2f(-0.03f, 0.95f);
        glVertex2f(0.02f, 0.95f);
	    glVertex2f(0.03f, 0.90f);
        glVertex2f(-0.02f, 0.90f);
	glEnd();

    glBegin(GL_QUADS);
        glColor3ub(120, 120,120);
        glVertex2f(-0.02f, 0.90f);
        glVertex2f(0.03f, 0.90f);
        glVertex2f(-1.0f, -0.75f);
	    glVertex2f(-1.0f, -0.60f);
	glEnd();

    glBegin(GL_QUADS);
        glColor3ub(80, 80, 80);
        glVertex2f(-0.03f, 0.95f);
        glVertex2f(-0.02f, 0.90f);
        glVertex2f(-1.0f, -0.60f);
	    glVertex2f(-1.0f, -0.50f);
	glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(-0.02f, 0.90f);
        glVertex2f(-1.0f, -0.60f);

        glVertex2f(0.03f, 0.90f);
        glVertex2f(-1.0f, -0.75f);

        glVertex2f(-0.03f, 0.95f);
        glVertex2f(-1.0f, -0.50f);

        glVertex2f(-0.03f, 0.95f);
        glVertex2f(0.02f, 0.95f);

        glVertex2f(0.02f, 0.95f);
	    glVertex2f(0.03f, 0.90f);

        glVertex2f(0.03f, 0.90f);
        glVertex2f(-0.02f, 0.90f);

        glVertex2f(-0.03f, 0.95f);
        glVertex2f(-0.02f, 0.90f);
    glEnd();
}

void skl_holderRope(){
    glPushMatrix();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(10,10,10);
        glVertex2f(0.0f, 0.90f);
        glVertex2f(0.0f, holderRopePos);
    glEnd();
    glPopMatrix();
}

void skl_skyLounge(){
    glPushMatrix();
    glScalef(0.75f, 0.75f, 0.0f);
    glTranslatef(0.0f, skyLoungePos, 0.0f);

    skl_floor();
    skl_roof();
    skl_waiter();

    skl_chair4();
    skl_personSitting4();

    skl_table();

    skl_foods();

    skl_chair1();
    skl_personSitting1();

    skl_chair2();
    skl_personSitting2();

    skl_personSitting3();
    skl_chair3();


    glPopMatrix();
}

void skyLoungeView(){
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    daySky();
    skl_sun();
    cloud1();
    cloud2();
    plane();
    dayRiver();
    skl_ship();
    boat();
    boat2();
    dayBeach();
    skl_parachute();

    skl_loungeHolder();
    skl_holderRope();
    skl_skyLounge();

    skl_personStanding();

    glFlush();
}

void daySkyLounge(){
    glPushMatrix();
    glScalef(0.6f, 0.8f, 0.0f);
    glTranslatef(-1.1f, -0.2f, 0.0f);
        skl_loungeHolder();
        skl_holderRope();
        skl_skyLounge();
    glPopMatrix();
}

//########################### SKY LOUNGE CODES END ############################


//---------calling function-----------

void day() {



	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);

    //fornt();
    daySky();



    //sun
    glColor3ub(245, 176, 65);
	int j;
	GLfloat x=-0.8f; GLfloat y=0.9f; GLfloat radius =.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
			glColor3ub(245, 249, 10);
		}
	glEnd();

    cloud1();
    cloud2();
    dayRiver();
    dayBeach();

    car();
    chair1();
    photographer();
    plane();
    bamboo();
    boat();
    boat2();
    car2();

    horse();



    glPushMatrix();
    glTranslatef(shipXPosition, shipYPosition, 0.0);
    ship();
    glPopMatrix();

    // Move the ship to the right
    shipXPosition += shipSpeed;

    // Check if the ship reaches the right edge
    if (shipXPosition > 1.0f) {
        shipXPosition = -1.0f; // Reset the ship to the left side
    }
    Tower();

    horsepic();



    daySkyLounge();
	glFlush();  // Render now
}


void evening(){
	glClearColor(0.8f, 0.7f, 0.5f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    //----front()--------------;
    eveningSky();
    eveningRiver();
    eveningBeach();




    glColor3ub(238 ,173,14);
	int j;
	GLfloat x=0.0f; GLfloat y=0.5f; GLfloat radius =.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
			glColor3ub(235, 152, 78);
		}
	glEnd();

	bird1();
	bird2();
	ship();
	hotBellon();
	chair1();
    daySkyLounge();
	glFlush();

}

void moon(){
//----------------moon--------
    glColor3ub(255, 255 ,255);
	int j;
	GLfloat x=0.8f; GLfloat y=0.9f; GLfloat radius =.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount+1;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
			glColor3ub(215, 219, 221);
		}
	glEnd();}


void night() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);
ship();

    nightRiver();
    nightBeach();
    star();



moon();



    chair1();
    daySkyLounge();
   glFlush();
}


void rain(){
     glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT);
    //fornt();
    rainySky();
    cloud1();
    cloud2();
    rainyRiver();




    displayRain();
    chair1();
    daySkyLounge();
    glFlush();

}


void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glColor3f(1.0,0.0,0.0);
    renderBitmapString(-0.2f, 0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "COX'S BAZAR SEA BEACH");
    glColor3f(0,0,0);

    renderBitmapString(-0.25f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "1. Sabiha Khair Ohi (ID: 20-41905-1)");
    renderBitmapString(-0.25f, -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "2. Name (ID: 2x-xxxxx-x)");
    renderBitmapString(-0.25f, -0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "3. Name (ID: 2x-xxxxx-x)");
    renderBitmapString(-0.25f, -0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "4. Name (ID: 2x-xxxxx-x)");
    renderBitmapString(-0.25f, -0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "5. Name (ID: 2x-xxxxx-x)");
    renderBitmapString(-0.25f, -0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "6. Name (ID: 2x-xxxxx-x)");
    glFlush(); // Render now
}


void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'c' || key == 'C') {
        // When the 'c' key is pressed, hide the object
        objectVisible = true;
        objectVisible2 = true;

        glutPostRedisplay(); // Mark the window for redrawing
        glutTimerFunc(3000, hideObject, 0);
        glutTimerFunc(500, hideObject2, 0);
    }


	switch (key) {
//----------------multiple view------------
    case 'd':

   glutDisplayFunc(day);

   glutPostRedisplay();

    break;

    case 'n':
   glutDisplayFunc(night);

    glutPostRedisplay();
    break;

    case 'e':
   glutDisplayFunc(evening);

    glutPostRedisplay();
    break;

    case 'r':
   glutDisplayFunc(rain);

    glutPostRedisplay();
    break;

    case 'l':
        glutDisplayFunc(skyLoungeView);
        glutPostRedisplay();
    break;

//-----speed control----

    case 'a'://--------stop----------
    speed = 0.0f;
    speedn=speed;
    break;
    case 's'://--------start-------------
    speed = 0.01f;
    speedn = 0.015f;
    break;
    glutPostRedisplay();
	}

}
void updateship(int value) {
    glutPostRedisplay(); // Notify GLUT that the display function should be called
    glutTimerFunc(16, update, 0); // 60 FPS (1000ms / 60fps = 16ms)
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1000,700);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Sea Beach");
    glutFullScreen();
	glutDisplayFunc(display);
    init();
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, updateBellon, 0);
    glutTimerFunc(100, updateBird, 0);
    glutTimerFunc(100, updateBird2, 0);
    glutTimerFunc(100, updateCloud1, 0);
    glutTimerFunc(100, updateCloud2, 0);
    glutTimerFunc(100, updateBoat, 0);
    glutTimerFunc(100, updateBoat2, 0);
    glutTimerFunc(100, updatecar, 0);
    glutTimerFunc(100, updateRain, 0);
    glutTimerFunc(0, updateship, 0);
    glutTimerFunc(100, updateSkyLounge, 0);
    glutTimerFunc(100, updatePersonStanding, 0);
    glutTimerFunc(100, updateParachute, 0);
	glutMainLoop();
	return 0;

}

