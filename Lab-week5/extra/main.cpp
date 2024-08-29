#include <iostream>
#include <cstring>

using namespace std;
//char s[100];
char cifra[11][30]={"zero","unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua"};

void scriere_numar(int n, char s[])
{s[0]=0;
char s1[100];
if(n<10)
{strcpy(s, cifra[n]);
}
else if(n==10) strcat(s, "zece");
else if(n<=19)
{if(n==11) strcat(s, "un");
else if(n==14) strcat(s, "pai");
else if(n==16) strcat(s, "sai");
else strcat(s, cifra[n-10]);
strcat(s, "sprezece");
}
else if(n<=99)
{if(n/10==2) strcat(s, "doua");
else if(n/10==6) strcpy(s, "sai");
else strcat(s, cifra[n/10]);
strcat(s, "zeci");
if(n%10!=0)
{strcat(s, " si ");
strcat(s, cifra[n%10]);
}
}
else if(n==100) strcat(s, "o suta");
else if(n<=199)
{strcat(s, "o suta ");
if(n/10%10)
{if(n/10%10==1)
{scriere_numar(n%100, s1);
strcat(s, s1);
}
else{if(n/10%10==2) strcat(s, "doua");
else if(n/10%10==6) strcat(s, "sai");
else  strcat(s, cifra[n/10%10]);
strcat(s, "zeci");}
}
if(n%10!=0 && n/10%10!=1)
{if(n/10%10) strcat(s, " si ");
strcat(s, cifra[n%10]);
}
}
else if(n<=999)
{
if(n/100==2) strcat(s, "doua ");
else strcat(s, cifra[n/100]);
strcat(s, " sute ");
if(n%100!=0)
{if(n/10%10)
 {if(n/10%10==1)
{scriere_numar(n%100, s1);
strcat(s, s1);
}
else{if(n/10%10==2) strcat(s, "doua");
else if(n/10%10==6) strcat(s, "sai");
else  strcat(s, cifra[n/10%10]);
strcat(s, "zeci");}
}
if(n%10!=0 && n/10%10!=1)
{if(n/10%10) strcat(s, " si ");
strcat(s, cifra[n%10]);
}
}
}
else if(n==1000) strcat(s, "o mie");
else if(n<=9999)
{ if(n<=1999) strcat(s, "o mie ");
else{
if(n/1000==2) strcat(s, "doua");
else strcat(s, cifra[n/1000]);
strcat(s, " mii ");
}
if(n/100%10==0)
{if(n/10%10==0) strcat(s, cifra[n%10]);
else
{
scriere_numar(n%100, s1);
strcat(s, s1);
}
}
else
{scriere_numar(n%1000, s1);
strcat(s, s1);
}
}
else if(n<=99999)
{
if(n%1000==0)
{
scriere_numar(n/1000, s1);
strcat(s, s1);
strcat(s, " mii ");
}
else
{scriere_numar(n/1000, s1);
strcat(s, s1);
strcat(s, " mii ");
if(n/100%10!=0)
{scriere_numar(n%1000, s1);
strcat(s, s1);
}
else if(n/10%10!=0)
{scriere_numar(n%100, s1);
strcat(s, s1);
}
else {
scriere_numar(n%10, s1);
strcat(s, s1);
}
}
}
}

int main()
{int n;
char nr[100];
cin>>n;
scriere_numar(n, nr);
cout<<nr;
    return 0;
}


