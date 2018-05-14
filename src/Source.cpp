// STL
#include <iostream>

// GLEW
#include <GL/glew.h>
#include <GL/glut.h>
// GLFW
#include <GLFW/glfw3.h>

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// Other includes
#include "Window/Window.h"
#include "Compontents/Camera.h"
#include "Compontents/Shader.h"
#include "Compontents/Texture.h"
#include "Compontents/Model.h"
vector<int>vnum;
vector<int>hnum;
bool  die=false;
struct Point
{
    GLfloat Px,Py,Pz;bool enable;
    Point (){}

    Point (GLfloat Px1,GLfloat Py1,GLfloat Pz1) : Px(Px1),Py(Py1),Pz(Pz1)
    {}
};
int idx=0;
int idx1=0;
int idx2=0;
// Window dimensions and title
const GLuint WIDTH = 1500, HEIGHT = 1000;
const GLchar* TITLE = "Sonic Game";
GLfloat COLLECTY = 8.3f;
GLfloat deltaTime;			// Time between current frame and last frame
GLfloat lastFrame;  		// Time of last frame
GLfloat lastX = WIDTH / 2;
GLfloat lastY = HEIGHT / 2;
GLboolean firstMouse = true;
GLboolean keys[1024];
GLfloat SonicY = 7.1f;
GLfloat SonicX = 0.0f;
GLfloat SonicZ = -40.0f;
// Camera
GLfloat cameraX = SonicX, cameraY = 103.0f, cameraZ = SonicZ + 110;
Camera camera(glm::vec3(cameraX, cameraY, cameraZ));
GLfloat WaterX = -60.0f;
GLfloat WaterY = -4.0f;
GLfloat WaterZ = -6.0f;
GLint jump = -60;
bool allow = 0;
GLfloat deg = 0.0f;
GLfloat Rotate = glm::radians(90.0f);
int once = 0;
int Left = 15;
int times = 15;
int diffX1 = 19, diffX2 = 15, diffX3 = 14, diffX4 = 13, diffX1H = 15, diffX2H = 15+6, diffX3H = 14+6, diffX4H = 13+6, diffZ1 = 0, diffZ2 = 0, diffZ3 = 0, diffZ4 = 0, diffZ5 = 0, diffZ2H = 0, diffZ3H = 0, diffZ4H = 0, diffZ5H = 0;
Point Coinarr[200];
Point KApplearr[200];
Point EApplearr[200];

// Function prototypes
void fillarr();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movement();
vector <Model> LoadWaterModels();
vector <Model> LoadNumberModels();
GLuint loadCubemap();
void dropX(double p1,double p2,double p3,double p4,double p5,double p6);
void dropXZ(double p1,double p2,double p3,double p4);
void drop(double p1,double p2,double p3,double p4,double p5,double p6);
void Jump();
void CameraTransformations();
void SonicRotation();
void DrawCoin(GLfloat x,GLfloat y,GLfloat z ,GLfloat r1,GLfloat r2,GLfloat r3 ,GLfloat s1,GLfloat s2,GLfloat s3 ,Shader& shad,Model& mod,GLint& modelLoc);
bool doCameraMovement();

