#include<raylib.h>
#include<vector>
#include<string>

#define HEIGHT 720
#define WIDTH 800
const float gravity = 2.5;

struct Ball{
    float x;
    float y;
    float radius;
    float vx;
    float vy;
    float ax; 
    float ay;
};

void update(std::vector<Ball> &balls){

    for(Ball &ball : balls){    
        ball.vx += ball.ax;
        ball.vy += ball.ay;

        ball.x += ball.vx;
        ball.y += ball.vy;
        
        if(ball.x - ball.radius <= 0 ){
        ball.x = 0 + ball.radius;
        ball.vx *= -1;
        }

        else if(ball.x + ball.radius > WIDTH){
            ball.x = WIDTH - ball.radius;
            ball.vx *= -1;
        }
    
        if(ball.y - ball.radius <= 0){
            ball.y = 0 + ball.radius;
            ball.vy *= -1;
        }

        else if(ball.y + ball.radius > HEIGHT){
            ball.y = HEIGHT - ball.radius;
            ball.vy *= -1;
        }        
    }
}

void draw(std::vector<Ball> &balls){
    ClearBackground(BLACK);
    for(Ball &ball : balls){
        DrawFPS(0,0);
        DrawCircle(ball.x,ball.y,ball.radius,GREEN);
    }
}

int main(){
    InitWindow(WIDTH,HEIGHT,"BALLSSSS");
    SetTargetFPS(60);

    std::vector<Ball> balls;

    for(int i = 0 ; i < 10 ; i++){
        balls.push_back(Ball{float(GetRandomValue(0,WIDTH)),float(GetRandomValue(0,HEIGHT)),5,float(GetRandomValue(-3,3)),float(GetRandomValue(-3,3)),0,gravity});
          
    }

    while(!WindowShouldClose()){
        update(balls);
        BeginDrawing();
        draw(balls);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}