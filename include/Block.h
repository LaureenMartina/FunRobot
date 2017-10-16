#ifndef BLOCK_H
#define BLOCK_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "glut.h"
#include "SOIL.h"

#define ANCHOR_FROM_ORIGIN 0
#define ANCHOR_FROM_CENTER 1

#define FRONT 0
#define BACK 1
#define LEFT 2
#define RIGHT 3
#define TOP 4
#define BOT 5
#define ALL 6
#define SPHERE 7
#define TUILE 8

#define TEXTURE_SCALE 1.0f

class Block
{
    public:
        Block();
        Block(float x, float y, float z);
        void Draw();
        void SetTexture(int face, GLuint texture);
        void Tete();
        void Corps();
        void Cou();
        void Jambes();
        void Pieds();
        void Bras();
        void Cerceau();
        void Murs();
        void Tables();
        void Vase();
        void Fleurs();
        void GrandeTable();
        void PiedTable();
        void Chaise1();
        void Chaise2();
        void GdeAiguille();
        void PttAiguille();
        void Porte();
        void ArmaturePorte();
        void Chapeau();

        void Cylindre(double,double,int,int);

        /*float alphaA = 0.0, betaA = 0.0;
        float xa = 0.0, ya = 1.0, za = 0.0;
        float xb = 0.0, yb = 0.0, zb = 0.0;
        float R = 1.0;*/

        float r = 2.0;
        float h = 0.4;
        int n = 15;

        float r1 = 2.5;
        float h1 = 0.4;
        int n1 = 15;

        void SolidCylinderSansNormales1(float,float,int);

        float posx;
        float posy;
        float posz;

        float x;
        float y;
        float z;
    protected:

    private:
        GLuint textures[7];
        char anchor[3];
};

#endif // BLOCK_H