int main(int argc, char **argv) {
    int score=0;
    int health=1;
    Window gameWind(WIDTH, HEIGHT, TITLE);
    // gameWind.EnableMouse(false);
    gameWind.SetClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    // Set the required callback functions
    glfwSetKeyCallback(gameWind.mWind, key_callback);
    // glfwSetCursorPosCallback(gameWind.mWind, mouse_callback);
    glfwSetScrollCallback(gameWind.mWind, scroll_callback);
    // Build and compile our shader program
    Shader lightingShader("Shaders/lighting_vertex.shader", "Shaders/lighting_fragment.shader");
    Shader lampShader("Shaders/lamp_vertex.shader", "Shaders/lamp_fragment.shader");
    Shader skyboxShader("Shaders/skybox_vertex.shader", "Shaders/skybox_fragment.shader");
    // Load models
    Model Road("Models/Roads-new/Road-try.obj");
    Model Apple("Models/apple/apple.obj");
    Model KindApple("Models/KindApple/kind_apple.obj");
    Model Coin("Models/coin/Coin.obj");
    Model Sonic("Models/SonicSo/source/Sonic.obj");
    Model ScoreWord("Models/Alpha/Score.obj");
    Model HealthWord("Models/Alpha/Health.obj");
    Model WinWord("Models/Alpha/YouWon.obj");
    Model LoseWord("Models/Alpha/GameOver.obj");
//    Model WinWord("Models/Alpha/YouWon.obj");
//    Model ConWord("Models/Alpha/c.obj");

    vector <Model> numbers =  LoadNumberModels();
    vector <Model> water=LoadWaterModels();

    float moment=0.0f;
    ////////////// sky bos
    GLfloat skyboxVertices[] = {
            // Positions
            -1.0f,  1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            -1.0f,  1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            1.0f, -1.0f,  1.0f
    };

    //-------------------------- first we make the plane
    ///sky box texture
    GLuint skyboxVAO, skyboxVBO;
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glBindVertexArray(0);


    // Light attributes
    glm::vec3 lightPos(10.0f, 15.0f, 10.0f);
    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
    glm::vec3 diffuseColor = lightColor;		// Decrease the influence
    glm::vec3 ambientColor = diffuseColor * glm::vec3(0.3f);	// Low influence


    GLuint cubemapTexture = loadCubemap();
    fillarr();
    GLint cnt=0;
    GLint i=0;
    GLboolean direc=true;
    // Game loop
    int cmt = 1, nu = 1, meu = 1;
    float hlthcondition = 0;
    while (!gameWind.CloseRequested()) {//-1415, 0
        if(cmt > 0)
            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/Klaw.ogg&"), cmt--;
        // Clear buffers
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //create skybox first
        //------------------------------------------------------------------------------------------------------------
        glDepthMask(GL_FALSE);
        skyboxShader.Use();
        glm::mat4 view = glm::mat4(glm::mat3(camera.GetViewMatrix(glm::vec3(SonicX, SonicY, SonicZ))));	// Remove any translation component of the view matrix
        glm::mat4 projection = glm::perspective(camera.Zoom, (float)WIDTH/(float)HEIGHT, 0.1f, 100.0f);
        glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ProgramID, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ProgramID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glBindVertexArray(skyboxVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        glDepthMask(GL_TRUE);

        // Set frame time
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        gameWind.PollEvents();
        // Clear the color buffer

        lightPos.x = cos(currentFrame) * 1.5f;
        lightPos.z = sin(currentFrame) * 1.5f;

        glm::mat4 model;
        view = camera.GetViewMatrix(glm::vec3(SonicX, SonicY, SonicZ));
        projection = glm::perspective(camera.Zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);

        // Activate shader
        lightingShader.Use();

        // Get handle to our shaders' uniform
        GLint modelLoc = glGetUniformLocation(lightingShader.ProgramID, "model");
        GLint viewLoc = glGetUniformLocation(lightingShader.ProgramID, "view");
        GLint projectionLoc = glGetUniformLocation(lightingShader.ProgramID, "projection");
        GLint viewPosLoc = glGetUniformLocation(lightingShader.ProgramID, "viewPos");
        GLint lightPositionLoc = glGetUniformLocation(lightingShader.ProgramID, "light.position");
        GLint lightAmbientLoc = glGetUniformLocation(lightingShader.ProgramID, "light.ambient");
        GLint lightDiffuseLoc = glGetUniformLocation(lightingShader.ProgramID, "light.diffuse");
        GLint lightSpecularLoc = glGetUniformLocation(lightingShader.ProgramID, "light.specular");

        model = glm::translate(model, glm::vec3(0.0f, 7.0f, -12.0f));
        model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
        glUniform3f(lightPositionLoc, lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(lightAmbientLoc, ambientColor.x, ambientColor.y, ambientColor.z);
        glUniform3f(lightDiffuseLoc, diffuseColor.x, diffuseColor.y, diffuseColor.z);
        glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);

        Road.Draw(lightingShader);

        ///////////////////////////////////////water plan/////////////////////////////////////////////
        ///////////--------------------------x = -50 , y = -6, z = -25
        model = glm::translate(glm::mat4(), glm::vec3(WaterX, WaterY, WaterZ));

        model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        water[i].Draw(lightingShader);
        drop(33.8762,-900.0,23.2412 ,-26.0513,-312.002, -339.597);
        drop(-900.5,-1411.6,7.77742 ,-10.4655, -1080.78,-1105.66 );
        drop(-1463.61,-2002.5,-331.866 , -351.35 ,-1727.0,-1763.44 );
        drop(-2033.28,-2756.13,16.3045  ,-2.6  ,-2223.0,-2265.88);
        drop(-2033.28,-2756.13,16.3045 ,-2.6 ,-2479.83 , -2514.17 );
        dropX(-1421.28,-1463.61,-1421.7 ,-1440.82,-17.6408,-335.815);
        dropX(-2003.65 ,-2030.2,-2003.15 ,-2021.8,-5.0,-324.031);
        dropXZ(-2762.29 ,-3317.54,31.80 ,-18.40);
        dropXZ(-3317.62 ,-3707.79 ,0.9 ,-18.40 );

        //---------------------------------------------------------------------------------------------------

        cnt++;
        if (cnt>25) {
            if (direc) i++;
            else i--;
            if (i > 6) i--, direc = false;
            if (i < 0) i++, direc = true;
            cnt=0;
        }
        int num=score;
        int dig;
        vnum.clear();
        while (num != 0) {
            dig=num%10;
            vnum.push_back(dig);
            num/=10;
        }
        num=health;
        hnum.clear();
        while (num != 0) {
            dig=num%10;
            hnum.push_back(dig);
            num/=10;
        }
        bool allowDie = 0;
        if (die && !allowDie && SonicY > -15) SonicY-=0.14;
        if(meu <= 0) {
            if(meu == -100)
                system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/YouLose.ogg&");
            meu--;
        }
        if(SonicY < 0 && nu)
            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/Trtasha.ogg&"), nu--, meu--;
        if (SonicY<-5)allowDie = 1;
        //////////////////////////////////////////////////////////////////////////////////////
/*********************************Sonic Model**************************************************/
        model = glm::translate(glm::mat4(), glm::vec3(SonicX, SonicY, SonicZ));
        model = glm::rotate(model, Rotate, glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.2f, 1.2f, 1.2f));

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        Sonic.Draw(lightingShader);
////lose
        if(health<=0 || allowDie)
        {
            model = glm::translate(glm::mat4(), glm::vec3(SonicX - 5, SonicY + 25 + hlthcondition, SonicZ + 2));
            model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));

            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            LoseWord.Draw(lightingShader);
            if(health <= 0 && hlthcondition > -15) {
                nu--;
                if(nu == -50)
                    system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/YouLose.ogg&"), nu--;
                hlthcondition -= 0.25;
            }
            gameWind.SwapBuffers();
            continue;
        }
        if(!die)
        {
            if( SonicZ <= -3400.0f){
                if(!doCameraMovement()) {
                    gameWind.SwapBuffers();
                    continue;
                }
                else {
                    model = glm::translate(glm::mat4(), glm::vec3(cameraX - 20,SonicY + 10,cameraZ + 20));
                    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                    model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));

                    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                    WinWord.Draw(lightingShader);
                    if(nu)
                        system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/win3.ogg&"), nu--;
                    gameWind.SwapBuffers();
                    continue;
                }
            }
        }

        model = glm::translate(glm::mat4(), glm::vec3(SonicX - diffX1, 20, SonicZ + diffZ1));
        model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        ScoreWord.Draw(lightingShader);;

        //3 digits of Score


        int dig1,dig2,dig3;
        dig1=dig2=dig3=0;
        if(vnum.size()>=1)
        {
            dig1=vnum[0];
        }
        if(vnum.size()>=2)
        {
            dig2=vnum[1];
        }
        if(vnum.size()==3)
        {
            dig3=vnum[2];
        }
        model = glm::translate(glm::mat4(), glm::vec3(SonicX - diffX2, 20, SonicZ + diffZ3));
        model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        numbers[dig3].Draw(lightingShader);

        model = glm::translate(glm::mat4(), glm::vec3(SonicX - diffX3, 20, SonicZ + diffZ4));
        model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        numbers[dig2].Draw(lightingShader);

        model = glm::translate(glm::mat4(), glm::vec3(SonicX - diffX4, 20, SonicZ + diffZ5));
        model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        numbers[dig1].Draw(lightingShader);
