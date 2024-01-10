//注意：这是一个非常低效的版本，时间复杂度为O((n-m＋1)*m)
//使用string[]来演示匹配方法
typedef char* String;
int Index(String S,String T,int pos)
{
    int i=pos;
    int j=1;
    while(i<=S[0]&&j<=T[0])
    //S[0]和T[0]存放字符串长度
    {
        if(S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+2;
            //防止一开始有匹配，但后面不匹配的情况，这里是退回上次匹配首位的下一位；
            j=1;

        }
    }
    if (j=T[0])
        return i-T[0];
    else 
        return 0;
}