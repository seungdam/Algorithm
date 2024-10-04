#include "pch.h"
#include <map>
#include <algorithm>

int countSames(string t, string d)
{
    int ans = 0;
    for (int i = 0; i < t.length(); ++i)
    {
        if (t[i] == d[i]) ++ans;
    }

    return ans;
}

int solution(string begin, string target, vector<string> words)
{
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    int answer = 0;
   map<string, bool> visited;
 
   queue<string> bfsq;
   bfsq.push(begin);
   while (!bfsq.empty())
   {
       begin = bfsq.front();
       bfsq.pop();
       if (begin == target) return answer;

       int accurate = 0;
       string next_word;
       for (auto w : words)
       {
           auto cnt = countSames(begin, w);
           if (cnt != begin.length() - 1) continue;
           if (visited[w]) continue;
           
           auto acc = countSames(w, target);
          
           if (accurate < acc)
           {
               accurate = acc;
               next_word = string(w);
           }
       }
       if (next_word.length() != 0)
       {
           bfsq.push(next_word);
           visited[next_word] = true;
           ++answer;
       }
   }
   return 0;
}



int main()
{
    vector<string> v{ "hot", "dot", "dog", "lot", "log", "zxc" };
    cout << solution("hit", "zxc", v);
}