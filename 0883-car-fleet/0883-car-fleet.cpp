class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<double,double>> p(n);
        for(int i=0;i<n;i++){
            p[i]=make_pair(position[i],speed[i]);
        }
        sort(p.begin(),p.end());
        int ans=n;
        double maxi=(target-p[n-1].first)/p[n-1].second;
        cout<<maxi<<endl;
        for(int i=n-2;i>=0;i--){
            double time=(target-p[i].first)/p[i].second;
            cout<<time<<endl;
            if(maxi>=time){
                ans--;
            }
            else{
                maxi=time;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};