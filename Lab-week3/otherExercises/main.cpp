/**
A.
#include <iostream>
#include <cmath>
#define epsilon 0.001

using namespace std;

double f(double x)
{
    return x*x-3;
}

double sol(double a, double b)
{double m;
m=(a+b)/2.0;
cout<<a<<' '<<b<<' '<<m<<endl;
if(f(m)<=epsilon && f(m)>=-epsilon) return m;
else {if(f(m)*f(b)<0) sol(m, b);
else if(f(a)*f(m)<0) sol(a, m);
}
}

double solutie(double a, double b)
{double mij, s;
mij=(a+b)/2;
while(!(f(mij)>=-epsilon && f(mij)<=epsilon))
{if(f(mij)*f(b)<0) a=mij;
else if(f(a)*f(mij)<0) b=mij;
mij=(a+b)/2.0;
}
return mij;
}



int main()
{
   cout<<solutie(-2, 2);
    return 0;
}

**/

/**#include <iostream>
#include <cmath>
#define epsilon 0.0001
using namespace std;

double radical(double x)
{double a, b;
a=1;
b=1/2.0*(a+(double)x/a);
while(abs(a-b)>epsilon)
{a=b;
b=1/2.0*(a+(double)x/a);
}
return b;

}

int main(){
double n;
cin>>n;
cout<<radical(n);



return 0;}


**/


#include <iostream>
#include <stdlib.h>
#define CARO 0
#include <bits/stdc++.h>
using namespace std;

struct Carte {
    char simbol;
    int valoare;
	}pachet[52];

#define as 11

int main(){
int i;
srand(time(0));
for(i=1; i<=52; i++)
{//srand(time(0));
pachet[i].simbol=rand()%4;
//srand(time(0));
pachet[i].valoare=rand()%15;
if(pachet[i].valoare==0 || pachet[i].valoare==1) pachet[i].valoare=as;
}
for(i=1; i<=5; i++)
    {if(pachet[i].simbol==0) cout<<"caro"<<' ';
    else if(pachet[i].simbol==1) cout<<"inima"<<' ';
    else if(pachet[i].simbol==2) cout<<"trefla"<<' ';
    else cout<<"frunza";
    if(pachet[i].valoare<=10) cout<<pachet[i].valoare<<endl;
    else if(pachet[i].valoare==11) cout<<"A"<<endl;
    else if(pachet[i].valoare==12) cout<<"J"<<endl;
    else if(pachet[i].valoare==13) cout<<"Q"<<endl;
    else cout<<"K"<<endl;
    }

return 0;}



/**
#include <iostream>

using namespace std;



struct lista
{
int in, sf;
}v[1001];


int n, cnt;
void adaugare(int st, int dr)
{int i, j, situatie=0;
cnt++;
v[cnt].in=st;
v[cnt].sf=dr;
if(cnt!=1)
{int i;
i=cnt-1;
int val=v[cnt].in, val2=v[cnt].sf;
while(val<v[i].in && i>=1)
{v[i+1]=v[i];
i--;
}
int ok=1;
if(i)
{if(val<=v[i].sf){cout<<"eroare";

for(j=i+1; j<cnt; j++)
v[j]=v[j+1];
cnt--;
ok=0;}
}
if(ok)
{if(i+1!=cnt && val2>=v[i+1].in){cout<<"eroare";

for(j=i+1; j<cnt; j++)
v[j]=v[j+1];
cnt--;
ok=0;}
if(ok){
if(i)
{if(v[i].sf+1==val)
{situatie=1;
for(j=i+1; j<cnt; j++)
    v[j]=v[j+1];
cnt--;
v[i].sf=val2;

if(i!=cnt)
{if(v[i].sf+1==v[i+1].in)
{v[i].sf=v[i+1].sf;
for(j=i+1; j<cnt; j++)
{v[j]=v[j+1];
}
cnt--;
}
}
}
}

if(i!=cnt)
{if(val2+1==v[i+1].in)
{for(j=i+1; j<cnt; j++)
v[j]=v[j+1];
cnt--;
v[i+1].in=val;
situatie=1;
}
}





if(!situatie)
{v[i+1].in=val;
v[i+1].sf=val2;}


}
}
}
}

void afis()
{int i;
for(i=1; i<=cnt; i++)
    cout<<'['<<v[i].in<<' '<<v[i].sf<<']'<<" ";
    cout<<endl;
}

void stergere(int st, int dr)
{int i, j;
i=cnt;
while(st<v[i].in)
{i--;
}
if(v[i].in==st)
{if(v[i].sf==dr)
{for(j=i; j<cnt; j++)
v[j]=v[j+1];
cnt--;
}
else
v[i].in=dr+1;

}
else
{if(v[i].sf==dr)
v[i].sf=st-1;
else
{//cout<<i<<endl;
for(j=cnt; j>=i; j--)
    v[j+1]=v[j];
cnt++;
v[i].sf=st-1;
v[i+1].in=dr+1;
}
}
}


int main(){
int oper, i, inc, sfs;
cin>>n;
for(i=1; i<=n; i++)
{cin>>oper>>inc>>sfs;
if(oper==1)
adaugare(inc, sfs);
else if(oper==0) stergere(inc, sfs);
//cout<<cnt<<endl;
afis();
}




return 0;}
**/

