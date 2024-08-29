#include <iostream>
#include <graphics.h>
#include <winbgim.h>

void patrate(int l1, int l2, int l3, int l4, int dist)
{int i;
for(i=1; i<=4; i++)
{rectangle(l1, l2, l3, l4);
l1+=dist;
l2+=dist;
l3-=dist;
l4-=dist;
}
}

void cercuri(int xc, int yc, int r)
{if(r>20)
{circle(xc, yc, r);
cercuri(xc, yc-r, 2*r/3);
cercuri(xc, yc+r, 2*r/3);
cercuri(xc-r, yc, 2*r/3);
cercuri(xc+r, yc, 2*r/3);
}
}
void triunghiuri(int a1, int a2, int b1, int b2, int c1, int c2)
{line(a1, a2, b1, b2);
line(a1, a2, c1, c2);
line(b1, b2, c1, c2);
}

void linii1(int pcx, int pcy, int x, int y, int r, int stopx)
{line(pcx, pcy, x, y);
if(x!=stopx)
    linii1(pcx, pcy, x+r, y, r, stopx);

}
void linii2(int pcx, int pcy, int x, int y, int r, int stopx)
{line(pcx, pcy, x, y);
if(x!=stopx)
    linii2(pcx, pcy, x-r, y, r, stopx);

}

int main()
{
  initwindow(600,600);
  //line(0, 300, 400, 300);
  //line(400, 300, 400, 0);
  rectangle(100, 100, 500, 500);
  line(300, 100, 300, 500);
  line(100, 300, 500, 300);
  patrate(120, 120, 280, 280, 20);
  cercuri(400,200, 50);
  triunghiuri(200, 350, 150, 450, 250, 450);
  triunghiuri(200, 325, 150, 375, 250, 375);
  triunghiuri(160, 410, 115, 475, 200, 475);
  triunghiuri(245, 410, 215, 475, 285, 475);
  linii1(300, 500, 300, 300, 50, 500);
  linii2(500, 500, 500, 300, 50, 300);
  getch();

  return 0;
}

/**
#include <iostream>
#include <graphics.h>
#include <winbgim.h>


int ok=1;
void triunghiuri(int a1, int a2, int b1, int b2, int c1, int c2)
{if(c1-b1>=5)
{line(a1, a2, b1, b2);
line(a1, a2, c1, c2);
line(b1, b2, c1, c2);
triunghiuri(a1, a2, (a1+b1)/2, (a2+b2)/2, (a1+c1)/2, (a2+c2)/2);
triunghiuri((a1+b1)/2, (a2+b2)/2, b1, b2, (b1+c1)/2, (b2+c2)/2);
triunghiuri((a1+c1)/2, (a2+c2)/2, (b1+c1)/2, (b2+c2)/2, c1, c2);


}
}

int main()
{
  initwindow(600,600);
triunghiuri(300, 100, 100, 500, 500, 500);
  //line(0, 300, 400, 300);
  //line(400, 300, 400, 0);

getch();
  return 0;
}
**/