/**

#include <iostream>
#include <cstring>

using namespace std;



void grupuri2(char cuv[101], char grup[])
{char aux[101], *p;


    p=strstr(cuv, grup);
while(p!=NULL)
{if(strchr("aeiou", p[-1])!=NULL)
{strcpy(aux, p);
p[0]='-';
strcpy(p+1, aux);
p=strstr(p+3, grup);
}
else p=strstr(p+2, grup);
}
}


void grupuri3(char cuv[101], char grup[])
{char aux[101], *p;


p=strstr(cuv, grup);
while(p!=NULL)
{if(strchr("aeiou", p[-1])!=NULL)
{strcpy(aux, p);
p[0]='-';
strcpy(p+1, aux);
p=strstr(p+4, grup);
}
else p=strstr(p+3, grup);
}
}

void grupuri_consoane(char cuv[101], char grup[])
{char *p, aux[101];
p=strstr(cuv, grup);
while(p!=NULL)
{if(strchr("aeiou", p[-1])&& strchr("aeiou", p[3]))
{strcpy(aux, p+2);
p[2]='-';
strcpy(p+3, aux);
p=strstr(p+4, grup);
}
else p=strstr(p+3, grup);
}
}




void desp_silabe(char cuv[101])
{int i;
char aux[101], *p;
i=1;
while(i<strlen(cuv)-1)
{if(strchr("aeiou", cuv[i])==NULL && strchr("aeiou", cuv[i-1]) && strchr("aeiou", cuv[i+1]))
{strcpy(aux, cuv+i);
cuv[i]='-';
strcpy(cuv+i+1, aux);
i+=3;
}
else i++;
}
grupuri2(cuv, "ce");
grupuri2(cuv, "ci");
grupuri2(cuv, "ge");
grupuri2(cuv, "gi");
grupuri3(cuv, "che");
grupuri3(cuv, "chi");
grupuri3(cuv, "ghe");
grupuri3(cuv, "ghi");


i=1;
while(i<strlen(cuv)-2)
{if(strchr("aeiou-", cuv[i])==NULL && strchr("aeiou", cuv[i-1]) && strchr("aeiou-", cuv[i+1])==NULL && strchr("aeiou", cuv[i+2]))
{
if((cuv[i+1]=='l'|| cuv[i+1]=='r') && strchr("bcdfghtpv", cuv[i]))
{strcpy(aux, cuv+i);
cuv[i]='-';
strcpy(cuv+i+1, aux);
i=i+3;
}
else{
strcpy(aux, cuv+i+1);
cuv[i+1]='-';
strcpy(cuv+i+2, aux);
i=i+3;
}

}
else i++;


}

grupuri_consoane(cuv, "lpt");
grupuri_consoane(cuv, "mpt");
grupuri_consoane(cuv, "nct");
grupuri_consoane(cuv, "ncs");
grupuri_consoane(cuv, "ndv");
grupuri_consoane(cuv, "rct");
grupuri_consoane(cuv, "rtf");
grupuri_consoane(cuv, "stm");

i=1;
while(i<=strlen(cuv)-4)
{
if(strchr("aeiou", cuv[i-1]) && strchr("aeiou-", cuv[i])==NULL && strchr("aeiou-", cuv[i+1])==NULL && strchr("aeiou-", cuv[i+2])==NULL && strchr("aeiou", cuv[i+3]))
{aux[0]=0;
strncat(aux, cuv+i, 3);
if(strcmp(aux, "lpt")!=0 && strcmp(aux, "mpt")!=0 && strcmp(aux, "nct")!=0 && strcmp(aux, "ncs")!=0 && strcmp(aux, "ndv")!=0 && strcmp(aux, "rct")!=0 && strcmp(aux, "rtf")!=0  && strcmp(aux, "stm")!=0)
{strcpy(aux, cuv+i+1);
cuv[i+1]='-';
strcpy(cuv+i+2, aux);
i=i+4;
}
else i=i+3;
}
else i++;
}

i=1;
while(i<=strlen(cuv)-5)
{
if(strchr("aeiou", cuv[i-1]) && strchr("aeiou-", cuv[i])==NULL && strchr("aeiou-", cuv[i+1])==NULL && strchr("aeiou-", cuv[i+2])==NULL && strchr("aeiou-", cuv[i+3])==NULL && strchr("aeiou", cuv[i+4]))
{aux[0]=0;
strcpy(aux, cuv+i+1);
cuv[i+1]='-';
strcpy(cuv+i+2, aux);
i=i+5;
}
else i++;
}

i=0;
while(i<=strlen(cuv)-1)
{
if(strchr("aeiou", cuv[i])&& cuv[i]==cuv[i+1])
{strcpy(aux, cuv+i+1);
cuv[i+1]='-';
strcpy(cuv+i+2, aux);
i=i+3;
}

else i++;
}




}

int main()
{
char cuv[101];
cin>>cuv;
desp_silabe(cuv);
cout<<cuv;


    return 0;
}
**/

