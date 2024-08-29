#include <iostream>
#include <fstream>

using namespace std;
ifstream f("arbori.in");

int cnt=0, v[101];
int maxim, a[101][101], nr[101];

struct nod
{int inf;
nod *st, *dr;
};

void creare(nod *&r)
{int x;
f>>x;
if(x!=0)
{r=new nod;
r->inf=x;
creare(r->st);
creare(r->dr);
}
else r=NULL;
}


void rsd(nod *r)
{
if(r!=NULL)
{cout<<r->inf<<" ";
rsd(r->st);
rsd(r->dr);
}
}

void srd(nod *r)
{
if(r!=NULL)
{srd(r->st);
cout<<r->inf<<" ";

srd(r->dr);
}
}

void sdr(nod *r)
{
if(r!=NULL)
{sdr(r->st);
sdr(r->dr);
cout<<r->inf<<" ";
}
}

void frunze( nod *r)
{
if(r!=NULL)
{if(r->st==NULL && r->dr==NULL)
{cnt++;
v[cnt]=r->inf;
}
else
{frunze(r->st);
frunze(r->dr);
}
}
}

void nivel(nod *r, int niv)
{if(r!=NULL)
{if(niv>maxim) maxim=niv;
nr[niv]++;
a[niv][nr[niv]]=r->inf;
nivel(r->st, niv+1);
nivel(r->dr, niv+1);
}
}

int vx[101], vy[101], ok;

void dfs1(nod *r, int x)
{if(r!=NULL && ok)
{if(r->inf==x) ok=0;
else
{
if(r->st!=NULL)
{vx[r->st->inf]=r->inf;
dfs1(r->st, x);
}
if(r->dr!=NULL)
{vx[r->dr->inf]=r->inf;
dfs1(r->dr, x);
}
}
}
}

void dfs2(nod *r, int x)
{if(r!=NULL && ok)
{if(r->inf==x) ok=0;
else
{
if(r->st!=NULL)
{vy[r->st->inf]=r->inf;
dfs2(r->st, x);
}
if(r->dr!=NULL)
{vy[r->dr->inf]=r->inf;
dfs2(r->dr, x);
}
}
}
}



int cnt1, cnt2;
int a1[101], a2[101];

int main()
{int i, j;
nod *rad;
creare(rad);
int val1, val2;
cin>>val1>>val2;
/*srd(rad);
cout<<endl;
rsd(rad);
cout<<endl;
sdr(rad);*/
//cnt=0;
/*frunze(rad);
cout<<cnt<<endl;
for(int i=1; i<=cnt; i++)
    cout<<v[i]<<' ';
    */\
/*maxim=0;
nivel(rad, 0);
cout<<maxim<<endl;
for(i=0; i<=maxim; i++)
{cout<<"Nivelul "<<i<<": ";
for(j=1; j<=nr[i]; j++)
    cout<<a[i][j]<<' ';
cout<<endl;
}*/
int t;
ok=1;
vx[rad->inf]=0;
dfs1(rad, val1);
cnt1=0, cnt2=0;
t=val1;
while(t)
{//cout<<vx[t]<<' ';
//t=vx[t];
cnt1++;
a1[cnt1]=t;
t=vx[t];
}

vy[rad->inf]=0;
ok=1;
dfs2(rad, val2);

t=val2;
while(t)
{//cout<<vx[t]<<' ';
//t=vx[t];
cnt2++;
a2[cnt2]=t;
t=vy[t];
}

i=cnt1;
j=cnt2;
while(a1[i]==a2[j] && i>=1 && j>=1) i--, j--;
cout<<a1[i+1];





    return 0;
}