/**
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;
ofstream fout("p.out");

int m, n, x;
struct puncte
{int eticheta;
struct
{int albe[1001];
int albe1[1001];
int cnt;
};
}negre[1001];
int nr;
void afisare()
{int i, j;
//cout<<endl;
for(i=1; i<=m; i++)
{cout<<negre[i].eticheta<<"->";
for(j=1; j<negre[i].cnt; j++)
    cout<<negre[i].albe[j]<<',';
cout<<negre[i].albe[negre[i].cnt];
cout<<endl;
//cout<<endl;
}
}


void afisare1()
{int i, j;
//cout<<endl;
for(i=1; i<=m; i++)
{cout<<negre[i].eticheta<<"->";
for(j=1; j<negre[i].cnt; j++)
    cout<<negre[i].albe1[j]<<',';
cout<<negre[i].albe1[negre[i].cnt];
cout<<endl;
//cout<<endl;
}
}



void inserare(int val)
{if(nr==0)
{nr++;
negre[nr].eticheta=val;
}
else
{int i=nr;
nr++;
while(val<negre[i].eticheta)
{negre[i+1].eticheta=negre[i].eticheta;
i--;
}
negre[i+1].eticheta=val;
}
}

void inserare1(int poz, int val)
{if(negre[poz].cnt==0)
{negre[poz].cnt++;
negre[poz].albe[1]=val;
}
else
{int i=negre[poz].cnt;
negre[poz].cnt++;
while(i>0 && val<negre[poz].albe[i])
{negre[poz].albe[i+1]=negre[poz].albe[i];
i--;
}
negre[poz].albe[i+1]=val;
}
}


void inserare3(int poz, int val)
{if(negre[poz].cnt==0)
{negre[poz].cnt++;
negre[poz].albe1[1]=val;
}
else
{int i=negre[poz].cnt;
negre[poz].cnt++;
while(i>0 && (abs(negre[poz].eticheta-val)<abs(negre[poz].albe1[i]-negre[poz].eticheta) ||(abs(negre[poz].eticheta-val)==abs(negre[poz].albe1[i]-negre[poz].eticheta) && val<negre[poz].albe1[i])))
{negre[poz].albe1[i+1]=negre[poz].albe1[i];
i--;
}
negre[poz].albe1[i+1]=val;
}
}


void inserare2(int poz, int val)
{if(negre[poz].cnt==1)
{
negre[poz].albe1[1]=val;
}
else
{int i=negre[poz].cnt-1;
while(i>0 && (abs(negre[poz].eticheta-val)<abs(negre[poz].albe1[i]-negre[poz].eticheta) ||(abs(negre[poz].eticheta-val)==abs(negre[poz].albe1[i]-negre[poz].eticheta) && val<negre[poz].albe1[i])))
{negre[poz].albe1[i+1]=negre[poz].albe1[i];
i--;
}
negre[poz].albe1[i+1]=val;
}
}


void stergere(int ind, int poz)
{int i;
for(i=poz; i<negre[ind].cnt; i++)
    negre[ind].albe1[i]=negre[ind].albe1[i+1];
negre[ind].cnt--;
}

void afis()
{for(int i=1; i<=nr; i++)
cout<<negre[i].eticheta<<' ';
}


int main(){
int i, j, ok, mij;
cin>>m;
for(i=1; i<=m; i++)
    {cin>>x;
    inserare(x);
    }
//afis();

cin>>n;
for(i=1; i<=m*n; i++)
{cin>>x; ok=0;
for(j=1; j<m && !ok; j++)
{if(x>=negre[j].eticheta && x<=negre[j+1].eticheta)
{mij=(negre[j].eticheta+negre[j+1].eticheta)/2;
if(x<=mij){inserare1(j, x); inserare2(j, x);
}
else{inserare1(j+1, x);inserare2(j+1, x);
}
ok=1;
}
}
if(j==m &&!ok)
{if(x<negre[1].eticheta){inserare1(1, x);
inserare2(1, x);
}
else{inserare1(m, x);
inserare2(m, x);
}

}
}

afisare();
i=1;
int k, gata;
gata=1;
do
{
gata=1;
for(i=1; i<=n; i++)
{if(negre[i].cnt!=n) gata=0;
if(negre[i].cnt>n)
{for(j=n+1; j<=negre[i].cnt; j++)
{if(i<n) k=i+1;
else k=1;
inserare3(k, negre[i].albe1[j]);
stergere(i, j);
//afisare1();
}
//i=k;

}
}
}while(!gata);
cout<<endl;
afisare1();

return 0;}
**/

