#include "Block.h"
#include<math.h>

int sens = 0;
float angle1 = 0.0;
float angle2 = 0.0;
float angle3 = 0.0;
float angle4 = 0.0;
float angle5 = 0.0;

Block::Block()
{
    posx = 0.0f;
    posy = 0.0f;
    posz = 0.0f;

    x = 1.0f;
    y = 1.0f;
    z = 1.0f;

    for (int i = 0; i < 6; i++)
    {
        textures[i] = 0;
    }
    for (int j = 0; j < 3; j ++)
    {
        anchor[j] = 0;
    }
}

Block::Block(float x, float y, float z)
{
    posx = 0.0f;
    posy = 0.0f;
    posz = 0.0f;

    this->x = x;
    this->y = y;
    this->z = z;

    for (int i = 0; i < 6; i++)
    {
        textures[i] = 0;
    }
    for (int j = 0; j < 3; j ++)
    {
        anchor[j] = 0;
    }
}

void Block::Draw()
{
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    if (anchor[0]) glTranslatef(-x/2, 0.0f, 0.0f);
    if (anchor[1]) glTranslatef(0.0f, -y/2, 0.0f);
    if (anchor[2]) glTranslatef(0.0f, 0.0f, -z/2);

    glPushMatrix();
        glTranslatef(0.0f, 20.0f,-20.0f);
        Tete();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0f, 17.8f,-20.0f);
        Cou();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0f, 16.0f, -20.0f);
        Corps();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.8f, 12.5f, -20.0f);
        Jambes();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.8f, 12.5f, -20.0f);
        Pieds();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-2.3f,15.5f,-20.0f);
        glRotatef(angle1,0,0,1);
        glTranslatef(0.0f, -1.0f, 0.0f);
        Bras();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.8f, 23.0f, -20.0f);
        Cerceau();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.3f, 33.0f, -20.0f);
        Murs();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0f, 0.3f, 18.0f);
        glRotatef(angle1,0,1,0);
        glTranslatef(0.0f, -1.0f, 0.0f);
        Tables();
        Vase();
        Fleurs();
    glPopMatrix();
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glTranslatef(0.0f, 3.0f, 28.0f);
        GrandeTable();
    glPopMatrix();
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glTranslatef(0.0f, 6.0f, 28.0f);
        PiedTable();
    glPopMatrix();
    glPushMatrix();
        glDisable(GL_TEXTURE_2D);
        glTranslatef(0.0f,2.0f,32.0f);
        Chaise1();
    glPopMatrix();
    glPushMatrix();
        glDisable(GL_TEXTURE_2D);
        glTranslatef(0.0f,2.0f,24.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        Chaise2();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-11.0f,47.0f,-23.0f);
        glColor3f(0.64f, 0.16f, 0.16f);
        glutSolidSphere(1.2,12,12);
    glPopMatrix();
    glPushMatrix();
        glDisable(GL_TEXTURE_2D);
        glTranslatef(-11.0f,47.0f,-24.0f);
        glRotatef(angle3,0,0,1);
        glTranslatef(0.0f, 0.0f, 1.0f);
        GdeAiguille();
    glPopMatrix();
    glPushMatrix();
        glDisable(GL_TEXTURE_2D);
        glTranslatef(-11.0f,47.0f,-24.0f);
        glRotatef(angle4,0,0,1);
        glTranslatef(0.0f, 0.0f, 1.0f);
        PttAiguille();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-10.0f,14.0f,80.0f);
        glRotatef(180,0.0,1.0,1.0);
        glRotatef(angle5,0,0,1);
        glTranslatef(0.0f, 1.0f, 0.0f);
        Porte();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-5.0f,14.0f,80.0f);
        glRotatef(180,0.0,1.0,1.0);
        glRotatef(angle5,0,0,1);
        glTranslatef(0.0f, 1.0f, 0.0f);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-10.0f,14.0f,80.0f);
        glColor3f(0.90f, 0.91f, 0.98f);
        ArmaturePorte();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(18.0f, 32.0f, -15.0f);
        Chapeau();
    glPopMatrix();
}

void Block::SetTexture(int face, GLuint texture)
{
    textures[face] = texture;
}

