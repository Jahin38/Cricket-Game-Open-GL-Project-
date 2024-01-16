#include<windows.h>
#include<cstdio>
#include <GL/glut.h>
#include<math.h>
#include<iostream>
#include<string>
#include<stdio.h>
#include <time.h>
#include <GL/gl.h>


#define PI 3.1416

GLfloat position =0.0f;
GLfloat position2 =0.0f;
GLfloat speed =0.01f;
int score =0;
GLfloat i = 0.0f;
bool isButtonClicked = false;
int tossResult = -1;
char key;


void initGL()
{
    glClearColor(0.0196f, 0.4f, 0.0314f, 1.1f); // Set background color to green and opaque
}


void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string;*c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void Idle()
{
    if (isButtonClicked) {
        i += 0.07f;
        glutPostRedisplay(); // marks the current window as needing to be redisplayed
        if (tossResult != -1) {
            isButtonClicked = false; // stop the rotation when the toss result is determined
        }
    }
}

void Audience_sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("Crowd.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void Silent_sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("NoSound.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void Welcome_sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("Soft.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}



void Field_sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("Audience.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void GameMenu_sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("GameMenu.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void Coin_sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("Coin_Sound.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void Cover_display()
{


glClearColor(0.0196f, 0.4f, 0.0314f, 1.1f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

glColor3f(1.0,1.0,1.0);
renderBitmapString(-0.4f,  0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh(AIUB)");
renderBitmapString(-0.4f,  0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Course Name: Computer Graphics");
renderBitmapString(-0.4f,  0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Section: A");
renderBitmapString(-0.4f,  0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Project Title: Cricket Tournament Game");
renderBitmapString(-0.4f,  0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Group Name: Code Black");

glEnd();
glColor3f(1.0,1.0,1.0);
renderBitmapString(-0.4f,  0.035f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Group Member Details & Contribution:");
glEnd();
glColor3f(1.0,1.0,1.0);
renderBitmapString(-0.4f,  -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Simit Jahin Megh: 21-44598-1 - 25%");
renderBitmapString(-0.4f,  -0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Khan Atik Faisal: 21-44602-1 - 30%");
renderBitmapString(-0.4f,  -0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Ahmed Farhan Amin: 21-44804-1 - 20%");
renderBitmapString(-0.4f,  -0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Saiful Islam: 20-42585-1 - 15%");
renderBitmapString(-0.4f,  -0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MD. Ashfaq Ahmmed Lejon: 21-44942-2 - 10%");
glColor3f(1.0,0.0,0.0);
//glColor3f(0.95,0.92,0.61);
renderBitmapString(-0.4f,  -0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press g for game menu");

glEnd();
}


void Menu_display() {
glClearColor(0.0196f, 0.4f, 0.0314f, 1.1f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

glColor3f(1.0,1.0,1.0);
renderBitmapString(-0.4f,  0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Cricket Tournament 2023");
renderBitmapString(-0.4f, -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Play");
renderBitmapString(-0.4f, -0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Instruction");
renderBitmapString(-0.4f, -0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Objective");
renderBitmapString(-0.4f, -0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Exit");
glEnd();

renderBitmapString(-0.1f, -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "-Press P");
renderBitmapString(-0.1f, -0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "-Press i");
renderBitmapString(-0.1f, -0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "-Press o");
renderBitmapString(-0.1f, -0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "-Press e");

}

void Instruction_display()
{
glClearColor(0.0196f, 0.4f, 0.0314f, 1.1f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.4f,  0.85f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Please read it carefully!");
glColor3f(1.0,1.0,1.0);
renderBitmapString(-0.4f,  0.65f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "1: Press s button for bowling");
renderBitmapString(-0.4f,  0.55f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "2: Press d for stop bowling");
renderBitmapString(-0.4f,  0.45f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "3: Press p to proceed game & go to the toss menu");
renderBitmapString(-0.4f,  0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "4: Press left button to score 4 run");
renderBitmapString(-0.4f,  0.25f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "5: Press right to hold batting");
renderBitmapString(-0.4f,  0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "6: Press down button to score 6 run");
renderBitmapString(-0.4f,  0.05f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "7: Press up button to score 1 run");
renderBitmapString(-0.4f,  -0.055f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "8: Press g to go to the game menu");
renderBitmapString(-0.4f,  -0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "9: Press f to play TEAM A ");
renderBitmapString(-0.4f,  -0.25f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "9: Press t to play TEAM B ");
renderBitmapString(-0.4f,  -0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "10: Press m to go back on our Game Cover");
renderBitmapString(-0.4f,  -0.45f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "11: Click left key of mouse to toss");
}

void Objective_display()
{
glClearColor(0.0196f, 0.4f, 0.0314f, 1.1f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.6f,  0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "The features that we have been able to add to the game are described below:");
glEnd();
glColor3f(1.0,1.0,1.0);
renderBitmapString(-0.9f,  0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "The main objective of this project is arriving at the designated goal which will be based on some limited scores");
renderBitmapString(-0.4f,  0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "The match begin after the Toss. ");
renderBitmapString(-0.6f,  0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Each level have certain set of scores that must be fulfilled");
renderBitmapString(-0.4f,  0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "2 Teams can be played equally");
renderBitmapString(-0.6f,  0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "One would first declare a fixed score and another one will try to chase");
renderBitmapString(-0.4f,  0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Fielders are added to the game ");
renderBitmapString(-0.3f, -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Bowling are shown");
renderBitmapString(-0.9f, -0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "There are one umpire and a separate window for audiences where some random people can be seen cheering up");
renderBitmapString(-0.5f, -0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "There are a fixed key for bating and bowling term. ");


glEnd();
}


void Coin()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Idle();
    //onClick(GLUT_LEFT_BUTTON);

    glLoadIdentity(); //Reset the current matrix

   glBegin(GL_QUADS);
   glColor3f(0.90f, 0.75f, 0.67f);
   glVertex2f(-1.0f, -1.0f);
   glVertex2f(-1.0f, 1.0f);
   glVertex2f(1.0f, 1.0f);//0.3f,0.35f
   glVertex2f(1.0f, -1.0f);
   glEnd();

    glPushMatrix();
    glRotatef(i, 0.1, 0.0, 0.0); //i=how many degree you want to rotate around an axis
    // Draw the coin
    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159 / 180.0;
        glVertex2f(0.2 * cos(angle), 0.2 * sin(angle));
    }
    glEnd();

    glPopMatrix();

    glLoadIdentity(); //Reset the current matrix

    glPushMatrix();
    glRotatef(i, 0.1, 0.0, 0.0);
    // Add a texture
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_LINES);
    for (int i = 0; i <= 360; i += 5)
    {
        float angle = i * 3.14159 / 180.0;
        glVertex3f(0.2 * cos(angle), 0.2 * sin(angle), 0.01);
        glVertex3f(0.22 * cos(angle), 0.22 * sin(angle), 0.01);
    }
    glEnd();

    glPopMatrix();

    // Draw the result of the toss on the coin
    glColor3f(0.5, 0.0, 1.0);
    glRasterPos2f(0.3, 0.0);
    if (tossResult == 0)
    {
      const char* teamA = "IT'S HEAD.TEAM A WINS !!!"; // text to display
    for (int i = 0; teamA[i] != '\0'; i++) { // iterate over the characters in the text
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, teamA[i]); // display each character using Helvetica 18 font
    }
    }
    else if (tossResult == 1)
    {
        const char* teamB = "IT'S TAIL.TEAM B WINS !!!"; // text to display
    for (int i = 0; teamB[i] != '\0'; i++) { // iterate over the characters in the text
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, teamB[i]);
    }
    }

    glRasterPos2f(-0.4f, 0.45f); // set the starting position for the text
    const char* teamA = "TEAM A = HEAD"; // text to display
    for (int i = 0; teamA[i] != '\0'; i++) { // iterate over the characters in the text
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, teamA[i]); // display each character using Helvetica 18 font
    }

    glRasterPos2f(0.2f, 0.45f); // set the starting position for the text
    const char* teamB = "TEAM B = TAIL"; // text to display
    for (int i = 0; teamB[i] != '\0'; i++) { // iterate over the characters in the text
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, teamB[i]); // display each character using Helvetica 18 font
    }


glColor3f(0.5, 0.0, 1.0); // set color to violet
glRasterPos2f(-0.09, 0.8); // set the position of the text
char* text = "TOSS TIME"; // the text to display
int len = strlen(text);
for (int i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // draw each character
}






glColor3f(0.5, 0.0, 1.0); // set color to violet
glRasterPos2f(-0.35, 0.65); // set the position of the text
char* texts = "TEAM WINNING THE TOSS WILL BAT FIRST"; // the text to display
int lengt = strlen(texts);
for (int i = 0; i < lengt; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texts[i]); // draw each character
}

/*// Set color to white
    glColor3f(1.0, 1.0, 1.0);

    // Draw the button
    glBegin(GL_QUADS);
    glVertex2f(0.7, -0.9);
    glVertex2f(0.9, -0.9);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.7, -0.7);
    glEnd();

    // Write "NEXT" on the button
    glColor3f(0.5, 0.0, 1.0);
    glRasterPos2f(0.75, -0.83);
    char* txtt = "NEXT";
    int leng = strlen(txtt);
    for (int i = 0; i < leng; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txtt[i]);
    }
    */



      // Draw the button
    /*glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.3, -0.7);
    glVertex2f(0.3, -0.7);
    glVertex2f(0.3, -0.9);
    glVertex2f(-0.3, -0.9);
    glEnd();

    // Write "FLIP COIN" on the button
   // glColor3f(0.5, 0.0, 1.0);
//glRasterPos2f(-0.12, -0.83);
//char* txt = "FLIP COIN";
//int length = strlen(txt);
//for (int i = 0; i < length; i++) {
    //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[i]);
//}*/

glColor3f(0.5, 0.0, 1.0);
renderBitmapString(-0.25f,-0.55f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"Press Left click on mouse to toss");
renderBitmapString(-0.25f,-0.7f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"After Toss,Press f to proceed the game for team A");
renderBitmapString(-0.25f,-0.8f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"After Toss,Press t to proceed the game for team B");

}


void fieldstuff()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);//score board layout
    glBegin(GL_QUADS);
    glVertex2f(-0.1f,0.9f);
    glVertex2f(0.2f,0.9f);
    glVertex2f(0.2f,1.0f);
    glVertex2f(-0.1f,1.0f);
    glEnd();

     //score fetching
    char buffer [50];
    sprintf (buffer, "RUNS: %d", score); //for generating output in string.
    glColor3f(1.0f, 0.0f,0.0f);
    renderBitmapString(-0.01f,0.93f,0.0f,(void*)GLUT_BITMAP_TIMES_ROMAN_24,buffer);



   glBegin(GL_QUADS);       // Pitch
   glColor3f(0.90f, 0.75f, 0.67f);
   glVertex2f(0.20f, 0.15f);
   glVertex2f(-0.10f, 0.15f);
   glVertex2f(-0.20f, -0.35f);//0.3f,0.35f
   glVertex2f(0.20f, -0.35f);
   glEnd();



      glLineWidth(3);//Lower Big line
   glBegin(GL_LINES);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.18f, -0.25f);
   glVertex2f(0.20f, -0.25f);
   glEnd();

    glLineWidth(3);
   glBegin(GL_LINES);//Lower Left line
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.125f, -0.25f);
   glVertex2f(-0.137f, -0.35f);
   glEnd();

    glLineWidth(3);// Lower Right line
   glBegin(GL_LINES);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(0.15f, -0.25f);
   glVertex2f(0.15f, -0.35f);
   glEnd();

    glLineWidth(3);// Lower Center line
   glBegin(GL_LINES);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.128f, -0.30f);
   glVertex2f(0.15f, -0.30f);
   glEnd();

    glLineWidth(3);// Upper Big line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.20f, 0.10f);
    glVertex2f(-0.11f, 0.10f);
   glEnd();

     glLineWidth(3);// Upper Right line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.155f, 0.15f);
    glVertex2f(0.155f, 0.10f);
   glEnd();

  glLineWidth(3);// Upper Left line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.05f, 0.15f);
    glVertex2f(-0.06f, 0.10f);
   glEnd();

    glLineWidth(3);// Upper Center Line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.055f, 0.125f);
    glVertex2f(0.155f, 0.125f);
   glEnd();

   glLineWidth(3);//upper center stump
   glBegin(GL_LINES);
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.055f, 0.205f);
   glVertex2f(0.055f, 0.12f);
   glEnd();

   glLineWidth(3);//upper right stump
   glBegin(GL_LINES);
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.068f, 0.205f);
   glVertex2f(0.068f, 0.12f);
   glEnd();

   glLineWidth(3);//upper left stump
   glBegin(GL_LINES);
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.041f, 0.205f);
   glVertex2f(0.041f, 0.12f);
   glEnd();

   glLineWidth(3);//upper stump left bell
   glBegin(GL_LINES);
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.041f, 0.205f);
   glVertex2f(0.052f, 0.205f);
   glEnd();

   glLineWidth(3);//upper stump right bell
   glBegin(GL_LINES);
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.058f, 0.205f);
   glVertex2f(0.068f, 0.205f);
   glEnd();

   glBegin(GL_LINES);//Lower middle stump
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.020f, -0.30f);
   glVertex2f(0.020f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower left stump
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.0025f, -0.30f);
   glVertex2f(0.0025f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower right stump
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.034f, -0.30f);
   glVertex2f(0.034f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower left bell
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.018f, -0.17f);
   glVertex2f(-0.0005f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower right bell
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.022f, -0.17f);
   glVertex2f(0.035f, -0.17f);
   glEnd();


   float radius = 1.1f; // Set the radius of the circle
    int num_segments = 100; // Set the number of line segments to draw the circle

    glBegin(GL_LINE_LOOP); // Begin drawing a line loop (a closed polyline)
    glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * PI * float(i) / float(num_segments); // Calculate the angle between two adjacent vertices
        float x = radius * cos(theta); // Calculate the x-coordinate of the vertex
        float y = radius * sin(theta); // Calculate the y-coordinate of the vertex
        glVertex2f(x, y); // Set the vertex of the circle
    }

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Set background color to gray and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	int i;

    glEnd();

     glBegin(GL_TRIANGLES);//DARAZ
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(0.99f,0.6f);
   glVertex2f(0.99f,0.99f);
   glVertex2f(0.6f,0.99f);


   glEnd();

    glBegin(GL_TRIANGLES);//ROBI
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(-0.99f,0.6f);
   glVertex2f(-0.99f,0.99f);
   glVertex2f(-0.6f,0.99f);

   glEnd();

    glBegin(GL_TRIANGLES);//WALTON
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(-0.99f,-0.6f);
   glVertex2f(-0.99f,-0.99f);
   glVertex2f(-0.6f,-0.99f);


   glEnd();

   glBegin(GL_TRIANGLES);//PEPSI
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(0.99f,-0.6f);
   glVertex2f(0.99f,-0.99f);
   glVertex2f(0.6f,-0.99f);


   glEnd();




    glColor3ub(255, 128, 0);
        renderBitmapString(0.83f,0.85f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"DARAZ");
         glColor3ub(0, 0, 153);
        renderBitmapString(0.83f,-0.92f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"PEPSI");

        glColor3ub(255, 0, 0);
        renderBitmapString(-0.93f,0.85f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"ROBI ");
         glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-0.93f,-0.92f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"WALTON  ");

        glEnd();



        //---batsman
     //Head
    int j;

	GLfloat x=0.06f; GLfloat y=0.25f; GLfloat radi =0.02;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f( x + (radi * cos(j *  twicePi / triangleAmount)),
                        y + (radi * sin(j* twicePi / triangleAmount)) );
		}
	glEnd();

   //body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.072f, 0.23f);
    glVertex2f(0.096f, 0.18f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.095f, 0.18f);
    glVertex2f(0.065f, 0.10f);
    glEnd();

     //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.095f, 0.18f);
    glVertex2f(0.095f, 0.10f);
    glEnd();

       //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.088f, 0.20f);
    glVertex2f(0.065f, 0.15f);
    glEnd();

    //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.085f, 0.21f);
    glVertex2f(0.066f, 0.17f);
    glEnd();


    //fielder--1
     //Head
    int j0;

	GLfloat x0=-0.50f; GLfloat y0=-0.15f; GLfloat radi0 =0.025;
	int triangleAmount0 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi0 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x0, y0); // center of circle
		for(j0 = 0; j0 <= triangleAmount0;j0++) {
			glVertex2f( x0 + (radi0 * cos(j0 *  twicePi0 / triangleAmount0)),
                        y0 + (radi0 * sin(j0* twicePi0 / triangleAmount0)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.50f, -0.175f);
    glVertex2f(-0.50f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, -0.25f);
    glVertex2f(-0.48f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, -0.25f);
    glVertex2f(-0.52f, -0.30f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.46f, -0.25f);
    glVertex2f(-0.50f, -0.22f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.54f, -0.25f);
    glVertex2f(-0.50f, -0.22f);
    glEnd();

    //---Fielder-2
     //Head
    int j1;

	GLfloat x1=0.50f; GLfloat y1=-0.15f; GLfloat radi1 =0.025;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j1 = 0; j1 <= triangleAmount1;j1++) {
			glVertex2f( x1 + (radi1 * cos(j1 *  twicePi1 / triangleAmount1)),
                        y1 + (radi1 * sin(j1* twicePi1 / triangleAmount1)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.50f, -0.175f);
    glVertex2f(0.50f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.48f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.52f, -0.30f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.46f, -0.25f);
    glVertex2f(0.50f, -0.22f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.54f, -0.25f);
    glVertex2f(0.50f, -0.22f);
    glEnd();

      //--Fielder-3
     //Head
    int j2;

	GLfloat x2=0.50f; GLfloat y2=0.30f; GLfloat radi2 =0.02;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(j2 = 0; j2 <= triangleAmount;j2++) {
			glVertex2f( x2 + (radi2 * cos(j2 *  twicePi2 / triangleAmount2)),
                        y2 + (radi2 * sin(j2* twicePi2 / triangleAmount2)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.50f, 0.22f);
    glVertex2f(0.50f, 0.28f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, 0.22f);
    glVertex2f(0.52f, 0.18f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, 0.22f);
    glVertex2f(0.48f, 0.18f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.47f, 0.22f);
    glVertex2f(0.50f, 0.26f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.53f, 0.22f);
    glVertex2f(0.50f, 0.26f);
    glEnd();

    //fielder--4
     //Head
    int j3;

	GLfloat x3=-0.50f; GLfloat y3=0.30f; GLfloat radi3 =0.02;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(j3 = 0; j3 <= triangleAmount3;j3++) {
			glVertex2f( x3 + (radi3 * cos(j3 *  twicePi3 / triangleAmount3)),
                        y3 + (radi3 * sin(j3* twicePi3 / triangleAmount3)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.50f, 0.22f);
    glVertex2f(-0.50f, 0.28f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, 0.22f);
    glVertex2f(-0.52f, 0.18f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, 0.22f);
    glVertex2f(-0.48f, 0.18f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.47f, 0.22f);
    glVertex2f(-0.50f, 0.26f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.53f, 0.22f);
    glVertex2f(-0.50f, 0.26f);
    glEnd();

    //Fielder5
     //Head
    int j4;

	GLfloat x4=-0.40f; GLfloat y4=0.90f; GLfloat radi4 =0.015;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(j4 = 0; j4 <= triangleAmount;j4++) {
			glVertex2f( x4 + (radi4 * cos(j4 *  twicePi4 / triangleAmount4)),
                        y4 + (radi4 * sin(j4* twicePi4 / triangleAmount4)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.40f, 0.88f);
    glVertex2f(-0.40f, 0.84f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.40f, 0.84f);
    glVertex2f(-0.42f, 0.82f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.40f, 0.84f);
    glVertex2f(-0.38f, 0.82f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.40f, 0.87f);
    glVertex2f(-0.42f, 0.855f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.40f, 0.87f);
    glVertex2f(-0.38f, 0.855f);
    glEnd();

    //Fielder-6
     //Head
    int j5;

	GLfloat x5=0.40f; GLfloat y5=0.90f; GLfloat radi5 =0.015;
	int triangleAmount5 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(j5 = 0; j5 <= triangleAmount;j5++) {
			glVertex2f( x5 + (radi5 * cos(j5 *  twicePi5 / triangleAmount5)),
                        y5 + (radi5 * sin(j5* twicePi5 / triangleAmount5)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.40f, 0.88f);
    glVertex2f(0.40f, 0.84f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.40f, 0.84f);
    glVertex2f(0.42f, 0.82f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.40f, 0.84f);
    glVertex2f(0.38f, 0.82f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.40f, 0.87f);
    glVertex2f(0.42f, 0.855f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.40f, 0.87f);
    glVertex2f(0.38f, 0.855f);
    glEnd();

    //Fielder-7
     //Head
    int j6;

	GLfloat x6=-0.05f; GLfloat y6=0.53f; GLfloat radi6 =0.018;
	int triangleAmount6 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(j6 = 0; j6 <= triangleAmount;j6++) {
			glVertex2f( x6 + (radi6 * cos(j6 *  twicePi6 / triangleAmount6)),
                        y6 + (radi6 * sin(j6* twicePi6 / triangleAmount6)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.05f, 0.51f);
    glVertex2f(-0.05f, 0.46f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.05f, 0.46f);
    glVertex2f(-0.07f, 0.43f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.05f, 0.46f);
    glVertex2f(-0.03f, 0.43f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.025f, 0.465f);
    glVertex2f(-0.05f, 0.495f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.05f, 0.495f);
    glVertex2f(-0.08f, 0.465f);
    glEnd();

    //--WicketKeeper
     //Head
    int j7;

	GLfloat x7=0.05f; GLfloat y7=0.45f; GLfloat radi7 =0.018;
	int triangleAmount7 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(j7 = 0; j7 <= triangleAmount;j7++) {
			glVertex2f( x7 + (radi * cos(j7 *  twicePi7 / triangleAmount7)),
                        y7 + (radi * sin(j7* twicePi7 / triangleAmount7)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.05f, 0.43f);
    glVertex2f(0.05f, 0.38f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.07f, 0.35f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.03f, 0.35f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.025f, 0.38f);
    glVertex2f(0.05f, 0.41f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.075f, 0.38f);
    glVertex2f(0.050f, 0.41f);
    glEnd();

     //Umpire
     //Head
    int j8;

	GLfloat x8=0.01f; GLfloat y8=-0.32f; GLfloat radi8 =0.03;
	int triangleAmount8 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(j8 = 0; j8 <= triangleAmount;j8++) {
			glVertex2f( x8 + (radi8 * cos(j8 *  twicePi8 / triangleAmount8)),
                        y8 + (radi8 * sin(j8* twicePi8 / triangleAmount8)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.01f, -0.35f);
    glVertex2f(0.01f, -0.44f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.01f, -0.44f);
    glVertex2f(0.05f, -0.50f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.01f, -0.44f);
    glVertex2f(-0.03f, -0.50f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.052f, -0.44f);
    glVertex2f(0.012f, -0.38f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.038f, -0.44f);
    glVertex2f(0.01f, -0.38f);
    glEnd();

    //Umpire-2
     //Head
    int j9;

	GLfloat x9=0.60f; GLfloat y9=0.16f; GLfloat radi9 =0.02;
	int triangleAmount9 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(j9 = 0; j9 <= triangleAmount9;j9++) {
			glVertex2f( x9 + (radi9 * cos(j9 *  twicePi9 / triangleAmount9)),
                        y9 + (radi9 * sin(j9* twicePi9 / triangleAmount9)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.14f);
    glVertex2f(0.60f, 0.07f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.07f);
    glVertex2f(0.57f, 0.04f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.07f);
    glVertex2f(0.63f, 0.04f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.11f);
    glVertex2f(0.63f, 0.08f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.11f);
    glVertex2f(0.57f, 0.08f);
    glEnd();

}

void fieldstuffB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);//score board layout
    glBegin(GL_QUADS);
    glVertex2f(-0.1f,0.9f);
    glVertex2f(0.2f,0.9f);
    glVertex2f(0.2f,1.0f);
    glVertex2f(-0.1f,1.0f);
    glEnd();

     //score fetching
    char buffer [50];
    sprintf (buffer, "RUNS: %d", score); //for generating output in string.
    glColor3f(1.0f, 0.0f,0.0f);
    renderBitmapString(-0.01f,0.93f,0.0f,(void*)GLUT_BITMAP_TIMES_ROMAN_24,buffer);



   glBegin(GL_QUADS);       // Pitch
   glColor3f(0.90f, 0.75f, 0.67f);
   glVertex2f(0.20f, 0.15f);
   glVertex2f(-0.10f, 0.15f);
   glVertex2f(-0.20f, -0.35f);//0.3f,0.35f
   glVertex2f(0.20f, -0.35f);
   glEnd();



      glLineWidth(3);//Lower Big line
   glBegin(GL_LINES);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.18f, -0.25f);
   glVertex2f(0.20f, -0.25f);
   glEnd();

    glLineWidth(3);
   glBegin(GL_LINES);//Lower Left line
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.125f, -0.25f);
   glVertex2f(-0.137f, -0.35f);
   glEnd();

    glLineWidth(3);// Lower Right line
   glBegin(GL_LINES);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(0.15f, -0.25f);
   glVertex2f(0.15f, -0.35f);
   glEnd();

    glLineWidth(3);// Lower Center line
   glBegin(GL_LINES);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.128f, -0.30f);
   glVertex2f(0.15f, -0.30f);
   glEnd();

    glLineWidth(3);// Upper Big line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.20f, 0.10f);
    glVertex2f(-0.11f, 0.10f);
   glEnd();

     glLineWidth(3);// Upper Right line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.155f, 0.15f);
    glVertex2f(0.155f, 0.10f);
   glEnd();

  glLineWidth(3);// Upper Left line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.05f, 0.15f);
    glVertex2f(-0.06f, 0.10f);
   glEnd();

    glLineWidth(3);// Upper Center Line
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.055f, 0.125f);
    glVertex2f(0.155f, 0.125f);
   glEnd();

   glLineWidth(3);//upper center stump
   glBegin(GL_LINES);
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.055f, 0.205f);
   glVertex2f(0.055f, 0.12f);
   glEnd();

   glLineWidth(3);//upper right stump
   glBegin(GL_LINES);
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.068f, 0.205f);
   glVertex2f(0.068f, 0.12f);
   glEnd();

   glLineWidth(3);//upper left stump
   glBegin(GL_LINES);
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.041f, 0.205f);
   glVertex2f(0.041f, 0.12f);
   glEnd();

   glLineWidth(3);//upper stump left bell
   glBegin(GL_LINES);
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.041f, 0.205f);
   glVertex2f(0.052f, 0.205f);
   glEnd();

   glLineWidth(3);//upper stump right bell
   glBegin(GL_LINES);
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.058f, 0.205f);
   glVertex2f(0.068f, 0.205f);
   glEnd();

   glBegin(GL_LINES);//Lower middle stump
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.020f, -0.30f);
   glVertex2f(0.020f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower left stump
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.0025f, -0.30f);
   glVertex2f(0.0025f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower right stump
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(0.034f, -0.30f);
   glVertex2f(0.034f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower left bell
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.018f, -0.17f);
   glVertex2f(-0.0005f, -0.17f);
   glEnd();

   glBegin(GL_LINES);//Lower right bell
   glColor3f(1.0f,0.0f,0.0f);
   glVertex2f(0.022f, -0.17f);
   glVertex2f(0.035f, -0.17f);
   glEnd();


   float radius = 1.1f; // Set the radius of the circle
    int num_segments = 100; // Set the number of line segments to draw the circle

    glBegin(GL_LINE_LOOP); // Begin drawing a line loop (a closed polyline)
    glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * PI * float(i) / float(num_segments); // Calculate the angle between two adjacent vertices
        float x = radius * cos(theta); // Calculate the x-coordinate of the vertex
        float y = radius * sin(theta); // Calculate the y-coordinate of the vertex
        glVertex2f(x, y); // Set the vertex of the circle
    }

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Set background color to gray and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	int i;

    glEnd();

     glBegin(GL_TRIANGLES);//DARAZ
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(0.99f,0.6f);
   glVertex2f(0.99f,0.99f);
   glVertex2f(0.6f,0.99f);


   glEnd();

    glBegin(GL_TRIANGLES);//ROBI
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(-0.99f,0.6f);
   glVertex2f(-0.99f,0.99f);
   glVertex2f(-0.6f,0.99f);

   glEnd();

    glBegin(GL_TRIANGLES);//WALTON
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(-0.99f,-0.6f);
   glVertex2f(-0.99f,-0.99f);
   glVertex2f(-0.6f,-0.99f);


   glEnd();

   glBegin(GL_TRIANGLES);//PEPSI
   glColor3f(0.350f, 0.250f, 0.330f);
   glVertex2f(0.99f,-0.6f);
   glVertex2f(0.99f,-0.99f);
   glVertex2f(0.6f,-0.99f);


   glEnd();




    glColor3ub(255, 128, 0);
        renderBitmapString(0.83f,0.85f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"DARAZ");
         glColor3ub(0, 0, 153);
        renderBitmapString(0.83f,-0.92f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"PEPSI");

        glColor3ub(255, 0, 0);
        renderBitmapString(-0.93f,0.85f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"ROBI ");
         glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-0.93f,-0.92f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"WALTON  ");

        glEnd();



        //---batsman
     //Head
    int j;

	GLfloat x=0.06f; GLfloat y=0.25f; GLfloat radi =0.02;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f( x + (radi * cos(j *  twicePi / triangleAmount)),
                        y + (radi * sin(j* twicePi / triangleAmount)) );
		}
	glEnd();

   //body

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.072f, 0.23f);
    glVertex2f(0.096f, 0.18f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.095f, 0.18f);
    glVertex2f(0.065f, 0.10f);
    glEnd();

     //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.095f, 0.18f);
    glVertex2f(0.095f, 0.10f);
    glEnd();

       //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.088f, 0.20f);
    glVertex2f(0.065f, 0.15f);
    glEnd();

    //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.085f, 0.21f);
    glVertex2f(0.066f, 0.17f);
    glEnd();


    //fielder--1
     //Head
    int j0;

	GLfloat x0=-0.50f; GLfloat y0=-0.15f; GLfloat radi0 =0.025;
	int triangleAmount0 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi0 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x0, y0); // center of circle
		for(j0 = 0; j0 <= triangleAmount0;j0++) {
			glVertex2f( x0 + (radi0 * cos(j0 *  twicePi0 / triangleAmount0)),
                        y0 + (radi0 * sin(j0* twicePi0 / triangleAmount0)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.50f, -0.175f);
    glVertex2f(-0.50f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, -0.25f);
    glVertex2f(-0.48f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, -0.25f);
    glVertex2f(-0.52f, -0.30f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.46f, -0.25f);
    glVertex2f(-0.50f, -0.22f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.54f, -0.25f);
    glVertex2f(-0.50f, -0.22f);
    glEnd();

    //---Fielder-2
     //Head
    int j1;

	GLfloat x1=0.50f; GLfloat y1=-0.15f; GLfloat radi1 =0.025;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j1 = 0; j1 <= triangleAmount1;j1++) {
			glVertex2f( x1 + (radi1 * cos(j1 *  twicePi1 / triangleAmount1)),
                        y1 + (radi1 * sin(j1* twicePi1 / triangleAmount1)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.50f, -0.175f);
    glVertex2f(0.50f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.48f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.52f, -0.30f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.46f, -0.25f);
    glVertex2f(0.50f, -0.22f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.54f, -0.25f);
    glVertex2f(0.50f, -0.22f);
    glEnd();

      //--Fielder-3
     //Head
    int j2;

	GLfloat x2=0.50f; GLfloat y2=0.30f; GLfloat radi2 =0.02;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(j2 = 0; j2 <= triangleAmount;j2++) {
			glVertex2f( x2 + (radi2 * cos(j2 *  twicePi2 / triangleAmount2)),
                        y2 + (radi2 * sin(j2* twicePi2 / triangleAmount2)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.50f, 0.22f);
    glVertex2f(0.50f, 0.28f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, 0.22f);
    glVertex2f(0.52f, 0.18f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.50f, 0.22f);
    glVertex2f(0.48f, 0.18f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.47f, 0.22f);
    glVertex2f(0.50f, 0.26f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.53f, 0.22f);
    glVertex2f(0.50f, 0.26f);
    glEnd();

    //fielder--4
     //Head
    int j3;

	GLfloat x3=-0.50f; GLfloat y3=0.30f; GLfloat radi3 =0.02;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(j3 = 0; j3 <= triangleAmount3;j3++) {
			glVertex2f( x3 + (radi3 * cos(j3 *  twicePi3 / triangleAmount3)),
                        y3 + (radi3 * sin(j3* twicePi3 / triangleAmount3)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.50f, 0.22f);
    glVertex2f(-0.50f, 0.28f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, 0.22f);
    glVertex2f(-0.52f, 0.18f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.50f, 0.22f);
    glVertex2f(-0.48f, 0.18f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.47f, 0.22f);
    glVertex2f(-0.50f, 0.26f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.53f, 0.22f);
    glVertex2f(-0.50f, 0.26f);
    glEnd();

    //Fielder5
     //Head
    int j4;

	GLfloat x4=-0.40f; GLfloat y4=0.90f; GLfloat radi4 =0.015;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(j4 = 0; j4 <= triangleAmount;j4++) {
			glVertex2f( x4 + (radi4 * cos(j4 *  twicePi4 / triangleAmount4)),
                        y4 + (radi4 * sin(j4* twicePi4 / triangleAmount4)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.40f, 0.88f);
    glVertex2f(-0.40f, 0.84f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.40f, 0.84f);
    glVertex2f(-0.42f, 0.82f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.40f, 0.84f);
    glVertex2f(-0.38f, 0.82f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.40f, 0.87f);
    glVertex2f(-0.42f, 0.855f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.40f, 0.87f);
    glVertex2f(-0.38f, 0.855f);
    glEnd();

    //Fielder-6
     //Head
    int j5;

	GLfloat x5=0.40f; GLfloat y5=0.90f; GLfloat radi5 =0.015;
	int triangleAmount5 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(j5 = 0; j5 <= triangleAmount;j5++) {
			glVertex2f( x5 + (radi5 * cos(j5 *  twicePi5 / triangleAmount5)),
                        y5 + (radi5 * sin(j5* twicePi5 / triangleAmount5)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.40f, 0.88f);
    glVertex2f(0.40f, 0.84f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.40f, 0.84f);
    glVertex2f(0.42f, 0.82f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.40f, 0.84f);
    glVertex2f(0.38f, 0.82f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.40f, 0.87f);
    glVertex2f(0.42f, 0.855f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.40f, 0.87f);
    glVertex2f(0.38f, 0.855f);
    glEnd();

    //Fielder-7
     //Head
    int j6;

	GLfloat x6=-0.05f; GLfloat y6=0.53f; GLfloat radi6 =0.018;
	int triangleAmount6 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(j6 = 0; j6 <= triangleAmount;j6++) {
			glVertex2f( x6 + (radi6 * cos(j6 *  twicePi6 / triangleAmount6)),
                        y6 + (radi6 * sin(j6* twicePi6 / triangleAmount6)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.05f, 0.51f);
    glVertex2f(-0.05f, 0.46f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.05f, 0.46f);
    glVertex2f(-0.07f, 0.43f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.05f, 0.46f);
    glVertex2f(-0.03f, 0.43f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.025f, 0.465f);
    glVertex2f(-0.05f, 0.495f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-0.05f, 0.495f);
    glVertex2f(-0.08f, 0.465f);
    glEnd();

    //--WicketKeeper
     //Head
    int j7;

	GLfloat x7=0.05f; GLfloat y7=0.45f; GLfloat radi7 =0.018;
	int triangleAmount7 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(j7 = 0; j7 <= triangleAmount;j7++) {
			glVertex2f( x7 + (radi * cos(j7 *  twicePi7 / triangleAmount7)),
                        y7 + (radi * sin(j7* twicePi7 / triangleAmount7)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.05f, 0.43f);
    glVertex2f(0.05f, 0.38f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.07f, 0.35f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.03f, 0.35f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.025f, 0.38f);
    glVertex2f(0.05f, 0.41f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.075f, 0.38f);
    glVertex2f(0.050f, 0.41f);
    glEnd();

     //Umpire
     //Head
    int j8;

	GLfloat x8=0.01f; GLfloat y8=-0.32f; GLfloat radi8 =0.03;
	int triangleAmount8 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(j8 = 0; j8 <= triangleAmount;j8++) {
			glVertex2f( x8 + (radi8 * cos(j8 *  twicePi8 / triangleAmount8)),
                        y8 + (radi8 * sin(j8* twicePi8 / triangleAmount8)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.01f, -0.35f);
    glVertex2f(0.01f, -0.44f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.01f, -0.44f);
    glVertex2f(0.05f, -0.50f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.01f, -0.44f);
    glVertex2f(-0.03f, -0.50f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.052f, -0.44f);
    glVertex2f(0.012f, -0.38f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.038f, -0.44f);
    glVertex2f(0.01f, -0.38f);
    glEnd();

    //Umpire-2
     //Head
    int j9;

	GLfloat x9=0.60f; GLfloat y9=0.16f; GLfloat radi9 =0.02;
	int triangleAmount9 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glColor3f(0.631f, 0.40f, 0.37f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(j9 = 0; j9 <= triangleAmount9;j9++) {
			glVertex2f( x9 + (radi9 * cos(j9 *  twicePi9 / triangleAmount9)),
                        y9 + (radi9 * sin(j9* twicePi9 / triangleAmount9)) );
		}
	glEnd();

	//body

    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.14f);
    glVertex2f(0.60f, 0.07f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.07f);
    glVertex2f(0.57f, 0.04f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.07f);
    glVertex2f(0.63f, 0.04f);
    glEnd();

         //Hand 1
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.11f);
    glVertex2f(0.63f, 0.08f);
    glEnd();

           //Hand 2
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.60f, 0.11f);
    glVertex2f(0.57f, 0.08f);
    glEnd();

}



GLfloat batposition =-0.003;

GLfloat batspeed =0.00;

void updatebat(int value) {

if(batposition >0.01)
    {
        batposition = -0.001;


    }
    batposition +=batspeed;




	glutPostRedisplay();
	glutTimerFunc(100, updatebat, 0);
}


void bat()
{

    //BAT handle
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,1.0f);
    glVertex2f(0.068f, 0.17f);
    glVertex2f(0.070f, 0.17f);
    glVertex2f(0.058f, 0.14f);
    glVertex2f(0.055f, 0.14f);

    glEnd();


    //BAT
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.050f, 0.14f);
    glVertex2f(0.061f, 0.14f);
    glVertex2f(0.048f, 0.11f);
    glVertex2f(0.040f, 0.11f);

    glEnd();

}

GLfloat ballposition =-0.10;

GLfloat ballspeed =0.00;
GLfloat ballspeed1=0.00;

void updateball(int value) {
if(ballposition >0.90)
    {
        ballposition = -0.10f;
        //ballposition1=-0.50f;

    }
    ballposition +=ballspeed;






	glutPostRedisplay();
	glutTimerFunc(100, updateball, 0);

}


GLfloat ballposition2 =-0.10;
GLfloat ballposition3 =-0.10;
GLfloat ballspeed2 =0.08;
GLfloat ballspeed3=0.00;

void updateball2(int value) {
if(ballposition2 > 0.90)
    {
        ballposition2 = -0.10f;
        ballposition3=-0.10;

    ballposition2 +=ballspeed2;
    }
    ballposition2 =0.0;
    //ballposition3 +=ballspeed3;


	glutPostRedisplay();
	glutTimerFunc(100, updateball2, 0);
}



void ball()
{

      //Head
    int j;

	GLfloat x=-0.15f; GLfloat y=-0.85f; GLfloat radi =0.018;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f( x + (radi * cos(j *  twicePi / triangleAmount)),
                        y + (radi * sin(j* twicePi / triangleAmount)) );
		}

	glEnd();


}

GLfloat cloudposition =-1.0;
GLfloat cloudposition1 =1.5;
GLfloat cloudspeed =0.01;
GLfloat cloudspeed1=0.01;

void updatecloud(int value) {
if(cloudposition >2.0)
    {
       cloudposition = -1.0f;
        cloudposition1=1.5f;

    }
   cloudposition +=cloudspeed;
    cloudposition1 +=cloudspeed1;


	glutPostRedisplay();
	glutTimerFunc(100, updatecloud, 0);
}


void gallerystuff()
{
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glClear(GL_COLOR_BUFFER_BIT);  //rooftop

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, 1.f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);

    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.175f, 0.0f, 0.280f);

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);

    glEnd();


    int i;
    GLfloat x = 0.6f;
    GLfloat y = 0.75f;
    GLfloat radius = 0.12f;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
               );
    }
    glEnd();

    x = -0.7f;
    y = 0.6f;
    radius = 0.15f;
    triangleAmount = 40;
    twicePi = 2.0f * PI;

    glPushMatrix();
    glTranslatef( cloudposition,0.15, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
               );
    }
    glEnd();

    x = -0.6f;
    y = 0.75f;
    radius = 0.15f;
    triangleAmount = 40;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
               );
    }
    glEnd();

    x = -0.5f;
    y = 0.6f;
    radius = 0.15f;
    triangleAmount = 40;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
               );
    }
    glEnd();


    x = -0.3f;
    y = 0.6f;
    radius = 0.15f;
    triangleAmount = 40;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
               );
    }
    glEnd();
glPopMatrix();


    glBegin(GL_QUADS); //gallery portion
    glColor3f(0.70f, 0.70f, 0.70f);

    glVertex2f(-1.0f, -0.50f);
    glVertex2f(-1.0f, 0.50f);
    glVertex2f(1.0f, 0.50f);
    glVertex2f(1.0f, -0.50f);


    glEnd();

    glLineWidth(16); //vertical Gallery 1st stair line
    glBegin(GL_LINES);
    glColor3f(0.500f, 0.500f, 0.500f);

    glVertex2f(-1.0f, 0.48f);
    glVertex2f(1.0f, 0.48f);

    glEnd();

    glLineWidth(7.5); //vertical Gallery 2nd stair line
    glBegin(GL_LINES);
    glColor3f(0.500f, 0.500f, 0.500f);

    glVertex2f(-1.0f, 0.25f);
    glVertex2f(1.0f, 0.25f);

    glEnd();

    glLineWidth(7.5); //vertical Gallery 3rd stair line
    glBegin(GL_LINES);
    glColor3f(0.500f, 0.500f, 0.500f);

    glVertex2f(-1.0f, 0.009f);
    glVertex2f(1.0f, 0.009f);

    glEnd();

    glLineWidth(10); //vertical Gallery 4th stair line
    glBegin(GL_LINES);
    glColor3f(0.500f, 0.500f, 0.500f);

    glVertex2f(-1.0f, -0.33f);
    glVertex2f(1.0f, -0.33f);


    glEnd();

    glLineWidth(5); //vertical first line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, 0.40f);
    glVertex2f(0.20f, 0.40f);


    glEnd();

    glLineWidth(5); //vertical 2nd line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, 0.30f);
    glVertex2f(0.20f, 0.30f);


    glEnd();

    glLineWidth(5); //vertical 3rd line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, 0.20f);
    glVertex2f(0.20f, 0.20f);


    glEnd();

    glLineWidth(5); //vertical 4th line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, 0.10f);
    glVertex2f(0.20f, 0.10f);


    glEnd();

    glLineWidth(5); //vertical 5th line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, 0.00f);
    glVertex2f(0.20f, 0.00f);


    glEnd();

    glLineWidth(5); //vertical 6th line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, -0.10f);
    glVertex2f(0.20f, -0.10f);


    glEnd();

    glLineWidth(5); //vertical 7th line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, -0.20f);
    glVertex2f(0.20f, -0.20f);


    glEnd();

    glLineWidth(5); //vertical 8th line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, -0.30f);
    glVertex2f(0.20f, -0.30f);


    glEnd();

    glLineWidth(5); //vertical 9th line
    glBegin(GL_LINES);
    glColor3f(0.700f, 0.250f, 0.0f);

    glVertex2f(-0.20f, -0.40f);
    glVertex2f(0.20f, -0.40f);


    glEnd();

    glLineWidth(5); //horizontal 1st line
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.50f);
    glVertex2f(0.20f, 0.50f);

    glEnd();

    glLineWidth(5); //horizontal 2nd line
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.50f);
    glVertex2f(-0.20f, 0.50f);

    glEnd();

    glLineWidth(5); //horizontal stair left line
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.10f, -0.49f);
    glVertex2f(-0.10f, 0.49f);

    glEnd();


    glLineWidth(5); //horizontal stair right 1st line
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.10f, 0.49f);
    glVertex2f(0.10f, -0.49f);

    glEnd();


    glBegin(GL_QUADS); //light Brown portion
    glColor3f(0.350f, 0.250f, 0.330f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -1.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f(-0.5f,-1.0f);
    glEnd();

      glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.0f,-0.5f);
    glVertex2f(0.0f,-1.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.5f,-0.5f);
    glVertex2f(0.5f,-1.0f);
    glEnd();

    glColor3ub(255, 128, 0);
    renderBitmapString(-0.3f,-0.8f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"DARAZ");
    glColor3ub(0, 0, 153);
    renderBitmapString(0.73f,-0.8f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"PEPSI");

    glColor3f(1.0f, 0.0f, 0.0f);
    renderBitmapString(0.20f,-0.8f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"ROBI ");
    glColor3f(1.0, 1.0f, 1.0f);
    renderBitmapString(-0.83f,-0.8f,0.0f,(void *)GLUT_BITMAP_TIMES_ROMAN_24,"WALTON  ");

    glEnd();



}

GLfloat audiposition =-0.03;
GLfloat audiposition1 =-0.03;
GLfloat audispeed =0.01;
GLfloat audispeed1=0.01;

void updateaudi(int value) {
if(audiposition >0.01)
    {
       audiposition = -0.03f;
        audiposition1=-0.03f;

    }
    audiposition +=audispeed;
    audiposition1 +=audispeed1;


	glutPostRedisplay();
	glutTimerFunc(100, updateaudi, 0);
}



void audience_Info()
{
     //Head----------------------1
    int j;

    GLfloat x=-0.50f; GLfloat y=-0.16f; GLfloat radi =0.03;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.150f, 0.250f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(j = 0; j <= triangleAmount;j++) {
            glVertex2f( x + (radi * cos(j *  twicePi / triangleAmount)),
                        y + (radi * sin(j* twicePi / triangleAmount)) );
        }
    glEnd();

    //body-

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.50f, -0.18f);
    glVertex2f(-0.50f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.50f, -0.25f);
    glVertex2f(-0.48f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.50f, -0.25f);
    glVertex2f(-0.52f, -0.30f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.0001f,audiposition, 0.0f);
         //Hand 1
    glBegin(GL_LINES);
    glColor3f(-0.01f,0.250f,0.250f);
    glVertex2f(-0.46f, -0.25f);
    glVertex2f(-0.50f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( -0.0001f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.54f, -0.25f);
    glVertex2f(-0.50f, -0.22f);
    glEnd();
    glPopMatrix();

//-----2
     //Head
    int j1;

    GLfloat x1=0.50f; GLfloat y1=-0.16f; GLfloat radi1 =0.03;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.150f, 0.250f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x1, y1); // center of circle
        for(j1 = 0; j1 <= triangleAmount;j1++) {
            glVertex2f( x1 + (radi1 * cos(j1 *  twicePi1 / triangleAmount1)),
                        y1 + (radi1 * sin(j1* twicePi1 / triangleAmount1)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.50f, -0.18f);
    glVertex2f(0.50f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.48f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.52f, -0.30f);
    glEnd();


    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);   //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.46f, -0.25f);
    glVertex2f(0.50f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.0001f,audiposition, 0.0f);   //Hand 1      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.54f, -0.25f);
    glVertex2f(0.50f, -0.22f);
    glEnd();
    glPopMatrix();

    //----3
    int j2;

    GLfloat x2=0.65f; GLfloat y2=-0.16f; GLfloat radi2 =0.03;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.265f, 0.250f, 0.265f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x2, y2); // center of circle
        for(j2 = 0; j2 <= triangleAmount2;j2++) {
            glVertex2f( x2 + (radi2 * cos(j2 *  twicePi2 / triangleAmount2)),
                        y2 + (radi2 * sin(j2* twicePi2 / triangleAmount2)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.65f, -0.18f);
    glVertex2f(0.65f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.65f, -0.25f);
    glVertex2f(0.63f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.65f, -0.25f);
    glVertex2f(0.67f, -0.30f);
    glEnd();


     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.61f, -0.25f);
    glVertex2f(0.65f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.69f, -0.25f);
    glVertex2f(0.65f, -0.22f);
    glEnd();
    glPopMatrix();

    //--4
     int j3;

    GLfloat x3=-0.75f; GLfloat y3=-0.16f; GLfloat radi3 =0.03;
    int triangleAmount3 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi3 = 2.0f * PI;

    glColor3f(-0.175f, 0.250f, -0.175f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x3, y3); // center of circle
        for(j3 = 0; j3 <= triangleAmount3;j3++) {
            glVertex2f( x3 + (radi3 * cos(j3 *  twicePi3 / triangleAmount3)),
                        y3 + (radi3 * sin(j3* twicePi3 / triangleAmount3)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.550f,0.0f,0.550f);
    glVertex2f(-0.75f, -0.18f);
    glVertex2f(-0.75f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.75f, -0.25f);
    glVertex2f(-0.73f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.75f, -0.25f);
    glVertex2f(-0.77f, -0.30f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.71f, -0.25f);
    glVertex2f(-0.75f, -0.22f);
    glEnd();
    glPopMatrix();
     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.79f, -0.25f);
    glVertex2f(-0.75f, -0.22f);
    glEnd();
    glPopMatrix();

    //-----5

    int j4;

    GLfloat x4=-0.65f; GLfloat y4=-0.16f; GLfloat radi4 =0.03;
    int triangleAmount4 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi4 = 2.0f * PI;

    glColor3f(-0.165f, 0.250f, -0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x4, y4); // center of circle
        for(j4 = 0; j4 <= triangleAmount4;j4++) {
            glVertex2f( x4 + (radi * cos(j4 *  twicePi4 / triangleAmount4)),
                        y4 + (radi * sin(j4* twicePi4 / triangleAmount4)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.65f, -0.18f);
    glVertex2f(-0.65f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.65f, -0.25f);
    glVertex2f(-0.63f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.65f, -0.25f);
    glVertex2f(-0.67f, -0.30f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.61f, -0.25f);
    glVertex2f(-0.65f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.69f, -0.25f);
    glVertex2f(-0.65f, -0.22f);
    glEnd();
    glPopMatrix();

    //--6

    int j5;

    GLfloat x5=0.75f; GLfloat y5=-0.16f; GLfloat radi5 =0.03;
    int triangleAmount5 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi5 = 2.0f * PI;

    glColor3f(-0.180f, 0.250f, 0.180f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x5, y5); // center of circle
        for(j5 = 0; j5 <= triangleAmount5;j5++) {
            glVertex2f( x5 + (radi5 * cos(j5 *  twicePi5 / triangleAmount5)),
                        y5 + (radi5 * sin(j5* twicePi5 / triangleAmount5)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.80f,0.0f,0.80f);
    glVertex2f(0.75f, -0.18f);
    glVertex2f(0.75f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.75f, -0.25f);
    glVertex2f(0.73f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.75f, -0.25f);
    glVertex2f(0.77f, -0.30f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.71f, -0.25f);
    glVertex2f(0.75f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.79f, -0.25f);
    glVertex2f(0.75f, -0.22f);
    glEnd();
    glPopMatrix();

    //---7
      int j6;

    GLfloat x6=-0.37f; GLfloat y6=-0.16f; GLfloat radi6 =0.03;
    int triangleAmount6 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi6 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x6, y6); // center of circle
        for(j6 = 0; j6 <= triangleAmount6;j6++) {
            glVertex2f( x6 + (radi6 * cos(j6 *  twicePi6 / triangleAmount6)),
                        y6 + (radi6 * sin(j6* twicePi6 / triangleAmount6)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.37f, -0.18f);
    glVertex2f(-0.37f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.37f, -0.25f);
    glVertex2f(-0.35f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.37f, -0.25f);
    glVertex2f(-0.39f, -0.30f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.34f, -0.25f);
    glVertex2f(-0.37f, -0.22f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.40f, -0.25f);
    glVertex2f(-0.37f, -0.22f);
    glEnd();
    glPopMatrix();

    //---8

    int j7;

    GLfloat x7=0.37f; GLfloat y7=-0.16f; GLfloat radi7 =0.03;
    int triangleAmount7 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi7 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x7, y7); // center of circle
        for(j7 = 0; j7 <= triangleAmount7;j7++) {
            glVertex2f( x7 + (radi7 * cos(j7 *  twicePi7 / triangleAmount7)),
                        y7 + (radi7 * sin(j7* twicePi7 / triangleAmount7)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.37f, -0.18f);
    glVertex2f(0.37f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.37f, -0.25f);
    glVertex2f(0.35f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.37f, -0.25f);
    glVertex2f(0.39f, -0.30f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.34f, -0.25f);
    glVertex2f(0.37f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.40f, -0.25f);
    glVertex2f(0.37f, -0.22f);
    glEnd();
    glPopMatrix();

    //---9

    int j8;

    GLfloat x8=0.86f; GLfloat y8=-0.16f; GLfloat radi8 =0.03;
    int triangleAmount8 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi8 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x8, y8); // center of circle
        for(j8 = 0; j8 <= triangleAmount8;j8++) {
            glVertex2f( x8 + (radi8 * cos(j8 *  twicePi8 / triangleAmount8)),
                        y8 + (radi8 * sin(j8* twicePi8 / triangleAmount8)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.86f, -0.18f);
    glVertex2f(0.86f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.86f, -0.25f);
    glVertex2f(0.86f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.86f, -0.25f);
    glVertex2f(0.86f, -0.30f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.83f, -0.25f);
    glVertex2f(0.86f, -0.22f);
    glEnd();
     glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.89f, -0.25f);
    glVertex2f(0.86f, -0.22f);
    glEnd();
     glPopMatrix();

     //--10
     int j9;

    GLfloat x9=-0.86f; GLfloat y9=-0.16f; GLfloat radi9 =0.03;
    int triangleAmount9 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi9 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x9, y9); // center of circle
        for(j9 = 0; j9 <= triangleAmount9;j9++) {
            glVertex2f( x9 + (radi9 * cos(j9 *  twicePi9 / triangleAmount9)),
                        y9 + (radi9 * sin(j9* twicePi9 / triangleAmount9)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.86f, -0.18f);
    glVertex2f(-0.86f, -0.25f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.86f, -0.25f);
    glVertex2f(-0.86f, -0.30f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.86f, -0.25f);
    glVertex2f(-0.86f, -0.30f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.83f, -0.25f);
    glVertex2f(-0.86f, -0.22f);
    glEnd();
    glPopMatrix();

      glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);        //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.89f, -0.25f);
    glVertex2f(-0.86f, -0.22f);
    glEnd();
    glPopMatrix();

    //---11

    int j10;

    GLfloat x10=-0.50f; GLfloat y10=0.16f; GLfloat radi10 =0.03;
    int triangleAmount10 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi10 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x10, y10); // center of circle
        for(j10 = 0; j10 <= triangleAmount10;j10++) {
            glVertex2f( x10 + (radi10 * cos(j10 *  twicePi10 / triangleAmount10)),
                        y10 + (radi10 * sin(j10* twicePi10 / triangleAmount10)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.50f, 0.09f);
    glVertex2f(-0.50f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.45f, 0.05f);
    glVertex2f(-0.50f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.55f, 0.05f);
    glVertex2f(-0.50f, 0.10f);
    glEnd();


    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.50f, 0.12f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);        //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.54f, 0.14f);
    glVertex2f(-0.50f, 0.12f);
    glEnd();
    glPopMatrix();

    //---12
     //Head
    int j11;

    GLfloat x11=0.50f; GLfloat y11=0.16f; GLfloat radi11 =0.03;
    int triangleAmount11 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi11 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x11, y11); // center of circle
        for(j11 = 0; j11 <= triangleAmount;j11++) {
            glVertex2f( x11 + (radi11 * cos(j11 *  twicePi11 / triangleAmount11)),
                        y11 + (radi11 * sin(j11* twicePi11 / triangleAmount11)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.50f, 0.09f);
    glVertex2f(0.50f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.45f, 0.05f);
    glVertex2f(0.50f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.55f, 0.05f);
    glVertex2f(0.50f, 0.10f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.46f, 0.14f);
    glVertex2f(0.50f, 0.12f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.54f, 0.14f);
    glVertex2f(0.50f, 0.12f);
    glEnd();
    glPopMatrix();

    //--13

    int j12;

    GLfloat x12=0.65f; GLfloat y12=0.16f; GLfloat radi12 =0.03;
    int triangleAmount12 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi12 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x12, y12); // center of circle
        for(j12 = 0; j12 <= triangleAmount12;j12++) {
            glVertex2f( x12 + (radi12 * cos(j12 *  twicePi12 / triangleAmount12)),
                        y12 + (radi12 * sin(j12* twicePi12 / triangleAmount12)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.65f, 0.09f);
    glVertex2f(0.65f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.60f, 0.05f);
    glVertex2f(0.65f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.70f, 0.05f);
    glVertex2f(0.65f, 0.10f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.61f, 0.14f);
    glVertex2f(0.65f, 0.12f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.69f, 0.14f);
    glVertex2f(0.65f, 0.12f);
    glEnd();
    glPopMatrix();

    //--14

    int j13;

    GLfloat x13=-0.65f; GLfloat y13=0.16f; GLfloat radi13 =0.03;
    int triangleAmount13 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi13 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x13, y13); // center of circle
        for(j13 = 0; j13 <= triangleAmount;j13++) {
            glVertex2f( x13 + (radi13 * cos(j13 *  twicePi13 / triangleAmount13)),
                        y13 + (radi13 * sin(j13* twicePi13 / triangleAmount13)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.65f, 0.09f);
    glVertex2f(-0.65f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,1.0f);
    glVertex2f(-0.60f, 0.05f);
    glVertex2f(-0.65f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,1.0f);
    glVertex2f(-0.70f, 0.05f);
    glVertex2f(-0.65f, 0.10f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.61f, 0.14f);
    glVertex2f(-0.65f, 0.12f);
    glEnd();
    glPopMatrix();


     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.69f, 0.14f);
    glVertex2f(-0.65f, 0.12f);
    glEnd();
    glPopMatrix();

    //--15

    int j14;

    GLfloat x14=-0.80f; GLfloat y14=0.16f; GLfloat radi14 =0.03;
    int triangleAmount14 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi14 = 2.0f * PI;

    glColor3f(0.250f, 0.250f, 0.250f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x14, y14); // center of circle
        for(j14 = 0; j14 <= triangleAmount14;j14++) {
            glVertex2f( x14 + (radi14 * cos(j14 *  twicePi14 / triangleAmount14)),
                        y14 + (radi14 * sin(j14* twicePi14 / triangleAmount14)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.80f, 0.09f);
    glVertex2f(-0.80f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.75f, 0.05f);
    glVertex2f(-0.80f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.85f, 0.05f);
    glVertex2f(-0.80f, 0.10f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.76f, 0.14f);
    glVertex2f(-0.80f, 0.12f);
    glEnd();
    glPopMatrix();


     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.84f, 0.14f);
    glVertex2f(-0.80f, 0.12f);
    glEnd();
    glPopMatrix();

    //--16

    int j15;

    GLfloat x15=0.80f; GLfloat y15=0.16f; GLfloat radi15 =0.03;
    int triangleAmount15 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi15 = 2.0f * PI;

    glColor3f(0.150f, 0.0f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x15, y15); // center of circle
        for(j15 = 0; j15 <= triangleAmount15;j15++) {
            glVertex2f( x15 + (radi15 * cos(j15 *  twicePi15 / triangleAmount15)),
                        y15 + (radi15 * sin(j15* twicePi15 / triangleAmount15)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.80f, 0.09f);
    glVertex2f(0.80f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.75f, 0.05f);
    glVertex2f(0.80f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.85f, 0.05f);
    glVertex2f(0.80f, 0.10f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.76f, 0.14f);
    glVertex2f(0.80f, 0.12f);
    glEnd();
    glPopMatrix();


     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.84f, 0.14f);
    glVertex2f(0.80f, 0.12f);
    glEnd();
    glPopMatrix();

    //--17
    int j16;

    GLfloat x16=0.37f; GLfloat y16=0.16f; GLfloat radi16 =0.03;
    int triangleAmount16 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi16 = 2.0f * PI;

    glColor3f(0.150f, 0.0f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x16, y16); // center of circle
        for(j16 = 0; j16 <= triangleAmount16;j16++) {
            glVertex2f( x16 + (radi16 * cos(j16 *  twicePi16 / triangleAmount16)),
                        y16 + (radi16 * sin(j16* twicePi16 / triangleAmount16)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.37f, 0.09f);
    glVertex2f(0.37f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.32f, 0.05f);
    glVertex2f(0.37f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.42f, 0.05f);
    glVertex2f(0.37f, 0.10f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.33f, 0.14f);
    glVertex2f(0.37f, 0.12f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);         //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.41f, 0.14f);
    glVertex2f(0.37f, 0.12f);
    glEnd();
    glPopMatrix();

    //-18
     //Head
    int j17;

    GLfloat x17=-0.37f; GLfloat y17=0.16f; GLfloat radi17 =0.03;
    int triangleAmount17 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi17 = 2.0f * PI;

    glColor3f(0.150f, 0.0f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x17, y17); // center of circle
        for(j17 = 0; j17 <= triangleAmount17;j17++) {
            glVertex2f( x17 + (radi17 * cos(j17 *  twicePi17 / triangleAmount17)),
                        y17 + (radi17 * sin(j17* twicePi17 / triangleAmount17)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.37f, 0.09f);
    glVertex2f(-0.37f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.32f, 0.05f);
    glVertex2f(-0.37f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.42f, 0.05f);
    glVertex2f(-0.37f, 0.10f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.33f, 0.14f);
    glVertex2f(-0.37f, 0.12f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.41f, 0.14f);
    glVertex2f(-0.37f, 0.12f);
    glEnd();
    glPopMatrix();

    //--19
    int j18;

    GLfloat x18=0.92f; GLfloat y18=0.16f; GLfloat radi18 =0.03;
    int triangleAmount18 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi18 = 2.0f * PI;

    glColor3f(0.150f, 0.250f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x18, y18); // center of circle
        for(j18 = 0; j18 <= triangleAmount18;j18++) {
            glVertex2f( x18 + (radi18 * cos(j18 *  twicePi18 / triangleAmount18)),
                        y18 + (radi18 * sin(j18* twicePi18 / triangleAmount18)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.92f, 0.09f);
    glVertex2f(0.92f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.87f, 0.05f);
    glVertex2f(0.92f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.97f, 0.05f);
    glVertex2f(0.92f, 0.10f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.88f, 0.14f);
    glVertex2f(0.92f, 0.12f);
    glEnd();
     glPopMatrix();

      glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.96f, 0.14f);
    glVertex2f(0.92f, 0.12f);
    glEnd();
     glPopMatrix();

     //--20

      int j19;

    GLfloat x19=-0.92f; GLfloat y19=0.16f; GLfloat radi19 =0.03;
    int triangleAmount19 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi19 = 2.0f * PI;

    glColor3f(0.150f, 0.250f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x19, y19); // center of circle
        for(j19 = 0; j19 <= triangleAmount19;j19++) {
            glVertex2f( x19 + (radi19 * cos(j19 *  twicePi19 / triangleAmount19)),
                        y19 + (radi19 * sin(j19* twicePi19 / triangleAmount19)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.92f, 0.09f);
    glVertex2f(-0.92f, 0.16f);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.87f, 0.05f);
    glVertex2f(-0.92f, 0.10f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.97f, 0.05f);
    glVertex2f(-0.92f, 0.10f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.88f, 0.14f);
    glVertex2f(-0.92f, 0.12f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.96f, 0.14f);
    glVertex2f(-0.92f, 0.12f);
    glEnd();
    glPopMatrix();

    //-21

    int j20;

    GLfloat x20=-0.92f; GLfloat y20=0.43f; GLfloat radi20 =0.03;
    int triangleAmount20 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi20 = 2.0f * PI;

    glColor3f(0.150f, 0.250f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x20, y20); // center of circle
        for(j20 = 0; j20 <= triangleAmount20;j20++) {
            glVertex2f( x20+ (radi20 * cos(j20 *  twicePi20 / triangleAmount20)),
                        y20 + (radi20* sin(j20* twicePi20 / triangleAmount20)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.92f, 0.35);
    glVertex2f(-0.92f, 0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.87f, 0.31f);
    glVertex2f(-0.92f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.97f, 0.31f);
    glVertex2f(-0.92f, 0.36f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);        //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.88f, 0.37f);
    glVertex2f(-0.92f, 0.39f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);          //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.96f, 0.37f);
    glVertex2f(-0.92f, 0.39f);
    glEnd();
    glPopMatrix();

    //--22
    int j21;

    GLfloat x21=0.92f; GLfloat y21=0.43f; GLfloat radi21 =0.03;
    int triangleAmount21 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi21 = 2.0f * PI;

    glColor3f(0.0f, 0.250f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x21, y21); // center of circle
        for(j21 = 0; j21 <= triangleAmount21;j21++) {
            glVertex2f( x21 + (radi21 * cos(j21 *  twicePi21 / triangleAmount21)),
                        y21 + (radi21 * sin(j21* twicePi21 / triangleAmount21)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.92f, 0.35);
    glVertex2f(0.92f, 0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.87f, 0.31f);
    glVertex2f(0.92f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.97f, 0.31f);
    glVertex2f(0.92f, 0.36f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.88f, 0.37f);
    glVertex2f(0.92f, 0.39f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.96f, 0.37f);
    glVertex2f(0.92f, 0.39f);
    glEnd();
    glPopMatrix();

    //--23

    int j22;

    GLfloat x22=0.80f; GLfloat y22=0.43f; GLfloat radi22 =0.03;
    int triangleAmount22 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi22 = 2.0f * PI;

    glColor3f(0.0f, 0.250f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x22, y22); // center of circle
        for(j22 = 0; j22 <= triangleAmount22;j22++) {
            glVertex2f( x22 + (radi22 * cos(j22 *  twicePi22 / triangleAmount22)),
                        y22+ (radi22 * sin(j22* twicePi22 / triangleAmount22)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.80f, 0.35);
    glVertex2f(0.80f, 0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.75f, 0.31f);
    glVertex2f(0.80f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.85f, 0.31f);
    glVertex2f(0.80f, 0.36f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.76f, 0.37f);
    glVertex2f(0.80f, 0.39f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);        //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.84f, 0.37f);
    glVertex2f(0.80f, 0.39f);
    glEnd();
    glPopMatrix();

    //--24

    int j23;

    GLfloat x23=-0.80f; GLfloat y23=0.43f; GLfloat radi23 =0.03;
    int triangleAmount23 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi23 = 2.0f * PI;

    glColor3f(0.0f, 0.250f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x23, y23); // center of circle
        for(j23 = 0; j23 <= triangleAmount23;j23++) {
            glVertex2f( x23 + (radi23 * cos(j23 *  twicePi23 / triangleAmount23)),
                        y23 + (radi23 * sin(j23* twicePi23 / triangleAmount23)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.80f, 0.35);
    glVertex2f(-0.80f, 0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.75f, 0.31f);
    glVertex2f(-0.80f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.85f, 0.31f);
    glVertex2f(-0.80f, 0.36f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.76f, 0.37f);
    glVertex2f(-0.80f, 0.39f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);        //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.84f, 0.37f);
    glVertex2f(-0.80f, 0.39f);
    glEnd();
    glPopMatrix();

    //--25

    int j24;

    GLfloat x24=-0.65f; GLfloat y24=0.43f; GLfloat radi24 =0.03;
    int triangleAmount24 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi24 = 2.0f * PI;

    glColor3f(0.150f, 0.0f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x24, y24); // center of circle
        for(j24 = 0; j24 <= triangleAmount24;j24++) {
            glVertex2f( x24 + (radi24 * cos(j24 *  twicePi24 / triangleAmount24)),
                        y24 + (radi24 * sin(j24* twicePi24 / triangleAmount24)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.65f, 0.35);
    glVertex2f(-0.65f, 0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.60f, 0.31f);
    glVertex2f(-0.65f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.70f, 0.31f);
    glVertex2f(-0.65f, 0.36f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.61f, 0.37f);
    glVertex2f(-0.65f, 0.39f);
    glEnd();
    glPopMatrix();


     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.69f, 0.37f);
    glVertex2f(-0.65f, 0.39f);
    glEnd();
    glPopMatrix();

    //--26

    int j25;

    GLfloat x25=0.65f; GLfloat y25=0.43f; GLfloat radi25 =0.03;
    int triangleAmount25 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi25 = 2.0f * PI;

    glColor3f(0.150f, 0.250f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x25, y25); // center of circle
        for(j25 = 0; j25 <= triangleAmount25;j25++) {
            glVertex2f( x25 + (radi25 * cos(j25 *  twicePi25 / triangleAmount25)),
                        y25 + (radi25 * sin(j25* twicePi25 / triangleAmount25)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.65f, 0.35);
    glVertex2f(0.65f, 0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.60f, 0.31f);
    glVertex2f(0.65f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.70f, 0.31f);
    glVertex2f(0.65f, 0.36f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.61f, 0.37f);
    glVertex2f(0.65f, 0.39f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.69f, 0.37f);
    glVertex2f(0.65f, 0.39f);
    glEnd();
    glPopMatrix();

    //--27

    int j26;

    GLfloat x26=0.50; GLfloat y26=0.43f; GLfloat radi26 =0.03;
    int triangleAmount26 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi26 = 2.0f * PI;

    glColor3f(0.150f, 0.0f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x26, y26); // center of circle
        for(j26 = 0; j26 <= triangleAmount26;j26++) {
            glVertex2f( x26 + (radi26 * cos(j26 *  twicePi26 / triangleAmount26)),
                        y26 + (radi26 * sin(j26* twicePi26 / triangleAmount26)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.50f,0.35f);
    glVertex2f(0.50f,0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.45f,  0.31f);
    glVertex2f(0.50f,0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.55f, 0.31f);
    glVertex2f(0.50f, 0.36f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);     //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.46f, 0.37f);
    glVertex2f(0.50f, 0.39f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);        //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.54f,0.37f);
    glVertex2f(0.50f, 0.39f);
    glEnd();
    glPopMatrix();

    //--28

    int j27;

    GLfloat x27=-0.50; GLfloat y27=0.43f; GLfloat radi27 =0.03;
    int triangleAmount27 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi27 = 2.0f * PI;

    glColor3f(0.150f, 0.0f, 0.150f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x27, y27); // center of circle
        for(j27 = 0; j27 <= triangleAmount27;j27++) {
            glVertex2f( x27 + (radi27 * cos(j27 *  twicePi27 / triangleAmount27)),
                        y27 + (radi27 * sin(j27* twicePi27 / triangleAmount27)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.50f,0.35f);
    glVertex2f(-0.50f,0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.45f,  0.31f);
    glVertex2f(-0.50f,0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.55f, 0.31f);
    glVertex2f(-0.50f, 0.36f);
    glEnd();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);    //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.46f, 0.37f);
    glVertex2f(-0.50f, 0.39f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.54f,0.37f);
    glVertex2f(-0.50f, 0.39f);
    glEnd();
    glPopMatrix();

    //--29

    int j28;

    GLfloat x28=-0.37; GLfloat y28=0.43f; GLfloat radi28 =0.03;
    int triangleAmount28 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi28 = 2.0f * PI;

    glColor3f(0.0f, 0.150f, 0.350f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x28, y28); // center of circle
        for(j28 = 0; j28 <= triangleAmount28;j28++) {
            glVertex2f( x28 + (radi28 * cos(j28 *  twicePi28 / triangleAmount28)),
                        y28 + (radi28 * sin(j28* twicePi28 / triangleAmount28)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(-0.37f,0.35f);
    glVertex2f(-0.37f,0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.32f, 0.31f);
    glVertex2f(-0.37f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(-0.42f, 0.31f);
    glVertex2f(-0.37f, 0.36f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.33f, 0.37f);
    glVertex2f(-0.37f, 0.39f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(-0.41f,0.37f);
    glVertex2f(-0.37f, 0.39f);
    glEnd();
    glPopMatrix();

    //--30

    int j29;

    GLfloat x29=0.37; GLfloat y29=0.43f; GLfloat radi29 =0.03;
    int triangleAmount29 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi29 = 2.0f * PI;

    glColor3f(0.0f, 0.150f, 0.350f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x29, y29); // center of circle
        for(j29 = 0; j29 <= triangleAmount29;j29++) {
            glVertex2f( x29 + (radi29 * cos(j29 *  twicePi29 / triangleAmount29)),
                        y29 + (radi29 * sin(j29* twicePi29 / triangleAmount29)) );
        }
    glEnd();

    //body

    glBegin(GL_LINES);
    glColor3f(0.250f,0.0f,0.250f);
    glVertex2f(0.37f,0.35f);
    glVertex2f(0.37f,0.41);
    glEnd();

    //Leg 1
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.32f, 0.31f);
    glVertex2f(0.37f, 0.36f);
    glEnd();

       //Leg 2
    glBegin(GL_LINES);
    glColor3f(0.570f, 0.570f, 0.250f);
    glVertex2f(0.42f, 0.31f);
    glVertex2f(0.37f, 0.36f);
    glEnd();

    glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);      //Hand 1
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.33f, 0.37f);
    glVertex2f(0.37f, 0.39f);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef( 0.00f,audiposition, 0.0f);       //Hand 2
    glBegin(GL_LINES);
    glColor3f(0.0f,0.250f,0.250f);
    glVertex2f(0.41f,0.37f);
    glVertex2f(0.37f, 0.39f);
    glEnd();
    glPopMatrix();






}

void showResult(int value)
{
    // Generate a random toss result
    tossResult = rand() % 2;

    // Mark the current window as needing to be redisplayed
    glutPostRedisplay();
}

void onClick(int button, int state, int x, int y)
{
    // Check if the left mouse button was clicked
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        Coin_sound();
        // Set the flag to true
        isButtonClicked = true;

        // Reset the rotation angle
        i = 0.0f;

        // Register the timer callback to show the result after 3 seconds
        glutTimerFunc(3000, showResult, 0);

        // Mark the current window as needing to be redisplayed
        glutPostRedisplay();
    }

}




int score1=0;
int score2=0;
int score3=0;
void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
batspeed =0.005f;
    score3=score3+1;

break;
case GLUT_KEY_DOWN:
batspeed =0.005f;
    score2=score2+6;

break;
case GLUT_KEY_LEFT:
    batspeed =0.005f;
    score1=score1+4;
break;
case GLUT_KEY_RIGHT:
    batspeed =0.0f;
    Field_sound();

break;
}
score =score1+score2+score3;
glutPostRedisplay();
}


int counter =0;
void KeyboardInput(unsigned char key, int x, int y)
{
    if(key=='f')
    {
        counter=2;
          Field_sound();
        //glutPostRedisplay();
    }
    else if(key=='e')
    {
        counter =3;
    }

    else if(key=='i')
    {

        counter =4;
        //glutPostRedisplay();
    }
      else if(key=='g')
    {
        counter= 1;
        GameMenu_sound();
        score1=0;
        score2=0;
        score3=0;
        score=score1+score2+score3;


        //glutPostRedisplay();
    }
     else if(key=='m')
    {
        counter =5;
        Welcome_sound();
    }
     else if(key=='o')
    {

        counter =6;
    }
    else if(key=='d')
    {
        ballspeed = 0.0f;
    }
    else if(key=='s')
    {
        ballspeed = 0.05f;

    }
    else if (key=='a')
    {
        counter =7;
        Audience_sound();
    }
    else if (key=='p')
    {
        Silent_sound();
        counter=8;
    }
    else if(key=='t')
    {
        counter=9;
          Field_sound();

        score1=0;
        score2=0;
        score3=0;
        score=score1+score2+score3;
    }







glutPostRedisplay();
}


void display()
{

 if(counter==2)
    {

    fieldstuff();
    glPushMatrix();
    glTranslatef( batposition,0.01f, 0.0f);
    bat();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.12f ,ballposition, 0.0f);
    ball();
    glPopMatrix();

    }

    if(counter==9)
    {

    fieldstuffB();
    glPushMatrix();
    glTranslatef( batposition,0.01f, 0.0f);
    bat();
    glPopMatrix();

    ballposition=-0.09;
    glPushMatrix();
    glTranslatef(0.12f ,ballposition, 0.0f);
    ball();
    glPopMatrix();

    }
    if(counter==3)
    {
        exit(0);

    }


    if(counter==1)
    {
        Menu_display();
    }

    if(counter==4)
    {

        Instruction_display();
    }
    if(counter==5)
    {
        Cover_display();
    }
    if(counter==6)
    {

        Objective_display();
    }
    if(counter==7)
    {
        gallerystuff();

    audience_Info();


    }
    if(counter==8)
    {
        Coin();
        Idle();
    }


   glFlush();
}
 int main(int argc, char** argv)
{
    printf("Press m to Open the game");
	glutInit(&argc, argv);          // Initialize GLUT
	glutInitWindowSize(1300, 730);   // Set the window's initial width & height
	glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
	glutCreateWindow("Cricket Game");  // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutSpecialFunc(SpecialInput);
	glutKeyboardFunc(KeyboardInput);
	glutTimerFunc(100, updateball, 0);
	glutTimerFunc(100, updatebat, 0);
	glutTimerFunc(100, updateaudi, 0);
	glutTimerFunc(100, updatecloud, 0);
	glutMouseFunc(onClick);
	initGL();
	glutIdleFunc(Idle);                      // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
