//
//  main.cpp
//  lecoodtest
//
//  Created by 朱磊 on 2017/9/19.
//  Copyright © 2017年 朱磊. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) //1
    {
        vector<int> returnArr;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    returnArr.push_back(i);
                    returnArr.push_back(j);
                }
            }
                
        }
        return returnArr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)//2
    {
        ListNode* result;
        ListNode* node=result;
        int c=0;
        int flag=0;
        while(l1!=NULL && l2!=NULL)
        {
            int sum=l1->val+l2->val+c;
            if(flag==0)
            {
                flag=1;
                result->val=sum%10;
            }
            else
            {
                ListNode* newnode=new ListNode(sum%10);
                node->next=newnode;
                node=node->next;
            }
            c=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int sum=l1->val+c;
            ListNode* newnode=new ListNode(sum%10);
            node->next=newnode;
            c=sum/10;
            node=node->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum=l2->val+c;
            ListNode* newnode=new ListNode(sum%10);
            node->next=newnode;
            c=sum/10;
            node=node->next;
            l2=l2->next;
        }
        if(c!=0)
        {
            ListNode* newnode=new ListNode(c);
            node->next=newnode;
        }
        while(result!=NULL)
        {
            cout<<result->val;
            result=result->next;
        }
        return result;
    }
    int lengthOfLongestSubstring(string s)//3
    {
        int temp[200];
        for(int i=0;i<200;i++)
            temp[i]=-1;
        int num=s.length();
        int maxlen=0;
        int curlen=0;
        for(int i=0;i<num;i++)
        {
            if(temp[s[i]]==-1)
            {
                temp[s[i]]=i;
                curlen++;
                if(curlen>maxlen)
                    maxlen=curlen;
            }
            else
            {
                for(int j=temp[s[i]]+1;j<i;j++)
                    temp[s[j]]=-1;
                i=temp[s[i]];
                temp[s[i]]=-1;
                if(curlen>maxlen)
                    maxlen=curlen;
                curlen=0;
            }
        }
        return maxlen;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)//4
    {
        vector<int> allnum;
        double result;
        if(nums1.size()<nums2.size())
        {
            allnum=nums1;
            for(int i=0;i<nums2.size();i++)
                allnum.push_back(nums2[i]);
        }
        else
        {
            allnum=nums2;
            for(int i=0;i<nums1.size();i++)
                allnum.push_back(nums1[i]);
        }
        sort(allnum.begin(),allnum.begin()+allnum.size());
        if(allnum.size()%2!=0)
        {
            int mid=allnum.size()/2;
            result=allnum[mid];
        }
        else
        {
            int mid=allnum.size()/2;
            result=double((allnum[mid]+allnum[mid-1]))/2;
        }
        return result;
    }
    string longestPalindrome(string s)//5**
    {
        string result;
        int max=1;
        int start=-1;
        int temp[1000][1000]={0};
        for(int i=0;i<s.length();i++)
        {
            temp[i][i]=1;
            if(i==s.length()-1)
                break;
            if(s[i]==s[i+1])
            {
                max=2;
                start=i;
                temp[i][i+1]=1;
            }
        }
        for(int i=3;i<=s.size();i++)
        {
            for(int j=0;j<=s.size()-i;j++)
            {
                if(s[j]==s[j+i-1] && temp[j+1][j+i-2]==1)
                {
                    temp[j][j+i-1]=1;
                    max=i;
                    start=j;
                }
            }
        }
        if(max>=2)
            result=s.substr(start,max);
        else
            result+=s[0];
        return result;
            
    }
    
    string convert(string s, int numRows)//6
    {
        if(numRows==1)
            return s;
        int times=2*numRows-2;
        string result="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(j%times==i || j%times==times-i)
                {
                    result+=s[j];
                }
            }
        }
        return result;
    }
    int reverse(int x)//7
    {
        int copyx=x;
        long result=0;
        long int times=1;
        while(copyx)
        {
            copyx=copyx/10;
            times*=10;
        }
        times/=10;
        while(times)
        {
            int c=x%10;
            result+=c*times;
            times/=10;
            x/=10;
        }
        if(result!=(int)result)
            return 0;
        return result;
    }
    int myAtoi(string str)//8  ****
    {
        long result=0;
        int len=str.size();
        long mul=1;
        int flag=0;
        int index=0;
        int i;
        int f=0;
        for(i=0;i<str.length();i++)
        {
            if(str[i]==' ')
            {
                if(f==1)
                    break;
                else
                    continue;
            }
            if(f==0 && (str[i]=='+' || str[i]=='-'))
            {
                f=1;
                continue;
            }
            f=1;
            if(str[i]>='0' && str[i]<='9')
                continue;
            else
                break;
        }
        index=i-1;
        for(i=index;i>=0;i--)
        {
            if(str[i]==' ')
                continue;
            int num=str[i]-'0';
            if(num<0 || num>9)
            {
                if(str[i]=='+')
                {
                    if(flag==1)
                        return 0;
                    flag=1;
                    continue;
                }
                else if(str[i]=='-')
                {
                    if(flag==1)
                        return 0;
                    flag=1;
                    result=-result;
                    continue;
                }
                else
                    return 0;
            }
            if(flag==1)
                return 0;
            long temp=mul*(str[i]-'0');
            result=result+temp;
            if(temp<0)
            {
                if(str[0]!='-')
                    result=2147483647;
                else
                    result=-2147483648;
                break;
            }
            if(result<0)
            {
                if(str[0]!='-')
                    result=2147483647;
                else
                    result=-2147483648;
                break;
            }
            mul*=10;
        }
        if(result>2147483647)
        {
            result=2147483647;
        }
        if(result<-2147483648)
        {
            result=-2147483648;
        }
        return result;
    }
    
    bool isPalindrome(int x)//9
    {
        bool result=true;
        int temp=x;
        if(x==0)
            return true;
        vector<int> a={};
        while(temp!=0)
        {
            cout<<temp%10<<endl;
            a.push_back(temp%10);
            temp=temp/10;
        }
        int len=a.size()-1;
        for(int i=0;i<=a.size()/2;i++)
        {
            int mid=(a[i]+a[len-i])/2;
            if(mid==a[i] && mid==a[len-i])
            {
                continue;
            }
            else
            {
                result=false;
            }
        }
        return result;
    }
    bool test(string s,string p)//10
    {
        if(p.size()==0 && s.size()==0)
            return true;
        if(p.size()==0 && s.size()!=0)
            return false;
        bool flag=true;
        if(s[0]!=p[0] && p[0]!='.')
        {
            if(p[1]=='*')
            {
                flag=test(s,p.substr(2,p.size()));
                if(flag==true)
                    return true;
            }
            else
                flag=false;
        }
        else if(p[0]=='.')
        {
            if(p[1]=='*')
            {
                flag=test(s,p.substr(2,p.size()));
                if(flag==true)
                    return true;
                if(flag==false && s!="")
                {
                    flag=test(s.substr(1,s.size()),p.substr(2,p.size()));
                    if(flag==true)
                        return true;
                }
                if(flag==false && s!="")
                {
                    flag=test(s.substr(1,s.size()),p);
                    if(flag==true)
                        return true;
                }
            }
            else
            {
                if(s=="")
                    return false;
                flag=test(s.substr(1,s.size()),p.substr(1,p.size()));
                if(flag==true)
                    return true;
            }
        }
        else
        {
            if(p[1]=='*')
            {
                if(s=="")
                {
                    flag=test(s,p.substr(2,p.size()));
                    if(flag==true)
                        return true;
                }
                else
                {
                    flag=test(s.substr(1,s.size()),p.substr(2,p.size()));
                    if(flag==true)
                        return true;
                    if(flag==false)
                    {
                        flag=test(s.substr(1,s.size()),p);
                        if(flag==true)
                            return true;
                    }
                    if(flag==false)
                    {
                        flag=test(s,p.substr(2,p.size()));
                        if(flag==true)
                            return true;
                    }
                }
            }
            else
            {
                if(s=="")
                    return false;
                flag=test(s.substr(1,s.size()),p.substr(1,p.size()));
                if(flag==true)
                    return true;
            }
        }
        return flag;
    }
    bool isMatch(string s, string p)//10
    {
        for(int i=0;i<s.size();i++)
        {
            if(p.find(s[i])==-1 && p.find('.')==-1)
                return false;
        }
        int flag=test(s,p);
        return flag;
    }
    int maxArea(vector<int>& height)//11
    {
        int result=0;
        int V;
        for (int i=0;i<height.size();i++)
        {
            int index=i;
            for(int j=height.size()-1;j>=i+1;j--)
            {
                if(height[j]>=height[i])
                    index=j;
                V=(j-i)*height[i];
                if(result<V)
                    result=V;
            }
        }
        return result;
    }
    string intToRoman(int num)//12
    {
        string temp[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int reduce[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string str;
        for(int i=12;i>=0;i--)
        {
            while(num-reduce[i]>=0)
            {
                str+=temp[i];
                num-=reduce[i];
            }
        }
        return str;
    }
    int romanToInt(string s)//13
    {
        string temp="IVXLCDM";
        int reduce[13]={1,5,10,50,100,500,1000};
        int sum=0;
        char pre=s[0];
        sum+=reduce[temp.find(s[0])];
        for(int i=1;i<s.size();i++)
        {
            if(temp.find(s[i])>temp.find(pre))
            {
                sum=sum+reduce[temp.find(s[i])]-2*reduce[temp.find(pre)];
            }
            else
            {
                sum+=reduce[temp.find(s[i])];
            }
            pre=s[i];
        }
        return sum;
    }
    string longestCommonPrefix(vector<string>& strs)//14
    {
        string result="";
        if(strs.size()==0)
            return result;
        if(strs.size()==1)
            return strs[0];
        int flag=0;
        while(true)
        {
            int index=0;
            char c=strs[0][index];
            for(int i=1;i<strs.size();i++)
            {
                if(index>strs[i].size() || strs[i][index]!=c)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
            result+=c;
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums)//15
    {
        set< vector<int> > s;
        vector< vector<int> > result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int> items={};
                    items.push_back(nums[i]);
                    items.push_back(nums[j]);
                    items.push_back(nums[k]);
                    sort(items.begin(),items.end());
                    if(s.find(items)==s.end())
                    {
                        result.push_back(items);
                        s.insert(items);
                    }
                    j++;
                    k--;
                    if(nums[j]==nums[k])
                        break;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
    int threeSumClosest(vector<int>& nums, int target)//16
    {
        int min=1000000;
        int result=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                int temp=nums[i]+nums[j]+nums[k]-target;
                cout<<nums[i]<<' '<<nums[j]<<' '<<nums[k]<<' '<<temp<<endl;
                if(abs(temp)<min)
                {
                    min=abs(temp);
                    result=nums[i]+nums[j]+nums[k];
                }
                if(temp==0)
                {
                    return target;
                }
                else if(temp>0)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
    vector<string> letterCombinations(string digits)//17 **
    {
        vector<string> result={};
        if(digits.size()==0)
            return result;
        result.push_back("");
        vector<int> indexs;
        string temp[12]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","",""};
        for(int i=0;i<digits.size();i++)
        {
            indexs.push_back(digits[i]-'0');
        }
        for(int i=0;i<indexs.size();i++)
        {
            int len=result.size();
            for(int j=0;j<len;j++)
            {
                for(int k=0;k<temp[indexs[i]].size();k++)
                {
                    result.push_back(result[0]+temp[indexs[i]][k]);
                }
                result.erase(result.begin());
            }
        }
        return result;
    }
    struct ADD_NUM
    {
        int x;
        int y;
        int value;
    };
    static bool compare(ADD_NUM a,ADD_NUM b)
    {
        return a.value<b.value;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target)//18
    {

        vector<ADD_NUM> adds;
        set< vector<int> > s;
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                ADD_NUM a;
                a.x=i;
                a.y=j;
                a.value=nums[i]+nums[j];
                adds.push_back(a);
            }
        }
        sort(adds.begin(),adds.end(),compare);
        int j=0,k=adds.size()-1;
        while(j<k)
        {
            if(adds[j].value+adds[k].value==target)
            {
                int startj=j,startk=k;
                while(adds[j+1].value==adds[j].value)
                    j++;
                while(adds[k-1].value==adds[k].value)
                    k--;
                for(int cj=startj;cj<=j;cj++)
                {
                    for(int ck=startk;ck>=k;ck--)
                    {
                        if(adds[cj].x!=adds[ck].x &&adds[cj].y!=adds[ck].y && adds[cj].x!=adds[ck].y && adds[cj].y!=adds[ck].x)
                        {
                            vector<int> items={};
                            items.push_back(nums[adds[ck].x]);
                            items.push_back(nums[adds[ck].y]);
                            items.push_back(nums[adds[cj].x]);
                            items.push_back(nums[adds[cj].y]);
                            sort(items.begin(),items.end());
                            if(s.find(items)==s.end())
                            {
                                result.push_back(items);
                                s.insert(items);
                            }
                        }
                    }
                }
                k--;
                j++;
            }
            else if(adds[j].value+adds[k].value>target)
            {
                k--;
            }
            else if(adds[j].value+adds[k].value<target)
            {
                j++;
            }
        }
        return result;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *latternode=head;
        ListNode *latterpre=NULL;
        ListNode *forwardnode=head;
        for(int i=1;i<n;i++)
        {
            forwardnode=forwardnode->next;
        }
        while(forwardnode->next!=NULL)
        {
            forwardnode=forwardnode->next;
            latterpre=latternode;
            latternode=latternode->next;
        }
        if(latterpre==NULL)
            return NULL;
        latterpre->next=latternode->next;
        return head;
    }
    bool isValid(string s)
    {
        bool result=true;
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            if(result==false)
                break;
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stk.push(s[i]);
            else if(s[i]==')' || s[i]==']' || s[i]=='}')
            {
                if(stk.size()==0)
                {
                    result=false;
                    break;
                }
                char c=stk.top();
                stk.pop();
                if(s[i]==')')
                    result=(c=='(');
                else if(s[i]==']')
                    result=(c=='[');
                else
                {
                    result=(c=='{');
                }
            }
            else
                continue;
        }
        if(stk.size()!=0)
            result=false;
        return result;
    }
};
int main()
{
    Solution sl;
    cout<<sl.isValid("()[]{}")<<endl;
    return 0;
}
