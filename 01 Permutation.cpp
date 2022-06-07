//Given a string, we need to find all the permutations that do NOT contain a sub-string "AB".

//Naive soln: Time = O(n! *n )
//	    : Generate all permutations....then reject the ones with sub-string "AB"
//          : see code below

#include <bits/stdc++.h>
using namespace std;

void permute(string str, int l, int r)
{
    if(l==r)
    {
        if(str.find("AB")==string::npos) //check for each permutation if "AB" is NOT a sub-string
            cout<<str<<" ";
        return;
    }
    else
    {
        for(int i=l;i<=r;i++)
	{
            swap(str[i],str[l]); //swap l and i
            permute(str,l+1,r); //recursion 
            swap(str[i],str[l]); //swap again to nullify the effect of previous swap...this is similar to backtracking...1st push in vector, then after recursive call, pop from vector
        }   
    }
}

int main() {
    string str="ABC";
    permute(str,0,str.length()-1);      
    return 0;  
}

//Efficient soln: Backtracking 
//              : DONT make the permutations with "AB" as a sub-string....reduces time significantly
//	 	: code below

#include <bits/stdc++.h>
using namespace std;

bool isSafe(string str,int l, int i, int r){
    if(l!=0 && str[l-1]=='A' && str[i]=='B') //obvio...since i and l are swapped
        return false;
    if(r==(l+1) && str[i]=='A' && str[l]=='B') // r==(l+1)...IMP->eg string is CBA...first B swapped with B, gives CBA as output, then B swapped with A...we get CAB...has AB sub-string, BUT above code DOES NOT handle it...so we need this extra line
        return false;
    return true;
}

void permute(string str, int l, int r){
    if(l==r)
    {
        cout<<str<<" ";
        return;
    }
    else
    {
        for(int i=l;i<=r;i++)
	{
            if(isSafe(str,l,i,r)) //extra check function added...if this is true, then only swap and recursion
	    {
                swap(str[i],str[l]);
                permute(str,l+1,r);
                swap(str[i],str[l]);
	    }
        }   
    }
}

int main() {
    string str="ABC";
    permute(str,0,str.length()-1);      
    return 0;  	
}


