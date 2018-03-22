#include <iostream>
#include <windows.h>
#include <graphics.h>

using namespace std;
int x, y, r,x2,y2;


/*void moving(){

}*/

int main()
{



    int punteggio=5;
    int velocita=100;

    r=20;
    x=200;
    y=500;

    x2=700;
    y2=500;

    int n=0;
    int n2=0;

    int pos_x_final=500;
    int pos_y_final=500;

    bool gaming = true;
    bool moving = false;
    initwindow(1000,1000,"ciao",2,2);
    while(1){

        int pos_x[100000];
        int pos_y[100000];

        int pos_x2[100000];
        int pos_y2[100000];

        while(gaming){



            setcolor(WHITE);

            if(GetAsyncKeyState( 'W' ) & 0x8000){
                y--;
                moving=true;
            }else if(GetAsyncKeyState( 'S' ) & 0x8000){
                y++;
                moving=true;
            }else if(GetAsyncKeyState( 'A' ) & 0x8000){
                x--;
                moving=true;
            }else if(GetAsyncKeyState( 'D' ) & 0x8000){
                x++;
                moving=true;
            }else{
                moving=false;
            }

            if(GetAsyncKeyState( VK_UP ) & 0x8000){
                y2--;
                moving=true;
            }else if(GetAsyncKeyState( VK_DOWN ) & 0x8000){
                y2++;
                moving=true;
            }else if(GetAsyncKeyState( VK_LEFT ) & 0x8000){
                x2--;
                moving=true;
            }else if(GetAsyncKeyState( VK_RIGHT ) & 0x8000){
                x2++;
                moving=true;
            }else{
                moving=false;
            }


            if(moving && velocita>2){
                punteggio+=5;
                velocita-=1;
            }


            pos_x[n]=x;
            pos_y[n]=y;
            circle(x,y,r);


            setcolor(GREEN);
            pos_x2[n2]=x2;
            pos_y2[n2]=y2;
            circle(x2,y2,r);

            setfillstyle(SOLID_FILL, BLACK);
            floodfill(x2,y2,BLACK);



            n++;
            n2++;




            if(x==1000 || y==1000 || x==0 || y==0){
                cleardevice();
                setcolor(WHITE);
                bgiout<<"GAME OVER"<<endl<<"PREMI SPAZIO PER RICOMINCIARE";
                outstreamxy(500,500);
                gaming=false;
            }

            delay(1);
        }

        if(GetAsyncKeyState( VK_SPACE ) & 0x8000){
            gaming=true;
            cleardevice();
            x=500;
            y=500;
            n=0;
        }
    }
    closegraph();
    return 0;
}