void Block::Tete()
{
    //cadre intérieur du robot
    glPushMatrix();
        //glTranslatef(0.0f, 10.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f); //A remplacer
        glScalef(2.0,1.0,1.0);
        glutSolidCube(2.0);
    glPopMatrix();
    //cadre extérieur du robot
    glPushMatrix();
        //glTranslatef(5.0f, 10.0f, 2.0f);
        glColor3f(0.0f, 0.5f, 0.5f);
        glScalef(2.8,1.0,1.0);
        glutSolidCube(2.0);
    glPopMatrix();
    //les yeux sphere
    glPushMatrix();
        glTranslatef(-1.0f, 0.0f, 0.5f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidSphere(1.0, 20, 30);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0f, 0.0f, 0.5f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidSphere(1.0, 20, 30);
    glPopMatrix();
    //pupilles des yeux
    glPushMatrix();
        glTranslatef(1.0f, 0.0f, 1.2f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glutSolidSphere(0.5, 20, 30);
    glPopMatrix();
    glPushMatrix();
        //glRotatef(angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(-1.0f, 0.0f, 1.2f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glutSolidSphere(0.5, 20, 30);
    glPopMatrix();
}

void Block::Cou()
{
    //1ere partie du cou du robot
    glPushMatrix();
        //glTranslatef(2.0F,10.0F,0.0F);
        glColor3f(0.5f, 0.5f, 0.5f);
        Cylindre(2.5,0.5,12,12);
    glPopMatrix();
    //articulation cou
    glPushMatrix();
        //glTranslatef(2.0f, 7.0f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidSphere(0.5, 20, 30);
    glPopMatrix();
    //2eme partie du cou du robot
    glPushMatrix();
        //glTranslatef(2.0F,6.0F,0.0F);
        glColor3f(1.0f, 0.5f, 0.5f);
        Cylindre(2.5,0.5,12,12);
    glPopMatrix();
}

void Block::Corps()
{
    //corps du robot
    glPushMatrix();
        //glTranslatef(2.0f, 5.0f, 0.0f);
        glScalef(2.3,1.0,1.0);
        glutSolidCube(2.0);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0f, -2.0f, 0.0f);
        glScalef(2.3,1.0,1.0);
        glutSolidCube(2.0);
    glPopMatrix();

    //coté du corps gauche
    glPushMatrix();
        glTranslatef(0.2f, -0.5f, -1.0f);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
            glVertex3f(-5.0,-2.5,0.0);//point bas droite
            glVertex3f(-2.5,1.7,0.0);//point haut
            glVertex3f(-2.5,-2.5,0.0);//point bas gauche
        glEnd();
        glPopMatrix();
        glTranslatef(0.2f, 0.0f, -3.0f);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
            glVertex3f(-5.0,-2.5,5.0);//point bas droite
            glVertex3f(-2.6,1.6,5.0);//point haut
            glVertex3f(-2.5,-2.5,5.0);//point bas gauche
        glEnd();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2f, -0.5f, 1.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
            glVertex3f(-5.0,-2.5,0.0);//point bas droite
            glVertex3f(-2.5,1.7,0.0);//point haut
            glVertex3f(-2.5,-2.5,0.0);//point bas gauche
        glEnd();
        glPopMatrix();
        glTranslatef(0.2f, 0.0f, -3.0f);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
            glVertex3f(-5.0,-2.5,5.0);//point bas droite
            glVertex3f(-2.6,1.6,5.0);//point haut
            glVertex3f(-2.5,-2.5,5.0);//point bas gauche
        glEnd();
        glPopMatrix();
    glPopMatrix();

    //partie droite
    /* glPushMatrix();
        glTranslatef(-0.2f, 0.5f, 1.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
            glColor3f(1.5f, 0.2f, 0.5f);
            glVertex3f(-5.0,-2.5,0.0);
            glVertex3f(-2.5,1.7,0.0);
            glVertex3f(-2.5,-2.5,0.0);
        glEnd();
        glPopMatrix();
        glTranslatef(0.2f, 0.0f, -3.0f);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
            glVertex3f(-5.0,-2.5,5.0);
            glVertex3f(-2.6,1.6,5.0);
            glVertex3f(-2.5,-2.5,5.0);
        glEnd();
        glPopMatrix();
    glPopMatrix(); */

    //rectange des triangles en bas du corps
    glPushMatrix();
        glTranslatef(0.0f, -3.0f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRectf(-4.5f, 1.0f, 4.5f, -1.0f);
    glPopMatrix();
}

void Block::Jambes()
{
    //Jambe gauche
    //1ere articulation
    glPushMatrix();
        glColor3f(1.5f, 0.2f, 0.5f);
        glutSolidSphere(0.9, 20, 30);
    glPopMatrix();

    //1ere partie jambe gauche du robot
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 2.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glColor3f(0.5f, 0.2f, 0.5f);
        Cylindre(3.8,0.5,12,12);
    glPopMatrix();

    //2ere articulation jambe gauche du robot
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 4.3f);
        glColor3f(1.5f, 0.2f, 0.5f);
        glutSolidSphere(0.7, 20, 30);
    glPopMatrix();

    //2eme partie jambe gauche
    glPushMatrix();
        glTranslatef(0.0f, -2.0f, 4.3f);
        glColor3f(0.5f, 0.2f, 0.5f);
        Cylindre(3.8,0.5,12,12);
    glPopMatrix();

    //3ere articulation jambe gauche
    glPushMatrix();
        //glRotatef(angle2, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, -4.0f, 4.3f);
        glColor3f(0.45f, 0.85f, 0.85f);
        glutSolidSphere(0.6, 20, 30);
    glPopMatrix();

    //Jambe droite
    //1ere articulation
    glTranslatef(3.5f,0.0f,0.0f);
    glPushMatrix();
        glColor3f(1.5f, 0.2f, 0.5f);
        glutSolidSphere(0.9, 20, 30);
    glPopMatrix();

    //1ere partie
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 2.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glColor3f(0.5f, 0.2f, 0.5f);
        Cylindre(3.8,0.5,12,12);
    glPopMatrix();

    //2ere articulation
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 4.3f);
        glColor3f(1.5f, 0.2f, 0.5f);
        glutSolidSphere(0.7, 20, 30);
    glPopMatrix();

    //2eme partie
    glPushMatrix();
        glTranslatef(0.0f, -2.0f, 4.3f);
        glColor3f(0.5f, 0.2f, 0.5f);
        Cylindre(3.8,0.5,12,12);
    glPopMatrix();

    //3ere articulation
    glPushMatrix();
        glTranslatef(0.0f, -4.0f, 4.3f);
        glColor3f(0.45f, 0.85f, 0.85f);
        glutSolidSphere(0.6, 20, 30);
    glPopMatrix();
}

