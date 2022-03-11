#include&lt;bits/stdc++.h&gt;
#include&lt;string.h&gt;
int max (int x, int y) { return (x &gt; y)? x : y; }

int lps(char *str)
{
int n = strlen(str);

int i, j, cl;
int L[n][n]; 

for (i = 0; i &lt; n; i++)
    L[i][i] = 1;
    for (cl=2; cl&lt;=n; cl++)
    {
        for (i=0; i&lt;n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] &amp;&amp; cl == 2)
            L[i][j] = 2;
            else if (str[i] == str[j])
            L[i][j] = L[i+1][j-1] + 2;
            else
            L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    return L[0][n-1];
}

int main()
{
    char seq[] = &quot;surajara&quot;;
    int n = strlen(seq);
    printf (&quot; %d&quot;, lps(seq));
    getchar();
    return 0;
}