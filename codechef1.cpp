 #include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <regex.h>
#include <cctype>
#include <string>

#include<bits/stdc++.h>
using namespace std;

const int MS=19999;
char s[MS];

void readLine(){
    fgets(s,MS,stdin); int l=strlen(s);
    if(s[l-1]=='\n')s[l-1]='\0';
}

char wd[MS];
string wds[MS];
int N;

bool nextWord(char *&p){
    while(*p==' ' && *p!='\0')++p; if(*p=='\0')return 0;
    if(*p=='(' || *p==')'){ wd[0]=*p;wd[1]='\0'; ++p; return 1; }
    if(islower(*p)||isdigit(*p)||isupper(*p)||*p=='-'){
        int low=islower(*p); char *o=wd;
        while(islower(*p)||isdigit(*p)||isupper(*p)||*p=='-'){
            if(low!=islower(*p)){ wd[0]='\0';return 1; }
            *(o++)=*(p++);
        } *(o++)='\0'; 
        return 1;
    }
    wd[0]='\0'; return 1;
}
const char errMsg[]="Format does not conform\n";

int getNumber(int &p){
    int x=0;
    if(wds[p][0]=='0')return 0;
    for(string::iterator it=wds[p].begin();it!=wds[p].end();++it){
        if(!isdigit(*it))return 0;
        x=x*10+*it-'0'; if(x>12)return 0;
    }
    if(x<2)x=0; return x;
}
void outNumber(int x,string &out){
    if(x/10)out.push_back(x/10+'0');
    out.push_back(x%10+'0');
}
bool isLiteral(int p){
    return isdigit(wds[p][0]) || isupper(wds[p][0]) || wds[p][0]=='-';
}
bool isCountable(int p){
    return wds[p].size()==1 && (isdigit(wds[p][0]) || isupper(wds[p][0]));
}

int parseFormatStr(int &p,string &out);
int parseFmtNoQuantifier(int &p,string &out){
    char ch1=wds[p][0];
    if(ch1=='('){ ++p; return parseFormatStr(p,out); }
    if(isCountable(p) && wds[p+1]=="to" && isCountable(p+2)){
        char ch2=wds[p+2][0]; p+=3;
        if(     (isdigit(ch1) && isdigit(ch2)) ||
                (isupper(ch1) && isupper(ch2)) ){
            if(ch1>ch2)return -1;
            out.push_back('['); out.push_back(ch1);
            out.push_back('-'); out.push_back(ch2);
            out.push_back(']');
            return 1;
        }
        return -1;
    }
    if(wds[p]=="upto" || wds[p]=="exactly"){
        int exa=ch1=='e';            ++p;
        int lim=getNumber(p);        ++p;
        if(!lim)return -1;
        if(wds[p]=="letters" || wds[p]=="digits"){
            int lett=wds[p][0]=='l'; ++p;
            out.push_back('['); out.push_back(lett?'A':'0');
            out.push_back('-'); out.push_back(lett?'Z':'9');
            out.push_back(']');
            out.push_back('{');
            if(!exa){ outNumber(0,out); out.push_back(','); }
            outNumber(lim,out);
            out.push_back('}');
            return lim;
        }
        return -1;
    }
    if(wds[p]=="digit"){
        ++p;
        out.push_back('['); out.push_back('0');
        out.push_back('-'); out.push_back('9');
        out.push_back(']');
        return 1;
    }
    if(wds[p]=="letter"){
        ++p;
        out.push_back('['); out.push_back('A');
        out.push_back('-'); out.push_back('Z');
        out.push_back(']');
        return 1;
    }
    if(isLiteral(p)){
        for(string::iterator it=wds[p].begin();it!=wds[p].end();++it)
            out.push_back(*it);
        return wds[p++].size();
    }
    return -1;
}

int parseSingleFmt(int &p,string &out){
    string tmp;
    int len=parseFmtNoQuantifier(p,tmp);
    while(wds[p]=="optional" || wds[p+1]=="times"){
        while(wds[p]=="optional"){
            ++p;
            out.push_back('(');
            tmp.append(")?");
        }
        while(wds[p+1]=="times"){
            int num=getNumber(p); p+=2;
            if(!num)return -1;
            out.push_back('(');
            tmp.push_back(')');
            tmp.push_back('{');
            outNumber(num,tmp);
            tmp.push_back('}');
            len*=num; if(len>2010)len=2010;
        }
    }
    out.append(tmp); return len;
}

int parseFormatStr(int &p,string &out){
    int lall=0; out.push_back('(');
    if(wds[p][0]==')')return -1;
    for(;;){
        int lsin=0;
        out.push_back('(');
        for(;;){
            int r=parseSingleFmt(p,out);
            if(r==-1)return -1;
            if(r>lsin)lsin=r;

            if(wds[p]=="or")   {++p;out.push_back('|');}
            else break;
        }
        out.push_back(')'); lall+=lsin; if(lall>2010)lall=2010;
        if(wds[p]==")"){++p;break;}
    }
    out.push_back(')'); return lall;
}

regex_t R;
void dit(){
    readLine(); N=0; char *p=s; int err=0;
    while(nextWord(p)){
        if(!wd[0]){ err=1;break; }
        wds[N++]=wd;
    } wds[N++]=")";
    wds[N++]=""; wds[N++]="";
    wds[N++]=""; wds[N++]="";
    wds[N++]=""; wds[N++]="";

    string reg("^");
    if(err)printf(errMsg);
    else{
        int st=0;int maxlen=parseFormatStr(st,reg); reg.push_back('$');
        if(maxlen==-1||wds[st]!=""){printf(errMsg);err=1;}
        else if(maxlen>2000){
            printf("Matches too long ID\n");
            err=1;
        }
    }
    int T;scanf("%d",&T);readLine();
    if(err){
        while(T--) readLine();
    }else{
        regcomp(&R,reg.c_str(),REG_NOSUB|REG_EXTENDED);
        while(T--){
            readLine();
            printf(regexec(&R,s,0,NULL,0)==0?"Valid-ID\n":"Invalid-ID\n");
        }
        regfree(&R);
    }
    printf("\n");
}

int main() {
    int T;scanf("%d",&T); readLine();
    while(T--)dit();
    return 0;
}