/////////////////////////////////*****Health******//////////////////////////////////////////
        model = glm::translate(glm::mat4(), glm::vec3(SonicX + diffX1H, 20, SonicZ - diffZ2H));
        model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        HealthWord.Draw(lightingShader);

//////////////
        dig1=dig2=dig3=0;
        if(hnum.size()>=1)
        {
            dig1=hnum[0];
        }
        if(hnum.size()>=2)
        {
            dig2=hnum[1];
        }
        if(hnum.size()==3)
        {
            dig3=hnum[2];
        }
        //3 digits of Health
        model = glm::translate(glm::mat4(), glm::vec3(SonicX + diffX2H, 20, SonicZ - diffZ3H));
        model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        numbers[dig1].Draw(lightingShader);

        model = glm::translate(glm::mat4(), glm::vec3(SonicX + diffX3H, 20, SonicZ - diffZ4H));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        numbers[dig2].Draw(lightingShader);

        model = glm::translate(glm::mat4(), glm::vec3(SonicX + diffX4H, 20, SonicZ - diffZ5H));
        model = glm::rotate(model, Rotate - glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(.6f, .6f, .6f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        numbers[dig3].Draw(lightingShader);
        CameraTransformations();
        SonicRotation();
        Jump();
        /////////////////////////////////////////////////////////////////////////////////////
/*********************************evil & kind Apple Model**************************************************/
        for (int j=0;j<idx1;j++) {
            //cout<<i<<endl;
            if(j>=15&&j<=20) {

                if (KApplearr[j].Px + 3 >= SonicX && KApplearr[j].Px - 10 <= SonicX) {
                    if (KApplearr[j].Pz + 2 >= SonicZ && KApplearr[j].Pz - 2 <= SonicZ &&
                        (KApplearr[j].Py + 2 >= SonicY && KApplearr[j].Py - 6 <= SonicY)) {
                        if (KApplearr[j].enable == 0) {
                            KApplearr[j].enable = 1, ++health;
                            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/GoodApp.ogg&");
                        }
                    }

                }
            }
            else
            {
                if (KApplearr[j].Px + 2 >= SonicX && KApplearr[j].Px - 2 <= SonicX) {
                    if (KApplearr[j].Pz + 3 >= SonicZ && KApplearr[j].Pz - 10 <= SonicZ &&
                        (KApplearr[j].Py + 2 >= SonicY && KApplearr[j].Py - 6 <= SonicY)) {
                        if (KApplearr[j].enable == 0)
                        {
                            KApplearr[j].enable = 1,++health;
                            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/GoodApp.ogg&");
                        }
                    }

                }
            }
            if(KApplearr[j].enable==0)
                DrawCoin(KApplearr[j].Px, KApplearr[j].Py, KApplearr[j].Pz, 0.0f, 0.0f, 0.0f, 1.7f, 1.7f, 1.7f,
                         lightingShader, KindApple, modelLoc);
        }

        for (int j=0;j<idx2;j++) {
            //cout<<j<<endl;
            if (j == 15 || j== 17 || j== 16) {
                if (EApplearr[j].Px + 3>= SonicX && EApplearr[j].Px - 10<= SonicX) {
                    if (EApplearr[j].Pz + 2.5>= SonicZ && EApplearr[j].Pz - 2.5 <= SonicZ &&
                        (EApplearr[j].Py + 2 >= SonicY && EApplearr[j].Py - 6 <= SonicY)) {
                        if (EApplearr[j].enable == 0)
                        {
                            EApplearr[j].enable = 1, --health;
                            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/BadApp.ogg&");
                        }
                    }

                }
            } else {
                if (EApplearr[j].Px + 2.5 >= SonicX && EApplearr[j].Px - 2.5 <= SonicX) {
                    if (EApplearr[j].Pz + 3 >= SonicZ && EApplearr[j].Pz - 10 <= SonicZ &&
                        (EApplearr[j].Py + 2 >= SonicY && EApplearr[j].Py - 6 <= SonicY)) {
                        if (EApplearr[j].enable == 0)
                        {
                            EApplearr[j].enable = 1, --health;
                            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/BadApp.ogg&");
                        }
                    }

                }
            }
            if (EApplearr[j].enable == 0)
                DrawCoin(EApplearr[j].Px, EApplearr[j].Py, EApplearr[j].Pz, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 1.5f,
                         lightingShader, Apple, modelLoc);
        }


/*********************************Coin Model**************************************************/
        // In right & left sides

        for (int j=0;j<idx;j++) {
            if((i>=47&&i<=54)||(i>=84&&i<=88))
            { if (Coinarr[j].Px + 2>= SonicX && Coinarr[j].Px - 10 <= SonicX) {
                    if (Coinarr[j].Pz + 2 >= SonicZ && Coinarr[j].Pz - 2<= SonicZ &&
                        (Coinarr[j].Py + 2 >= SonicY && Coinarr[j].Py - 6 <= SonicY))
                        if (Coinarr[j].enable == 0) {
                            score++, Coinarr[j].enable = 1;
                            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/coins.ogg&");

                        }
                }
            }
            else {
                if (Coinarr[j].Px + 2.>= SonicX && Coinarr[j].Px - 2 <= SonicX) {
                    if (Coinarr[j].Pz + 3 >= SonicZ && Coinarr[j].Pz - 10 <= SonicZ &&
                        (Coinarr[j].Py + 2 >= SonicY && Coinarr[j].Py - 6 <= SonicY))
                        if (Coinarr[j].enable == 0){score++, Coinarr[j].enable = 1;
                            system("canberra-gtk-play -f /home/riham/ClionProjects/Sonic/Sonic/Sounds/coins.ogg&");
                        }

                }
            }

            if(Coinarr[j].enable==0)
                DrawCoin(Coinarr[j].Px, Coinarr[j].Py, Coinarr[j].Pz, 0.0f, 1.0f, 0.0f, 0.4f, 0.4f, 0.4f, lightingShader,
                         Coin, modelLoc);


        }


        deg+=0.02;
        if(fabs(deg - 360) < 0.01) deg = 0;
        if(fabs(Rotate - 360) < 0.01) Rotate = 0;
        // --------------------------------------------
        // Swap the screen buffers
        gameWind.SwapBuffers();
    }


    return 0;
}

