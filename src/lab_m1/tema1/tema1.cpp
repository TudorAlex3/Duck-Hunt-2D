#include "lab_m1/tema1/tema1.h"

#include <vector>
#include <iostream>
#include <string.h>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


tema1::tema1()
{
}


tema1::~tema1()
{
}


void tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    // Grass
    glm::vec3 grassCorner = glm::vec3(0, 0, 0);

    // Duck
    duck_x = 10 + (float)(rand() % 1100);
    duck_y = 0 + (float)(rand() % 100);
    
    if (1 + (float)(rand() % 100) <= 50)
        right_direction = 2;
    else
        right_direction = 1;
    move = 0;

    // Head
    head_x = 0;
    head_y = 0;
    head_radius = 25;
    glm::vec3 headCenter = glm::vec3(head_x, head_y, 0);

    // Beak
    beak_base = 30;
    beak_height = 20;
    beak_x = 0;
    beak_y = 0;
    body_rotate_angle = 0 ;
    glm::vec3 beakCorner = glm::vec3(beak_x, beak_y, 0);

    // Body
    body_base = 50;
    body_height = 80;
    body_x = 0;
    body_y = 0;
    glm::vec3 bodyCorner = glm::vec3(body_x, body_y, 0);

    // Left wing
    left_wing_x = 0;
    left_wing_y = 0;
    left_wing_length = 40;
    glm::vec3 leftWingCorner = glm::vec3(left_wing_x, left_wing_y, 0);

    // Right wing
    right_wing_x = 0;
    right_wing_y = 0;
    right_wing_length = 40;
    glm::vec3 rightWingCorner = glm::vec3(right_wing_x, right_wing_y, 0);

    // Left leg
    leg1_x = 0;
    leg1_y = 0;
    leg1_length = 15;
    glm::vec3 leftLegCorner = glm::vec3(leg1_x, leg1_y, 0);

    // Right leg
    leg2_x = 0;
    leg2_y = 0;
    leg2_length = 15;
    glm::vec3 rightLegCorner = glm::vec3(leg2_x, leg2_y, 0);

    // One rectangle for each positioning of the duck.
    duck_rec_x = 0;
    duck_rec_y = 0; 
    duck_rec_length = 2.6 * right_wing_length / 2 + body_base;
    duck_rec_height = 3 * beak_height / 2 + head_radius + body_height;
    duck1_rec_length = 90;
    duck1_rec_height = 110;
    duck2_rec_length = 110;
    duck2_rec_height = 90;
    duck3_rec_length = 110;
    duck3_rec_height = 108;
    duck4_rec_length = 120;
    duck4_rec_height = 100;
    rec_type = 0;
    glm::vec3 duckRecCorner = glm::vec3(duck_rec_x, duck_rec_y, 0);

    // Fulll score bar
    score1_x = 0;
    score1_y = 0;
    score1_length = 200;
    score1_height = 20;
    glm::vec3 score1Corner = glm::vec3(score1_x, score1_y, 0);

    // Real score bar
    score2_x = 0;
    score2_y = 0;
    score2_length = 1;
    score2_height = 20;
    scoreScale = 0;
    glm::vec3 score2Corner = glm::vec3(score2_x, score2_y, 0);

    // Life
    life_number = 3;
    life_total = 3;
    life_x = 0;
    life_y = 0;
    life_radius = 10;
    glm::vec3 lifeCenter = glm::vec3(life_x, life_y, 0);

    // Bullet
    bullet_number = 3;
    bullet_total = 3;
    bullet_x = 0;
    bullet_y = 0;
    bullet_length = 10;
    bullet_height = 20;
    glm::vec3 bulletCorner = glm::vec3(bullet_x, bullet_y, 0);

    // Wings move
    wingsMove = 0.1;
    resetWingsMove = true;

    // Window limits
    up_limit = 720;
    right_limit = 1280;
    down_limit = 150;
    left_limit = 0;

    // Final face
    end = false;
    face_x = 640; 
    face_y = 360;
    face_radius = 300;
    glm::vec3 faceCenter = glm::vec3(face_x, face_y, 0);
    eye_x = 640;
    eye_y = 360;
    eye_radius = 50;
    iris_x = 640;
    iris_y = 360;
    iris_radius = 20;
    mouth_x = 640;
    mouth_y = 360;
    mouth_length = 300;
    mouth_height = 20;
    glm::vec3 mouthCorner = glm::vec3(mouth_x, mouth_y, 0);
    tears_x = 640;
    tears_y = 360;
    tears_radius = 10;
    glm::vec3 tearsCenter = glm::vec3(tears_x, tears_y, 0);
    nose_x = 640;
    nose_y = 360;
    nose_length = 50;
    glm::vec3 noseCorner = glm::vec3(nose_x, nose_y, 0);

    // Other variables
    left_limit = 0;
    ul_x_limit = 0;
    ul_y_limit = 0;
    dr_x_limit = 0;
    dr_y_limit = 0;
    up = false;
    left = false;
    right = false;
    down = false;
    x_increment = true;
    y_increment = true;
    body_rotate = false;
    shot = false;
    begin = true;
    escape = false;
    scale_time = false;
    speed = 1;
    speed_flag = 0;
    duck_counter = 0;
    new_score = false;
    col_counter = 0;
    seconds = 0;
    killingSpree = 0;
    killingScale = 0;
    killingScaleUp = false;

    head_color = 0;
    beak_color = 0;
    body_color = 0;
    lw_color = 0;
    rw_color = 0;
    ll_color = 0; 
    rl_color = 0;
    ColorChange();

    Mesh* grass = object2D::CreateRectangle("grass", grassCorner, 1280, 150, glm::vec3(0, 1, 0), true);
    AddMeshToList(grass);

    // Red head can spawn a new life
    // Yellow head can spawn a new bullet
    Mesh* head = object2D::CreateCircle("head", headCenter, head_radius, glm::vec3(1, 0, 0), true);
    AddMeshToList(head);
    Mesh* head_1 = object2D::CreateCircle("head_1", headCenter, head_radius, glm::vec3(0, 1, 0.5f), true);
    AddMeshToList(head_1);
    Mesh* head1 = object2D::CreateCircle("head1", headCenter, head_radius, glm::vec3(1, 0.2f, 0.8f), true);
    AddMeshToList(head1);
    Mesh* head2 = object2D::CreateCircle("head2", headCenter, head_radius, glm::vec3(0, 0.7f, 0.7f), true);
    AddMeshToList(head2);
    Mesh* head3 = object2D::CreateCircle("head3", headCenter, head_radius, glm::vec3(0.8f, 1, 0.6f), true);
    AddMeshToList(head3);
    Mesh* head4 = object2D::CreateCircle("head4", headCenter, head_radius, glm::vec3(0.8f, 0.6f, 0), true);
    AddMeshToList(head4);
    Mesh* head5 = object2D::CreateCircle("head5", headCenter, head_radius, glm::vec3(0.4f, 0.4f, 0.6f), true);
    AddMeshToList(head5);

    Mesh* beak = object2D::CreateIsoscelesTriangle("beak", beakCorner, beak_base, beak_height, glm::vec3(0.8f, 1, 0.6f), true);
    AddMeshToList(beak);
    Mesh* beak1 = object2D::CreateIsoscelesTriangle("beak1", beakCorner, beak_base, beak_height, glm::vec3(0.2f, 0.6f, 1), true);
    AddMeshToList(beak1);
    Mesh* beak2 = object2D::CreateIsoscelesTriangle("beak2", beakCorner, beak_base, beak_height, glm::vec3(1, 0.8f, 0.4f), true);
    AddMeshToList(beak2);
    Mesh* beak3 = object2D::CreateIsoscelesTriangle("beak3", beakCorner, beak_base, beak_height, glm::vec3(0.6f, 0, 0.8f), true);
    AddMeshToList(beak3);
    Mesh* beak4 = object2D::CreateIsoscelesTriangle("beak4", beakCorner, beak_base, beak_height, glm::vec3(0.8f, 0, 0.4f), true);
    AddMeshToList(beak4);


    Mesh* body = object2D::CreateIsoscelesTriangle("body", bodyCorner, body_base, body_height, glm::vec3(0.6f, 1, 0.2f), true);
    AddMeshToList(body);
    Mesh* body1 = object2D::CreateIsoscelesTriangle("body1", bodyCorner, body_base, body_height, glm::vec3(0.2f, 0.2f, 0.8f), true);
    AddMeshToList(body1);
    Mesh* body2 = object2D::CreateIsoscelesTriangle("body2", bodyCorner, body_base, body_height, glm::vec3(1, 1, 0.6f), true);
    AddMeshToList(body2);
    Mesh* body3 = object2D::CreateIsoscelesTriangle("body3", bodyCorner, body_base, body_height, glm::vec3(0.8f, 0.4f, 0.6f), true);
    AddMeshToList(body3);
    Mesh* body4 = object2D::CreateIsoscelesTriangle("body4", bodyCorner, body_base, body_height, glm::vec3(0.4f, 0, 0.8f), true);
    AddMeshToList(body4);

    Mesh* leftWing = object2D::CreateEquilateralTriangle("leftWing", leftWingCorner, left_wing_length, glm::vec3(1, 0.8f, 0.6f), true);
    AddMeshToList(leftWing);
    Mesh* leftWing1 = object2D::CreateEquilateralTriangle("leftWing1", leftWingCorner, left_wing_length, glm::vec3(1, 0.8f, 0.4f), true);
    AddMeshToList(leftWing1);
    Mesh* leftWing2 = object2D::CreateEquilateralTriangle("leftWing2", leftWingCorner, left_wing_length, glm::vec3(1, 0.6f, 0.6f), true);
    AddMeshToList(leftWing2);
    Mesh* leftWing3 = object2D::CreateEquilateralTriangle("leftWing3", leftWingCorner, left_wing_length, glm::vec3(0.6f, 0, 1), true);
    AddMeshToList(leftWing3);
    Mesh* leftWing4 = object2D::CreateEquilateralTriangle("leftWing4", leftWingCorner, left_wing_length, glm::vec3(0, 1, 0.8f), true);
    AddMeshToList(leftWing4);

    Mesh* rightWing = object2D::CreateEquilateralTriangle("rightWing", rightWingCorner, right_wing_length, glm::vec3(1, 0.8f, 0.6f), true);
    AddMeshToList(rightWing);
    Mesh* rightWing1 = object2D::CreateEquilateralTriangle("rightWing1", leftWingCorner, right_wing_length, glm::vec3(1, 0.8f, 0.4f), true);
    AddMeshToList(rightWing1);
    Mesh* rightWing2 = object2D::CreateEquilateralTriangle("rightWing2", leftWingCorner, right_wing_length, glm::vec3(1, 0.6f, 0.6f), true);
    AddMeshToList(rightWing2);
    Mesh* rightWing3 = object2D::CreateEquilateralTriangle("rightWing3", leftWingCorner, right_wing_length, glm::vec3(0.6f, 0, 1), true);
    AddMeshToList(rightWing3);
    Mesh* rightWing4 = object2D::CreateEquilateralTriangle("rightWing4", leftWingCorner, right_wing_length, glm::vec3(0, 1, 0.8f), true);
    AddMeshToList(rightWing4);

    Mesh* leftLeg = object2D::CreateEquilateralTriangle("leftLeg", leftLegCorner, leg1_length, glm::vec3(1, 0.8f, 0.6f), true);
    AddMeshToList(leftLeg);
    Mesh* leftLeg1 = object2D::CreateEquilateralTriangle("leftLeg1", leftLegCorner, leg1_length, glm::vec3(1, 0.8f, 0.4f), true);
    AddMeshToList(leftLeg1);
    Mesh* leftLeg2 = object2D::CreateEquilateralTriangle("leftLeg2", leftLegCorner, leg1_length, glm::vec3(1, 0.6f, 0.6f), true);
    AddMeshToList(leftLeg2);
    Mesh* leftLeg3 = object2D::CreateEquilateralTriangle("leftLeg3", leftLegCorner, leg1_length, glm::vec3(0.6f, 0, 1), true);
    AddMeshToList(leftLeg3);
    Mesh* leftLeg4 = object2D::CreateEquilateralTriangle("leftLeg4", leftLegCorner, leg1_length, glm::vec3(0, 1, 0.8f), true);
    AddMeshToList(leftLeg4);

    Mesh* rightLeg = object2D::CreateEquilateralTriangle("rightLeg", rightLegCorner, leg1_length, glm::vec3(1, 0.8f, 0.6f), true);
    AddMeshToList(rightLeg);
    Mesh* rightLeg1 = object2D::CreateEquilateralTriangle("rightLeg1", rightLegCorner, leg1_length, glm::vec3(1, 0.8f, 0.4f), true);
    AddMeshToList(rightLeg1);
    Mesh* rightLeg2 = object2D::CreateEquilateralTriangle("rightLeg2", rightLegCorner, leg1_length, glm::vec3(1, 0.6f, 0.6f), true);
    AddMeshToList(rightLeg2);
    Mesh* rightLeg3 = object2D::CreateEquilateralTriangle("rightLeg3", rightLegCorner, leg1_length, glm::vec3(0.6f, 0, 1), true);
    AddMeshToList(rightLeg3);
    Mesh* rightLeg4 = object2D::CreateEquilateralTriangle("rightLeg4", rightLegCorner, leg1_length, glm::vec3(0, 1, 0.8f), true);
    AddMeshToList(rightLeg4);

    Mesh* duckRec = object2D::CreateRectangle("duckRec", duckRecCorner, duck_rec_length, duck_rec_height, glm::vec4(0, 0.8, 1, 1), false);
    AddMeshToList(duckRec);
    Mesh* duckRec1 = object2D::CreateRectangle("duckRec1", duckRecCorner, duck1_rec_length, duck1_rec_height, glm::vec4(0, 0.8, 1, 1), false);
    AddMeshToList(duckRec1);
    Mesh* duckRec2 = object2D::CreateRectangle("duckRec2", duckRecCorner, duck2_rec_length, duck2_rec_height, glm::vec4(0, 0.8, 1, 1), false);
    AddMeshToList(duckRec2);
    Mesh* duckRec3 = object2D::CreateRectangle("duckRec3", duckRecCorner, duck3_rec_length, duck3_rec_height, glm::vec4(0, 0.8, 1, 1), false);
    AddMeshToList(duckRec3);
    Mesh* duckRec4 = object2D::CreateRectangle("duckRec4", duckRecCorner, duck4_rec_length, duck4_rec_height, glm::vec4(0, 0.8, 1, 1), false);
    AddMeshToList(duckRec4);

    Mesh* fullScore = object2D::CreateRectangle("fullScore", score1Corner, score1_length, score1_height, glm::vec3(1, 1, 1), false);
    AddMeshToList(fullScore);

    Mesh* realScore = object2D::CreateRectangle("realScore", score2Corner, score2_length, score2_height, glm::vec3(0, 0, 1), true);
    AddMeshToList(realScore);

    Mesh* life = object2D::CreateCircle("life", lifeCenter, life_radius, glm::vec3(1, 0, 0), true);
    AddMeshToList(life);

    Mesh* bullet = object2D::CreateRectangle("bullet", bulletCorner, bullet_length, bullet_height, glm::vec3(0, 1, 0.5f), true);
    AddMeshToList(bullet);

    Mesh* killing = object2D::CreateRectangle("killing", grassCorner, 30, 30, glm::vec3(0.5f, 1, 0.5f), true);
    AddMeshToList(killing);

    Mesh* face = object2D::CreateCircle("face", faceCenter, face_radius, glm::vec3(1, 0, 0), true);
    AddMeshToList(face);
    Mesh* eye = object2D::CreateCircle("eye", faceCenter, eye_radius, glm::vec3(0, 0, 0), true);
    AddMeshToList(eye);
    Mesh* iris = object2D::CreateCircle("iris", faceCenter, iris_radius, glm::vec3(1, 1, 1), true);
    AddMeshToList(iris);
    Mesh* tears = object2D::CreateCircle("tears", tearsCenter, tears_radius, glm::vec3(0, 0, 1), true);
    AddMeshToList(tears);
    Mesh* mouth = object2D::CreateRectangle("mouth", mouthCorner, mouth_length, mouth_height, glm::vec3(0, 0, 0), true);
    AddMeshToList(mouth);
    Mesh* nose = object2D::CreateEquilateralTriangle("nose", noseCorner, nose_length, glm::vec3(1, 1, 1), true);
    AddMeshToList(nose);
}


void tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0.8, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();

    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void tema1::Update(float deltaTimeSeconds)
{   
    // A duck is in the starting area until it completely enters the frame.
    if (begin) {
        move = speed;

        if (right_direction == 1) {
            duck_x += move;
            x_increment = true;
        }
        if (right_direction == 2) {
            duck_x += move;
            x_increment = false;
        }
        y_increment = true;

        duck_y += move;

        if (dr_y_limit >= 50) {
            begin = false;
        }

    } else {
        //If the duck is shot or escapes
        if (shot || escape) {
            if (duck_y >= 50 && shot) {
                move += 0.1 * deltaTimeSeconds;
                if (move > 1)
                    move -= 0.1 * deltaTimeSeconds;

                duck_y -= move;
            }
            else if (duck_y <= 800 && escape) {
                move += 0.1 * deltaTimeSeconds;
                if (move > 1)
                    move -= 0.1 * deltaTimeSeconds;
                duck_y += move;
            }
            else {
                // Another duck spawns
                shot = false; begin = true; escape = false;
                move = 0;

                if (life_number == 0)
                    end = true;

                // Random for new position
                duck_x = 100 + (float)(rand() % 900);
                duck_y = 20 + (float)(rand() % 100);
                if (1 + (float)(rand() % 100) <= 50)
                    right_direction = 2;
                else
                    right_direction = 1;

                // Random for new colors;
                ColorChange();
            }
        }
        else {
            move = speed;
            seconds += deltaTimeSeconds;
            // Check if the duck has entered the frame completely.
            if (body_rotate) {
                if (ul_y_limit < up_limit && ul_y_limit > down_limit
                    && dr_y_limit < up_limit && dr_y_limit > down_limit
                    && ul_x_limit > left_limit && ul_x_limit < right_limit
                    && dr_x_limit > left_limit && dr_x_limit < right_limit) {
                    body_rotate = false;
                }
            }
            // Check if the duck hits the edges of the screen.
            CheckCollision();
        }

    }
    
    // If the duck has hit 20 of the edges of the screen or 20 seconds have passed since spawning.
    if (col_counter == 20 || seconds >= 20) {
        escape = true;
        killingSpree = 0;
        col_counter = 0;

        life_number -= 1;
        if (life_number == 0) {
            escape = true;
        }

        seconds = 0;
    }

    // Render all objects if is not the end.
    if (!end) {
        DuckTranslate();
        Render(deltaTimeSeconds);
    }
    else
        RenderEnd(deltaTimeSeconds);
}

void tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */

// Check if the duck has reached the edge of the screen
void tema1::CheckCollision()
{
    // Check if the rectangle around the duck exceeds any edge.
    if ((ul_y_limit > up_limit || dr_y_limit > up_limit) && up == false) { // up edge
        up = true; down = false; left = false; right = false;
        if (!body_rotate) col_counter += 1;
        body_rotate = true;
    }
    else if ((ul_y_limit < down_limit || dr_y_limit < down_limit) && down == false) { // down edge
        up = false; down = true; left = false; right = false;
        if (!body_rotate) col_counter += 1;
        body_rotate = true;
    }
    else if ((ul_x_limit > right_limit || dr_x_limit > right_limit) && right == false) { // right edge
        up = false; down = false; left = false; right = true;
        if (!body_rotate) col_counter += 1;
        body_rotate = true;
    }
    else if ((ul_x_limit < left_limit || dr_x_limit < left_limit) && left == false) { // left edge
        up = false; down = false; left = true; right = false;
        if (!body_rotate) col_counter += 1;
        body_rotate = true;
    }

    if (up == true)
        y_increment = false;
    else if (down == true)
        y_increment = true;
    else if (right == true)
        x_increment = false;
    else if (left == true)
        x_increment = true;

    if (x_increment && y_increment) {
        duck_x += move;
        duck_y += move;
    }

    if (x_increment && !y_increment) {
        duck_x += move;
        duck_y -= move;
    }

    if (!x_increment && y_increment) {
        duck_x -= move;
        duck_y += move;
    }

    if (!x_increment && !y_increment) {
        duck_x -= move;
        duck_y -= move;
    }

}