/**
#include <iostream>

using namespace  std;
int n, joc[1001][1001], muta;

void afis()
{int i, j;
for(i=1; i<=n; i++, cout<<endl)
    for(j=1; j<=n; j++)
    cout<<joc[i][j]<<' ';
}

bool castiga(int jucator)
{int i, j, l, c;
for(i=0; i<=n+1; i++)
    {joc[0][i]=joc[n+1][i]=jucator;
    joc[i][0]=joc[i][n+1]=jucator;
    }
for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
   {if(joc[i][j]==0) l=i, c=j;
   }
if(joc[l][c+1]==jucator && joc[l+1][c]==jucator && joc[l][c-1]==jucator && joc[l-1][c]==jucator)
   return true;
   return false;

}


int main()
{int i, j;
cin>>n;
for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    cin>>joc[i][j];
//for(i=1; i<=n; i++)
//{for(j=1; j<=n; j++)
//if(i%2==j%2) joc[i][j]=1;
//else joc[i][j]=2;
//}
//joc[n/2+1][n/2+1]=0;
cout<<castiga(1);

return 0;
}
**/
/**
#include <iostream>
#include <string.h>

using namespace std;

int n, m, cnt;
char s[1001], afis[1001];

struct joc
{int nr_cutii, nr_litere=0, out=0;
char litere[1001];

}copil[1001];

void afisare()
{int i;
for(i=1; i<=n; i++)
    cout<<copil[i].nr_cutii<<' '<<copil[i].out<<' '<<copil[i].nr_litere<<' '<<copil[i].litere<<endl;
cout<<endl;}

int main()
{int i, k, j;
cin>>n;
for(i=1; i<=n; i++)
{cin>>copil[i].nr_cutii;
}
cin>>m;
k=1; afis[0]=0;
for(i=1; i<=m; i++)
{cin>>s;
for(j=0; j<strlen(s); j++)
{
while(copil[k].out) {if(k==n) k=1;
else k++;}
copil[k].nr_litere++;
copil[k].litere[copil[k].nr_litere-1]=s[j];
if(copil[k].nr_litere==copil[k].nr_cutii)
{strcat(afis, copil[k].litere);
copil[k].out=1;
}
//afisare();
if(k==n) k=1;
else k++;
}

}



cout<<afis;


    return 0;
}
**/