void do_movement() {
    if (die) return ;
    // Camera controls
    if (1) {
        if(Left == 0) {
            SonicX -= 60 * deltaTime, WaterX -= 60*deltaTime;
        } else if(Left == 30) {
            SonicX += 60 * deltaTime, WaterX += 60*deltaTime;
        } else{
            SonicZ -= 60 * deltaTime, WaterZ -= 60 * deltaTime;
        }
    }
    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT]) {
        if(Left == 0) {
            SonicZ += 30 * deltaTime, WaterZ += 30*deltaTime;
        } else if(Left == 30) {
            SonicZ -= 30 * deltaTime, WaterZ -= 30*deltaTime;
        } else{
            SonicX -= 20 * deltaTime, WaterX -= 20*deltaTime;
        }
    }
    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) {
        if(Left == 0) {
            SonicZ -= 30 * deltaTime, WaterZ -= 30*deltaTime;
        } else if(Left == 30) {
            SonicZ += 30 * deltaTime, WaterZ += 30*deltaTime;
        } else{
            SonicX += 20 * deltaTime, WaterX += 20*deltaTime;
        }
    }
    if (keys[GLFW_KEY_SPACE] && SonicY == 7.1f) {
        jump = 29;
        allow = 1;
    }
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (action == GLFW_PRESS)
        keys[key] = true;
    else if (action == GLFW_RELEASE)
        keys[key] = false;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset, deltaTime);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(yoffset);
}
vector <Model> LoadWaterModels() {

    vector <Model> water;
    water.push_back("Models/Water/wat1.obj");
    water.push_back("Models/Water/wat2.obj");
    water.push_back("Models/Water/wat3.obj");
    water.push_back("Models/Water/wat4.obj");
    water.push_back("Models/Water/wat5.obj");
    water.push_back("Models/Water/wat6.obj");
    water.push_back("Models/Water/wat7.obj");
    return water;
}

