#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("lista.in.ads");
ofstream fout("lista.out");


struct nod
{int info;
nod *urm;
};


void creare (nod *&prim, nod*&ultim, int n)
{nod *p;
int i;
int x;
prim=ultim=NULL;
for(i=1; i<=n; i++)
{fin>>x;
p=new nod;
p->info=x;
p->urm=NULL;
if(prim==NULL) prim=p;
else ultim->urm=p;
ultim=p;
}
}








void afisare(nod *prim)
{nod *p=prim;
while(p!=NULL)
{cout<<p->info<<' ';
p=p->urm;
}

}


void inserare(nod *&prim, nod *&ultim, int val)
{ nod *q;
q=new nod;
q->info=val;
q->urm=NULL;
if(prim==NULL)
{prim=ultim=q;
}
else{
ultim->urm=q;
ultim=q;
}
}

void stergere (nod *&prim)
{nod *p;
/*if(prim->info%2==0)
{nod *q;
q=new nod;
q=prim;
prim=prim->urm;
delete q;

}*/

while(prim->info%2==0)
{nod *q;
q=prim;
prim=prim->urm;
delete q;
}


p=prim;
while(p->urm!=NULL)
{if(p->urm->info%2==0)
{nod *q;
q=p->urm;
p->urm=p->urm->urm;
delete q;
}
else p=p->urm;
}
}

void interclasare(nod *&p1, nod *&p2, nod *&p3, nod *&u)
{nod *p, *q;
p=p1; q=p2;
p3=u=NULL;
nod *r;
while(p!=NULL && q!=NULL)
{

if(p->info<q->info)
{inserare(p3, u, p->info);
p=p->urm;
}

else
{
inserare(p3, u, q->info);
q=q->urm;
}
//cout<<r->info<<endl;
}
/*
while(p!=NULL)
{nod *r;
r=new nod;
r->urm=NULL;
r->info=p->info;
if(p3==NULL)
{p3=r;
}
else
{u->urm=r;
u=r;
}
p=p->urm;
}



while(q!=NULL)
{nod *r;
r=new nod;
r->urm=NULL;
r->info=q->info;
if(p3==NULL)
{p3=r;
}
else
{u->urm=r;
u=r;
}
q=q->urm;
}
*/

}


int palindrom(nod *prim)
{nod *p;
int m=0, n=0, aux;
p=prim;
while(p!=NULL)
{m=m*10+p->info;
p=p->urm;
}
aux=m;
while(m)
{n=n*10+m%10;
m=m/10;
}
//cout<<m<<' '<<n;
if(n==aux) return 1;
else return 0;




}


/*int pal(nod &*prim)
{nod *p;
int cnt=0;


}
*/



int main()
{nod *prim, *ultim, *p, *q, *u, *u1;
int m, n;
fin>>n>>m;
creare(prim, ultim, n);
creare(p, u1, m);
inserare(prim, ultim, 8);
interclasare(prim, p, q, u);
/*afisare(prim);
cout<<endl;
afisare(p);*/
afisare(q);
//cout<<palindrom(prim);

    return 0;
}
