typedef char bool;
#define true 1
#define false 0

char s[100000];

bool one_symbol_in_str()
{
    int length = 0;
	for(; s[length] != '\0'; length++);

    for (int i = 1; i < length; i++)
        if (s[i] != s[0])
            return false;

    return true;
}

bool is_palindrome(int _begin, int _end)
{
    if(_begin >= _end) return true;
    else return (is_palindrome(_begin + 1, _end - 1) && (s[_begin] == s[_end]));
}

int main()
{

    //string s;
    scanf("%s", s);
	//getline(cin, s);

	if(one_symbol_in_str(s))
        printf("-1");
        //cout << "-1";

    else
    {
        int length = 0;

        for(; s[length] != '\0'; length++);

        bool check = is_palindrome(0, length-1);

        if(!check) printf("%d", length); //cout << length;

        else printf("%d", length-1); //cout << length-1;
    }

    return 0;
}