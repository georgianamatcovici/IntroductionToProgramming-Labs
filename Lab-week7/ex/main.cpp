#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <graphics.h>
#include <stdlib.h>



using namespace std;

void cercuri(int x, int y, int r)
{if(r>10)
{circle(x, y, r);
cercuri(x, y, r/2);
}
}

int main()
{int i, d, ok, y, x;
initwindow(800, 800);
rectangle(100, 100, 700, 700);
ok=0;
y=100;
for(y=100; y<=600; y+=100)
{
for(x=100; x<=600; x+=100)
{//cout<<ok<<endl;
if(ok%2) setcolor(15);
else setcolor(0);
//rectangle(x, y, x+100, y+100);
//floodfill(x, y+100, );
if(x%200!=y%200) bar(x, y, x+100, y+100);
ok++;

}

}


//setcolor(3);
//bar(100, 100, 400, 400);
getch();
closegraph();
initwindow(800, 800);
cercuri(400, 400, 200);
getch();



    return 0;
}




