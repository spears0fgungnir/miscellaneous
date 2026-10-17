class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>rm;
        string lt="IVXLCDM";int nm[]={1,5,10,50,100,500,1000};
        for(int i=0;i<7;i++)rm[lt[i]]=nm[i];
        unordered_map<char,string>lp={{'I',"VX"},{'X',"LC"},{'C',"DM"}};
        int i=0,ans=0;
        while(i<s.size()){
            char c=s[i];
            if(lp.contains(c)){
                if(i!=s.size()-1&&lp[c].find(s[i+1])!=-1){
                    ans+=rm[s[i+1]]-rm[c];i+=2;continue;
                }
            }
            ans+=rm[c];i++;
        }
        return ans;
    }
};