void Block::Pieds()
{
    //pied gauche
    glPushMatrix();
        glTranslatef(0.0f, -5.4f, 4.3f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        glColor3f(0.45f, 0.85f, 0.85f);
        glutSolidCone(1, 2, 20, 30);
    glPopMatrix();

    //pied droit
    glTranslatef(3.5f, 0.0f, 0.0f);
    glPushMatrix();
        glTranslatef(0.0f, -5.4f, 4.3f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        glColor3f(0.45f, 0.85f, 0.85f);
        glutSolidCone(1, 2, 20, 30);
    glPopMatrix();
}

void Block::Bras()
{
    //1ere articulation gauche
    glPushMatrix();
        //glTranslatef(6.5f, 4.5f, 0.0f);
        glColor3f(0.45f, 0.85f, 0.85f);
        glutSolidSphere(0.9, 20, 30);
    glPopMatrix();

    // avant-bras gauche
    glPushMatrix();
        //1ere partie bras gauche
        glPushMatrix();
            glTranslatef(-1.6f, 1.8f, 0.0f);
            glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
            glColor3f(0.5f, 0.2f, 0.5f);
            Cylindre(3.5,0.5,12,12);
        glPopMatrix();

        //2eme articulation bras gauche
        glPushMatrix();
            glTranslatef(-2.8f, 3.0f, 0.0f);
            glColor3f(0.45f, 0.85f, 0.85f);
            glutSolidSphere(0.7, 20, 30);
        glPopMatrix();

        //2eme partie bras gauche
        glPushMatrix();
            glTranslatef(-4.2f, 2.5f, 0.0f);
            glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
            glColor3f(0.5f, 0.2f, 0.5f);
            Cylindre(2.8,0.4,12,12);
        glPopMatrix();

        //support main gauche
        glPushMatrix();
            glTranslatef(-5.4f, 1.9f, 0.0f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glutSolidSphere(0.6, 20, 30);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-6.2f, 1.4f, 0.0f);
            glColor3f(1.0f, 1.0f, 0.0f);
            glutSolidSphere(0.8, 20, 30);
        glPopMatrix();
    glPopMatrix();

    //avant bras droit
    glTranslatef(4.6f, 0.4f, 0.0f);
    glRotatef(180.0f,0.0f,1.0f,0.0);
    glPushMatrix();
        glColor3f(0.45f, 0.85f, 0.85f);//1ere articulation
        glutSolidSphere(0.9, 20, 30);
    glPopMatrix();

    // avant-bras
    glPushMatrix();
        //1ere partie bras
        glPushMatrix();
            glTranslatef(-1.6f, 1.8f, 0.0f);
            glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
            glColor3f(0.5f, 0.2f, 0.5f);
            Cylindre(3.5,0.5,12,12);
        glPopMatrix();

        //2eme articulation bras
        glPushMatrix();
            glTranslatef(-2.8f, 3.0f, 0.0f);
            glColor3f(0.45f, 0.85f, 0.85f);
            glutSolidSphere(0.7, 20, 30);
        glPopMatrix();

        //2eme partie bras
        glPushMatrix();
            glTranslatef(-3.9f, 4.0f, 0.0f);
            glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
            glColor3f(0.5f, 0.2f, 0.5f);
            Cylindre(2.8,0.4,12,12);
        glPopMatrix();

        //support main gauche
        glPushMatrix();
            glTranslatef(-5.0f, 5.0f, 0.0f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glutSolidSphere(0.6, 20, 30);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-5.6f, 5.5f, 0.0f);
            glColor3f(1.0f, 1.0f, 0.0f);
            glutSolidSphere(0.8, 20, 30);
        glPopMatrix();
    glPopMatrix();
}

void Block::Cerceau()
{
    glPushMatrix();//Cerceau 1 central
        glColor3f(0.13f, 0.55f, 0.13f);
        glutSolidTorus(0.7,12,20,20);
    glPopMatrix();

    glTranslatef(20.0f,10.0f,-0.25f);
    glPushMatrix();//Cerceau 2
        glColor3f(0.60f, 0.10f, 1.00f);
        glutSolidTorus(0.7,12,20,20);
    glPopMatrix();

    glTranslatef(-30.0f,12.0f,-1.5f);
    glPushMatrix();//Cerceau 3
        glColor3f(0.60f, 0.80f, 1.00f);
        glutSolidTorus(0.7,12,20,20);
    glPopMatrix();
}

void Block::Murs()
{
    //Mur horizontal
    glPushMatrix(); //1ere pierre
        glTranslatef(2.0f, 25.0f, 0.0f);
        glColor3f(0.75f, 0.60f, 0.49f);
        glScalef(10.0,1.0,1.0);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//2eme pierre a droite
        glTranslatef(12.0f, 29.0f, 0.0f);
        glColor3f(0.65f, 0.50f, 0.39f);
        glScalef(6.0,1.0,1.0);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//3eme pierre a gauche
        glTranslatef(-10.0f, 29.0f, 0.0f);
        glColor3f(0.55f, 0.40f, 0.29f);
        glScalef(6.0,1.0,1.0);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//4eme pierre a gauche
        glTranslatef(-15.0f, 33.0f, 0.0f);
        glColor3f(0.45f, 0.30f, 0.19f);
        glScalef(7.0,1.0,1.0);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//5eme pierre a droit
        glTranslatef(18.0f, 33.0f, 0.0f);
        glColor3f(0.75f, 0.60f, 0.49f);
        glScalef(7.0,1.0,1.0);
        glutSolidCube(3.5);
    glPopMatrix();

    glPushMatrix();//1er mur vertical droite
        glTranslatef(29.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(10.0,1.0,1.0);
        glColor3f(0.45f, 0.30f, 0.19f);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//2è mur vertical droite
        glTranslatef(32.5f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(8.0,1.0,1.0);
        glColor3f(0.55f, 0.40f, 0.29f);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//1er mur vertical gauche
        glTranslatef(-25.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(9.0,1.0,1.0);
        glColor3f(0.45f, 0.30f, 0.19f);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//2è mur vertical gauche
        glTranslatef(-29.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(11.0,1.0,1.0);
        glColor3f(0.75f, 0.60f, 0.49f);
        glutSolidCube(3.5);
    glPopMatrix();

    //1er mur horizontal bas
    glPushMatrix(); //1ere pierre
        glTranslatef(4.6f, -26.0f, 0.0f);
        glScalef(11.5,1.0,1.0);
        glColor3f(0.75f, 0.60f, 0.49f);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix(); //2è pierre
        glTranslatef(3.8f, -29.5f, 0.0f);
        glScalef(13.5,1.0,1.0);
        glColor3f(0.55f, 0.40f, 0.29f);
        glutSolidCube(3.5);
    glPopMatrix();
    glPushMatrix();//3è pierre
        glTranslatef(0.3f, -32.6f, 0.0f);
        glScalef(13.4,1.0,1.0);
        glColor3f(0.45f, 0.30f, 0.19f);
        glutSolidCube(3.5);
    glPopMatrix();
}

void Block::Tables()
{
    //Pied de la table
    glPushMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        //glColor3f(0.30f, 0.30f, 1.00f);
        glColor3f(0.52f, 0.37f, 0.26f);
        glutSolidCone(1.5, 2.3, 20, 30);
    glPopMatrix();
    //piller de la table
    glPushMatrix();
        glTranslatef(0.0f, 4.0f, 0.0f);
        glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
        glColor3f(0.90f, 0.91f, 0.98f);
        Cylindre(5.0,0.3,12,12);
    glPopMatrix();
    //Tables milieu
    glPushMatrix();
        glTranslatef(0.0f, 6.5f, 0.0f);
        glColor3f(0.36f, 0.20f, 0.09f);
        SolidCylinderSansNormales1(r, h, n);
    glPopMatrix();
    //Table droite
    glPushMatrix();
        glTranslatef(1.5f, 5.5f, 0.0f);
        glColor3f(0.85f, 0.53f, 0.10f);
        SolidCylinderSansNormales1(r1, h1, n1);
    glPopMatrix();
    //Table gauche
    glPushMatrix();
        glTranslatef(-1.5f, 4.5f, 0.0f);
        glColor3f(0.85f, 0.53f, 0.10f);
        SolidCylinderSansNormales1(r1, h1, n1);
    glPopMatrix();
    //Teapot
    glPushMatrix();
        glTranslatef(0.0f, 7.2f, 0.0f);
        glColor3f(0.196078f, 0.8f, 0.6f);
        glutSolidTeapot(1);
    glPopMatrix();
    //Tasse droite
    glPushMatrix();
        glTranslatef(2.8f, 6.3f, 0.0f);
        glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
        glColor3f(0.67f, 0.13f, 0.30f);
        Cylindre(1.5,0.5,12,12);
    glPopMatrix();
    //anse de la tasse
    glPushMatrix();
        glTranslatef(3.2f, 6.5f, 0.0f);
        glColor3f(0.67f, 0.13f, 0.30f);
        glutSolidTorus(0.1,0.4,20,20);
    glPopMatrix();
}

void Block::Vase()
{
    glPushMatrix();
        glTranslatef(-3.0f, 5.0f, 0.0f);
        glutSolidSphere(0.7, 20, 30);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-3.0f, 5.4f, 0.0f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        glutSolidCone(0.6, 1, 20, 30);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-3.0f, 6.3f, 0.0f);
        glColor3f(0.67f, 0.13f, 0.30f);
        Cylindre(1.0,0.2,12,12);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-3.0f, 6.9f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glutSolidCone(0.4, 1, 20, 30);
    glPopMatrix();
}

void Block::Fleurs()
{
    //Fleur #1
    static GLfloat ctrlpoints[4][3] = {
        {-3.0, 4.0, 0.0}, {2.0, -4.0, 0.0},
        {2.0, 4.0, 0.0}, {-3.0, -4.0, 0.0}
    };
    glTranslatef(-3.5f, 7.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f,1.0f,0.40f);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.5, 3, 4, &ctrlpoints[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glBegin(GL_LINE_STRIP);
    for (GLfloat i = 0.0; i <= 1.0; i+=0.05f)
        glEvalCoord1f(i);
    glEnd();
    glDisable(GL_MAP1_VERTEX_3);

    glPushMatrix();
        glDisable(GL_TEXTURE_2D);
        GLUquadric* params = gluNewQuadric();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(-3.0f, 4.0f, 0.0f);
            gluSphere(params,0.5, 20, 30);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(1.4f, 3.5f, -0.3f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(1.6f, 3.0f, 0.0f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(1.0f, 2.5f, 0.0f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();

    //Fleur #2
    static GLfloat ctrlpoints2[4][3] = {
        {3.0, 4.0, 0.0}, {2.0, 4.0, 0.0},
        {2.0, -4.0, 0.0}, {3.0, -4.0, 0.0}
    };
    glTranslatef(-1.9f, -1.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f,1.0f,0.40f);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.8, 3, 4, &ctrlpoints2[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glBegin(GL_LINE_STRIP);
    for (GLfloat i = 0.0; i <= 1.0; i+=0.05f)
        glEvalCoord1f(i);
    glEnd();
    glDisable(GL_MAP1_VERTEX_3);

    glPushMatrix();
        glDisable(GL_TEXTURE_2D);
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(3.0f, 4.0f, 0.0f);
            glColor3f(0.65f,0.49f,0.24f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(-1.4f, 4.9f, -0.5f);
            glColor3f(1.00f,0.60f,1.7f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(-0.8f, 4.9f, 0.8f);
            glColor3f(0.65f,0.49f,0.24f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();

    //Fleur #3
    static GLfloat ctrlpoints3[4][3] = {
        {-3.0, 4.0, 0.0}, {2.0, 4.0, 0.0},
        {2.0, -4.0, 0.0}, {-3.0, -4.0, 0.0}
    };
    glTranslatef(2.0f, -1.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    glColor3f(0.65f,0.49f,0.24f);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.8, 3, 4, &ctrlpoints3[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glBegin(GL_LINE_STRIP);
    for (GLfloat i = 0.0; i <= 1.0; i+=0.05f)
        glEvalCoord1f(i);
    glEnd();
    glDisable(GL_MAP1_VERTEX_3);

    glPushMatrix();
        glDisable(GL_TEXTURE_2D);
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(-3.0f, 4.0f, 0.0f);
            glColor3f(0.65f,0.49f,0.24f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(-3.0f, 3.7f, 0.0f);
            glColor3f(1.00f,0.60f,1.7f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        gluQuadricTexture(params,GL_TRUE);
        glPushMatrix();
            glTranslatef(-3.0f, 3.9f, -0.5f);
            glColor3f(0.65f,0.49f,0.24f);
            gluSphere(params,0.4, 20, 30);
        glPopMatrix();
    glPopMatrix();
}

void Block::GrandeTable()
{
    glPushMatrix();
        glTranslatef(-10.0f,0.0f,-5.5f);
        glScalef(10.0,0.5,6.0);

        /** BACK **/
        glBindTexture(GL_TEXTURE_2D, textures[TOP]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glTexCoord2f(0.0f, y/TEXTURE_SCALE);
            glVertex3f(0.0f, y, 0.0f);
            glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
            glVertex3f(x, y, 0.0f);
            glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
            glVertex3f(x, 0.0f, 0.0f);
        glEnd();

        /** RIGHT **/
        glBindTexture(GL_TEXTURE_2D, textures[TOP]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(x, 0.0f, 0.0f);
            glTexCoord2f(0.0f, z/TEXTURE_SCALE);
            glVertex3f(x, 0.0f, z);
            glTexCoord2f(y/TEXTURE_SCALE, z/TEXTURE_SCALE);
            glVertex3f(x, y, z);
            glTexCoord2f(y/TEXTURE_SCALE, 0.0f);
            glVertex3f(x, y, 0.0f);
        glEnd();

        /** TOP **/
        glBindTexture(GL_TEXTURE_2D, textures[TOP]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.0f, y, 0.0f);
            glTexCoord2f(0.0f, y/TEXTURE_SCALE);
            glVertex3f(0.0f, y, z);
            glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
            glVertex3f(x, y, z);
            glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
            glVertex3f(x, y, 0.0f);
        glEnd();

        /** BOT **/

        glBindTexture(GL_TEXTURE_2D, textures[TOP]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glTexCoord2f(0.0f, z/TEXTURE_SCALE);
            glVertex3f(0.0f, 0.0f, z);
            glTexCoord2f(x/TEXTURE_SCALE, z/TEXTURE_SCALE);
            glVertex3f(x, 0.0f, z);
            glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
            glVertex3f(x, 0.0f, 0.0f);
        glEnd();

        /** FRONT **/
        glBindTexture(GL_TEXTURE_2D, textures[TOP]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, z);
            glTexCoord2f(0.0f, y/TEXTURE_SCALE);
            glVertex3f(0.0f, y, z);
            glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
            glVertex3f(x, y, z);
            glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
            glVertex3f(x, 0.0f, z);
        glEnd();

        /** LEFT **/
        glBindTexture(GL_TEXTURE_2D, textures[TOP]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glTexCoord2f(0.0f, z/TEXTURE_SCALE);
            glVertex3f(0.0f, 0.0f, z);
            glTexCoord2f(y/TEXTURE_SCALE, z/TEXTURE_SCALE);
            glVertex3f(0.0f, y, z);
            glTexCoord2f(y/TEXTURE_SCALE, 0.0f);
            glVertex3f(0.0f, y, 0.0f);
        glEnd();
    glPopMatrix();
}

void Block::PiedTable()
{
    float x = 1.0;
    for(int i=0; i<4; i++)//pied droit arrière
    {
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, textures[LEFT]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params,GL_TRUE);
            glPushMatrix();
                glTranslatef(10.0f, -3.5f*x, -5.5f);
                gluSphere(params,0.8,20,20);
            glPopMatrix();

        glPopMatrix();
        x += 0.4;
    }
    glTranslatef(10.0f, 5.6f, -0.4f);//pied gauche arrière
    for(int i=0; i<4; i++)
    {
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, textures[SPHERE]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params,GL_TRUE);
            glPushMatrix();
                glTranslatef(-20.0f, -3.5f*x, -5.5f);
                gluSphere(params,0.8,20,20);
            glPopMatrix();

        glPopMatrix();
        x += 0.4;
    }
    glTranslatef(20.0f, 5.6f, 12.0f);//pied droit avant
    for(int i=0; i<4; i++)
    {
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, textures[LEFT]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params,GL_TRUE);
            glPushMatrix();
                glTranslatef(-20.0f, -3.5f*x, -5.5f);
                gluSphere(params,0.8,20,20);
            glPopMatrix();

        glPopMatrix();
        x += 0.4;
    }
    glTranslatef(-20.0f, 5.6f, -0.4f); //pied gauche avant
    for(int i=0; i<4; i++)
    {
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, textures[SPHERE]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params,GL_TRUE);
            glPushMatrix();
                glTranslatef(-20.0f, -3.5f*x, -5.5f);
                gluSphere(params,0.8,20,20);
            glPopMatrix();

        glPopMatrix();
        x += 0.4;
    }
}

void Block::Chaise1()
{
    glPushMatrix();
        glPushMatrix();
            glTranslatef(10.5f, 0.0f,-5.5f);
            glScalef(2.0,0.3,2.0);
            glColor3f(1.5f,1.5f,1.40f);

            /** BACK **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(0.0f, y/TEXTURE_SCALE);
                glVertex3f(0.0f, y, 0.0f);
                glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
                glVertex3f(x, y, 0.0f);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, 0.0f, 0.0f);
            glEnd();

            /** RIGHT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(x, 0.0f, 0.0f);
                glTexCoord2f(0.0f, z/TEXTURE_SCALE);
                glVertex3f(x, 0.0f, z);
                glTexCoord2f(y/TEXTURE_SCALE, z/TEXTURE_SCALE);
                glVertex3f(x, y, z);
                glTexCoord2f(y/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, y, 0.0f);
            glEnd();

            /** TOP **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, y, 0.0f);
                glTexCoord2f(0.0f, y/TEXTURE_SCALE);
                glVertex3f(0.0f, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
                glVertex3f(x, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, y, 0.0f);
            glEnd();

            /** BOT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(0.0f, z/TEXTURE_SCALE);
                glVertex3f(0.0f, 0.0f, z);
                glTexCoord2f(x/TEXTURE_SCALE, z/TEXTURE_SCALE);
                glVertex3f(x, 0.0f, z);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, 0.0f, 0.0f);
            glEnd();

            /** FRONT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, z);
                glTexCoord2f(0.0f, y/TEXTURE_SCALE);
                glVertex3f(0.0f, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
                glVertex3f(x, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, 0.0f, z);
            glEnd();

            /** LEFT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(0.0f, z/TEXTURE_SCALE);
                glVertex3f(0.0f, 0.0f, z);
                glTexCoord2f(y/TEXTURE_SCALE, z/TEXTURE_SCALE);
                glVertex3f(0.0f, y, z);
                glTexCoord2f(y/TEXTURE_SCALE, 0.0f);
                glVertex3f(0.0f, y, 0.0f);
            glEnd();

            glPushMatrix();//pied devant gauche
                glTranslatef(0.2f, -6.0f, 1.84f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(14.0,0.15,12,12);
            glPopMatrix();

            glPushMatrix();//pied devant droit
                glTranslatef(1.8f, -1.0f, 1.84f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(25.0,0.15,12,12);
            glPopMatrix();

            glPushMatrix();//pied derriere gauche
                glTranslatef(0.2f, -6.0f, 0.15f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(14.0,0.15,12,12);
            glPopMatrix();

            glPushMatrix();//pied derriere droit
                glTranslatef(1.8f, -1.0f, 0.15f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(25.0,0.15,12,12);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(14.0f, 2.0f, -3.6f);
            glRotatef(54.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.85f, 0.50f, 0.39f);
            Cylindre(4.1,0.15,12,12);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(14.0f, 2.0f, -3.6f);
            glRotatef(-54.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.85f, 0.50f, 0.39f);
            Cylindre(4.1,0.15,12,12);
        glPopMatrix();
    glPopMatrix();
}

void Block::Chaise2()
{
    glPushMatrix();
        glPushMatrix();
            glTranslatef(10.5f, 0.0f,-5.5f);
            glScalef(2.0,0.3,2.0);
            glColor3f(1.5f,1.5f,1.40f);

            /** BACK **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(0.0f, y/TEXTURE_SCALE);
                glVertex3f(0.0f, y, 0.0f);
                glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
                glVertex3f(x, y, 0.0f);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, 0.0f, 0.0f);
            glEnd();

            /** RIGHT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(x, 0.0f, 0.0f);
                glTexCoord2f(0.0f, z/TEXTURE_SCALE);
                glVertex3f(x, 0.0f, z);
                glTexCoord2f(y/TEXTURE_SCALE, z/TEXTURE_SCALE);
                glVertex3f(x, y, z);
                glTexCoord2f(y/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, y, 0.0f);
            glEnd();

            /** TOP **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, y, 0.0f);
                glTexCoord2f(0.0f, y/TEXTURE_SCALE);
                glVertex3f(0.0f, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
                glVertex3f(x, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, y, 0.0f);
            glEnd();

            /** BOT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(0.0f, z/TEXTURE_SCALE);
                glVertex3f(0.0f, 0.0f, z);
                glTexCoord2f(x/TEXTURE_SCALE, z/TEXTURE_SCALE);
                glVertex3f(x, 0.0f, z);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, 0.0f, 0.0f);
            glEnd();

            /** FRONT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, z);
                glTexCoord2f(0.0f, y/TEXTURE_SCALE);
                glVertex3f(0.0f, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, y/TEXTURE_SCALE);
                glVertex3f(x, y, z);
                glTexCoord2f(x/TEXTURE_SCALE, 0.0f);
                glVertex3f(x, 0.0f, z);
            glEnd();

            /** LEFT **/

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(0.0f, z/TEXTURE_SCALE);
                glVertex3f(0.0f, 0.0f, z);
                glTexCoord2f(y/TEXTURE_SCALE, z/TEXTURE_SCALE);
                glVertex3f(0.0f, y, z);
                glTexCoord2f(y/TEXTURE_SCALE, 0.0f);
                glVertex3f(0.0f, y, 0.0f);
            glEnd();

            glPushMatrix();//pied devant gauche
                glTranslatef(0.2f, -6.0f, 1.84f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(14.0,0.15,12,12);
            glPopMatrix();

            glPushMatrix();//pied devant droit
                glTranslatef(1.8f, -1.0f, 1.84f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(25.0,0.15,12,12);
            glPopMatrix();

            glPushMatrix();//pied derriere gauche
                glTranslatef(0.2f, -6.0f, 0.15f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(14.0,0.15,12,12);
            glPopMatrix();

            glPushMatrix();//pied derriere droit
                glTranslatef(1.8f, -1.0f, 0.15f);
                glRotatef(95.0f, 0.0f, 1.0f, 0.0f);
                glColor3f(0.85f, 0.50f, 0.39f);
                Cylindre(25.0,0.15,12,12);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(14.0f, 2.0f, -3.6f);
            glRotatef(54.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.85f, 0.50f, 0.39f);
            Cylindre(4.1,0.15,12,12);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(14.0f, 2.0f, -3.6f);
            glRotatef(-54.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.85f, 0.50f, 0.39f);
            Cylindre(4.1,0.15,12,12);
        glPopMatrix();
    glPopMatrix();
}

void Block::GdeAiguille()
{
    glPushMatrix();
        glTranslatef(0.0f, -7.8f, 0.0f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glutSolidCone(1.0, 9.0, 20, 30);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0f, -7.8f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glutSolidCone(1.0, 2.5, 20, 30);
    glPopMatrix();
}

void Block::PttAiguille()
{
    glPushMatrix();
        glPushMatrix();
            glTranslatef(0.0f, 5.0f, 0.0f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.32f, 0.32f, 0.32f);
            glutSolidCone(1.0, 5.0, 20, 30);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0f, 5.0f, 0.0f);
            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.32f, 0.32f, 0.32f);
            glutSolidCone(1.0, 2.5, 20, 30);
        glPopMatrix();
    glPopMatrix();
}

void Block::Porte()
{
    glPushMatrix();
        glTranslatef(-13.0f, 0.0f, 0.0f);
        glScalef(6.0,0.3,7.5);
        glColor3f(0.709f, 0.792f, 0.552f);
        glutSolidCube(4);
    glPopMatrix();
}
void Block::ArmaturePorte()
{
    glPushMatrix();
        //glTranslatef(-30.0f, 6.0f, 80.0f);
        Cylindre(31.0,1.0,12,12);
    glPopMatrix();
}
void Block::Chapeau()
{
    glPushMatrix();
        glColor3f(0.32f, 0.32f, 0.32f);
        Cylindre(5.0,2.0,12,12);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0f, -1.9f, 0.0f);
        glColor3f(0.658824f, 0.658824f, 0.658824f);
        glRotatef(180,0.0,1.0,1.0);
        glutSolidTorus(0.3,2.3,30,30);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0f, -3.0f, 0.0f);
        glRotatef(180,0.0,1.0,1.0);
        glColor3f(0.32f, 0.32f, 0.32f);
        glutSolidCone(4.0,1.5,30,30);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(0.0f, 2.9f, 0.5f);
        glRotatef(180,0.0,1.0,1.0);
        glRotatef(angle2,1,0,0);
        glTranslatef(0.0f, 1.0f, 0.0f);

        glColor3f(1.32f, 0.32f, 0.32f);
        glutSolidCone(2.0,0.0,30,30);
    glPopMatrix();
}

void Block::Cylindre(double h,double r,int n,int m)
{






  glPushMatrix();
  glRotatef(90.0F,1.0F,0.0F,0.0F);
  glTranslatef(0.0F,0.0F,-h/2);
  GLUquadricObj *qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluCylinder(qobj,r,r,h,n,m);
  gluDeleteQuadric(qobj);
  glPopMatrix();
}

void Block::SolidCylinderSansNormales1(float r,float h,int n)
{
  int i;
  glPushMatrix();
  glBegin(GL_QUADS);
  for( i = 0 ; i < n ; i++ ){
    float ai=(2*M_PI*i)/n;
    float aj=(2*M_PI*(i+1))/n;
    float si=sin(ai);
    float sj=sin(aj);
    float ci=cos(ai);
    float cj=cos(aj);
    float xi=r*ci;
    float zi=r*si;
    float xj=r*cj;
    float zj=r*sj;
    glVertex3f(xi,h/2,zi);
    glVertex3f(xi,-h/2,zi);
    glVertex3f(xj,-h/2,zj);
    glVertex3f(xj,h/2,zj); }
  glEnd();
  glBegin(GL_POLYGON);
  for( i = 0 ; i < n ; i++ ){
    float ai=(2*M_PI*i)/n;
    float si=sin(ai);
    float ci=cos(ai);
    glVertex3f(r*ci,-h/2,r*si); }
  glEnd();
  glBegin(GL_POLYGON);
  for( i = 0 ; i < n ; i++ ){
    float ai=(2*M_PI*i)/n;
    float si=-sin(ai);
    float ci=cos(ai);
    glVertex3f(r*ci,h/2,r*si); }
  glEnd();
  glPopMatrix();
}

void update(int value)
{
    if(sens == 0){
        angle1 += 0.8;
        if(angle1 > 20){
          sens = 1;
        }
    }
    if(sens == 1){
        angle1 -= 0.8;
        if(angle1 < -20){
            sens = 0;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(20,update, 0);
}
void update2(int value)
{
    if(sens == 0){
        angle1 += 0.8;
        if(angle1 > 100){
          sens = 1;
        }
    }
    if(sens == 1){
        angle1 -= 0.8;
        if(angle1 < -100){
            sens = 0;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(20,update2,0);
}
void update3(int value)
{
    if(angle3 >= 360)
        angle3 = 0;

    angle3 += 3.0;
    glutPostRedisplay();
	glutTimerFunc(20,update3,0);
}
void update4(int value)
{
    if(angle4 >= 360)
        angle4 = 0;

    angle4 -= 3.0;
    glutPostRedisplay();
	glutTimerFunc(20,update4,0);
}
void update5(int value)
{
    if(angle5 >= 300)
        angle5 = 0;

    angle5 -= 0.3;
    glutPostRedisplay();
	glutTimerFunc(20,update5,0);
}
void update6(int value)
{
    if(sens == 0){
        angle2 += 0.8;
        if(angle2 > 60){
          sens = 1;
        }
    }
    if(sens == 1){
        angle2 -= 0.8;
        if(angle2 < -60){
            sens = 0;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(20,update6, 0);
}