// Compute the new coordinates for each component of the duck
void tema1::DuckTranslate()
{
    // Beak 
    beak_y = duck_y + 20;
    beak_x = duck_x - beak_base / 2;

    // Body
    body_x = duck_x - body_base / 2;
    body_y = duck_y - body_height;

    // Left wing
    left_wing_x = duck_x - body_base / 4;
    left_wing_y = duck_y - head_radius - body_base;

    // Right wing
    right_wing_x = duck_x + body_base / 4;
    right_wing_y = duck_y - head_radius - body_height / 8;

    // Left leg
    leg1_x = duck_x - body_base / 2.5;
    leg1_y = duck_y - body_height - leg1_length;

    // Right leg
    leg2_x = duck_x + body_base / 2.5 - leg2_length;
    leg2_y = duck_y - body_height - leg2_length;

    // up-left duck_rec corner, down-right duck_rec corner
    ul_x_limit = duck_x - body_base / 2 - left_wing_length / 1.5;
    ul_y_limit = duck_y - body_height - leg2_length + duck_rec_height;
    dr_x_limit = duck_x - body_base / 2 - left_wing_length / 1.5 + duck_rec_length;
    dr_y_limit = duck_y - body_height - leg2_length;

    // The duck was shot, so it will be face down.
    if (shot) {
        body_rotate_angle = 3.14;
        beak_x += 30;
        beak_y -= 40;    
        body_x += 50;
        body_y += 170;
        left_wing_x += 20;
        left_wing_y += 150;
        right_wing_x -= 20;
        right_wing_y += 70;
        leg1_x += 15;
        leg1_y += 200;
        leg2_x += 10;
        leg2_y += 200;
    }
    else if (x_increment && y_increment && !escape) { // Left down -> Up
        body_rotate_angle = (-1) * 3.14 / 4;
        beak_x += 20;
        beak_y += 5;
        body_x -= 50;
        body_y += 30;
        left_wing_x -= 40;
        left_wing_y += 20;
        right_wing_x -= 25;
        leg1_x -= 60;
        leg1_y += 30;
        leg2_x -= 70;
        leg2_y += 15;

        // up-left duck_rec corner, down-right duck_rec corner
        // up-left duck_rec corner, down-right duck_rec corner
        ul_x_limit = leg1_x + leg1_length/2;
        ul_y_limit = beak_y;
        dr_x_limit = beak_x;
        dr_y_limit = leg2_y;
        rec_type = 1;
    }
    else if (x_increment && !y_increment && !escape) { // Up -> Right down
        body_rotate_angle = (-1) *  2 * 3.14 / 3;
        beak_x += 40;
        beak_y -= 15;
        body_x -= 45;
        body_y += 150;
        left_wing_x -= 50;
        left_wing_y += 120;
        right_wing_x -= 45;
        right_wing_y += 45;
        leg1_x -= 65;
        leg1_y += 160;
        leg2_x -= 100;
        leg2_y += 145;

        ul_x_limit = leg1_x;
        ul_y_limit = leg1_y;
        dr_x_limit = beak_x + beak_height * 2;
        dr_y_limit = beak_y - beak_height * 2;
        rec_type = 2;

    }
    else if (!x_increment && y_increment && !escape) { // Down -> Left up
        body_rotate_angle = 3.14 / 4;
        beak_x -= 10;
        beak_y -= 15;
        body_x += 70;
        body_y += 5;
        left_wing_x += 60;
        left_wing_y += 20;
        right_wing_x += 15;
        right_wing_y += 20;
        leg1_x += 80;
        leg1_y += 15;
        leg2_x += 75;
        leg2_y += 35;

        ul_x_limit = beak_x;
        ul_y_limit = beak_y + beak_height;
        dr_x_limit = leg2_x;
        dr_y_limit = leg1_y;
        rec_type = 3;

    }
    else if (!x_increment && !y_increment && !escape) { // Right -> Left down
        body_rotate_angle = 2 * 3.14 / 3;

        beak_x += 5;
        beak_y -= 45;
        body_x += 120;
        body_y += 105;
        left_wing_x += 80;
        left_wing_y += 110;
        right_wing_x += 15;
        right_wing_y += 60;
        leg1_x += 125;
        leg1_y += 130;

        leg2_x += 85;
        leg2_y += 155;

        ul_x_limit = beak_x - beak_base / 2;
        ul_y_limit = leg2_y;
        dr_x_limit = leg1_x - leg1_length;
        dr_y_limit = beak_y;
        rec_type = 4;

    }
    else
        body_rotate_angle = 0;
}