vector <Model> LoadNumberModels() {
    vector <Model> numbers;
    string path;
    for(int i=0;i<10;i++) {
        char tmp = i+'0';
        path = "Models/Alpha/_", path += tmp, path += ".obj";
        numbers.push_back(path.c_str());
    }
    return numbers;
}

GLuint loadCubemap() {
    vector<const GLchar*> faces;
    faces.push_back("Models/skybox/skybox2/right.png");
    faces.push_back("Models/skybox/skybox2/left.png");
    faces.push_back("Models/skybox/skybox2/top.png");
    faces.push_back("Models/skybox/skybox2/bottom.png");
    faces.push_back("Models/skybox/skybox2/back.png");
    faces.push_back("Models/skybox/skybox2/front.png");
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width,height;
    unsigned char* image;

    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    for(GLuint i = 0; i < faces.size(); i++)
    {
        image = SOIL_load_image(faces[i], &width, &height, 0, SOIL_LOAD_RGB);
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        SOIL_free_image_data(image);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

    return textureID;
}
void Jump() {
    if (die) return ;
    //Jumping ---
    if(allow && jump > 0) {
        SonicY += 0.35;
        jump--;
    } else if(allow && jump >= -29) {
        SonicY -= 0.35;
        jump--;
    } else {allow = 0; SonicY=7.1f;}
}
void DrawCoin(GLfloat x,GLfloat y,GLfloat z ,GLfloat r1,GLfloat r2,GLfloat r3 ,GLfloat s1,GLfloat s2,GLfloat s3 ,Shader& shad,Model& mod,GLint& modelLoc)
{
    glm::mat4 model = glm::translate(glm::mat4(), glm::vec3(x,y,z));
    if (r1 || r2 || r3)
        model = glm::rotate(model, deg, glm::vec3(r1, r2, r3));
    model = glm::scale(model, glm::vec3(s1, s2, s3));

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    mod.Draw(shad);
}

void fillarr()
{
    for (int i=0;i<4;i++) {
        Coinarr[idx++]=Point(8,COLLECTY,-130-4*i);
        Coinarr[idx++]=Point(-8,COLLECTY,-130-4*i);
    }


    for (int i=0;i<4;i++)
        Coinarr[idx++]=Point(0,17,-305-4*i);
    for (int i=0;i<4;i++)
        Coinarr[idx++]=Point(0,17,-400-4*i);
    for (int i=0;i<6;i++)
        Coinarr[idx++]=Point(-5+2*i,COLLECTY,-525-4*i);
    for (int i=0;i<6;i++)
        Coinarr[idx++]=Point(5-2*i,COLLECTY,-545-4*i);
    for (int i=0;i<5;i++)
        Coinarr[idx++]=Point(0,11+2*i,-1065-5*i);
    for (int i=0;i<5;i++)
        Coinarr[idx++]=Point(0.4*i,19-2*i,-1081-5*i);

    for (int i=0;i<8;i++)
        Coinarr[idx++]=Point(-338,COLLECTY,-1550-4*i);
    for (int i=0;i<8;i++)
        Coinarr[idx++]=Point(-255+4*i,COLLECTY,-2009);

    for (int i=0;i<4;i++) {
        Coinarr[idx++] = Point(3, COLLECTY, -1200 - 4 * i);
        Coinarr[idx++] = Point(-4, COLLECTY, -1200 - 4 * i);

    }
    for (int i=0;i<4;i++) {
        Coinarr[idx++] = Point(11, COLLECTY, -2090-4*i);
        Coinarr[idx++] = Point(3, COLLECTY, -2090-4*i);

    }
    for (int i=0;i<4;i++) {
        Coinarr[idx++] = Point(3, COLLECTY, -1300 - 4 * i);
        Coinarr[idx++] = Point(-4, COLLECTY, -1300 - 4 * i);

    }
    for (int i=0;i<5;i++)
        Coinarr[idx++]=Point(-340,11+2*i,-1720-5*i);
    for (int i=0;i<5;i++)
        Coinarr[idx++]=Point(-192-4*i,COLLECTY,-1436);
    for (int i=0;i<5;i++)
        Coinarr[idx++]=Point(-340-0.4*i,19-2*i,-1740-5*i);

    for (int i=0;i<6;i++) {
        EApplearr[idx2++] = Point(6, COLLECTY, -2980 - 20 * i);
        KApplearr[idx1++]=Point(6,17,-2980-20*i);
    }

    for (int i=0;i<5;i++)
        Coinarr[idx++]=Point(1,19-2*i,-2980-20*i);
    for (int i=0;i<5;i++)
        Coinarr[idx++]=Point(11,19-2*i,-2980-20*i);


    for (int i=0;i<3;i++) {
        EApplearr[idx2++] = Point(4, COLLECTY, -100-400*i);
        EApplearr[idx2++] = Point(-4, COLLECTY, -100-400*i);
        KApplearr[idx1++]=Point(0,COLLECTY,-100-400*i);

    }
    for (int i=0;i<3;i++) {
        KApplearr[idx1++] = Point(4, COLLECTY, -200-400*i);
        KApplearr[idx1++] = Point(-4, COLLECTY, -200-400*i);
        EApplearr[idx2++]=Point(0,COLLECTY,-200-400*i);

    }
    for (int i=0;i<3;i++) {
        KApplearr[idx1++] = Point(-80-90*i, COLLECTY, -1436);
        KApplearr[idx1++] = Point(-80-90*i, COLLECTY, -1428);
        EApplearr[idx2++]=Point(-80-90*i,COLLECTY,-1432);

    }

    for (int i=0;i<4;i++) {
        KApplearr[idx1++] = Point(4, COLLECTY,-2200-200*i);
        EApplearr[idx2++]=Point(7,COLLECTY,-2200-200*i);
        KApplearr[idx1++]=Point(10,COLLECTY,-2200-200*i);

    }

}
void CameraTransformations() {
    if(once == -1) {
        do_movement();
    }
    // Create transformations
    if(!once && cameraY > 23) {
        cameraY--;
        cameraZ--;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
        if(cameraY == 23)
            once = 1;
    }
    if(once == 1) {
        do_movement();
        diffX1 = 19;
        diffX2 = 15;
        diffX3 = 13;
        diffX4 = 11;

        diffX1H = 13;
        diffX2H = 17 + 4;
        diffX3H = 15 + 4;
        diffX4H = 13 + 4;

        diffZ1 = 0;
        diffZ2 = 0;
        diffZ3 = 0;
        diffZ4 = 0;
        diffZ5 = 0;

        diffZ2H = 0;
        diffZ3H = 0;
        diffZ4H = 0;
        diffZ5H = 0;
        cameraX = SonicX;
        cameraZ = SonicZ + 30;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
    } else if(once == 2) {
        do_movement();
        diffZ1 = 15;
        diffZ2 = 19;
        diffZ3 = 11;
        diffZ4 = 9;
        diffZ5 = 7;

        diffZ2H = 7;
        diffZ3H = 11+3;
        diffZ4H = 9+3;
        diffZ5H = 7+3;

        diffX1 = 0;
        diffX2 = 0;
        diffX3 = 0;
        diffX4 = 0;

        diffX1H = 0;
        diffX2H = 0;
        diffX3H = 0;
        diffX4H = 0;

        cameraZ = SonicZ;
        cameraX = SonicX + 30;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
    } else if(once == 3) {
        do_movement();
        diffZ1 = -15;
        diffZ2 = -19;
        diffZ3 = -11;
        diffZ4 = -9;
        diffZ5 = -7;

        diffZ2H = -8;
        diffZ3H = -(11+5);
        diffZ4H = -(9+5);
        diffZ5H = -(7+5);

        diffX1 = 0;
        diffX2 = 0;
        diffX3 = 0;
        diffX4 = 0;

        diffX1H = 0;
        diffX2H = 0;
        diffX3H = 0;
        diffX4H = 0;

        cameraZ = SonicZ;
        cameraX = SonicX - 30;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
    }
}


bool doCameraMovement() {
    if(cameraZ > SonicZ - 40) {
        cameraZ-=0.25;
        cameraX+=0.25;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
        return false;
    }
    return true;
}

void SonicRotation() {
    if( SonicZ <= -1406 && SonicX > -20 && SonicX < 15 && times >= 0 && times <= 15 ) {
        once = -1;//keep changes
        Rotate += 0.1;
        cameraZ -= 1.4;
        cameraX += 1.4;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
        times--;
        SonicX -= 0.15;
        SonicZ += 0.58;
    }
    if(times < 0 && Left) {
        once = 2;
        Left--;
        SonicX-=0.3;
    }
    if( SonicX <= -325 && SonicZ >= -1480 && SonicZ <= -1400 && times <= 15) {
        Rotate -= 0.1;
        times++;
        SonicZ -= 0.25;
        SonicX += 0.2;
        once = -1;
        cameraZ += 1.4;
        cameraX -= 1.4;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
    }
    if(times > 15 && Left < 15) {
        once = 1;
        Left++;
        SonicZ -= 0.3;
    }
    if( SonicZ <= -1978 && SonicX <= -310 && SonicX >= -370 && times <= 30) {
        Rotate -= 0.095;
        times++;
        SonicX -= 0.1;
        SonicZ += 0.15;
        once = -1;
        cameraZ -= 1.4;
        cameraX -= 1.4;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
    }
    if(times > 30 && Left < 30) {
        once = 3;
        Left++;
        SonicX += 0.3;
    }
    if( SonicX >= -5 && SonicZ <= -1985 && times > 30 && times <= 46) {
        Rotate += 0.1;
        times++;
        SonicZ -= 0.3;
        SonicX -= 0.45;
        once = -1;
        cameraZ += 1.4;
        cameraX += 1.4;
        camera.setPosition(glm::vec3(cameraX, cameraY, cameraZ));
    }
    if(times > 46 && Left < 45) {
        once = 1;
        Left++;
        SonicZ -= 0.2;
    }
}
void drop(double p1,double p2,double p3,double p4,double p5,double p6)
{
    if (SonicZ <=p1  && SonicZ >=p2 ) {
        if (SonicX >p3 || SonicX < p4 || (SonicZ <=p5  && SonicZ >=p6 && SonicY <= COLLECTY))
            die=true;
    }
}
void dropX(double p1,double p2,double p3,double p4,double p5,double p6)
{
    if (SonicZ <=p1  && SonicZ >=p2 && SonicX<=p5 && SonicX>=p6 ) {
        if (SonicZ >p3 || SonicZ <p4  )
            die=true;
    }
}
void dropXZ(double p1,double p2,double p3,double p4)
{
    if (SonicZ <=p1  && SonicZ >=p2 ) {
        if (SonicX >p3 || SonicX <p4  )
            die=true;
    }
}