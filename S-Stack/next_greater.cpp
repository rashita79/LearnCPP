#include <bits/stdc++.h>
using namespace std;
// problem statement
/* from the given vector or array we need to find the element which is next greater for each array element
for example in array 10 4 7 9 13 6
  arr[0] =10 -> next greater element will be 13 if after 13 we had any other elemnent like 12/14 then also the ans would have been 13 as it is nearest
  arr[1] = 4->next greater element will be 7
  arr[2] = 7->next greater element will be 9
  arr[3] = 9->next greater element will be 13
  arr[4] = 13->next greater element will be -1 because there is no element larger than 13 to the right side
  arr[5] = 6->next greater element will be -1 because no element is there in right side*/
vector<int> next_greater(vector<int> &v, int n)
{
    stack<int> s;     // we use stack
    s.push(v[n - 1]); // pushing last element in the stack
    vector<int> ans;
    ans.push_back(-1);               // -1 for last element of answer array
    for (int i = n - 2; i >= 0; i--) // loop from 2nd last element
    {
        while (!s.empty() && s.top() < v[i]) //  if stack has smaller element than the current element then we pop it from the stack
            s.pop();
        if (s.empty())
            ans.push_back(-1);// -1 if no number is found that is when stack is empty
        else
            ans.push_back(s.top());
        s.push(v[i]);// pushing current element in the stack
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cout << "ENTER NUMBER OF ELEMENTS IN ARRAY" << endl;
    cin >> n;
    vector<int> v;
    cout << "ENTER ARRAY ELEMENTS" << endl;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    vector<int> ans;
    ans = next_greater(v, n);
    for (auto x : ans)
        cout << x << " ";
}