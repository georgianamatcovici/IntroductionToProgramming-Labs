#include <iostream>
#include <cstring>

using namespace std;

struct cuvinte{
		char cuvant[100];
		unsigned int nrAparitii=0;
	}aux;
int cnt=0;
void f(cuvinte v[100], char cuv[])
{int ap, j;
char *p, sep[]=" ,.?!:;", m[101][101];
p=strtok(cuv, sep);
while(p!=NULL)
{ap=0;
for(j=1; j<=cnt; j++)
if(strcmp(v[j].cuvant, p)==0) {ap++; v[j].nrAparitii++;}
if(!ap) {cnt++; strcpy(v[cnt].cuvant, p); v[cnt].nrAparitii++;}
p=strtok(NULL, sep);
}


int i, k;
for(i=1; i<cnt; i++)
    for(j=i+1; j<=cnt; j++)
{if(v[j].nrAparitii>v[i].nrAparitii)
{aux=v[i]; v[i]=v[j]; v[j]=aux;
}
else if(v[j].nrAparitii==v[i].nrAparitii)
{if(strcmp(v[i].cuvant, v[j].cuvant)>0)
{aux=v[i]; v[i]=v[j]; v[j]=aux;
}
}
}


}

int main()

{char s[101];
cin.getline(s, 100);
cuvinte a[100];
f(a, s);
int i;
for(i=1; i<=cnt; i++)
    cout<<a[i].cuvant<<' '<<a[i].nrAparitii<<endl;





    return 0;
}
