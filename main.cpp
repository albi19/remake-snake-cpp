#include <iostream>
#include <windows.h>
#include <graphics.h>

using namespace std;
int x, y, r;


/*void moving(){

}*/

int main()
{



    int length=5;

    r=20;
    x=500;
    y=500;

    int n=0;

    int pos_x_final=500;
    int pos_y_final=500;

    bool gaming = true;
    bool moving = false;
    initwindow(1000,1000,"ciao",2,2);
    while(1){

        int pos_x[100000];
        int pos_y[100000];

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
            pos_x[n]=x;
            pos_y[n]=y;
            circle(x,y,r);
            n++;




            length=500;

            if(n>length){
                pos_x_final=pos_x[n-length];
                pos_y_final=pos_y[n-length];

                int pos_x_final1=pos_x[n-1];
                int pos_y_final1=pos_y[n-1];
                if(moving==true && x!=pos_x_final1 && y!=pos_y_final1){



                    setcolor(BLACK);

                    circle(pos_x_final,pos_y_final,r);

                    setfillstyle(SOLID_FILL, BLACK);
                    floodfill(pos_x_final,pos_y_final,BLACK);

                }

            }






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
