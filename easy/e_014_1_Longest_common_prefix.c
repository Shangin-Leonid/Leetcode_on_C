/*
    ACCEPTED
    0 ms    100%
    5.8 MB  94 %
*/

char * longestCommonPrefix(char ** strs, int strsSize)
{
    char *LCP;
    int LCP_len = 0;
    int need_continue = 1;


    if(strsSize == 1)
        return *strs;

    for(int n_let = 0; need_continue; ++n_let)
    {
        LCP_len++;
        char temp = strs[0][n_let];
        if(temp == '\0')
            need_continue = 0;
        for(int n_str = 1; (n_str < strsSize) && need_continue; ++n_str)
        {
            char tmp = strs[n_str][n_let];
            if(tmp == '\0')
                need_continue = 0;
            if(temp != tmp)
                need_continue = 0;
        }
    }


    LCP = (char *) malloc(LCP_len * sizeof(char));
    for(int i = 0; i < LCP_len-1; ++i)
        LCP[i] = strs[0][i];
    LCP[LCP_len-1] = '\0';


    return LCP;
}
