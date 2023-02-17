#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class tema1 : public gfxc::SimpleScene
    {
     public:
         tema1();
        ~tema1();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        void CheckCollision();
        void DuckTranslate();
        void Render(float deltaTimeSeconds);
        void RenderEnd(float deltaTimeSeconds);
        void RendHeadColor();
        void RendBeakColor();
        void RendBodyColor();
        void RendLwColor();
        void RendRwColor();
        void RendLlColor();
        void RendRlColor();
        void ColorChange();

     protected:
        glm::mat3 modelMatrix;
        float duck_x, duck_y;
        float head_x, head_y, head_radius;
        float beak_x, beak_y, beak_base, beak_height;
        float body_x, body_y, body_base, body_height;
        float left_wing_x, left_wing_y, left_wing_length;
        float right_wing_x, right_wing_y, right_wing_length;
        float leg1_x, leg1_y, leg1_length;
        float leg2_x, leg2_y, leg2_length;
        float duck_rec_x, duck_rec_y, duck_rec_length, duck_rec_height;
        float duck1_rec_length, duck1_rec_height;
        float duck2_rec_length, duck2_rec_height;
        float duck3_rec_length, duck3_rec_height;
        float duck4_rec_length, duck4_rec_height;
        float score1_x, score1_y, score1_length, score1_height;
        float score2_x, score2_y, score2_length, score2_height, scoreScale;
        bool scale_time, new_score;
        int life_number, life_total;
        float life_x, life_y, life_radius;
        int bullet_number, bullet_total;
        float bullet_x, bullet_y, bullet_length, bullet_height;
        float wingsMove;
        bool resetWingsMove;
        float move;
        float up_limit, right_limit, down_limit, left_limit;
        float ul_x_limit, ul_y_limit, dr_x_limit, dr_y_limit;
        bool up, left, right, down, x_increment, y_increment;
        bool body_rotate;
        bool shot, escape;
        bool begin;
        int right_direction;
        float speed, speed_flag;
        int duck_counter, col_counter;
        float seconds;
        float culoare;
        int killingSpree;
        float killingScale;
        bool killingScaleUp;
        int head_color, beak_color, body_color, lw_color, rw_color, ll_color, rl_color;
        int rec_type;
        float body_rotate_angle;
        bool end;
        float face_x, face_y, face_radius;
        float eye_x, eye_y, eye_radius;
        float iris_x, iris_y, iris_radius;
        float mouth_x, mouth_y, mouth_length, mouth_height;
        float tears_x, tears_y, tears_radius;
        float nose_x, nose_y, nose_length;
    };
}   // namespace m1
