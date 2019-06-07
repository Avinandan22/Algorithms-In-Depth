#include<iostream>
#include<string>

using namespace std;

int main()
{
	string text,s;
	cin >> text >> s;
   int length = text.size();
	int len = s.size();
   int arr[len];
   arr[0] = 0;
   int j = 0;
   for(int i = 1;i < len;i++)
   {
      if(s[j] == s[i])
      {
         arr[i] = j + 1;
         j++;
      }
      else
      {
         while(j > 0)
         {
            j = arr[j - 1];
            if(s[j] == s[i])
            {
               arr[i] = j + 1;
               j++;
               break;
            }
         }
         if(j == 0)
            arr[i] = 0;
      }
   }  
   int val = -1,k = 0; 
   for(int i = 0;i < length;i++)
   {
      if(text[i] == s[k])
      {
         k++;
         if(k == len)
         {
            val = i;
            break;
         }
      }
      else if(k == 0)
         continue;
      else
      {
         if(s[arr[k - 1]] == text[i])
         {
            k = arr[k - 1] + 1;
         }
         else
         {
            k = 0;
         }
      }
   }   
   cout << val + 1 - len;
	return 0;
}