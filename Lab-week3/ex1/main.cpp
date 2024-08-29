#include <iostream>

using namespace std;

///Complex numbers operations

struct complexe
{
double re, im;
}x;

complexe adunare(complexe x, complexe y)
{complexe a;
a.re=x.re+y.re;
a.im=x.im+y.im;
return a;
}

complexe scadere(complexe x, complexe y)
{complexe a;
a.re=x.re-y.re;
a.im=x.im-y.im;
return a;
}

complexe inmultire(complexe x, complexe y)
{complexe p;
p.re=x.re*y.re-x.im*y.im;
p.im=x.im*y.re+x.re*y.im;
return p;
}

complexe impartire(complexe x, complexe y)
{complexe i;
i.re=(double)(x.re*y.re+x.im*y.im)/(y.re*y.re+y.im*y.im);
i.im=(double)(x.im*y.re-x.re*y.im)/(y.re*y.re+y.im*y.im);
return i;
}

int main()
{complexe x, y, a, b, p, i;
cin>>x.re>>x.im>>y.re>>y.im;
a=adunare(x, y);
b=scadere(x, y);
p=inmultire(x, y);
i=impartire(x, y);
cout<<a.re<<' '<<a.im<<'i'<<endl;
cout<<b.re<<' '<<b.im<<'i'<<endl;
cout<<p.re<<' '<<p.im<<'i'<<endl;
cout<<i.re<<' '<<i.im<<'i'<<endl;
return 0;
}


/*#include <iostream>

using namespace std;

struct piesa
{char c, t;
int l, col;
};

bool inmat(int i, int j)
{
    return(i>=1 && j>=1 && i<=8 && j<=8);
}

bool ataca (piesa nebun, piesa pion)
{int m[101][101];
int i, j;
for(i=1; i<=8; i++)
    for(j=1; j<=8; j++)
    m[i][j]=0;

i=nebun.l;
j=nebun.col;
while(inmat(i, j))
{m[i][j]=1;
//cout<<i<<' '<<j<<endl;
i++;
j++;
if(i>8 || j>8) break;
}

while(inmat(i, j))
{m[i][j]=1;
i++;
j--;
if(i>8 || j>8) break;
}

while(inmat(i, j))
{m[i][j]=1;
i--;
j++;
if(i>8 || j>8) break;
}


while(inmat(i, j))
{m[i][j]=1;
i--;
j--;
if(i>8 || j>8) break;
}
cout<<endl;
for(i=1; i<=8; i++, cout<<endl)
   for(j=1; j<=8; j++)
    cout<<m[i][j]<<' ';
if(m[pion.l][pion.col] && pion.c!=nebun.c)  return true;
return false;

}

int main()
{int i, j;

piesa p1;
piesa p2;
cin>>p1.t>>p1.c>>p1.l>>p1.col;
cin>>p1.t>>p1.c>>p2.l>>p2.col;

cout<<ataca(p1, p2);
/*
while(inmat(i, j))
{m[i][j]=1;
cout<<i<<' '<<j<<endl;
i++;
j++;
if(i>8 || j>8) break;
}

while(inmat(i, j))
{m[i][j]=1;
i++;
j--;
if(i>8 || j>8) break;
}

while(inmat(i, j))
{m[i][j]=1;
i--;
j++;
if(i>8 || j>8) break;
}


while(inmat(i, j))
{m[i][j]=1;
i--;
j--;
if(i>8 || j>8) break;
}
cout<<endl;
for(i=1; i<=8; i++)
    for(j=1; j<=8; j++, cout<<endl)
    cout<<m[i][j]<<' ';




    return 0;
}
*/
