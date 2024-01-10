typedef char *String;
int StrLength(String T);
//string长度
int SubString(String Sub,String S,int pos,int len);
//串S存在，1≤pos≤StrLength(S)，且0≤len≤StrLength(S)-pos+1，用Sub返回串S的第pos个字符起长度为len的子串。
//串S和T存在，T是非空串，1≤pos≤StrLength(S)。
int StrCompare(String S,String T);
int Index (String T, String S,int pos)
{
    int n,m,i;
    String sub;
    if(pos>0)
    {
        n=StrLength(S);
        m=StrLength(T);
        i=pos;
        while(i<=n-m+1)
        {
            SubString(sub,S,i,m);
            if(StrCompare(sub,T)!=0)
                ++i;
            else
                return i;

        }
    }
    return 0;
    
}