// Render all objects
void tema1::Render(float deltaTimeSeconds)
{
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, 0);
    RenderMesh2D(meshes["grass"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(duck_x, duck_y);
    RendHeadColor();


    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(beak_x, beak_y);
    modelMatrix *= transform2D::Rotate(body_rotate_angle);
    RendBeakColor();

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(body_x, body_y);
    modelMatrix *= transform2D::Rotate(body_rotate_angle);
    RendBodyColor();


    if (resetWingsMove == false) {
        wingsMove += deltaTimeSeconds;
        if (wingsMove >= 0.1)
            resetWingsMove = true;
    }
    else {
        wingsMove -= deltaTimeSeconds;
        if (wingsMove <= 0)
            resetWingsMove = false;
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(left_wing_x, left_wing_y);
    modelMatrix *= transform2D::Rotate(M_PI / 2);
    modelMatrix *= transform2D::Rotate(body_rotate_angle);
    modelMatrix *= transform2D::Rotate(wingsMove);
    RendLwColor();

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(right_wing_x, right_wing_y);
    modelMatrix *= transform2D::Rotate(-M_PI / 2);
    modelMatrix *= transform2D::Rotate(body_rotate_angle);
    modelMatrix *= transform2D::Rotate(wingsMove);
    RendRwColor();

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(leg1_x, leg1_y);
    modelMatrix *= transform2D::Rotate(body_rotate_angle);
    modelMatrix *= transform2D::Rotate(wingsMove);
    RendLlColor();

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(leg2_x, leg2_y);
    modelMatrix *= transform2D::Rotate(body_rotate_angle);
    modelMatrix *= transform2D::Rotate(wingsMove);
    RendRlColor();

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1260 - score1_length, 700 - score1_height);
    RenderMesh2D(meshes["fullScore"], shaders["VertexColor"], modelMatrix);

    // Check if the score bar has been filled
    if (scale_time) {
        scoreScale += 2 * duck_counter;
        if (scoreScale > 200 && new_score == false) {
            scoreScale = 200;
            bullet_total += 1;
            bullet_total = MIN(bullet_total, 10);
            new_score = true;
        }
        else if (new_score) {
            scoreScale = 0;
            new_score = false;
        }

        scale_time = false;
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1260 - score1_length, 700 - score1_height);
    modelMatrix *= transform2D::Scale(scoreScale, 1);
    RenderMesh2D(meshes["realScore"], shaders["VertexColor"], modelMatrix);

    for (int i = 0; i < life_number; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(20 + i * 25, 700);
        RenderMesh2D(meshes["life"], shaders["VertexColor"], modelMatrix);
    }

    int j = 0;
    for (int i = 0; i < bullet_number; i++) {
        modelMatrix = glm::mat3(1);
        if (i <= 4)
            modelMatrix *= transform2D::Translate(10 + i * 20, 650);
        else {
            modelMatrix *= transform2D::Translate(10 + j * 20, 600);
            j += 1;
        }
        RenderMesh2D(meshes["bullet"], shaders["VertexColor"], modelMatrix);
    }

    // Bonus: killing spree
    if (killingSpree >= 3) {
        if (killingScale <= 1 && killingScaleUp == true)
            killingScale += killingSpree / 3 * deltaTimeSeconds;
        else {
            killingScaleUp = false;
        }

        if (killingScale >= 0 && killingScaleUp == false) {
            killingScale -= killingSpree / 3 * deltaTimeSeconds;
        }
        else {
            killingScaleUp = true;
        }

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(1200, 700 - 3 * score1_height);
        modelMatrix *= transform2D::Translate(0, 0);
        modelMatrix *= transform2D::Rotate(90);
        modelMatrix *= transform2D::Scale(killingScale, killingScale);
        RenderMesh2D(meshes["killing"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(ul_x_limit, dr_y_limit);
        switch (rec_type)
        {
        case 1: RenderMesh2D(meshes["duckRec1"], shaders["VertexColor"], modelMatrix);
            break;
        case 2: RenderMesh2D(meshes["duckRec2"], shaders["VertexColor"], modelMatrix);
            break;
        case 3: RenderMesh2D(meshes["duckRec3"], shaders["VertexColor"], modelMatrix);
            break;
        case 4: RenderMesh2D(meshes["duckRec4"], shaders["VertexColor"], modelMatrix);
            break;
        }
    }
}

void tema1::RendHeadColor()
{
    switch (head_color)
    {
    case 1:
        RenderMesh2D(meshes["head"], shaders["VertexColor"], modelMatrix);
        break;
    case 2:
        RenderMesh2D(meshes["head_1"], shaders["VertexColor"], modelMatrix);
        break;
    case 3:
        RenderMesh2D(meshes["head1"], shaders["VertexColor"], modelMatrix);
        break;
    case 4:
        RenderMesh2D(meshes["head2"], shaders["VertexColor"], modelMatrix);
        break;
    case 5:
        RenderMesh2D(meshes["head3"], shaders["VertexColor"], modelMatrix);
        break;
    case 6:
        RenderMesh2D(meshes["head4"], shaders["VertexColor"], modelMatrix);
        break;
    case 7:
        RenderMesh2D(meshes["head5"], shaders["VertexColor"], modelMatrix);
        break;
    }
    
}

void tema1::RendBeakColor()
{
    switch (beak_color)
    {
    case 1:
        RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);
        break;
    case 2:
        RenderMesh2D(meshes["beak1"], shaders["VertexColor"], modelMatrix);
        break;
    case 3:
        RenderMesh2D(meshes["beak2"], shaders["VertexColor"], modelMatrix);
        break;
    case 4:
        RenderMesh2D(meshes["beak3"], shaders["VertexColor"], modelMatrix);
        break;
    case 5:
        RenderMesh2D(meshes["beak4"], shaders["VertexColor"], modelMatrix);
        break;
    }
}

void tema1::RendBodyColor()
{
    switch (body_color)
    {
    case 1:
        RenderMesh2D(meshes["body"], shaders["VertexColor"], modelMatrix);
        break;
    case 2:
        RenderMesh2D(meshes["body1"], shaders["VertexColor"], modelMatrix);
        break;
    case 3:
        RenderMesh2D(meshes["body2"], shaders["VertexColor"], modelMatrix);
        break;
    case 4:
        RenderMesh2D(meshes["body3"], shaders["VertexColor"], modelMatrix);
        break;
    case 5:
        RenderMesh2D(meshes["body4"], shaders["VertexColor"], modelMatrix);
        break;
    }
}

void tema1::RendLwColor()
{
    switch (lw_color)
    {
    case 1:
        RenderMesh2D(meshes["leftWing"], shaders["VertexColor"], modelMatrix);
        break;
    case 2:
        RenderMesh2D(meshes["leftWing1"], shaders["VertexColor"], modelMatrix);
        break;
    case 3:
        RenderMesh2D(meshes["leftWing2"], shaders["VertexColor"], modelMatrix);
        break;
    case 4:
        RenderMesh2D(meshes["leftWing3"], shaders["VertexColor"], modelMatrix);
        break;
    case 5:
        RenderMesh2D(meshes["leftWing4"], shaders["VertexColor"], modelMatrix);
        break;
    }
}

void tema1::RendRwColor()
{
    switch (rw_color)
    {
    case 1:
        RenderMesh2D(meshes["rightWing"], shaders["VertexColor"], modelMatrix);
        break;
    case 2:
        RenderMesh2D(meshes["rightWing1"], shaders["VertexColor"], modelMatrix);
        break;
    case 3:
        RenderMesh2D(meshes["rightWing2"], shaders["VertexColor"], modelMatrix);
        break;
    case 4:
        RenderMesh2D(meshes["rightWing3"], shaders["VertexColor"], modelMatrix);
        break;
    case 5:
        RenderMesh2D(meshes["rightWing4"], shaders["VertexColor"], modelMatrix);
        break;
    }
}

void tema1::RendLlColor()
{
    switch (ll_color)
    {
    case 1:
        RenderMesh2D(meshes["leftLeg"], shaders["VertexColor"], modelMatrix);
        break;
    case 2:
        RenderMesh2D(meshes["leftLeg1"], shaders["VertexColor"], modelMatrix);
        break;
    case 3:
        RenderMesh2D(meshes["leftLeg2"], shaders["VertexColor"], modelMatrix);
        break;
    case 4:
        RenderMesh2D(meshes["leftLeg3"], shaders["VertexColor"], modelMatrix);
        break;
    case 5:
        RenderMesh2D(meshes["leftLeg4"], shaders["VertexColor"], modelMatrix);
        break;
    }
}

void tema1::RendRlColor()
{
    switch (rl_color)
    {
    case 1:
        RenderMesh2D(meshes["rightLeg"], shaders["VertexColor"], modelMatrix);
        break;
    case 2:
        RenderMesh2D(meshes["rightLeg1"], shaders["VertexColor"], modelMatrix);
        break;
    case 3:
        RenderMesh2D(meshes["rightLeg2"], shaders["VertexColor"], modelMatrix);
        break;
    case 4:
        RenderMesh2D(meshes["rightLeg3"], shaders["VertexColor"], modelMatrix);
        break;
    case 5:
        RenderMesh2D(meshes["rightLeg4"], shaders["VertexColor"], modelMatrix);
        break;
    }
}

void tema1::ColorChange()
{
    head_color = 1 + (float)(rand() % 7);
    beak_color = 1 + (float)(rand() % 5);
    body_color = 1 + (float)(rand() % 5);
    lw_color = 1 + (float)(rand() % 5);
    rw_color = 1 + (float)(rand() % 5);
    ll_color = 1 + (float)(rand() % 5);
    rl_color = 1 + (float)(rand() % 5);
}

// Render the screen that marks the end of the game.
void tema1::RenderEnd(float deltaTimeSeconds) {

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-face_radius / 2, +face_radius / 2);
    RenderMesh2D(meshes["iris"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(+face_radius / 2, +face_radius / 2);
    RenderMesh2D(meshes["iris"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-face_radius / 2, +face_radius / 2);
    RenderMesh2D(meshes["eye"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(+face_radius / 2, +face_radius / 2);
    RenderMesh2D(meshes["eye"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-face_radius / 2, +face_radius / 4);
    RenderMesh2D(meshes["tears"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-face_radius / 2, +face_radius / 5);
    RenderMesh2D(meshes["tears"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-face_radius / 2, +face_radius / 6);
    RenderMesh2D(meshes["tears"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-nose_length / 2, 0);
    RenderMesh2D(meshes["nose"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-face_radius / 2, -face_radius / 2);
    RenderMesh2D(meshes["mouth"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, 0);
    RenderMesh2D(meshes["face"], shaders["VertexColor"], modelMatrix);
}


void tema1::OnInputUpdate(float deltaTime, int mods)
{

}

void tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}

void tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}

void tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}

void tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    if (button == 1 && shot == false && begin == false && escape == false) {
        if ((mouseX >= ul_x_limit) && (mouseX <= dr_x_limit) &&
            (mouseY <= 720 - dr_y_limit) && (mouseY >= 720 - ul_y_limit)) {
            shot = true;
            scale_time = true;
            seconds = 0;
            col_counter = 0;
            duck_counter += 1;
            killingSpree += 1;
            if (duck_counter % 5 == 0) {
                speed_flag += 0.2f;
                speed += speed_flag * speed / 10;
            }

            if (head_color == 1) {
                if ((1 + (float)(rand() % 100)) <= 50) {
                    life_number += 1;
                    life_number = MIN(life_number, 10);
                }
            }
            else if (head_color == 2) {
                    if ((1 + (float)(rand() % 100)) <= 50) {
                        bullet_total += 1;
                        bullet_total = MIN(bullet_total, 10);
                    }
            }
            bullet_number = bullet_total;
        }
        else {
            bullet_number--;
            if (bullet_number == 0) {
                escape = true;
                life_number -= 1;

                if (life_number == 0) {

                    escape = true;
                }

                seconds = 0;
                bullet_number = bullet_total;
                killingSpree = 0;
            }
        }
    }
}

void tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}

void tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void tema1::OnWindowResize(int width, int height)
{
}