/**#include <iostream>
#include <cstring>

using namespace std;

char s[101];


int main()
{cin.getline(s, 100);
char *p;
int ok=1;
p=strchr(s, '<');
while(p!=NULL && ok)
{if(p[1]=='b' || p[1]=='i' || p[1]=='u' || p[1]=='/')
{int i=1;
while(p[i]!='>' && i+1<=strlen(p)-1) i++;
if(i==strlen(p)-1)
{if(p[i]=='>') p[0]=0;
else ok=0;
}
else
{strcpy(p, p+i+1);
p=strchr(p, '<');}
}
else p=strchr(p+1, '<');

}

cout<<s;


    return 0;
}
**/

/**
#include <iostream>
#include <cstring>


using namespace std;

int i=1, j, k, nrv[300], copie;

int main()
{char s[300], m[300][300], aux[300], *p;
cin.getline(s, 256);

p=strtok(s, " ");
while(p!=NULL)
{strcpy(m[i], p);
for(j=0; j<strlen(p); j++)
    if(strchr("aeiou", p[j])) nrv[i]++;
i++;
p=strtok(NULL, " ");
}
i--;

for(j=1; j<i; j++)
    for(k=j+1; k<=i; k++)
        {if(nrv[k]<nrv[j])
    {copie=nrv[k];
    nrv[k]=nrv[j];
    nrv[j]=copie;
    strcpy(aux, m[k]);
    strcpy(m[k], m[j]);
    strcpy(m[j], aux);
    }
    else if(nrv[k]==nrv[j] && strlen(m[k])<strlen(m[j]))
    {
copie=nrv[k];
    nrv[k]=nrv[j];
    nrv[j]=copie;
   strcpy(aux, m[k]);
    strcpy(m[k], m[j]);
    strcpy(m[j], aux);
    }
    else if(nrv[k]==nrv[j] && strlen(m[k])==strlen(m[j]) && strcmp(m[k], m[j])<0)
    {
        copie=nrv[k];
    nrv[k]=nrv[j];
    nrv[j]=copie;
strcpy(aux, m[k]);
    strcpy(m[k], m[j]);
    strcpy(m[j], aux);
    }
    }

for(j=1; j<=i; j++)
    cout<<m[j]<<' ';





    return 0;
}
**/

/**
#include <iostream>
#include <string.h>


using namespace std;

int main()
{char s[101], *p, *q, aux[101];
int l, gasit=0;
cin.getline(s, 101);
p=s;
q=strchr(p, ' ');
while(q!=NULL)
{
l=q-p;
if(l%2==1 && l>1)
{strcpy(aux, p+l/2+1);
strcpy(p+l/2, aux);
gasit=1;
}
p=strchr(p, ' ')+1;
q=strchr(p, ' ');
}
l=strlen(p);
if(l%2==1 && l>1)
{strcpy(aux, p+l/2+1);
strcpy(p+l/2, aux);
gasit=1;
}

if(gasit) cout<<s;
else cout<<"nu exista";
return 0;
}
**/

/**

#include <iostream>
#include <cstring>

using namespace std;

struct cuvinte{
		char cuvant[100];
		unsigned int nrAparitii;
	};
int cnt=0;
void f(cuvinte v[100], char cuv[])
{int ap, j;
char *p, sep[]=" ,.?!:;", m[101][101];
p=strtok(cuv, sep);
while(p!=NULL)
{cnt++;
strcpy(m[cnt], p);
strcpy(v[cnt].cuvant, p);
p=strtok(NULL, sep);
}
int i;
for(i=1; i<=cnt; i++)
{ap=1;
for(j=1; j<=cnt; j++)
    if(strcmp(m[i], m[j])==0 && i!=j) ap++;
v[i].nrAparitii=ap;
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
**/

/**#include <iostream>
#include <cstring>


using namespace std;

char s[101], *p, m[101][101];
int cnt;
int main()
{cin.getline(s, 100);
p=strtok(s, " ");
while(p!=NULL)
{strcpy(m[++cnt], p);
p=strtok(NULL, " ");
}




    return 0;
}**/
